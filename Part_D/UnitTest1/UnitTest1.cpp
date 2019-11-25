#include "pch.h"
#include "CppUnitTest.h"
#include "..\assignment2_code\Receptionist.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestFinalPaymentAmount)
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

			Assert::AreEqual(TRUE, pinto.TireStatus());

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

			double total_cost = 5.0 * 10.0 + 20.0 + 15.0 + 50.0 + 10.0 + 10.0 + 400.0 + 100.0 + 20.0;

			Assert::AreEqual(total_cost, Ellie.my_Invoice);
			Assert::AreEqual(FALSE, pinto.TireStatus());
			//Check that all 4 tires are changed
			Assert::AreEqual(37, pinto.Tire1->size);
			Assert::AreEqual(37, pinto.Tire2->size);
			Assert::AreEqual(37, pinto.Tire3->size);
			Assert::AreEqual(37, pinto.Tire4->size);
		}
	};
}
