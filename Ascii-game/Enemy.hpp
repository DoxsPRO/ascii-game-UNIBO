class Enemy
{
	protected:
		struct Nodo
		{			
			int id;
			int x=0, y=0;
			int d=-1; //direction
			char ascii = '@';
			int health = 100;
			int damage = 10;
			double diffuculty = 1;
			bool alive=false;
			int still=0;
			int lastFire=10;
		};
		
		
		Nodo enemies[20];
		int mulD=1; //moltiplicatore danno inflitto

	public:
		int count=0;
		void ScanEnemy(char **map);
		char **Tick(char **map);
		void SetDamage(int x);
		
		
};
