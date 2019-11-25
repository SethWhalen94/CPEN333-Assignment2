#include "Receptionist.h"
#include "Technician.h"

int main()
{
	Receptionist Ellie("Ellie", 0, 3);
	Technician Dave;
	//JobSheet JS1;
	Garbage Garbage;
	Recycling Recycle;
	Stores CT;

	AirFilter a1(10);
	OilFilter o1(11);
	Tire t1(25);
	Tire t2(25);
	Tire t3(25);
	Tire t4(25);
	Car pinto("Pinto", 1994, 530, &a1, &o1, &t1, &t2, &t3, &t4);

	Ellie.AddTech(&Dave);		//Receptionist now talks to Technician Dave

	Ellie.MakeCoffee(10);

	Dave.Service(&pinto);		//Technician now has the car

	

	//========================
	//Technician work record
	//========================
	//Dave.AddJobSheet(&JS1);
	Dave.AddGarbage(&Garbage);
	Dave.AddRecycling(&Recycle);
	Dave.AddStores(&CT);

	Ellie.my_JobSheet = Dave.ReturnJobSheet();
	Ellie.GenerateInvoice();
	Ellie.StampServiceRecord();

	
	cout << Ellie.my_JobSheet << '\n';

	Ellie.Payment();

	


	return 0;
}