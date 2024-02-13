#include<iostream>
#include<iomanip>
#include<limits>
#include <algorithm>
using namespace std;

struct studentas
{
    string vardas;
    string pavarde;
    int *ndrez;
    int n;
    int erez;
    double gbalas;
};

int main()
{
    srand(time(nullptr));

    string vardai[] = {"Jonas", "Vytautas", "Tomas", "Mindaugas", "Antanas", "Darius", "Rokas", "Matas", "Lukas", "11" };
    string pavardes[] = {"Kazlauskas", "Jankauskas", "Petrauskas", "Stankevicius", "Vasiliauskas", "Vaigauskas", "Gilys", "Gavenas", "Gruodis" };

    int vardaiS = sizeof(vardai) / sizeof(vardai[0]);
    int pavardesS = sizeof(pavardes) / sizeof(pavardes[0]);

    int m = 0, sum = 0;
    double vid, mediana;

    int ivedbudas;
    cout << "Pasirinkite studentu duomenu ivedimo buda (1 - ranka, 2 - generuoti pazymius, 3 - generuoti pazymius ir studentus, 4 - baigti darba): ";
    cin >> ivedbudas;

    if (ivedbudas != 4){
    char budas;
    cout << "Pasirinkite galutinio balo apskaiciavimo buda (vidurkis (v) ar mediana (m)): ";
    cin >> budas;

    studentas* A = nullptr; //masyvui paskiriama dinamine atmintis

    while(true)
    {
        if (A == nullptr){
            A = new studentas[1];
        }
        else {
            studentas *temp = new studentas[m + 1];
            for (int i = 0; i < m; i++){
                temp[i] = A[i];
            }
            delete[] A;
            A = temp;
        }

        sum = 0;
        if (ivedbudas == 1 || ivedbudas == 2)
        {
            cout << "Iveskite studento varda ir pavarde arba „11“, jeigu norite uzbaigti studentu vedima: ";
            cin >> A[m].vardas;
            if (A[m].vardas == "11")
            {
                break;
            }
            cin >> A[m].pavarde;
        }
        if (ivedbudas == 3)
        {
            A[m].vardas = vardai[rand() % vardaiS];
            if (A[m].vardas == "11")
            {
                break;
            }
            A[m].pavarde = pavardes[rand() % pavardesS];
        }
        A[m].ndrez = new int[1];

        if (ivedbudas == 1){
        cout << "Iveskite studento namu darbu rezultata arba „11“, jeigu norite uzbaigti rezultatu vedima: " << endl;}
        while (true)
        {
            int pazymys;
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

            int* temp = new int[A[m].n + 1];
            for (int i = 0; i < A[m].n; i++) {
                temp[i] = A[m].ndrez[i];
                }
            delete[] A[m].ndrez;
            A[m].ndrez = temp;
            A[m].ndrez[A[m].n++] = pazymys;
            sum += pazymys;
        }
        if (A[m].n == 0)
        {
            vid = 0;
            mediana = 0;
        } 
        else
        {
            vid = sum / (A[m].n * 1.0);

        sort(A[m].ndrez, A[m].ndrez + A[m].n);
        if (A[m].n % 2 == 0) {
            mediana = (A[m].ndrez[A[m].n / 2 - 1] + A[m].ndrez[A[m].n / 2]) / 2.0;
        } else {
            mediana = A[m].ndrez[A[m].n / 2];
        }}
        if (ivedbudas == 1)
        {
        cout << "Iveskite studento egzamino rezultata: ";
        while (!(cin >> A[m].erez) || A[m].erez < 0 || A[m].erez > 10) {
            cout << "Netinkamas ivesties formatas. Iveskite pazymi nuo 0 iki 10: " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        if (ivedbudas == 2 || ivedbudas == 3)
        {
            A[m].erez = rand() % 11;
        }
        if (budas=='v'){
            A[m].gbalas = 0.4 * vid + 0.6 * A[m].erez;}
        else if (budas=='m'){
            A[m].gbalas = 0.4 * mediana + 0.6 * A[m].erez;}
            m++;
    }

    if (budas=='v'){
        cout << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << left << "Galutinis (Vid.)" << endl;}
    else if (budas=='m'){
        cout << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << left << "Galutinis (Med.)" << endl;}
    cout << "-----------------------------------------------------" << endl;
    for (int i = 0; i < m; i++)
    {
        cout << setw(20) << left << A[i].vardas << setw(20) << left << A[i].pavarde << setw(20) << left << fixed << setprecision(2) << A[i].gbalas << endl;
        delete[] A[i].ndrez;
    }
    delete[] A;
    }
    else {return 0;}
    return 0;
}