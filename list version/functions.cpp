#include "functions.h"
#include "errorfinder.h"

int tlaikas = 0;

void skaitymasisfailo(list<studentas> &A, char budas, char ivedbudas)
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

        A.push_front(new_studentas); //studentas idedamas i vektoriu
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

void irasymasifaila(list<studentas> &A, char budas)
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
    for (const auto& studentas : A)
    {
        buffer << setw(25) << left << studentas.vardas << setw(25) << left << studentas.pavarde << setw(25) << left << fixed << setprecision(2) << studentas.gbalas << endl;
    }
    out << buffer.str(); 
    out.close();
    auto stop = high_resolution_clock::now(); // Stop measuring time
    auto duration = duration_cast<milliseconds>(stop - start); 
    cout << "Writing to file took: " << duration.count() << " milliseconds" << endl;
    tlaikas += duration.count();
}

void isvedimas(list<studentas> &A, char budas)
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
        for (const auto& studentas : A)
        {
            cout << setw(25) << left << studentas.vardas << setw(25) << left << studentas.pavarde << setw(25) << left << fixed << setprecision(2) << studentas.gbalas << endl;
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

        new_studentas.ndrez.sort();
            
        auto it = new_studentas.ndrez.begin(); // Iterator pointing to the beginning of the list
        advance(it, new_studentas.ndrez.size() / 2); // Move the iterator to the middle element
        mediana = *it; // Assign the middle element as the median

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

void rikiavimas(list<studentas> &A)
{
    char rikbudas;
    rikbudas = rikbudpatikra();
    auto start = high_resolution_clock::now(); 
    if (rikbudas == 'b')
    {
        A.sort(rikiavimasgbalas);
    }
    else if (rikbudas == 'v') {A.sort(rikiavimasvardas);}
    else if (rikbudas == 'p') {A.sort(rikiavimaspavarde);}
    auto stop = high_resolution_clock::now(); // Stop measuring time
    auto duration = duration_cast<milliseconds>(stop - start); 
    cout << "Rūšiavimas (sort) truko: " << duration.count() << " miliseconds" << endl;
    tlaikas += duration.count();
}
// //1 strategija
// void skirstymas(list<studentas> &A, list<kietiakas> &K, list<vargsiukas> &V)
// {
//     auto start = high_resolution_clock::now();
//     for (const auto& studentas : A)
//     {
//         if (studentas.gbalas >= 5.0)
//         {
//             kietiakas k;
//             k.vardas = studentas.vardas;
//             k.pavarde = studentas.pavarde;
//             k.gbalas = studentas.gbalas;
//             K.push_back(k);
//         }
//         if (studentas.gbalas < 5.0)
//         {
//             vargsiukas v;
//             v.vardas = studentas.vardas;
//             v.pavarde = studentas.pavarde;
//             v.gbalas = studentas.gbalas;
//             V.push_back(v);
//         }
//     }
//     auto stop = high_resolution_clock::now();
//     auto duration = duration_cast<milliseconds>(stop - start);

//     cout << "Studentų skirstymas užtruko: " << duration.count() << " milliseconds" << endl;
//     tlaikas += duration.count();
// }

// //2 strategija
// void skirstymas(list<studentas> &A, list<kietiakas> &K, list<vargsiukas> &V)
// {
//     auto start = high_resolution_clock::now();
//     for (auto studentas = --A.end(); studentas != A.begin(); --studentas)
//     {
//         if (studentas->gbalas < 5.0)
//         {
//             vargsiukas v;
//             v.vardas = studentas->vardas;
//             v.pavarde = studentas->pavarde;
//             v.gbalas = studentas->gbalas;
//             V.push_back(v);
//             studentas = A.erase(studentas);
//         }
//     }
//     auto stop = high_resolution_clock::now();
//     auto duration = duration_cast<milliseconds>(stop - start);

//     cout << "Studentų skirstymas užtruko: " << duration.count() << " milliseconds" << endl;
//     tlaikas += duration.count();
// }

//3 strategija
void skirstymas(list<studentas> &A, list<kietiakas> &K, list<vargsiukas> &V) {
    auto start = high_resolution_clock::now();

    auto partition_point = partition(A.begin(), A.end(), [](const studentas& s) {
        return s.gbalas >= 5.0;
    });

    transform(A.begin(), partition_point, std::back_inserter(K), [](const studentas& s) {
        kietiakas k;
        k.vardas = s.vardas;
        k.pavarde = s.pavarde;
        k.gbalas = s.gbalas;
        return k;
    });

    transform(partition_point, A.end(), std::back_inserter(V), [](const studentas& s) {
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

void irasymasifailaK(list<studentas> &A, list<kietiakas> &K, list<vargsiukas> &V, char budas)
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
    for (const auto& k : K)
    {
        bufferK << setw(25) << left << k.vardas << setw(25) << left << k.pavarde << setw(25) << left << fixed << setprecision(2) << k.gbalas << endl;
    }
    // //2 strategija
    // for (const auto& s : A)
    // {
    //     bufferK << setw(25) << left << s.vardas << setw(25) << left << s.pavarde << setw(25) << left << fixed << setprecision(2) << s.gbalas << endl;
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
    for (const auto& v : V)
    {
        bufferV << setw(25) << left << v.vardas << setw(25) << left << v.pavarde << setw(25) << left << fixed << setprecision(2) << v.gbalas << endl;
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