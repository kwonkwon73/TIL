#include <stdio.h>

int main(void){
	unsigned char num1 = 162; // 1010 0010(2) 128 32 2   
	unsigned char num2;

	num2 = ~num1; //0101 1101(2)   
	
	printf("%u\n", num2); //93출력, 0101 1101(2)    

	return 0;
}

