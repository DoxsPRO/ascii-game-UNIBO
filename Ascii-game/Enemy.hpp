class Enemy
{
	protected:
		struct Nodo
		{
			Nodo *next;
			Nodo *prev;
			
			int idEnemy;
			int x=0, y=0;
			char ascii = '@';
			int health = 100;
			int damage = 10;
			double diffuculty = 1;
		};
		
		Nodo *testa, *coda;
	
	public:
		
};
