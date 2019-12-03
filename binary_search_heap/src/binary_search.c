#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "binary_search.h"
#include "numbers.h"
#include "heap.h"

int binary_search(number_t ** numbers, int i, int value){

	if(numbers[i] == NULL){
		return INT_MIN;
	}

	if(get_number(numbers[i]) == value){
		return i;
	}

	if(get_number(numbers[i]) < value){
		return binary_search(numbers, right(i), value);
	}

	return binary_search(numbers, left(i), value);

}
