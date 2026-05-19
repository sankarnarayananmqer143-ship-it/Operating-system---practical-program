#include <stdio.h>

int main() {
    int frames, pages;
    int page_faults = 0;
    int i, j, k = 0;

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    int frame[frames], page[pages];

    // Initialize frames to -1
    for (i = 0; i < frames; i++)
        frame[i] = -1;

    printf("Enter page reference string:\n");
    for (i = 0; i < pages; i++)
        scanf("%d", &page[i]);

    printf("\nPage\tFrames\n");

    for (i = 0; i < pages; i++) {
        int found = 0;

        // Check if page already in frame
        for (j = 0; j < frames; j++) {
            if (frame[j] == page[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            frame[k] = page[i];
            k = (k + 1) % frames;  // FIFO replacement
            page_faults++;
        }

        // Display frames
        printf("%d\t", page[i]);
        for (j = 0; j < frames; j++) {
            if (frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", page_faults);

    return 0;
}
