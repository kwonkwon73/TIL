// 조건식 연산자 conditional operator
// 조건식 연산자를 삼항 연산자라고도 하는구나. (피 연산자를 3개 사용한다고 해서, expression ? expression : expression)
// 첫번째 피연산자는 암시적으로 bool로 변환
// 첫번째 피연산자가 true(1)면 두번째 피연산자 계산
// 첫번째 피연산자가 false(0)면 세번째 피연산자 계산
// 내용 : https://msdn.microsoft.com/ko-kr/library/e4213hs1.aspx 

#include <stdio.h>

int main(void)
{
	int x, y, z = 0;

	printf("두 수를 입력하세요 : ");
	scanf("%d %d", &y, &z);
	x = (y < z) ? y : z; // z가 y보다 크면 x에 y대입, z가 y보다 작거나 같으면 x에 z대입

	/*
	위 조건식 연산자를 if로 표현하면 다음과 같음
	if (y<z)
		x = y;
	else
		x = z;
	*/

	printf("y = %d < z = %d = %d, x = %d \n", y, z, y < z, x);

	return 0;
}