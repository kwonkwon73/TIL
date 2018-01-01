## 복습용

게임의 기본 구조는 \[초기화\] -&gt; \[데이터 갱신\] -&gt; \[렌더링\] -&gt; \[해제\] 인데,

여기서 \[데이터 갱신\] -&gt; \[렌더링\]은 무한 반복되는 부분이다.

```c
#include <stdio.h>

void Init()
{
}
void Update()
{
}
void Render()
{
}
void Release()
{
}

int main(void)
{
Init();

    while(1)
    {
        Update();
        Render();
    }
    
    return 0;
Release();
}

```

그 다음, 화면에 리소스를 출력해야 하는데 cpu 성능에 따라 프레임 출력하는 속도가 다르다.

30fps \(1초에 30프레임\) 정도면, 사람의 눈이 장면이 연결되어 있다고 인식한다. 



