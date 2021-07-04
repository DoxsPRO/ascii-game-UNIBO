class Player 
{
	protected:
		int x=0, y=0;
		char ascii='O';
		int health = 100;
		int coin = 0;
		
	public:
		void GetPosition(int &posX, int &posY);
		void Move(int posX, int posY);
		void setHealth(int setH);
		void setCoin(int setC);
		void Tick();
		void PrintStats();
};
