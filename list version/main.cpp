#include "functions.h"
#include "errorfinder.h"
#include"filegenerator.h"

int main()
{
    list<std::string> vardai = {"Jonas", "Vytautas", "Tomas", "Mindaugas", "Antanas", "Darius", "Rokas", "Matas", "Lukas"};

    list<std::string> pavardes = {"Kazlauskas", "Jankauskas", "Petrauskas", "Stankevicius", "Vasiliauskas", "Vaigauskas", "Gilys", "Gavenas", "Gruodis"};

    srand(time(nullptr));

    failugeneravimas();
    int ivedbudas;
    ivedbudas = ivedbudpatikra();
    
    if (ivedbudas != 4)
    {
        char budas;
        budas = budaspatikra();
        char duomskait;
        if (ivedbudas == 1 || ivedbudas == 2){
            duomskait = dskaitpatikra();
        }
        char ski;

        list<studentas> A; //sudaromas list
        list<kietiakas> K; 
        list<vargsiukas> V; 

        if ((ivedbudas == 1 || ivedbudas == 2) && duomskait == 'f')
        {
            skaitymasisfailo(A, budas, ivedbudas);
            rikiavimas(A);
            ski = skirstymopatikra();
            if (ski == 't')
            {
                skirstymas(A, K, V);
                irasymasifailaK(K, V, budas);
            }
            else if (ski == 'n')
            {
                isvedimas(A, budas);
            }
            
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
            ski = skirstymopatikra();
            if (ski == 't')
            {
                skirstymas(A, K, V);
                irasymasifailaK(K, V, budas);
            }
            else if (ski == 'n')
            {
                isvedimas(A, budas);
            }
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
                // Generate random indices for names to avoid duplicates
                int name_index = rand() % vardai.size();
                int surname_index = rand() % pavardes.size();
                // Assign random names
                new_studentas.vardas = *std::next(vardai.begin(), name_index);
                new_studentas.pavarde = *std::next(pavardes.begin(), surname_index);
                // Generate random grades
                pazymiuived(new_studentas, budas, ivedbudas);
                A.push_back(new_studentas);
            }
            rikiavimas(A);
            ski = skirstymopatikra();
            if (ski == 't')
            {
                skirstymas(A, K, V);
                irasymasifailaK(K, V, budas);
            }
            else if (ski == 'n')
            {
                isvedimas(A, budas);
            }
        }
    }
    else {return 0;}
    return 0;
}