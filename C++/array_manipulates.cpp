#include <iostream>
using namespace std;

const int SIZE=5;

void squareIndex(int arr[], int size);
void fibArray(int A[], int n);
void leapToIndex(int arr[], int size, int leap, int num);
void fillWithNum(int arr[], int size, int num);

void squareIndex(int arr[] ,int size)
{
	int *p;

	for(p=arr; p<arr+size; p++)
	{
		*p = (p-arr)*(p-arr);
		cout << *p << " "; 
	}
	cout << endl;
}

void fibArray(int A[], int n)
{
	int *a, *b, *temp, sum;
	for(a=A+1, b=A+2; b<A+n;)
	{
		sum=*a+*b;
		temp=a;
		a=b;
		b=b+*temp;
		*b=sum;
	}

	for(int i=0; i<n; i++)
		cout << A[i] << " ";

	cout<<endl;
}

void leapToIndex(int arr[], int size, int leap, int num)
{
	int *p;
	for (p=arr; p<arr+size; p+=leap)
		*p=num;
}

void fillWithNum(int arr[], int size, int num)
{
	int* p ;
	for(p=arr; p<arr+size; p++)
		*p=num;
}

void main()
{
	int choose;
	do
	{
		cout << ("Please choose the desired program (type -1 to end)\n");
		cin >> choose;
		flushall();

		switch(choose)
		{
			case 1:
			{
				int arr[10];
				int size = sizeof(arr)/sizeof(arr[0]);

				squareIndex(arr, size);
			
				break ;
			}
/*
0 1 4 9 16 25 36 49 64 81
*/

			case 2:
			{
				int arr[25] = {0,1,2};
				int size = sizeof(arr) / sizeof(arr[0]);
				for (int i=3; i<size; i++)
					arr[i]=-1;
				cout << "The fibonacci series is: " << endl;
				fibArray(arr, size);

				break ;
			}
/*
The fibonacci series is: 
0 1 2 3 -1 5 -1 -1 8 -1 -1 -1 -1 13 -1 -1 -1 -1 -1 -1 -1 21 -1 -1 -1
*/

			case 3:
			{
				int arr1[] = {1,2,3,4,5}, arr2[] = {6,7,8,9,10}, arr3[] = {11,12,13,14,15}, arr4[] = {16,17,18,19,20}; 
				int* A[] = {arr1, arr2, arr3, arr4};
				int sizeOfA = sizeof(A) / sizeof(A[0]);
				int sizeOfArr = sizeof(arr1) / sizeof(arr1[0]);

				cout << "The even numbers are:" << endl;
				for(int** i=A; i<A+sizeOfA ;i++) 
					for(int* j=*i; j<*i+sizeOfArr; j++)
						if(*j%2==0)
							cout << *j << " ";
				cout << endl;

				break ;
			}
/*
The even numbers are:
2 4 6 8 10 12 14 16 18 20
*/

			case 4:
			{
				int mat[10][10];

				for(int i=0; i<10; i++)
					leapToIndex((int*)mat+i, 100-i, 10, i);

				for(int i=0; i<10; i++)
				{
					for(int j=0; j<10; j++)
						cout << mat[i][j] << " ";
					cout << endl;
				}

				break ;
			}
/*
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
*/

			case 5 :
			{
				int mat[10][10];
				fillWithNum((int*)mat, 100, 0);
				
				for(int i=0; i<10; i++)
					fillWithNum((int*)mat[i]+i, 10-i, i+1);

				for(int i=0; i<10; i++)
				{
					for(int j=0 ; j<10 ; j++ )
						cout<<mat[i][j]<< " ";
					cout << endl;
				}
			}
/*
1 1 1 1 1 1 1 1 1 1
0 2 2 2 2 2 2 2 2 2
0 0 3 3 3 3 3 3 3 3
0 0 0 4 4 4 4 4 4 4
0 0 0 0 5 5 5 5 5 5
0 0 0 0 0 6 6 6 6 6
0 0 0 0 0 0 7 7 7 7
0 0 0 0 0 0 0 8 8 8
0 0 0 0 0 0 0 0 9 9
0 0 0 0 0 0 0 0 0 10
*/

			case -1: break;

			default: cout << "Please enter the right program number!!\n"; system("pause"); break;
		}
	}while(choose != -1);

}