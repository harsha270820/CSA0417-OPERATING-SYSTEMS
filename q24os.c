#include <stdio.h>

#define BLOCK_SIZE 8192   
#define POINTER_SIZE 4    

#define DIRECT_BLOCKS 12
#define SINGLE_INDIRECT_BLOCKS (BLOCK_SIZE / POINTER_SIZE)
#define DOUBLE_INDIRECT_BLOCKS (BLOCK_SIZE / POINTER_SIZE) * (BLOCK_SIZE / POINTER_SIZE)
#define TRIPLE_INDIRECT_BLOCKS (BLOCK_SIZE / POINTER_SIZE) * (BLOCK_SIZE / POINTER_SIZE) * (BLOCK_SIZE / POINTER_SIZE)

int main() {
    int maxFileSize = 0;

    
    maxFileSize += DIRECT_BLOCKS * BLOCK_SIZE;
    maxFileSize += SINGLE_INDIRECT_BLOCKS * BLOCK_SIZE;
    maxFileSize += DOUBLE_INDIRECT_BLOCKS * BLOCK_SIZE;
    maxFileSize += TRIPLE_INDIRECT_BLOCKS * BLOCK_SIZE;

    printf("Maximum file size: %d bytes\n", maxFileSize);

    return 0;
}
