
#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Deli.h" 
#include "Product.h"
#include "Scale.h"
#include "Price_list.h"

int main()
{
	int action;
	int id=-1;
	Deli mydeli(0,0,0,0,0,0); /*Creates the deli object.*/
	cout<<"Please select the number of an action to perform:\n 0: Exit\n 1: Have new customer arrive\n 2: Select customer to serve\n 3: Report\n 4: Start new day\n 5: Change prices (originally set at $1 each)\n 6: View prices"<<endl; /*Prints out the main menu.*/
	cin>>action;
	while (action!=0) /*Allows different actions to be performed and allows the user to select a new action as many times as he or she wants.*/
	{
		if (action < 0 || action > 6) cout<<"That is not a valid choice."<<endl;
		else
		{
			switch (action)
			{
				case 0: 
					break;
				case 1:
					mydeli.customer_arrival();
					break;
				case 2:
					cout<<"Pick the id of the customer you would like to serve from 0-9\n"<<endl;
					cin>>id;
					if (id>9 || id<0) cout<<"That id is not valid.\n"<<endl; 
					else if (mydeli.get_availability(id)!=0)
					{
						cout<<"A customer with that id is not currently in the deli."<<endl; /*If a customer has not entered the deli with that id, they cannot be served. */
					}
					else
					{
						mydeli.serve_customer(id);
					}
					break;
				case 3:
					mydeli.report();
					break;
				case 4:
					mydeli.new_day();
					break;				
				case 5:
					mydeli.change_prices();
					break;
				case 6: 
					mydeli.view_prices();
					break;
			}
		}
		cout<<"Please select the number of an action to perform:\n 0: Exit\n 1: Have new customer arrive\n 2: Select customer to serve\n 3: Report\n 4: Start new day\n 5: Change prices (originally set at $1 each)\n 6:View prices"<<endl; /*The menu repeats until the user selects 0. */
		cin>>action;

	}
}

