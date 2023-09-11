#include <iostream>
#include <vector>
#include <memory>

using namespace std;

struct Base
{
	virtual ~Base() = default;
};

class massive
{
	int mass_size;
	
	const unique_ptr<Base> arr[];

	vector <double> ish_mass()
	{
		vector <double> mass;
		int temp = 0;
		cin >> mass_size;

		// заполнение исходного массива числами в диапазоне от -50 до 50
		for (int i = 0; i < mass_size; i++)
		{
			temp = rand() % 100 - 50;
			mass.push_back(temp);
		}
	}

	void result_mass(vector <double>* mass)
	{

	}
};

int main()
{
	

	return 0;
}