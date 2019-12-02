#include <stdio.h>
#include <stdlib.h>

#include "merge_sort.h"

void merge_sort(number_t ** numbers, int esquerda, int direita){
	if(esquerda < direita){
		int meio = (esquerda + direita) / 2;

		merge_sort(numbers, esquerda, meio);
		merge_sort(numbers, meio + 1, direita);

		funde(numbers, esquerda, meio, direita);
	}
}

void funde(number_t ** numbers, int esquerda, int meio, int direita){

	number_t *temp[direita];

	int i = esquerda;
	int j = esquerda;
	int k = meio + 1;

	while(j <= meio && k <= direita){
		if(get_number(numbers[j]) < get_number(numbers[k])){
			temp[i++] = numbers[j++];
		}else{
			temp[i++] = numbers[k++];
		}
	}

	while(j <= meio){
		temp[i++] = numbers[j++];

	}

	for(i = esquerda; i < k; i++){
		numbers[i] = temp[i];
	}
}
