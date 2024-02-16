/**
* PART 1 Project: ��� ������Ʈ �� EXIT ��ɾ� ����
*/

#include <Windows.h>
#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define STR_LEN			256
#define CMD_TOKEN_NUM	10

TCHAR ERROR_CMD[] = _T("'%s'��(��) ������ �� �ִ� ���α׷��� �ƴմϴ�. \n");

int CmdProcessing(void);
TCHAR* StrLower(TCHAR*);

int tmain(int argc, TCHAR* argv[])
{
	// �ѱ� �Է��� ������ �ϱ� ����
	_tsetlocale(LC_ALL, _T("Korean"));

	DWORD isExit;
	while (1)
	{
		isExit = CmdProcessing();
		if (isExit == TRUE)
		{
			_fputts(_T("��ɾ� ó���� �����մϴ�. \n"), stdout);
			break;
		}
	}
	return 0;
}

TCHAR cmdString[STR_LEN];
TCHAR cmdTokenList[CMD_TOKEN_NUM][STR_LEN];
TCHAR seps[] = _T(" ,\t\n");

/*******************************
* �Լ�: int CmdProcessing(void)
* ���: ��ɾ �Է� �޾Ƽ� �ش� ��ɾ �����Ǿ� �ִ� ����� �����Ѵ�.
*		exit �� �ԷµǸ� TRUE�� ��ȯ�ϰ� �̴� ���α׷��� ����� �̾�����.
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
	else if (!_tcscmp(cmdTokenList[0], _T("�߰� �Ǵ� ��ɾ� 1")))
	{
		// TODO
	}
	else if (!_tcscmp(cmdTokenList[0], _T("�߰� �Ǵ� ��ɾ� 2")))
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
* �Լ�: TCHAR* StrLower(TCHAR* pStr)
* ���: ���ڿ� ���� �����ϴ� ��� �빮�ڸ� �ҹ��ڷ� �����Ѵ�.
*		����� ���ڿ��� �����͸� ��ȯ�Ѵ�.
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
