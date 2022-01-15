#include <iostream>
#include <string>
#include <limits>
#include <math.h>

//Clasa din Baza
class MathFunction{

    //Date membre
    protected:
        std::string function_name;

    //Constructor
    public:

        //Constructor Gol
        MathFunction(){}

        //Constructor cu Lista de Initializare
        MathFunction(std::string function_name): function_name(function_name){}


    //Functii
    public:

        //Setters si Getters
        void set_func(std::string name){this->function_name = name;}
        std::string get_func(){return this->function_name;}


        float get_value(int x){
            return x;
        }

        float get_max_value(int x, int y){
            return x;
        }

        virtual void afisare(){}
};


//Clasa Derivata din Baza
class Polynomial : public MathFunction{

    //Date membre
    protected:
        float *coefficients;

    //Constructor
    public:

        //Constructor Gol
        Polynomial(){}

        //Constructor cu Lista de Initializare
        Polynomial(float *coeff, int n){

            //Array de elementele ce le contine
            MathFunction::set_func("Polynomial");
            this->coefficients = new float[n + 1];

            for (int i = 0; i < n; i++){
                this->coefficients[i] = coeff[i];
            }
        *&(this->coefficients[n]) = NULL;
    }

    //Functii
    public:
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


//Clasa Derivata din Polynomial
class Quadratic : public Polynomial{

    //Constructor
    public:

        //Constructor Gol
        Quadratic(){}

        //Constructor cu Lista de Initializare
        Quadratic(float *coeff) : Polynomial(coeff, 3)
        {
            MathFunction::set_func("Quadratic");
        }

    //Functii
    public:
        void afisare(){
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

        void print_roots(){
        }
};

//Clasa Derivata din Baza
class Exponential : public MathFunction{

    //Date membre
    private:
        const float e = 2.71;
        float constant, exp_coeff;

    //Constructor
    public:

        //Constructor Gol
        Exponential(){}

        //Constructor cu Lista de Initializare
        Exponential(float constant, float exp_coeff) : constant(constant), exp_coeff(exp_coeff)
        {
            MathFunction::set_func("Exponential");
        }

    //Functii
    public:
        void afisare()
        {
            int p;
            std::cout << MathFunction::get_func()
                      << "\n";
            std::cout << "f(x) = " << this->constant << " + " << this->exp_coeff << "e^x";
            std::cout << "\n";
        }
};


//Clasa Derivata din Baza
class DiscreteFunction : public MathFunction{

    //Date membre
    public:
        float x_values[1000];
        float y_values[1000];

    //Constructor
    public:
        DiscreteFunction() {}
        std::string find_best_aproximation()
        {
        }

};



//Functia main
int main(){


    //Initializam Date
    int n, termeni, c;
    float coef[10];
    float exp_coeff, consta;
    std::string nume;
    std::cin >> n;

    //Facem Array de Obiecte (Toate sunt diferite)
    MathFunction *functii[100];
    int k = 0;

    //Generator de Obiecte
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


    //Optiuni
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
