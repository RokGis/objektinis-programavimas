#include "functions.h"
#include "errorfinder.h"

int tlaikas = 0;

void skaitymasisfailo(vector<studentas> &A, char budas, char ivedbudas)
{
    int sum = 0;
    ifstream in("studentai10000000.txt");
    
    try {
        if (!in.is_open()) {
            throw runtime_error("Nepavyko atidaryti failo.");
        }

    string eil;
    auto start = high_resolution_clock::now();
    getline(in, eil);

    while(getline(in, eil)){
        studentas new_studentas;
        sum = 0;
        new_studentas.vardas = eil.substr(0, 25);
        new_studentas.pavarde = eil.substr(25, 25);
        if (ivedbudas == 1)
        {
            string pazymiai = eil.substr(50); // studento pazymiai saugomi kaip string tipo duomenys
            stringstream my_buffer(pazymiai);
            int pazymys;
            while (my_buffer >> pazymys)
            {
                new_studentas.ndrez.push_back(pazymys); // prisikiriamas elSementas
                sum += pazymys;
            }
            new_studentas.erez = new_studentas.ndrez.back(); // paskutinis elementas priskiriamas kaip egzamino rezultatas
            new_studentas.ndrez.pop_back();                  // paskutinis elementas istrinamas is namu darbu pazymiu vektoriaus
            sum -= new_studentas.erez; //atimame egzamino reiksme, nes ji buvo prideta prie sumos
            skaiciavimas(new_studentas, sum, budas);
        }
        if (ivedbudas == 2)
        {
            pazymiuived(new_studentas, budas, ivedbudas);
        }

        A.push_back(new_studentas); //studentas idedamas i vektoriu
    }
    in.close();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "Reading from file took: " << duration.count() << " milliseconds" << endl;
    tlaikas += duration.count();
    }
    catch (const runtime_error &e)
    {
        cerr << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}

void irasymasifaila(vector<studentas> &A, char budas)
{
    auto start = high_resolution_clock::now(); 
    ofstream out("kursiokai.txt");
    ostringstream buffer;
    if (budas == 'v')
    {
        buffer << setw(25) << left << "Vardas" << setw(25) << left << "Pavarde" << setw(25) << left << "Galutinis (Vid.)" << endl;
    }
    else if (budas=='m'){
         buffer << setw(25) << left << "Vardas" << setw(25) << left << "Pavarde" << setw(25) << left << "Galutinis (Med.)" << endl;}
    buffer << "---------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < A.size(); i++)
    {
        buffer << setw(25) << left << A[i].vardas << setw(25) << left << A[i].pavarde << setw(25) << left << fixed << setprecision(2) << A[i].gbalas << endl;
    }
    out << buffer.str(); 
    out.close();
    auto stop = high_resolution_clock::now(); // Stop measuring time
    auto duration = duration_cast<milliseconds>(stop - start); 
    cout << "Writing to file took: " << duration.count() << " milliseconds" << endl;
    tlaikas += duration.count();
}

void isvedimas(vector<studentas> &A, char budas)
{
    char isvedbud;
    isvedbud = isvedbudpatikra();
    if (isvedbud == 'e')
    {
        if (budas == 'v')
        {
            cout << setw(25) << left << "Vardas" << setw(25) << left << "Pavarde" << setw(25) << left << "Galutinis (Vid.)" << endl;
        }
        else if (budas == 'm')
        {
            cout << setw(25) << left << "Vardas" << setw(25) << left << "Pavarde" << setw(25) << left << "Galutinis (Med.)" << endl;
        }
        cout << "---------------------------------------------------------------------------------------------------" << endl;
        for (int i = 0; i < A.size(); i++)
        {
            cout << setw(25) << left << A[i].vardas << setw(25) << left << A[i].pavarde << setw(25) << left << fixed << setprecision(2) << A[i].gbalas << endl;
        }
    }
    else if (isvedbud == 'f')
    {
        irasymasifaila(A, budas);
    }
}

void pazymiuived(studentas &new_studentas, char budas, int ivedbudas)
{
    int sum = 0;
    int pazymys;
    if (ivedbudas == 1){
        cout << "Iveskite studento namu darbu rezultata arba „11“, jeigu norite uzbaigti rezultatu vedima: " << endl;}
    
    while (true)
    {
        if (ivedbudas == 1)
        {
            pazymys = pazymiopatikra();
            if (pazymys == 11)
            {
                break;
            }                
        }

        if (ivedbudas == 2 || ivedbudas == 3)
        {
            pazymys = rand() % 12;
            if (pazymys == 11) {
                break;}
        }
        new_studentas.ndrez.push_back(pazymys); // pridedamas elementas i gala
        sum += pazymys;
    }
    if (ivedbudas == 1)
    {
        new_studentas.erez = erezpatikra();
    }

    if (ivedbudas == 2 || ivedbudas == 3)
    {
        new_studentas.erez = rand() % 11;
    }
    skaiciavimas(new_studentas, sum, budas);
}

void skaiciavimas(studentas &new_studentas, int sum, char budas)
{
    auto start = high_resolution_clock::now(); 
    double vid, mediana;
    if (new_studentas.ndrez.size() == 0)
    {
        vid = 0;
        mediana = 0;
    }
    else 
    {
        vid = sum / (new_studentas.ndrez.size() * 1.0);
            
        sort(new_studentas.ndrez.begin(), new_studentas.ndrez.end());
        if (new_studentas.ndrez.size() % 2 == 0) {
            mediana = (new_studentas.ndrez[new_studentas.ndrez.size() / 2 - 1] + new_studentas.ndrez[new_studentas.ndrez.size() / 2]) / 2.0;}
        else {
                mediana = new_studentas.ndrez[new_studentas.ndrez.size() / 2];}
    }

    if (budas == 'v')
    {
        new_studentas.gbalas = 0.4 * vid + 0.6 * new_studentas.erez;
    }
    else if (budas == 'm')
    {
        new_studentas.gbalas = 0.4 * mediana + 0.6 * new_studentas.erez;
    }
    sum = 0;
    auto stop = high_resolution_clock::now(); // Stop measuring time
    auto duration = duration_cast<milliseconds>(stop - start); 
    tlaikas += duration.count();
}

bool rikiavimasgbalas(const studentas &a, const studentas &b)
{
    return a.gbalas > b.gbalas;
}

bool rikiavimasvardas(const studentas &a, const studentas &b)
{
    return a.vardas < b.vardas;
}

bool rikiavimaspavarde(const studentas &a, const studentas &b)
{
    return a.pavarde < b.pavarde;
}

void rikiavimas(vector<studentas> &A)
{
    char rikbudas;
    rikbudas = rikbudpatikra();
    auto start = high_resolution_clock::now(); 
    if (rikbudas == 'b')
    {
        sort(A.begin(), A.end(), rikiavimasgbalas);
    }
    else if (rikbudas == 'v') {sort(A.begin(), A.end(), rikiavimasvardas);}
    else if (rikbudas == 'p') {sort(A.begin(), A.end(), rikiavimaspavarde);}
    auto stop = high_resolution_clock::now(); // Stop measuring time
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Rūšiavimas (sort) truko: " << duration.count() << " miliseconds" << endl;
    tlaikas += duration.count();
}

////1 strategija
// void skirstymas(vector<studentas> &A, vector<kietiakas> &K, vector<vargsiukas> &V)
// {
//     auto start = high_resolution_clock::now();
//     for (int i = 0; i < A.size(); i++)
//     {
//         if (A[i].gbalas >= 5.0)
//         {
//             kietiakas k;
//             k.vardas = A[i].vardas;
//             k.pavarde = A[i].pavarde;
//             k.gbalas = A[i].gbalas;
//             K.push_back(k);
//         }
//         if (A[i].gbalas < 5.0)
//         {
//             vargsiukas v;
//             v.vardas = A[i].vardas;
//             v.pavarde = A[i].pavarde;
//             v.gbalas = A[i].gbalas;
//             V.push_back(v);
//         }
//     }
//     auto stop = high_resolution_clock::now();
//     auto duration = duration_cast<milliseconds>(stop - start);

//     cout << "Studentų skirstymas užtruko: " << duration.count() << " milliseconds" << endl;
//     tlaikas += duration.count();
// }

// //2 strategija
// void skirstymas(vector<studentas> &A, vector<kietiakas> &K, vector<vargsiukas> &V)
// {
//     auto start = high_resolution_clock::now();
//     for (int i = A.size()-1; i >= 0; i--)
//     {
//         if (A[i].gbalas < 5.0)
//         {
//             vargsiukas v;
//             v.vardas = A[i].vardas;
//             v.pavarde = A[i].pavarde;
//             v.gbalas = A[i].gbalas;
//             V.push_back(v);
//             A.pop_back();
//         }
//     }
//     auto stop = high_resolution_clock::now();
//     auto duration = duration_cast<milliseconds>(stop - start);

//     cout << "Studentų skirstymas užtruko: " << duration.count() << " milliseconds" << endl;
//     tlaikas += duration.count();
// }

//3 strategija
void skirstymas(vector<studentas> &A, vector<kietiakas> &K, vector<vargsiukas> &V)
{
    auto start = high_resolution_clock::now();

    auto partition_point = partition(A.begin(), A.end(), [](const studentas& s) {
        return s.gbalas >= 5.0;
    });

    transform(A.begin(), partition_point, back_inserter(K), [](const studentas& s) {
        kietiakas k;
        k.vardas = s.vardas;
        k.pavarde = s.pavarde;
        k.gbalas = s.gbalas;
        return k;
    });

    transform(partition_point, A.end(), back_inserter(V), [](const studentas& s) {
        vargsiukas v;
        v.vardas = s.vardas;
        v.pavarde = s.pavarde;
        v.gbalas = s.gbalas;
        return v;
    });

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "Studentų skirstymas užtruko: " << duration.count() << " milliseconds" << endl;
    tlaikas += duration.count();
}

void irasymasifailaK(vector<studentas> &A, vector<kietiakas> &K, vector<vargsiukas> &V, char budas)
{
    auto start = high_resolution_clock::now(); 
    ofstream outK("kietiakai.txt");
    ostringstream bufferK;
    if (budas == 'v')
    {
        bufferK << setw(25) << left << "Vardas" << setw(25) << left << "Pavarde" << setw(25) << left << "Galutinis (Vid.)" << endl;
    }
    else if (budas=='m'){
         bufferK << setw(25) << left << "Vardas" << setw(25) << left << "Pavarde" << setw(25) << left << "Galutinis (Med.)" << endl;}
    bufferK << "---------------------------------------------------------------------------------------------------" << endl;
    //1 strategija
    for (int i = 0; i < K.size(); i++)
    {
        bufferK << setw(25) << left << K[i].vardas << setw(25) << left << K[i].pavarde << setw(25) << left << fixed << setprecision(2) << K[i].gbalas << endl;
    }
    // //2 strategija
    // for (int i = 0; i < A.size(); i++)
    // {
    //     bufferK << setw(25) << left << A[i].vardas << setw(25) << left << A[i].pavarde << setw(25) << left << fixed << setprecision(2) << A[i].gbalas << endl;
    // }
    outK << bufferK.str();
    outK.close();
    bufferK.clear();
    ofstream outV("vargsiukai.txt");
    ostringstream bufferV;
    if (budas == 'v')
    {
        bufferV << setw(25) << left << "Vardas" << setw(25) << left << "Pavarde" << setw(25) << left << "Galutinis (Vid.)" << endl;
    }
    else if (budas=='m'){
         bufferV << setw(25) << left << "Vardas" << setw(25) << left << "Pavarde" << setw(25) << left << "Galutinis (Med.)" << endl;}
    bufferV << "---------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < V.size(); i++)
    {
        bufferV << setw(25) << left << V[i].vardas << setw(25) << left << V[i].pavarde << setw(25) << left << fixed << setprecision(2) << V[i].gbalas << endl;
    }
    outV << bufferV.str();
    outV.close();
    bufferV.clear();
    auto stop = high_resolution_clock::now(); // Stop measuring time
    auto duration = duration_cast<milliseconds>(stop - start); 
    cout << "Writing to file took: " << duration.count() << " milliseconds" << endl;
    tlaikas += duration.count();
    cout << "Programos vykdymo laikas: " << tlaikas << " milliseconds" << endl;
}