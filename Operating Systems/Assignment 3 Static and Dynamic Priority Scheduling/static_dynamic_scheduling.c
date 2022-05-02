#include <stdio.h>
/* #include <conio.h> */
#include <stdlib.h>

struct PCB
{
	int p, at, bt, pr, wt, ta, rt;
}a[10], t;

int c=0, idle=0, n, con_swt[20], d=0, opt;
float WTsum, TAsum, WTavg, TAavg, util=0, uperc;


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
	
	for(i=0;i<n;i++)
	{
		a[i].p=i;
		printf("\n For Process %d", i);
		printf(" Arrival Time of P[%d] = ", i);
		scanf("%d", &a[i].at);
		printf(" Burst Time of P[%d] = ", i);
		scanf("%d", &a[i].bt);
		printf(" Priority of P[%d] = ", i);
		scanf("%d", &a[i].pr);
		util+=a[i].bt;
		a[i].rt=a[i].bt;
		printf("\n");
	}
	
	system("cls");
	if(opt==1)
	printf("\nStatic Priority Scheduling:\n");
	else
	printf("\nDynamic Priority Scheduling:\n");
	printf(" Process   Arrival time   Burst time   Priority\n");
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

//sorting acc. to decreasing priority
void sort(int x)
{
	int i, j, min, flag=0;
	min = a[x].pr;
	
	for(j=x+1;j<n;j++)
	{
		if(a[j].at>c)
		break;
		
		if(a[j].pr<min)
		{
			min = a[j].pr;
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

void sps()
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
		}
		
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
	uperc=util/c*100;
}

void dps()
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
		}
		
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
	uperc=util/c*100;
}

int main()
{
	int i, j;
	//clrscr();
	
	flag:
	printf("Enter 1 For Static and 2 for Dynamic Priority Scheduling: ");
	scanf("%d", &opt);
	
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
	
	printf("\n Output: (lower number is higher priority)\n");
	printf(" Process   Waiting time   Turnaround time\n");
	for(i=0;i<n;i++)
	printf(" P%d            %d ms            %d ms\n", a[i].p, a[i].wt, a[i].ta);
	
	printf(" \nAverage waiting time: %.3f ms\n", WTavg);
	printf(" Average turnaround time: %.3f ms\n", TAavg);
	printf(" CPU utilization time: %.3f ms\n", util);
	printf(" CPU utilization percentage: %.3f %%\n", uperc);
	printf(" CPU idle time: %.3f ms\n", (float)idle);
	printf("\n Context switch points:");
	for(i=0;i<d;i++)
	{
		printf(" %d ms ", con_swt[i]);
		if(i==0)
		printf(" OS -> Process ");
		else if(i==d-1)
		printf(" Process -> OS");
		else
		printf(" Process -> OS -> Process ");
	}
	printf("\n Mode switch points:");
	for(i=0;i<d;i++)
	{
		printf(" %d ms ", con_swt[i]);
		if(i==0)
		printf(" Kernel -> User ");
		else if(i==d-1)
		printf(" User -> Kernel ");
		else
		printf(" User -> Kernel -> User ");
	}
	
	/* getch(); */
    return 0;
}

