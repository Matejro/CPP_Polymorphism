#pragma once
#include <string.h>
#include <iostream>
using namespace std;

class Samochod {
protected:
    char* marka;
    float poj_baku;
    float predkosc_max;
    float zuzycie_paliwa;
public:
    Samochod(const char* r, int b, int p, int z) {
        this->marka = new char[strlen(r) + 1];
        strcpy(this->marka, r);
        this->poj_baku = b;
        this->predkosc_max = p;
        this->zuzycie_paliwa = z;
    };

    void jedz(float jakSzybko, float jakDaleko) const {
        if (jakSzybko > this->predkosc_max) {
            cout << "Ten samoch�d nie jest taki szybki";
        }
        else {
            cout << "Samoch�d pojedzie z pr�dko�cia " << jakSzybko << " i bedzie musial tankowac po drodze " << (float)((this->zuzycie_paliwa * jakDaleko / 100) / this->poj_baku) << " razy.\n";
        }
    }

};
class Kabriolet : public Samochod {

public:
    bool dach_otwarty;
    Kabriolet(const char* r, int b, int p, int z) :Samochod(r, b, p, z) { this->dach_otwarty = false; };
    void jedz(float jakSzybko, float jakDaleko) const {
        if (jakSzybko > this->predkosc_max) {
            cout << "Ten samoch�d nie jest taki szybki";
        }
        else if (this->dach_otwarty == true) {
            cout << "Samoch�d pojedzie z pr�dko�cia " << jakSzybko << " i bedzie musial tankowac po drodze " << (float)((this->zuzycie_paliwa * 1.15 * jakDaleko / 100) / this->poj_baku) << " razy.\n";
        }
        else {
            cout << "Samoch�d pojedzie z pr�dko�cia " << jakSzybko << " i bedzie musial tankowac po drodze " << (float)((this->zuzycie_paliwa * jakDaleko / 100) / this->poj_baku) << " razy.\n";
        }
    }
    void otworz_dach() { dach_otwarty = true; };
    void zamknij_dach() { dach_otwarty = false; };

};

class Figura {

public:
    Figura() {};
    virtual string nazwa() { return ""; }
    virtual float pole() { return 0; }
    virtual void wypisz() { cout << nazwa() << " o polu " << pole() << endl; }
};

class Kolo : public Figura {
public:
    float prom=0;

    virtual string nazwa() { return typeid(this).name(); }
    virtual float pole() { return prom * prom * 3.14; }
    void ustawPromien(float a) { prom = a; }
    float promien() { return prom; }

};