#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Include the <string.h> header file for strcmp()

#define MAX_FRAMES 4

// Define a structure to represent page replacement simulation
typedef struct {
    int reference_string[100];  // Array to store the page reference string
    int num_frames;             // Number of frames currently in use
    int frames[MAX_FRAMES];     // Array to represent the frames in memory
    int page_faults;            // Counter to track the number of page faults
} PageReplacement;

// Function prototypes
int page_not_in_frames(PageReplacement *pr, int page);
void lru(PageReplacement *pr, int page);
void optimal(PageReplacement *pr, int page, int current_step, int length);
void fifo(PageReplacement *pr, int page);
void display_output(PageReplacement *pr, char *algorithm, int length);

// Function to check if a page is in the frames
int page_not_in_frames(PageReplacement *pr, int page) {
    for (int i = 0; i < pr->num_frames; i++) {
        if (pr->frames[i] == page) {
            return 0;  // Page found in frames
        }
    }
    return 1;  // Page not found in frames
}

// Function to implement Least Recently Used (LRU) page replacement algorithm
void lru(PageReplacement *pr, int page) {
    for (int i = 0; i < pr->num_frames; i++) {
        if (pr->frames[i] == page) {
            // Move the recently used page to the end of the frames
            for (int j = i; j < pr->num_frames - 1; j++) {
                pr->frames[j] = pr->frames[j + 1];
            }
            pr->frames[pr->num_frames - 1] = page;
            break;
        }
    }
}

// Function to implement First In First Out (FIFO) page replacement algorithm
void fifo(PageReplacement *pr, int page) {
    // Shift all pages in frames to the left by one position
    for (int i = 0; i < pr->num_frames - 1; i++) {
        pr->frames[i] = pr->frames[i + 1];
    }
    // Replace the last page with the new page
    pr->frames[pr->num_frames - 1] = page;
}

// Function to implement Optimal page replacement algorithm
void optimal(PageReplacement *pr, int page, int current_step, int length) {
    if (pr->num_frames < MAX_FRAMES) {
        // If there are empty frames, fill one with the new page
        pr->frames[pr->num_frames] = page;
        pr->num_frames++;
    } else {
        int farthest_use = -1;
        int page_to_replace = -1;
        // Find the page in frames that won't be used for the longest time
        for (int i = 0; i < pr->num_frames; i++) {
            int j;
            for (j = current_step; j < length; j++) {
                if (pr->frames[i] == pr->reference_string[j]) {
                    if (j > farthest_use) {
                        farthest_use = j;
                        page_to_replace = i;
                    }
                    break;
                }
            }
            // If the page won't be used anymore, replace it
            if (j == length) {
                page_to_replace = i;
                break;
            }
        }
        pr->frames[page_to_replace] = page;
    }
}

// Function to display the simulation output for a given algorithm
void display_output(PageReplacement *pr, char *algorithm, int length) {
    printf("For %s Algorithm:\n", algorithm);
    for (int step = 0; step < length; step++) {
        int page = pr->reference_string[step];
        if (page_not_in_frames(pr, page)) {
            pr->page_faults++;
            if (pr->num_frames < MAX_FRAMES) {
                pr->frames[pr->num_frames] = page;
                pr->num_frames++;
            } else {
                // Invoke the respective algorithm to replace a page
                if (strcmp(algorithm, "LRU") == 0) {
                    lru(pr, page);
                } else if (strcmp(algorithm, "Optimal") == 0) {
                    optimal(pr, page, step, length);
                } else if (strcmp(algorithm, "FIFO") == 0) {
                    fifo(pr, page);
                }
            }
        } else {
            if (strcmp(algorithm, "LRU") == 0) {
                lru(pr, page);
            }
        }
        // Print the simulation step details
        printf("• Step %d: Page fault (%d) - Page Table: {", step + 1, page);
        for (int i = 0; i < pr->num_frames; i++) {
            printf("%d", pr->frames[i]);
            if (i != pr->num_frames - 1) {
                printf(", ");
            }
        }
        printf("}, Frames: [");
        for (int i = 0; i < pr->num_frames; i++) {
            printf("%d", pr->frames[i]);
            if (i != pr->num_frames - 1) {
                printf(", ");
            }
        }
        printf("], Faults: %d\n", pr->page_faults);
    }
    printf("• Total Page Faults: %d\n\n", pr->page_faults);
}

// Main function to initiate the simulation
int main() {
    PageReplacement pr;
    pr.num_frames = 0;
    pr.page_faults = 0;
    int reference_string[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int length = sizeof(reference_string) / sizeof(reference_string[0]);
    // Copy the reference string
    for (int i = 0; i < length; i++) {
        pr.reference_string[i] = reference_string[i];
    }

    // Run simulations for each algorithm
    display_output(&pr, "LRU", length);
    display_output(&pr, "Optimal", length);
    display_output(&pr, "FIFO", length);

    return 0;
}
