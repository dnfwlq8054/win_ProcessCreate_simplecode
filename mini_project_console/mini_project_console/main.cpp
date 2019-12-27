#include <iostream>
#include <tchar.h>
#include <winddi.h>
#include <string>

using namespace std;

#define STR_LEN 256
#define CMD_TOKEN_NUM 10

TCHAR ERROR_CMD[]
= _T("'%s'는 실행할 수 있는 프로그램이 아닙니다. \n");

bool CmdProcessing (void);
TCHAR * StrLower(TCHAR *);

int tmain(int agrc, TCHAR * argv[]) {
	_tsetlocale(LC_ALL, _T("Korean"));

	bool isExit;
	while (1) {
		isExit = CmdProcessing();
		if (isExit == true) {
			_fputts(_T("명령어 처리를 종료합니다. \n"));
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