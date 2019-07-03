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
* 소문자 L과 대문자 O의 혼용
```c++
if (O == l) a = Ol;
```
