## Section 5. 문자열(string)

### std::string 클래스
문자열을 읽어들일 때, 아래의 경우
```cpp
char s[256];
cin.getline(s, 256);
```
- 아무것도 읽지 못하거나
- 버퍼 이상을 받아올 때(한 줄에 문자가 256자 이상일 때) 문제가 생길 수 있다.

`std::string`은 길이가 증가할 수 있다.

#### 대입과 덧붙이기(Assignment & Appending)
C의 경우
- strcpy (대입), strcat (appending)
- 안전하지 않음(destination의 길이를 초과할 가능성이 있다)

이에 비해 `std::string`은 직관적이고 안전하다.
```cpp
std::string name = "POPE";
name += " KIM";
```

#### 문자열 합치기(Concatenation)
C의 경우
- snprintf
```c
snprintf(fullName, 40, "%s %s", firstName, lastName);
```
C++의 경우
- \+ 연산자 사용
```cpp
fullName = firstName + " " + lastName;
```

#### 비교(Relational) 연산자
C의 경우
- strcmp 사용  
: 두 arg가 같을 때 0을 반환. ASCII 값을 기준으로 비교가 수행된다.(사전 순)

C++의 경우
- 비교연산자를 사용할 수 있다. 부등호를 사용하면 사전 순서로 비교할 수 있다.

#### size(), length(), c_str()
- size()와 length()는 문자열의 길이를 반환한다.

c_str()
- `const char *` 반환(고전 string)
```cpp
string line;
cin >> line;
const char *cLine = line.c_str();
```
C와의 호환성을 위해 많이 사용된다. **메모리 문제가 없다.**  
: ~~const 타입이기 때문?~~

#### strong 속의 한 문자에 접근하기
C에서 하는 것처럼 `firstName[1]`과 같이 접근할 수 있다.  
사실 이 형태는 **함수**이고, **참조형을 반환**하므로 값을 수정할 수 있다.
`line.at(1)`과 같은 방법으로 접근할 수도 있지만 잘 사용하지 않는다.

#### 한 줄 읽기
```cpp
string mailHeader;
getline(cin, mailHeader);
// getline(cin, mailHeader, '@');
```
`getline()`은 세 번째 인자로 구분자(delimiter)를 받을 수 있다.
cin으로부터 `delimiter`전까지의 문자들을 입력받아 저장한다. `delimiter`가 주어지지 않을 경우, `\n`이 들어올 때까지 입력받는다. `delimiter`는 버려진다.  
*->EOF가 들어온다면?*


### std::string이 좋은가요? 
#### \<sstream\>
stringstream - 유용하지만 잘 쓰이지 않는다. `cin`과 비슷, 스트림. string에서 들어오고 string으로 나간다.

* `std::istringstream`  
: 키보드 대신 string으로부터 읽어온다. `sscanf()`와 비슷.
* `std::ostringstream`  
: 콘솔 대신 string으로 출력한다. `sprintf()`와 비슷.

`cout`, `cin` 쓰는 곳에 거의 비슷하게 쓰인다.

#### c headers
여전히 성능상의 이유로 많이 사용한다. `cstdio`, `cstring`, `cctype`, ...

#### string에서 가변 길이가 가능한 이유?

기존 용량보다 큰 용량이 필요해질 경우(현재 메모리 공간에 연속적으로 할당할 수 없는 경우)  
=> 메모리를 새로 할당한다.
1. 기존 값을 복사하고 새 메모리를 가리킨다.
2. 이전에 할당되었던 메모리를 해제한다.
3. 추가된 문자열을 복사해 넣는다.

왜 이렇게 복잡하게 운용되는가?
- 힙 메모리 할당이 복잡하기 때문(OS 전체에서 사용하기 때문에)
- memory fraction(메모리 단편화) 문제
- 내부 버퍼 증가는 멀티 쓰레드 환경에서 위험할 수 있다.*(ex. 메모리 재할당)*
- 성능이 중요한 업계에서 C++ 을 사용한다: 그래서 여전히 `snprintf`, `char[]`를 많이 사용.

`c_str()` 동작방식
- 내부적으로 `char[]`를 관리해 준다.  
(* `c_str()`의 반환은 `const char`로 받으며 따라서 변경할 수 없다. `string`의 내부를 변경할 수 없는 것.)

#### TIP. const 타입을 읽는 방법 -- 오른쪽에서 왼쪽으로
1. `const char *`  
: pointer to const char, const char를 가리키는 포인터
2. `char *const`  
: const pointer to char, char를 가리키는 const pointer.  
*(사실 여기서 const pointer 개념은 써 본 적이 없어서 직관적으로 이해가 되진 않는다.)*
3. `const char *const`
: const pointer to const char

**const는 기본적으로 붙이고 필요없을 때만 빼는 게 좋은 습관이다.**