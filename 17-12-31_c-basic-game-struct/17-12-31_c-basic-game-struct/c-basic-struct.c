#include <stdio.h>
#include <time.h>

int g_nFramCount; //������ ����

void Init()
{

}
void Update()
{

}
void Render()
{

}
void Release()
{

}

int main(void)
{
	clock_t CurTime, OldTime;
	Init();

	OldTime = clock(); //OldTime �ʱ�ȭ
	while (1)
	{
		Update();
		Render();

		while (1)
		{
			
			CurTime = clock();
			if (CurTime - OldTime > 33)
			{
				OldTime = CurTime;
				break;
			}
		}
		g_nFramCount++;
	}

	Release();
	return 0;
}
