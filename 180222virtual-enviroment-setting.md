## 문제

웹 크롤링을 위한 개발 환경 설정이 안 되어 있음

## 가이드

[자바스크립트와 Node.js 를 이용한 웹 크롤링 테크닉](http://www.aladin.co.kr/shop/wproduct.aspx?ItemId=99209938)

---

## 이번에 알게 된 것

- 프로그램 개발에 편리한 가상 환경을 구축하여 사용 (VirtualBox 위에  CentOS 설치)

> p.11
>
> 독자와 필자의 운영체제 차이로 생기는 여러 에러 메시지에 관한 걱정 없이 코드의 설명에 집중할 수 있다. 또한, 가상 환경을 만들면 다양한 실험을 해볼 수 있으며, 문제가 생겨도 쉽게 복구할 수 있다. 어떠한 무리한 프로그램을 실행시켜도 호스트 머신 환경에 영향을 미치지 않기 때문이다.

- 가상 머신 제어

  - 기동 상태 확인 `vagrant status`
  - 실행 중인 가상 머신 종료 `vagrant halt`
  - 가상 머신 시동 `vagrant up`
  - 가상 머신 휴면 `vagrant suspend`
  - 가상 머신 휴면 상태에서 복원 `vagrant resume`
  - 가상 머신 재시동 `vagrant reload`
  - 가상 머신 삭제 `vagrant destroy`
  - 가상 머신에 로그인 `vagrant ssh`
    - mac이라 따로 설정할 것 없이 로그인 된 것 같은데, 윈도우에서는  ssh 클라이언트에서 접속해야 되는 듯


- Node.js 설치 \(가상머신에\)

  1. nvm 사용

    > p.19
    > node.js는 버전에 따라 동작이 다르다. 그래서 nvm이라는 도구를 사용해서 특정 버전의 Node.js를 설치할 것이다.

    `curl -o- https://raw.githubusercontent.com/creationix/nvm/v0.25.3/install.sh | bash`

    - `logout`후 재시동

      - 재시동하면서 기본 접속 정보 확인할 수 있었음![](/assets/screen 94.jpg)
      - 재시동하고 `vagrant ssh`로 가상머신에 로그인까지 해야함

    - Node.js 0.12.4 설치

      - `nvm install v0.12.4`
      - `nvm alias default v0.12.4`
      - 설치(및 버전) 확인 `node -v`

    - Node.js REPL(Read-Eval-Print-Loop)
      - 아 이걸 REPL이라고 부르는구나. 파이썬에서는 인터프리터라고 불렀던 것 같은데
      ![](/assets/screen 95.jpg)

    - `sudo visudo`
      - 설정 항목 수정
      > p.20
      > nvm을 사용해서 Node.js를 설치한 경우에는 sudo 명령어와 함께 npm이나 node 명령어를 사용할 수 없다. 이를 위해 sudo 명령을 실행할 때의 패스(PATH: 프로그램이나 명령을 찾는 기본 경로를 담고 있는 환경 변수)를 일반 사용자의 패스와 같게 해야 한다.


  - git 설치
  - 가상 머신에서 웹 서버 사용하기 위한 설정
  > p.21
  > 가상 머신에 웹 서버를 만들면 기본적으로 호스트 머신에서 접근할 수 없음. 접근할 수 있게 하기 위해서는 Vagrant의 설정 파일 Vagrantfile에 다음 내용 추가

    - 에러 메시지 발생
      - ``` There was an error loading a Vagrantfile. The file being loaded
  and the error message are shown below. This is usually caused by
  a syntax error.

  Path: /Users/Kwonkwon/Vagrantfile
  Line number: 77
  Message: NameError: undefined local variable or method `config' for main:Object ```


---
## 새로 생긴 질문

- [ ] 파이썬도 가상 환경 만들어서 코드 돌려봤던 것 같은데 \(한두달 전이라 기억이 안남 흑흑...\) 이거랑 비슷한건가? 툴만 다르고
- [ ] 인터프리터 / REPL?
