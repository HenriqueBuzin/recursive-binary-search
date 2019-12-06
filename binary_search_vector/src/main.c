#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "numbers.h"
#include "merge_sort.h"
#include "binary_search.h"


int main() {

	clock_t inicio, fim;
	double total = 0.0;
	double media = 0.0;

	int i;
	for(i = 1; i <= 1; i++){

		int n_lines = 0;

		//number_t **numbers = get_numbers("yellow_pages.csv", &n_lines);
		// number_t **numbers = get_numbers("data.csv", &n_lines);
		number_t **numbers = get_numbers("100.000.csv", &n_lines);

		merge_sort(numbers, 0, n_lines - 1);

		inicio = clock();
		int d = binary_search(numbers, 0, n_lines - 1, 999999451);
		fim = clock();

		// puts("\n----------------------\n");
		// show_numbers(numbers, n_lines);
		printf("\nO item foi encontrado na posição: %d\n", d);

		total = (double) (fim - inicio) / (CLOCKS_PER_SEC * 1000);
		media += total;

		printf("Tempo decorrido: %lf (ms)\n", total);

		liberate_numbers(numbers, n_lines);
	}

	printf("Média do Tempo Decorrido: %lf (ms)\n", media / (i - 1));

	return EXIT_SUCCESS;
}
