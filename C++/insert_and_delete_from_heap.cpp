#include <iostream>
using namespace std;

typedef struct heap{
	int arr[100];
	int heapSize;
} HEAP;

void empty(HEAP &h)
{
	h.heapSize=0;
}

bool isEmpty(HEAP h)
{
	if(h.heapSize==0)
		return true;
	else
		return false;
}

void insert(HEAP &h, int val)
{
	int i=h.heapSize;
	h.arr[i]=val;
	h.heapSize++;
	while(i>=1 && h.arr[(i-1)/2]<val)
	{
		h.arr[i]=h.arr[(i-1)/2];
		i=(i-1)/2;
	}
	h.arr[i]=val;
}

int maximum(HEAP h)
{
	return h.arr[0];
}
void swap(int &a, int &b)
{
	int temp=a;
	a=b;
	b=temp;
}

void fixHeap(int arr[], int heapSize)
{
	int i=0, maxIndex, temp;
	bool exit=false;
	while((2*i)+1<=heapSize && exit==false)
	{
		if((2*i)+2<=heapSize)
		{
			if(arr[(2*i)+1]>arr[(2*i)+2])
				maxIndex = 2*i+1;
			else
				maxIndex = 2*i+2;
			if(arr[i] < arr[maxIndex])
			{
				swap(arr[i], arr[maxIndex]);
				i=maxIndex;
			}
			else
				exit=true;
		}
		else
		{
			if(arr[i] < arr[(2*i)+1])
				swap(arr[i], arr[(2*i)+1]);
			else
				exit=true;
		}
	}
}
//4 9 5 8 6 2 1 3 7 4
//0 1 2 3 4 5 6 7 8 9
//heapsize=9
void deleteMax(HEAP &h)
{
	h.arr[0]=h.arr[h.heapSize-1];
	h.heapSize--;
	fixHeap(h.arr, h.heapSize);
}

void printHeap(HEAP h)
{
	for(int i=0; i<h.heapSize; i++)
		cout << h.arr[i] << " ";
	cout << endl;
}

void main()
{
	HEAP heap;
	empty(heap);
	insert(heap, 5);
	insert(heap, 3);
	insert(heap, 8);
	insert(heap, 4);
	insert(heap, 9);
	insert(heap, 2);
	insert(heap, 1);
	insert(heap, 10);
	insert(heap, 7);
	insert(heap, 6);
	cout << "After insertion: ";
	printHeap(heap);
	for(int i=1; i<=5; i++)
	{
		cout << "After " << i << " deletions: ";
		deleteMax(heap);
		printHeap(heap);
	}
	system("pause");
}

/*
After insertion: 10 9 5 8 6 2 1 3 7 4
After 1 deletions: 9 8 5 7 6 2 1 3 4
After 2 deletions: 8 7 5 4 6 2 1 3
After 3 deletions: 7 6 5 4 3 2 1
After 4 deletions: 6 4 5 1 3 2
After 5 deletions: 5 4 2 1 3
Press any key to continue . . .
*/