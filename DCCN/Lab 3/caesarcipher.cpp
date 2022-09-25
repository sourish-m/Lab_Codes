#include <iostream>
using namespace std;

int main()
{
	cout<<"1. Encrypt 2. Decrypt"<<endl;
	int choice;
	cin>>choice;
	
	cout<<"\nEnter String:"<<endl;
	string text;
	int key; char i;
	cin.ignore();
	getline(cin, text);

	cout<<"\nEnter the value of key: ";
	cin>>key;

	if (choice==1)
	{
		for(char &c : text)
			if (c!=' ')
			{
				c<='Z'?i='A':i='a';
				c = (c - i + key ) % 26 + i; // shift by key
			}
	}

	if (choice==2)
	{
		for(char &c : text)
			if (c!=' ')
			{
				c<='Z'?i='Z':i='z';
				c = i + (c - i - key) % 26;
			}
	}
	cout<<"\nThe Output is:\n"<<text<<endl;
}
