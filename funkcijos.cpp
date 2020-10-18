#include "funkcijos.h"

double vid(int egzaminas, vector<int>nd)
{
    double v;
    v = accumulate(nd.begin(), nd.end(), 0.000) / nd.size();

    return v;
}

double gal_rez(int egzaminas, vector<int> nd)
{
    double vidurkis, galutinis1;

    vidurkis = accumulate(nd.begin(), nd.end(), 0.000) / nd.size();
    galutinis1 = (0.4 * vidurkis) + (0.6 * egzaminas);

    return galutinis1;
}

double gal_mediana(int egzaminas, vector<int> nd)
{
    vector<double> skaiciai;
    for (int i = 0; i < nd.size(); i++) {
        skaiciai.push_back(nd.at(i));
    }

    skaiciai.push_back(egzaminas);

    sort(skaiciai.begin(), skaiciai.end());

    if (skaiciai.size() % 2 == 0)
    {
        return (skaiciai[skaiciai.size() / 2 - 1] + skaiciai[skaiciai.size() / 2]) / 2;
    }
    else
    {
        return skaiciai[skaiciai.size() / 2];
    }
}
void spausdinimas(vector<string> vardai, vector<string> pavardes, vector<double>galutinis1, vector<double> galutiniai, vector<double> galutiniai2)
{
    cout << setw(10) << "Vardas" << setw(25) << "Pavarde" << setw(25) << "Galutinis" << setw(25) << "Vidurkis" << setw(25) << "Mediana" << endl;
    cout << "---------------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < vardai.size(); i++) {

        cout << setw(5) << vardai[i] << setw(25) << pavardes[i] << setw(25) << galutinis1[i] << setw(25) << galutiniai[i] << setw(25) << galutiniai2[i] << endl;

    }
}
bool isNumber(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;

    return true;
}
