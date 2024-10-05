#include "Head.h"
#include "GlobalValue.h"

BOOL RunCom()
{
	cout << "������ָ�";
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
		cout << "��Чָ�" << endl;
		return COM_ERROR;
	}
}

BOOL HelpCom()
{
	cout << "ָ��˵����" << endl;
	cout << "cls			����" << endl;
	cout << "help			����" << endl;
	cout << "start			��ʼ��Ϸ" << endl;
	cout << "exit			�˳�������" << endl;
	cout << "save			�浵" << endl;
	cout << "load			����" << endl;
	cout << "delete			����浵" << endl;
	cout << "statis			ͳ������" << endl;
	cout << "name			�����ǳ�" << endl;
	cout << "size			���ô�С" << endl;
	cout << endl;
	cout << "����˵����" << endl;
	cout << "ʹAWSD���в���" << endl;
	cout << "��Esc�˳������˵�" << endl;
	cout << "��R���¿�ʼ��Ϸ" << endl;
	cout << endl;
	return COM_HELP;
}

BOOL ExitCom()
{
	cout << "�Ƿ��˳������棿��Yȷ��" << endl;
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
	cout << "�ǳ�				" << statis.name << endl;
	cout << "�ߴ�				" << statis.size << endl;
	cout << "��߷���			" << statis.HighestScore << endl;
	cout << "��߿�				" << statis.HighestBlock << endl;
	cout << "��Ϸ����			" << statis.GameTime << endl;
	cout << endl;
	return COM_STATIS;
}

BOOL NameChangeCom()
{
	cout << "���������ǳƣ�";
	cin >> statis.name;
	cout << "���óɹ��������ǳƽ���ʾΪ��" << statis.name << endl;
	return COM_NAME;
}

BOOL SetSizeCom()
{
	cout << "�������³ߴ磨Ĭ��Ϊ" << DEFAULT_SIZE << "����";
	cin >> statis.size;
	cout << "���óɹ���Ŀǰ�ߴ�Ϊ" << statis.size << endl;
	return COM_SIZE;
}