#ifndef __JobSheet__
#define __JobSheet__
#include"GlobalDefinitions.h"

struct Item {

	int Part_Num;
	int Quantity;

};

class JobSheet
{
	list <string> my_Jobs;
	
	list <Item> my_Items;
	double my_Cost;

public:

	JobSheet(double cost = 0) : my_Cost(cost)
	{

	}
	void AddItem(int part, int quantity, double cost)
	{

		Item item = { part,quantity };	//Create Item to add to list of items
		my_Cost = my_Cost + quantity*cost;		//Increment cost

		my_Items.push_front(item);		//Add item to list 

		//.Wait();
		//MOVE_CURSOR(0, 22);
		cout << "Adding Item to jobsheet...\n";
		//.Signal();
	}

	void AddLabourItem(string job, double cost)
	{
		my_Cost = my_Cost + cost;		//Increment Cost
		my_Jobs.push_front(job);		//Add job to list

		//.Wait();
		//MOVE_CURSOR(0, 23);
		cout << "Adding Labour Item to jobsheet...\n";
		//.Signal();

	}

	double ReturnCost()
	{
		return my_Cost;
	}

};


#endif // !JobSheet
