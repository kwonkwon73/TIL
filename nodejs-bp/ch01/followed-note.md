책 내용을 실습하면서 본문과 다른 부분들을 정리합니다.

기준 : 1쇄(2017.7)
실습 : 2018.1
--

1. p26, 4번 항목
  ```
  4. 이제 chapter-01/views 폴더에 있는 error.js와 index.js 파일을 (중략)
  ```
  위의 views 폴더에 `error.js`, `index.js` 대신 `error.ejs`, `index.ejs` 파일이 들어있어서 이걸 옮김

2. p26, 첫번째 코드 박스
 ```
 var routes = require('./server/routes/index');
 var user = require('./server/routes/users');
 ```
 `var users` 윗 줄에 `var routes` 대신 `var index` 만 있음. 이를 다음과 같이 수정함
 `var index = require('./server/routes/index');`
 참고로 `var routes`를 입력해 프로젝트를 실행하면 에러가 난다.
