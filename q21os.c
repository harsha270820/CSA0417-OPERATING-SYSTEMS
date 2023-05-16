#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5 

typedef enum { THINKING, HUNGRY, EATING } State;

sem_t mutex;
sem_t forks[N];
State state[N];

int left(int i) {
    return i;
}

int right(int i) {
    return (i + 1) % N;
}

void test(int i) {
    if (state[i] == HUNGRY && state[left(i)] != EATING && state[right(i)] != EATING) {
        state[i] = EATING;
        sem_post(&forks[i]);
    }
}

void grab_forks(int i) {
    sem_wait(&mutex);
    state[i] = HUNGRY;
    test(i);
    sem_post(&mutex);
    sem_wait(&forks[i]);
}

void release_forks(int i) {
    sem_wait(&mutex);
    state[i] = THINKING;
    test(left(i));
    test(right(i));
    sem_post(&mutex);
}

void *philosopher(void *arg) {
    int i = *(int *)arg;
    while (1) {
        printf("Philosopher %d is thinking.\n", i);
        sleep(rand() % 3);

        grab_forks(i);

        printf("Philosopher %d is eating.\n", i);
        sleep(rand() % 3);

        release_forks(i);
    }
}

int main() {
    int i;
    pthread_t tid[N];

    sem_init(&mutex, 0, 1);
    for (i = 0; i < N; i++)
        sem_init(&forks[i], 0, 0);

    for (i = 0; i < N; i++) {
        int *arg = malloc(sizeof(*arg));
        *arg = i;
        pthread_create(&tid[i], NULL, philosopher, arg);
    }

    for (i = 0; i < N; i++)
        pthread_join(tid[i], NULL);

    return 0;
}
