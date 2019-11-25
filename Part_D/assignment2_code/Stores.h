#ifndef __Stores__
#define __Stores__
#include"GlobalDefinitions.h"

class Stores
{
	int Oil1, Oil2, Oil3;
	int Tires1, Tires2, Tires3;
	int AirFilter, OilFilter;

public:
	int GetOil(int type, int quantity)
	{
		if (type == 1030)
			return 1030;
		else if (type == 2030)
			return 2030;
		else
			return 530;

	}

	int GetAirFilter()
	{
		return 1;
	}

	int GetOilFilter()
	{
		return 2;
	}

	int GetTires(string make, int size, int quantity)
	{
		if (make == "Truck" || "truck")
		{
			if (size == 35)
				return 35;
			else if (size == 37)
				return 37;
			else
				return 40;
		}

		else if (make == "Car" || "car")
		{
			if (size == 25)
				return 25;
			else if (size == 27)
				return 27;
			else
				return 30;
		}

		else
			return 33;

	}

};


#endif // !Stores
