#include <iostream>
#include <math.h>
#include <string>
#include <limits>
#include <iomanip>


class Aeroport{
    protected:
    std::string oras_plecare;
    std::string oras_sosire;
    int ora_plecare;
    int ora_sosire;
    int minut_plecare;
    int minut_sosire;
    float distanta;
    
    public:
    Aeroport(){}
    
    Aeroport(std::string oras_plecare, std::string oras_sosire, int ora_plecare, int ora_sosire,
    int minut_plecare, int minut_sosire,float distanta):oras_plecare(oras_plecare),oras_sosire(oras_sosire),
    ora_plecare(ora_plecare), ora_sosire(ora_sosire), minut_plecare(minut_plecare), 
    minut_sosire(minut_sosire), distanta(distanta){}
    
    std::string get_oras_plecare(){
        return this->oras_plecare;
    }
    
    std::string get_oras_sosire(){
        return this->oras_sosire;
    }
    
    int get_ora_plecare(){
        return this->ora_plecare;
    }
    
    int get_ora_sosire(){
        return this->ora_sosire;
    }
    int get_minut_plecare(){
        return this->minut_plecare;
    }
    int get_minut_sosire(){
        return this->minut_sosire;
    }
    void afisare(){
        std::cout<<oras_plecare<<" - "<<oras_sosire<<std::endl;
        std::cout<<ora_plecare<<":"<<minut_plecare<<" - "<<ora_sosire<<":"<<minut_sosire<<std::endl;
    }
    void afisare2(){
        std::cout<<oras_plecare<<" - "<<oras_sosire<<std::endl;
        
    }
    void set_distanta(float distanta){this->distanta=distanta;}
    
    float get_distanta(){
        return this->distanta;
    }
    
};




