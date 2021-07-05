#include "Bullet.hpp"
#include <iostream>
using namespace std;

char **Bullet::Tick(char **map)
{
	return map;
}

void Bullet::SpawnBullet(int x, int y, int d)
{
	
}

void Bullet::Delete()
{
	
}

void Bullet::Clear()
{
	for(int i=0; i<count ; i++)
	{
		bullets[i].active=false;
	}
	
	count=0;
}
