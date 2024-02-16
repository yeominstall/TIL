/**
* 예제 2-10
*/
#define UNICODE
#define _UNICODE

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

int _tmain(int argc, TCHAR* argv[])
{
	LPCTSTR str1 = _T("MBCS or WBCS 1");	// 최근 버전 VS는 const to non-const 로 대입 연산을 할 수 없다.
	TCHAR str2[] = _T("MBCS or WBCS 2");
	TCHAR str3[100];
	TCHAR str4[50];

	LPCTSTR pStr = str1;
	_tprintf(_T("string size: %lld \n"), sizeof(str2));
	_tprintf(_T("string length: %lld \n"), _tcsclen(pStr));

	_fputts(_T("Input String 1: "), stdout);
	_tscanf(_T("%s"), str3);
	_fputts(_T("Input String 2: "), stdout);
	_tscanf(_T("%s"), str4);

	_tcscat(str3, str4);
	_tprintf(_T("String1 + String2 : %s \n"), str3);

	return 0;
}