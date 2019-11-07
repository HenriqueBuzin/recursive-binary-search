#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "numbers.h"

struct numbers {
	int series;
	int number;
	char name[60];
    char address[60];
};

number_t * create_number(int series, int number, char name[60], char address[60]){

	number_t * data = malloc(sizeof(number_t));

	data->series = series;

	data->number = number;

	strcpy(data->name, name);

	strcpy(data->address, address);

	return data;
}

number_t ** get_numbers(char *file_name, int *n_lines){

	FILE *fp = fopen(file_name,"r");

	if(!fp){
		perror("Erro ao abrir arquivo");
		exit(-1);
	}

	// int d = fscanf(fp, "%*[^\n]");
	// printf("d: %d\n", d);

	fseek(fp, 28, SEEK_SET);

	char line[200];
	*n_lines = 0;
	while(fgets(line, sizeof(line), fp) != NULL){
		(*n_lines)++;
	}

	number_t ** numbers;

	numbers = malloc(sizeof(struct numbers *) * *n_lines);

	//d = fscanf(fp, "%*[^\n]");
	//printf("d: %d\n", d);

	fseek(fp, 28, SEEK_SET);

	int series;
	int number;
	char name[60];
	char address[60];

	int i = 0;
	while(fscanf(fp, "%d, %d, %59[^,], %59[^\n]", &series, &number, name, address) == 4){

		//printf("Lido %d, %d, %s, %s\n", series, number, name, address);

		numbers[i] = create_number(series, number, name, address);

	    i++;
	}

	fclose(fp);
	return numbers;
}

void bubblesort(number_t **numbers, int n_lines){
	//number_t * number = NULL;

			printf("%d\n", n_lines);




}
