#include "Enemy.hpp"
#include <conio.h>
#include <iostream>

using namespace std;

void Enemy::ScanEnemy(char **map)
{
	count=0;
	
	for(int i=0;i<16;i++)
	{
		for(int j=0;j<96;j++)
		{
			if(map[j][i] == '@')
			{
				enemies[count].id = count;
				enemies[count].x = j;
				enemies[count].y = i;
				enemies[count].alive = true;
				count++;
			}
		}
	}
}


int Enemy::EnemyAt(int x, int y)
{
	
}

void Enemy::Clear()
{
	
}

char **Enemy::Tick(char **map)
{
	for(int i=0; i<count; i++)
	{
		if(enemies[i].alive)
	}
	return map;
}



