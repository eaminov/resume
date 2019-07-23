#include <iostream>
using namespace std;

const int SIZE=3, ROWS=3, COLS=6; 

bool equal (int matrix[SIZE][SIZE]);
bool mirror (int mat[ROWS][COLS]);

bool equal (int matrix[SIZE][SIZE])
{
	int i, j, sumRow=0, sumCol=0;
	for(i=0; i<SIZE; i++)
	{
		for(j=0; j<SIZE; j++)
		{
			sumRow = matrix[i][j] + sumRow;
			sumCol = matrix[j][i] + sumCol;
		}
		if(sumRow!=sumCol)
			return false;
	}
	return true;
}

bool mirror (int mat[ROWS][COLS])
{
	int i,j;
	for(i=0; i<ROWS; i++)
		for(j=0; j<COLS/2; j++)
			if(mat[i][j] != mat[i][COLS-1-j])
				return false;
	return true;
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
		case 5:
			int mat[SIZE][SIZE], i, j;
			bool isEqual;
			cout << "please enter " << SIZE*SIZE << " numbers\n";
			for ( i=0 ; i<SIZE ; i++ ) 
				for(j=0; j<SIZE; j++)
					cin >> mat[i][j];
			isEqual = equal(mat);
			switch(isEqual)
			{
			case 1: cout << "TRUE\n"; break;
			case 0:	cout << "FALSE\n"; break;
			}
			break;
/*
please enter 9 numbers
1 2 3
4 5 6
7 8 9
FALSE
*/
		case 6:
			int matrix[ROWS][COLS];
			bool isMirror;
			cout << "please enter " << ROWS*COLS << " numbers\n";
			for (i=0; i<ROWS; i++)
				for(j=0; j<COLS; j++)
					cin >> matrix[i][j];
			isMirror = mirror(matrix);
			switch(isMirror)
			{
			case 1: cout << "TRUE\n"; break;
			case 0:	cout << "FALSE\n"; break;
			}
			break;
/*
please enter 18 numbers
3 1 4 5 1 2
6 7 3 3 7 6
0 8 0 0 8 0
FALSE
*/	
		case -1: break;

		default: cout << "Please enter the right program number!!\n"; system("pause"); break;
		}
	}while(choose != -1);

}