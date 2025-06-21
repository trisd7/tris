#include<stdio.h>

int main()
{
    int bt[20], at[20], wt[20], tat[20], i, j, n, temp;
    float avgWT = 0, avgTAT = 0;

    printf("Enter the number of processes -- ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter Arrival Time and Burst Time for Process %d -- ", i);
        scanf("%d %d", &at[i], &bt[i]);
    }

    // Sort processes by Arrival Time (FCFS with arrival time)
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(at[i] > at[j])
            {
                // Swap arrival time
                temp = at[i]; at[i] = at[j]; at[j] = temp;
                // Swap burst time
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
            }
        }
    }

    wt[0] = 0;
    tat[0] = bt[0];
    avgTAT = tat[0];

    for(i = 1; i < n; i++)
    {
        if(at[i] > tat[i - 1])
            wt[i] = 0; // CPU was idle
        else
            wt[i] = tat[i - 1] - at[i];

        tat[i] = wt[i] + bt[i];
        avgWT += wt[i];
        avgTAT += tat[i];
    }

    printf("\nPROCESS\tARRIVAL TIME\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, at[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time -- %f", avgWT / n);
    printf("\nAverage Turnaround Time -- %f\n", avgTAT / n);

    return 0;
}
