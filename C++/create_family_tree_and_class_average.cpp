#include <iostream>
using namespace std;

const int SIZE=15;
const int R = 10;
const int C = 20;
const int MAX_NAME = 20;
const int NOT_FOUND = -1;

struct Person
{
	char firstName[SIZE];
	long id;
};

struct Family
{
	char lastName[SIZE];
	Person father;
	Person mother;
	int childrenQuantity;
};

struct Student
{
	char name[MAX_NAME];
	int id;
	double averageGrade;
};

typedef struct{
char ch;
int n_appearances;
} APPEAR;

void printData(Person p, Family f);
int SearchRow(int M[][C],int x);
double average(Student students[], int size);
void printGoodStudents(Student students[ ] , int size);
void sortStudents(Student students[ ] , int size);
void swap(Student& a, Student& b);
int findStudent(Student students[], int size, int id, Student &s);
void appearances (char* str, APPEAR appear[], int &n);

void printData(Person p, Family f)
{
	cout << "Your name is: " << p.firstName << " " << f.lastName << ", ID: " << p.id << endl;
	cout << "Your father name is: " << f.father.firstName << ", ID: " << f.father.id << endl;
	cout << "Your mother name is: " << f.mother.firstName << ", ID: " << f.mother.id << endl;
	cout << "Your children quantity is: " << f.childrenQuantity << endl;
}

int SearchRow(int M[][C],int x)
{
	int min=0, max=R-1, mid;
    while ( min <= max )
	{
		mid = (min + max)/2;
		if(x >= M[mid][0] && x <= M[mid][C-1])
			return mid;

		if (x < M[mid][0])
			max = mid - 1;
		else
			min = mid + 1;
    }
    return -1;
}

double average(Student students[], int size)
{
	double average=0;
	for(int i=0; i<size; i++)
		average += students[i].averageGrade;
	return average/size;
}

void printGoodStudents(Student students[] , int size)
{
	for(int i=0; i<size; i++)
		if(students[i].averageGrade > 80)
			cout << students[i].name << endl;
}

void sortStudents(Student students[], int size)
{
	for (int i=size-1; i>0; i--)
		for (int j=0; j<i; j++)
			if (students[j].id > students[j+1].id)
				swap(students[j], students[j+1]);
}

void swap(Student& a, Student& b)
{
	Student temp = a;
	a = b;
	b = temp;
}

int findStudent(Student students[], int size, int id, Student &s)
{
	int low=0, high=size-1, middle;
	bool found=false;
	while (low <= high && !found)
	{
		middle = (low + high)/2;
		if (id == students[middle].id)
		     found = true;
		else if (id < students[middle].id)
		     high = middle -1;
		else
		     low = middle +1;
	}
	if(!found)
		return NOT_FOUND;
	strcpy(s.name,students[middle].name);
	s.id = students[middle].id;
	s.averageGrade = students[middle].averageGrade;
	return middle;
}

void appearances (char* str, APPEAR appear[], int &n)
{
	bool changed = false;
	for(int i=0; str[i]!='\0'; i++)
	{
		changed = false;
		for(int j=0; j<n && !changed; j++)
		{
			if(appear[j].ch == str[i])
			{
				appear[j].n_appearances++;
				changed = true;
			}
		}
		if(!changed)
		{
			appear[i].ch = str[i];
			appear[i].n_appearances++;
			changed = false;
		}
	}
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
				Person p;
				Family f;

				cout << "please enter your name and ID\n";
				cin >> p.firstName >> p.id;
				cout << "please enter your last name\n";
				cin >> f.lastName;
				cout << "please enter your father name and ID\n";
				cin >> f.father.firstName >> f.father.id;
				cout << "please enter your mother name and ID\n";
				cin >> f.mother.firstName >> f.mother.id;
				cout << "please enter your children quantity\n";
				cin >> f.childrenQuantity;

				printData(p,f);
			
				break;
			}
/*
please enter your name and ID
Erez 301583373
please enter your last name
Aminov
please enter your father name and ID
Father 123456789
please enter your mother name and ID
Mother 987654321
please enter your children quantity
10
Your name is: Erez Aminov, ID: 301583373
Your father name is: Father, ID: 123456789
Your mother name is: Mother, ID: 987654321
Your children quantity is: 10
*/
			case 2:
			{
				cout << "The function is written above\n";
				break;
			}

			case 3:
			{
/* The function defines a new array named Count which counts the number of appearances of a certain number
in the appropriate Count array index (for instance: if the number 5 appears 3 times in the array, then Count[5]=3).
Then the function prints the original array in an ascending order (it prints the a number according the number
of times it appears in the Count array [by it's index]).
*/
			}

			case 4:
			{
				Student stud[2], s = {};
				int id, studentIndex;

				for(int i=0; i<2; i++)
				{
					cout << "Please enter name, id and average\n";
					cin >> stud[i].name >> stud[i].id >> stud[i].averageGrade;
				}
				cout << "The class average is: " << average(stud, 2) << endl;
				cout << "The good students are: " << endl;
				printGoodStudents(stud, 2);
				sortStudents(stud, 2);
				cout << "Which ID are you looking for? ";
				cin >> id;
				studentIndex = findStudent(stud, 2, id, s);

				if(studentIndex == -1)
					cout << "Student not found\n";
				else
				{
					cout << "The student is in index #: " << studentIndex << endl;
					cout << "Student Name: " << s.name << endl;
					cout << "Student ID: " << s.id << endl;
					cout << "Student Average: " << s.averageGrade << endl;
				}
				break;
			}
/*
Please enter name, id and average
Erez 2 90
Please enter name, id and average
Avi 1 85
The class average is: 87.5
The good students are:
Erez
Avi
Which ID are you looking for? 1
The student is in index #: 0
Student Name: Avi
Student ID: 1
Student Average: 85
*/
			case 5:
			{
				char str[] = {"abrakadabra"};
				APPEAR appear[10] = {};
				int n=10;
				appearances (str, appear, n);
				cout << "The word '" << str << "' has:" << endl;
				for(int i=0; i<10; i++)
					if (appear[i].n_appearances!=0)
						cout << appear[i].n_appearances << " " << appear[i].ch << "'s" << endl;
				break;
			}
/*
The word 'abrakadabra' has:
5 a's
2 b's
2 r's
1 k's
1 d's
*/
			case -1: break;

			default: cout << "Please enter the right program number!!\n"; system("pause"); break;
		}
	}while(choose != -1);
}