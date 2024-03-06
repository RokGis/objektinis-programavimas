#include "functions.h"
#include "errorfinder.h"
#include"filegenerator.h"

int main()
{
    vector<string> vardai = {"Jonas", "Vytautas", "Tomas", "Mindaugas", "Antanas", "Darius", "Rokas", "Matas", "Lukas"};

    vector<string> pavardes = {"Kazlauskas", "Jankauskas", "Petrauskas", "Stankevicius", "Vasiliauskas", "Vaigauskas", "Gilys", "Gavenas", "Gruodis"};

    srand(time(nullptr));

    int ivedbudas;
    ivedbudas = ivedbudpatikra();
    failugeneravimas();

    if (ivedbudas != 4)
    {
        char budas;
        budas = budaspatikra();
        char duomskait;
        if (ivedbudas == 1 || ivedbudas == 2){
            duomskait = dskaitpatikra();
        }

        vector<studentas> A; //sudaromas vektorius
        vector<kietiakas> K; 
        vector<vargsiukas> V; 

        if ((ivedbudas == 1 || ivedbudas == 2) && duomskait == 'f')
        {
            skaitymasisfailo(A, budas, ivedbudas);
            skirstymas(A, K, V);
            rikiavimas(A);
            isvedimas(A, budas);
            irasymasifailaK(K, budas);
            irasymasifailaV(V, budas);
        }

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
            m = studskpatikra();

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