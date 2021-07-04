#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Player.hpp"
#include "World.hpp"
using namespace std;


Player p;
World w;
int posX, posY;
int jumping=0;

void Setup()
{
	CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    
    w.Init();
	
}

void Gravity()
{
	p.GetPosition(posX, posY);
		
		if(w.BlockAt(posX, posY+1)==32 && jumping<=0)
		{
			w.SetBlock(' ', posX, posY);
			posY++;
			p.Move(posX, posY);
			jumping++;
		}
		else if(jumping>0)
		{
			if(jumping>12 && w.BlockAt(posX, posY-1)==32)
			{
				w.SetBlock(' ', posX, posY);
				posY--;
				p.Move(posX, posY);
			}
			jumping--;
		}
}

void Movement()
{
	if (_kbhit())
	{
		int key = _getch();
		
		//LEFT
		if (key == 97 || key == 75)
		{
			if(posX>0 && w.BlockAt(posX-1, posY)==' ')
			{
				w.SetBlock(' ', posX, posY);
				posX--;
				p.Move(posX, posY);
			}
			else if(posX==0)
			{
				w.SetBlock(' ', posX, posY);
				if(w.PreviousSection())
				{
					posX=95;
					p.Move(posX, posY);
				}
				else
					w.SetBlock('P', posX, posY);
		
				
			}
		}

		//RIGHT
		if (key == 100 || key == 77)
		{
			if(posX<w.maxX-1 && w.BlockAt(posX+1, posY)==' ')
			{
				w.SetBlock(' ', posX, posY);
				posX++;
				p.Move(posX, posY);
			}
			else if(posX==95)
			{
				w.SetBlock(' ', posX, posY);
				w.NextSection();
				posX=0;
				p.Move(posX, posY);
			}
		}

		//JUMP
		if ((key == 119 || key == 72)&& jumping<=0)
		{
			if(w.BlockAt(posX, posY+1)!=32)
				jumping=15;
		}
		
		//FIRE
		if (key == 320)
		{	
			w.SetBlock('-',posX+1,posY);
		}
		
		//SPAWN ENEMY
		if(key == 112)
		{
			
		}			
		cout<<key<<endl;
	}
}

int main(int argc, char** argv) {	
	
	Setup();
	while(true)
	{
		Gravity();
		Movement();
		//collisions
	
		w.SetBlock('P', posX, posY);
		w.Print();
		p.PrintStats();
		cout<<posX<<" "<<posY<<endl;
		
		
		
		//system("pause");	
	}
	
	system("pause");
	return 0;
}
