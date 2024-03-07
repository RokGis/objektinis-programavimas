#include "filegenerator.h"
#include "errorfinder.h"

int failugeneravimas ()
{
    char fgen;
    fgen = fgeneravimopatikra();
    if (fgen == 't')
    {
        int n = 0;
        int m = 0;
        cout << "Iveskite studentu skaiciu: ";
        n = studskpatikra();
        cout << "Iveskite namu darbu pazymiu skaiciu: ";
        m = studskpatikra();
        ofstream out("studentai" + to_string(n) + ".txt");
        ostringstream buffer;

        buffer << setw(25) << left << "Vardas" << setw(25) << left << "Pavarde";
        for (int i = 0; i < m; i++)
        {
            buffer << setw(8) << right << "ND" + to_string(i + 1);
        }
        buffer << setw(8) << right << "Egz." << endl;

        for (int i = 0; i < n; i++)
        {
            buffer << setw(25) << left << "Vardas" + to_string(i + 1) << setw(25) << left << "Pavarde" + to_string(i + 1);
            for (int j = 0; j < m + 1; j++)
            {
                buffer << right << setw(8) << rand() % 11;
            }
            buffer << endl;
        }
        out << buffer.str();
        out.close();
        return 0;
    }
    else
        return 0;
}
