#include "Head.h"
#include "GlobalValue.h"

//#define DEBUG

#ifdef DEBUG
void GridOut();
void SetGrid();
#endif

int main()
{
	//调试区

	



	///////////////////////////////////////

	//链接存档
	if (!save)
		CreateSave();
	else
		OpenSave();
	SaveOut();

	//游戏初始化
	if (statis.IfNew == true)
	{
		InitStatis();
		cout << "游戏初始化成功！" << endl;
		cout << "输入\"help\"查看帮助" << endl << endl;
	}
	else
		cout << "欢迎回来！" << statis.name << endl << endl;

	//主逻辑
	while(true)
	{
		BOOL com = RunCom();
		if (com == COM_ERROR)
			while (RunCom() == COM_ERROR) {}
		else if (com == COM_START)
			Gamef();
		else if (com == COM_EXIT)
			break;
	}

	//退出游戏
	SaveIn();
	CloseSave();
}

//伪代码
/*
	检测是否新进入
		是：初始化数据

		执行指令

	进入游戏：
		Gamef()
*/
/*Game()
	初始化游戏结构体

	Step()
	{
		生成block
		判断是否结束
		运算表格
		更新表格
	}

*/

#ifdef DEBUG

void SetGrid()
{
	game.grid[0][0] = 1;
	game.grid[0][1] = 2;
	game.grid[0][2] = 3;
	game.grid[0][3] = 4;
	game.grid[1][0] = 5;
	game.grid[1][1] = 6;
	game.grid[1][2] = 7;
	game.grid[1][3] = 8;
	game.grid[2][0] = 9;
	game.grid[2][1] = 10;
	game.grid[2][2] = 11;
	game.grid[2][3] = 12;
	game.grid[3][0] = 13;
	game.grid[3][1] = 14;
	game.grid[3][2] = 15;
	game.grid[3][3] = 16;
}
void GridOut()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
			cout << game.grid[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}
#endif