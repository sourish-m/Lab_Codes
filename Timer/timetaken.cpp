#include <iostream>
#include <fstream>
#include <time.h>
#include <unistd.h>
using namespace std;

int main()
{
	ifstream input;
	input.open("data.txt");
	clock_t begin = clock();

	
    clock_t end = clock();
    //-----------------------Write Code here----------------------
    












    //------------------------End Code----------------------------
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	cout << "The elapsed time is " << time_spent << " seconds" << endl;
	input.close();

	return 0;
}
