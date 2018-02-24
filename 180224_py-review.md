## 문제
파이썬 기초 내용 복습
(머신러닝 튜토리얼에 필요한데 기본 내용 익힌게 기억이 안남
- 덧. 초기에 공부한 내용은 복습 겸 공유하기 위해 카드형 콘텐츠로 만들었더니 검색이 안 되어서 불편함 =.=


## 가이드
[점프 투 파이썬](https://wikidocs.net/book/1)

---

## 내용

- 문자열 포매팅
  - https://wikidocs.net/13#_12
  - 이거 c언어 공부할때도 나왔던 내용이라 노트에 정리해뒀었음
  - d가 숫자, s가 문자 맞음 `print("%d" % number)`
    - 변수 타입 체크 `type()`
    - `input()`은 기본값이 스트링으로 저장된다. 아래와 같이 하면 에러남
    ```py
    x = input("더할 숫자를 입력하세요 : ")
    y = input("더할 숫자를 입력하세요 : ") #생각해보니 입력 받는 문장도 반복되니까 문자열 포매팅 사용하는게 편할 듯
    print("결과값 : %d", x + y) #%d와 x+y 데이터 타입 맞지 않아 에러 발생
    ```

- 여러개 변수 한 번에 선언하기 (JavaScript, Python)
  -  Python에서 `sum, num = 0` 으로 선언하니 `TypeError: 'int' object is not iterable` 에러 발생하여 찾아보게 됨. 이런 식으로 선언되는게 있었는데... C는 아니고 js는 가능했던 것 같은데 확실하지 않음
  - Python
    - https://dojang.io/mod/page/view.php?id=846
      > 변수와 값의 개수가 맞지 않으면 에러가 발생합니다.

    - `sum, num = 0, 0` 처럼 입력하거나 `sum = num = 0` 이런 식으로 입력해야 되는구나.
  - JavaScript
    - [3가지 방법으로 변수 선언 가능](https://developer.mozilla.org/ko/docs/Web/JavaScript/Guide/Values,_variables,_and_literals)
      - var, let, =(대입 연산자)
        - [ ] 변수 선언하는 방법에 따라 범위 달라지나보네? 이게 에러 발생하는 원인이 될 수 있으니 테스트 해봐야겠다.
    - https://jsbin.com/tererukinu/edit?js,console
      ```js
      //1. 변수 선언
      var a = 1
      console.log(a) // 1

      //2. 기대대로 동작 안 함
      var b, c = 1
      console.log(b) // undefined
      console.log(c) // 1

      //3. 변수 선언
      c = 2
      console.log(c) // 2

      // 4. 에러 발생, ReferenceError: d is not defined
      d, e = 2
      console.log(d)
      console.log(e)
      ```
      - 위 경우에서 1, 3은 변수 하나씩 선언할 때 쓸 수 있는 방법
      - 2에서 undefined가 나와서 뭐지 했는데, `var` 키워드를 쓰면 변수 여러개 선언 한 번에 가능은 하나 undefined가 기본값인 것 같다. 마지막에 있는 변수만 대입 연산자 값 들어가고.
        - 혹시 파이썬처럼 변수와 값 개수 맞추면 될까 싶어서 `var b, c = 1, 1` 로 해보았으나 `SyntaxError: Unexpected number` 자바스크립트에서는 안 된다.
        - `var b, c, d = 1`이면 `b, c`는 undefined, 마지막 `d`만 값 1 할당
  - 비교 연산자
    - 파이썬으로 사용자에게 입력 값을 받아서 특정 조건이면 종료되는 기능을 만드는데 헷갈려서 테스트해보고 정리함.
      - [ ] 자동 형변환 자바스크립트랑 파이썬 어떻게 처리되는지 찾아봐야겠다.
    - JS
      ```js
      a = 0
      console.log(typeof(a)) //number
      console.log(a=="0") //Ture

      b = "0"
      console.log(typeof(b)) //string
      console.log(b=="0") //Ture
      ```
    - Python
      ```py
      a = 0
      print(type(a)) #number
      print(a == "0") #False

      b = "0"
      print(type(b)) #string
      print(b == 0) #False
      ```

- 클래스
  - 원래 이 부분 복습이 메인인데 계산기 더하기 기능 예시 보고 만들다 정작 본론은 못 들어갔네, 허허. 근데 만들어서 재미는 있음! 위에 내용 다시 복습 하는 계기도 됐고.
  - `sum = sum + num`은 중복되는 `sum` 빼고 `sum += num` 으로 쓸 수 있음
