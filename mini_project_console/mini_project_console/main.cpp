#include <iostream>
#include <tchar.h>
#include <winddi.h>
#include <string>

using namespace std;

#define STR_LEN 256
#define CMD_TOKEN_NUM 10

TCHAR ERROR_CMD[]
= _T("'%s'�� ������ �� �ִ� ���α׷��� �ƴմϴ�. \n");

bool CmdProcessing (void);
TCHAR * StrLower(TCHAR *);

int tmain(int agrc, TCHAR * argv[]) {
	_tsetlocale(LC_ALL, _T("Korean"));

	bool isExit;
	while (1) {
		isExit = CmdProcessing();
		if (isExit == true) {
			_fputts(_T("��ɾ� ó���� �����մϴ�. \n"));
			break;
		}
	}
	return 0;
}

string cmdString;
TCHAR cmdTokenList[CMD_TOKEN_NUM][STR_LEN];

bool CmdProcessing(void) {
	_fputts(_T("Best command prompt>> "), stdout);
	cin >> cmdString;

}