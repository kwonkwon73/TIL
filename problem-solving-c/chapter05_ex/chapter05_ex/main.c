// ���ǽ� ������ conditional operator
// ���ǽ� �����ڸ� ���� �����ڶ�� �ϴ±���. (�� �����ڸ� 3�� ����Ѵٰ� �ؼ�, expression ? expression : expression)
// ù��° �ǿ����ڴ� �Ͻ������� bool�� ��ȯ
// ù��° �ǿ����ڰ� true(1)�� �ι�° �ǿ����� ���
// ù��° �ǿ����ڰ� false(0)�� ����° �ǿ����� ���
// ���� : https://msdn.microsoft.com/ko-kr/library/e4213hs1.aspx 

#include <stdio.h>

int main(void)
{
	int x, y, z = 0;

	printf("�� ���� �Է��ϼ��� : ");
	scanf("%d %d", &y, &z);
	x = (y < z) ? y : z; // z�� y���� ũ�� x�� y����, z�� y���� �۰ų� ������ x�� z����

	/*
	�� ���ǽ� �����ڸ� if�� ǥ���ϸ� ������ ����
	if (y<z)
		x = y;
	else
		x = z;
	*/

	printf("y = %d < z = %d = %d, x = %d \n", y, z, y < z, x);

	return 0;
}