#include "Head.h"
#include "GlobalValue.h"

Game game{};
Statis statis{};

//��ʼ��
//Game�ṹ���ʼ��
void InitGame()
{
	game.CurScore = 0;
	game.IfStarted = false;
	game.CurTime = 0;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			game.grid[i][j] = 0;
}
//Statis�ṹ���ʼ��
void InitStatis()
{
	statis.IfNew = true;
	statis.name = "Player";
	statis.size = DEFAULT_SIZE;
	statis.HighestScore = 0;
	statis.HighestScore = 0;
	statis.TotalTime = 0;
	statis.GameTime = 0;
}

//���ɿ�
void CreateBlock()
{
	//��ȡ�¿��С
	//0.2�ĸ���Ϊ4��0.8Ϊ2
	block BlockNum{ (GetRand(1, 5) == 5) ? (block)4 : (block)2 };

	//��ȡ�¿�λ��
	uint row{}, col{};
	GetEmptyAddress(row, col);

	//д��
	game.grid[row][col] = BlockNum;
}
//��ȡ�����
uint GetRand(uint bot, uint top)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distrib(bot, top);
	return distrib(gen);
}
//��ȡ��λ��
uint GetEmptyNum()
{
	uint count{};
	for(int i = 0;i<4;++i)
		for (int j = 0; j < 4; ++j)
			if (game.grid[i][j] == 0)
				++count;
	return count;
}
//��ȡ��λ��ַ
void GetEmptyAddress(uint& _out_ row, uint& _out_ col)
{
	uint n = GetRand(1, GetEmptyNum());
	uint count = 0;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
		{
			if (game.grid[i][j] == 0)
				++count;
			if (count == n)
			{
				row = i;
				col = j;
				return;
			}
		}

}

//�ж��Ƿ����
bool IfEnd()
{
	//�Ƿ��п�λ
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			if (game.grid[i][j] == 0)
				return false;

	//�Ƿ�����ƶ�
	const Game gamemid{ game };
	const uint curscoremid{ game.CurScore };

	Left();
	if (game.CurScore != curscoremid)
		return false;
	game = gamemid;
	game.CurScore = curscoremid;
	Right();
	if (game.CurScore != curscoremid)
		return false;
	game = gamemid;
	game.CurScore = curscoremid;
	Up();
	if (game.CurScore != curscoremid)
		return false;
	game = gamemid;
	game.CurScore = curscoremid;
	Down();
	if (game.CurScore != curscoremid)
		return false;
	game = gamemid;
	game.CurScore = curscoremid;


	return true;
}

//������
bool ComputeGrid()
{
	int direction{ _getch() };

	switch (direction)
	{
	case (int)'a':
	case (int)'A':
		Left();
		break;
	case (int)'d':
	case (int)'D':
		Right();
		break;
	case (int)'w':
	case (int)'W':
		Up();
		break;
	case (int)'s':
	case (int)'S':
		Down();
		break;
	case (int)'r':
	case (int)'R':
		ReStart();
		break;
	case 27://ESC
		return Esc();
		break;
	default:
		ComputeGrid();
		break;
	}
	return !ESC;
}

//����
void Left()
{
	//�ϲ�
	for (int i = 0; i < 4; ++i)//ÿһ��
		for (int j = 0; j < 4; ++j)//��ʼ���
			if (game.grid[i][j] != 0)//��ʼԪ�ط���
				for (int k = j + 1; k < 4; ++k)
					if (game.grid[i][k] != 0 && game.grid[i][k] != game.grid[i][j])//4 2
						break;
					else if (game.grid[i][k] == 0)//4 0
						continue;
					else//4 4
					{
						Scored(game.grid[i][j]);
						game.grid[i][j] *= 2;
						game.grid[i][k] = 0;
					}
	//����
	for(int i = 0; i < 4; ++i)
	{
		//�Ĵ�
		block mid[4]{};
		int p{};
		for (int j = 0; j < 4; ++j)
			if (game.grid[i][j] != 0)
			{
				mid[p] = game.grid[i][j];
				++p;
			}

		//д��
		for (int j = 0; j < 4; ++j)
			game.grid[i][j] = mid[j];
	}
}


//������
void Exchange(block& x, block& y)
{
	block mid = x;
	x = y;
	y = mid;
}

//���ҷ�ת
void Mirror()
{
	for (int i = 0; i < 4; ++i)
	{
		Exchange(game.grid[i][0], game.grid[i][3]);
		Exchange(game.grid[i][1], game.grid[i][2]);
	}
}

//ת��
void Transpose()
{
	Exchange(game.grid[0][1], game.grid[1][0]);
	Exchange(game.grid[0][2], game.grid[2][0]);
	Exchange(game.grid[0][3], game.grid[3][0]);
	Exchange(game.grid[1][2], game.grid[2][1]);
	Exchange(game.grid[1][3], game.grid[3][1]);
	Exchange(game.grid[2][3], game.grid[3][2]);
}

//����
inline void Right()
{
	Mirror();
	Left();
	Mirror();
}

//����
inline void Up()
{
	Transpose();
	Left();
	Transpose();
}

//����
inline void Down()
{
	Transpose();
	Right();
	Transpose();
}

//���¿�ʼ
void ReStart()
{
	cout << "�Ƿ����¿�ʼ����Yȷ��" << endl;
	int tap{ _getch() };
	if (tap == (int)'Y' || tap == (int)'y')
		Gamef();
}
//�˳�
bool Esc()
{
	cout << "�Ƿ��˳������˵�����Yȷ��" << endl;
	int tap{ _getch() };
	if (tap == (int)'Y' || tap == (int)'y')
	{
		system("cls");
		return ESC;
	}
	else
		return !ESC;
}

//�÷�
inline void Scored(block x)
{
	game.CurScore += x * 2;
}

//��ȡ��߿�
block GetHighestBlock()
{
	block output{ game.grid[0][0] };
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			if (game.grid[i][j] > output)
				output = game.grid[i][j];
	return output;
}

//������
bool Step()
{
	CreateBlock();
	PrintGrid();
	if (IfEnd() == true)
		return ESC;
	if(ComputeGrid() == ESC)
		return ESC;

	return !ESC;
}

//��Ϸ����
inline void Gamef()
{
	InitGame();
	//��һ��
	CreateBlock();
	CreateBlock();
	PrintGrid();
	ComputeGrid();

	//������
	while (Step()) {}

	//����
	cout << "��Ϸ������" << endl;
	if (game.CurScore > statis.HighestScore)
	{
		cout << "�¼�¼����߷����Ѹ��£�" << game.CurScore << endl;
		statis.HighestScore = game.CurScore;
	}
	block CurHighestBlock = GetHighestBlock();
	statis.HighestBlock = CurHighestBlock > statis.HighestBlock ? CurHighestBlock : statis.HighestBlock;
	++statis.GameTime;
	statis.IfNew = false;
}