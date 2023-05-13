#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 5

int main() {
    int requests[MAX_REQUESTS] = {55, 58, 60, 70, 18};
    int head = 50; 
    int total_head_movement = 0; 

    printf("Head movement:\n");
    for (int i = 0; i < MAX_REQUESTS; i++) {
        int current_request = requests[i];
        int head_movement = abs(head - current_request); 
        printf("%d -> %d: %d\n", head, current_request, head_movement);
        total_head_movement += head_movement;
        head = current_request;
    }

    float average_head_movement = (float) total_head_movement / MAX_REQUESTS;
    printf("Average head movement: %.2f\n", average_head_movement);

    return 0;
}
