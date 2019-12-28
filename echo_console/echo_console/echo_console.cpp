#include <cstdio>
#include <tchar.h>
#include <iostream>
#include <Windows.h>

using namespace std;

int _tmain(int args, TCHAR * argv[]) {
	cout << " echo_console.exe" << endl;
	int i = 1;

	for(int i = 2; i < args; i++)
		cout << argv[i] << " ";

	cout << endl;

	cin >> i;

	return 0;
}