#ifndef __Car__
#define __Car__
#include"GlobalDefinitions.h"
#include"AirFilter.h"
#include"OilFilter.h"
#include"Tire.h"
class Car
{
	//string my_Name;
	int Year, my_Oil;
	BOOL TiresWarn;

	AirFilter* my_AirFilter;
	OilFilter* my_OilFilter;
	

public:
	string my_Name;
	Tire* Tire1;
	Tire* Tire2;
	Tire* Tire3;
	Tire* Tire4;

	Car(string name, int year, int oil, AirFilter* air, OilFilter* oilfilter, Tire* t1, Tire* t2, Tire* t3, Tire* t4, int Warn = TRUE) :
		my_Name(name), Year(year), my_Oil(oil), my_AirFilter(air), my_OilFilter(oilfilter),
		Tire1(t1), Tire2(t2), Tire3(t3), Tire4(t4), TiresWarn(Warn)
	{

	}

	int SwapOil(int new_oil)
	{
		int old_oil = my_Oil;
		my_Oil = new_oil;

		return old_oil;
	}

	int SwapOilFilter(int new_filter)
	{
		int old_filter = my_OilFilter->part_number;		//Old oil filter
		
		my_OilFilter->part_number = new_filter;		//Replace old filter

		return old_filter;
	}

	int SwapAirFilter(int new_filter)
	{
		int old_filter = my_AirFilter->part_number;		//Old air filter

		my_AirFilter->part_number = new_filter;		//Replace old filter

		return old_filter;
	}

	BOOL TireStatus()
	{
		return TiresWarn;

	}

	int SwapTires(int new_tires)
	{
		int old_tires = Tire1->size;
		Tire1->size = new_tires;
		Tire2->size = new_tires;
		Tire3->size = new_tires;
		Tire4->size = new_tires;

		TiresWarn = FALSE;		//Tires are brand new

		return old_tires;
	}

	void RotateTires()
	{


	}
	

};

#endif // !Car
