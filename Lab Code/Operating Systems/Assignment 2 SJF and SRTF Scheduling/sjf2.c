#include <stdio.h>
/* #include <conio.h> */
#include <stdlib.h>

struct PCB
{
	int p, at, bt, pr, wt, ta, rt;
}a[10], t;

int c=0, idle=0, n, con_swt[20], d=0, opt;
float WTsum, TAsum, WTavg, TAavg, util_time=0, util_perc;


int time(int x)
{
	if(opt==1)
	return a[x].bt;
	else
	return a[x].rt;
}

void input()
{
	int i, j;
	
	do
	{
		printf("\n Enter number of processes: ");
		scanf("%d", &n);
		
		if(n<1)
		{
			system("cls");
			printf("\n Number of processes must be > 0");
		}
	}while(n<1);
	
	printf("\n Enter Arrival time(AT), Burst time(BT) and Priority(PR) for processes:\n");
	for(i=0;i<n;i++)
	{
		a[i].p=i;
		printf("\n Process %d", i);
		line(11);
		printf(" AT[%d] = ", i);
		scanf("%d", &a[i].at);
		printf(" BT[%d] = ", i);
		scanf("%d", &a[i].bt);
		printf(" PR[%d] = ", i);
		scanf("%d", &a[i].pr);
		util_time+=a[i].bt;
		a[i].rt=a[i].bt;
		printf("\n");
	}
	
	system("cls");
	if(opt==1)
	printf("\n --------- SJF Scheduling ---------\n");
	else
	printf("\n --------- SRTF Scheduling ---------\n");
	printf("\n Input: (Lower the num, higher the priority)");
	line(48);
	printf(" Process   Arrival time   Burst time   Priority");
	line(48);
	for(i=0;i<n;i++)
	printf(" P%d            %d ms          %d ms        %d\n", i, a[i].at, a[i].bt, a[i].pr);
	
	//	sorting acc. to increasing arrival time
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[j].at<a[i].at)
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
}

// sorting acc. to increasing burst/remaining time
void sort(int x)
{
	int i, j, min, flag=0;
	min = time(x);
	
	for(j=x+1;j<n;j++)
	{
		if(a[j].at>c)
		break;
		
		if(time(j)<min)
		{
			min = time(j);
			i = j;
			flag=1;
		}
	}
	
	if(flag)
	{
		if(con_swt[d-1]!=c && opt==2)
		con_swt[d++]=c;
		t = a[x];
		a[x] = a[i];
		a[i] = t;
	}
}

void sjf()
{
	int i;
	
	for(i=0;i<n;i++)
	{
		con_swt[d++]=c;
		
		if(c<a[i].at)
		{
			idle+=a[i].at-c;
			c=a[i].at;
			con_swt[d++]=c;
		}
		
		sort(i);
		a[i].wt=c-a[i].at;
		a[i].ta=a[i].wt+a[i].bt;
		WTsum+=a[i].wt;
		TAsum+=a[i].ta;
		c+=a[i].bt;
	}
	con_swt[d++]=c;
	WTavg=WTsum/n;
	TAavg=TAsum/n;
	util_perc=util_time/c*100;
}

void srtf()
{
	int i;
	
	for(i=0;i<n;i++)
	{
		con_swt[d++]=c;
		
		if(c<a[i].at)
		{
			idle+=a[i].at-c;
			c=a[i].at;
			con_swt[d++]=c;
		}
			
		while(a[i].rt!=0)
		{
			sort(i);
			c++;
			a[i].rt--;
		}
		
		a[i].ta=c-a[i].at;
		a[i].wt=a[i].ta-a[i].bt;
		WTsum+=a[i].wt;
		TAsum+=a[i].ta;
	}
	con_swt[d++]=c;
	WTavg=WTsum/n;
	TAavg=TAsum/n;
	util_perc=util_time/c*100;
}

int main()
{
	int i, j;
	//clrscr();
	
	flag:
	printf("\n 1. SJF Scheduling\n 2. SRTF Scheduling\n 3. Exit\n");
	printf("\n Enter choice: ");
	scanf("%d", &opt);
	
	switch(opt)
	{
		case 1:
			input();
			sjf();
			break;
		case 2:
			input();
			srtf();
			break;
		case 3:
			printf("\n Thank you");
			exit(0);
		default:
			printf("\n Wrong choice\n");
			goto flag;
	}
	
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[j].p<a[i].p)
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	
	printf("\n Output:");
	line(42);
	printf(" Process   Waiting time   Turnaround time");
	line(42);
	for(i=0;i<n;i++)
	printf(" P%d            %d ms            %d ms\n", a[i].p, a[i].wt, a[i].ta);
	
	printf("\n\n Average waiting time: %.3f ms\n", WTavg);
	printf("\n Average turnaround time: %.3f ms\n", TAavg);
	printf("\n CPU utilization time: %.3f ms\n", util_time);
	printf("\n CPU utilization percentage: %.3f %%\n", util_perc);
	printf("\n CPU idle time: %.3f ms\n", (float)idle);
	printf("\n Context switch points:");
	for(i=0;i<d;i++)
	{
		printf("\n -> %d ms", con_swt[i]);
		if(i==0)
		printf(" | First process is loaded");
		else if(i==d-1)
		printf(" | Final process is saved\n");
		else
		printf(" | Previous process is saved, another process is loaded(restored)");
	}
	printf("\n Mode switch points:");
	for(i=0;i<d;i++)
	{
		printf("\n -> %d ms", con_swt[i]);
		if(i==0)
		printf(" | Kernel -> User");
		else if(i==d-1)
		printf(" | User -> Kernel");
		else
		printf(" | User -> Kernel -> User");
	}
	
	/* getch(); */
    return 0;
}
