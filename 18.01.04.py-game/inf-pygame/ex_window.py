#pygame 라이브러리를 gm 으로 불러오고, 초기화한다.
import pygame as gm
gm.init()

#c하다 파이썬하다 하니까 헷갈리기도 @.@ 특히 세미콜론..

#pygame 라이브러리의 메쏘드 활용해 콘솔창 띄우기
screen = gm.display.set_mode((400, 300)) #화면 크기는 튜플로 지정, 튜플은 리스트와 비슷하나 값 수정 불가
#콘솔창 이름 지정
gm.display.set_caption('hello pygame 안녕 파이게임')

#변수 선언
finish = False

#반복문 선언
## 화면을 띄우는 부분을 설명을 설명을 잘 못하네
### pygame 레퍼런스 문서를 보자!
#### https://www.pygame.org/docs/
while finish == False:
    for in
        if :
            finish == True
        gm.display.flip()