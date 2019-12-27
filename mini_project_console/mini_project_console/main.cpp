#include <iostream>
#include <tchar.h>
#include <Windows.h>
#include <string>
#include <boost/tokenizer.hpp>
#include <algorithm>


using namespace std;
typedef basic_string<TCHAR> TSTRING;

#define CMD_TOKEN_NUM 10

TSTRING ERROR_CMD
= _T("'%s'는 실행할 수 있는 프로그램이 아닙니다. \n");

bool CmdProcessing (void);
TSTRING StrLower(TSTRING);

int _tmain(int agrc, TCHAR * argv[]) {
	_tsetlocale(LC_ALL, _T("Korean"));

	bool isExit = true;
	while (1) {
		isExit = CmdProcessing();
		if (isExit == true) {
			_fputts(_T("명령어 처리를 종료합니다. \n"), stdout);
			break;
		}
	}
	return 0;
}

TSTRING cmdString;
TSTRING cmdTokenList[CMD_TOKEN_NUM];

bool CmdProcessing(void) {
	_fputts(_T("Best command prompt>> "), stdout);
	getline(cin, cmdString);
	int index = 0;
	//boost::escaped_list_separator<char>
	boost::tokenizer<> tok(cmdString);

	for_each(tok.begin(), tok.end(), [&](auto& s) {
		cmdTokenList[index++] = [&](TSTRING s) -> TSTRING{
			for (int i = 0; i < s.size(); i++)
				s[i] = tolower(s[i]);
			return s;
		}(s);
		});

	for (int i = 0; i < CMD_TOKEN_NUM; i++)
		cout << cmdTokenList[i] << endl;

	return true;
}