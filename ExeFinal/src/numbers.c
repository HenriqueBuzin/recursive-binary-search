#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "numbers.h"

struct numbers {
	int number;
	char name[60];
    char address[60];
};

number_t * create_number(int number, char name[60], char address[60]){

	number_t * data = malloc(sizeof(number_t));

	data->number = number;

	strcpy(data->name, name);

	strcpy(data->address, address);

	return data;
}

number_t ** get_numbers(char *file_name, int *n_lines){

	char line[60];
	*n_lines = 0;
	int i = 0;


	FILE *fp = fopen(file_name,"r");

	if(!fp){
		perror("Erro ao abrir arquivo");
		exit(-1);
	}

	fscanf(fp, "%*[^\n]");

	while(fgets(line, sizeof(line), fp) != NULL){
		(*n_lines)++;
	}

	number_t ** numbers;

	numbers = malloc(sizeof(struct numbers *) * *n_lines);

	fseek(fp, 0, SEEK_SET);

	fscanf(fp, "%*[^\n]");

	int number;
	char name[60];
	char address[60];

	while(fscanf (fp, "%d %c %59[^\n]", &number, name, address) == 3){
		printf("Lido %d, %c, %c\n", number, name, address);

	    //numbers[i] = create_number(number, name, address);

	    i++;
	}

	return numbers;
}

/*
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
	puts("   Vector");
	puts("-----------");
	for(int i = 0; i < *n_lines; i++){
		printf(" %d\n", number[i]);
	}
	puts("-----------\n");
}

void show_number(int* number, int position){
	if(position == -1 ){
		perror("Erro ao acessar posição no vetor");
		exit(-1);
	}
	puts(" Position");
	puts("-----------");
	printf(" %d\n", number[position]);
	puts("-----------\n");
}

void release_numbers(int* number){
	free(number);
}

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
*/
