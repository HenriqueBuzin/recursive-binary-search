#include <stdio.h>
#include <stdlib.h>

#include "numbers.h"

int search(int* number, int left, int right, int value){
	if(right >= left){
		int index = (left + (right-left)/2);
		if(number[index] == value){
			return index;
		}
		if(number[index] > value){
			return search(number, left, index - 1, value);
		} return search(number, index + 1, right, value);
	}
	return -1;
}

int main(void) {
	int n_lines = 0;
	int *number = get_numbers("yellow_pages.csv", &n_lines);
	number = counting_sort_numbers(number, &n_lines);

	show_numbers(number, &n_lines);

	int r = search(number, 1, n_lines, 992635865);
	printf("%d\n", r);

	return 0;
}
