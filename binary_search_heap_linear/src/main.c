#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "../src/heap.h"
#include "../src/numbers.h"
#include "linear_search.h"

int main() {

	clock_t start, end;
	double total = 0.0;
	double media = 0.0;

	int i;
	for(i = 1; i <= 1; i++){

		int n_lines = 0;

		number_t **numbers = get_numbers("yellow_pages.csv", &n_lines);
		// number_t **numbers = get_numbers("data.csv", &n_lines);
		//number_t **numbers = get_numbers("100.000.csv", &n_lines);

		heap_sort(numbers, n_lines);

		start = clock();
		int d = linear_search(numbers, n_lines, 999999451);
		end = clock();

		puts("\n----------------------\n");
		show_numbers(numbers, n_lines);
		printf("\nO item foi encontrado na posição: %d\n", d);

		total = (double) ((end - start) * 1000) / CLOCKS_PER_SEC;
		media += total;

		printf("Tempo decorrido: %lf (ms)\n", total);

		liberate_numbers(numbers, n_lines);
	}

	printf("Média do Tempo Decorrido: %lf (ms)\n", media / (i - 1));

	return EXIT_SUCCESS;
}
