#include <stdlib.h>
#include <stdio.h>

#include "heap.h"
#include "numbers.h"
#include "linear_search.h"

int linear_search(number_t ** numbers, int n_lines, int value){
	for(int i = 0; i < n_lines; i++){
		if(get_number(numbers[i]) == value){
			return i;
		}
	}
	return -1;
}
