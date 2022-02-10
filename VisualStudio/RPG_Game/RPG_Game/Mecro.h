#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <list>
#include <map>
#include <fstream>
#include<time.h>

using namespace std;

//////////////////////////////////////////////////////
#define col GetStdHandle(STD_OUTPUT_HANDLE) 
#define BLACK SetConsoleTextAttribute( col,0x0000 );
#define DARK_BLUE SetConsoleTextAttribute( col,0x0001 );
#define GREEN SetConsoleTextAttribute( col,0x0002 );
#define BLUE_GREEN SetConsoleTextAttribute( col,0x0003 );
#define BLOOD SetConsoleTextAttribute( col,0x0004 );
#define PUPPLE SetConsoleTextAttribute( col,0x0005 );
#define GOLD SetConsoleTextAttribute( col,0x0006 );			//색상 지정
#define ORIGINAL SetConsoleTextAttribute( col,0x0007 );
#define GRAY SetConsoleTextAttribute( col,0x0008 );
#define BLUE SetConsoleTextAttribute( col,0x0009 );
#define HIGH_GREEN SetConsoleTextAttribute( col,0x000a );
#define SKY_BLUE SetConsoleTextAttribute( col,0x000b );
#define RED SetConsoleTextAttribute( col,0x000c );
#define PLUM SetConsoleTextAttribute( col,0x000d );
#define YELLOW SetConsoleTextAttribute( col,0x000e );
//////////////////////////////////////////////////////

#define UP 'w'
#define DOWN 's'
#define ENTER '\r'
#define PERSENT_10 0.1f
#define PERSENT_20 0.2f
#define PERSENT_30 0.3f
#define PERSENT_40 0.4f
#define PERSENT_50 0.5f
#define PERSENT_60 0.6f
#define PERSENT_70 0.7f
#define PERSENT_80 0.8f
#define PERSENT_90 0.9f
#define HALF(x) (x) * 0.5f
#define TWO_TIMES(x) (x) * 2
#define MIN(a, b) (a < b) ? a : b
#define NEW_PLAY 0
#define WINDOW_MAX_BUF 256
#define DONGEON_MENU_EXIT 7
#define SAVE 0
#define LOAD 1
#define MAX_SHOP_COUNT 5
#define DEFAULT_SHOP_MENU_COUNT 3
#define WEAPON_BOW_MAX 5
#define WEAPON_DAGGER_MAX 6
#define WEAPON_GUN_MAX 4
#define WEAPON_SWORD_MAX 5
#define WEAPON_WAND_MAX 5
#define WEAPON_HAMMER_MAX 5
#define LEVEL_UP_STAT_MAX 4
#define ONE_SCISSORS 49
#define TWO_ROCK 50
#define THREE_PAPER 51

enum Map
{
	MAP_SURPLUS_LINE = 1,
	MAP_WIDTH_SIZE = 30,
	MAP_HEIGHT_SIZE = 34
};

enum Line_Length
{
	LINE_LENGTH_1 = 1,
	LINE_LENGTH_2,
	LINE_LENGTH_3,
	LINE_LENGTH_4,
	LINE_LENGTH_5,
	LINE_LENGTH_6,
	LINE_LENGTH_7,
	LINE_LENGTH_8,
	LINE_LENGTH_9,
	LINE_LENGTH_10,
	LINE_LENGTH_11,
	LINE_LENGTH_12,
	LINE_LENGTH_13,
	LINE_LENGTH_14
};

enum Main_Menu
{
	MAIN_MENU_NEW_GAME = 1,
	MAIN_MENU_LOAD_GAME,
	MAIN_MENU_EXIT_GAME
};

enum Play_Menu
{
	PLAY_MENU_DONGEON = 1,
	PLAY_MENU_PLAYER_INFO,
	PLAY_MENU_MONSTER_INFO,
	PLAY_MENU_WEAPON_SHOP,
	PLAY_MENU_SAVE,
	PLAY_MENU_EXIT
};

enum Menu_Count
{
	MENU_COUNT_MAIN = 3,
	MENU_COUNT_GAME = 6,
	MENU_COUNT_DONGEON,
	MENU_COUNT_WEAPON_SHOP = MENU_COUNT_DONGEON,
	MENU_COUNT_LOAD = 11,
	MENU_COUNT_SAVE = MENU_COUNT_LOAD
};

enum File
{
	FILE_1 = 1,
	FILE_2,
	FILE_3,
	FILE_4,
	FILE_5,
	FILE_6,
	FILE_7,
	FILE_8,
	FILE_9,
	FILE_10,
	FILE_EXIT
};

enum Monster_Name
{
	MONSTER_NAME_GOBLIN,
	MONSTER_NAME_ORC,
	MONSTER_NAME_WEREWOLF,
	MONSTER_NAME_OGRE,
	MONSTER_NAME_SKELETON_ARCHER,
	MONSTER_NAME_LICH,
	MONSTER_NAME_MAX_COUNT
};

enum Weapon_Type
{
	WEAPON_TYPE_DAGGER = 1,
	WEAPON_TYPE_GUN,
	WEAPON_TYPE_SWORD,
	WEAPON_TYPE_WAND,
	WEAPON_TYPE_BOW,
	WEAPON_TYPE_HAMMER,
	WEAPON_TYPE_MAX_COUNT = WEAPON_TYPE_HAMMER,
	WEAPON_SHOP_EXIT
};

enum Weapon_Menu
{
	WEAPON_MENU_BEFORE = 1,
	WEAPON_MENU_AFTER,
	WEAPON_MENU_EXIT,
	WEAPON_MENU_LIST_MAX = 8
};

enum Attack
{
	ATTACK_SCISSORS = 1,
	ATTACK_ROCK,
	ATTACK_PAPER
};

enum Result
{
	RESULT_DRAW,
	RESULT_WIN,
	RESULT_LOSE
};


