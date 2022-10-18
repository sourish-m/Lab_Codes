/* Program to generate subkeys used in DES cipher */
#include <iostream>
#include <sstream>
using namespace std;
string hex2bin(string s)
{
	unsigned long long value;
	istringstream ost(s);
	ost >> hex >> value;
	bitset<64> bits(value);
	return bits.to_string();
}
string bin2hex(string s)
{
	bitset<48> set(s);
	stringstream res;
	res << hex << uppercase << set.to_ullong();
	return res.str();
}

string permute(string k, int* arr, int n)
{
	string per = "";
	for (int i = 0; i < n; i++)
	{
		per += k[arr[i] - 1];
	}
	return per;
}

string shift_left(string k, int shifts)
{
	string s = "";
	for (int i = 0; i < shifts; i++)
	{
		s = k.substr(1, 27);
		s += k[0];
		k = s; s = "";
	}
	return k;
}

int main()
{

	string key;
	/* cout<<"Enter key in hexadecimal:"<<endl; */
	/* cin>>key; */
	key = "AABB09182736CCDD";

	key = hex2bin(key);

	// PC1 table
	int keyp[56]
	    = { 57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34,
	        26, 18, 10, 2, 59, 51, 43, 35, 27, 19, 11, 3,
	        60, 52, 44, 36, 63, 55, 47, 39, 31, 23, 15, 7,
	        62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37,
	        29, 21, 13, 5, 28, 20, 12, 4
	      };

	// getting 56 bit key from 64 bit using the parity bits
	key = permute(key, keyp, 56); // key without parity
	// Number of bit shifts
	int shift_table[16] = { 1, 1, 2, 2, 2, 2, 2, 2,
	                        1, 2, 2, 2, 2, 2, 2, 1
	                      };
	//PC2 Table
	int key_comp[48] = { 14, 17, 11, 24, 1, 5, 3, 28,
	                     15, 6, 21, 10, 23, 19, 12, 4,
	                     26, 8, 16, 7, 27, 20, 13, 2,
	                     41, 52, 31, 37, 47, 55, 30, 40,
	                     51, 45, 33, 48, 44, 49, 39, 56,
	                     34, 53, 46, 42, 50, 36, 29, 32
	                   };

	// Splitting
	string left = key.substr(0, 28);
	string right = key.substr(28, 56);

	string k1, k2, combine;
	for (int i = 0; i < 16; i++)
	{
		// Shifting
		left = shift_left(left, shift_table[i]);
		right = shift_left(right, shift_table[i]);

		// Combining
		combine = left + right;

		k1 = permute(combine, key_comp, 48);
		cout << "\nKey " << i + 1 << " in binary is " << k1 << endl;

		k2 = bin2hex(k1);
		cout << "Key " << i + 1 << " in hex is " << k2 << endl;
	}
}
