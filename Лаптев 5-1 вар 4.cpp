#include <iostream>
#include <vector>

class massiv
{
public:
	std::vector <double> mass;
	int mass_size;

	//ñîçäàíèå ìàññèâà
	void new_mass()
	{
		double temp;

		std::cin >> mass_size;

		for (int i = 0; i < mass_size; i++)
		{
			std::cin >> temp;
			mass.push_back(temp);
		}

		std::cout << mass.size() << std::endl;
		result_cout();

		menu();
	}

private:
	//âûáîð äåéñòâèÿ
	void menu()
	{
		int point = -1;

		while (point != 0)
		{
			std::cin >> point;

			if (point == 0)
			{
				break;
			}
			else if (point == 1)
			{
				add_el();
			}
			else if (point == 2)
			{
				del_el();
			}

			result_cout();
		}
	}

	//äîáàâëåíèå ýëåìåíòà â ìàññèâ
	void add_el()
	{
		double temp;
		std::cin >> temp;

		mass.push_back(temp);

		std::cout << "+: " << mass.size() << std::endl;
	}

	//óäàëåíèå ýëåìåíòà èç ìàññèâà
	void del_el()
	{
		mass.pop_back();

		std::cout << "-: " << mass.size() << std::endl;
	}

	//íàõîæäåíèå ñóììû è ñðåäíåãî àðèôìåòè÷åñêîãî
	void math_methods()
	{
		double summ = 0, arith_mean = 0;

		for (int i = 0; i < mass.size(); i++)
		{
			summ += mass[i];
		}

		arith_mean = summ / mass.size();

		mass.push_back(summ);
		mass.push_back(arith_mean);
	}
	//äîï çàäàíèå - óìíîæåíèå íà íàèìåíüøèé àðãóìåíò
	void dop_quest()
	{
		double min_num = mass[0];

		for (int i = 1; i < mass.size(); i++)
		{
			if (min_num > mass[i])
			{
				min_num = mass[i];
			}
		}

		for (int i = 0; i < mass.size(); i++)
		{
			mass[i] *= min_num;
		}
	}

	//âûâîä äàíûõ
	void result_cout()
	{
		print_mass();

		math_methods();
		print_mass();

		dop_quest();
		print_mass();
	}
	//âûâîä ìàññèâà
	void print_mass()
	{
		std::cout.setf(std::ios::fixed);
		std::cout.precision(3);

		for (int i = 0; i < mass.size(); i++)
		{
			std::cout << mass[i] << " ";
		}
		std::cout << std::endl;
	}
};


int main()
{
	massiv start;

	start.new_mass();

	return 0;
}
