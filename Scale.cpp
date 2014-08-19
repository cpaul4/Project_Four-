#include "Scale.h"
#include <iostream>
using std::cout;
using std::endl;

/*The scale constructor.*/
Scale::Scale(float w)
{
	weight=w;
}

/*Increases wieght as long as it is below desired_weight.*/
void Scale::add_weight(float desired_weight)
{
	while (weight<desired_weight)
	{
		weight=weight+0.5;
	}
}

/*Decreases weight as long as it is above desired_weight.*/
void Scale::subtract_weight(float desired_weight)
{
	while (weight>desired_weight)
	{
		weight=weight-0.5;
	}
}

/*Returns weight.*/
float Scale::get_weight() const
{
	return weight;
}

/*Sets weight equal to 0.*/
void Scale::zero_weight()
{
	weight=0;
}
