#pragma once
#include <map>
#include "Customer.h"

class CustomerManager
{
public:
	static CustomerManager& instance()
	{
		static CustomerManager* instance = new CustomerManager(); 
		return *instance;
	}
	   
	void add_customer_point(int id, float point);
	float get_customer_point(int id);
	bool search_customer(int id);

private:
	CustomerManager();
	~CustomerManager();
	
	std::map<int, float> _customer_point_map;
};

