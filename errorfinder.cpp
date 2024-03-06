#include "errorfinder.h"

int ivedbudpatikra()
{
    int ivedbudas;
    cout << "Pasirinkite studentu duomenu ivedimo buda (1 - ivesti duomenis (skaityti is failo), 2 - generuoti pazymius, 3 - generuoti pazymius ir studentus, 4 - baigti darba): ";
    while(true)
    {
    try{
        if(!(cin >> ivedbudas) || ivedbudas > 4 || ivedbudas < 1)
        {
            throw "Įvestas (ne)skaičius ne iš intervalo (1-4). Įveskite dar kartą: ";
        }
        return ivedbudas;
        break;
    } catch (char const *error)
    {
        cerr << error << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    }
}

char budaspatikra()
{
    char budas;
    cout << "Pasirinkite galutinio balo apskaiciavimo buda (vidurkis (v) ar mediana (m)): ";
    while(true)
    {
        try{
        if(!(cin >> budas) || (budas != 'v' && budas != 'm'))
        {
            throw "Įvestas netinkamas simbolis. Įveskite dar kartą 'v' arba 'm': ";
        }
        return budas;
        break;
        } catch (char const *error)
        {
            cerr << error << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

char dskaitpatikra()
{
    char duomskait;
    cout << "Pasirinkite studentu duomenu skaitymo buda (ivedimas ranka (r) ar skaitymas is failo (f)): ";
    while(true)
    {
        try{
        if(!(cin >> duomskait) || (duomskait != 'r' && duomskait != 'f'))
        {
           throw "Įvestas netinkamas simbolis. Įveskite dar kartą 'r' arba 'f': ";
        }
        return duomskait;
        break;
        }catch (char const *error)
        {
            cerr << error << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

int studskpatikra()
{
    int m;
    while(true)
    {
        try{
        if(!(cin >> m) || m <= 0)
        {
            throw "Įvestas netinkamas skaičius. Įveskite dar kartą natūralųjį skaičių: ";
        }
        return m;
        break;
        } catch(char const *error)
        {
            cerr << error << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

char isvedbudpatikra()
{
    char isvedbud;
    cout << "Pasirinkite studentu duomenu isvedimo buda (ekrane (e) ar irasymas i faila (f)): ";
    while(true)
    {
        try{
        if(!(cin >> isvedbud) || (isvedbud != 'e' && isvedbud != 'f'))
        {
            throw "Įvestas netinkamas simbolis. Įveskite dar kartą 'e' arba 'f': ";
        }
        return isvedbud;
        break;
        } catch(char const *error)
        {
            cerr << error << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

int erezpatikra()
{
    int erez;
    cout << "Iveskite studento egzamino rezultata nuo 0 iki 10: ";
    while(true)
    {
        try{
        if (!(cin >> erez) || erez < 0 || erez > 10)
        {
            throw "Įvestas (ne)skaičius ne iš intervalo (0-10). Įveskite dar kartą: ";
        }
        return erez;
        break;
        }
        catch (char const *error)
        {
            cerr << error << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

char rikbudpatikra()
{
    char rikbudas;
    cout << "Pasirinkite studentu rikiavimo buda (pagal galutinius balus (b), pagal vardus (v) ar pagal pavardes (p)): ";
    while(true)
    {
        try{
        if(!(cin >> rikbudas) || (rikbudas != 'b' && rikbudas != 'v' && rikbudas != 'p'))
        {
            throw "Įvestas netinkamas simbolis. Įveskite dar kartą 'b', 'v' arba 'p': ";
        }
        return rikbudas;
        break;
        } catch (char const *error)
        {
            cerr << error << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

int pazymiopatikra()
{
    int pazymys;
    cout << "Iveskite pazymi nuo 0 iki 10: ";
    while(true)
    {
    try{           
        if (!(cin >> pazymys) || pazymys < 0 || pazymys > 11)
        {
            throw "Įvestas (ne)skaičius ne iš intervalo (1-4). Įveskite dar kartą: ";
        }
        return pazymys;
        break;
    }
    catch (char const *error)
    {
        cerr << error << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

char skirstymopatikra()
{
    char ski;
    cout << "Ar skirstyti studentus į kietiakus ir vargselius? Pasirinkite: taip (t) arba ne (n): ";
    while(true)
    {
        try{
        if(!(cin >> ski) || (ski != 't' && ski != 'n'))
        {
           throw "Įvestas netinkamas simbolis. Įveskite dar kartą 't' arba 'n': ";
        }
        return ski;
        break;
        }catch (char const *error)
        {
            cerr << error << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}