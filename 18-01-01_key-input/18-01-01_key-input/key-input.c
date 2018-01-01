#include <stdio.h>
#include <conio.h>
#include <time.h>

int g_nFramCount; //프레임 변수

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
	int nKey;
	clock_t CurTime, OldTime;
	Init();

	OldTime = clock(); //OldTime 초기화
	while (1)
	{
		if (_kbhit()) //키 입력 처리
		{
			nKey = _getch();
			if (nKey == 'q')
				break;
			switch (nKey)
			{
			case 'j' :
				break;
			case 'l' :
				break;
			}
		}
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
