#include <iostream>
#include "RNGX.h"

using namespace std;

int main()
{
	cout << "start load\n";
	RNGX rngx;
	rngx.rngxl();
	cout << "start gennum\n";
	int num = rngx.rngxg(0,88);
	cout << num << endl;
	system("pause");
	return 0;
}