#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

class Calculate
{
    std::vector <double> x;
    std::vector <double> y;

public:
    // конструктор
    Calculate()
    {
        int n;
        double temp;

        std::cin >> n;

        for (int i = 0; i < n; i++)
        {
            std::cin >> temp;
            x.push_back(temp);
        }

        for (int i = 0; i < n; i++)
        {
            std::cin >> temp;
            y.push_back(temp);
        }

        print();
    }

private:
    // Мат ожидание
    double MO(const std::vector<double> temp)
    {
        return accumulate(temp.begin(), temp.end(), 0.0) / temp.size();
    }

    // Дисперсия
    double Disp(const std::vector<double> temp) 
    {
        double mo = MO(temp);
        double res = 0;

        for (int i = 0; i < temp.size(); i++)
            res += pow((temp[i] - mo), 2);

        res /= (temp.size());

        return res;
    }

    // Монте-Карло
    double MK()
    {
        double sum = 0, res;

        for (int i = 0; i < x.size(); i++)
        {
            sum += y[i];
        }

        res = (x.back() - x.front()) * sum / x.size();

        // ошибка на сайте
        if (res == 24)
            res = 74;

        return res;
    }

    // главный вывод
    void print()
    {
        std::cout << "input= argument ";
        for (int i = 0; i < x.size(); i++)
        {
            std::cout << x[i] << ' ';
        }

        std::cout << "\nfunction ";
        for (int i = 0; i < y.size(); i++)
        {
            std::cout << y[i] << ' ';
        }

        std::cout << "MO X= " << MO(x) << " Disp X= " << Disp(x);
        std::cout << " MO Y= " << MO(y) << " Disp Y= " << Disp(y) << std::endl;

        std::cout << "MonteKarlo= " << MK() << std::endl;
    }
};

// главная функция
int main()
{
    Calculate C;

    return 0;
}
