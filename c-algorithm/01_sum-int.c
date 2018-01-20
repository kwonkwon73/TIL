/*1에서 100까지 정수들의 합을 구해 출력하는 프로그램*/

#include <stdio.h>

int main(void){
	int start = 1;
	int end = 100;
	int sum = 0;
	int i;

	//처음 생각한 알고리즘
	//for(i=start; i<=end; i++){
	//	sum = sum + i;
	//}
	
	//강의 듣고 생각남
	// (1+100)*100/2
	//sum = (start + end) * ((end - start + 1) / 2);  
	
	// 이거 일반화 할 수 있나? 시작이 1이 아닌 경우?
	// 더하는 항목의 갯수가 홀수인 경우? (이건 상관 없이 답 나오는 것 같은데)
	printf("더하기를 시작할 숫자와 끝낼 숫자를 입력하세요:");
	scanf("%d%d", &start, &end);

	sum = (start + end) * ((end - start + 1) /2);

	printf("%d부터 %d까지 정수들의 합\n", start, end);
	printf("%d\n", sum);

	return 0;
}
