
## 아래 내용 반복되니까 필요한 만큼 숫자 더하게 하려면?
#a = input("더할 숫자를 입력하세요 : ")
#a = int(a)
#b = input("더할 숫자를 입력하세요 : ")
#b = int(b)
#c = a + b

## 계산기에서 = 버튼 누를때와 동일한 액션 필요함
## 입력된 키 체크받아서 특정 키(예를들어 엔터 2번이라든가) 누르면 결과값 출력하게 하려고 이벤트 바인딩? 내용 찾아봄
## 근데 엔터 두번 누르는 것도 기존 인터랙션(input일 때 엔터 눌러서 값 입력)하는 것과 헷갈리니까, 입력 값으로 숫자가 아닌 = 들어왔을 때 루프 종료하고 값 반환하는 함수를 만드는 걸 해볼 수 있을 것 같다.


sum =  0
msg = "더할 값을 입력하세요 : "
num = input("%s" % msg)

while True:
    if num != "=":
        num = int(num)
        sum = sum + num
        num = input("%s" % msg)
    if num == "=": #1. 원래 =등호가 입력되면 종료로 하려 했는데 위에 num=int(num)이 먼저 실행이 되는지 에러가 남. 우선 기능은 되는지 보게 0으로 바꿔서 실행
        print("결과값 : %d" %sum)
        break

#2. 아-0으로 바꿔도 소용 없구나. 에러 안 나고 Enter 한번 더 입력하게 됨.
#3. 비교하는 데이터 타입을 잘 못 써줬구나. num == "0"과 num == 0 다르다.
#또 저렇게 위에 변수 값 0으로 선언해놓고 종료 조건 0이면 안 되지 ㅋㅋㅋㅋ ㅠㅠ
#아 실행되는 순서 바꾸니까 되는구나! num 초기 선언에 아얘 input 넣고(while 안에서만 num 쓰려고 했는데 쪼갬), 판단 먼저 하고(종료인지 고인지) -> 입력값 형변환 -> 다음 수 입력 받기 순으로 하니까 동작함 ㅎㅎ  
