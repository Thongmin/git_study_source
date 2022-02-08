#pragma once
#pragma warning(disable: 26451)
#pragma warning(disable: 4838)
#pragma warning(disable: 4244)

#include<iostream>
#include<string>
#include<conio.h>
#include<iomanip>
#include<Windows.h>
#include<list>
#include<fstream>

using namespace std;

#define CURRENT_PLAYER_STONE 1
#define OTHER_PLAYER_STONE 2
#define MAP 3
#define LOWER 32
#define ESC 27
#define ENTER 13
#define OPTION 'p'
#define UNDO 'n'
#define UP 'w'
#define LEFT 'a'
#define DOWN 's'
#define RIGHT 'd'
#define X_AXIS 2
#define Y_AXIS 1
#define DOUBLE 2
#define THREE_SPACES 3
#define LEFT_INPUTBOX_SIZE 0.3
#define RIGHT_INPUTBOX_SIZE 0.5
#define HALF 2
#define UNDO_DEFAULT 5
#define WIN_COUNT_MAX 5
#define INFO_DISPLAY_SIZE 6
#define WIDTH_MIN 20
#define WIDTH_MAX 90
#define HEIGHT_MIN 20
#define HEIGHT_MAX 45
#define UNDO_COUNT_MAX 10
#define NEXT_LINE 1
#define FIRST_LINE 1
#define SECOND_LINE 2
#define THIRD_LINE 3
#define FOURTH_LINE 4
#define FIFTH_LINE 5
#define BOOL_COUNT 2
#define TWENTY_PERCENT_HEIGHT 0.2
#define THIRTY_PERCENT_HEIGHT 0.3
#define FORTY_PERCENT_HEIGHT 0.4
#define FIFTY_PERCENT_HEIGHT 0.5
#define SIXTY_PERCENT_HEIGHT 0.6
#define SEVENTY_PERCENT_HEIGHT 0.7
#define EIGHTY_PERCENT_HEIGHT 0.8
#define NINETY_PERCENT_HEIGHT 0.9
#define YES 1
#define NO 2
#define NO_DATA 0
#define HAVE_DATA 1
#define TRASH_DATA -1


enum Main_Menu
{
	MAIN_MENU_PLAY = 1,
	MAIN_MENU_OPTION,
	MAIN_MENU_REPLAY,
	MAIN_MENU_EXIT
};

enum Option_Menu
{
	OPTION_MENU_MAP_SIZE_SETTING = 1,
	OPTION_MENU_CURSOR_FORM_SETTING,
	OPTION_MENU_STONE_FORM_SETTING,
	OPTION_MENU_UNDO_SETTING,
	OPTION_MENU_RETURN
};

enum Cursor_Custom_Menu
{
	CURSOR_CUSTOM_MENU_CIRCLE_FORM = 1,
	CURSOR_CUSTOM_MENU_HEART_FORM,
	CURSOR_CUSTOM_MENU_FINGER_FORM,
	CURSOR_CUSTOM_MENU_NUMBER_FORM,
	CURSOR_CUSTOM_MENU_RETURN
};

enum Stone_Custom_Menu
{
	STONE_CUSTOM_MENU_CIRCLE_FORM = 1,
	STONE_CUSTOM_MENU_HEART_FORM,
	STONE_CUSTOM_MENU_FINGER_FORM,
	STONE_CUSTOM_MENU_NUMBER_FORM,
	STONE_CUSTOM_MENU_RETURN
};

enum Undo_Menu
{
	UNDO_MENU_COUNT_SETTING = 1,
	UNDO_MENU_OFF,
	UNDO_MENU_RETURN
};