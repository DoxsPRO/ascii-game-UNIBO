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
			int lastFire;
		};
		
		Nodo enemies[20];
		double mulD=1.0; //moltiplicatore danno inflitto
		int killed=0;

	public:
		int numEnemy = 0;
		int count=0;
		void ScanEnemy(char **map);
		char **Tick(char **map);
		void SetDamage(double x);
		double getDamage();
		int GetKilled();
		
};
