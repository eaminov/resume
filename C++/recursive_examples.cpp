#include <iostream>
using namespace std;

const int SIZE=3;

int recNumEvenCount(int num);
bool recNumAllEven(int num);
int recArrEvenCount(int arr[], int size);
bool recArrAllEven(int arr[], int size);
bool recStringAllCapital(char str[]);
bool recStringCaseSensative(char str[]);
void printOpositeTriangles(int n);
void switch_letters(char *beg, char *end);
void minMax(int A[], int left, int right, int &min, int &max);
void drawRuler(int k);
void printInBinary(int num);

int recNumEvenCount(int num)
{
	if(num==0)
		return 0;
	if(num%2==0)
		return recNumEvenCount(num/10)+1;
	return recNumEvenCount(num/10);
}

bool recNumAllEven(int num)
{
	if(num==0)
		return true;
	if(num%2!=0)
		return false;
	return recNumAllEven(num/10);
}

int recArrEvenCount(int arr[], int size)
{
	if(size==0)
		return 0;
	if(arr[0]%2==0)
		return recArrEvenCount(arr+1,size-1)+1;
	return recArrEvenCount(arr+1,size-1);
}

bool recArrAllEven(int arr[], int size)
{
	if(size==0)
		return true;
	if(arr[0]%2!=0)
		return false;
	return recArrAllEven(arr+1,size-1);
}

bool recStringAllCapital(char str[])
{
	if(str[0]=='\0')
		return true;
	if(str[0]>'Z')
		return false;
	return recStringAllCapital(str+1);
}

bool recStringCaseSensative(char str[])
{
	if(str[1]=='\0')
		return true;
	if(str[0]>='A' && str[0]<='Z')
		if(str[1]>='a' && str[1]<='z')
			return false;
	if(str[0]>='a' && str[0]<='z')
		if(str[1]>='A' && str[1]<='Z')
			return false;

	return recStringCaseSensative(str+1);
}

void printOpositeTriangles(int n)
{
	if(n==0)
		return;

	for(int i=0; i<n; i++)
		cout << "*";
	cout << endl;

	printOpositeTriangles(n-1);

	for(int i=0; i<n; i++)
		cout << "*";
	cout << endl;
}

void switch_letters(char *beg, char *end)
{
	char temp;
	if(beg>=end)
		return;
	temp = *beg;
	*beg = *end;
	*end = temp;
	return switch_letters(beg+1, end-1);
}

void minMax(int A[], int left, int right, int &min, int &max)
{
	if(left > right)
		return;
	if(A[left] > max)
		max = A[left];
	if(A[left] < min)
		min = A[left];
	return minMax(A, left+1, right, min, max);
}


void drawRuler (int k)
{
	if (k==0) 
		return;

	drawRuler (k-1);

	for (int i=0 ; i<k ; i++)
		cout << "-";
	cout << endl;
 
	drawRuler (k-1);

}

void printInBinary(int num)
{
	if(num==0)
		return;
	cout << num%2;
	return printInBinary(num/2);
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
				int evenCount, num;
				cout << "please enter a number\n";
				cin >> num;
				evenCount = recNumEvenCount(num);
				cout << evenCount << endl;
			
				break ;
			}
/*
please enter a number
234
2
*/

			case 2:
			{
				int num;
				bool isAllEven;
				cout << "please enter a number\n";
				cin >> num;
				isAllEven = recNumAllEven(num);
				cout << isAllEven << endl;

				break ;
			}
/*
please enter a number
24642
1
*/

			case 3:
			{
				int evenCount, arr[SIZE];

				cout << "please enter " << SIZE << " numbers\n";
				for(int i=0; i<SIZE; i++)
					cin >>arr[i];

				evenCount = recArrEvenCount(arr,SIZE);
				cout << evenCount << endl;

				break ;
			}
/*
please enter 3 numbers
234 122 565
2
*/

			case 4:
			{
				int arr[SIZE];
				bool isAllEven;

				cout << "please enter " << SIZE << " numbers\n";
				for(int i=0; i<SIZE; i++)
					cin >>arr[i];

				isAllEven = recArrAllEven(arr,SIZE);
				cout << isAllEven << endl;

				break ;
			}
/*
please enter 3 numbers
22 44 65
0
*/

			case 5:
			{
				char str[10];
				bool isAllCapital;

				cout << "please enter a string\n";
				cin >> str;

				isAllCapital = recStringAllCapital(str);
				cout << isAllCapital << endl;

				break;
			}

/*
please enter a string
ASDfDS
0
*/
			case 6:
			{
				char str[10];
				bool isCaseSensative;

				cout << "please enter a string\n";
				cin >> str;

				isCaseSensative = recStringCaseSensative(str);
				cout << isCaseSensative << endl;

				break;
			}
/*
please enter a string
AkJL
0
*/
			case 7:
			{
				int base;
				cout << "Please type a base\n";
				cin >> base;
				printOpositeTriangles(base);

				break;
			}
/*
Please type a base
5
*****
****
***
**
*
*
**
***
****
*****
*/
			case 8:
			{
				char str[10];
				cout << "please enter a string\n";
				cin >> str;
				switch_letters(str, str+strlen(str)-1);
				cout << str << endl;

				break;
			}
/*
please enter a string
abcdef
fedcba
*/
			case 9:
			{
				int arr[] = {5,7,2,6,3}, left, right;
				cout << "Choose the left index: ";
				cin >> left;
				cout << "Choose the right index: ";
				cin >> right;

				int size = sizeof(arr)/sizeof(arr[0]);
				int min = arr[left], max = arr[left];

				minMax(arr, left, right, min, max);
				cout << "The minimum is: " << min << ", The maximum is: " << max << endl;

				break;
			}
/*
Choose the left index: 2
Choose the right index: 4
The minimum is: 2, The maximum is: 6
*/
			case 10:
			{
				int num;
				cout << "Please enter a number\n";
				cin >> num;
				drawRuler(num);
				break;
			}
/*
Please enter a number
3
-
--
-
---
-
--
-
*/
			case 11:
			{
				int num;
				cout << "Choose a number\n";
				cin >> num;
				cout << "The Binary value is: ";
				printInBinary(num);
				cout << endl;
				break;
			}
/*
Choose a number
73
The Binary value is: 1001001
*/
			case -1: break;

			default: cout << "Please enter the right program number!!\n"; system("pause"); break;
		}
	}while(choose != -1);
}