#include "Head.h"
#include "GlobalValue.h"

fstream save(DEFAULT_PATH);

//�����浵
void CreateSave()
{
	ofstream crefile(DEFAULT_PATH);
	crefile.close();
	save.open(DEFAULT_PATH, ios::in | ios::out);
	SaveRe();
}

//�򿪴浵
void OpenSave()
{
	save.close();
	save.open(DEFAULT_PATH, ios::in | ios::out);
}

//�رմ浵
void CloseSave()
{
	save.close();
}

//10��
uint mi10(uint n)
{
	uint output{ 1 };
	if (n == 0)
		return 1;
	for (uint i = 1; i <= n; ++i)
		output *= 10;
	return output;
}

//stringתuint
uint StrToUint(string str)
{
	uint num{};
	for (uint i = 0; i < str.length(); ++i)
		num += (str.at(i) - STR_DELTA) * mi10((uint)str.length() - i - 1);
	return num;
}

//����
void SaveOut()
{
	//��ȡΪ�ı�
	string mid;
	string lines[7];
	for (uint i = 0; getline(save, mid); ++i)
		lines[i] = mid;

	statis.IfNew = (bool)StrToUint(lines[0]);
	statis.name = lines[1];
	statis.size = StrToUint(lines[2]);
	statis.HighestScore = StrToUint(lines[3]);
	statis.HighestBlock = StrToUint(lines[4]);
	statis.TotalTime = StrToUint(lines[5]);
	statis.GameTime = StrToUint(lines[6]);
}

//�浵
void SaveIn()
{
	save.close();
	save.open(DEFAULT_PATH, ios::trunc | ios::in | ios::out);

	save << statis.IfNew << "\n";
	save << statis.name << "\n";
	save << statis.size << "\n";
	save << statis.HighestScore << "\n";
	save << statis.HighestBlock << "\n";
	save << statis.TotalTime << "\n";
	save << statis.GameTime;

}

//���ô浵
void SaveRe()
{
	save.close();
	save.open(DEFAULT_PATH, ios::trunc | ios::in | ios::out);

	save << true << "\n";
	save << "Player" << "\n";
	save << 0 << "\n";
	save << 0 << "\n";
	save << 0 << "\n";
	save << 0 << "\n";
	save << 0;

	save.close();
	save.open(DEFAULT_PATH, ios::in | ios::out);
}