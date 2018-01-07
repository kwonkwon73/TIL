import pygame
pygame.init()

screen = pygame.display.set_mode((1000, 400)) #튜플사용, 리스트랑 비슷한데 값 바꿀 수 없는 것
pygame.display.set_caption('First pygame 파이게임')
finish = False

while not finish:
    for event in pygame.event.get(): #발생한 이벤트 리스트 가져옴
        if event.type == pygame.QUIT:
            finish = True
        pygame.display.flip() #화면 업데이트 flip()과 update() 가능


