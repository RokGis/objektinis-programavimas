#include <iostream>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct studentas
{
    string vardas;
    string pavarde;
    deque<int> ndrez; //sudaromas vektorius
    int erez;
    double gbalas;
};

struct kietiakas
{
    string vardas;
    string pavarde;
    double gbalas;
};

struct vargsiukas
{
    string vardas;
    string pavarde;
    double gbalas;
};

extern int tlaikas;

void skaitymasisfailo(deque<studentas> &A, char budas, char ivedbudas);
void isvedimas(deque<studentas> &A, char budas);
void pazymiuived(studentas &new_studentas, char budas, int ivedbudas);
void skaiciavimas(studentas &new_studentas, int sum, char budas);
void irasymasifaila(deque<studentas> &A, char budas);
bool rikiavimasgbalas(const studentas &a, const studentas &b);
bool rikiavimasvardas(const studentas &a, const studentas &b);
bool rikiavimaspavarde(const studentas &a, const studentas &b);
void rikiavimas(deque<studentas> &A);
void skirstymas(deque<studentas> &A, deque<kietiakas> &K, deque<vargsiukas> &V);
void irasymasifailaK(deque<kietiakas> &K, deque<vargsiukas> &V, char budas);