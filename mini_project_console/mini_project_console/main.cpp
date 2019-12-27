#include <iostream>
#include <tchar.h>
#include <winddi.h>
#include <string>
#include <boost/tokenizer.hpp>

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

	boost::tokenizer<boost::escaped_list_separator<char>> tok(cmdString);

}