#include <stdio.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

#define PI 3.14159265

void clearScreen() {
    printf("\033[H\033[J");
}

void printCentered(char* message, int width, int position) {
    int padding = (width - strlen(message)) / 2 + (int)(10 * sin(position * PI / 180));
    printf("%*s%s\n", padding, "", message);
}

int main() {
    const char* message = "I am sorry";
    int width = 80;   // Console width
    int height = 20;  // Console height
    int position = 0; // Starting position for wave

    // Loop to keep the animation running
    while (1) {
        clearScreen();  // Clear the console

        // Generate the wave-like effect by printing the message at different positions
        for (int row = 0; row < height; row++) {
            // Rotating the message with a ripple effect
            float ripple = 10 * sin((position + row * 10) * PI / 180);
            int offset = (width / 2) + (int)ripple - (strlen(message) / 2);

            // Print the message centered with the ripple effect
            printf("%*s%s\n", offset, "", message);
        }

        // Increment the position for the animation effect
        position += 4;

        // Delay to control the speed of the animation
        usleep(50000);  // 50 milliseconds
    }

    return 0;
}
