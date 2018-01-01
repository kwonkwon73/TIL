## FMOD 사운드 시스템

* 튜토리얼
  [https://youtu.be/W95Bi6QJXVk](https://youtu.be/W95Bi6QJXVk)
* fmod 구버전 다운로드

  * [http://cafe.daum.net/nowcampus/dbMz/7](http://cafe.daum.net/nowcampus/dbMz/7)
  * 혹은 [fmod.org](https://www.fmod.com/)에서 최신 버전을 받을 수 있다.

* 환경설정  
  버전이 달라서 튜토리얼에 안내되어 있는 `fmodex_vc.lib`이 파일이 없어서 에러가 난다.  
  API 폴더에 후보가 3개 정도 있었는데 example 까보니까 이렇게 써야된다.

* 프로젝트 \[properties\] &gt; \[Linker\] &gt; \[Input\] &gt; \[Additional Dependencies\] &gt; `fmodL_vc.lib`

따라서 헤더 파일, 라이브러리 파일 경로도 이렇게 등록.

* 헤더 파일
  * \[properties\] &gt; \[VC++ Derectories\] &gt; \[Include Directories\] &gt; \[C:\Program Files \(x86\)\FMOD SoundSystem\FMOD Studio API Windows\api\lowlevel\lib\]
* 라이브러리 파일
  * \[properties\] &gt; \[VC++ Derectories\] &gt; \[Library Directories\] &gt; \[C:\Program Files \(x86\)\FMOD SoundSystem\FMOD Studio API Windows\api\lowlevel\inc\]

fmodL\_vc.dll 파일은 실행 파일\(.exe\)이랑 같이 넣어줘야 되므로 이렇게 투척

* \[프로젝트 폴더\] &gt; \[Debug\]

이렇게 설정하면 라이브러리 못 찾는 에러 해결! 이제 FMOD 사용 가능하다.



1. fmod 사운드 프로그래밍

   > '...헤더 파일에 &lt;&gt;을 사용할 수 있는 것은 헤더 파일의 경로를 프로그래밍 툴에 등록했기 때문이다..p101

* 헤더 파일 "", &lt;&gt; 구분 진짜 이렇게 하나? \(외부 라이브러리 "", 내부 라이브러리 &lt;&gt;\)



* 코드 따라했는데 에러 발생
* 책에서 제공하는 샘플코드도 동작 안 됨
  * 아아아 뭘 잘못한거지



#### 멘탈

* examples 실행해보면 재밌음, 특히 콘솔에서 노래 나오는데 신선하다 ㅋㅋㅋㅋ
  * 요즘같이 그래픽 빵빵한 시대에 콘솔 텍스트 인터페이스 + 반전매력 고급진 소리\(?\)
* fmod.org 홈페이지에 사용예, 튜토리얼 보면 사운드 디자인 매우매우 배워보고 싶어짐

  * 특히 지형맵 따라 소리가 달라지는거, 물리+소리 걷기, 거리...
  * 전부터 배우고 싶었는데 그때는 음악치라 안돼...라고 생각했다가
  * 지금은 뭐 하면 해보지 라는 마음가짐 \(잘하든 못하든\)
  * 또 해보고 싶은 이유가, 생각보다 텍스트 -&gt; 소리로 변환하는 과정에 잃게 되는 정보가 많더라.
  * 특정 맥락에는 다른 폰트를 사용하고, 의미 구분을 위해 단락 구분하는 등의 의도가 희미해지는게 아쉽다.
  * 여튼 결론은 이래저래 하고 싶은거 테스트해보는데 게임이 가장 좋은 베이스인걸 새삼 느낌



