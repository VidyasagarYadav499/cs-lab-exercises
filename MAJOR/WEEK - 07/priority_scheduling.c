#include <stdio.h>
#include <stdlib.h>

void main()
{
    int burst_time[15], priority[15];
    int num_proc;

    printf("Enter the number of processes: ");
    scanf("%d", &num_proc);

    printf("Enter burst time for all processes: ");
    for (int i = 0; i < num_proc; i++)
    {
        scanf("%d", &burst_time[i]);
    }

    printf("Enter priority (lower = more priority): ");
    for (int i = 0; i < num_proc; i++)
    {
        scanf("%d", &priority[i]);
    }

    for (int i = 0; i < num_proc - 1; i++)
    {
        for (int j = i + 1; j < num_proc; j++)
        {
            if (priority[i] > priority[j])
            {
                int temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;
            }
        }
    }

    int waiting_time[num_proc];
    waiting_time[0] = 0;

    for (int i = 1; i < num_proc; i++)
    {
        waiting_time[i] = burst_time[i - 1] + waiting_time[i - 1];
    }

	printf("\n");
	
    printf("Priority   Burst-time   Waiting-time   Turnaround-time\n");

    float total_wt = 0.0;
    float total_tat = 0.0;

    for (int i = 0; i < num_proc; i++)
    {
        int turnaround_time = burst_time[i] + waiting_time[i];

        printf("%d\t\t", priority[i]);
        printf("%d\t\t", burst_time[i]);
        printf("%d\t\t", waiting_time[i]);
        printf("%d\n", turnaround_time);

        total_wt += waiting_time[i];
        total_tat += turnaround_time;
    }

    float avg_wt = total_wt / num_proc;
    float avg_tat = total_tat / num_proc;

	printf("\n");
	
    printf("Avg Waiting Time: %f\n", avg_wt);
    printf("Avg Turnaround Time: %f\n", avg_tat);
}

