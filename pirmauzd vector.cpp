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
    vardai.push_back("11");

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

    int sum = 0;
    double vid;

    srand(time(nullptr));

    int ivedbudas;
    cout << "Pasirinkite studentu duomenu ivedimo buda (1 - ranka, 2 - generuoti pazymius, 3 - generuoti pazymius ir studentus, 4 - baigti darba): ";
    cin >> ivedbudas;
    if (ivedbudas != 4){
    char budas;
    cout << "Pasirinkite galutinio balo apskaiciavimo buda (vidurkis (v) ar mediana (m)): ";
    cin >> budas;

    vector<studentas> A; //sudaromas vektorius
    
        while (true)
        {
            studentas new_studentas;

            sum = 0;
            if (ivedbudas == 1 || ivedbudas == 2)
            {
                cout << "Iveskite studento varda ir pavarde arba „11“, jeigu norite uzbaigti studentu vedima: ";
                cin >> new_studentas.vardas;
                if (new_studentas.vardas == "11")
                {
                    break;
                }
                cin >> new_studentas.pavarde;
            }

            if (ivedbudas == 3)
            {
                new_studentas.vardas = vardai[rand() % vardai.size()];
                if (new_studentas.vardas == "11")
                {
                    break;
                }
                new_studentas.pavarde = pavardes[rand() % pavardes.size()];
            }

            int pazymys;
        if (ivedbudas == 1)
        {
            cout << "Iveskite studento namu darbu rezultata arba „11“, jeigu norite uzbaigti rezultatu vedima: " << endl;}
        while (true)
        {
            if (ivedbudas == 1){
            cout << "Iveskite pazymi nuo 0 iki 10: ";
            if (!(cin >> pazymys))
            {
                cout << "Netinkamas ivesties formatas. ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if (pazymys == 11) {
                break;}
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
        vid = sum / (new_studentas.ndrez.size() * 1.0);

        sort(new_studentas.ndrez.begin(), new_studentas.ndrez.end());
        double mediana;
        if (new_studentas.ndrez.size() % 2 == 0) {
            mediana = (new_studentas.ndrez[new_studentas.ndrez.size() / 2 - 1] + new_studentas.ndrez[new_studentas.ndrez.size() / 2]) / 2.0;
        }
        else
        {
            mediana = new_studentas.ndrez[new_studentas.ndrez.size() / 2];
        }
        if (ivedbudas == 1)
        {
        cout << "Iveskite studento egzamino rezultata nuo 0 iki 10: ";
        while (!(cin >> new_studentas.erez) || new_studentas.erez < 0 || new_studentas.erez > 10) {
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

        A.push_back(new_studentas); // pridedamas elementas i gala
    }

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
    else {return 0;}
    return 0;
}