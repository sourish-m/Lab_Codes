#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void input();
void sort(int);
void sjf();
void srtf();
int time(int);

struct PCB
{
	int p, at, bt, pr, wt, ta, rt;
}a[10], t;

int c=0, idle=0, n, con_swt[20], d=0, opt;
float WTsum, TAsum, WTavg, TAavg, util_time=0, util_perc;

void main()
{
	int i, j;
	//clrscr();
	
	flag:
	printf("\nPress 1 for SJF and 2 for SRTF\n");
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
	
	printf("\n Output:\n");
	printf(" Process   Waiting time   Turnaround time\n");
    printf("===========================================\n");
	for(i=0;i<n;i++)
	printf(" P%d            %d ms            %d ms\n", a[i].p, a[i].wt, a[i].ta);
	
	printf("\n\n Average waiting time is  %.3f ms\n", WTavg);
	printf("\n Average turnaround time is %.3f ms\n", TAavg);
	printf("\n CPU idle time is %.3f ms\n", (float)idle);
	printf("\n CPU utilization time is %.3f ms\n", util_time);
	printf("\n CPU util. %% is %.3f %%\n", util_perc);
	printf("\n Context switch occurs at:");
	for(i=0;i<d;i++)
	{
		printf("\n%d ms", con_swt[i]);
        if (i==0)
            printf(" (OS to Process)\n");
        else if (i==d-1)
            printf(" (Process to OS)\n");
        else
            printf(" (Process to OS to Process)\n");
	}
	printf("\n Mode switch occurs at:\n");
	for(i=0;i<d;i++)
	{
		printf("\t%d ms", con_swt[i]);
        if (i==0)
            printf(" (Kernel to User)\n");
        else if (i==d-1)
            printf(" (User to Kernel)\n");
        else
            printf(" (User to Kernel to User)\n");
	}
	
	getch();
}

void input()
{
	int i, j;
	
	do
	{
		printf("\n Enter no. of processes: ");
		scanf("%d", &n);
		
	}while(n<1);
	
	for(i=0;i<n;i++)
	{
		a[i].p=i;
		printf("\n for Process %d, ", i);
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
	printf("\nSJf Scheduling:\n");
	else
	printf("\nSRTF Scheduling:\n");
	printf(" Process   Arrival time   Burst time   Priority\n");
    printf("=================================================\n");
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

//sorting acc. to increasing burst/remaining time
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
		if(c<a[i].at)
		{
			idle+=a[i].at-c;
			if(c)
			con_swt[d++]=c;
			c=a[i].at;
			con_swt[d++]=c;
		}
		
		if(con_swt[d-1]!=c)
		con_swt[d++]=c;
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
		if(c<a[i].at)
		{
			idle+=a[i].at-c;
			if(c)
			con_swt[d++]=c;
			c=a[i].at;
			con_swt[d++]=c;
		}
		
		if(con_swt[d-1]!=c)
		con_swt[d++]=c;
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

int time(int x)
{
	if(opt==1)
	return a[x].bt;
	else
	return a[x].rt;
}

