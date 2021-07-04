class Enemy
{
	protected:
		int x=0, y=0;
		char ascii = '@';
		int health = 100;
	
	public:
		void GetPosition(int &posX, int &posY);
		void Move(int posX, int posY);
		void getHealth();
		void setHealth(int setH);
		void Tick();
		void PrintStats();
};
