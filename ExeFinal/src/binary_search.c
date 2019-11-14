#include <stdio.h>
#include <stdlib.h>

#include "binary_search.h"

int binary_search(number_t ** numbers, int left, int right, int value){
	if(right >= left){
		int index = (left + right) / 2;
		if(get_number(numbers[index]) == value){
			return index;
		}
		if(get_number(numbers[index]) > value){
			return binary_search(numbers, left, index - 1, value);
		}
		return binary_search(numbers, index + 1, right, value);
	}
	return -1;
}
