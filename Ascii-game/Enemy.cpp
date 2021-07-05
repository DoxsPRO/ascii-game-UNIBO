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
			enemies[i].still--;
			if(map[enemies[i].x-1][enemies[i].y]=='-')//damage
			{
				enemies[i].health-=50;
				map[enemies[i].x-1][enemies[i].y]=' ';
				
			}
			if(enemies[i].health<=0)
			{
				map[enemies[i].x][enemies[i].y]=' ';
				enemies[i].alive=false;
				
				continue;
			}
			
			if(map[enemies[i].x][enemies[i].y+1]==' ')
			{
				map[enemies[i].x][enemies[i].y]=' ';
				enemies[i].y++;
				map[enemies[i].x][enemies[i].y]=enemies[i].ascii;
			}			
			else if(enemies[i].still<=0)
			{
				if(map[enemies[i].x+enemies[i].d][enemies[i].y]==' ' && (enemies[i].x+enemies[i].d<95) && (enemies[i].x+enemies[i].d>0))
				{
					enemies[i].still=5;
					map[enemies[i].x][enemies[i].y]=' ';
					enemies[i].x+=enemies[i].d;
					map[enemies[i].x][enemies[i].y]=enemies[i].ascii;	
				}
				else
					enemies[i].d*=-1;
			}
			
			
			
			
			
		}
	}
	return map;
}



