#include "functions.h"

int main()
{
    vector<string> vardai = {"Jonas", "Vytautas", "Tomas", "Mindaugas", "Antanas", "Darius", "Rokas", "Matas", "Lukas"};

    vector<string> pavardes = {"Kazlauskas", "Jankauskas", "Petrauskas", "Stankevicius", "Vasiliauskas", "Vaigauskas", "Gilys", "Gavenas", "Gruodis"};

    srand(time(nullptr));

    int ivedbudas;
    cout << "Pasirinkite studentu duomenu ivedimo buda (1 - ivesti duomenis (skaityti is failo), 2 - generuoti pazymius, 3 - generuoti pazymius ir studentus, 4 - baigti darba): ";
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
        char duomskait;
        if (ivedbudas == 1 || ivedbudas == 2){
        cout << "Pasirinkite studentu duomenu skaitymo buda (ivedimas ranka (r) ar skaitymas is failo (f)): ";
        while (!(cin >> duomskait) || (duomskait != 'r' && duomskait != 'f'))
        {
            cout << "Iveskite 'r' arba 'f': ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }}

        vector<studentas> A; //sudaromas vektorius

        if ((ivedbudas == 1 || ivedbudas == 2) && duomskait == 'f')
        {
            skaitymasisfailo(A, budas, ivedbudas);
            rikiavimas(A);
            isvedimas(A, budas);}

        else if ((ivedbudas == 1 || ivedbudas == 2) && duomskait == 'r')
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
            rikiavimas(A);
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
            rikiavimas(A);
            isvedimas(A, budas);
        }
    }
    else {return 0;}
    return 0;
}