/**
* 예제 3-2
*/
#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

//#ifdef _WIN64		#if defined(_WIN64)
//typedef __int64			LONG_PTR;
//typedef unsigned __int64	ULONG_PTR;
//
//typedef __int64			INT_PTR;
//typedef unsigned __int64	UINT_PTR;
//#else	// _WIN32
//typedef long			LONG_PTR;
//typedef unsigned long	ULONG_PTR;
//
//typedef int			INT_PTR;
//typedef unsigned int	UINT_PTR;
//#endif
// *_PTR : 포인터값 기반의 산술 연산을 위해 정의된 자료형
// 64비트 환경에서는 64비트 자료형으로, 32비트 환경에서는 32비트 자료형으로

UINT_PTR CalDistance(UINT_PTR a, UINT_PTR b)
{
	return a - b;
}

int _tmain(void)
{
	INT val1 = 10;
	INT val2 = 20;

	_tprintf(_T("Position %u, %u \n"), (UINT)&val1, (UINT)&val2);
	_tprintf(_T("distance: %u \n"), CalDistance((UINT)&val1, (UINT)&val2));
	printf("%d\n", sizeof(INT));

	return 0;
}
