/*moon year
조건 :
연도가 4로 나누어 떨어진다.
100으로 나누어 떨어지는 연도는 제외한다
400으로 나누어 떨어지는 연도는 윤년이다

연도 입력 : 4자리 정수만 입력 가능
입력한 정수가 윤년인지 판단

1600

(x % 4 = 0) && (x % 400 = 0) && !(x % 100 = 0)

100의 배수이면서 400의 배수가 아니면 -> 윤년이 아닙니다.
(year % 100 == 0) && !(year % 400 == 0)

(!(year % 4 == 0) && (year % 100 == 0)) && !(year % 400 == 0)

((year % 4 == 0) && !(year % 100 == 0)) && (year % 400 == 0)

*/

#include <stdio.h>

int main(void)
{
	int year;
	printf("년도(4자리 정수)를 입력하시면 윤년인지 판단이 가능합니다: ");
	scanf("%d", &year);

	if (((year % 4 == 0) && !(year % 100 == 0)) || (year % 400 == 0))
	{
		printf("%d년은 윤년이 맞습니다.\n", year);
	}
	else
	{
		printf("%d년은 윤년이 아닙니다.\n", year);
	}

	return 0;
}
