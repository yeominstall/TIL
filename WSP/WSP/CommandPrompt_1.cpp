/**
* PART 1 Project: 명령 프롬프트 및 EXIT 명령어 구현
*/

#include <Windows.h>
#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define STR_LEN			256
#define CMD_TOKEN_NUM	10

TCHAR ERROR_CMD[] = _T("'%s'은(는) 실행할 수 있는 프로그램이 아닙니다. \n");

int CmdProcessing(void);
TCHAR* StrLower(TCHAR*);

int tmain(int argc, TCHAR* argv[])
{
	// 한글 입력을 가능케 하기 위해
	_tsetlocale(LC_ALL, _T("Korean"));

	DWORD isExit;
	while (1)
	{
		isExit = CmdProcessing();
		if (isExit == TRUE)
		{
			_fputts(_T("명령어 처리를 종료합니다. \n"), stdout);
			break;
		}
	}
	return 0;
}

TCHAR cmdString[STR_LEN];
TCHAR cmdTokenList[CMD_TOKEN_NUM][STR_LEN];
TCHAR seps[] = _T(" ,\t\n");

/*******************************
* 함수: int CmdProcessing(void)
* 기능: 명령어를 입력 받아서 해당 명령어에 지정되어 있는 기능을 수행한다.
*		exit 가 입력되면 TRUE를 반환하고 이는 프로그램의 종료로 이어진다.
*/

int CmdProcessing(void)
{
	_fputts(_T("Best command prompt >> "), stdout);
	_getts_s(cmdString, STR_LEN);

	TCHAR* token = _tcstok(cmdString, seps);
	int tokenNum = 0;
	while (token != NULL)
	{
		_tcscpy(cmdTokenList[tokenNum++], StrLower(token));
		token = _tcstok(NULL, seps);
	}

	if (!_tcscmp(cmdTokenList[0], _T("exit")))
		return TRUE;
	else if (!_tcscmp(cmdTokenList[0], _T("추가 되는 명령어 1")))
	{
		// TODO
	}
	else if (!_tcscmp(cmdTokenList[0], _T("추가 되는 명령어 2")))
	{
		// TODO
	}
	else
	{
		_tprintf(ERROR_CMD, cmdTokenList[0]);
	}
	return 0;
}

/*******************************
* 함수: TCHAR* StrLower(TCHAR* pStr)
* 기능: 문자열 내에 존재하는 모든 대문자를 소문자로 변경한다.
*		변경된 문자열의 포인터를 반환한다.
*/
TCHAR* StrLower(TCHAR* pStr)
{
	TCHAR* ret = pStr;

	while (*pStr)
	{
		if (_istupper(*pStr))
			*pStr = _totlower(*pStr);
		pStr++;
	}
	return ret;
}
