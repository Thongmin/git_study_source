#pragma once
#pragma warning(disable : 26451)
#include<iostream>
#include<string>
#include<time.h>
#include<Windows.h>
#include<stdlib.h>
#include<conio.h>
#include<list>

#define MAP_HEIGHT_30_PERCENT 0.3f
#define MAP_HEIGHT_40_PERCENT 0.4f
#define MAP_HEIGHT_50_PERCENT 0.5f
#define MAP_HEIGHT_60_PERCENT 0.6f
#define MAP_HEIGHT_70_PERCENT 0.7f
#define MULTI2(x) (x) * 2
#define HALF(x) x * 0.5f
#define BLOCK_DEFAULT_MAX_COUNT 30
#define HEART_DEFAULT_MAX_COUNT 10
#define NOTTING ' '
#define BIG_TO_SMALL 32

struct StructurePoint
{
	int ix;
	int iy;
};

enum Impact
{
	IMPACT_NOTTING,
	IMPACT_BLOCK,
	IMPACT_SNAKEBODY,
	IMPACT_HEART
};

enum Way
{
	WAY_NOTTING = ' ',
	WAY_UP = 'w',
	WAY_DOWN = 's',
	WAY_RIGHT = 'd',
	WAY_LEFT = 'a'
};

enum MAP_SIZE
{
	MAP_DEFAULT_SIZE_WIDTH = 50,
	MAP_DEFAULT_SIZE_HEIGHT = 30
};

enum GAME
{
	GAME_START = 1,
	GAME_EXIT
};

enum MOVE
{
	MOVE_UP = -1,
	MOVE_RIGHT = 2,
	MOVE_DOWN = 1,
	MOVE_LEFT = -2
};

enum SPEED
{
	SPEED_DEFAULT = 250,
	SPEED_PLUS = 10,
	SPEED_MAX = 50
};

enum TIME
{
	TIME_ONE_SECOND = 1000
};

enum MAP_LINE
{
	MAP_LINE_BLANK,
	MAP_LINE_SCORE,
	MAP_LINE_MAX
};

enum MAP_EDGE
{
	MAP_EDGE_UP,
	MAP_EDGE_LEFT = MAP_EDGE_UP,
	MAP_EDGE_DOWN,
	MAP_EDGE_RIGHT = MAP_EDGE_DOWN
};