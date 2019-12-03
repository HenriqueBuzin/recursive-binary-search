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

int get_series(number_t * number){
	return (number->series);
}

int get_number(number_t * number){
	return (number->number);
}

char * get_name(number_t * number){
	return (number->name);
}

char * get_address(number_t * number){
	return (number->address);
}

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

	char line[200];

	fgets(line, sizeof(line), fp);

	*n_lines = 0;
	while(fgets(line, sizeof(line), fp) != NULL){
		(*n_lines)++;
	}

	number_t ** numbers;

	numbers = malloc(sizeof(struct numbers *) * *n_lines);

	fseek(fp, 0, SEEK_SET);

	fgets(line, sizeof(line), fp);

	int series;
	int number;
	char name[60];
	char address[60];

	int i = 0;
	while(fscanf(fp, "%d, %d, %59[^,], %59[^\n]", &series, &number, name, address) == 4){

		// printf("Lido %d, %d, %s, %s\n", series, number, name, address);

		numbers[i] = create_number(series, number, name, address);

	    i++;
	}

	fclose(fp);
	return numbers;
}

void show_number(number_t * number){
	printf("%d %d %s %s \n", get_series(number), get_number(number), get_name(number), get_address(number));
}

void show_numbers(number_t ** numbers, int n_lines){
	for(int i = 0; i < n_lines; i++){
		show_number(numbers[i]);
	}
}

void liberate_number(number_t * number){
	if(number == NULL){
		perror("liberate_number");
		exit(-1);
	}
	free(number);
}

void liberate_numbers(number_t ** numbers, int n_lines){
	if(numbers == NULL){
		perror("liberate_numbers");
		exit(-1);
	}
	for (int i = 0; i < n_lines; i++){
		free(numbers[i]);
	}
	free(numbers);
}
