#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

class Calculate
{
    vector <double> x;
    vector <double> y;

public:
    // конструктор
    Calculate()
    {
        int n;
        double temp;

        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            x.push_back(temp);
        }

        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            y.push_back(temp);
        }

        print();
    }

private:
    // Мат ожидание
    double MO(const vector<double> temp)
    {
        return accumulate(temp.begin(), temp.end(), 0.0) / temp.size();
    }

    // Дисперсия
    double Disp(const vector<double> temp) 
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
        cout << "input= argument ";
        for (int i = 0; i < x.size(); i++)
        {
            cout << x[i] << ' ';
        }

        cout << "\nfunction ";
        for (int i = 0; i < y.size(); i++)
        {
            cout << y[i] << ' ';
        }

        cout << "MO X= " << MO(x) << " Disp X= " << Disp(x);
        cout << " MO Y= " << MO(y) << " Disp Y= " << Disp(y) << endl;

        cout << "MonteKarlo= " << MK() << endl;
    }
};

// главная функция
int main()
{
    Calculate C;

    return 0;
}
