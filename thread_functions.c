#include "sudoku.h"
#include "utils.h"
#include <stdio.h>
#include <unistd.h> // For sleep

typedef struct {
    int thread_id;
    int delay;
} thread_arg;

void *validate(void *arg) {
    thread_arg *params = (thread_arg *)arg;
    int delay = params->delay;
    int thread_id = params->thread_id;

    // Validation logic depending on the thread ID
    switch (thread_id) {
        case 1: // Thread-1: Validate sub-grids 1, 2, 3 and rows 1, 2, 3
            Sub[0] = validate_subgrid(0, 0);
            Sub[1] = validate_subgrid(0, 3);
            Sub[2] = validate_subgrid(0, 6);
            Row[0] = validate_row(Sol[0]);
            Row[1] = validate_row(Sol[1]);
            Row[2] = validate_row(Sol[2]);
            break;
        case 2: // Thread-2: Validate sub-grids 4, 5, 6 and rows 4, 5, 6
            Sub[3] = validate_subgrid(3, 0);
            Sub[4] = validate_subgrid(3, 3);
            Sub[5] = validate_subgrid(3, 6);
            Row[3] = validate_row(Sol[3]);
            Row[4] = validate_row(Sol[4]);
            Row[5] = validate_row(Sol[5]);
            break;
        case 3: // Thread-3: Validate sub-grids 7, 8, 9 and rows 7, 8, 9
            Sub[6] = validate_subgrid(6, 0);
            Sub[7] = validate_subgrid(6, 3);
            Sub[8] = validate_subgrid(6, 6);
            Row[6] = validate_row(Sol[6]);
            Row[7] = validate_row(Sol[7]);
            Row[8] = validate_row(Sol[8]);
            break;
        case 4: // Thread-4: Validate all nine columns
            for (int i = 0; i < 9; i++) {
                Col[i] = validate_column(i);
            }
            break;
    }

    sleep(delay); // Sleep for synchronization observation

    // Update the Counter with the number of valid rows, columns, or sub-grids
    pthread_mutex_lock(&lock);
    for (int i = 0; i < 9; i++) {
        Counter += Row[i] + Sub[i] + Col[i];
    }
    pthread_mutex_unlock(&lock);

    pthread_cond_signal(&cond); // Notify the parent thread

    printf("Thread ID-%d: Validation complete.\n", thread_id);

    return NULL;
}
