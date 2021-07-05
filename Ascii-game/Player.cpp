#include "Player.hpp"
#include <conio.h>
#include <iostream>

using namespace std;

void Player::GetPosition(int &posX, int &posY)
{
	posX=x;
	posY=y;
}

void Player::Move(int posX, int posY)
{
	x=posX;
	y=posY;
}

void Player::Tick()
{

}

void Player::PrintStats()
{
	cout<<"\n\t"<<health<<" "<<char(03)<<"\t"<<coin<<" $";
}

void Player::setHealth(int setH)
{
	health += setH;
}

void Player::setCoin(int setC)
{
	coin += setC;
}

int Player::getHealth()
{
	return health;
}

int Player::getCoin()
{
	return coin;
}

