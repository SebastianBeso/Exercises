#include <iostream>
#include <string>
#include <limits>
#include <math.h>

//Clasa de Baza
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

        // float get_value(int value){
        //     return this->value;
        // }

        // float get_max_value(int value1, int value2){

        //     if(value1>value2)
        //         return value1;
        //     if(value2>value1)
        //         return value2;
        // }

        //Getter si Setter
        // void get_function_name(){return this->function_name;}

};


//Clasa derivata din Baza
class DiscreteFunction: public MathFunction{

    //Date membre
    protected:
        float x_values[100];
        float y_values[100];

    //Constructor
    public:

        //Constructor Gol
        DiscreteFunction(){}

        //Constructor cu Lista de Initializare
        DiscreteFunction(std::string function_name, float x_value[], float y_values[]): MathFunction(function_name){


        }

    //Functii
    public:
        // std::string find_best_approximation(){}


};


//Clasa din Derivata din Baza
class Exponential: public MathFunction{


    //Date membre
    private:
        float e;
        float constant;
        float exp_coeff;


    //Constructor
    public:

        //Constructor Gol
        Exponential(){};

        //Constructor cu Lista de Initializare
        Exponential(float e=0, float constant=0, float exp_coeff=0, std::string function_name="")
        :MathFunction(function_name), e(e), constant(constant), exp_coeff(exp_coeff){}



    //Functii
    public:

        void display(){

            std::cout<<function_name<<std::endl;
        }




};

//Clasa Derivata din Baza
class Polynomial: public MathFunction{

    //Date membre
    protected:
        float coefficients[10];
        int lungime;

    //Constructor
    public:

        Polynomial(){}

        Polynomial(float coefficients[10], int lungime, std::string function_name)
        :MathFunction(function_name), lungime(lungime){

            for(int i=0; i<lungime; i++){
                this->coefficients[i]=coefficients[i];
            }
        }

    //Functii
    public:

    void display()
    {

        std::cout<<"f(x) = ";
        for(int i=0; i<lungime;i++)
        {

            if(coefficients[i] == 0)
            continue;

            if(i == 0)
            {
                std::cout<<coefficients[i]<<' ';
            }
            else
            {
                if(coefficients[i] > 0)
                {
                    if(coefficients[i]!=1)
                        std::cout<<" + "<<abs(coefficients[i]);
                    else std::cout<<" + ";

                    if(i == 1)
                    {
                        std::cout<<"x";
                    }
                    else
                    {
                        std::cout<<"x^"<<i<<" ";
                    }
                }
                else if(coefficients[i] < 0)
                {
                    if(coefficients[i]!=1)
                        std::cout<<" - "<<abs(coefficients[i]);
                    else std::cout<<" - ";
                    if(i == 1)
                    {
                        std::cout<<"x";
                    }
                    else
                    {
                        std::cout<<"x^"<<i<<" ";
                    }
                }
            }

        }

    }


};


//Clasa Derivata din Polynomial
class Quadratic: public Polynomial{


    //Date membre
    public:
        int a1;
        int a2;
        int a3;

    public:
        Quadratic(){}

        Quadratic(int a1, int a2, int a3):a1(a1), a2(a2), a3(a3){}

    //Functii
    public:
        void print_roots(void){}

        void display()
        {





        }


};





//Functia main
int main()
{
    //Initializam Date
    int numar_functii;
    std::cin>>numar_functii;

    int numar_valori;

    int flag_p=0, flag_c=0, flag_e=0, flag_d=0;

    for(int i=0; i<numar_functii; i++){

        std::string function_name;
        std::cin>>function_name;

        //Polynomial
        if(function_name=="Polynomial"){
            flag_p=1;

            std::cin>>numar_valori;
            float coefficients[10];
            for(int j=0; j<numar_valori; j++){
                    std::cin>>coefficients[j];
            }
            Polynomial P(coefficients, numar_valori, function_name);
            P.display();
        }

        if(function_name=="Quadratic"){

            flag_c=1;
            int a1;
            int a2;
            int a3;

            std::cin>>a1;
            std::cin>>a2;
            std::cin>>a3;

            Quadratic q(a1,a2,a3);
        }

        if(function_name=="Exponential"){

            flag_e=1;
            const float e=2.71;
            float constant;
            float exp_coeff;

            std::cin>>constant;
            std::cin>>exp_coeff;

            Exponential exp(e, constant, exp_coeff);

        }


    }



    //Optiuni
    int optiune;
    std::cin>>optiune;

    if(optiune==1){

        if(flag_p)
        {


        }
        else if(flag_c)
        {



        }
        else if(flag_e)
        {



        }


    }




    return 0;
}
