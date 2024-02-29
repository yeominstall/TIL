* C, C++ 과 같은 memory unsafe language 사용 중단 권고 (C++ 쓰지 말라는 부분만 대충 봄)
[Back to the building blocks](https://www.whitehouse.gov/wp-content/uploads/2024/02/Final-ONCD-Technical-Report.pdf)
  * 우주선 등 space ecosystem -- 매우 높은 안전성과 정확성을 요구하는 -- 은 메모리 안전 취약점에 대비가 되어 있지 않다.
  * 하지만 언어에 대해 아래 세 가지 제약 조건을 제시하고 있다.
    1. SW와 HW 가 밀접하게 상호작용할 수 있도록, 커널 레벨 조작이 가능해야 한다.
    2. 결과값 도출 시간을 일관되게 하기 위해 결정론?(determinism)을 지원해야 한다.
      * 무슨 말인지 모르겠군
    3. GC를 가지거나 재정의할 수 없어야 한다.
  * C, C++ 은 memory safe 하지 않다.
  * rust 써라
