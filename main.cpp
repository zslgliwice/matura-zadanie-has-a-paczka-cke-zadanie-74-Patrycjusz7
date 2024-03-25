#include <iostream>
#include <fstream>
#include <sstream>

// Funkcja do obliczania sumy cyfr liczby
int sumaCyfr(int liczba)
{
    int suma=0;
    while(liczba>0) 
    {
        suma+=liczba%10;
        liczba/=10;
    }
    return suma;
}

int main() 
{
    std::ifstream plik("trojki.txt");
    if(!plik) 
    {
        std::cerr<<"Nie udało się otworzyć pliku." << std::endl;
        return 1;
    }

    int liczba1, liczba2, liczba3;
    while(plik >> liczba1 >> liczba2 >> liczba3) 
    {
        int suma1=sumaCyfr(liczba1);
        int suma2=sumaCyfr(liczba2);
        if(suma1+suma2==liczba3) 
        {
            std::cout<<"Znaleziono trojkę spełniającą warunek: "<<std::endl;
            std::cout<<"Liczba 1: " << liczba1<<std::endl;
            std::cout<<"Liczba 2: " << liczba2<<std::endl;
            std::cout<<"Liczba 3: " << liczba3<<std::endl;
            std::cout<<"Suma cyfr liczby 1: "<<suma1<<std::endl;
            std::cout<<"Suma cyfr liczby 2: "<<suma2<<std::endl;
            std::cout<<"Równanie sumy cyfr: "<<suma1<<" + "<<suma2<<" = "<<liczba3<<std::endl;
        }
    }

    plik.close();
    return 0;
}