int main(){
    int n;//nr avionie
    std::string oras_plecare;
    std::string oras_sosire;
    int ora_plecare;
    int ora_sosire;
    int minut_plecare;
    int minut_sosire;
    int optiune;
    
    std::cin>>n;
    Aeroport ** aeroport_array=nullptr;
    aeroport_array= new Aeroport*[n];
    int k=0;
    for(int i=0;i<n;i++){
        std::cin>>oras_plecare>>oras_sosire;
        std::cin>>ora_plecare>>minut_plecare;
        std::cin>>ora_sosire>>minut_sosire;
         *(aeroport_array+(k++))= new Aeroport(oras_plecare, oras_sosire,ora_plecare, ora_sosire,
         minut_plecare, minut_sosire, 0);
    }
    
    std::cin>>optiune;
    
    if(optiune==1){
        int ch;
        std::cin>>ch;
        if(ch==0){
            for(int i=0;i<n;i++){
                if((*(aeroport_array+i))->get_oras_plecare()=="Bucuresti"){
                    (*(aeroport_array+i))->afisare();
                }
            }
        }
        else{
            for(int i=0;i<n;i++){
                if((*(aeroport_array+i))->get_oras_sosire()=="Bucuresti"){
                    (*(aeroport_array+i))->afisare();
                }
            }
            
        }
    }
    
    if(optiune==2){
        int ora2_plecare;
        int ora2_sosire;
        int minut2_plecare;
        int minut2_sosire;
        
        std::cin>>ora2_plecare>>minut2_plecare;
        std::cin>>ora2_sosire>>minut2_sosire;
        
        for(int i=0;i<n;i++){
            if((*(aeroport_array+i))->get_ora_sosire()<ora2_sosire &&
            (*(aeroport_array+i))->get_ora_plecare()>ora2_plecare){
                (*(aeroport_array+i))->afisare();
            }
            
            if((*(aeroport_array+i))->get_ora_sosire()==ora2_sosire &&
                (*(aeroport_array+i))->get_minut_sosire()<minut2_sosire &&
                (*(aeroport_array+i))->get_ora_plecare()==ora2_plecare &&
                (*(aeroport_array+i))->get_minut_plecare()>minut2_plecare){
                    (*(aeroport_array+i))->afisare();
                }
            if((*(aeroport_array+i))->get_ora_sosire()==ora2_sosire &&
                (*(aeroport_array+i))->get_minut_sosire()<minut2_sosire &&
                (*(aeroport_array+i))->get_ora_plecare()>ora2_plecare){
                    (*(aeroport_array+i))->afisare();
                }
                
            if((*(aeroport_array+i))->get_ora_sosire()<ora2_sosire &&
                (*(aeroport_array+i))->get_ora_plecare()==ora2_plecare &&
                (*(aeroport_array+i))->get_minut_plecare()>minut2_plecare){
                    (*(aeroport_array+i))->afisare();
                }
            }
        }
        
    
        
    if(optiune==3){
        float nr_ore_zbor;
        float nr_minute_zbor;
        float durata;
        float distanta;
        float viteza=0;
        for(int i=0;i<n;i++){
            std::cin>>distanta;
            (*(aeroport_array+i))->set_distanta(distanta);
        }
        
         for(int i=0;i<n;i++){
             nr_ore_zbor=((*(aeroport_array+i))->get_ora_sosire()-(*(aeroport_array+i))->get_ora_plecare());
             if((*(aeroport_array+i))->get_minut_plecare()>(*(aeroport_array+i))->get_minut_sosire()){
                 nr_ore_zbor=nr_ore_zbor-1;
                 nr_minute_zbor=(60-(*(aeroport_array+i))->get_minut_plecare()+(*(aeroport_array+i))->get_minut_sosire());
                 durata=nr_ore_zbor*60+nr_minute_zbor;
                 viteza=(*(aeroport_array+i))->get_distanta()/durata*60;
                 (*(aeroport_array+i))->afisare();
                 std::cout<<std::fixed;
                 std::cout<<std::setprecision(2)<<viteza<<std::endl;
                 

             }
             else{
                 nr_minute_zbor=((*(aeroport_array+i))->get_minut_sosire()-(*(aeroport_array+i))->get_minut_plecare());
                 durata=nr_ore_zbor*60+nr_minute_zbor;
                 viteza=(*(aeroport_array+i))->get_distanta()/durata*60;
                 (*(aeroport_array+i))->afisare();
                 std::cout<<std::fixed;
                 std::cout<<std::setprecision(2)<<viteza<<std::endl;
                 
                 
             }
         }
        
        
    }
    
    if(optiune==4){
        float nr_ore_zbor;
        float nr_minute_zbor;
        float durata;
        float distanta;
        float profit;
        float castiguri;
        float costuri;
        
        for(int i=0;i<n;i++){
            std::cin>>distanta;
            (*(aeroport_array+i))->set_distanta(distanta);
        }
        
         for(int i=0;i<n;i++){
             nr_ore_zbor=((*(aeroport_array+i))->get_ora_sosire()-(*(aeroport_array+i))->get_ora_plecare());
             if((*(aeroport_array+i))->get_minut_plecare()>(*(aeroport_array+i))->get_minut_sosire()){
                 nr_ore_zbor=nr_ore_zbor-1;
                 nr_minute_zbor=(60-(*(aeroport_array+i))->get_minut_plecare()+(*(aeroport_array+i))->get_minut_sosire());
                 durata=nr_ore_zbor*60+nr_minute_zbor;
                 costuri=(10000*durata/60);
                 castiguri=(400*0.15*(*(aeroport_array+i))->get_distanta());
                 profit=castiguri-costuri;
                 (*(aeroport_array+i))->afisare2();
                 std::cout<<std::fixed;
                 std::cout<<std::setprecision(2);
                 std::cout<<profit<<std::endl;
                 

             }
             else{
                 nr_minute_zbor=((*(aeroport_array+i))->get_minut_sosire()-(*(aeroport_array+i))->get_minut_plecare());
                 durata=nr_ore_zbor*60+nr_minute_zbor;
                 costuri=(10000*(durata/60));
                 castiguri=(400*0.15*(*(aeroport_array+i))->get_distanta());
                 profit=castiguri-costuri;
                 (*(aeroport_array+i))->afisare2();
                 std::cout<<std::fixed;
                 std::cout<<std::setprecision(2);
                 std::cout<<profit<<std::endl;
                 
                 
             }
         }
        
        
    }
    
    
    
    
    
    return 0;
}
