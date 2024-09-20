#include <stdlib.h>
#include <stdio.h>

void main()
{
    int p_id[15], num_proc, burst_time[15];

    printf("Enter the number of processes: ");
    scanf("%d", &num_proc);

    printf("Enter PID for all the processes: ");
    for (int i = 0; i < num_proc; i++)
    {
        scanf("%d", &p_id[i]);
    }

    printf("Enter burst time for every processes: ");
    for (int i = 0; i < num_proc; i++)
    {
        scanf("%d", &burst_time[i]);
    }

    printf("\n");

    int waiting_time[num_proc];
    waiting_time[0] = 0;

    // waiting time of each process
    for (int i = 1; i < num_proc; i++)
    {
        waiting_time[i] = burst_time[i - 1] + waiting_time[i - 1];
    }

    printf("PID     Burst-time      Waiting-time    Turnaround-time\n");
    printf("------------------------------------------------------\n");

    float total_wt = 0.0;
    float total_tat = 0.0;

    for (int i = 0; i < num_proc; i++)
    {
        // printf("%d\t\t%d\t\t%d\t\t%d\t\t\n\n", p_id[i], burst_time[i], waiting_time[i], burst_time[i] + waiting_time[i]);

        printf("%d\t\t", p_id[i]);
        printf("%d\t\t", burst_time[i]);
        printf("%d\t\t", waiting_time[i]);
        printf("%d\t\t", burst_time[i] + waiting_time[i]); // turnaround time of every process
        printf("\n\n");

        total_wt += waiting_time[i];                    // total waiting time
        total_tat += (waiting_time[i] + burst_time[i]); // total turnaround time
    }

    float avg_tat, avg_wt;

    avg_wt = total_wt / num_proc;   // average waiting time
    avg_tat = total_tat / num_proc; // average turnaround time

    printf("Avg. waiting time: %f\n", avg_wt);
    printf("Avg. turnaround time: %f", avg_tat);
}