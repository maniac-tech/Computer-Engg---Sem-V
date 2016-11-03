#include <stdio.h>

void main()
{
	char pn[10];
	int arr[10], bur[10], star[10], finish[10], tat[10], wt[10], i, n;
	int ttotwt=0, tottat=0;
	printf("Enter the number of processes\n");
	scanf("%d",&n);

	for (i=0;i<n;i++)
	{
		printf("Enter the process name, Arrival time & Burst Time");
		scanf ("%s %d %d",&pn[i],&arr[i],&bur[i]);
	}
	for (i=0;i<n;i++)
	{
		if (i==0)
		{
			star[i]=arr[i];
			wt[i]=star[i]-arr[i];
			finish[i]=star[i]+bur[i];
			tat[i]=finish[i]-arr[i];
		}
		else
		{
			star[i]=finish[i-1];
			wt[i]=star[i]-arr[i];
			finish[i]=star[i]+bur[i];
			tat[i]=finish[i]-arr[i];
		}
	}
	printf("\nPName ArrTime BurstTime Start TAT Finish");
	for (i=0;i<n;i++)
	{
		printf("\n%c \t%6d \t\t%6d \t%6d \t%6d \t%6d",pn[i],arr[i],bur[i],star[i],tat[i],finish[i]);
		ttotwt+=wt[i];
		tottat+=tat[i];
	}
	printf("Average Waiting time:%f",(float)(ttotwt)/n );
	printf("Average Turn around time:%f\n",(float)tottat/n );
}
}