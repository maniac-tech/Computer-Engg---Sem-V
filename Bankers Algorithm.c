#include <stdio.h>

//in a nutshell
/*	get rows and colums
	get claim matrix
	get allocated matrix
	calc need matrix = claim matrix - allocated matrix
	print nedd matrix
	get availble matrix
	print claim,allocated,available matrix
	logic if available > need then safe else unsafe
	print safe or unsafe state*/

void main(){

	int cl[10][10],al[10][10],av[10],i,j,k,m,n,ne[10][10],flag=0;

	printf("\nEnter the matrix");
	scanf("%d %d",&m,&n);

	printf("\nEnter the claim matrix:");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&cl[i][j]);
		}
	}

	printf("\nEnter allocated matrix:");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&al[i][j]);
		}
	}

	printf("\nThe need matrix:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			ne[i][j]=cl[i][j]-al[i][j];
			printf("\t%d",ne[i][j]);
		}
		printf("\n");
	}

	printf("\nEnter avaliable matrix");
	for(i=0;i<n;i++)
		scanf("%d",&av[i]);

	printf("Claim matrix:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("\t%d",cl[i][j]);
		}
		printf("\n");
	}

	printf("\n Allocated matrix:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("\t%d",al[i][j]);
		}
		printf("\n");
	}

	printf("Available matrix:\n");
	for(i=0;i<n;i++){
		printf("%d\t",av[i]);
	}

	//for(k=0;k<m;k++)
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(av[j]>=ne[i][j])
				flag=1;
			else
				flag=0;
		}
	}

	if(flag==0)
		printf("Unsafe State");
	else
		printf("Safe State");

}