class Bullet
{
	protected:
		struct Nodo
		{
			int x, y;
			int d; //direction
			int damage = 10;
			bool active=false;
			int id;
		};
		
		int count=0;
		struct Nodo bullets[500];
		char **map;

	public:
		char **Tick(char **map);
		void SpawnBullet(int x, int y, int d);
		void Clear();
		void Delete(int id);
		
		
		
};
