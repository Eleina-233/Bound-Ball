#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>
int i, j, x, y, velocity_x, velocity_y, left, right, top, bottom,
position_x, position_y, r, score, target_x, target_y;



void init();
void show();
void WithOutInput();
void gotoxy(int x, int y);
void WithInput();
