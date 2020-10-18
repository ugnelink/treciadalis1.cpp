#include "funkcijos.h"
#include "duomenys.h"
#include "studentas.h"
#include "rusiavimas.h"

bool palygintiVardus(rusiavimas& a, rusiavimas& b) { return a.vardai < b.vardai; };
bool palygintiPavardes(rusiavimas& a, rusiavimas& b) { return a.pavardes < b.pavardes; };

int main()
{
    ofstream myfile;
    fstream infile;

    int sk, egzaminas{}, tmp;

    vector<int> nd;
    vector<string> vardai;
    vector<string> pavardes;
    vector<double>galutinis1;
    vector<double> galutiniai;
    vector<double> galutiniai2;

    string vardas, pavarde, vardas_i, pavarde_i;

    int egzaminai;

    string atsakymas;

    cout << "Ar norite, kad duomenys butu nuskaityti is failo? ('T'-taip/'N'-ne)\n";
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

                        cout << "Ar namu darbu pazymius sugeneruoti automatiskai? ('T'-taip/'N'-ne) \n";
                        string ats;
                        cin >> ats;

                        if (ats == "T") {

                            while (true) {

                                int max = 10;
                                srand(time(0));
                                tmp = rand() % max;
                                nd.push_back(tmp);

                                cout << "Sugeneruotas balas:  " << tmp << "\n";


                                cout << "Ar jau ivesti visi rezulatatai ('T'-taip/'N'-ne)? \n";
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
                                   if (ats2 == "T") {
                                        break;
                                    }

                                }
       else {
                                    cout << "Klaida! Pazimys turi buti 10-baleje sistemoje.\n";
                                }
                            }
                        }
                      
                        else
                        {
                            cout << "Klaida! reikia pasirinkti T arba N.\n";
                        }

                        cout << "Ar egzamino bala sugeneruoti automatiskai? ('T'-taip/'N'-ne) \n";
                        string ats2;
                        cin >> ats2;

                        if (ats2 == "T")
                        {
                            int max = 10;
                            srand(time(0));
                            egzaminas = rand() % max;
                            cout << "Egzamino balas  " << egzaminas << "\n";
                        }
                            catch (int x) {
                                cout << "Klaida! Egzamino rezultatas turi buti 10-baleje sistemoje;
                            } 
                        }
                        
                        try {
                            if (ats2 != "T" && ats2 != "N") {
                                throw 1;
                            }
                        }
                        catch (int x) {
                            cout << "Klaida! Reikia pasirinkti T arba N. ERROR: " << x << endl;
                        }

                        galutinis1.push_back(gal_rez(egzaminas, nd));

                        galutiniai.push_back(vid(egzaminas, nd));

                        galutiniai2.push_back(gal_mediana(egzaminas, nd));

                        nd.clear();

                    }

                }
            }
        }
        try {
            if (sk<=0) {
                throw 2;
            }
        }
        catch (int x) {
            cout << "Klaida! Studentu skaicius turi buti teigiamas sveikasis skaicius. ERROR: " << x << endl;
        }

        spausdinimas(vardai, pavardes, galutinis1, galutiniai, galutiniai2);
    }
    try {
        if (atsakymas != "T" && atsakymas != "N") {
            throw 1;
        }
    }
    catch (int x) {
        cout << "Klaida! Reikia pasirinkti T arba N.;
    }
}
