#include <stdio.h>
#include <stdlib.h>

/* Recursive function to verify the heap */
void MaxHeapify(char* A, int i, int n)
{
	int aux, left = 2 * i, right = 2 * i + 1, bigger;
	if ((A[i] < A[left]) && (left <= n) && (left >= 1))
	{
		bigger = left;
	}
	else
	{
		bigger = i;
	}
	if ((A[bigger] < A[right]) && (right <= n) && (right >= 1))
	{
		bigger = right;
	}
	if (bigger != i)
	{
		aux = A[bigger];
		A[bigger] = A[i];
		A[i] = aux;
		MaxHeapify(A, bigger, n);
	}
}

/* Function to make the heap */
void Build_Max_Heap(char* A, int n)
{
	for (int i = n/2; i > 0; i--)
	{
		MaxHeapify(A, i, n);
	}
}

void Heap_Sort(char* A, int n)
{
	int aux, size = n, i;
	Build_Max_Heap(A, n);
	for (int i = 1; i <= 12; i++)
	{
		printf("%c ", A[i]);
	}
	for (i = 1; i <= n - 1; i++)
	{
		aux = A[1];
		A[1] = A[size];
		A[size] = aux;
		size--;
		MaxHeapify(A, 1, size);
	}
}

int main()
{
	char A[13];
	A[1] = 'F';
	A[2] = 'E';
	A[3] = 'R';
	A[4] = 'N';
	A[5] = 'A';
	A[6] = 'N';
	A[7] = 'D';
	A[8] = 'A';
	A[9] = 'M';
	A[10] = 'E';
	A[11] = 'L';
	A[12] = 'O';
	Heap_Sort(A, 12);
	/*for (int i = 1; i <= 12; i++)
	{
		printf("%c ", A[i]);
	}*/
}