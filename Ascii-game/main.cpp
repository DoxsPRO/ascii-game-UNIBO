#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Player.hpp"
#include "World.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"
using namespace std;


Player p;
World w;
Enemy en;
Bullet bt;
int posX, posY;
int jumping=0, firing=0;
int diff=1;

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
		else if(w.BlockAt(posX, posY+1)=='$' && jumping<=0)
		{
			w.SetBlock(' ', posX, posY);
			w.SetBlock(' ', posX, posY+1);
			posX++;
			p.Move(posX, posY);
			p.setCoin(1);
			jumping++;
		}
		else if(w.BlockAt(posX, posY+1)=='@' && jumping<=0)
		{
			w.SetBlock(' ', posX, posY);
			posY -= 2;
			p.Move(posX, posY);
			p.setHealth(-1*diff);
			jumping++;
		}
		else if(w.BlockAt(posX, posY+1)==03 && jumping<=0)
		{
			w.SetBlock(' ', posX, posY);
			w.SetBlock(' ', posX, posY+1);
			posX++;
			p.Move(posX, posY);
			p.setHealth(5);
			jumping++;;
		}
		else if(w.BlockAt(posX, posY+1)==05 && jumping<=0)
		{
			w.SetBlock(' ', posX, posY);
			w.SetBlock(' ', posX, posY+1);
			posX++;
			p.Move(posX, posY);
			en.SetDamage(4);
			jumping++;;
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
					w.Copy(bt.Delete(w.GetMap()));
					en.ScanEnemy(w.GetMap());
					posX=95;
					p.Move(posX, posY);
					diff--;
				}
				else
					w.SetBlock('P', posX, posY);	
			}
			else if(w.BlockAt(posX-1, posY)=='$')
			{
				w.SetBlock(' ', posX, posY);
				posX--;
				w.SetBlock(' ', posX, posY); //cancello dollaro
				p.Move(posX, posY);
				p.setCoin(1);
			}
			else if(w.BlockAt(posX-1, posY)==03)
			{
				w.SetBlock(' ', posX, posY);
				posX--;
				w.SetBlock(' ', posX, posY); //cancello cuore
				p.Move(posX, posY);
				p.setHealth(5);
			}
			else if(w.BlockAt(posX-1, posY)==05)
			{
				w.SetBlock(' ', posX, posY);
				posX--;
				w.SetBlock(' ', posX, posY); //cancello pow
				p.Move(posX, posY);
				en.SetDamage(4);
			}
			else if(w.BlockAt(posX-1, posY)=='@')
			{
				w.SetBlock(' ', posX, posY);
				posX += 2;
				p.Move(posX, posY);
				p.setHealth(-1*diff);
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
				w.Copy(bt.Delete(w.GetMap()));
				w.SetBlock(' ', posX, posY);
				w.NextSection();
				en.ScanEnemy(w.GetMap());
				posX=0;
				p.Move(posX, posY);
				diff++;
			}
			else if(w.BlockAt(posX+1, posY)=='$')
			{
				w.SetBlock(' ', posX, posY);
				w.SetBlock(' ', posX+1, posY);
				posX++;
				p.Move(posX, posY);
				p.setCoin(1);
			}
			else if(w.BlockAt(posX+1, posY)==03)
			{
				w.SetBlock(' ', posX, posY);
				posX++;
				w.SetBlock(' ', posX, posY); //cancello cuore
				p.Move(posX, posY);
				p.setHealth(5);
			}
			else if(w.BlockAt(posX+1, posY)==05)
			{
				w.SetBlock(' ', posX, posY);
				posX++;
				w.SetBlock(' ', posX, posY); //cancello pow
				p.Move(posX, posY);
				en.SetDamage(4);
			}
			else if(w.BlockAt(posX+1, posY)=='@')
			{
				w.SetBlock(' ', posX, posY);
				posX -= 2;
				p.Move(posX, posY);
				p.setHealth(-1*diff);
			}
		}

		//JUMP
		if ((key == 119 || key == 72)&& jumping<=0)
		{
			if(w.BlockAt(posX, posY+1)!=32)
				jumping=15;
		}
		
		//FIRE
		if (key == 32)
		{
			if(firing<=0 && posX<94)
			{
				bt.SpawnBullet(posX, posY, 1);
				firing=5;
			}			
		}
		
		
		cout<<key<<endl;		
	}
				
		
	
}

void CheckLeverClear()
{
	if(en.numEnemy == 0)
	{
		p.setCoin(5);
		en.numEnemy = -1;
	}
		
}

void Tick()
{
	Gravity();
	firing--;
	Movement();
	CheckLeverClear();
	en.SetDamage(-0.05);
	
	char **map=w.GetMap();
	map=en.Tick(map);
	map=bt.Tick(map);
	
	w.Copy(map);
}

void endGame()
{
	cout<<"                                                                                                "<<endl;
	cout<<"                                                                                                "<<endl;
	cout<<"          OOOOOO   OOOOOO   OO   OO   OOOOOO         OOOOOO   O       O   OOOOOO   OOOOO        "<<endl;
	cout<<"          O        O    O   O O O O   O              O    O    O     O    O        O   O        "<<endl;
	cout<<"          O  OOO   OOOOOO   O  O  O   OOOOOO         O    O     O   O     OOOOOO   OOOOO        "<<endl;
	cout<<"          O    O   O    O   O     O   O              O    O      O O      O        O O          "<<endl;
	cout<<"          OOOOOO   O    O   O     O   OOOOOO         OOOOOO       O       OOOOOO   O  OO        "<<endl;
	cout<<"                                                                                                "<<endl;
	cout<<"                                                                                                "<<endl;
	cout<<"                                                                                                "<<endl;
	cout<<"                                                                                                "<<endl;
	cout<<"                                                                         -Domenico Ciancio      "<<endl;
	cout<<"                                                                         -Orazio Capone         "<<endl;
	cout<<"                                                                         -Cosimo Coppolaro      "<<endl;
	cout<<"                                                                                                "<<endl;
	cout<<"================================================================================================"<<endl;
}

int main(int argc, char** argv) {	
	
	Setup();
	en.ScanEnemy(w.GetMap());
	
	while(true)
	{
		Tick();
		
		w.SetBlock('P', posX, posY);
		w.Print();
		p.PrintStats();
		cout<<"\t "<<en.getDamage()<<"\tDMG"<<endl;
		cout<<"Killed enemy "<<en.GetKilled()<<endl;
		
		cout<<posX<<" "<<posY<<endl;
		cout<<"Tot. enemy= "<<en.numEnemy<<endl;
		
		if(p.getHealth() <= 0)
		{
			break;
		}
		
		//system("pause");	
	}
	system("cls");
	endGame();
	cout<<"Hai raccolto in totale: "<<p.getCoin()<<"$ !"<<endl;
	system("pause");
	return 0;
}
