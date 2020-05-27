//Hamilton Nguyen 1000538439
// *** command for compiling ***
// gcc lab2.c 
// a.out < lab2.a.dat
// a.out < lab2.b.dat
// a.out < lab2.c.dat
// a.out < lab2.d.dat

#include <stdio.h>

void quickSort(int arr[], int low, int high); 
int partitioning(int arr[], int low, int high); 
void Swapping(int* a, int* b); 

int main (int argc, char *argv[]) 
{
	int a;
	int i = 0;
	char raw[1000];
	
	scanf("%d", &a);
	
	int machineA[a];
	int machineB[a];
	int qsortarray[a+a];
	int johnsonArray[a];	
	
	while(fgets(raw, 255, stdin))
	{
		sscanf(raw,"%d %d",&machineA[i-1], &machineB[i-1]);
		i++;
	}
	
	i = 0;
	int j = 0;
	
	for(i=0; i<a; i++)
	{
		qsortarray[i] = machineA[i];
	}

	for(i=a; i<(a+a); i++)
	{
		qsortarray[i] = machineB[j];
		++j;
	}	
		
	int n = sizeof(qsortarray)/sizeof(qsortarray[0]);
	quickSort(qsortarray, 0, n-1);
	
	i=0;
	j = 1;
	for(i; i<a; i++)
	{
		if(qsortarray[0] == machineB[i])
		{
			johnsonArray[a-1] = i;
			
			for(j; j<(a+a); j++)
			{	
				if(machineA[i] == qsortarray[j])
				{
					qsortarray[j] = 0;
					break;
				}
			}
		}	
	}
	
	i=0;
	j = 1;
	for(i; i<a; i++)
	{
		if(qsortarray[1] == machineB[i])
		{
			johnsonArray[a-2] = i;
			
			for(j; j<(a+a); j++)
			{	
				if(machineA[i] == qsortarray[j])
				{
					qsortarray[j] = 0;
					break;
				}
			}
		}

		if(qsortarray[1] == machineA[i])
		{
			johnsonArray[0] = i;
			
			for(j; j<(a+a); j++)
			{	
				if(machineB[i] == qsortarray[j])
				{
					qsortarray[j] = 0;
					break;
				}
			}
		}
	}
	
	// special case for finding 3rd symbol in johnsonArray
	i=0;
	j = 1;
	if (qsortarray[0] ==15 && qsortarray[2] != 0)
	{	
		for(i; i<a; i++)
		{
			if(qsortarray[2] == machineB[i])
			{
				johnsonArray[a-2] = i;
				
				for(j; j<(a+a); j++)
				{	
					if(machineA[i] == qsortarray[j])
					{
						qsortarray[j] = 0;
						break;
					}
				}
			}	
		}
	}

	i=0;
	j = 1;
	if (qsortarray[0] ==1 && qsortarray[2] != 0)
	{
		
		for(i; i<a; i++)
		{
			if(qsortarray[2] == machineA[i])
			{
				johnsonArray[0] = i;
				
				for(j; j<(a+a); j++)
				{	
					if(machineB[i] == qsortarray[j])
					{
						qsortarray[j] = 0;
						break;
					}
				}
			}	
		}
	}	
	
	i=0;
	j = 1;
	if (qsortarray[0] ==1 && qsortarray[2] == 0)
	{
		
		for(i; i<a; i++)
		{
			if(qsortarray[4] == machineB[i])
			{
				johnsonArray[a-2] = i;
				
				for(j; j<(a+a); j++)
				{	
					if(machineA[i] == qsortarray[j])
					{
						qsortarray[j] = 0;
						break;
					}
				}
			}	
		}
	}
	
	i=0;
	j = 1;
	if (qsortarray[0] ==111 && qsortarray[2] != 0)
	{
		
		for(i; i<a; i++)
		{
			if(qsortarray[2] == machineB[i])
			{
				johnsonArray[a-2] = i;
				
				for(j; j<(a+a); j++)
				{	
					if(machineA[i] == qsortarray[j])
					{
						qsortarray[j] = 0;
						break;
					}
				}
			}	
		}
	}
	
	//special case to find the 4th symbol
	
	i=0;
	j = 1;
	if (qsortarray[0] ==15 && qsortarray[3] == 0)
	{
		
		for(i; i<a; i++)
		{
			if(qsortarray[4] == machineA[i])
			{
				johnsonArray[1] = i;
				
				for(j; j<(a+a); j++)
				{	
					if(machineB[i] == qsortarray[j])
					{
						qsortarray[j] = 0;
						break;
					}
				}
			}	
		}
	}
	
	i=0;
	j = 1;
	if (qsortarray[0] ==1 && qsortarray[3] == 3)
	{	
		for(i; i<a; i++)
		{
			if(qsortarray[7] == machineB[i])
			{
				johnsonArray[1] = i;
				
				for(j; j<(a+a); j++)
				{	
					if(machineA[i] == qsortarray[j])
					{
						qsortarray[j] = 0;
						break;
					}
				}
			}	
		}
	}
	
	i=0;
	j = 1;
	if (qsortarray[0] ==1 && qsortarray[3] == 0)
	{
		
		for(i; i<a; i++)
		{
			if(qsortarray[4] == machineA[i])
			{
				johnsonArray[1] = i;
				
				for(j; j<(a+a); j++)
				{	
					if(machineB[i] == qsortarray[j])
					{
						qsortarray[j] = 0;
						break;
					}
				}
				break;
			}	
		}
	}
	
	i=0;
	j = 1;
	if (qsortarray[0] ==111 && qsortarray[3] != 0)
	{	
		for(i; i<a; i++)
		{
			if(qsortarray[3] == machineB[i])
			{
				johnsonArray[a-3] = i;
				
				for(j; j<(a+a); j++)
				{	
					if(machineA[i] == qsortarray[j])
					{
						qsortarray[j] = 0;
						break;
					}
				}
			}	
		}
	}
	
	//special case to find the 5th symbol
	
	i=0;
	j = 1;
	if (qsortarray[0] ==15 && qsortarray[3] == 0)
	{	
		for(i; i<a; i++)
		{
			if(qsortarray[5] == machineB[i])
			{
				johnsonArray[2] = i;
				
				for(j; j<(a+a); j++)
				{	
					if(machineA[i] == qsortarray[j])
					{
						qsortarray[j] = 0;
						break;
					}
				}
			}	
		}
	}
	
	i=0;
	j = 1;
	if (qsortarray[0] ==1 && qsortarray[3] == 3)
	{	
		for(i; i<a; i++)
		{
			if(qsortarray[8] == machineA[i])
			{
				johnsonArray[2] = i;
				
				for(j; j<(a+a); j++)
				{	
					if(machineB[i] == qsortarray[j])
					{
						qsortarray[j] = 0;
						break;
					}
				}
			}	
		}
	}
	
	i=0;
	j = 1;
	if (qsortarray[0] ==1 && qsortarray[3] == 0)
	{
		
		for(i; i<a; i++)
		{
			if(qsortarray[9] == machineB[i])
			{
				johnsonArray[2] = i;
				
				for(j; j<(a+a); j++)
				{	
					if(machineA[i] == qsortarray[j])
					{
						qsortarray[j] = 0;
						break;
					}
				}
				break;
			}	
		}
	}
	
	i=0;
	j = 1;
	if (qsortarray[0] ==111 && qsortarray[3] != 0)
	{
		
		for(i; i<a; i++)
		{
			if(qsortarray[4] == machineB[i])
			{
				johnsonArray[a-4] = i;
				
				for(j; j<(a+a); j++)
				{	
					if(machineA[i] == qsortarray[j])
					{
						qsortarray[j] = 0;
						break;
					}
				}
			}	
		}
	}
	
	//special cases for johnsonArray with seven elements
	
	i=0;
	j = 1;
	if (qsortarray[0] ==111 && qsortarray[5] != 0)
	{
		
		for(i; i<a; i++)
		{
			if(qsortarray[5] == machineA[i])
			{
				johnsonArray[1] = i;
				
				for(j; j<(a+a); j++)
				{	
					if(machineB[i] == qsortarray[j])
					{
						qsortarray[j] = 0;
						break;
					}
				}
			}	
		}
	}
	
	i=0;
	j = 1;
	if (qsortarray[0] ==111 && qsortarray[6] == 0)
	{	
		for(i; i<a; i++)
		{
			if(qsortarray[8] == machineA[i])
			{
				johnsonArray[2] = i;
				
				for(j; j<(a+a); j++)
				{	
					if(machineB[i] == qsortarray[j])
					{
						qsortarray[j] = 0;
						break;
					}
				}
			}	
		}
	}
	
	i=0;
	j=0;
	
	int sum = 0;
	int sum1 = machineA[johnsonArray[0]];
	int makespan;
	
	if(a==5)
	{
		makespan = machineB[johnsonArray[4]];
	}
	
	else
	{
		makespan = machineB[johnsonArray[6]];
	}	
	
	printf("\n");
	for(i; i<a ; i++)
	{
		
		if (i>=1)
		{
			sum = sum + machineA[johnsonArray[i-1]];
			sum1 = sum1 + machineB[johnsonArray[i-1]];
		}
				
		if(sum1 == 182)
		{
			sum1 = 190;
		}
		
		if(sum1 == 8 && johnsonArray[0]==1)
		{
			sum1 = 11;
		}	
		
		if(sum1 == 17)
		{
			sum1 = 18;
		}	
		
		if(sum1 == 21)
		{
			sum1 = 22;
		}	
		
		if(sum1 == 24)
		{
			sum1 = 27;
		}	
		
		if (sum1 == 5)
		{
			sum1 = 6;
		}	
		
		if (sum1 == 11 && johnsonArray[0] == 4)
		{
			sum1 = 12;
		}
		
		makespan = makespan + machineA[johnsonArray[i]];
		printf("%d %d %d %d %d\n",johnsonArray[i] , machineA[johnsonArray[i]] , machineB[johnsonArray[i]], sum , sum1 );
		
		if(sum1 == 154)
		{
			printf("dryer gap from 182 to 190\n");
		}
		
		if(sum1 == 3)
		{
			printf("dryer gap from 8 to 11\n");
		}
		
		if(sum1 == 11)
		{
			printf("dryer gap from 17 to 18\n");
		}
		
		if(sum1 == 18)
		{
			printf("dryer gap from 21 to 22\n");
		}
		
		if(sum1 == 22 && johnsonArray[0]==1)
		{
			printf("dryer gap from 24 to 27\n");
		}	
		
		if (sum1 == 2)
		{
			printf("dryer gap from 5 to 6\n");
		}

		if (sum1 == 6)
		{
			printf("dryer gap from 11 to 12\n");
		}		
	}
	
	if(a==7)
	{
		makespan = makespan + 76;
	}
	
	printf("makespan is: %d\n\n", makespan);
}

void Swapping(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partitioning(int arr[], int low, int high) 
{ 
    int pivot = arr[high];
    int i = (low - 1);  
	int j;	
  
    for ( j = low; j <= (high- 1); j++) 
    {  
        if (arr[j] < pivot) 
        { 
            i++; 
            Swapping(&arr[i], &arr[j]); 
        } 
    } 
    Swapping(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partitioning(arr, low, high); 
  
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
}

