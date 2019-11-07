#include <stdio.h>
#include <stdlib.h>

#include "numbers.h"

int main(void) {
	int n_lines = 0;
	number_t **numbers = get_numbers("yellow_pages.csv", &n_lines);
	bubblesort(numbers, n_lines);


	return 0;
}
