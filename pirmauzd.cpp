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
    int erez;
    double gbalas;
};

int main()
{
    int n = 0, m = 0, sum = 0;
    double vid;

    // cout << "Iveskite studentu skaiciu (naturalusis skaicius): ";
    // while (!(cin >> m) || m <= 0) {
    //     cout << "Netinkamas ivesties formatas. Iveskite naturaluji skaiciu: " << endl;
    //     cin.clear();
    //     cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // }

    // cout << "Iveskite studentu namu darbu pazymiu skaiciu (naturalusis skaicius): ";
    // while (!(cin >> n) || n <= 0) {
    //     cout << "Netinkamas ivesties formatas. Iveskite naturaluji skaiciu: " << endl;
    //     cin.clear();
    //     cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // }

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
        cout << "Iveskite studento varda ir pavarde arba „11“, jeigu norite uzbaigti studentu vedima: ";
        cin >> A[m].vardas >> A[m].pavarde;
        if (A[m].vardas == "11")
        {
            break;
        }

        cout << "Iveskite studento namu darbu rezultatus (0-10) arba „11“, jeigu norite uzbaigti rezultatu vedima: " << endl;
        A[m].ndrez = new int[1];
        while (true){
            int pazymys;
            cin >> pazymys;
            if (pazymys == 11) {
                break;
            }
            while (pazymys < 0 || pazymys > 10)
            {
                cout << "Netinkamas ivesties formatas. Iveskite pazymi nuo 0 iki 10: " << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> pazymys;
            }
            int *temp = new int[n + 1];
            for (int i = 0; i < n; i++){
                temp[i] = A[m].ndrez[i];
            }
            delete[] A[m].ndrez;
            A[m].ndrez[n++] = pazymys;
            sum += pazymys;
        }
        vid = sum / (n * 1.0);

        sort(A[m].ndrez, A[m].ndrez + n);
        double mediana;
        if (n % 2 == 0) {
            mediana = (A[m].ndrez[n / 2 - 1] + A[m].ndrez[n / 2]) / 2.0;
        } else {
            mediana = A[m].ndrez[n / 2];
        }

        cout << "Iveskite studento egzamino rezultata: ";
        while (!(cin >> A[m].erez) || A[m].erez < 0 || A[m].erez > 10) {
            cout << "Netinkamas ivesties formatas. Iveskite pazymi nuo 0 iki 10: " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

        if (budas=='v'){
            A[m].gbalas = 0.4 * vid + 0.6 * A[m].erez;}
        else if (budas=='m'){
            A[m].gbalas = 0.4 * mediana + 0.6 * A[m].erez;}
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
        delete[] A[i].ndrez;
    }
    delete[] A;
    return 0;
}