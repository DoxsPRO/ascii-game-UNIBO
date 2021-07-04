#include "Enemy.hpp"
#include <conio.h>
#include <iostream>

using namespace std;

void Enemy::GetPosition(int &posX, int &posY)
{
	posX=x;
	posY=y;
}

void Enemy::Move(int posX, int posY)
{
	x=posX;
	y=posY;
}

void Enemy::Tick()
{

}

void Enemy::setDifficulty(int setDiff)
{
	diffuculty = setDiff;
}

void Enemy::setHealth(int setH)
{
	health = setH;
}

double Enemy::getTotalDamage()
{
	return diffuculty * damage;
}



