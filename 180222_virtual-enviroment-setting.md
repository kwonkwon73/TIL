## 문제

웹 크롤링을 위한 개발 환경 설정이 필요함

## 가이드

[자바스크립트와 Node.js 를 이용한 웹 크롤링 테크닉](http://www.aladin.co.kr/shop/wproduct.aspx?ItemId=99209938)

---

## 이번에 알게 된 것

- 프로그램 개발에 편리한 가상 환경을 구축하여 사용 (VirtualBox 위에  CentOS 설치)
  - [ ] 파이썬도 가상 환경 만들어서 코드 돌려봤던 것 같은데 \(한두달 전이라 기억이 안남 흑흑...\) 이거랑 비슷한건가? 툴만 다르고

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
        - [ ] 인터프리터 / REPL?

    - `sudo visudo`
      - 설정 항목 수정
      > p.20
      > nvm을 사용해서 Node.js를 설치한 경우에는 sudo 명령어와 함께 npm이나 node 명령어를 사용할 수 없다. 이를 위해 sudo 명령을 실행할 때의 패스(PATH: 프로그램이나 명령을 찾는 기본 경로를 담고 있는 환경 변수)를 일반 사용자의 패스와 같게 해야 한다.


  - git 설치
  - 가상 머신에서 웹 서버 사용하기 위한 설정
  > p.21
  > 가상 머신에 웹 서버를 만들면 기본적으로 호스트 머신에서 접근할 수 없음. 접근할 수 있게 하기 위해서는 Vagrant의 설정 파일 Vagrantfile에 다음 내용 추가 (end 위에 기술)
  >
  > 가상 머신의 웹 서버 포트 80이 호스트 머신의 포트 8080에 할당
  >
  > `config.vm.network "forwarded_port", guest: 80, host: 8080`
  >
  > 가상 머신의 IP 주소가 192.168.33.10
  >
  > `config.vm.netword "private_network", ip: "192.168.33.10"`

    - 에러 메시지 발생
    ```
    There was an error loading a Vagrantfile.
    The file being loaded and the error message are shown below. This is usually caused by a syntax error.
    Path: /Vagrantfile
    Line number: 77
    Message: NameError: undefined local variable or method `config' for main:Object
    ```
      - 아 삽질 ㅋㅋㅋㅋ [document](https://www.vagrantup.com/docs/vagrantfile/machine_settings.html) 보니까 `config.vm`있는데 뭐지.. 했다가 end 위에 적어야 되는걸 end 밖에다 적으니 당연히 에러가 나지 깨달음 하하
      - [ ] vim 해당 줄 복사 / 붙여넣기, 선택 영역 expand 단축키?
  - 호스트 머신과 가상 머신 간의 폴더 공유
    - `config.vm.synced_folder "호스트 머신의 경로", "가상 머신의 경로"`
      - 이거 설정하고나니 가상머신 호스트이름(?)이 `vagrant@ip`에서 `bash`로 바뀌었다. 폴더 공유는 제대로 된다. 아마 가상 머신 경로가 문제가 있는 것 같은데, 정확히는 모르겠다. 또 로그인할 때 비밀번호 묻게 변경됨. 참고로 기본 계정 정보는 id : `vagrant`, pw : `vagrant`이다.
        - 위에 "가상머신의 경로"를 `/home/vagrant` 로 입력했는데, `/vagrant` 로 바꾸니 위와 같은 형상 없어졌다. 책에 보니 특별한 설정 없이도 가상 머신의 /vagrant 폴더가 호스트 머신의 설정 폴더(Vagrantfile이 있는 폴더)와 공유된다는 내용이 있었는데 이와 관련이 있는 것 같다.
        - 아 ㅋㅋㅋㅋㅋ 근데 이번엔 폴더 공유가 안됨 ㅠ.ㅠ 호스트 머신에 플러그인 설치를 하나 했는데 에러 메시지가 뜸
          - 호스트 머신에 설치한 플러그인(다음 명령어를 입력하면 가상 단말에 VirtualBox-guest-addition의 설치 여부를 확인한 후 필요 시에 자동으로 설치가 이루어진다고 설명) `vagrant plugin install vagrant-vbguest`
          - 에러 메시지 `Removing existing VirtualBox DKMS kernel modules`
            - [ ] VirtualBox-guest-addition 이게 뭔지?
            - [ ] 에러 메시지 의미? (무슨 조치가 필요한지)
          - 본문에서 vbox 재빌드함으로 문제가 해결되기도 한다고 하여 가상 머신에서 아래 명령어 입력 `sudo /etc/init.d/vboxadd setup`
          - 에러 메시지 `Could not find the X.Org or XFree86 Window System, skipping.`
            - vbox는 설치되어 있음 5.0.26 버전
            - VirtualBox 다운로드에서 덮어 쓰지 말라고 하는 것 같아서;; 인스톨은 안함... 버전 문제인가?
            - 허허 경로 문제였나보다. 가상 머신에 sources 폴더 새로 하나 만들고 `/home/vagrant/sources` 라고 입력하니 sync 됨! 아아 이제 본론으로 넘어갈 수 있겠다 ㅠㅠㅠㅠ

    > p.22
    >
    > 호스트 머신에서 개발하고 가상 머신에서 실행
    > 호스트 머신과 가상 머신 간에 폴더가 공유되면 편리한 점이 많다. 예를 들면, 호스트 머신인 윈도우(혹은 Mac OS X)에서 프로그램을 작성한 후에 가상 머신 위의 CentOS에서 프로그램을 실행하는 것이 쉬워진다. 또한, 이 책의 예제 코드를 다운로드하고 압축을 해제하는 것은 호스트 머신에서 수행하고, 실행은 가상 머신에서 할 수도 있다.

  - Node.js 모듈 설치
    - npm 사용법
    > p.24
    > Node.js의 이점은 많은 모듈이 공개되어 있다는 점이다. 패키지 관리자인 npm을 사용하면 모듈을 쉽게 설치할 수 있다.
    >
    > npm이란?
    > npm은 Node.js의 모듈을 관리하는 패키지 관리자다. 기본적으로 Node.js의 모듈을 설치하는 목적으로 사용된다. 그리고 Node.js로 만든 애플리케이션을 설치할 수도 있다.

    - 책에 설치에 필요한 설정(글로벌 설치 등) 안내 되어있으나 우선은 가상 머신에 설치 제대로 되는 것 확인하고 넘어감
