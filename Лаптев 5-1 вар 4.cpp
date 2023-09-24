#include <iostream>
#include <vector>

class massiv
{
public:
	vector <double> mass;
	int mass_size;

	//создание массива
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
	//выбор действия
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

	//добавление элемента в массив
	void add_el()
	{
		double temp;
		std::cin >> temp;

		mass.push_back(temp);

		std::cout << "+: " << mass.size() << std::endl;
	}

	//удаление элемента из массива
	void del_el()
	{
		mass.pop_back();

		std::cout << "-: " << mass.size() << std::endl;
	}

	//нахождение суммы и среднего арифметического
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
	//доп задание - умножение на наименьший аргумент
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

	//вывод даных
	void result_cout()
	{
		print_mass();

		math_methods();
		print_mass();

		dop_quest();
		print_mass();
	}
	//вывод массива
	void print_mass()
	{
		std::cout.setf(ios::fixed);
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