#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 3

// Function to simulate sending a frame
void send_frame(int frame_number) {
    printf("Sending frame %d\n", frame_number);
}

// Function to simulate receiving an acknowledgment (with 70% chance of success)
int receive_ack(int frame_number) {
    int ack_received = rand() % 10 < 7;  // 70% chance to receive ACK
    if (ack_received) {
        printf("Acknowledgement for frame %d received.\n", frame_number);
        return 1;  // ACK received
    } else {
        printf("No acknowledgement for frame %d. Resending...\n", frame_number);
        return 0;  // No ACK received
    }
}

int main() {
    int total_frames;
    srand(time(NULL));  // Seed the random number generator

    printf("Enter the total number of frames to send: ");
    scanf("%d", &total_frames);

    // Validate input
    if (total_frames <= 0) {
        printf("Invalid number of frames. Exiting...\n");
        return 1;
    }

    // Loop through the total frames and try sending each one
    for (int i = 0; i < total_frames; i++) {
        int attempts = 0;

        // Try sending the frame up to MAX_ATTEMPTS times
        while (attempts < MAX_ATTEMPTS) {
            send_frame(i);  // Send the frame

            // Check if ACK was received
            if (receive_ack(i)) {
                break;  // If ACK is received, break out of the attempt loop
            }

            attempts++;  // Increment the number of attempts

            // If max attempts are reached, move to the next frame
            if (attempts == MAX_ATTEMPTS) {
                printf("Max attempts reached for frame %d. Moving to next frame.\n", i);
            }
        }
    }

    printf("All frames processed!\n");
    return 0;
}
