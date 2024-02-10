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
    while (!(cin >> n) || n <= 0) {
        cout << "Netinkamas ivesties formatas. Iveskite naturaluji skaiciu: " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Iveskite studentu namu darbu pazymiu skaiciu (naturalusis skaicius): ";
    while (!(cin >> m) || m <= 0) {
        cout << "Netinkamas ivesties formatas. Iveskite naturaluji skaiciu: " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    studentas A[n];
    for(int i = 0; i < n; i++)
    {
        sum = 0;
        cout << "Iveskite studento varda ir pavarde: ";
        cin >> A[i].vardas >> A[i].pavarde;
        A[i].ndrez = new int[m];
        cout << "Iveskite studento " << m << " namu darbu rezultatus: " << endl;
        for (int j = 0; j < m; j++)
        {
            while (!(cin >> A[i].ndrez[j]) || A[i].ndrez[j] < 0 || A[i].ndrez[j] > 10) {
            cout << "Netinkamas ivesties formatas arba pazymys neturi buti mazesnis nei 0 arba didesnis nei 10. Iveskite pazymi nuo 0 iki 10: " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            sum += A[i].ndrez[j];
        }
        vid = sum / m;
        cout << "Iveskite studento egzamino rezultata: ";
        cin >> A[i].erez;
        A[i].gbalas = 0.4 * vid + 0.6 * A[i].erez;
    }
    cout << "Vardas\tPavarde\tGalutinis (Vid.)" << endl;
    cout << "--------------------------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << A[i].vardas << "\t" << A[i].pavarde << "\t" << fixed << setprecision(2) << A[i].gbalas << endl;
    }
}