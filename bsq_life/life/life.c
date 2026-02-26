#include "life.h"

int	main(int argc, char **argv)
{
	if (argc != 4)
		return 1;

	int	w = atoi(argv[1]);
	int	h = atoi(argv[2]);
	int	n = atoi(argv[3]);

	int	*b = calloc(w * h, sizeof(int));
	int	*t = calloc(w * h, sizeof(int));

	if (w <= 0 || h <= 0 || n < 0)
		return 1;

	int	x = 0;
	int y = 0;
	int pen = 0;
	char c;

	while(read(0, &c, 1) > 0)
	{
		if (c == 'x')
			pen = !pen;
		else
		{
			int	nx = x, ny = y;
			if (c == 'w') ny--;
			if (c == 's') ny++;
			if (c == 'a') nx--;
			if (c == 'd') nx++;
			if (nx >= 0 && nx < w && ny >= 0 && ny < h)
			{
				x = nx;
				y = ny;
			}
		}
		if (pen && x >= 0 && x < w && y >= 0 && y < h)
			b[y * w + x] = 1;
	}

	while(n--)
	{
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				int	cnt = 0;
				for (int dy = -1; dy <= 1; dy++)
				{
					for (int dx = -1; dx <= 1; dx++)
					{
						if (dy == 0 && dx == 0)
							continue;
						int	ni = i + dy, nj = j + dx;
						if (ni >= 0 && ni < h && nj >= 0 && nj < w)
							cnt += b[ni * w + nj];
					}
				}
				t[i * w + j] = ((cnt == 3) || (b[i * w + j] && cnt == 2));
			}
		}
		int *tmp = b;
		b = t;
		t = tmp;
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
			putchar(b[i * w + j] ? '0' : ' ');
		putchar('\n');
	}

	free(b);
	free(t);
	return (0);
}