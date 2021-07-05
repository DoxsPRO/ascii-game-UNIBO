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
		{
			if(map[enemies[i].x-1][enemies[i].y] == '-')
			{
				enemies[i].health -= 10;
				
				if(enemies[i].health <= 0)
				{
					enemies[i].alive = false;
				}
			}
			else if(map[enemies[i].x-1][enemies[i].y] == '=')
			{
				if(map[enemies[i].x+1][enemies[i].y] != '=' && map[enemies[i].x+1][enemies[i].y] != '$' && map[enemies[i].x+1][enemies[i].y] != '@')
				{
					if(enemies[i].x<95)
						enemies[i].x++;
					//aggiungere alternativa
				}		
			}
			else if(map[enemies[i].x-1][enemies[i].y] == '$')
			{
				if(enemies[i].x>=2 && map[enemies[i].x-2][enemies[i].y] != '=' && map[enemies[i].x-2][enemies[i].y] != '$' && map[enemies[i].x-2][enemies[i].y] != '@')
					enemies[i].x -= 2;
				else if(map[enemies[i].x+1][enemies[i].y] != '=' && map[enemies[i].x+1][enemies[i].y] != '$' && map[enemies[i].x+1][enemies[i].y] != '@')
				{
					if(enemies[i].x<95)
						enemies[i].x++;
					//aggiungere alternativa
				}
			}
		}
	}
	return map;
}



