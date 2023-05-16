#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_TRACKS 100

int abs(int n) {
    return (n < 0) ? -n : n;
}

void scan(int tracks[], int numTracks, int initialPosition) {
    int headMovement = 0;
    int i, j;
    int currentTrack = initialPosition;
    int direction = 1; 

    
    for (i = 0; i < numTracks; i++) {
        if (tracks[i] == initialPosition)
            break;
    }

   
    for (i = 0; i < numTracks - 1; i++) {
        for (j = 0; j < numTracks - i - 1; j++) {
            if (tracks[j] > tracks[j + 1]) {
                int temp = tracks[j];
                tracks[j] = tracks[j + 1];
                tracks[j + 1] = temp;
            }
        }
    }

    
    for (i = 0; i < numTracks; i++) {
        if (tracks[i] == initialPosition)
            break;
    }

    for (j = i; j >= 0; j--) {
        headMovement += abs(currentTrack - tracks[j]);
        currentTrack = tracks[j];
    }

    headMovement += abs(currentTrack - 0);
    currentTrack = 0;

    for (j = i + 1; j < numTracks; j++) {
        headMovement += abs(currentTrack - tracks[j]);
        currentTrack = tracks[j];
    }

    printf("Head movement: %d\n", headMovement);
}

int main() {
    int numTracks;
    int tracks[MAX_TRACKS];
    int initialPosition;

    printf("Enter the number of tracks: ");
    scanf("%d", &numTracks);

    printf("Enter the track positions:\n");
    for (int i = 0; i < numTracks; i++) {
        scanf("%d", &tracks[i]);
    }

    printf("Enter the initial position of the head: ");
    scanf("%d", &initialPosition);

    scan(tracks, numTracks, initialPosition);

    return 0;
}
