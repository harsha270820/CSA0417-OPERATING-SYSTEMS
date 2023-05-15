#include <stdio.h>

void firstFit(int mem_size, int n, int process_size[]) {
    int i, j, allocated[n], frag_sum = 0;

    
    for (i = 0; i < n; i++) {
        allocated[i] = -1;
    }

    
    for (i = 0; i < n; i++) {
        for (j = 0; j < mem_size; j++) {
            if (allocated[j] == -1 && process_size[i] <= j+1) {
                allocated[j] = i;
                break;
            }
        }
    }

    
    printf("Process No.\tProcess Size\tAllocated Block No.\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i+1, process_size[i]);
        if (allocated[i] != -1) {
            printf("%d\n", allocated[i]+1);
        } else {
            printf("Not Allocated\n");
        }
    }

    for (i = 0; i < mem_size; i++) {
        if (allocated[i] == -1) {
            frag_sum++;
        }
    }

    printf("Total External Fragmentation: %d KB\n", frag_sum);
}

int main() {
    int i, mem_size;
    

    printf("Enter the number of memory partitions: ");
    scanf("%d", &mem_size);

    int memory[mem_size];
    for (i = 0; i < mem_size; i++) {
        printf("Enter size of memory partition %d: ", i+1);
        scanf("%d", &memory[i]);
    }


    int process_count;
    printf("\nEnter the number of processes: ");
    scanf("%d", &process_count);

    int process_size[process_count];
    for (i = 0; i < process_count; i++) {
        printf("Enter size of process %d: ", i+1);
        scanf("%d", &process_size[i]);
    }

    firstFit(mem_size, process_count, process_size);

    return 0;
}
