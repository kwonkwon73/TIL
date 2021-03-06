## 비주얼스튜디오로 생성한 프로젝트파일, git으로 버전 컨트롤하기

---

지금은 버전 컨트롤이 필요한 수준이 아니지만, 노트랑 코드도 같이 볼 수 있게 github에 올리기로 했다. 그리고 공부할 때는 코드 파일에 주석으로 메모하는 경우도 잦아서 이런 메모는 트랙킹이 되면 편하더라. \(뭐가 문제였는데 이렇게 하니 해결이 되었다는 과정을 남길 수 있음\)

사실 처음엔 큰 고민없이 비주얼 스튜디오에서 생성한 프로젝트 파일을 몽땅 때려 넣으려고 했는데, 특정 파일이 권한이 거부되면서 커밋에 에러가 났다.

그리고 실행 파일이 지저분하게 생기면서 해당 repository에서 확장자가 c인 파일과 md인 파일만 tracking 하도록 설정하려 했으나, 다음 링크를 참고해 시도해본게 의도대로 되지 않았다. 작동하는 방식을 이해하기 보다 우선 되게 하려고 해서 적당히 코드만 복붙해서 그런 것 같다.

* [https://gs.saro.me/\#!m=elec&jn=737](https://gs.saro.me/#!m=elec&jn=737)
* [http://rapapa.net/?p=85](http://rapapa.net/?p=85)
* [https://hyeonseok.com/soojung/dev/2016/07/12/797.html](https://hyeonseok.com/soojung/dev/2016/07/12/797.html)

어쨌든 당장은 목표가 _'gitignore을 마스터해야지!'_ 가 아니라 _'뺄껀 빼고 올리자'_ 이므로 다른 방법을 검색했다. 템블릿 파일이 있는 걸 알게 됐다.

* [https://www.gitignore.io/](https://www.gitignore.io/)
* [https://github.com/github/gitignore/blob/master/VisualStudio.gitignore](https://github.com/github/gitignore/blob/master/VisualStudio.gitignore)

1\) gitignore.io에서 windows, c, c++을 태그로 넣고 생성된 내용을 `.gitignore`파일에 넣었는데 그래도 permission denined에러를 발생시키는 `opendb`등의 파일이 빠지지 않았고, 원치 않는 내용들이 올라가길래  
2\) visual studio gitignore 따위로 검색하니 아래 링크로 원하는 결과가 나왔다! 사용해보니 불필요한 파일은 깔끔하게 무시된다. 굿굿. 추후에 gitignore 작성 패턴을 공부하고 싶을 땐 이 파일로 어떻게 작성해야 어떻게 동작하는지 알 수 있을 것 같다.

#### 키워드

* `.gitignore` 템플릿 사용

#### 미해결문제

* [ ] `.gitignore` 파일 작성법

#### 멘탈

* 웹으로 혼자 끄적끄적 할 때는 필요성을 느낀 적이 없었는데, 이렇게 프로젝트를 올려보니 이래서 필요하구나를 알 수 있었다.



