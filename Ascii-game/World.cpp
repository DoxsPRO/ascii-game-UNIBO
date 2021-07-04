#include "World.hpp"
#include <iostream> 
#include <windows.h>
#include "Chunks.hpp"
using namespace std;


void World::Init()
{
	maxX=96;
	maxY=16;
	
	
	for(int i=0; i<96; i++)
	{
		for(int j=0; j<16; j++)
		{
			map[i][j]=32;
		}
	}
	
	for(int i=0; i<96; i++)
	{
			map[i][15]='=';
	}
	
	pointer=NULL;
	CreaNodo();
	CaricaMat(pointer);
}

void World::CaricaMat(Nodo *n)
{
	for(int i=0; i<16; i++)
	{
		for(int j=0; j<96; j++)
		{
			map[j][i]=n->sec[j][i];
		}
	}
}

void World::Print()
{
	SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE), {0,0});
	for(int i=0; i<maxY; i++)
	{
		for(int j=0; j<maxX; j++)
		{
			cout<<map[j][i];
		}
		cout<<endl;
	}

}

char World::BlockAt(int x, int y)
{
	if(x<0 || y<0 || x>=maxX || y>=maxY)
	 	return 0;
	else
		return map[x][y];
}

void World::SetBlock(char c, int x, int y)
{
	if(x<0 || y<0 || x>=maxX || y>=maxY)
	 	return;
	 	
	map[x][y]=c;
}






void World::NextSection()
{
	if(pointer->next==NULL)
		CreaNodo();
		
	pointer=pointer->next;
	CaricaMat(pointer);
}

void World::PreviousSection()
{
	
}

void World::CreaNodo()
{
	Nodo *temp=new Nodo;
	temp->next=NULL;
	
	Chunks ch;
	ch.Init();
	
	for(int z=0; z<3; z++)
	{
		char **chunk=ch.GetRandom();
		
		for(int i=0; i<16; i++)
		{
			for(int j=0; j<32 ; j++)
			{
				temp->sec[j+(32*z)][i]=chunk[j][i];
			}
		}
	}
	
	if(pointer ==NULL)
	{
		pointer=temp;
		return;
	}
	else
	{
		pointer->next=temp;
		temp->prev=pointer;
		
		return;
	}
	
	
}
	
		
		
		

