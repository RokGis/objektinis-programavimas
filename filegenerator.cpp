#include "filegenerator.h"

int failugeneravimas ()
{
    ofstream out("studentai1000.txt");
    int n = 0;
    int m = 0;
    cout << "Iveskite studentu skaiciu: ";
    cin >> n;
    cout << "Iveskite namu darbu pazymiu skaiciu: ";
    cin >> m;
    for (int i = 0; i < n; i++)
    {
        out << setw(25) << left << "Vardas" + to_string(i + 1) << setw(25) << left << "Pavarde" + to_string(i + 1);
        for (int j = 0; j < m; j++)
        {
            out << right << setw(8) << rand() % 11;
        }
        out << endl;
    }
    return 0;
}
