#ifndef SUDOKU_H
#define SUDOKU_H

#include <pthread.h>

#define N 9 // Sudoku size

// Shared variables
extern int Sol[N][N];
extern int Row[N], Col[N], Sub[N];
extern int Counter;
extern pthread_mutex_t lock;
extern pthread_cond_t cond;

// Function declarations
void *validate(void *params);
void readSolution(const char *filename);

#endif

