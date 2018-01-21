#include <stdio.h>

int main(void){
	unsigned char num1 = 3; // 0000 0011(2)
	unsigned char num2 = 24; // 0001 1000(2)

	printf("%u\n", num1 << 3); //24 -> 0001 1000(2)
	printf("%u\n", num2 >> 2); //6 -> 0000 0110(2)

	return 0;
}
