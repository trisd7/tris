#include <stdio.h>

struct file {
    int all[10];
    int max[10];
    int need[10];
    int flag;
};

int main() {
    struct file f[10];
    int avail[10], seq[10], request[10];
    int n, r, i, j, k, cnt = 0, fl = 0;
    int pid, safe, p;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &r);

    for (i = 0; i < n; i++) {
        printf("Enter Allocation for P%d: ", i);
        for (j = 0; j < r; j++)
            scanf("%d", &f[i].all[j]);

        printf("Enter Max for P%d: ", i);
        for (j = 0; j < r; j++)
            scanf("%d", &f[i].max[j]);

        f[i].flag = 0;
    }

    printf("Enter Available Resources: ");
    for (i = 0; i < r; i++)
        scanf("%d", &avail[i]);

    // Calculate Need Matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < r; j++)
            f[i].need[j] = f[i].max[j] - f[i].all[j];

    // --- Handle New Request ---
    printf("Enter process ID making the request: ");
    scanf("%d", &pid);
    printf("Enter resource request for P%d: ", pid);
    for (i = 0; i < r; i++) {
        scanf("%d", &request[i]);

        if (request[i] > f[pid].need[i]) {
            printf("Error: Process exceeded its maximum claim.\n");
            return 0;
        }

        if (request[i] > avail[i]) {
            printf("Resources not available. P%d must wait.\n", pid);
            return 0;
        }
    }

    // --- Tentatively allocate resources ---
    for (i = 0; i < r; i++) {
        avail[i] -= request[i];
        f[pid].all[i] += request[i];
        f[pid].need[i] -= request[i];
    }

    // --- Safety Algorithm with work[] to display updated available ---
    cnt = 0;
    fl = 0;
    int work[10];
    for (i = 0; i < r; i++)
        work[i] = avail[i];

    for (i = 0; i < n; i++)
        f[i].flag = 0;

    while (cnt < n) {
        safe = 0;
        for (i = 0; i < n; i++) {
            if (f[i].flag == 0) {
                int can_allocate = 1;
                for (j = 0; j < r; j++) {
                    if (f[i].need[j] > work[j]) {
                        can_allocate = 0;
                        break;
                    }
                }

                if (can_allocate) {
                    for (j = 0; j < r; j++)
                        work[j] += f[i].all[j];

                    printf("\nP%d is visited(", i);
                    for (j = 0; j < r; j++)
                        printf(" %d", work[j]);
                    printf(" )");

                    f[i].flag = 1;
                    seq[fl++] = i;
                    cnt++;
                    safe = 1;
                }
            }
        }

        if (!safe) {
            printf("\nRequest cannot be granted. System is in UNSAFE state.\n");
            return 0;
        }
    }

    printf("\n\nRequest can be granted. System is in SAFE state.");
    printf("\nSafe Sequence: ");
    for (i = 0; i < fl; i++)
        printf("P%d ", seq[i]);
    printf("\n");

    // --- Final Table ---
    printf("\nProcess\tAllocation\tMax\t\tNeed\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t", i);
        for (j = 0; j < r; j++)
            printf("%d ", f[i].all[j]);
        printf("\t");

        for (j = 0; j < r; j++)
            printf("%d ", f[i].max[j]);
        printf("\t");

        for (j = 0; j < r; j++)
            printf("%d ", f[i].need[j]);
        printf("\n");
    }

    return 0;
}
