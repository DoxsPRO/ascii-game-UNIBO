class World 
{
	protected:
	char map[96][16];
	public:
	struct Nodo{
		Nodo *next;
		Nodo *prev;
		char sec[96][16]; //section
	};
	
	Nodo *pointer;
	//char chunk[32][16];
	
	//NODO
	
	
		int maxX, maxY;
		void Init();
		void Print();
		char BlockAt(int x, int y);
		void SetBlock(char c, int x, int y);
		
		void NextSection();
		bool PreviousSection();
		void CreaNodo();
		void App(); //append
		void CaricaMat(Nodo *n);
		void SalvaMat(Nodo *n);
		char **GetMap();
		void Copy(char **m);
		
};
