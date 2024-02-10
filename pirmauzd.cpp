#include<iostream>
#include<iomanip>
#include<limits>
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
    int n, m, sum = 0;
    double vid;

    cout << "Iveskite studentu skaiciu (naturalusis skaicius): ";
    while (!(cin >> m) || m <= 0) {
        cout << "Netinkamas ivesties formatas. Iveskite naturaluji skaiciu: " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Iveskite studentu namu darbu pazymiu skaiciu (naturalusis skaicius): ";
    while (!(cin >> n) || n <= 0) {
        cout << "Netinkamas ivesties formatas. Iveskite naturaluji skaiciu: " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    char budas;
    cout << "Pasirinkite galutinio balo apskaiciavimo buda (vidurkis (v) ar mediana (m)): ";
    cin >> budas;

    studentas A[n];
    for(int i = 0; i < m; i++)
    {
        sum = 0;
        cout << "Iveskite studento varda ir pavarde: ";
        cin >> A[i].vardas >> A[i].pavarde;

        A[i].ndrez = new int[n];

        cout << "Iveskite studento " << n << " namu darbu rezultatus: " << endl;
        for (int j = 0; j < n; j++)
        {
            while (!(cin >> A[i].ndrez[j]) || A[i].ndrez[j] < 0 || A[i].ndrez[j] > 10) {
            cout << "Netinkamas ivesties formatas. Iveskite pazymi nuo 0 iki 10: " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            sum += A[i].ndrez[j];
        }
        vid = sum / (n * 1.0);

        sort(A[i].ndrez, A[i].ndrez + n);
        double mediana;
        if (n % 2 == 0) {
            mediana = (A[i].ndrez[n / 2 - 1] + A[i].ndrez[n / 2]) / 2.0;
        } else {
            mediana = A[i].ndrez[n / 2];
        }

        cout << "Iveskite studento egzamino rezultata: ";
        while (!(cin >> A[i].erez) || A[i].erez < 0 || A[i].erez > 10) {
            cout << "Netinkamas ivesties formatas. Iveskite pazymi nuo 0 iki 10: " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

        if (budas=='v'){
            A[i].gbalas = 0.4 * vid + 0.6 * A[i].erez;}
        else if (budas=='m'){
            A[i].gbalas = 0.4 * mediana + 0.6 * A[i].erez;}
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
}