#include <iostream>
using namespace std;
int main()
{
	cout <<"Enter Plaintext"<<endl;
	string text, key;
	getline(cin,text);
	cout<<"Enter keyword"<<endl;
	getline(cin,key);
	key.erase( unique(key.begin(), key.end()), key.end());
	
	char matrix[5][5];
	
	
	
}
