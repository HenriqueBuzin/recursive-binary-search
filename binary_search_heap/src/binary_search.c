#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "binary_search.h"
#include "numbers.h"
#include "heap.h"

int binary_search(number_t ** numbers, int n_lines, value){

	int half =  n_lines / 2 - 1;
	if(get_numbers(half) == value){
		return half;
	}else{
		return binary_search_childs();
	}
	return INT_MIN;
}

static int binary_search_childs(number_t ** numbers, int i, int value){

	int l = left(i);

	int r = right(i);

	if(r >= l){
		if(get_number(numbers[l] == value)){
			return l;
		}
		if(get_number(numbers[r] == value)){
			return r;
		}
		return binary_search(numbers, index + 1, right, value);
	}
	return INT_MIN;
}



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

