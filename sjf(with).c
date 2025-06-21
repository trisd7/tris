#include <stdio.h>

int main() {
    int n, i, time = 0, comp = 0, sm;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], x[n], ct[n], tat[n], wt[n];
    float awt = 0, atat = 0;

    // Input process details
    for (i = 0; i < n; i++) {
        printf("Enter Burst Time and Arrival Time of Process %d: ", i + 1);
        scanf("%d %d", &bt[i], &at[i]);
        pid[i] = i + 1;
        x[i] = bt[i]; // Copy burst time for later use
    }

    int min_bt, index;
    
    while (comp < n) {
        min_bt = 9999;
        index = -1;

        // Find the process with the shortest remaining time that has arrived
        for (i = 0; i < n; i++) {
            if (at[i] <= time && bt[i] > 0 && bt[i] < min_bt) {
                min_bt = bt[i];
                index = i;
            }
        }

        // If no process is available, just increment time
        if (index == -1) {
            time++;
            continue;
        }

        // Process execution
        bt[index]--;
        time++;

        // If process completes execution
        if (bt[index] == 0) {
            comp++;
            ct[index] = time;
            tat[index] = ct[index] - at[index];
            wt[index] = tat[index] - x[index];
            awt += wt[index];
            atat += tat[index];
        }
    }

    // Display results
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], x[i], ct[i], tat[i], wt[i]);
    }

    // Calculate and print averages
    printf("\nAverage Waiting Time: %.2f", awt / n);
    printf("\nAverage Turnaround Time: %.2f\n", atat / n);

    return 0;
}

