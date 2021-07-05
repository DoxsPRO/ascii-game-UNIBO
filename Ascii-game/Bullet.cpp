#include "Bullet.hpp"
#include <iostream>
using namespace std;

char **Bullet::Tick(char **map)
{
	for(int i=0; i<count; i++)
	{
		if(bullets[i].active && bullets[i].time<=0)
		{
			bullets[i].active=false;
			map[bullets[i].x][bullets[i].y]=' ';
		}
		
		if(bullets[i].active && bullets[i].x<95 && map[bullets[i].x+bullets[i].d][bullets[i].y]==' ')
		{
			map[bullets[i].x][bullets[i].y]=' ';
			bullets[i].x+=bullets[i].d;
			map[bullets[i].x][bullets[i].y]='-';
		}
		else if(bullets[i].active && bullets[i].x>=95 || map[bullets[i].x+bullets[i].d][bullets[i].y]=='=')
		{
			map[bullets[i].x][bullets[i].y]=' ';
			bullets[i].active=false;
		}
		else if(bullets[i].active && map[bullets[i].x+bullets[i].d][bullets[i].y]=='$')
		{
			map[bullets[i].x][bullets[i].y]=' ';
			bullets[i].x+=bullets[i].d*2;
			map[bullets[i].x][bullets[i].y]='-';
		}
		
		bullets[i].time--;
			
	}
	
	
	
	
	return map;
}

void Bullet::SpawnBullet(int x, int y, int d)
{
	bullets[count].active=true;
	bullets[count].x=x+d;
	bullets[count].y=y;
	bullets[count].d=d;
	bullets[count].id=count;
	bullets[count].time=15;
	
	count++;
}

char **Bullet::Delete(char **map)
{
	for(int i=0; i<count; i++)
	{
		if(bullets[i].active)
		{
			bullets[i].active=false;
			map[bullets[i].x][bullets[i].y]=' ';
		}
	}
	
	return map;
}
