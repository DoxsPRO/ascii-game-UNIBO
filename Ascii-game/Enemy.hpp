class Enemy
{
	protected:
		struct Nodo
		{			
			int id;
			int x=0, y=0;
			char ascii = '@';
			int health = 100;
			int damage = 10;
			double diffuculty = 1;
			bool alive=false;
			int lastFire=10;
		};
		
		Nodo enemies[20];
	
	public:
		int count=0;
		void ScanEnemy(char **map);
		int EnemyAt(int x, int y); //restituisce l'id
		void Clear();
		char **Tick(char **map);
		
		
};
