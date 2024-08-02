#include "sudoku.h"
#include <stdio.h>
#include <stdlib.h>

int Sol[N][N];
int Row[N], Col[N], Sub[N];
int Counter;
pthread_mutex_t lock;
pthread_cond_t cond;

void readSolution(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (fscanf(file, "%d", &Sol[i][j]) != 1) {
                fclose(file);
                perror("Error reading Sudoku data");
                exit(EXIT_FAILURE);
            }
        }
    }
    fclose(file);
}

