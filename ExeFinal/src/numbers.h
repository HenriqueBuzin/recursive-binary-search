#ifndef NUMBERS_H_INCLUDED

typedef struct numbers number_t;

int get_series(number_t * number);

int get_number(number_t * number);

char * get_name(number_t * number);

char * get_address(number_t * number);

number_t * create_number(int series, int number, char name[60], char address[60]);

number_t ** get_numbers(char *file_name, int *n_lines);

void bubblesort(number_t **numbers, int n_linhas);

void show_number(number_t * number);

void show_numbers(number_t ** numbers, int n_lines);

void liberate_number(number_t * number);

void liberate_numbers(number_t ** numbers, int n_lines);

int binary_search(number_t ** numbers, int left, int right, int value);

#endif
