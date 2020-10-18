using namespace std;

#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdio>
#include <sstream> 

#include "vid.h"
#include "gal_rez.h"
#include "mediana.h"
#include "spausdinimas.h"
#include "isNumber.h"

//#include "duomenys.h""
//#include "studentas.h"
//#include "rusiavimas.h"

struct duomenys
{
    string vardai;
    string pavardes;
    vector<string> pazymiai;
};

struct studentas
{
    string vardai;
    string pavardes;
    vector<int> pazymiai;
};

struct rusiavimas
{
    string vardai;
    string pavardes;
    double vidurkiai;
    double medianos;
};

bool palygintiVardus(rusiavimas& a, rusiavimas& b) { return a.vardai < b.vardai; };
bool palygintiPavardes(rusiavimas& a, rusiavimas& b) { return a.pavardes < b.pavardes; };


int main()
{
    ofstream myfile;
    fstream infile;

    int sk, egzaminas{}, tmp;

    string vardas, pavarde, vardas_i, pavarde_i;

    int egzaminai;

    string atsakymas;

    cout << "Ar norite, kad duomenys butu nuskaityti is failo? ('N'-ne/'T'-taip)\n";
    cin >> atsakymas;
    
    if (atsakymas == "T")
    {
        vector<studentas> studentai;
        vector<duomenys> info;
        vector<int> tikrinimas;

        string failo_pav;

        cout << "Iveskite failo pavadinima: \n";
        cin >> failo_pav;

        infile.open(failo_pav);

        int rows = 0, cols = 0;
        string eilute, reiksme;
        infile.close();

        infile.open(failo_pav);

        string rez;
        vector<string> visi_rezultatai_i;
        vector<string> visi_rezultatai;
        
         if (infile.fail())
        {
            perror(nullptr);
            return 1;
        }
        else
        {

            for (int i = 0; i < 1; i++)
            {
                infile >> vardas_i >> pavarde_i;

                for (int j = 0; j < cols - 2; j++)
                {
                    infile >> rez;
                    visi_rezultatai_i.push_back(rez);
                }

                info.push_back(duomenys{ vardas_i, pavarde_i, visi_rezultatai_i });
                visi_rezultatai_i.clear();
            }
             for (int i = 1; i < rows; i++)
            {
                infile >> vardas >> pavarde;

                for (int j = 0; j < cols - 2; j++)
                {
                    infile >> rez;
                    visi_rezultatai.push_back(rez);

                        visi_rezultatai.clear();
                        vector<string>().swap(visi_rezultatai);
                    }
                }

                studentai.push_back(studentas{ vardas, pavarde, tikrinimas });

                tikrinimas.clear();
                vector<int>().swap(tikrinimas);
            }

            vector<double> vidurkiai;
            vector<double> medianos;
            
             for (int i = 0; i < studentai.size(); i++)
            {

                cout << "Skaiciuojama mediana ir vidurkis \n";

                vidurkiai.push_back(gal_rez(studentai[i].pazymiai.back(), studentai[i].pazymiai));
                medianos.push_back(gal_mediana(studentai[i].pazymiai.back(), studentai[i].pazymiai));
            }

            vidurkiai.clear();
            medianos.clear();
            studentai.clear();
            vector<double>().swap(vidurkiai);
            vector<double>().swap(medianos);
            vector<studentas>().swap(studentai);
            
            string var;
            cout << "Rusiuoti pagal pavardes ar vardus ? (V/P)";
            cin >> var;

            if (var == "V")
            {
                sort(stud_rus.begin(), stud_rus.end(), palygintiVardus);
            }
            else if (var == "P")
            {
                sort(stud_rus.begin(), stud_rus.end(), palygintiPavardes);
            }

            myfile.open("kursiokai.txt");

            if (myfile.fail())
            {
                perror(nullptr);
                return 1;
            }
            else
            {
                for (int i = 0; i < info.size(); i++)
                {
                    myfile << "Vardas" << setw(25) << "Pavarde" << setw(25) << "Vidurkis" << setw(25) << "Mediana" << "\n";
                }

                for (int i = 0; i < stud_rus.size(); i++)
                {
                    myfile << stud_rus[i].vardai << setw(25) << stud_rus[i].pavardes << setw(25) << stud_rus[i].vidurkiai << setw(25) << stud_rus[i].medianos << "\n";
                }
            }
            myfile.close();
            stud_rus.clear();
            vector<rusiavimas>().swap(stud_rus);
        }
    }
    else if (atsakymas == "N")
    {
        cout << "Iveskite studentu skaiciu: \n";
        cin >> sk;

        if (sk > 0)
        {
            for (int i = 0; i < sk; i++) {

                cout << "Iveskite studento varda: \n";
                cin >> vardas;
                if (isdigit(vardas[i]))
                {
                    cout << "Klaida! Vardas negali buti skaicius\n";
                }
                else {
                    vardai.push_back(vardas);

                    cout << "Iveskite studento pavarde: \n";
                    cin >> pavarde;
                    if (isdigit(pavarde[i]))
                    {
                        cout << "Klaida! Pavarde negali buti skaicius \n";
                    }
                    else
                    {
                        pavardes.push_back(pavarde);

                        cout << "Ar balus sugeneruoti automatiskai? (T/N) \n";
                        string ats;
                        cin >> ats;

                        if (ats == "T")

                                cout << "Sugeneruotas balas:  " << tmp << "\n";


                                cout << "Ar jau ivesti visi rezulatatai (T/N)? \n";
                                string ats2;
                                cin >> ats2;

                                if (ats2 == "T") {
                                    break;
                                }
                            }
                        }
                        
                        else if (ats == "N") {

                            while (true) {
                                cout << "Iveskite namu darbu rezultatus \n";
                                cin >> tmp;
                                if (tmp > 0 && tmp <= 10)
                                    cout << "Klaida! Pazimys turi buti 10-baleje sistemoje.\n";
                        else
                        {
                            cout << "Klaida! reikia pasirinkti T arba N";
                        }
                        
                        


