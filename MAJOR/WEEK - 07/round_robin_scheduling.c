#include <stdio.h>

void main()
{
    int num_proc, burst_time[15], rem_time[15], waiting_time[15], turnaround_time[15];
    int time_quantum, time = 0, proc_left;

    printf("Enter the number of processes: ");
    scanf("%d", &num_proc);
    proc_left = num_proc;

    printf("Enter burst time for every process: ");
    for (int i = 0; i < num_proc; i++)
    {
        scanf("%d", &burst_time[i]);
        rem_time[i] = burst_time[i];
        waiting_time[i] = 0;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    while (proc_left > 0)
    {
        for (int i = 0; i < num_proc; i++)
        {
            if (rem_time[i] > 0 && rem_time[i] > time_quantum)
            {
                time += time_quantum;
                rem_time[i] -= time_quantum;
            }
            else if (rem_time[i] > 0)
            {
                time += rem_time[i];
                turnaround_time[i] = time;
                waiting_time[i] = time - burst_time[i];
                rem_time[i] = 0;
                proc_left--;
            }
        }
    }

	printf("\n");
	
    printf("Burst-time    Waiting-time    Turnaround-time\n");

    float total_wt = 0.0, total_tat = 0.0;

    for (int i = 0; i < num_proc; i++)
    {
        printf("%d\t\t%d\t\t%d\n", burst_time[i], waiting_time[i], turnaround_time[i]);
        total_wt += waiting_time[i];
        total_tat += turnaround_time[i];
    }

    float avg_wt = total_wt / num_proc;
    float avg_tat = total_tat / num_proc;

    printf("\nAverage waiting time: %f\n", avg_wt);
    printf("Average turnaround time: %f\n", avg_tat);
}

