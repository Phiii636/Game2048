#include "Head.h"
#include "GlobalValue.h"

BOOL RunCom()
{
	cout << "请输入指令：";
	string command{};
	cin >> command;

	if (command == "cls")
	{
		system("cls");
		return COM_CLS;
	}
	else if (command == "help")
		return HelpCom();
	else if (command == "start")
		return COM_START;
	else if (command == "exit")
		return ExitCom();
	else if (command == "save")
		return SaveCom();
	else if (command == "load")
		return LoadCom();
	else if (command == "delete")
		return DeleteCom();
	else if (command == "statis")
		return PrintStatisCom();
	else if (command == "name")
		return NameChangeCom();
	else if (command == "size")
		return SetSizeCom();
	else
	{
		cout << "无效指令！" << endl;
		return COM_ERROR;
	}
}

BOOL HelpCom()
{
	cout << "指令说明：" << endl;
	cout << "cls			清屏" << endl;
	cout << "help			帮助" << endl;
	cout << "start			开始游戏" << endl;
	cout << "exit			退出至桌面" << endl;
	cout << "save			存档" << endl;
	cout << "load			读档" << endl;
	cout << "delete			清除存档" << endl;
	cout << "statis			统计数据" << endl;
	cout << "name			更改昵称" << endl;
	cout << "size			设置大小" << endl;
	cout << endl;
	cout << "操作说明：" << endl;
	cout << "使AWSD进行操作" << endl;
	cout << "按Esc退出至主菜单" << endl;
	cout << "按R重新开始游戏" << endl;
	cout << endl;
	return COM_HELP;
}

BOOL ExitCom()
{
	cout << "是否退出至桌面？按Y确认" << endl;
	int tap{ _getch() };
	if (tap == (int)'Y' || tap == (int)'y')
		return COM_EXIT;
	else
		return COM_CANCEL;
}

inline BOOL SaveCom()
{
	SaveIn();
	return COM_SAVE;
}

inline BOOL LoadCom()
{
	SaveOut();
	return COM_LOAD;
}

inline BOOL DeleteCom()
{
	SaveRe();
	return COM_DELETE;
}

BOOL PrintStatisCom()
{
	cout << "昵称				" << statis.name << endl;
	cout << "尺寸				" << statis.size << endl;
	cout << "最高分数			" << statis.HighestScore << endl;
	cout << "最高块				" << statis.HighestBlock << endl;
	cout << "游戏局数			" << statis.GameTime << endl;
	cout << endl;
	return COM_STATIS;
}

BOOL NameChangeCom()
{
	cout << "请输入新昵称：";
	cin >> statis.name;
	cout << "设置成功！您的昵称将显示为：" << statis.name << endl;
	return COM_NAME;
}

BOOL SetSizeCom()
{
	cout << "请输入新尺寸（默认为" << DEFAULT_SIZE << "）：";
	cin >> statis.size;
	cout << "设置成功！目前尺寸为" << statis.size << endl;
	return COM_SIZE;
}