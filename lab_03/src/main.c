/**
 * @mainpage
 * *Вариант 11*\n\n
 * Умножение разреженных вектора-строки и матрицы
 * **Автор:** Маслова Марина
 * **Группа:** ИУ7-33Б
 */

#include <stdio.h>
#include <stdbool.h>

#include "menu.h"
#include "errors.h"
#include "matrix.h"

#define OK 0

int main(void)
{
    setbuf(stdout, NULL);

    puts("ПРОГРАММА УМНОЖЕНИЯ РАЗРЕЖЕННЫХ ВЕКТОРА-СТРОКИ И МАТРИЦ");

    int exit_code = OK;

    sparse_matrix_t sparse_matrix = { .elements = NULL, .rows = NULL, .elements = NULL,
                                      .sizes.columns = 0, .sizes.rows = 0, .sizes.nonzeros = 0}; 
    sparse_matrix_t sparse_row = { .elements = NULL, .rows = NULL, .elements = NULL,
                                      .sizes.columns = 0, .sizes.rows = 0, .sizes.nonzeros = 0}; 
    matrix_t matrix = { .matrix = NULL, .sizes.rows = 0, .sizes.columns = 0, .sizes.nonzeros = 0};
    matrix_t row = { .matrix = NULL, .sizes.rows = 0, .sizes.columns = 0, .sizes.nonzeros = 0};

    while (true)
    {
        short int action;
        print_menu();
        exit_code = choose_action(&action);

        if (exit_code)
        {
            print_error_message(exit_code);
            continue;
        }

        exit_code = do_action(action, &sparse_matrix, &sparse_row, &matrix, &row);

        if (exit_code)
        {
            print_error_message(exit_code);
            continue;
        }
    }

    return OK;
}