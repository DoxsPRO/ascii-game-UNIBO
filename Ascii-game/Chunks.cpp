#include "Chunks.hpp"
#include <iostream>
using namespace std;

void Chunks::Append(char *text, int level)
{
	Nodo *n=new Nodo;
	n->next=NULL;
	n->id=AId;
	n->level=level;
	AId++;
	
	for(int i=0; i<16; i++)
	{
		for(int j=0; j<32 ; j++)
		{
			n->chunk[j][i]=text[j+(i*32)];
		}
	}
	
	if(testa==NULL)
	{
		testa=n;
		coda=n;
	}
	else
	{
		coda->next=n;
		coda=n;
	}
}

void Chunks::Print()
{
	Nodo *n=testa;
	
	while(n!=NULL)
	{
		for(int i=0; i<16; i++)
		{
			for(int j=0; j<32; j++)
			{
				cout<<n->chunk[j][i];
			}
			cout<<endl;
		}
		
		cout<<n->id<<" "<<n->level<<endl;
		n=n->next;
	}
}

char Chunks::**GetRandom()
{
	
	return testa->chunk;
	
}

void Chunks::Init()
{
	testa=NULL;
	AId=0;
	
	Append(	"                                "
			"                                "
			"                                "
			"                                "
			"                                "
			"       ======                   "
			"                                "
			"                 ======         "
			"                                "
			"                                "
			"            =====               "
			"                                "
			"                                "
			"      ======                    "
			"                                "
			"================================", 0);
			
	Append(	"                                "
			"                                "
			"                                "
			"                                "
			"                                "
			"                                "
			"                                "
			"                                "
			"                                "
			"              ==                "
			"                                "
			"                                "
			"           ===  ==              "
			"                                "
			"                                "
			"================================", 0);
				
	Append(	"                                "
			"                                "
			"                                "
			"                                "
			"                                "
			"                                "
			"                                "
			"                                "
			"                                "
			"                                "
			"                                "
			"                                "
			"                                "
			"                                "
			"               ====             "
			"================================", 0);
			
	Print();
			
			
			
			
}

