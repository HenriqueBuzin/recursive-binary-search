#ifndef NUMBERS_H_INCLUDED

typedef struct numbers number_t;

number_t * create_number(int series, int number, char name[60], char address[60]);

number_t ** get_numbers(char *file_name, int *n_lines);

void bubblesort(number_t **numbers, int n_linhas);

#endif
