#include "Head.h"
#include "GlobalValue.h"

Game game{};
Statis statis{};

//初始化
//Game结构体初始化
void InitGame()
{
	game.CurScore = 0;
	game.IfStarted = false;
	game.CurTime = 0;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			game.grid[i][j] = 0;
}
//Statis结构体初始化
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

//生成块
void CreateBlock()
{
	//获取新块大小
	//0.2的概率为4，0.8为2
	block BlockNum{ (GetRand(1, 5) == 5) ? (block)4 : (block)2 };

	//获取新块位置
	uint row{}, col{};
	GetEmptyAddress(row, col);

	//写入
	game.grid[row][col] = BlockNum;
}
//获取随机数
uint GetRand(uint bot, uint top)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distrib(bot, top);
	return distrib(gen);
}
//获取空位数
uint GetEmptyNum()
{
	uint count{};
	for(int i = 0;i<4;++i)
		for (int j = 0; j < 4; ++j)
			if (game.grid[i][j] == 0)
				++count;
	return count;
}
//获取空位地址
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

//判断是否结束
bool IfEnd()
{
	//是否有空位
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			if (game.grid[i][j] == 0)
				return false;

	//是否可以移动
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

//运算表格
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

//向左
void Left()
{
	//合并
	for (int i = 0; i < 4; ++i)//每一行
		for (int j = 0; j < 4; ++j)//起始检查
			if (game.grid[i][j] != 0)//起始元素非零
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
	//对齐
	for(int i = 0; i < 4; ++i)
	{
		//寄存
		block mid[4]{};
		int p{};
		for (int j = 0; j < 4; ++j)
			if (game.grid[i][j] != 0)
			{
				mid[p] = game.grid[i][j];
				++p;
			}

		//写入
		for (int j = 0; j < 4; ++j)
			game.grid[i][j] = mid[j];
	}
}


//交换块
void Exchange(block& x, block& y)
{
	block mid = x;
	x = y;
	y = mid;
}

//左右翻转
void Mirror()
{
	for (int i = 0; i < 4; ++i)
	{
		Exchange(game.grid[i][0], game.grid[i][3]);
		Exchange(game.grid[i][1], game.grid[i][2]);
	}
}

//转置
void Transpose()
{
	Exchange(game.grid[0][1], game.grid[1][0]);
	Exchange(game.grid[0][2], game.grid[2][0]);
	Exchange(game.grid[0][3], game.grid[3][0]);
	Exchange(game.grid[1][2], game.grid[2][1]);
	Exchange(game.grid[1][3], game.grid[3][1]);
	Exchange(game.grid[2][3], game.grid[3][2]);
}

//向右
inline void Right()
{
	Mirror();
	Left();
	Mirror();
}

//向上
inline void Up()
{
	Transpose();
	Left();
	Transpose();
}

//向下
inline void Down()
{
	Transpose();
	Right();
	Transpose();
}

//重新开始
void ReStart()
{
	cout << "是否重新开始？按Y确认" << endl;
	int tap{ _getch() };
	if (tap == (int)'Y' || tap == (int)'y')
		Gamef();
}
//退出
bool Esc()
{
	cout << "是否退出至主菜单？按Y确认" << endl;
	int tap{ _getch() };
	if (tap == (int)'Y' || tap == (int)'y')
	{
		system("cls");
		return ESC;
	}
	else
		return !ESC;
}

//得分
inline void Scored(block x)
{
	game.CurScore += x * 2;
}

//获取最高块
block GetHighestBlock()
{
	block output{ game.grid[0][0] };
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			if (game.grid[i][j] > output)
				output = game.grid[i][j];
	return output;
}

//步函数
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

//游戏函数
inline void Gamef()
{
	InitGame();
	//第一步
	CreateBlock();
	CreateBlock();
	PrintGrid();
	ComputeGrid();

	//其他步
	while (Step()) {}

	//结束
	cout << "游戏结束！" << endl;
	if (game.CurScore > statis.HighestScore)
	{
		cout << "新纪录！最高分数已更新：" << game.CurScore << endl;
		statis.HighestScore = game.CurScore;
	}
	block CurHighestBlock = GetHighestBlock();
	statis.HighestBlock = CurHighestBlock > statis.HighestBlock ? CurHighestBlock : statis.HighestBlock;
	++statis.GameTime;
	statis.IfNew = false;
}