#include <stdio.h>
#include <stdlib.h>

#include "numbers.h"

int main() {
	int n_lines = 0;
	number_t **numbers = get_numbers("yellow_pages.csv", &n_lines);
	show_numbers(numbers, n_lines);
	bubblesort(numbers, n_lines);
	puts("\n----------------------\n");
	show_numbers(numbers, n_lines);
	puts("\n----------------------\n");
	int d = binary_search(numbers, 0, n_lines - 1, 9);
	printf("Index: %d", d);
	liberate_numbers(numbers, n_lines);
	return EXIT_SUCCESS;
}
