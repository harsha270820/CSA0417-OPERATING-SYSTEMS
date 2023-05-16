#include <stdio.h>

#define FILE_SIZE 100


int contiguousAllocation(int blockPosition) {
    return 1; 
}


int linkedAllocation(int blockPosition) {
    return 1; 
}


int indexedAllocation(int blockPosition) {
    int indexBlockPosition = blockPosition / 10; 
    return 2; 
}

int main() {
    int blockPosition;

    printf("Enter the block position (1-%d): ", FILE_SIZE);
    scanf("%d", &blockPosition);

    if (blockPosition < 1 || blockPosition > FILE_SIZE) {
        printf("Invalid block position!\n");
        return 1;
    }

    printf("Contiguous Allocation:\n");
    printf("Disk I/O operations required: %d\n", contiguousAllocation(blockPosition));

    printf("Linked Allocation:\n");
    printf("Disk I/O operations required: %d\n", linkedAllocation(blockPosition));

    printf("Indexed Allocation (Single-level):\n");
    printf("Disk I/O operations required: %d\n", indexedAllocation(blockPosition));

    return 0;
}
