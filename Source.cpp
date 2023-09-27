#include <iostream>
#include <string.h>
#include <string>

using namespace std;

int cm1(int [], int [], int , int );
int cm2(int [], int [], int , int );

int main()
{
	int flag = 1;
	int i, m, c;
	
	int a1[10] = { 1,1,1,-1,-1,-1 };
	int b1[10], b2[10];
	
	string st;
	int sum = 0;

	cout << "**********************************************************************************" << endl;
	cout << "*                   Missionaries and cannibals problem                           *" << endl;
	cout << "*--------------------------------------------------------------------------------*" << endl;
	cout << "*                         Program description:                                   *" << endl;
	cout << "*                                                                                *" << endl;
	cout << "*   There are three missionaries and three cannibals on one side of the river,   *" << endl;
	cout << "*                                                                                *" << endl;
	cout << "*               as well as a boat that can carry 1 or 2 people.                  *" << endl;
	cout << "*                                                                                *" << endl;
	cout << "*   The rules of the game: The number of missionaries on one side of the river   *" << endl;
	cout << "*                                                                                *" << endl;
	cout << "*                     should not be less than cannibals!                         *" << endl;
	cout << "*                                                                                *" << endl;
	cout << "*                          $ Hope you enjoy :) $                                 *" << endl;
	cout << "*                                                                                *" << endl;
	cout << "**********************************************************************************" << endl;

	while (true)
	{
		cout << endl << "-> Start the game?" << "  ";
		cin >> st;
		cout << endl;
		cout << "***************************************************************" << endl;
		cout << endl;
		
		for (i = 0; i < 10; i++)
		{
			b1[i] = a1[i];
		}
		int a2[10] = { 0,0,0,0,0,0 };
		for (i = 0; i < 10; i++)
		{
			b2[i] = a2[i];
		}
		if (st == "Yes" || st == "yes" || st == "Y" || st == "y" || st == "Start" || st == "start" || st == "S" || st == "s")
		{
			cout << "In this program, missionaries are shown with the number 1 and cannibals with the number -1!" << endl << endl;
			cout << "On the first side of the river:";
			for (i = 0; i < 6; i++)
			{
				cout << " [ " << a1[i] << " ] ";
			}
			cout << endl;
			cout << "On the second side of the river:";
			for (i = 0; i < 6; i++)
			{
				cout << " [ " << a2[i] << " ] ";
			}
			cout << endl;
			cout << "Choose two or one person to transfer to the other side of the river:" << endl;

			do
			{
				cout << endl;
				cout << "***  Moving to the second side of the river  ***" << endl;
				cout << endl;
				do
				{
					cout << "first one:";
					cin >> m;
					if (m == 1 || m == -1 || m == 0)
					{
						break;
					}
					else
					{
						cout << endl;
						cout << "Incorrect number! Please use 1 for missionaries and -1 for cannibal :)" << endl;
						cout << endl;
					}

				} while (true);
				cout << endl;
				do
				{
					cout << "second one:";
					cin >> c;
					if (c == 1 || c == -1 || c == 0)
					{
						break;
					}
					else
					{
						cout << endl;
						cout << "Incorrect number! Please use 1 for missionaries and -1 for cannibal :)" << endl;
						cout << endl;
					}
				} while (true);

				cout << endl;
				flag = cm1(b1, b2, m, c);
				if (flag != 1)
				{
					break;
				}
				cout << endl;
				cout << "***  Move to the first side of the river  ***" << endl;
				cout << endl;
				do
				{
					cout << "first one:";
					cin >> m;
					if (m == 1 || m == -1 || m == 0)
					{
						break;
					}
					else
					{
						cout << endl;
						cout << "Incorrect number! Please use 1 for missionaries and -1 for cannibal :)" << endl;
						cout << endl;
					}

				} while (true);
				cout << endl;
				do
				{
					cout << "second one:";
					cin >> c;
					if (c == 1 || c == -1 || c == 0)
					{
						break;
					}
					else
					{
						cout << endl;
						cout << "Incorrect number! Please use 1 for missionaries and -1 for cannibal :)" << endl;
						cout << endl;
					}
				} while (true);
				cout << endl;
				flag = cm2(b1, b2, m, c);
			} while (flag == 1);


			cout << endl;
			cout << endl;

		}
		else
		{
			cout << endl;
			cout << "I hope you enjoyed the game :)" << endl;

			break;

		}
	}
	
	cin.get();
	cin.get();
	
	return 0;
}

