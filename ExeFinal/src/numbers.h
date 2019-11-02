#ifndef NUMBERS_H_INCLUDED

typedef struct numbers number_t;


number_t * create_number(int number, char name[60], char address[60]);

number_t ** get_numbers(char *file_name, int *n_lines);

int* bubble_sort_number(int* number, int *n_lines);

int* counting_sort_number(int* number, int *n_lines);

void show_numbers(int* number, int *n_lines);

void show_number(int* number, int position);

void release_numbers(int* number);

int search(int* number, int left, int right, int value);

#endif
