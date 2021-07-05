class Bullet
{
	protected:
		struct Nodo
		{
			int x, y;
			int directionBullet;
			int damage = 10;
			bool active=false;
			int id;
		};
		
		int count=0;
		struct Nodo bullets[100];

	public:
		char **Tick(char **map);
		void SpawnBullet(int x, int y, int d);
		void Clear();
		void Delete();
		
		
		
};
