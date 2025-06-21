#include <stdio.h>

void main() {
    int n, i, time = 0, comp = 0, index;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    int pid[n], at[n], bt[n], pr[n], ct[n], tat[n], wt[n], x[n];
    float awt = 0, atat = 0;
    
    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time, Burst Time, and Priority of Process %d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        pid[i] = i + 1;
        x[i] = bt[i];
    }
    
    int min_priority, selected;
    while (comp < n) {
        min_priority = 9999;
        selected = -1;
        
        for (i = 0; i < n; i++) {
            if (at[i] <= time && bt[i] > 0 && pr[i] < min_priority) {
                min_priority = pr[i];
                selected = i;
            }
        }
        
        if (selected == -1) {
            time++; // If no process is available, CPU remains idle
            continue;
        }
        
        bt[selected]--; // Execute the selected process for 1 time unit
        time++;
        
        if (bt[selected] == 0) { // Process completed
            comp++;
            ct[selected] = time;
            tat[selected] = ct[selected] - at[selected];
            wt[selected] = tat[selected] - x[selected];
            awt += wt[selected];
            atat += tat[selected];
        }
    }
    
    printf("\nProcess\tAT\tBT\tPriority\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], x[i], pr[i], ct[i], tat[i], wt[i]);
    }
    
    printf("\nAverage Waiting Time: %.2f", awt / n);
    printf("\nAverage Turnaround Time: %.2f\n", atat / n);
}
