#include <iostream>
#include <tchar.h>
#include <winddi.h>
#include <string>
#include <boost/tokenizer.hpp>
#include <algorithm>

using namespace std;
typedef basic_string<TCHAR> TSTRING;

#define CMD_TOKEN_NUM 10

TSTRING ERROR_CMD
= _T("'%s'�� ������ �� �ִ� ���α׷��� �ƴմϴ�. \n");

bool CmdProcessing (void);
TSTRING StrLower(TSTRING);

int tmain(int agrc, TCHAR * argv[]) {
	_tsetlocale(LC_ALL, _T("Korean"));

	bool isExit;
	while (1) {
		isExit = CmdProcessing();
		if (isExit == true) {
			_fputts(_T("��ɾ� ó���� �����մϴ�. \n"), stdout);
			break;
		}
	}
	return 0;
}

TSTRING cmdString;
TSTRING cmdTokenList[CMD_TOKEN_NUM];

bool CmdProcessing(void) {
	_fputts(_T("Best command prompt>> "), stdout);
	cin >> cmdString;
	int index = 0;
	boost::tokenizer<boost::escaped_list_separator<char>> tok(cmdString);
	for_each(tok.begin(), tok.end(), [&](TSTRING s) {
		cmdTokenList[index++] = s;
		});

	for (int i = 0; i < CMD_TOKEN_NUM; i++)
		cout << cmdTokenList[i] << endl;

	return true;
}