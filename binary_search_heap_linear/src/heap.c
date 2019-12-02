#include "heap.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "numbers.h"

int father(int i) {
	return floor((i - 1) / 2);
}

int left(int i) {
	return (2 * i + 1);
}

int right(int i) {
	return (2 * i + 2);
}

static void swap(number_t ** numbers, int a, int b) {
	number_t *aux = numbers[a];
	numbers[a] = numbers[b];
	numbers[b] = aux;
}

static void max_heapify(int i, int len, number_t ** numbers) {
	int l = left(i);
	int r = right(i);

	int maior = 0;
	if (l < len && (get_number(numbers[l]) > get_number(numbers[i]))) {
		maior = l;
	} else {
		maior = i;
	}

	if (r < len && (get_number(numbers[r]) > get_number(numbers[maior]))) {
		maior = r;
	}

	if (maior != i) {
		swap(numbers, i, maior);
		max_heapify(maior, len, numbers);
	}
}

static void build_heap(number_t **numbers, int n_lines) {

	for (int i = n_lines / 2 - 1; i >= 0; i--) {
		max_heapify(i, n_lines, numbers);
	}

}

void heap_sort(number_t ** numbers, int n_lines) {

	build_heap(numbers, n_lines);

	int tam = n_lines;

	for (int i = n_lines - 1; i >= 1; i--) {

		swap(numbers, 0, i);

		tam--;

		max_heapify(0, tam, numbers);

	}

}
