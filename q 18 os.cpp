#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 3

int buffer[BUFFER_SIZE];
int fill = 0;
int use = 0;
int count = 0;

void put(int value) {
    buffer[fill] = value;
    fill = (fill + 1) % BUFFER_SIZE;
    count++;
}

int get() {
    int tmp = buffer[use];
    use = (use + 1) % BUFFER_SIZE;
    count--;
    return tmp;
}

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t empty = PTHREAD_COND_INITIALIZER;
pthread_cond_t full = PTHREAD_COND_INITIALIZER;

void *producer(void *arg) {
    int i;
    for (i = 1; i <= 4; i++) {
        pthread_mutex_lock(&mutex);
        while (count == BUFFER_SIZE) {
            printf("Buffer is full\n");
            pthread_cond_wait(&empty, &mutex);
        }
        put(i);
        printf("Producer produced item %d\n", i);
        pthread_cond_signal(&full);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void *consumer(void *arg) {
    int i, tmp;
    for (i = 0; i < 1; i++) {
        pthread_mutex_lock(&mutex);
        while (count == 0) {
            printf("Buffer is empty\n");
            pthread_cond_wait(&full, &mutex);
        }
        tmp = get();
        printf("Consumer consumed item %d\n", tmp);
        pthread_cond_signal(&empty);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t producer_thread, consumer_thread;

    
    pthread_create(&consumer_thread, NULL, consumer, NULL);
    pthread_join(consumer_thread, NULL);

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_join(producer_thread, NULL);
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_join(producer_thread, NULL);
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_join(producer_thread, NULL);
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_join(producer_thread, NULL);

    return 0;
}
