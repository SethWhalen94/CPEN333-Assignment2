#ifndef __Garbage__
#define __Garbage__
#include"GlobalDefinitions.h"

class Garbage
{
public:
	void Dispose(int stuff)
	{
		//.Wait();
		//MOVE_CURSOR(0, 21);
		cout << "Disposing of part with part number " << stuff << " ....\n";
		//.Signal();

	}

};


#endif // !Garbage
