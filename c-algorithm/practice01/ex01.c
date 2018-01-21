/*입력으로 두 개의 정수 a와 b를 받은 후, a^b을 계산하여 출력하는 프로그램을 작성하라. 단 b는 음이 아닌 정수이다. (예: 7^0 = 1, 2^5 = 32, 11^5 = 161051)*/

#include <stdio.h>

int main(void){

	int a, b;
	int i, result;
	int type_check;

	printf("a^b를 계산하기 위해 정수를 입력하세요.\n");
	printf("a : ");
	scanf("%d", &a);
	printf("b(단, b는 음이 아닌 정수이다) : ");
	scanf("%d", &b);

	//이걸로 문자 입력하면 바로 종료되게 하려 했는데,
	//a를 int로 선언해서 문자 입력해도 의도한대로 안 나온다.
	//type_check = sizeof(a);
	//printf("%d", type_check);
	
	if(b == 0){
		result = 1;
	}
	else{
		for(i = 1; i <= b; i++){
			result = result * a;
		}
	}
	
	printf("%d^%d 계산 결과 : %d\n", a, b, result);
	return 0;

}
