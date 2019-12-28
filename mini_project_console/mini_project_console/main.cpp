#include <iostream>
#include <tchar.h>
#include <Windows.h>
#include <string>
#include <boost/tokenizer.hpp>
#include <algorithm>
#include <cstdio>

using namespace std;
typedef basic_string<TCHAR> TSTRING;

#define CMD_TOKEN_NUM 10
#define BUFFER 1000

TSTRING ERROR_CMD
= _T("is not execution code. \n");

bool CmdProcessing (void);
TSTRING StrLower(TSTRING);
void Make_Process(TSTRING& , TSTRING);

int _tmain(int agrc, TCHAR * argv[]) {
	_tsetlocale(LC_ALL, _T("Korean"));

	bool isExit = true;
	while (1) {
		isExit = CmdProcessing();
		if (isExit == true) {
			_fputts(_T("command end..... \n"), stdout);
			break;
		}
	}
	return 0;
}

bool CmdProcessing(void) {
	TSTRING cmdString;
	TSTRING cmdTokenList[CMD_TOKEN_NUM];
	_fputts(_T("Best command prompt>> "), stdout);
	getline(cin, cmdString);
	int index = 0;
	//boost::escaped_list_separator<char>
	boost::tokenizer<> tok(cmdString);

	for_each(tok.begin(), tok.end(), [&](auto& s) {
		cmdTokenList[index++] = [&](TSTRING s) -> TSTRING{	//대문자를 소문자로.
			for (int i = 0; i < s.size(); i++)
				s[i] = tolower(s[i]);
			return s;
		}(s);
	});
	
	if (cmdTokenList[0] == _T("exit"))
		return true;
	else if (cmdTokenList[0] == _T("start")) {
		Make_Process(cmdTokenList[1], cmdString);
		return false;
	}
	else {
		cout << cmdTokenList[0] << ERROR_CMD << endl;
		return false;
	}
	return -1;
}

void Make_Process(TSTRING& cmd, TSTRING echo) {
	TCHAR command[] = _T("..\\..\\echo_console\\Debug\\echo_console.exe");
	STARTUPINFO si = { 0, };
	PROCESS_INFORMATION pi;
	si.cb = sizeof(si);
	TCHAR title[] = "echo_console.exe";
	si.lpTitle = title;

	TCHAR c_echo[BUFFER];
	TCHAR sum_echo[BUFFER];
	int len;

	if (cmd == _T("echo")) {
		echo.erase(0, 6);
		len = echo.size();
		echo.copy(c_echo, len);
		c_echo[len] = '\0';
		_stprintf_s(sum_echo, _T("%s %s"), command, c_echo);
	}
	else if (cmd == _T("")) {
		_stprintf_s(sum_echo, _T("%s"), command);
	}

	int ischeck = CreateProcess(NULL, sum_echo, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
	if (!ischeck)
		cout << "ProcessCreate Error!!" << endl;
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}