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
	stats[4]=03;
	for(int i=0; i<100; i++)
		cout<<stats[i];
		
	cout<<endl;
}

void Player::setHealth(int setHealth)
{
	health = setHealth;
	updateStats();
}

void Player::setCoin(int setCoin)
{
	coin = setCoin;
	updateStats();
}



