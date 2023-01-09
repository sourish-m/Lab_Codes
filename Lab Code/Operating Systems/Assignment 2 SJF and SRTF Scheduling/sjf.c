#include <stdio.h>
#include <stdlib.h>

struct proc
{
	int p, at, bt, wt, ta, rt;
}a[10], t;

int c=0, idle=0, n, con_swt[20], d=0, opt;
float WTsum, TAsum, WTavg, TAavg, util_time=0, util_perc;
//clrscr();


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
	
	printf("\n Enter Arrival time, Burst time for processes:\n");
	for(i=0;i<n;i++)
	{
		a[i].p=i;
		printf("\n Process %d", i);
		printf(" AT[%d] = ", i);
		scanf("%d", &a[i].at);
		printf(" BT[%d] = ", i);
		scanf("%d", &a[i].bt);
		util_time+=a[i].bt;
		a[i].rt=a[i].bt;
		printf("\n");
	}
	
	system("cls");
    printf("Input Data--\n");
	printf(" Process   Arrival time   Burst Time\n");
    printf("=======================================\n");
	for(i=0;i<n;i++)
	{
		printf(" P%d \t\t%d ms \t\t%d ms\n", i, a[i].at, a[i].bt);
	}
	
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
	WTavg=WTsum/n;
	TAavg=TAsum/n;
	util_perc=util_time/c*100;
}


int main()
{
	int i, j;
	
	flag:
	printf("\n Press 1 for SJF and 2 for SRTF scheduling: ");
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
    printf("\nOutput Data---\n");
	printf("\nProcess Name\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
	printf("==================================================================================================\n");
	for (i = 0; i < n; i++)
	{
		printf("  P%d\t\t  %d\t\t  %d\t\t %d\t\t %d\t\t\n", i, a[i].at, a[i].bt, a[i].wt,a[i].ta);
	}
	printf("\nAverage Waiting Time is: %lf\nAverage Turnaround Time is: %lf\n", WTavg, TAavg);
	printf(" CPU Utilization Time: %.3f ms\n", util_time);
	printf(" CPU Utilization Percentage: %.3f %%\n", util_perc);
	printf(" CPU Idle Time: %.3f ms\n", (float)idle);
    printf("\nContext switch occurs at: ");
    for (i=0; i<d; i++)
    {
		printf("\t %d ms", con_swt[i]);
    }
	
	/* getch(); */
    return 0;
}
