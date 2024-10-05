#include "Head.h"
#include "GlobalValue.h"

//������
void PrintGrid()
{
	system("cls");

	//��ӡ����
	cout << "Ŀǰ������" << game.CurScore << endl;
	cout << "��߷�����" << statis.HighestScore << endl << endl;

	string Side{ "+" };
	for (uint i = 0; i < 4 * statis.size + 3; ++i)
		Side += ' ';

	//���4��
	for (int x = 0; x < 4; ++x)
	{
		//�����߿�
		PrintLoop(Side, 4);
		cout << '+' << endl;

		//�����Ϸ�
		PrintLoop('\n', statis.size);

		//����
		for (int y = 0; y < 4; ++y)
		{
			PrintLoop(' ', GetSpaceLeft(game.grid[x][y]));
			if (game.grid[x][y] != 0)
				cout << game.grid[x][y];
			else
				cout << ' ';
			PrintLoop(' ', GetSpaceRight(game.grid[x][y]));
		}

		//�����·�
		cout << endl;
		PrintLoop('\n', statis.size);
	}
	//�ײ��߿�
	PrintLoop(Side, 4);
	cout << '+' << endl << endl;
}

//�ظ�cout
void PrintLoop(string str, int time)
{
	for (int i = 1; i <= time; ++i)
		cout << str;
}
void PrintLoop(char letter, int time)
{
	for (int i = 1; i <= time; ++i)
		cout << letter;
}

//��ȡλ��
//����0��λ��Ϊ0
int GetDigit(block x)
{
	if (x == 0)
		return 0;
	else
	{
		for (int n = 1;; ++n)
		{
			int digit_bas = (int)pow(10, n);
			if (x == (x % digit_bas))
			{
				return n;
			}
			else if (x % digit_bas == 0)
			{
				return n + 1;
			}
		}
	}
}

//���ո�����ȡ
int GetSpaceLeft(block x)
{
	if (GetDigit(x) == 1 || GetDigit(x) == 0)//һλ��
		return 2 * statis.size + 2;
	else if (x % 2 == 0)//ż��
		return 2 * statis.size + 2 - ((int)(0.5 * GetDigit(x)) - 1);
	else//����
		return 2 * statis.size + 2 - (int)(0.5 * (GetDigit(x) - 1));
}

//�Ҳ�ո�����ȡ
int GetSpaceRight(block x)
{
	if (GetDigit(x) == 1 || GetDigit(x) == 0)//һλ��
		return 2 * statis.size + 2;
	else if (x % 2 == 0)//ż��
		return 2 * statis.size + 1 - (int)(0.5 * GetDigit(x));
	else//����
		return 2 * statis.size + 1 - ((int)(0.5 * (GetDigit(x)) - 1));
}

