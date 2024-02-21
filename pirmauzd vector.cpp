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
using namespace std;

struct studentas
{
    string vardas;
    string pavarde;
    vector<int> ndrez; //sudaromas vektorius
    int erez;
    double gbalas;
};

void skaitymasisfailo(vector<studentas> &A, char budas, char ivedbudas);
void isvedimas(vector<studentas> &A, char budas);
void pazymiuived(studentas &new_studentas, char budas, int ivedbudas);
void skaiciavimas(studentas &new_studentas, int sum, char budas);
void irasymasifaila(vector<studentas> &A, char budas);
bool rikiavimasgbalas(const studentas &a, const studentas &b);
bool rikiavimasvardas(const studentas &a, const studentas &b);
bool rikiavimaspavarde(const studentas &a, const studentas &b);
void rikiavimas(vector<studentas> &A);

int main()
{
    vector<string> vardai;
    vardai.push_back("Jonas");
    vardai.push_back("Vytautas");
    vardai.push_back("Tomas");
    vardai.push_back("Mindaugas");
    vardai.push_back("Antanas");
    vardai.push_back("Darius");
    vardai.push_back("Rokas");
    vardai.push_back("Matas");
    vardai.push_back("Lukas");

    vector<string> pavardes;
    pavardes.push_back("Kazlauskas");
    pavardes.push_back("Jankauskas");
    pavardes.push_back("Petrauskas");
    pavardes.push_back("Stankevicius");
    pavardes.push_back("Vasiliauskas");
    pavardes.push_back("Vaigauskas");
    pavardes.push_back("Gilys");
    pavardes.push_back("Gavenas");
    pavardes.push_back("Gruodis");

    srand(time(nullptr));

    int ivedbudas;
    cout << "Pasirinkite studentu duomenu ivedimo buda (1 - ivesti duomenis (skaityti is failo), 2 - generuoti pazymius, 3 - generuoti pazymius ir studentus, 4 - baigti darba): ";
    while (!(cin >> ivedbudas) || ivedbudas > 4 || ivedbudas < 1)
    {
        cout << "Iveskite skaiciu (1-4): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    if (ivedbudas != 4)
    {
        char budas;
        cout << "Pasirinkite galutinio balo apskaiciavimo buda (vidurkis (v) ar mediana (m)): ";
        while (!(cin >> budas) || (budas != 'v' && budas != 'm'))
        {
            cout << "Iveskite 'v' arba 'm': ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        char duomskait;
        if (ivedbudas == 1 || ivedbudas == 2){
        cout << "Pasirinkite studentu duomenu skaitymo buda (ivedimas ranka (r) ar skaitymas is failo (f)): ";
        while (!(cin >> duomskait) || (duomskait != 'r' && duomskait != 'f'))
        {
            cout << "Iveskite 'r' arba 'f': ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }}

        vector<studentas> A; //sudaromas vektorius

        if ((ivedbudas == 1 || ivedbudas == 2) && duomskait == 'f')
        {
            skaitymasisfailo(A, budas, ivedbudas);
            rikiavimas(A);
            isvedimas(A, budas);}

        else if ((ivedbudas == 1 || ivedbudas == 2) && duomskait == 'r')
        {
            while (true)
            {
                studentas new_studentas;
                cout << "Iveskite studento varda ir pavarde arba „11“, jeigu norite uzbaigti studentu vedima: ";
                cin >> new_studentas.vardas;
                if (new_studentas.vardas == "11"){
                    break;}
                cin >> new_studentas.pavarde;
                pazymiuived(new_studentas, budas, ivedbudas);
                A.push_back(new_studentas); // pridedamas elementas i gala 
            }
            rikiavimas(A);
            isvedimas(A, budas);
        }
        
        if (ivedbudas == 3)
        {
            int m;
            cout << "Iveskite studentu skaiciu: ";
            while (!(cin >> m) || m <= 0)
            {
                cout << "Iveskite skaiciu didesni uz 0: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            A.resize(m); // nustatyti vektoriaus dydi

            for (int i = 0; i < m; i++)
            {
                studentas new_studentas;
                new_studentas.vardas = vardai[rand() % vardai.size()];
                new_studentas.pavarde = pavardes[rand() % pavardes.size()];
                pazymiuived(new_studentas, budas, ivedbudas);
                A[i] = new_studentas;
            }
            rikiavimas(A);
            isvedimas(A, budas);
        }
    }
    else {return 0;}
    return 0;
}

void skaitymasisfailo(vector<studentas> &A, char budas, char ivedbudas)
{
    int sum = 0;
    ifstream in("studentai1000000.txt");
    if (!in.is_open()) {
        cout << "Nepavyko atidaryti failo." << endl;
        return;
    }

    string eil;
    getline(in, eil);

    while(getline(in, eil)){
        studentas new_studentas;
        sum = 0;
        new_studentas.vardas = eil.substr(0, 25);
        new_studentas.pavarde = eil.substr(25, 25);
        if (ivedbudas == 1)
        {
            string pazymiai = eil.substr(50); // studento pazymiai saugomi kaip string tipo duomenys
            stringstream my_buffer(pazymiai);
            int pazymys;
            while (my_buffer >> pazymys)
            {
                new_studentas.ndrez.push_back(pazymys); // prisikiriamas elementas
                sum += pazymys;
            }
            new_studentas.erez = new_studentas.ndrez.back(); // paskutinis elementas priskiriamas kaip egzamino rezultatas
            new_studentas.ndrez.pop_back();                  // paskutinis elementas istrinamas is namu darbu pazymiu vektoriaus
            sum -= new_studentas.erez; //atimame egzamino reiksme, nes ji buvo prideta prie sumos
            skaiciavimas(new_studentas, sum, budas);
        }
        if (ivedbudas == 2)
        {
            pazymiuived(new_studentas, budas, ivedbudas);
        }

        A.push_back(new_studentas); //studentas idedamas i vektoriu
    }
    in.close();
}

void irasymasifaila(vector<studentas> &A, char budas)
{
    ofstream out("kursiokai.txt");
    if (budas == 'v')
    {
        out << setw(25) << left << "Vardas" << setw(25) << left << "Pavarde" << setw(25) << left << "Galutinis (Vid.)" << endl;
    }
    else if (budas=='m'){
         out << setw(25) << left << "Vardas" << setw(25) << left << "Pavarde" << setw(25) << left << "Galutinis (Med.)" << endl;}
    out << "---------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < A.size(); i++)
    {
        out << setw(25) << left << A[i].vardas << setw(25) << left << A[i].pavarde << setw(25) << left << fixed << setprecision(2) << A[i].gbalas << endl;
    }
    out.close();
}

void isvedimas(vector<studentas> &A, char budas)
{
    char isvedbud;
    cout << "Pasirinkite studentu duomenu isvedimo buda (ekrane (e) ar irasymas i faila (f)): ";
    while (!(cin >> isvedbud) || (isvedbud != 'e' && isvedbud != 'f'))
    {
        cout << "Iveskite 'e' arba 'f': ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if (isvedbud == 'e')
    {
        if (budas == 'v')
        {
            cout << setw(25) << left << "Vardas" << setw(25) << left << "Pavarde" << setw(25) << left << "Galutinis (Vid.)" << endl;
        }
        else if (budas == 'm')
        {
            cout << setw(25) << left << "Vardas" << setw(25) << left << "Pavarde" << setw(25) << left << "Galutinis (Med.)" << endl;
        }
        cout << "---------------------------------------------------------------------------------------------------" << endl;
        for (int i = 0; i < A.size(); i++)
        {
            cout << setw(25) << left << A[i].vardas << setw(25) << left << A[i].pavarde << setw(25) << left << fixed << setprecision(2) << A[i].gbalas << endl;
        }
    }
    else if (isvedbud == 'f')
    {
        irasymasifaila(A, budas);
    }
}

void pazymiuived(studentas &new_studentas, char budas, int ivedbudas)
{
    int sum = 0;
    int pazymys;
    if (ivedbudas == 1){
        cout << "Iveskite studento namu darbu rezultata arba „11“, jeigu norite uzbaigti rezultatu vedima: " << endl;}
    
    while (true)
    {
        if (ivedbudas == 1)
        {
            cout << "Iveskite pazymi nuo 0 iki 10: ";
            if (!(cin >> pazymys))
            {
                cout << "Netinkamas ivesties formatas. ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if (pazymys == 11)
            {
                break;
            }
            if (pazymys < 0 || pazymys > 10)
            {
                cout << "Netinkamas ivesties formatas. ";
                continue;
            }
                
        }

        if (ivedbudas == 2 || ivedbudas == 3)
        {
            pazymys = rand() % 12;
            if (pazymys == 11) {
                break;}
        }
        new_studentas.ndrez.push_back(pazymys); // pridedamas elementas i gala
        sum += pazymys;
    }
    if (ivedbudas == 1)
    {
        cout << "Iveskite studento egzamino rezultata nuo 0 iki 10: ";
        while (!(cin >> new_studentas.erez) || new_studentas.erez < 0 || new_studentas.erez > 10)
        {
            cout << "Netinkamas ivesties formatas. Iveskite pazymi nuo 0 iki 10: " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    if (ivedbudas == 2 || ivedbudas == 3)
    {
        new_studentas.erez = rand() % 11;
    }
    skaiciavimas(new_studentas, sum, budas);
}

void skaiciavimas(studentas &new_studentas, int sum, char budas)
{
    double vid, mediana;
    if (new_studentas.ndrez.size() == 0)
    {
        vid = 0;
        mediana = 0;
    }
    else 
    {
        vid = sum / (new_studentas.ndrez.size() * 1.0);
            
        sort(new_studentas.ndrez.begin(), new_studentas.ndrez.end());
        if (new_studentas.ndrez.size() % 2 == 0) {
            mediana = (new_studentas.ndrez[new_studentas.ndrez.size() / 2 - 1] + new_studentas.ndrez[new_studentas.ndrez.size() / 2]) / 2.0;}
        else {
                mediana = new_studentas.ndrez[new_studentas.ndrez.size() / 2];}
    }

    if (budas == 'v')
    {
        new_studentas.gbalas = 0.4 * vid + 0.6 * new_studentas.erez;
    }
    else if (budas == 'm')
    {
        new_studentas.gbalas = 0.4 * mediana + 0.6 * new_studentas.erez;
    }
    sum = 0;
}

bool rikiavimasgbalas(const studentas &a, const studentas &b)
{
    return a.gbalas > b.gbalas;
}

bool rikiavimasvardas(const studentas &a, const studentas &b)
{
    return a.vardas < b.vardas;
}

bool rikiavimaspavarde(const studentas &a, const studentas &b)
{
    return a.pavarde < b.pavarde;
}

void rikiavimas(vector<studentas> &A)
{
    char rikbudas;
    cout << "Pasirinkite studentu rikiavimo buda (pagal galutinius balus (b), pagal vardus (v) ar pagal pavardes (p)): ";
    while (!(cin >> rikbudas) || (rikbudas != 'b' && rikbudas != 'v' && rikbudas != 'p'))
    {
        cout << "Iveskite 'b', 'v' ar 'p': ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if (rikbudas == 'b') {sort(A.begin(), A.end(), rikiavimasgbalas);}
    else if (rikbudas == 'v') {sort(A.begin(), A.end(), rikiavimasvardas);}
    if (rikbudas == 'p') {sort(A.begin(), A.end(), rikiavimaspavarde);}
}