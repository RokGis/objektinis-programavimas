#include "functions.h"
#include "errorfinder.h"
#include"filegenerator.h"

int main()
{
    // vector<std::string> vardai = {"Jonas", "Vytautas", "Tomas", "Mindaugas", "Antanas", "Darius", "Rokas", "Matas", "Lukas"};

    // vector<std::string> pavardes = {"Kazlauskas", "Jankauskas", "Petrauskas", "Stankevicius", "Vasiliauskas", "Vaigauskas", "Gilys", "Gavenas", "Gruodis"};

std::vector<std::string> vardai;
    vardai.push_back("Jonas");
    vardai.push_back("Vytautas");
    vardai.push_back("Tomas");
    vardai.push_back("Mindaugas");
    vardai.push_back("Antanas");
    vardai.push_back("Darius");
    vardai.push_back("Rokas");
    vardai.push_back("Matas");
    vardai.push_back("Lukas");

    std::vector<std::string> pavardes;
    pavardes.push_back("Kazlauskas");
    pavardes.push_back("Jankauskas");
    pavardes.push_back("Petrauskas");
    pavardes.push_back("Stankevicius");
    pavardes.push_back("Vasiliauskas");
    pavardes.push_back("Vaigauskas");
    pavardes.push_back("Gilys");
    pavardes.push_back("Gavenas");
    pavardes.push_back("Gruodis");

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

        vector<studentas> A; //sudaromas vektorius
        vector<kietiakas> K; 
        vector<vargsiukas> V; 

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
                new_studentas.vardas = vardai[rand() % vardai.size()];
                new_studentas.pavarde = pavardes[rand() % pavardes.size()];
                pazymiuived(new_studentas, budas, ivedbudas);
                A[i] = new_studentas;
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