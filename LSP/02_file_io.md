# CHAPTER 2. 파일 입출력

파일은 읽거나 쓰기 전에 반드시 열어야 한다.
파일 디스크립터(file descriptor, fd)
* 음이 아닌 정수 값, int ~~(0이 포함되나? 모르겠다.)~~
    * -1 = error
    * 0 = stdin
    * 1 = stdout
    * 2 = stderr
* 프로세스가 연 파일의 정보는 파일 테이블에 저장되며, fd는 이 파일 테이블의 인덱싱이다.
* 파일 테이블의 각 항목은 inode를 가리키는 포인터, 메타데이터 등을 포함한다.
* 각 리눅스 프로세스가 열 수 있는 최대 파일 개수는 정해져 있다.

자식 프로세스는 부모 프로세스가 소유한 파일 테이블의 복사본을 상속받는다.
(자식 프로세스가 파일을 닫는다고 해서 부모 프로세스 등 다른 프로세스의 파일이 닫히진 않는다.)

## 파일 열기
### open() 시스템 콜
| flags     | description   |
|---        |---            |
| O_APPEND  | |
| O_ASYNC   | |
| O_CLOEXEC | |
| O_CREAT   | |
| O_DIRECT  | |

### 새로운 파일의 소유자
파일 소유자의 uid는 파일을 생성한(호출한?) 프로세스의 euid(유효 uid)다.  
파일의 소유 그룹은 기본적으로 파일을 생성한 프로세스의 egid(유효 gid)이나, BSD는 파일의 그룹이 상위 디렉터리의 gid로 설정되게 한다. 리눅스도 옵션을 통해 이런 방식으로 동작할 수 있다.  
gid가 중요할 경우 chown()을 사용해 명시적으로 설정해 주는 것이 바람직하다.

### 새로운 파일의 권한
파일 생성 시 mode 인자가 입력되지 않으면 파일 권한이 정의되지 않아 문제가 발생할 수 있다.
- 파일을 쓰기 상태로 열었지만 파일의 접근 권한이 읽기 전용일 수 있다
```c
fd = open(filename, O_RDONLY) // 모순 발생
```
- 시스템에 따라, 비트 위치에 따른 비호환성이 있을 수 있다. 이를 보완하기 위해 상수 집합이 제공된다  

| mode      | description   |
|---        |---            |
| S_IRWXU   | ...           |
| S_IRWXO   | ...           |
| ...       | ...           |

- 열고자 하는 파일이 존재하지 않고 umask가 022이면, 입력된 새 접근권한을 가지는 파일이 생성된다.

([?]옵션의 순서가 함수 실행에 영향을 미치는가?)

### creat() 함수
```c
// same
fd = open (filename, O_WRONLY | O_CREAT | O_TRUNC, 0664);
fd = creat (filename, 0644);
```

### 반환값과 에러 코드
open()과 creat()는 성공하면 fd를, 실패하면 -1을 반환한다.  

## read()로 읽기
```c
ssize_t read (int fd, void *buf, size_t len);
```

### 반환값
읽은 바이트 수가 ssize_t로 반환된다. 오류가 발생할 경우 -1을 반환한다.
읽을 수 있는 바이트가 len보다 작을 경우 read() 홀출은 읽을 바이트가 생길 때까지 블록된다.  

read()의 반환이 0이 될 경우:
- 사용 가능한 데이터가 없음(blocked)
- 파일 끝
