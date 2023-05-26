#include <stdio.h>
/* #include <conio.h> */
#include <stdlib.h>

struct PCB
{
	int proc_no, arrival_time, burst_time, priority, waiting_time, turnaround_time, rt;
} a[10], temp;

int c = 0, idle = 0, n, con_swt[20], d = 0, opt;
float WTsum, TAsum, WTavg, TAavg, util = 0, uperc;


void input()
{
	int i, j;

	do
	{
		printf("\n Enter number of processes: ");
		scanf_s("%d", &n);

		if(n < 1)
		{
			system("cls");
			printf("\n Number of processes must be > 0");
		}
	}
	while(n < 1);

	for(i = 0; i < n; i++)
	{
		a[i].proc_no = i;
		printf("\n For Process %d", i);
		printf(" Arrival Time of P[%d] = ", i);
		scanf_s("%d", &a[i].arrival_time);
		printf(" Burst Time of P[%d] = ", i);
		scanf_s("%d", &a[i].burst_time);
		printf(" Priority of P[%d] = ", i);
		scanf_s("%d", &a[i].priority);
		util += a[i].burst_time;
		a[i].rt = a[i].burst_time;
		printf("\n");
	}

	system("cls");
	if(opt == 1)
		printf("\nStatic Priority Scheduling:\n");
	else
		printf("\nDynamic Priority Scheduling:\n");
	printf(" Process   Arrival time   Burst time   Priority\n");
	for(i = 0; i < n; i++)
		printf(" P%d            %d ms          %d ms        %d\n", i, a[i].arrival_time, a[i].burst_time, a[i].priority);

//	sorting acc. to increasing arrival time
	for(i = 0; i < n; i++)
	{
		for(j = i + 1; j < n; j++)
		{
			if(a[j].arrival_time < a[i].arrival_time)
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

//sorting acc. to decreasing priority
void sort(int x)
{
	int i, j, min, flag = 0;
	min = a[x].priority;

	for(j = x + 1; j < n; j++)
	{
		if(a[j].arrival_time > c)
			break;

		if(a[j].priority < min)
		{
			min = a[j].priority;
			i = j;
			flag = 1;
		}
	}

	if(flag)
	{
		if(con_swt[d - 1] != c && opt == 2)
			con_swt[d++] = c;
		temp = a[x];
		a[x] = a[i];
		a[i] = temp;
	}
}

void sps()
{
	int i;

	for(i = 0; i < n; i++)
	{
		if(c < a[i].arrival_time)
		{
			idle += a[i].arrival_time - c;
			if(c)
				con_swt[d++] = c;
			c = a[i].arrival_time;
		}

		con_swt[d++] = c;
		sort(i);
		a[i].waiting_time = c - a[i].arrival_time;
		a[i].turnaround_time = a[i].waiting_time + a[i].burst_time;
		WTsum += a[i].waiting_time;
		TAsum += a[i].turnaround_time;
		c += a[i].burst_time;
	}
	con_swt[d++] = c;
	WTavg = WTsum / n;
	TAavg = TAsum / n;
	uperc = util / c * 100;
}

void dps()
{
	int i;

	for(i = 0; i < n; i++)
	{
		if(c < a[i].arrival_time)
		{
			idle += a[i].arrival_time - c;
			if(c)
				con_swt[d++] = c;
			c = a[i].arrival_time;
		}

		con_swt[d++] = c;
		while(a[i].rt != 0)
		{
			sort(i);
			c++;
			a[i].rt--;
		}

		a[i].turnaround_time = c - a[i].arrival_time;
		a[i].waiting_time = a[i].turnaround_time - a[i].burst_time;
		WTsum += a[i].waiting_time;
		TAsum += a[i].turnaround_time;
	}
	con_swt[d++] = c;
	WTavg = WTsum / n;
	TAavg = TAsum / n;
	uperc = util / c * 100;
}

int main()
{
	int i, j;
	//clrscr();

flag:
	printf("Enter 1 For Static and 2 for Dynamic Priority Scheduling: ");
	scanf_s("%d", &opt);

	switch(opt)
	{
	case 1:
		input();
		sps();
		break;
	case 2:
		input();
		dps();
		break;
	case 3:
		printf("\n Thank you");
		exit(0);
	default:
		printf("\n Wrong choice\n");
		goto flag;
	}

	for(i = 0; i < n; i++)
	{
		for(j = i + 1; j < n; j++)
		{
			if(a[j].proc_no < a[i].proc_no)
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}

	printf("\n Output: (lower number is higher priority)\n");
	printf(" Process   Waiting time   Turnaround time\n");
	for(i = 0; i < n; i++)
		printf(" P%d            %d ms            %d ms\n", a[i].proc_no, a[i].waiting_time, a[i].turnaround_time);

	printf(" \nAverage waiting time: %.3f ms\n", WTavg);
	printf(" Average turnaround time: %.3f ms\n", TAavg);
	printf(" CPU utilization time: %.3f ms\n", util);
	printf(" CPU utilization percentage: %.3f %%\n", uperc);
	printf(" CPU idle time: %.3f ms\n", (float)idle);
	printf("\n Context switch points:");
	for(i = 0; i < d; i++)
	{
		printf(" %d ms ", con_swt[i]);
		if(i == 0)
			printf(" OS -> Process ");
		else if(i == d - 1)
			printf(" Process -> OS");
		else
			printf(" Process -> OS -> Process ");
	}
	printf("\n Mode switch points:");
	for(i = 0; i < d; i++)
	{
		printf(" %d ms ", con_swt[i]);
		if(i == 0)
			printf(" Kernel -> User ");
		else if(i == d - 1)
			printf(" User -> Kernel ");
		else
			printf(" User -> Kernel -> User ");
	}

	/* getch(); */
	return 0;
}

