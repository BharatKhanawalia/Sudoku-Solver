#include <iostream>
using namespace std;

#define SIZE 9

int matrix[9][9] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0}};
void takeinput()
{
    for (int i = 0; i < 9; i++)
    {

        for (int j = 0; j < 9; j++)
        {
            cin >> matrix[i][j];
        }
    }
}
void print_sudoku()

{
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            cout << matrix[i][j] << "    ";
        }
        cout << endl;
    }
}
int number_unassigned(int *row, int *col)
{

    int num_unassign = 0;

    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (matrix[i][j] == 0)
            {
                *row = i;
                *col = j;
                num_unassign = 1;

                return num_unassign;
            }
        }
    }
    return num_unassign;
}
int is_safe(int n, int r, int c)
{
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        if (matrix[r][i] == n)
            return 0;
    }
    for (i = 0; i < SIZE; i++)
    {
        if (matrix[i][c] == n)
            return 0;
    }
    int row_start = (r / 3) * 3;

    int col_start = (c / 3) * 3;

    for (i = row_start; i < row_start + 3; i++)
    {
        for (j = col_start; j < col_start + 3; j++)

        {
            if (matrix[i][j] == n)
                return 0;
        }
    }
    return 1;
}
int solve_sudoku()
{
    int row;
    int col;
    if (number_unassigned(&row, &col) == 0)

        return 1;
    int n, i;
    for (i = 1; i <= SIZE; i++)
    {
        if (is_safe(i, row, col))

        {
            matrix[row][col] = i;
            if (solve_sudoku())
                return 1;
            matrix[row][col] = 0;
        }
    }
    return 0;
}

int main()
{
    cout << "Enter matrix" << endl;
    takeinput();
    if (solve_sudoku())
    {
        cout << "\nSolved Sudoku:\n";
        print_sudoku();
    }
    else
        cout << "\nNO SOLUTION" << endl;
    return 0;
}

/* Sudoku Input Example
4 2 0 0 0 5 0 8 0
0 1 0 0 0 0 0 0 0
7 0 3 4 2 0 0 0 0
0 0 0 0 0 0 1 0 0
0 0 9 1 0 0 0 0 7
5 3 0 2 0 0 0 9 0
0 0 0 0 0 0 7 0 8
0 0 5 0 0 6 0 0 0
0 0 0 0 9 0 0 5 0
*/