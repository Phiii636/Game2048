#include "Head.h"
#include "GlobalValue.h"

//#define DEBUG

#ifdef DEBUG
void GridOut();
void SetGrid();
#endif

int main()
{
	//������

	



	///////////////////////////////////////

	//���Ӵ浵
	if (!save)
		CreateSave();
	else
		OpenSave();
	SaveOut();

	//��Ϸ��ʼ��
	if (statis.IfNew == true)
	{
		InitStatis();
		cout << "��Ϸ��ʼ���ɹ���" << endl;
		cout << "����\"help\"�鿴����" << endl << endl;
	}
	else
		cout << "��ӭ������" << statis.name << endl << endl;

	//���߼�
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

	//�˳���Ϸ
	SaveIn();
	CloseSave();
}

//α����
/*
	����Ƿ��½���
		�ǣ���ʼ������

		ִ��ָ��

	������Ϸ��
		Gamef()
*/
/*Game()
	��ʼ����Ϸ�ṹ��

	Step()
	{
		����block
		�ж��Ƿ����
		������
		���±��
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