#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf("***************************\n");
	printf("***1.��ʼ��Ϸ 0.�˳���Ϸ***\n");
	printf("***************************\n");
	printf("����������1��0:");
}
void game()
{
	char r;
	char board[ROW][COL] = { 0 };
	//��ʼ�����̣�������̣�
	Initboard(board, ROW, COL);
	//��ӡ����
	Displayboard(board, ROW, COL);
	//�˻�����
	while (1)
	{
		Player(board, ROW, COL);
		Displayboard(board, ROW, COL);
		r = Judge(board, ROW, COL);
		if (r != 'C')
			break;
		Computer(board, ROW, COL);
		Displayboard(board, ROW, COL);
		r = Judge(board, ROW, COL);
		if (r != 'C')
			break;
	}
	//�ж���Ӯ
	if (r == '*')
	{
		printf("���Ӯ\n");
	}
	else if (r == '#')
	{
		printf("����Ӯ\n");
	}
	else if (r == 'E')
	{
		printf("ƽ��\n");
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��ʼ��Ϸ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("��������ȷ��ѡ��\n");
			break;
		}
	} while (input);
	printf("��Ϸ������");
	return 0;
}