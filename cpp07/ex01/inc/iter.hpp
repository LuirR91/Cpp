#pragma once

#include <iostream>

template<typename T1, typename T2>
void	iter(T1 *array, const int length, T2 function)
{
	for(int i = 0; i < length; i++)
		function(array[i]);
};
