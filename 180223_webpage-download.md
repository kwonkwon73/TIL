## 문제
사이트에 있는 내용 자동으로 내려받기
이미지 파일 다운 받을 때 inspector로 image source 긁어서 하나씩 다운 받는게 매우 번거로움. 자동화 할 수 있는 방법

## 가이드
[자바스크립트와 Node.js 를 이용한 웹 크롤링 테크닉](http://www.aladin.co.kr/shop/wproduct.aspx?ItemId=99209938)

---

## 이번에 알게 된 것

- 가상 머신 폴더 구조
  - `/` 최상위 폴더
    - `/vagrant` -> 해당 경로는 호스트 머신의 Vagrantfile가 있는 폴더와 동기화 되는 듯
    - `/home/vagrant` -> 로그인 하면 나오는 경로 (바탕화면)
    - `/etc/sysconfig/` -> CentOS 설정파일?
      - vim에서 한글이 안 먹어서 utf-8 로 수정하려고 봤더니 이미 utf-8 임 =.=
        - 관련 내용 작성하여 스팀잇에 글 올림 [CentOS에서 vi 한글 깨질 때 수정 방법](https://steemkr.com/kr/@kwonkwon/centos-vi)
- Node.js로 웹 페이지 다운로드 하기
  - 와 쩔어 ㅋㅋㅋㅋㅋㅋ실행했을 때 파일 딱 생기니까 너무 기분 좋음 ㅋㅋㅋㅋㅋㅋㅋㅋㅋ 재밌다 ㅠㅠㅠ 로컬이랑 가상 머신이랑 연동하니까 작성 하고 결과물 확인하는 것도 이렇게 편하구나.

  ```js
  // url에 있는 파일을 savepath에 다운로드

  // 다운로드할 url 지정
  var url = "http://jpub.tistory.com/";

  // 저장할 위치를 지정
  var savepath = "test.html";

  // 사용 모듈 정의
  // 사용하는 모듈 require 통해 로드
  // -> Node.js에서는 require를 사용해 다양한 외부 모듈 사용할 수 있도록 선언함
  // ->> 그러고보니 내가 다운로드 한 적이 없는데 and 해당 폴더엔 아무 것도 없는데 어떻게 불러와서 쓸 수 있는거지? 구조? 방식?
  // ->>> 아, 아래 stream 모듈 보고 나니까 cdn 같이 가져오는게 아니라 프레임워크에서 제공하는 기능 단위 같이? 작동하는건가보다. 모듈에 node.js에서 제공하는 API라는 표현을 쓰네. nodejs에서 이미 정의되어 있기 때문에 require하고 바로 쓸 수 있는 것
  var http = require('http'); //HTTP 모듈
  var fs = require('fs');  // 파일 처리 관련 모듈

  // 출력 지정
  // 모듈 확보 완료되면 fs.createWriteStream() 메소드로 저장할 파일 이름 저장
  // -> fs.createWriteStream는 node에서 제공하는 기능인데, `Returns a new WriteStream object.` 라고 설명되어 있다.
  // ->> WriteStream 클릭하니 Class, `WriteStream is a Writable Stream.`
  // ->>> Writable Stream은 `Class: stream.Writable`
  // ->>>> stream 모듈??
  // > A stream is an abstract interface for working with streaming data in Node.js. The stream module provides a base API that makes it easy to build objects that implement the stream interface.
  var outfile = fs.createWriteStream(savepath);

  // 비동기로 url의 파일 다운로드
  //이어서 http.get() 메소드로 URL에 접속. 그러나 http.set() 메소드의 반환값이 우리가 획득하려는 데이터인 것은 아니다.
  // -> - [ ] 얘가 반환하는 값은 무엇? http.request()랑 비슷한 기능이 있나봐. 문서에 차이점을 언급하는 부분이 있네
  http.get(url, function(res) {
  	res.pipe(outfile);
  	res.on('end', function() {
  		outfile.close();
  		console.log("ok");
  	});
  });

  ```
  - '비동기적으로 수행' 의미
  > p.44
  >
  > Node.js에서는 시간이 걸리는 처리를 비동기적으로 수행하는 스타일을 사용한다. 즉, 수행이 끝날 때까지 진행을 멈추고 기다리는 대신, 처리가 완료되었을 때 콜백 함수가 호출되는 식이다. 그래서 서버에 요청만 보내고 수행 흐름이 계속 된다.
  > 우리가 원하는 데이터는 http.get() 메소드의 두 번째 인자로 지정한 콜백 함수에 전해진다. 콜백 함수의 res.pipe(outfile); 에서 다운로드한 데이터를 파일제 저장하도록 지정한다. 여기서도 지정만 할 뿐 이 시점에서 저장이 완료되는 거슨 아니다. 서버로부터의 response를 받는 데에도 시간이 걸리므로 처리가 완료되었을 때 다시 콜백 함수가 호출된다. 그것이 res.on();에 해당한다. 다운로드가 완료되면 end에 지정한 함수가 호출된다.

    - 아 그래서 끝나고 콘솔에 ok가 찍히는구나.
    - 몇 줄 안되는 간단한 코드인데도 흐름을 매끄럽게 이해하는게 아직 어렵다. 메소드가 무슨 일을 어떻게 처리하는지 수행 방식을 이해해야 할 것 같은데, 콜백도 무슨 뜻인지 모르니까, 일단은 기능들을 튜토리얼 보면서 많이 써보고(이게 이런게 되는구나) 그 다음으로 세세하게 확인(어떻게 되는거지?)하기로.  
  - 코드 리팩토링
    ```js
        // 다운로드
    download(
      "http://jpub.tistory.com/539",
      "spring.html",
      function(){
        console.log("ok, spring");
      }
    );

    download(
      "http://jpub.tistory.com/537",
      "angular.html",
      function() {
        console.log("ok, angular");
      }
    );

    //url의 파일을 savepath에 다운로드하는 함수
    function download(url, savepath, callback) {
      var http = require('http');
      var fs = require('fs');
      var outfile = fs.createWriteStream(savepath);

      var req = http.get(url, function(res){
        res.pipe(outfile);
        res.on('end', function(){
          outfile.close();
          callback();
        });
      });
    }
    ```
- Rhino / Narshon 사용
  - 생략
