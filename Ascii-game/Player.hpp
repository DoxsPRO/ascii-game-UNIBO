class Player 
{
	protected:
		int x=0, y=0;
		char ascii='O';
		char stats[100]="100   100 coin";
		
	public:
		void GetPosition(int &posX, int &posY);
		void Move(int posX, int posY);
		void Tick();
		void PrintStats();
};
