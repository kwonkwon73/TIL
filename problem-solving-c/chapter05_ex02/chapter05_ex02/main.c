//1부터 입력한 수까지 각 수의 제곱 구하기

#include <stdio.h>

int main(void)
{
	//변수 선언 : 입력 받을 수
	int end;
	//변수 선언 : 반복문에 쓰일 변수
	int i, squrt;

	//수 입력 받기
	printf("1부터 입력한 수까지 각 수의 제곱을 구합니다.\n 마지막 수를 입력하세요. \n");
	scanf("%d", &end);

	//각 수의 제곱 구하기
	for (i = 1; i <= end; i++) {
		squrt = i * i;
		//printf("%d^2은 %d\n", i, squrt);
		printf("%5d^2= %10d\n", i, squrt); //출력 형식 지정, 5칸 잡고 오른쪽 정렬, 10칸 잡고 오른쪽 정렬
	}
	
	printf("%d까지 각각의 수의 제곱을 모두 구했습니다. \n", end);

	return 0;
}