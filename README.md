# objektinis-programavimas
### Konteinerių testavimas:<br>
Duomenų nuskaitymas iš failo vyko greičiau su std::vector ir std::deque konteineriais.
![image](https://github.com/RokGis/objektinis-programavimas/assets/147180109/b6b98719-bba2-44d2-9267-9be3c27118b8)
Studentų rūšiavimas didėjimo tvarka (sort) greičiausiai vyko su std::vector, kai naudojami didesni failai, ir std::list konteineriais, kai naudojami mažesni failai.
![image](https://github.com/RokGis/objektinis-programavimas/assets/147180109/2dd960d8-bc94-44c5-a52a-7903f8be633a)
Studentų skirtymas į dvi grupes/kategorijas vyko greičiausiai su std::vector ir šiek tiek lėčiau su std::list konteineriais.
![image](https://github.com/RokGis/objektinis-programavimas/assets/147180109/35435ad4-3ec0-4f21-a4a2-6587ee3fae28)
Testavimo sistemos parametrai:<br>
![image](https://github.com/RokGis/objektinis-programavimas/assets/147180109/9f0673e6-d7fd-4641-8cbc-a81b543abbc7)<br>
### Studentų rūšiavimo (dalijimo) į dvi kategorijas optimizavimas:<br>
Studentų skirstymas į dvi grupes/kategorijas greičiausiai vyko pritaikius 3 strategiją, naudojant std::partition ir std::transform algoritmus.
![image](https://github.com/RokGis/objektinis-programavimas/assets/147180109/af2fd838-8203-49ff-842d-6a5ca46973e8)
### Naudotojo sąveikos vadovas:

1. **Pasirinkimas Sugeneruoti arba Nuskaityti Failą su Studentais:**
   - `t`: Taip
   - `n`: Ne
   - **Pastaba:** Jei taip, įveskite studentų skaičių ir namų darbų pažymių skaičių.

2. **Pasirinkite Duomenų Įvedimo Metodą:**
   Naudotojai pasirenka vieną iš keturių variantų:
   - `1`: Rankiniu būdu įvesti arba nuskaityti duomenis iš failo.
   - `2`: Rankiniu būdu įvesti vardus, o pažymius sugeneruoti atsitiktinai.
   - `3`: Sugeneruoti vardus ir pažymius atsitiktinai.
   - `4`: Baigti programą.

3. **Pasirinkite Skaičiavimo Metodą:**
   Variantams 1, 2 ir 3, naudotojai turi pasirinkti galutinių rezultatų skaičiavimo metodą:
   - `v`: Namų darbų pažymių vidurkis.
   - `m`: Namų darbų pažymių mediana.

4. **Įveskite Studentų Duomenis:**
   - Variantams 1 ir 2: Pasirinkite įvedimo metodą (`r` rankiniu būdu, `f` iš failo). Jei pasirenkate rankinį įvedimą (`r`), įveskite studentų vardus ir pavardes. Norėdami sustabdyti, įveskite "11".
   - Variantui 3: Įveskite studentų skaičių.

5. **Įveskite arba Sugeneruokite Pažymius:**
   - Variantui 1: Jei pasirenkate rankinį įvedimą (`r`), įveskite kiekvieno studento namų darbų pažymius ir galutinį egzamino rezultatą. Norėdami sustabdyti įvedimą, įveskite "11".
   - Variantams 2 ir 3: Pažymiai sugeneruojami automatiškai.

6. **Pasirinkite Duomenų Rūšiavimo Tipą:**
   - `g`: Rūšiuoti pagal galutinius rezultatus.
   - `v`: Rūšiuoti pagal vardus.
   - `p`: Rūšiuoti pagal pavardes.

7. **Pasirinkite Padalinti Studentus į Dvi Grupes Pagal Galutinį Rezultatą:**
   - `t`: Taip
   - `n`: Ne

8. **Jei Naudotojas Pasirinko Neskirstyti Studentų:**
   Pasirinkite Studentų Duomenų Išvesties Metodą:
   - `e`: Išvesti ekrane.
   - `f`: Rašyti duomenis į failą.

### Instrukcijos naudoti Makefile:

1. **Atidarykite Terminalą:**
   Atidarykite terminalą arba komandinę eilutę savo sistemoje.

2. **Naršykite į Projekto Katalogą:**
   Naudodami `cd` komandą, naršykite į savo projekto katalogą, kuriame turite Makefile ir jūsų šaltinių failus.

3. **Sukompiliuokite Programą:**
   Įveskite `make` terminale ir spauskite Enter, kad sukompiliuotumėte programą. Ši komanda sukompiliuos visus `.cpp` ir `.h` failus į vykdomąjį failą, kuris bus pavadintas `main`.

4. **Paleiskite Programą:**
   Po kompiliavimo įveskite `./main` terminale ir spauskite Enter, kad sukompiliuotumėte ir paleistumėte programą. Ši komanda kompiliuos programą (jei dar nekompiliuota) ir tada ją paleis.

5. **Tvarkykite:**
   Jei norite pašalinti sukompiliuotą vykdomąjį failą, įveskite `make clean` terminale ir spauskite Enter. Ši komanda pašalins `main` vykdomąjį failą iš jūsų projekto katalogo.

Pastaba: Įsitikinkite, kad jūsų sistemoje įdiegta GNU Make paslauga, kad galėtumėte naudoti Makefile komandas. Taip pat atkreipkite dėmesį, kad Makefile, `.cpp` bei `.h` failai būtų viename (projekte) aplanke.

  
