#ifndef __Technician__
#define __Technician__
#include"GlobalDefinitions.h"
#include"Car.h"
#include"Garbage.h"
#include"Stores.h"
#include"Recycling.h"
#include"JobSheet.h"

class Technician// : public ActiveClass
{
	
	int NewOil, NewAirFilter, NewOilFilter;
	int OldOil, OldAirFilter, OldOilFilter;
	int NewTires, OldTires;
	//Pointers to other objects that Technician calls
	Car* my_Car;
	Garbage* my_Garbage;
	Recycling* my_Recycle;
	Stores* my_Stores;
	JobSheet* my_JobSheet;



	/*int main(void)
	{
		while (my_Car == NULL)
		{
			//.Wait();
			//(0, 10);
			cout << "Technician is waiting for a car...\n";
			//.Signal();
		}



		return 0;
	}*/

public:

	

	//============================
	//Functions for adding objects
	//============================

	void AddCar(Car* car)
	{
		my_Car = car;		//Point to car
	}
	void DelCar()
	{
		my_Car = NULL;		//Pointer does not point to car anymore
	}

	void AddGarbage(Garbage* garb)
	{
		my_Garbage = garb;		//Point to garb
	}
	void DelGarbage()
	{
		my_Garbage = NULL;		//Pointer does not point to  anymore
	}

	void AddRecycling(Recycling* recycle)
	{
		my_Recycle = recycle;		//Point to recycling
	}
	void DelRecycling()
	{
		my_Recycle = NULL;		//Pointer does not point to Recycling anymore
	}

	void AddStores(Stores* stores)
	{
		my_Stores = stores;		//Point to stores 
	}
	void Del()
	{
		my_Stores = NULL;		//Pointer does not point to  anymore
	}

	void AddJobSheet(JobSheet* sheet)
	{
		my_JobSheet = sheet;		//Point to job sheet
	}
	void DelJobSheet()
	{
		my_JobSheet = NULL;		//Pointer does not point to  anymore
	}

	//====================================
	// End of ADD/DELETE object functions
	//====================================
	void Service(Car* pinto)
	{
		my_Car = pinto;
		my_JobSheet = new JobSheet;
		cout << "Technician got a car...\n";


		//Getting new items from Canadian Tire
		cout << "Technician getting new parts for car...\n";
		NewOil = my_Stores->GetOil(530, 10);		//Getting new oil from the store
		NewAirFilter = my_Stores->GetAirFilter();
		NewOilFilter = my_Stores->GetOilFilter();

		cout << "Adding oil to item list...\n\n";
		cout << "Adding oil filter to item list...\n\n";
		cout << "Adding air filter to item list...\n\n";
		my_JobSheet->AddItem(530, 10, 5.0);
		my_JobSheet->AddItem(1, 1, 20.0);
		my_JobSheet->AddItem(2, 1, 15.0);



		//Taking Old Items from the Car
		cout << "Technician removing Old Oil...\n";
		OldOil = my_Car->SwapOil(NewOil);
		my_Recycle->Recycle(OldOil);
		cout << "Adding oil change to job list...\n";
		my_JobSheet->AddLabourItem("Oil Change", 50.0);

		cout << "Technician removing Old Oil filter...\n";

		OldOilFilter = my_Car->SwapOilFilter(NewOilFilter);
		my_Garbage->Dispose(OldOilFilter);
		//Add Labour Item
		cout << "Adding oil filter change to job list...\n";
		my_JobSheet->AddLabourItem("Oil filter Change", 10.0);


		cout << "Technician removing Old Air filter...\n";

		OldAirFilter = my_Car->SwapAirFilter(NewAirFilter);
		my_Garbage->Dispose(OldAirFilter);
		//Add Labour Item
		cout << "Adding air filter change to job list...\n";
		my_JobSheet->AddLabourItem("Air Filter Change", 10.0);


		cout << "Technician recycling old oil and throwing out old parts...\n";


		//Checking tires
		cout << "Technician Checking the tires...\n";
		if (my_Car->TireStatus())
		{
			NewTires = my_Stores->GetTires("pinto", 37, 4);

			cout << "Adding 4 tires to item list...\n";
			my_JobSheet->AddItem(NewTires, 4, 100.0);

			OldTires = my_Car->SwapTires(NewTires);


			cout << "Technician swapping tires...\n";


			//Add Labour Item
			cout << "Addingtire change to job list...\n";
			my_JobSheet->AddLabourItem("tire Change", 100.0);

			my_Car->RotateTires();
			cout << "Technician rotating tires...\n";

			//Add Labour Item
			cout << "Adding rotate tires to job list...\n";
			my_JobSheet->AddLabourItem("rotate tires", 20.0);
		}
			

		cout << "Technician Done Servicing " << my_Car->my_Name;
	}

	Car* ReturnCar()
	{
		return my_Car;

	}
	JobSheet* ReturnJobSheet()
	{
		return my_JobSheet;

	}

	~Technician()
	{
		delete my_JobSheet;
	}

};




#endif // !Technician
