#include<iostream>
#include<string>
#include<conio.h>
using namespace std;
int main()
{
	string inputstr;
	string outputstr;
	char lookuptbl[2][26];

	char var = 'A';
	for (int i = 0; i < 26; i++)
	{
		
		lookuptbl[0][i] = var + i;
		lookuptbl[1][i] = (var + i + 3)%26+65;
		cout << lookuptbl[0][i] << "\t" << lookuptbl[1][i] << endl;
	}

	//Part 3
	cout << "Please type your input string: ";
	cin >> inputstr;

	int length = inputstr.length();

	for (int i = 0; i < length; i++)
	{
		
		char mych = inputstr[i];
		
		int j = 0;
		for (; j < 26; j++)
		{
			if (mych == lookuptbl[0][j])
				break;
		}
		outputstr = outputstr + lookuptbl[1][j];
	}
	
	cout << "\nThe encoded string is: " << outputstr<<endl;

	//Part6
	string inputstr2;
	string outputstr2;
	cout << "Please type your input string: ";
	cin >> inputstr2;

	int length2 = inputstr2.length();

	for (int j = 0; j < length2; j++)
	{

		char mych2 = inputstr2[j];

		int i = 0;
		for (; i < 26; i++)
		{
			if (mych2 == lookuptbl[1][i])
				break;
		}
		outputstr2 = outputstr2 + lookuptbl[0][i];
	}

	cout << "\nThe decoded string is: " << outputstr2 << endl;
	
	_getch();
	return 0;
}