#include <iostream>
#include <string>
#include <limits>
#include <math.h>
class MathFunction
{
protected:
    std::string function_name;

public:
    MathFunction() {}
    float get_value(int x)
    {
        return x;
    }
    float get_max_value(int x, int y)
    {
        return x;
    }
    virtual void afisare() {}
    void set_func(std::string name)
    {
        this->function_name = name;
    }
    std::string get_func()
    {
        return this->function_name;
    }
};
class Polynomial : public MathFunction
{
protected:
    float *coefficients;

public:
    Polynomial() {}
    Polynomial(float *coeff, int n)
    {
        MathFunction::set_func("Polynomial");
        this->coefficients = new float[n + 1];
        for (int i = 0; i < n; i++)
        {
            this->coefficients[i] = coeff[i];
        }
        *&(this->coefficients[n]) = NULL;
    }
    void afisare()
    {
        int p;
        std::cout << MathFunction::get_func()
                  << "\n";
        std::cout << "f(x) = ";
        std::cout << this->coefficients[0];
        int i = 1;
        while (*&(this->coefficients[i]))
        {
            p = this->coefficients[i];
            if (p > 0)
                std::cout << " + " << p;
            else
                std::cout << "- " << -p;
            std::cout << "x^" << i + 1;
            i++;
        }
        std::cout << "\n";
    }
    float *get_coeff()
    {
        return this->coefficients;
    }
};
class Quadratic : public Polynomial
{

public:
    Quadratic() {}
    Quadratic(float *coeff) : Polynomial(coeff, 3)
    {
        MathFunction::set_func("Quadratic");
    }
    void afisare()
    {
        int p;
        std::cout << MathFunction::get_func()
                  << "\n";
        std::cout << "f(x) = ";
        std::cout << (Polynomial::get_coeff())[0];
        int i = 1;
        while (*&((Polynomial::get_coeff())[i]))
        {
            p = (Polynomial::get_coeff())[i];
            if (p > 0)
                std::cout << " + " << p;
            else
                std::cout << "- " << -p;
            std::cout << "x^" << i + 1;
            i++;
        }
        std::cout << "\n";
    }
    void print_roots()
    {
    }
};
class Exponential : public MathFunction
{
private:
    const float e = 2.71;
    float constant, exp_coeff;

public:
    Exponential() {}
    Exponential(float constant, float exp_coeff) : constant(constant), exp_coeff(exp_coeff)
    {
        MathFunction::set_func("Exponential");
    }
    void afisare()
    {
        int p;
        std::cout << MathFunction::get_func()
                  << "\n";
        std::cout << "f(x) = " << this->constant << " + " << this->exp_coeff << "e^x";
        std::cout << "\n";
    }
};

class DiscreteFunction : public MathFunction
{

    float x_values[1000];
    float y_values[1000];

public:
    DiscreteFunction() {}
    std::string find_best_aproximation()
    {
    }
};
int main()
{
    int n, termeni, c;
    float coef[10];
    float exp_coeff, consta;
    std::string nume;
    std::cin >> n;
    MathFunction *functii[100];
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> nume;
        if (nume == "Polynomial")
        {
            std::cin >> termeni;
            for (int j = 0; j < termeni; j++)
            {
                std::cin >> coef[j];
            }
            functii[k++] = new Polynomial(coef, termeni);
        }
        if (nume == "Quadratic")
        {
            for (int j = 0; j < 3; j++)
            {
                std::cin >> coef[j];
            }
            functii[k++] = new Quadratic(coef);
        }
        if (nume == "Exponential")
        {
            std::cin >> exp_coeff;
            std::cin >> consta;
            functii[k++] = new Exponential(consta, exp_coeff);
        }
    }
    std::cin >> c;
    if (c == 1)
    {
        for (int i = 0; i < n; i++)
        {
            functii[i]->afisare();
        }
    }
    return 0;
}
