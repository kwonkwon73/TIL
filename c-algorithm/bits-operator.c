#include <stdio.h>

int main(){
	unsigned char num1 = 1; //0000 0001(2)
	unsigned char num2 = 3; //0000 0011(2)

	printf("%d\n", num1 & num2); //and연산, 0000 00001(2) -> 1(10)
	printf("%d\n", num1 | num2); //or연산, 0000 00011(2) -> 3(10)
	printf("%d\n", num1 ^ num2); //xor연산, 0000 0010(2) -> 2(10)

	return 0;
}
