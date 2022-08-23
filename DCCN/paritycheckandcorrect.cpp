# include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
int main(int argc, char *argv[])
{
	srand(time(0));
	int i, j;
	cout << "Enter the number of frames: ";
	int row;
	cin >> row;
	cout << "\nEnter the size of each frame: ";
	int column;
	cin >> column;

	int m[row + 1][column + 1];

	cout << "\nEnter the frame matrix\n";

	for (i = 0; i < row; i++)
		for (j = 0; j < column; j++)
			cin >> m[i][j];


	//actual logic
	int count_one = 0;
	for ( i = 0; i < row; i++)
	{
		count_one = 0;

		for ( j = 0; j < column; j++)
		{
			if (m[i][j] == 1)
				count_one++;
		}

		if (count_one % 2 == 0)
			m[i][column] = 1;
		else
			m[i][column] = 0;
	}

	for ( j = 0; j < column + 1; j++)
	{
		count_one = 0;

		for ( i = 0; i < row; i++)
		{
			if (m[i][j] == 1)
				count_one++;
		}

		if (count_one % 2 == 0)
			m[row][j] = 1;
		else
			m[row][j] = 0;

	}

	cout << "\n-------Sender---------" << endl;
	cout << "\nThe parity matrix is:" << endl;
	for (i = 0; i < row + 1; i++)
	{
		for (j = 0; j < column + 1; j++)
		{
			cout << m[i][j] << " ";
		}
		cout << endl;
	}

    cout << "\n(Simulating network error through randomization)" << endl;
	cout << "\n---------Receiver------" << endl;
	int r = rand() % row;
	int c = rand() % column;
	int temp = m[r][c];
	m[r][c] = rand() % 2;

	cout << "\n The Received matrix is:" << endl;

	for (i = 0; i < row + 1; i++)
	{
		for (j = 0; j < column + 1; j++)
		{
			cout << m[i][j] << " ";
		}
		cout << endl;
	}

	if (temp == m[r][c])
		cout << "No Error detected" << endl;
	else
		cout << "Error detected in row " << r << " and column " << c << endl;


	return 0;
}
