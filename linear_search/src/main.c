#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "numbers.h"

int main() {

	clock_t inicio, fim;
	double total = 0.0;
	double media = 0.0;

	int i;
	for(i = 1; i <= 2; i++){

		int n_lines = 0;

		number_t **numbers = get_numbers("yellow_pages.csv", &n_lines);
		bubblesort(numbers, n_lines);

		inicio = clock();
		int d = linear_search(numbers, n_lines, 9);
		fim = clock();

		puts("\n----------------------\n");
		show_numbers(numbers, n_lines);
		printf("\nO item foi encontrado na posi��o: %d\n", d);

		total = (double) (fim - inicio) / (CLOCKS_PER_SEC / 1000);
		media += total;

		printf("Tempo decorrido: %lf (ms)\n", total);

		liberate_numbers(numbers, n_lines);
	}

	printf("M�dia do Tempo Decorrido: %lf (ms)\n", media / (i - 1));

	return EXIT_SUCCESS;
}