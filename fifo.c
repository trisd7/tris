#include<stdio.h>

void main() {
    int i, j, k, f, pf = 0, count = 0, rs[25], m[10], n;
    float pfr;

    printf("\nEnter the length of reference string: ");
    scanf("%d", &n);

    printf("\nEnter the reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &rs[i]);

    printf("\nEnter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
        m[i] = -1;

    printf("\nThe Page Replacement Process is:\n");

    for (i = 0; i < n; i++) {
        int flag = 0;

        // Check if page is already present
        for (k = 0; k < f; k++) {
            if (m[k] == rs[i]) {
                flag = 1;
                break;
            }
        }

        // If page not found
        if (flag == 0) {
            m[count] = rs[i];
            count = (count + 1) % f;
            pf++;
        }

        // Print current frames
        for (j = 0; j < f; j++) {
            if (m[j] != -1)
                printf("%d\t", m[j]);
            else
                printf("-\t");
        }

        if (flag == 0)
            printf("PF No. %d", pf);

        printf("\n");
    }

    // Calculate and print Page Fault Rate
    pfr = (float)pf / n;
    printf("\nTotal number of Page Faults using FIFO: %d", pf);
    printf("\nPage Fault Rate: %.2f\n", pfr);
}
