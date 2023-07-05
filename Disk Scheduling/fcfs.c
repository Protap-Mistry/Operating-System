/*
	Disk Scheduling
	First Come First Serve
*/
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
int main()
{
	int i,no_of_requests,initial_head;
	printf("Enter the number of requests w/o head: ");
	scanf("%d",&no_of_requests);

	int request[no_of_requests];
	printf("\nEnter the request: \n");
	for (i = 0; i < no_of_requests; ++i)
	{
        printf("Request[%d]: ", i+1);
		scanf("%d",&request[i]);
	}

	printf("\nEnter initial position of R/W head: \n");
	scanf("%d",&initial_head);

	int seek_time=0;
	printf("Sequence: %d -> ",initial_head );
	for(i=0;i<no_of_requests;i++)
	{
		if(i == no_of_requests-1)
			printf("%d\n", request[i] );
		else
			printf("%d -> ", request[i] );
		seek_time += abs(request[i] - initial_head);
		initial_head = request[i];
	}
	printf("Seek Time: %d\n", seek_time);
}
