#include<iostream>
#include<iomanip>
#include<limits>
#include <algorithm>
#include<vector>
using namespace std;

struct studentas
{
    string vardas;
    string pavarde;
    vector<int> ndrez;
    int erez;
    double gbalas;
};

int main()
{
    int m = 0, sum = 0;
    double vid;

    char budas;
    cout << "Pasirinkite galutinio balo apskaiciavimo buda (vidurkis (v) ar mediana (m)): ";
    cin >> budas;

    vector<studentas> A;

    while(true)
    {
        studentas new_studentas;

        sum = 0;
        cout << "Iveskite studento varda ir pavarde arba „11“, jeigu norite uzbaigti studentu vedima: ";
        cin >> new_studentas.vardas;
        if (new_studentas.vardas == "11")
        {
            break;
        }
        cin >> new_studentas.pavarde;

        cout << "Iveskite studento namu darbu rezultata arba „11“, jeigu norite uzbaigti rezultatu vedima: " << endl;
        while (true)
        {
            int pazymys;
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

            new_studentas.ndrez.push_back(pazymys);
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

        cout << "Iveskite studento egzamino rezultata: ";
        while (!(cin >> new_studentas.erez) || new_studentas.erez < 0 || new_studentas.erez > 10) {
            cout << "Netinkamas ivesties formatas. Iveskite pazymi nuo 0 iki 10: " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

        if (budas=='v'){
            new_studentas.gbalas = 0.4 * vid + 0.6 * new_studentas.erez;}
        else if (budas=='m'){
            new_studentas.gbalas = 0.4 * mediana + 0.6 * new_studentas.erez;}

        A.push_back(new_studentas);
        m++;
    }

    if (budas=='v'){
        cout << "Vardas\tPavarde\tGalutinis (Vid.)" << endl;}
    else if (budas=='m'){
        cout << "Vardas\tPavarde\tGalutinis (Med.)" << endl;}
    cout << "-----------------------------------------------------" << endl;
    for (int i = 0; i < m; i++)
    {
        cout << A[i].vardas << "\t" << A[i].pavarde << "\t" << fixed << setprecision(2) << A[i].gbalas << endl;
    }
    return 0;
}