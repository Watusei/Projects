#ifndef UTILS_H
#define UTILS_H

#define N 9  // Size of the Sudoku grid

// Function declarations for Sudoku validation
int validate_row(int row[N]);
int validate_column(int col_idx);
int validate_subgrid(int startRow, int startCol);

#endif

