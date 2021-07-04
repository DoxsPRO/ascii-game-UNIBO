class Player 
{
	protected:
		int x=0, y=0;
		char ascii='O';
		char stats[100]="100   100 coin";
		int health = 100;
		int coin = 0;
		
	public:
		void GetPosition(int &posX, int &posY);
		void Move(int posX, int posY);
		void setHealth(int setHealth);
		void setCoin(int setCoin);
		void Tick();
		void PrintStats();
};
