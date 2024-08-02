#include "sudoku.h"
#include <string.h> // For memset

// Helper function to check if all elements in the array are unique from 1 to 9
static int check_unique(int arr[N]) {
    int count[N] = {0};
    for (int i = 0; i < N; i++) {
        if (arr[i] < 1 || arr[i] > 9 || count[arr[i] - 1] > 0) {
            return 0; // Not unique or out of bounds
        }
        count[arr[i] - 1]++;
    }
    return 1;
}

// Validate a single row
int validate_row(int row[N]) {
    return check_unique(row);
}

// Validate a single column
int validate_column(int col_idx) {
    int col[N];
    for (int i = 0; i < N; i++) {
        col[i] = Sol[i][col_idx];
    }
    return check_unique(col);
}

// Validate a 3x3 sub-grid starting from (startRow, startCol)
int validate_subgrid(int startRow, int startCol) {
    int elems[N];
    int idx = 0;
    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            elems[idx++] = Sol[i][j];
        }
    }
    return check_unique(elems);
}

