#include <stdio.h>

int main() {
    int a[10], b[10], x[10], i;
    int smallest, count = 0, time, n;
    double avg = 0, tt = 0, end;

    printf("Enter the number of processes:\n");
    scanf("%d", &n);

    printf("Enter the arrival times:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter the burst times:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &b[i]);

    for(i = 0; i < n; i++)
        x[i] = b[i]; // Copy of burst times

    b[9] = 9999; // Sentinel value for comparison

    for(time = 0; count != n; time++) {
        smallest = 9;
        for(i = 0; i < n; i++) {
            if(a[i] <= time && b[i] < b[smallest] && b[i] > 0)
                smallest = i;
        }

        b[smallest]--;

        if(b[smallest] == 0) {
            count++;
            end = time + 1;
            avg += end - a[smallest] - x[smallest]; // Waiting time
            tt += end - a[smallest];               // Turnaround time
        }
    }

    printf("\n\nAverage Waiting Time = %lf\n", avg / n);
    printf("Average Turnaround Time = %lf\n", tt / n);

    return 0;
}
