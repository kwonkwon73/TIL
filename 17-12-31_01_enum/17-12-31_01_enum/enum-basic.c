#include <stdio.h>

enum COUNT { ZERO = 1, ONE, TWO}; //�� �� main�Լ� �ȿ��� �� ��� �Ǵ°� �ƴϱ���

int main(void)
{
	enum COUNT nCount; //enum�� ����, enum COUNT�� nCount��� ��
	nCount = ONE; // �� ����, nCount�� enum COUNT�̱� ������ ������ ONE�� 2�� ������
	printf("��� : nCount = %d \n", nCount); //�׷��� nCount = ONE�� �����ϰ� ����� ����� 2�� ������ ����
	return 0;
};