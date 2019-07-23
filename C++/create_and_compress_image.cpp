#include <iostream>
using namespace std;

struct Picture
{
	int height;
	int width;
	char* data;
};

struct Sequence
{
	char c;
	int times;
};

struct CompressedPic
{
	int height;
	int width;
	Sequence* data;
};

Picture createPicture()
{
	Picture pic;
	int size;
	cout << "Please enter height and width\n";
	cin >> pic.height >> pic.width;
	size = pic.height*pic.width;
	pic.data = new char[size+1];

	cout << "Enter the picture (" << size << " chars):\n";
	for(int i=0; i<size; i++)
		cin >> pic.data[i];

	return pic;
}

CompressedPic compressThePicture(Picture p)
{
	int size = p.height*p.width, counter=0;
	Sequence* seq = new Sequence[size];
	CompressedPic cPic;
	
	cPic.height = p.height;
	cPic.width = p.width;

	for(int i=0; i<size-1; i+=seq[counter-1].times)
	{
		seq[counter].times = 1;
		seq[counter].c = p.data[i];
		bool isEqual = true;

		for(int j=i+1; j<size && isEqual; j++)
		{
			isEqual = false;
			if(p.data[i] == p.data[j])
			{
				seq[counter].times++;
				isEqual = true;
			}
		}
		counter++;
	}
	cPic.data = new Sequence[counter+1];
	for(int i=0; i<counter; i++)
	{
		cPic.data[i].c = seq[i].c;
		cPic.data[i].times = seq[i].times;
	}

	return cPic;
}

Picture unCompressThePicture(CompressedPic p)
{
	Picture pic;
	pic.height = p.height;
	pic.width = p.width;
	int size = p.height*p.width, index=0, counter=0;
	pic.data = new char[size+1];
	for(int i=0; p.data[i].times>0; i++)
	{
		counter=0;
		while(p.data[i].times > counter)
		{
			pic.data[index] = p.data[i].c;
			counter++;
			index++;
		}
	}
	return pic;
}

void main()
{
	int choose;
	do
	{
		cout << ("Please select your action (-1 to exit):\n1. Create Picture\n2. Compress Picture\n3. Uncompress Picture\n");
		cin >> choose;
		flushall();

		switch(choose)
		{
			case 1:
			{
				Picture pic;
				pic = createPicture();
				int size = pic.height*pic.width;
				cout << "The picture is:";
				for(int i=0; i<size; i++)
				{
					if(i%pic.width==0)
						cout << endl;
					cout << pic.data[i] << " ";
				}
				cout << endl;
			
				break;
			}
/*
Please select your action (-1 to exit):
1. Create Picture
2. Compress Picture
3. Uncompress Picture
1
Please enter height and width
4 5
Enter the picture (20 chars):
* * * * * * * ^ * * * ^ ^ ^ * ^ ^ ^ ^ ^
The picture is:
* * * * *
* * ^ * *
* ^ ^ ^ *
^ ^ ^ ^ ^
*/
			case 2:
			{
				Picture pic;
				pic = createPicture();
				CompressedPic cPic;
				cPic = compressThePicture(pic);
				cout << "\nCompressed picture:\n";
				for(int i=0; cPic.data[i].times >= 1; i++)
					cout << cPic.data[i].c << cPic.data[i].times << " ";
				cout << endl;
				break;
			}
/*
Please select your action (-1 to exit):
1. Create Picture
2. Compress Picture
3. Uncompress Picture
2
Compressed picture:
*7 ^1 *3 ^3 *1 ^5
*/

			case 3:
			{
				Picture pic;
				pic = createPicture();
				int size = pic.height*pic.width;
				CompressedPic cPic;
				cPic = compressThePicture(pic);
				Picture unCompPic;
				unCompPic = unCompressThePicture(cPic);

				cout << "Uncompressed picture:";
				for(int i=0; i<size; i++)
				{
					if(i%unCompPic.width==0)
						cout << endl;
					cout << unCompPic.data[i] << " ";
				}
				cout << endl;
				break;
			}
			
/*
Please select your action (-1 to exit):
1. Create Picture
2. Compress Picture
3. Uncompress Picture
3
Uncompressed picture:
* * * * *
* * ^ * *
* ^ ^ ^ *
^ ^ ^ ^ ^
*/
			case -1: break;

			default: cout << "Please enter the right program number!!\n"; system("pause"); break;
		}
	}while(choose != -1);
}