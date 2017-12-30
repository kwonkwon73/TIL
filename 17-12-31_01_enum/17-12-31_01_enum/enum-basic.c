#include <stdio.h>

enum COUNT { ZERO = 1, ONE, TWO}; //아 꼭 main함수 안에만 다 써야 되는게 아니구나

int main(void)
{
	enum COUNT nCount; //enum형 선언, enum COUNT를 nCount라고 함
	nCount = ONE; // 값 대입, nCount가 enum COUNT이기 때문에 얘한테 ONE은 2와 동일함
	printf("출력 : nCount = %d \n", nCount); //그래서 nCount = ONE을 대입하고 출력한 결과가 2가 나오는 것임
	return 0;
};