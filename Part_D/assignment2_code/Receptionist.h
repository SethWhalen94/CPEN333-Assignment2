#ifndef __Receptionist__
#define __Receptionist__
#include "GlobalDefinitions.h"
#include "Technician.h"
#include <list>

class Receptionist// : public ActiveClass
{
	
	int my_ServiceRecord;
	/*int my_Invoice;*/
	string my_Name;
	/*JobSheet* my_JobSheet;*/
	Technician* my_Tech;
	BOOL my_Payment;

	

public:

	JobSheet* my_JobSheet;
	double my_Invoice;
	
	Receptionist(string name, int invoice, int servicerecord, BOOL payment = FALSE)
		: my_Name(name), my_Invoice(invoice), my_ServiceRecord(servicerecord), my_Payment(payment)
	{

	}

	//============================
	// Functions to add Technician
	//============================

	void AddTech(Technician* thisTech)
	{

		my_Tech = thisTech;


	}

	void DelTech()
	{
		if (my_Tech != NULL)
		{
			my_Tech = NULL;

		}

	}


	//===========================
	// End of technician functions
	//===========================

	//===========================
	// Other member functions
	//===========================

	void MakeCoffee(int cups)
	{
		//.Wait();
		//MOVE_CURSOR(0, 0);
		cout << "The receptionist is making " << cups << " cups of coffee....\n\n";
		//.Signal();

	}

	void GenerateInvoice()	//Update my_Invoice
	{
		my_JobSheet = my_Tech->ReturnJobSheet();

		my_Invoice = my_JobSheet->ReturnCost();

		//.Wait();
		//MOVE_CURSOR(0, 1);
		cout << "The receptionist generated the invoice...\n";
		//.Signal();

	}

	void StampServiceRecord()		//Stamp service record bt incrementing its value by 1
	{
		my_ServiceRecord = my_ServiceRecord + 1;
		//.Wait();
		//MOVE_CURSOR(0, 2);
		cout << "The receptionist stamped the service record...\n";
		//.Signal();

	}

	void GetJobSheet()		//change my_Jobsheet to the Technicians Job sheet
	{
		my_JobSheet = my_Tech->ReturnJobSheet();
	}

	void Payment()
	{
		if (my_Payment == FALSE)
			my_Payment = TRUE;

		cout << "Customer, you owe $" << my_Invoice << "\n Please use the terminal to pay\n";

		int pin;
		//MOVE_CURSOR(0, 50);
		cout << "Enter your PIN : ";
		cin >> pin;

		cout << "\n\nThank you for your business...\n\n";

		//.Wait();
		//MOVE_CURSOR(0, 3);
		cout << "The receptionist Recieved the payment...\n";
		//.Signal();
	}


};

#endif // !Receptionist
