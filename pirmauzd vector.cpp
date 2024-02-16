#include <iostream>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

struct studentas
{
    string vardas;
    string pavarde;
    vector<int> ndrez; //sudaromas vektorius
    int erez;
    double gbalas;
};

void isvedimas(const vector<studentas> &A, char budas);
void pazymiuived(studentas &new_studentas, char budas, int ivedbudas);

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
    cout << "Pasirinkite studentu duomenu ivedimo buda (1 - ranka, 2 - generuoti pazymius, 3 - generuoti pazymius ir studentus, 4 - baigti darba): ";
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

        vector<studentas> A; //sudaromas vektorius
        
        if (ivedbudas == 1 || ivedbudas == 2)
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

            isvedimas(A, budas);
        }
    }
    else {return 0;}
    return 0;
}
void isvedimas(const vector<studentas>& A, char budas)
{
    if (budas=='v'){
        cout << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << left << "Galutinis (Vid.)" << endl;}
    else if (budas=='m'){
         cout << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << left << "Galutinis (Med.)" << endl;}
    cout << "-----------------------------------------------------" << endl;
    for (int i = 0; i < A.size(); i++)
    {
        cout << setw(20) << left << A[i].vardas << setw(20) << left << A[i].pavarde << setw(20) << left << fixed << setprecision(2) << A[i].gbalas << endl;
    }
}

void pazymiuived(studentas& new_studentas, char budas, int ivedbudas)
{
    int sum = 0;
    double vid, mediana;
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

    if (budas == 'v')
    {
        new_studentas.gbalas = 0.4 * vid + 0.6 * new_studentas.erez;
    }
    else if (budas == 'm')
    {
        new_studentas.gbalas = 0.4 * mediana + 0.6 * new_studentas.erez;
    }
}