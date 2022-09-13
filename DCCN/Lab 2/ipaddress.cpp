#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{
	cout << "\nEnter the ip address in decimal format." << endl;
	int ip[4], i = 0;
	char buffer[20];

	string binary_ip[4];
	for (i = 0; i < 4; i++)
	{
		cin >> ip[i];
		itoa(ip[i], buffer, 2);
		binary_ip[i] = buffer;
	}

	if (ip[0] >= 0 && ip[0] < 128)
	{
		cout << "\n class A" << endl;
		ip[1] = ip[2] = ip[3] = 0;
	}
	if (ip[0] >= 128 && ip[0] <= 191)
	{
		cout << "\n class B" << endl;
		ip[2] = ip[3] = 0;
	}

	if (ip[0] > 191 && ip[0] < 224)
	{
		cout << "\n Class C" << endl;
		ip[3] = 0;
	}

	if (ip[0] >= 224 && ip[0] < 240)
		cout << "\n Class D" << endl;
	if (ip[0] > 240 && ip[0] <= 254)
		cout << "\n Class E" << endl;

	cout << "\nNetwork Address of ip is: ";
	for (i = 0; i < 3; i++)
		cout << ip[i] << '.';
    cout<<ip[3];

	cout << "\nIP in binary is:";
	for (i = 0; i < 4; i++)
	{
		cout << setw(8) << setfill('0') << binary_ip[i] << '.';

	}

	return 0;
}