int cm1(int b1[10], int b2[10], int m, int c) 
{
	int i;
	int cnt1 = 0;
	int cnt2 = 0;
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < 6; i++) {
		if (b1[i] == m)
		{
			b1[i] = 0;
			if (m != 0)
			{
				b2[i] = m;
			}
			break;
		}

	}
	for (int i = 0; i < 6; i++) {
		if (b1[i] == c)
		{
			b1[i] = 0;
			if (c != 0)
			{
				b2[i] = c;
			}

			break;
		}

	}
	
	for (i = 0; i < 10; i++)
	{
		sum1 += b1[i];
		sum2 += b2[i];
	}
	
	for (i = 0; i < 10; i++)
	{
		if (b1[i] != 0)
		{
			cnt1++;
		}
	}
	for (i = 0; i < 10; i++)
	{
		if (b2[i] != 0)
		{
			cnt2++;
		}
	}
	
	if ((sum1 < 0 && cnt1 > 3) || (sum2 < 0 && cnt2 > 3))
	{
		cout << "On the first side of the river:";
		for (i = 0; i < 6; i++)
		{
			cout << " [ " << b1[i] << " ] ";
		}
		cout << endl;
		cout << "On the second side of the river:";
		for (i = 0; i < 6; i++)
		{
			cout << " [ " << b2[i] << " ] ";
		}
		cout << endl;
		cout << "You lost the game ! ;)" << endl;
		return -1;

	}
	
	else if (cnt1 == 0 && cnt2 == 6)
	{
		cout << "On the first side of the river:";
		for (i = 0; i < 6; i++)
		{
			cout << " [ " << b1[i] << " ] ";
		}
		cout << endl;
		cout << "On the second side of the river:";
		for (i = 0; i < 6; i++)
		{
			cout << " [ " << b2[i] << " ] ";
		}
		cout << endl;
		cout << "You won ! ;)" << endl;
		return -1;
	}
	else
	{
		cout << "On the first side of the river:";
		for (i = 0; i < 6; i++)
		{
			cout << " [ " << b1[i] << " ] ";
		}
		cout << endl;
		cout << "On the second side of the river:";
		for (i = 0; i < 6; i++)
		{
			cout << " [ " << b2[i] << " ] ";
		}
		cout << endl;
		return 1;
	}

}

int cm2(int b1[10], int b2[10], int m, int c) 
{
	int i;
	int cnt1 = 0;
	int cnt2 = 0;
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < 6; i++) {
		if (b2[i] == m)
		{
			b2[i] = 0;
			if (m != 0)
			{
				b1[i] = m;
			}

			break;
		}

	}
	for (int i = 0; i < 6; i++) {
		if (b2[i] == c)
		{
			b2[i] = 0;
			if (c != 0)
			{
				b1[i] = c;
			}

			break;
		}

	}

	for (i = 0; i < 10; i++)
	{
		sum1 += b1[i];
		sum2 += b2[i];
	}
	for (i = 0; i < 10; i++)
	{
		if (b1[i] != 0)
		{
			cnt1++;
		}
	}
	for (i = 0; i < 10; i++)
	{
		if (b2[i] != 0)
		{
			cnt2++;
		}
	}

	if ((sum1 < 0 && cnt1 > 3) || (sum2 < 0 && cnt2 > 3))
	{
		cout << "On the first side of the river:";
		for (i = 0; i < 6; i++)
		{
			cout << " [ " << b1[i] << " ] ";
		}
		cout << endl;
		cout << "On the second side of the river:";
		for (i = 0; i < 6; i++)
		{
			cout << " [ " << b2[i] << " ] ";
		}
		cout << endl;
		cout << "You lost the game ! ;)" << endl;
		return -1;

	}

	else if (cnt1 == 0 && cnt2 == 6)
	{
		cout << "On the first side of the river:";
		for (i = 0; i < 6; i++)
		{
			cout << " [ " << b1[i] << " ] ";
		}
		cout << endl;
		cout << "On the second side of the river:";
		for (i = 0; i < 6; i++)
		{
			cout << " [ " << b2[i] << " ] ";
		}
		cout << endl;
		cout << "You won ! ;)" << endl;
		return -1;
	}
	else
	{
		cout << "On the first side of the river:";
		for (i = 0; i < 6; i++)
		{
			cout << " [ " << b1[i] << " ] ";
		}
		cout << endl;
		cout << "On the second side of the river:";
		for (i = 0; i < 6; i++)
		{
			cout << " [ " << b2[i] << " ] ";
		}
		cout << endl;
		return 1;
	}

}

