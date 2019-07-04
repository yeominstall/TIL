# 2장. 의미 있는 이름

### 의도를 분명히 밝혀라

변수나 함수, 클래스 이름은 다음과 같은 주요한 질문들에 답할 수 있어야 한다.
* 존재 이유
* 수행 기능
* 사용 방법

따로 주석이 필요하면 의도를 드러내지 못한 것 -- 잘못된 네이밍  
**코드의 함축성** -- 코드 맥락이 코드 자체에 명시적으로 드러나야 한다.
```java
public List<Cell> getFlaggedCells() {
    List<Cell> flaggedCells = new ArrayLists<Cell>();
    for (Cell cell : gameBoard)
        if (cell.isFlagged())
            flaggedCells.add(cell);
    return flaggedCells;
}
```

### 그릇된 정보를 피하라

* 실제 List 컨테이너가 아닌데 List라는 이름을 사용  
    _하지만 List 컨테이너에 *List라는 이름을 사용하는 것도 바람직하진 않다._
```c++
std::vector<int> flagList;  // 잘못된 변수명.
```
* 일관성이 떨어지는 표기법  
    유사 개념은 유사 표기법을 사용해야 한다. 유사성도 정보다.
* 소문자 L과 대문자 O의 혼용
```c++
if (O == l) a = Ol;
```

### 의미 있게 구분하라

지으려던 이름이 이미 사용되고 있다고 해서 약간 변형해서 쓰면 안 된다.   
_ex. Product와 ProductInfo, zork와 theZork, getActiveAccount()와 getActiveAccounts()와 getActiveAccountInfo()_


### 발음하기 쉬운 이름을 사용하라

genymdhms(generate year month day hour minute second)를 젠 야 무다 힘즈 따위로 읽도록 만들지 않는다.  
_-- generationTimestamp_

### 검색하기 쉬운 이름을 사용하라

변경 사항이 생길 때 변수를 검색해서 수정할 수 있어야 한다.  
* [[N5]()]**이름 길이는 범위 크기에 비례해야 한다.**  
_간단한 메서드나 로컬 변수 정도에나 한 글자짜리 이름을 사용한다._  
* 자주 쓰이는 상수에는 이름을 붙인다
```c++
// before
for (int j = 0; j < 34; j++) {
    s += (t[j] * 4) / 5;
}

// after
int realDayPerIdealDay = 4;
const int WORK_DAYS_PER_WEEK = 5    //--named constant
int sum = 0;
for (int j = 0; j < NUMBER_OF_TASKS; j++) {
    int realTaskDays = taskEstimate[j] * realDayPerIdealDay;
    ...
}
```

### 인코딩을 피하라
> [?] 여기서 말하는 인코딩이 뭔지 잘 모르겠다.

#### 헝가리식 표기법(Hungarian Notation)
>: 변수에 타입을 나타내는 접두어를 붙여 데이터 타입을 명시하는 방식  
>_ex. char* strName, int *pN, char chCategory, ..._  

타입이 바뀌어도 이름은 바뀔 필요가 없어야 한다.

#### 멤버 변수 접두어
접두어가 필요 없을 만큼 작은 단위의 클래스를 운용한다.

#### 인터페이스 클래스와 구현 클래스
를 접두어로 굳이 나타내지 않는다.

### 자신의 기억력을 자랑하지 마라
남들이 이해하는 명료한 이름을 사용하는 것이 곧 전문성이다.

### 클래스 이름(객체 이름)
명사나 명사구가 적합하다. _Customer, AddressParser_

### 메서드 이름
동사나 동사구가 적합하다. _deletePage, save_  
생성자를 중복정의(overload) 할 때는 정적 팩토리 메서드를 사용한다.
```c++
Complex fulcrumPoint = Complex.FromRealNumber(23.0);
```

### 기발한 이름은 피하라
구어체나 속어에 기반한 이름을 사용하지 않는다.


### 한 개념에 한 단어를 사용하라
똑같은 기능을 하는 메서드인데 클래스마다 이름이 다르다면 혼란을 유발한다.

### 말장난을 하지 마라
### 해법 영역에서 가져온 이름을 사용하라
기술 개념의 이름을 빌려올 수 있다. 오히려 이 편이 독자(프로그래머)에게 쉬울 수 있다.

### 문제 영역에서 가져온 이름을 사용하라
_문제 영역과 해법 영역을 구분할 줄 알아야 한다._

### 의미 있는 맥락을 추가하라
### 불필요한 맥락을 없애라