#include <stdio.h>
#include <stdlib.h>

#include "numbers.h"

int* get_numbers(char *file_name, int *n_lines){
	*n_lines = 0;
	char line[11];
	int lines;
	int i = 0;
	FILE *fp = fopen(file_name,"r");
	if(!fp){
		perror("Erro ao abrir arquivo");
		exit(-1);
	}
	while(fgets(line, sizeof(line), fp) != NULL){
		(*n_lines)++;
	}
	int *number = malloc(sizeof(int) * *n_lines);
	rewind(fp);
	while(fscanf(fp, "%d[^\n]", &lines) == 1){
		number[i] = lines;
		i++;
	}
	fclose(fp);
	return number;
}

int* bubble_sort_numbers(int* number, int *n_lines){
	 int i, j, aux;
	 for (i = 1; i < *n_lines; i++) {
		 for (j = 0; j < (*n_lines) - 1; j++) {
			 if (number[j] > number[j + 1]) {
				 aux          = number[j];
	             number[j]     = number[j + 1];
	             number[j + 1] = aux;
	         }
	     }
	 }
	return number;
}

int* counting_sort_numbers(int* number, int *n_lines){
	int i, z, j, max, min;
	for(i = 0; i < *n_lines; i++){
		if(number[i] > max){
			max = number[i];
		}else if(number[i] < min){
			min = number[i];
		}
	}
	int range = max - min + 1;
	int *count = malloc(range * sizeof(*number));
	for(i = 0; i < range; i++){
		count[i] = 0;
	}
	for(i = 0; i < *n_lines; i++){
		count[ number[i] - min ]++;
	}
	for(i = min, z = 0; i <= max; i++) {
		for(j = 0; j < count[i - min]; j++) {
			number[z++] = i;
		}
	}
	free(count);
	return number;
}

void show_numbers(int* number, int *n_lines){
	puts(" Vector");
	puts("--------");
	for(int i = 0; i < *n_lines; i++){
		printf("%d\n", number[i]);
	}
	puts("--------\n");
}

void show_number(int* number, int position){
	if(position == -1 ){
		perror("Erro ao acessar posição no vetor");
		exit(-1);
	}
	puts("Position");
	puts("--------");
	printf("%d\n", number[position]);
	puts("--------\n");
}
