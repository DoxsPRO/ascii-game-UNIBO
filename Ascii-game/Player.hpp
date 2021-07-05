#include "Bullet.hpp"
class Player 
{
	protected:
		int x=0, y=14;
		char ascii='O';
		int health = 100;
		int coin = 0;
		Bullet bt;
		
		
	public:
		void GetPosition(int &posX, int &posY);
		void Move(int posX, int posY);
		void setHealth(int setH);
		int getHealth();
		int getCoin();
		void setCoin(int setC);
		void PrintStats();
		char **BTick(char **map);
		void SpawnBullet(int x, int y, int d);
		char **Delete(char **map);
};
