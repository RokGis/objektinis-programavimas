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

    studentas() : ndrez(nullptr), n(0) {}
};

void isvedimas(studentas *A, char budas, int m);
void pazymiuived(studentas *A, char budas, int i, int ivedbudas);

int main()
{
    srand(time(nullptr));

    string vardai[] = {"Jonas", "Vytautas", "Tomas", "Mindaugas", "Antanas", "Darius", "Rokas", "Matas", "Lukas"};
    string pavardes[] = {"Kazlauskas", "Jankauskas", "Petrauskas", "Stankevicius", "Vasiliauskas", "Vaigauskas", "Gilys", "Gavenas", "Gruodis" };

    int vardaiS = sizeof(vardai) / sizeof(vardai[0]);
    int pavardesS = sizeof(pavardes) / sizeof(pavardes[0]);

    int m = 0;

    int ivedbudas;
    cout << "Pasirinkite studentu duomenu ivedimo buda (1 - ranka, 2 - generuoti pazymius, 3 - generuoti pazymius ir studentus, 4 - baigti darba): ";
    while (!(cin >> ivedbudas) || ivedbudas > 4 || ivedbudas < 1)
    {
        cout << "Iveskite skaiciu (1-4): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (ivedbudas != 4){
    char budas;
    cout << "Pasirinkite galutinio balo apskaiciavimo buda (vidurkis (v) ar mediana (m)): ";
    while (!(cin >> budas) || (budas != 'v' && budas != 'm')) {
        cout << "Iveskite 'v' arba 'm': ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (ivedbudas == 1 || ivedbudas == 2)
        {
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

        cout << "Iveskite studento varda ir pavarde arba „11“, jeigu norite uzbaigti studentu vedima: ";
        cin >> A[m].vardas;
        if (A[m].vardas == "11")
        {
            break;
        }
        cin >> A[m].pavarde;

        A[m].ndrez = new int[1];

        if (ivedbudas == 1){
        cout << "Iveskite studento namu darbu rezultata arba „11“, jeigu norite uzbaigti rezultatu vedima: " << endl;
        }
        pazymiuived(A, budas, m, ivedbudas);
        m++;
    }
    isvedimas(A, budas, m);
        }

        if (ivedbudas == 3)
        {
            cout << "Iveskite studentu skaiciu: ";
            while (!(cin >> m) || m <= 0)
            {
                cout << "Iveskite skaiciu didesni uz 0: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            studentas A[m];
            for (int i = 0; i < m; i++)
            {
                A[i].vardas = vardai[rand() % vardaiS];
                A[i].pavarde = pavardes[rand() % pavardesS];
                pazymiuived(A, budas, i, ivedbudas);
            }
            isvedimas(A, budas, m);
        }
    }
    else {return 0;}
    return 0;
}
void isvedimas(studentas *A, char budas, int m)
{
    if (budas=='v'){
        cout << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << left << "Galutinis (Vid.)" << endl;}
    else if (budas=='m'){
        cout << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << left << "Galutinis (Med.)" << endl;}
    cout << "-----------------------------------------------------" << endl;
    for (int i = 0; i < m; i++)
    {
        
        cout << setw(20) << left << A[i].vardas << setw(20) << left << A[i].pavarde << setw(20) << left << fixed << setprecision(2) << A[i].gbalas << endl;
    }
}

void pazymiuived(studentas *A, char budas, int i, int ivedbudas)
{
    int sum = 0;
    double vid, mediana;
    if (A[i].ndrez == nullptr) {
        A[i].ndrez = new int[1];
    }

    if (ivedbudas == 1)
    {
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

            int* temp = new int[A[i].n + 1];
            for (int j = 0; j < A[i].n; j++) {
                temp[j] = A[i].ndrez[j];
                }
            delete[] A[i].ndrez;
            A[i].ndrez = temp;
            A[i].ndrez[A[i].n++] = pazymys;
            sum += pazymys;
        }
        if (A[i].n == 0)
        {
            vid = 0;
            mediana = 0;
        } 
        else
        {
            vid = sum / (A[i].n * 1.0);

        sort(A[i].ndrez, A[i].ndrez + A[i].n);
        if (A[i].n % 2 == 0) {
            mediana = (A[i].ndrez[A[i].n / 2 - 1] + A[i].ndrez[A[i].n / 2]) / 2.0;
        } else {
            mediana = A[i].ndrez[A[i].n / 2];
        }}
        if (ivedbudas == 1)
        {
        cout << "Iveskite studento egzamino rezultata: ";
        while (!(cin >> A[i].erez) || A[i].erez < 0 || A[i].erez > 10) {
            cout << "Netinkamas ivesties formatas. Iveskite pazymi nuo 0 iki 10: " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        if (ivedbudas == 2 || ivedbudas == 3)
        {
            A[i].erez = rand() % 11;
        }
        if (budas=='v'){
            A[i].gbalas = 0.4 * vid + 0.6 * A[i].erez;}
        else if (budas=='m'){
            A[i].gbalas = 0.4 * mediana + 0.6 * A[i].erez;}
        delete[] A[i].ndrez;
 }