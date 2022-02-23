// Lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Header.h"
#include <vector>
#include <array>

using namespace std;


class Ssak {
protected:
    
public:
    Ssak() {};
    ~Ssak() {}
    virtual void Jedz() const {}
    virtual void Mow() const {}
    };

class Pies : public Ssak {
public:
    char* rasa;
    Pies(const char* a) : Ssak() {
        this->rasa = new char[strlen(a) + 1];
        strcpy(this->rasa, a);
    };
    ~Pies(){ delete[] this->rasa; }
    virtual void Jedz() const { cout << "Pies zjada jedzenie\n"; }
    virtual void Mow() const { cout << "Hau Hau\n"; }
};

class Kotek : public Ssak {
private:
    long waga;
public:
    Kotek(long kilo) : Ssak() {
        waga = kilo;
    };
    ~Kotek() {};
    virtual void Jedz() const { cout << "Kotek zjada jedzenie\n"; }
    virtual void Mow() const { cout << "Miau Miau\n"; }
    void JemWszystkoOproczSiana() { cout << "Kotek zjada wszystko ale bez sianka.\n"; }
    long SprawdzWage() { return this->waga;}
    float PijWode() { return 0.5; }

};

class Krowa : public Ssak {
private:
    long waga;
public:
    Krowa(long kilo) : Ssak() {
        waga = kilo;
    };
    ~Krowa() {};
    virtual void Jedz() const { cout << "Krowa zjada jedzenie\n"; }
    virtual void Mow() const { cout << "Muuuuu\n"; }
    int jemSiano() { return 80; }
    long SprawdzWage() { return this->waga; }
    float PijWode() { return 3.0; }

};

class Owca : public Ssak {
private:
    long waga;
public:
    Owca(long kilo) : Ssak() {
        waga = kilo;
    };
    ~Owca() {};
    virtual void Jedz() const { cout << "Owca zjada jedzenie\n"; }
    virtual void Mow() const { cout << "Meeee\n"; }
    int jemSiano() { return 40; }
    long SprawdzWage() { return this->waga; }
    float PijWode() { return 2.0; }

};

class Kot : public Ssak {
public:
    char* rasa;
    Kot(const char* b) : Ssak() {
        this->rasa = new char[strlen(b) + 1];
        strcpy(this->rasa, b);
    };
    ~Kot(){ delete[] this->rasa; }
    virtual void Jedz() const { cout << "Kot zjada jedzenie\n"; }
    void Mow() const { cout << "Miau Miau\n"; }
};

class Husky : public Pies {
public:
    char* rasa;
    Husky(const char* c) : Pies(c) {
        this->rasa = new char[strlen(c) + 1];
        strcpy(this->rasa, c);
    };
    ~Husky() { delete[] this->rasa; }
    virtual void Mow() const { cout << "Hau Hau\n"; }
    virtual void Jedz() const { cout << "Husky zjada jedzenie\n"; }
    virtual void Biegaj() const { cout << "Husky biega\n"; }
};

int main()
{
    Kotek k1(2);
    Kotek k2(2.5);
    Owca o1(100);
    Owca o2(120);
    Krowa k(400);
    std::cout << "Hello World!\n";
    array<const Ssak*, 5>  my_array{ &k1, &k2,&k,&o1,&o2 };
    int i = 0;
    float wypita_woda = 0;
    int zjedzone_siano = 0;
    int waga_min = 0;
    for (const auto& x : my_array) {
        const Kotek* k1 = dynamic_cast<const Kotek*>(my_array[i]);
        const Owca* o1 = dynamic_cast<const Owca*>(my_array[i]);
        const Krowa* k = dynamic_cast<const Krowa*>(my_array[i]);
        if (k1) {
            wypita_woda+=static_cast<Kotek>(*k1).PijWode();
            cout << static_cast<Kotek>(*k1).PijWode();
            if (i == 0) {
                waga_min = static_cast<Kotek>(*k1).SprawdzWage();
            }
            else {
                if (waga_min > static_cast<Kotek>(*k1).SprawdzWage()) {
                    waga_min = static_cast<Kotek>(*k1).SprawdzWage();
                }
            }
        }
        else if (o1) {
            wypita_woda += static_cast<Owca>(*o1).PijWode();
            zjedzone_siano += static_cast<Owca>(*o1).jemSiano();
            if (i == 0) {
                waga_min = static_cast<Owca>(*o1).SprawdzWage();
            }
            else {
                if (waga_min > static_cast<Owca>(*o1).SprawdzWage()) {
                    waga_min = static_cast<Owca>(*o1).SprawdzWage();
                }
            }
        }
        else {
            wypita_woda += static_cast<Krowa>(*k).PijWode();
            zjedzone_siano += static_cast<Krowa>(*k).jemSiano();
            if (i == 0) {
                waga_min = static_cast<Krowa>(*k).SprawdzWage();
            }
            else {
                if (waga_min > static_cast<Krowa>(*k).SprawdzWage()) {
                    waga_min = static_cast<Krowa>(*k).SprawdzWage();
                }
            }
        }
        i++;
    }

    cout << "Wypito " << wypita_woda << " litrow wody podczas jednego pojenia\n";
    cout << "Zjedzono " << zjedzone_siano << " jednostek siana podczas jednego karmienia\n";
    cout << "Najlzejsze zwierze wazy " << waga_min <<"kg"<<endl;


  
    
   
    

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
