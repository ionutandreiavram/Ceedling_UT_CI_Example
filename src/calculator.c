
#include "calculator.h"
#include "dummy_value.h" //This is just for mocking trial (get_value function)

double add_numbers(double a, double b)
{
	if (get_value())
	{
		//do nothing
	}
	else
	{
		a = 1;
	}
	double c = get_value();
return a+b+c;
}

double sub_numbers(double a, double b)
{
	if (a>0){
		//do nothing
	}
	else{
		//do nothing also
	}
return a-b+get_value();
}




























