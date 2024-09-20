#include <stdlib.h>
#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_by_burst_time(int burst_time[], int p_id[], int num_proc)
{
    for (int i = 0; i < num_proc - 1; i++)
    {
        for (int j = 0; j < num_proc - i - 1; j++)
        {
            if (burst_time[j] > burst_time[j + 1])
            {
                swap(&burst_time[j], &burst_time[j + 1]);
                swap(&p_id[j], &p_id[j + 1]);
            }
        }
    }
}

int main()
{
    int p_id[15], num_proc, burst_time[15];

    printf("Enter the number of processes: ");
    scanf("%d", &num_proc);

    printf("Enter PID for all the processes: ");
    for (int i = 0; i < num_proc; i++)
    {
        scanf("%d", &p_id[i]);
    }

    printf("Enter burst time for every process: ");
    for (int i = 0; i < num_proc; i++)
    {
        scanf("%d", &burst_time[i]);
    }

    // Sort processes by burst time
    sort_by_burst_time(burst_time, p_id, num_proc);

    int waiting_time[num_proc];
    int turnaround_time[num_proc];

    waiting_time[0] = 0;

    // waiting time for each process
    for (int i = 1; i < num_proc; i++)
    {
        waiting_time[i] = burst_time[i - 1] + waiting_time[i - 1];
    }

    // turnaround time for each process
    for (int i = 0; i < num_proc; i++)
    {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
    }

    printf("\nPID     Burst-time      Waiting-time    Turnaround-time\n");
    printf("------------------------------------------------------\n");

    float total_wt = 0.0;
    float total_tat = 0.0;

    for (int i = 0; i < num_proc; i++)
    {
        printf("%d\t\t", p_id[i]);
        printf("%d\t\t", burst_time[i]);
        printf("%d\t\t", waiting_time[i]);
        printf("%d\t\t", turnaround_time[i]);
        printf("\n");

        total_wt += waiting_time[i];     // total waiting time
        total_tat += turnaround_time[i]; // total turnaround time
    }

    float avg_wt, avg_tat;

    avg_wt = total_wt / num_proc;   // average waiting time
    avg_tat = total_tat / num_proc; // average turnaround time

    printf("\nAvg. waiting time: %f\n", avg_wt);
    printf("Avg. turnaround time: %f\n", avg_tat);

    return 0;
}
