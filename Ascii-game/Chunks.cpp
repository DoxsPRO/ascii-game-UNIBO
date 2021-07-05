#include "Chunks.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
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

char **Chunks::GetRandom()
{
	int max=coda->id + 1;
	
	int r=rand() % max; //random number
	
	
	Nodo *t=testa;
	
	while(r>0)
	{
		t=t->next;
		r--;
	}
	
	//system("pause");
	
	char **temp=new char *[32];
	
	for(int i=0; i<32; i++)
		temp[i]=new char[16];
		
	for(int i=0; i<16 ; i++)
	{
		for(int j=0; j<32 ; j++)
		{
			
			temp[j][i]=t->chunk[j][i];
		}
	}
	//system("pause");
	
	return temp;
	
}

void Chunks::Init()
{
	srand (time(NULL));
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
			"             $                  "
			"            =====               "
			"                                "
			"                                "
			"      ======                    "
			"                  $             "
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
			"       $               $        "
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
			"         $    $                 "
			"                                "
			"               ====             "
			"================================", 0);
				
	Append(	"                                "
			"                                "
			"                                "
			"                                "
			"                                "
			"                                "
			"                                "
			"                                "
			"                 =====          "
			"                                "
			"              $                 "
			"             ===                "
			"           ===                  "
			"         ===                    "
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
			"                  ===           "
			"          =====                 "
			"                                "
			"               ====             "
			"         $                      "
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
			"                ===             "
			"                                "
			"              ==   ==           "
			"                                "
			"                ===             "
			"       $                        "
			"================================", 0);
			
	//Print();
			
			
			
			
}

