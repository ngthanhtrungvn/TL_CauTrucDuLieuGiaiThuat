//tim vung nho dau tien co kich thuoc du chua process.
#include<stdio.h>
#include<conio.h> 
void main()
{
	int blockSize[10];//kich thuoc cua 1 khoi bo nho
	int processSize[10];//kich thuoc cua 1 quy trinh
	int blockNo;//so khoi 
	int processNo;//qua trinh
	int flags[10];//co`
	int allocation[10];//phan bo
	int i, j;

	for(i = 0; i < 10; i++)
	{
		flags[i] = 0;
		allocation[i]= -1;
	}

	printf("Enter no. of blocks: ");
	scanf("%d", &blockNo);

	printf("\nEnter size of each block: ");
	for(i = 0; i < blockNo; i++)
		scanf("%d", &blockSize[i]);
	printf("\nEnter no. of process: ");
	scanf("%d", &processNo);

	printf("\nEnter size of each process: ");
	for(i = 0; i < processNo; i++)
		scanf("%d", &processSize[i]);
	for(i = 0; i < processNo; i++)
		for(j = 0; j < blockNo; j++)
			if(flags[j] == 0 && blockSize[j] >= processSize[i])
			{
				allocation[j] = i;
				flags[j] = 1;
				break;
			}

	printf("\nBlock no. \tsize\t\tprocess no.\t\tsize");
	for(i = 0; i < blockNo; i++)
	{
		printf("\n %d\t\t%d\t\t", i+1, blockSize[i]);
		if(flags[i]==1)
			printf("%d\t\t\t%d", allocation[i]+1, processSize[allocation[i]]);
		else
			printf("No allocated\n");
	}
	getch();
}