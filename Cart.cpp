#include "Cart.h"
#include "Price_list.h"
#include "Scale.h"
#include "Product.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <stdlib.h>

#include <string>
using std::string;

/*Creates a cart.*/
Cart::Cart()
{
	Queue_head=NULL;
}

/*Creates a new_product that takes in as attributes what product the user wants, the weight the user wants, and the current price of the product. */
void Cart::select_product(string &product_name, float weight, float  price)

{
	new_product=(product*) malloc(sizeof(product));
	new_product->pproduct = new Product(product_name, weight, price);
	new_product->pproduct->set_price(price);
	new_product->pproduct->set_weight(weight);
	new_product->pproduct->set_name(product_name);		
	new_product->next=NULL;
}

/*Adds the new_product to the cart, setting it either as Queue_head, if Queue_head is NULL, or else setting it at the end of the queue.*/
void Cart::add_to_cart(string &product_name, float weight, float price)
{
	select_product(product_name, weight, price);
	if (Queue_head==NULL) 
	{	
		Queue_head=new_product;
		
	}
	else
	{
		product *qproduct;
		qproduct=Queue_head;
		while (qproduct->next!=NULL)
		{
			qproduct=qproduct->next;
		}
		qproduct->next=new_product;
	}
}

/*Runs through all the objects in the queue as long as Queue_head is not null, printing out their names, prices, weights, and costs. It also prints out the total cost of all the products in the cart.*/
void Cart::print_invoice()
{
	if (Queue_head==NULL) cout<<"There are no products in the cart."<<endl;
	else
	{
		float total_cost=0;
		product *qproduct;
		qproduct=Queue_head;
		while (qproduct!=NULL)
		{
			cout<<qproduct->pproduct->get_product_name()<<" "<<qproduct->pproduct->get_weight()<<" pounds "<<"Price: $"<<qproduct->pproduct->get_price()<<" Cost: $"<<qproduct->pproduct->get_weight()*qproduct->pproduct->get_price()<<endl;
			total_cost+=(qproduct->pproduct->get_weight()*qproduct->pproduct->get_price());
			qproduct=qproduct->next;
		}
		cout<<"\nTotal cost is: $"<<total_cost<<endl;
	}
}

/*Returns 0 if there are no objects in the cart. If there is at least one object, it deletes the first object after setting the id, weight, and price of the object as the parameters.*/
int Cart::check_out(float &weight, float &price, int &id)
{
	if (Queue_head==NULL)
	{
		cout<<"Cart is now empty."<<endl;
		return 0;
	}
	else
	{
		product *temp;
		id=Queue_head->pproduct->get_product_id();
		weight=Queue_head->pproduct->get_weight();
		price=Queue_head->pproduct->get_price();
		temp=Queue_head;
		Queue_head=Queue_head->next;
		delete temp->pproduct;
		free (temp);
		return 1;
	}
}

/*Returns Queue_head as a product, not a pointer.*/
product Cart::get_Queue_head() const
{
	return *Queue_head;
}
