#include "sudoku.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int thread_id;
    int delay;
} thread_arg;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <solution file> <delay>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int delay = atoi(argv[2]);  // Ensure this variable is actually used
    readSolution(argv[1]);

    pthread_t threads[4];
    thread_arg thread_args[4];  // Argument structure for threads

    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);

    // Create threads
    for (int i = 0; i < 4; i++) {
        thread_args[i].thread_id = i + 1;
        thread_args[i].delay = delay;  // Passing delay to threads
        pthread_create(&threads[i], NULL, validate, &thread_args[i]);
    }

    // Wait for threads to finish
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    // Cleanup
    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);

    return EXIT_SUCCESS;
}

