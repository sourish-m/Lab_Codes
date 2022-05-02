#include <stdio.h>
#include <stdlib.h>

int main()
{
	/* FILE *fptr; */
	int n, i;
	int burst_time[10], bt_sum = 0, arrival_time[10], wait_time[10], wt_avg = 0, turnaround_time[10], tt_avg = 0, idle_time[10];
    double cpu_util_perc=0.0;
    int context_switch[10];
	/* fptr = fopen(".\\input.txt", "r"); */

	printf("Enter number of processes: ");
	scanf( "%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("\nEnter arrival time of P%d: ", i);
		scanf( "%d", &arrival_time[i]);
		printf("\nEnter burst time of P%d: ", i);
		scanf( "%d", &burst_time[i]);
	}
    /* fclose(fptr); */

	system("cls");
	printf("\nInput Data---\n");
	printf("\nProcess Name\tArrival Time\tBurst Time\n");
	printf("===========================================\n");
	for (i = 0; i < n; i++)
	{
		printf("  P%d\t\t  %d\t\t  %d\n", i, arrival_time[i], burst_time[i]);
	}

	for (i = 0; i < n; i++)
	{
		bt_sum += burst_time[i];
		if (i == 0)
		{
			wait_time[0] = 0;
			idle_time[i] = 0;
		}
		else
			wait_time[i] = bt_sum - burst_time[i] - arrival_time[i];
        if (wait_time[i] < 0)
            wait_time[i]=0;

		wt_avg += wait_time[i];

		turnaround_time[i] = burst_time[i] + wait_time[i];
		tt_avg += turnaround_time[i];
		idle_time[i] = arrival_time[i] - (turnaround_time[i - 1] + arrival_time[i - 1]);
		if (idle_time[i] < 0)
			idle_time[i] = 0;
        cpu_util_perc+=burst_time[i];
	}
    for (i=0; i<=n; i++)
    {
        if (i==0)
            context_switch[0]=arrival_time[0];
        else if (i==n)
            context_switch[i]=arrival_time[i-1]+wait_time[i-1]+burst_time[i-1];
        else 
            context_switch[i]=arrival_time[i]+wait_time[i];
    }


	
	printf("\nOutput Data---\n");
	printf("\nProcess Name\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tIdle Time\n");
	printf("===================================================================================================================================\n");
	for (i = 0; i < n; i++)
	{
		printf("  P%d\t\t  %d\t\t  %d\t\t %d\t\t %d\t\t %d\n", i, arrival_time[i], burst_time[i], wait_time[i], turnaround_time[i], idle_time[i]);
	}
	printf("\nAverage Waiting Time is: %lf\nAverage Turnaround Time is: %lf\n", (double)wt_avg / n, (double)tt_avg / n);
    printf("\nTotal CPU utilization time is: %lf",cpu_util_perc);
    printf("\nCPU Utilization %% is: %lf",cpu_util_perc*100/(arrival_time[n-1]+burst_time[n-1]+wait_time[n-1]));
    printf("\nContext switch occurs at: ");
    for (i=0; i<=n; i++)
    {
        printf("\t%d ms", context_switch[i]);
    }
    printf("\nMode switch occurs at: ");
    for (i=0; i<=n; i++)
    {
        printf("\t%d ms", context_switch[i]);
    }
}

