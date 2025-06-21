#include <stdio.h>

int main() {
    int p[20], bt[20], pri[20], at[20], wt[20], tat[20], completed[20];
    int i, n, time = 0, total = 0;
    float wtavg = 0, tatavg = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        p[i] = i;
        printf("Enter Arrival Time, Burst Time & Priority of Process %d: ", i);
        scanf("%d %d %d", &at[i], &bt[i], &pri[i]);
        completed[i] = 0;
    }

    printf("\nPROCESS\tARRIVAL\tBURST\tPRIORITY\tWAITING\tTURNAROUND");

    while(total < n) {
        int idx = -1;
        int highest_priority = 9999;

        // Find highest priority process among arrived and not yet completed
        for(i = 0; i < n; i++) {
            if(at[i] <= time && !completed[i]) {
                if(pri[i] < highest_priority) {
                    highest_priority = pri[i];
                    idx = i;
                }
            }
        }

        if(idx != -1) {
            wt[idx] = time - at[idx];
            if (wt[idx] < 0) wt[idx] = 0;
            tat[idx] = wt[idx] + bt[idx];

            time += bt[idx];
            completed[idx] = 1;
            total++;

            wtavg += wt[idx];
            tatavg += tat[idx];

            printf("\nP%d\t%d\t%d\t\t%d\t%d\t%d", p[idx], at[idx], bt[idx], pri[idx], wt[idx], tat[idx]);
        } else {
            time++; // No process ready, CPU idle
        }
    }

    printf("\n\nAverage Waiting Time: %.2f", wtavg / n);
    printf("\nAverage Turnaround Time: %.2f\n", tatavg / n);

    return 0;
}
