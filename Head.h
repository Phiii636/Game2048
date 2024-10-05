#pragma once
#include<iostream>
#include<conio.h>
#include<string>
#include<time.h>
#include<fstream>
#include<random>
using namespace std;

typedef unsigned uint;
typedef uint block;
typedef int BOOL;
struct Game
{
	uint CurScore;
	block grid[4][4];
	bool IfStarted;
	uint CurTime;
};
struct Statis
{
	bool IfNew;
	string name;
	uint size;
	uint HighestScore;
	uint HighestBlock;
	uint TotalTime;//游戏时长
	uint GameTime;//游戏局数
};

//GameLogic.h
#define _out_
#define ESC false

void InitGame();
void InitStatis();

void CreateBlock();
uint GetRand(uint bot, uint top);
uint GetEmptyNum();
void GetEmptyAddress(uint& _out_ row, uint& _out_ col);

bool IfEnd();

bool ComputeGrid();
void Left();
void Exchange(block& x, block& y);
void Right();
void Transpose();
void Up();
void Down(); 
void ReStart();
bool Esc();

void Scored(block x);

bool Step();
void Gamef();

//PrintScr.h
#define DEFAULT_SIZE 4

void PrintGrid();
void PrintLoop(string str, int time);
void PrintLoop(char letter, int time);
int GetDigit(block x);
int GetSpaceLeft(block x);
int GetSpaceRight(block x);

//Command.h
#define COM_CLS 9
#define COM_HELP 1
#define COM_START 2
#define COM_EXIT 3
#define COM_SAVE 4
#define COM_LOAD 5
#define COM_DELETE 6
#define COM_STATIS 7
#define COM_NAME 8
#define COM_SIZE 10
#define COM_CANCEL 0
#define COM_ERROR -1

BOOL RunCom();

BOOL HelpCom();
BOOL ExitCom();
BOOL SaveCom();
BOOL LoadCom();
BOOL DeleteCom();
BOOL PrintStatisCom();
BOOL NameChangeCom();
BOOL SetSizeCom();

//SaveLoad.h
#define DEFAULT_PATH "D:/save2048.sav"
#define STR_DELTA ('1' - 1)

void CreateSave();
void OpenSave();
void CloseSave();
uint mi10(uint n);
uint StrToUint(string str);
void SaveOut();
void SaveIn();
void SaveRe();