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
	cout<<health<<" "<<char(03)<<"  "<<coin<<" $";	
	cout<<endl;
}

void Player::setHealth(int setH)
{
	health = setH;
}

void Player::setCoin(int setC)
{
	coin += setC;
}



