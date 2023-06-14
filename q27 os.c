#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_INSTANCES 4
#define NUM_PROCESSES 4

sem_t semaphore;

void* process(void* arg) {
    int process_id = *(int*)arg;
    
    
    sem_wait(&semaphore);
    
  
    printf("Process P%d is using the resource.\n", process_id);
    
    
    sem_post(&semaphore);
    
    pthread_exit(NULL);
}

int main() {
    int process_ids[NUM_PROCESSES] = {1, 2, 3, 4};
    
  
    sem_init(&semaphore, 0, NUM_INSTANCES);
    
   
    pthread_t threads[NUM_PROCESSES];
    for (int i = 0; i < NUM_PROCESSES; i++) {
        pthread_create(&threads[i], NULL, process, &process_ids[i]);
    }
    
  
    for (int i = 0; i < NUM_PROCESSES; i++) {
        pthread_join(threads[i], NULL);
    }
    
    sem_destroy(&semaphore);
    
    
    int process_id = 5;
    
   
    sem_wait(&semaphore);
    
   
    printf("Process P%d is using the resource.\n", process_id);
    
    
    sem_post(&semaphore);
    
    return 0;
}
