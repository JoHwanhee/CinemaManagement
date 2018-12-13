#include "CustomerManager.h"

CustomerManager::CustomerManager()
{
}

CustomerManager::~CustomerManager()
{
}

void CustomerManager::add_customer_point(int id, float point)
{
	if (search_customer(id))
	{
		for (auto customer : _customer_point_map)
		{
			if (customer.first == id)
			{
				_customer_point_map[id] += point;
				break;;
			}
		}
	}
	else
	{
		_customer_point_map[id] += point;
	}

	if (_customer_point_map[id] < 0)
	{
		_customer_point_map[id] = 0;
	}
}

float CustomerManager::get_customer_point(int id)
{
	if (search_customer(id))
	{
		return _customer_point_map[id];
	}
	return 0.0;
}

bool CustomerManager::search_customer(int id)
{
	for (auto customer : _customer_point_map)
	{
		if (customer.first == id)
		{
			return  true;
		}
	}
	return false;
}
