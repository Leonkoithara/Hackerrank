#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void heapSort(int [], int);
void heapify(int [], int, int);

long int marcsCakewalk(int calorie_size, int* calorie) 
{
    long int result=0;
	int i;

	heapSort(calorie, calorie_size);

	for(i=calorie_size-1;i>=0;i--)
	{
		result += calorie[i]*pow(2, calorie_size-i-1); 
	}

	return result;
}

int main() 
{
    int n; 
    scanf("%i", &n);
    int *calorie = malloc(sizeof(int) * n);

    for (int calorie_i = 0; calorie_i < n; calorie_i++) 
	{
       scanf("%i",&calorie[calorie_i]);
    }

    long int result = marcsCakewalk(n, calorie);
    printf("%ld\n", result);
    return 0;
}

void heapify(int arr[], int n, int i)
{
	int temp;
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {
        temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
// main function to do heap sort
void heapSort(int arr[], int n)
{
	int temp, i;
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}


