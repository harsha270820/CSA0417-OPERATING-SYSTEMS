#include <stdio.h>
#include <stdlib.h>

#define MAX_TRACKS 100 

int main() {
    int num_tracks;
    int tracks[MAX_TRACKS];
    int head_position;
    int total_head_movement = 0;
    int i;

    
    printf("Enter the number of tracks: ");
    scanf("%d", &num_tracks);
    printf("Enter the track positions:\n");
    for (i = 0; i < num_tracks; i++) {
        scanf("%d", &tracks[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &head_position);

    
    for (i = 0; i < num_tracks; i++) {
        int track = tracks[i];
        total_head_movement += abs(track - head_position);
        head_position = track;
    }

    
    printf("Total head movement: %d\n", total_head_movement);
    printf("Average head movement: %.2f\n", (float) total_head_movement / num_tracks);

    return 0;
}
