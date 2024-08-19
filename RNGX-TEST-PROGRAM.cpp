#include <iostream>
#include "RNGX7.h"

using namespace std;

int main()
{
	cout << "start load...\n";
	RNGX rngx;
	rngx.loading();
	cout << "start gennum\n";
	int num = rngx.Gen(0,88);
	cout << num << endl;
	system("pause");
	return 0;
}