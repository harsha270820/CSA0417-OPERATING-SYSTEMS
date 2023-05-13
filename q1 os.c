#include <stdio.h>

int main() {
    int n = 8; 
    int pages[8] = {4, 1, 2, 4, 3, 2, 1, 5};
    int frameCount = 3; 
    int frames[3] = {-1, -1, -1}; 

    int pageFaults = 0; 

    int nextFrameIndex = 0; 

    for (int i = 0; i < n; i++) {
        int currentPage = pages[i];

        
        int pageHit = 0;
        for (int j = 0; j < frameCount; j++) {
            if (frames[j] == currentPage) {
                pageHit = 1;
                break;
            }
        }

        if (!pageHit) {
            frames[nextFrameIndex] = currentPage;
            nextFrameIndex = (nextFrameIndex + 1) % frameCount; 
            pageFaults++; 
        }

        printf("%d: ", currentPage);
        for (int j = 0; j < frameCount; j++) {
            if (frames[j] == -1) {
                printf(" - ");
            } else {
                printf("%d ", frames[j]);
            }
        }
        printf("\n");
    }

    printf("Number of page faults: %d\n", pageFaults);

    return 0;
}
