# Mini Serv - Guia de Estudo

## 📋 O que é?
Um servidor TCP multi-cliente simples que permite chat entre clientes conectados usando `select()`.

## 🎯 Conceitos Principais

### 1. Socket + Bind + Listen
```c
socket()  → cria o file descriptor do servidor
bind()    → associa o socket a uma porta
listen()  → coloca o socket em modo de escuta
```

### 2. Select + FD_SET
```c
fd_set curr;           // conjunto de todos os fds ativos
fd_set rfd, wfd;       // cópias para leitura/escrita

FD_ZERO(&curr);        // limpa o conjunto
FD_SET(fd, &curr);     // adiciona fd ao conjunto
FD_CLR(fd, &curr);     // remove fd do conjunto
FD_ISSET(fd, &rfd);    // verifica se fd está pronto
```

### 3. Accept
```c
accept(serverfd, ...)  → aceita nova conexão
                       → retorna novo fd para o cliente
```

### 4. Recv
```c
recv(fd, buffer, ...)  → recebe dados do cliente
                       → retorna bytes lidos (0 = desconectou)
```

## 🧠 Estrutura do Código

### Variáveis Globais
```c
t_client clients[1024];  // array de clientes indexado por fd
char sbuff[400000];      // buffer de envio (mensagens broadcast)
char rbuff[300000];      // buffer de recepção
int maxfd;               // maior fd ativo (para select)
int gid;                 // próximo ID de cliente
fd_set curr, rfd, wfd;   // conjuntos de file descriptors
```

### Funções Principais

#### `err(msg)` - Erro fatal
- Escreve mensagem de erro
- Termina programa

#### `send_all(except)` - Broadcast
- Envia `sbuff` para todos os clientes
- Exceto o cliente `except`
- Usa `wfd` para verificar quem pode receber

#### `create_server(port)` - Setup inicial
1. Cria socket
2. Configura endereço (INADDR_ANY + porta)
3. Bind + Listen
4. Inicializa `curr` e `clients`
5. Retorna `serverfd`

#### `add_client(serverfd)` - Novo cliente
1. `accept()` nova conexão
2. Atualiza `maxfd` se necessário
3. Atribui ID único (`gid++`)
4. Adiciona fd ao `curr`
5. Notifica outros clientes

#### `remove_client(fd)` - Cliente saiu
1. Notifica outros clientes
2. Remove fd do `curr`
3. Fecha conexão
4. Limpa buffer de mensagens

#### `handle_msg(fd)` - Processa mensagem
1. `recv()` dados do cliente
2. Se `ret <= 0`: cliente desconectou → `remove_client()`
3. Senão: adiciona ao buffer do cliente
4. Quando encontra `\n`: envia linha completa em broadcast

### Main Loop
```c
while(1) {
    wfd = rfd = curr;              // copia curr para select
    select(maxfd + 1, &rfd, &wfd, 0, 0);

    for(fd = 0; fd <= maxfd; fd++) {
        if(FD_ISSET(fd, &rfd)) {   // fd pronto para ler
            if(fd == serverfd)
                add_client();       // nova conexão
            else
                handle_msg();       // mensagem de cliente
            break;
        }
    }
}
```

## 💡 Pontos de Atenção para Decorar

### 1. Select precisa de cópias
```c
wfd = rfd = curr;  // SEMPRE antes do select!
```
Porque `select()` modifica os fd_sets.

### 2. Mensagens acumulam até `\n`
```c
clients[fd].msg[j] = rbuff[i];
if(clients[fd].msg[j] == '\n') {
    // envia e limpa buffer
    j = -1;  // recomeça do início
}
```

### 3. Atualizar maxfd
```c
if(fd > maxfd) maxfd = fd;
```
Quando novo cliente entra, pode ter fd maior.

### 4. Formato das mensagens
```c
"server: client %d just arrived\n"
"server: client %d just left\n"
"client %d: %s\n"
```

## 📝 Fluxo Completo

1. **Setup**: Cria servidor, inicializa `curr` com `serverfd`
2. **Loop infinito**:
   - Copia `curr` para `rfd` e `wfd`
   - `select()` espera atividade
   - Percorre todos os fds
   - Se `serverfd`: aceita novo cliente
   - Se cliente: processa mensagem ou desconexão
3. **Mensagens**: Acumulam em buffer até `\n`, depois broadcast

## 🔑 Dicas para o Exame

1. **Ordem de setup**: socket → bind → listen → FD_ZERO → FD_SET
2. **Sempre copiar curr**: `wfd = rfd = curr;` antes do select
3. **Dois casos no loop**: serverfd (accept) vs cliente (recv)
4. **recv() <= 0**: cliente desconectou
5. **Mensagens linha a linha**: só envia quando encontra `\n`
6. **Limpar buffers**: `bzero()` após enviar ou remover cliente
7. **Broadcast exclui**: o cliente que enviou e o serverfd

## ⚡ Checklist Rápido

- [ ] Validar argc == 2
- [ ] Socket + bind + listen + FD_ZERO + FD_SET
- [ ] Loop: copiar curr, select, iterar fds
- [ ] Se serverfd: accept, gid++, FD_SET, broadcast "arrived"
- [ ] Se cliente e recv <= 0: broadcast "left", FD_CLR, close
- [ ] Se cliente e recv > 0: acumular até \n, broadcast mensagem
- [ ] send_all() itera fds, usa FD_ISSET no wfd, exclui except
