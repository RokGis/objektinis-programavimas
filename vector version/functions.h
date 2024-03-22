#include <iostream>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <vector>
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
    vector<int> ndrez; //sudaromas vektorius
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

void skaitymasisfailo(vector<studentas> &A, char budas, char ivedbudas);
void isvedimas(vector<studentas> &A, char budas);
void pazymiuived(studentas &new_studentas, char budas, int ivedbudas);
void skaiciavimas(studentas &new_studentas, int sum, char budas);
void irasymasifaila(vector<studentas> &A, char budas);
bool rikiavimasgbalas(const studentas &a, const studentas &b);
bool rikiavimasvardas(const studentas &a, const studentas &b);
bool rikiavimaspavarde(const studentas &a, const studentas &b);
void rikiavimas(vector<studentas> &A);
void skirstymas(vector<studentas> &A, vector<kietiakas> &K, vector<vargsiukas> &V);
void irasymasifailaK(vector<studentas> &A, vector<kietiakas> &K, vector<vargsiukas> &V, char budas);