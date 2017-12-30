## VisualStudio2017 설치하고 C로 Hello world 출력하기

---

비주얼 스튜디오 2017 인스톨하고 c로 hello world 출력하는데도 에러가 나서 한참 헤맸다.

1\) \[File\] &gt; \[New Project\] &gt; \[Visual C++\] &gt; \[Windows Desktop Wizard\]  
새 프로젝트에서 \[Windows Console Application\]으로 생성해도 되지만,  
C언어 교재에 나오는 Win32 응용 프로그램 마법사를 보려면 저렇게 생성해야 되더라.

2\) 그런 후 \[Security Development Lifecycle \(SDL\) checks\]항목은 체크 해제한 상태에서 완료

3\) 프로젝트가 생성되면 \[Solution Explorer\]창에서 Source Files폴더 오른쪽 클릭 &gt; \[Add\] &gt; \[new item\(Ctrl + Shift + A\)\]으로 확장자가 c인 파일을 생성한다.  
생성창에 \[C++ File\(.cpp\)\]이 있는데 그걸로 선택하고, Name에 확장자를 `.c`로 입력하면 된다.

4\) hello world를 출력하는 코드를 입력한다.

```
hello.c
----

#include <stdio.h>

int main(void)
{
  printf("Hello world\n");
  return 0;
}
```

5\) 프로젝트를 빌드한다. \[Build\] &gt; \[Build Solution\(Ctrl + Shift + B\)\]

6\) 에러를 감상한다\(...\)

| Description | File |
| --- | --- |
| unexpected end of file while looking for precompiled header. Did you forget to add '\#include "stdafx.h" to your source? | hello.c |

7\) 저 문구대로 구글링하니까 c파일 맨 위에 `#include "stdafx.h"`를 입력하면 된다던가, 아니면 솔루션 설정에서 미리 컴파일된 헤더를 사용하지 않음으로 변경하면 된다고 하던데 나는 둘다 안 되었다. 전자는 입력하면 새로운 에러가 2개 더 나오고, 후자는 변동이 없었음.

8\) 그래서 새로 나온 에러로 검색 해보니 `프로젝트이름.cpp`로 된 파일을 삭제하면 된다는 [내용](https://social.msdn.microsoft.com/Forums/vstudio/en-US/cf3b6326-6e58-4b85-afb1-2694a1450128/error-lnk2005-main-already-defined?forum=vclanguage)이 보인다! 삭제하고 다시 빌드 ㄱㄱ  
\(지울 수 있는 선택지에 \[remove\]와 \[delete\]가 있는데 \[delete\]로 지웠다.\)

9\) 이때 또 stdafx.h에러가 나면 미리 컴파일된 헤더를 사용하지 않음 설정 해주면 된다. \[Solution Exploer\] &gt; 프로젝트 이름\(최상단 솔루션 말고\) 오른쪽 클릭 &gt; \[Properties\(Alt + Enter\)\] &gt; \[C/C++\] &gt; \[Precompiled Headers\] &gt; \[Precompiled Header\]를 \[Not Using Precompiled Headers\]으로 설정

10\) 드디어 빌드에 성공했다\(눈물\). \[Debug\] &gt; \[Start Without Debugging\(Ctrl + F5\)\]을 하면 콘솔창에서 내가 입력한 hello world를 볼 수 있다.

#### 키워드

* 비주얼 스튜디오 사용
* 프로젝트 생성
* c hello world 출력
* 미리 컴파일된 헤더 파일 사용 안 함

#### 미해결 문제

* [ ] 빌드, 디버깅이란?
* [ ] 디버깅 시작\(실행 후 콘솔창 종료\) / 디버깅 없이 시작은 무슨 차이?
* [ ] `#include "stdafx.h"`로 입력한 것과 `#include <stdio.h>` 헤더 파일을 큰 따옴표로 입력한 것, 꺽쇠로 입력한 것 의미 차이 있나?

#### 멘탈

* 윈도우 어렵다. 맥이나 계속 쓰고 싶은데, 나중 생각하면 어차피 써야되니까 미리 쓰는게 낫겠다\(OS 안 익숙하면 그것도 적응하는데 시간 까먹음\).
* 코드만 치면 되겠지 했는데, 셋팅하는데 생각보다 오래 걸리고 어려움
* 영어로 검색해야 해결책이 잘 나온다.
* 어쨌든 이제 실습 할 수 있게 되어서 기분이 좋음
* 프로그램 설치할 때 깜박하면 한글로 깔려서 불편하다\(운영체제 언어 따라가는 듯\). 에러 메시지가 한글로 나오는데 한글로 검색하면 결과가 잘 안 나와서 영어로 검색할 수 있는 영문판 설치 필요..실행하고 아차해서 언어 변경하는 법을 검색하는 나 ㅠㅠ

