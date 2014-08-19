#include "Deli.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::getline;

/*Creates a Deli object and sets the weights of all the products sold equal to the parameters. It ssets the name of each Product in the array equal to a product sold in the deli. It also sets the prices equal to the prices in a price_list object that is an attribute of the class. It gives each customer object in the array of customers an id, an availability, and instantiates their Cart.*/
Deli::Deli(float weight1, float weight2, float weight3, float weight4, float weight5, float weight6)
{
	product_sold[0]=Product ("Pastrami", weight1);
	product_sold[1]=Product ("Roast Beef", weight2);
	product_sold[2]=Product ("Salami", weight3);
	product_sold[3]=Product ("Pickles", weight4);
	product_sold[4]=Product ("Black Olives", weight5);
	product_sold[5]=Product ("Green Olives", weight6);
	int i;
	for (i=0; i<6; i++)
	{
		product_sold[i].set_price(price_list.get_price(product_sold[i].get_product_name()));
	}
	int j;
	for(j=0; j<10; j++)
	{
		customer_array[j].customer_id=j;
		customer_array[j].availability=1;
		customer_array[j].cart=Cart();		
	}
}

/*It sets the availability of a customer equal to 0, signalling that that customer is now in the deli, as many times as the user watns or until it runs out of available customers.*/
void Deli::customer_arrival()
{
	char answer='y';
	while (answer=='y')
	{
		int i=0;
		while (customer_array[i].availability!=1 && i<11)
		{
			i++;
		}
		if (i==10) 
		{
			cout<<"There is no room for any more customers."<<endl;
			answer='n';
		}
		else
		{
			customer_array[i].customer_id=i;
			customer_array[i].availability=0;
			cout<<"A customer with id "<<i<<" has arrived. Do you want another customer to arrive? (y/n)"<<endl; 
			cin>>answer;
			if (answer!='y' || answer!='n') cout<<"That is not a valid answer"<<endl;
		}
	}                                        	
}

/* Creates a menu that allows a user to print an invoice for a customer, allows a customer to select a product and then add it to the cart, check out, or return to the main menu.*/
void Deli::serve_customer(int id)
{
	int choice;
	cout<<"Please choose an action:\n 1: Print invoice\n 2: Add something to cart\n 3: Check out\n 4: Return to main menu"<<endl;
	cin>>choice;
	if (choice<1 || choice>4) cout<<"That is not a valid choice"<<endl;
	else
	{
		switch (choice)
		{
			case 1:
				customer_array[id].cart.print_invoice();
				break;
			case 2:
			{	
				string name;
				int weight;
				int price;
				char answer='y';
				while (answer=='y')
				{
					cout<<"Enter the name of what you would like to buy"<<endl;
					cin.ignore();
					getline(cin, name);
					cout<<"Enter the weight you would like to buy"<<endl;
					cin>>weight;
					price=price_list.get_price(name);
					if (weight<scale.get_weight()) scale.add_weight();
					if (weight>scale.get_weight()) scale.subtract_weight(); 
					customer_array[id].cart.select_product(name, weight, price);
					cout<<"Do you want to add the product to your cart?(y/n)"<<endl;
					cin>>answer;
					if (answer=='y')
					{
						customer_array[id].cart.add_to_cart(name, weight, price);
					} 
					cout<<"Would you like to buy something else? (y/n)"<<endl;
					cin>>answer;	 
				}
				break;
			}
			case 3:
				check_out(id);
				break;
			case 4: 
				break;
		}
	}
}

/*Runs through and deletes all the products in a customer's cart while at the same time storing the weights of each product in the product_sold array as the total product sold. It also stores the costs of each product as the price of each product in the product_sold array. This is not really the price, but actually is the total revenue for each product so far.*/
void Deli::check_out(int id)
{
	float w, p;
	int i;
	customer_array[id].cart.print_invoice();
	while (customer_array[id].cart.check_out(w,p,i)==1)
	{
		product_sold[i].set_weight(product_sold[i].get_weight()+w);
		product_sold[i].set_price(product_sold[i].get_price()+p*w);
	}
	customer_array[id].availability=1;
}

/*This prints out the total product sold for all products in the array as well as the total revenue for all products.*/
void Deli::report()
{
	int total_product=0;
	int total_revenue=0;
	int i;
	for (i=0; i<6; i++)
	{
		total_product+=product_sold[i].get_weight();
		total_revenue+=product_sold[i].get_price();
		cout<<product_sold[i].get_product_name()<<":"<<product_sold[i].get_weight()*product_sold[i].get_price()<<endl;
	}
	cout<<"Total product sold: "<<total_product<<endl;
	cout<<"Total revenue: "<<total_revenue<<endl;
}

/*This sets all the weights equal to 0.*/
void Deli::new_day()
{
	int i;
	for (i=0; i<6; i++)
	{
		product_sold[i].set_weight(0);
		product_sold[i].set_price(0);
	}
}

/*This allows a user to change the price in the price_list of as many products as he or she wants.*/
void Deli::change_prices()
{
	string product_name;
	float new_price;
	char answer='y';
	while (answer=='y')
	{
		cout<<"Enter the name of the product whose price you would like to change"<<endl;
		cin.ignore();
		getline(cin, product_name);
		cout<<"Enter the price you would like to change it to"<<endl;
		cin>>new_price;
		if (new_price<0)
		{
			cout<<"That is not a valid price."<<endl;
			answer='n';
		}
		else
		{
			price_list.set_price(product_name, new_price);
			cout<<"Would you like to change another price?(y/n)\n"<<endl;
			cin>>answer;
		}
	}
}

/* This allows a user to view the prices in the price_list.*/
void Deli::view_prices()
{
	price_list.print_price();
}

/*This allows a user to check the availability of an id without trying to access a private function.*/
int Deli::get_availability(int id) const
{
	return customer_array[id].availability;
}
