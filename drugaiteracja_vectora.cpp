#include <iostream>
#include <vector>
#include <fstream>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

struct uczen
{
        string imie, nazwisko;
        int numer;
};

class klasa
{
                vector <struct uczen> spis;
       
        public:
                void wprowadz();
                void wypisz();
                void zapiszDoPliku(const char *);
//              void wczytajZPliku(const char *);                
};

void klasa::wprowadz()
{
        int iloscUczniow;
        struct uczen wprowadzany;
        cout << "Ilosc uczniow: ";
        cin  >> iloscUczniow;
        for (int i=0; i<iloscUczniow; i++)
        {
                cout << "Nr Imie Nazwisko: ";
                cin >> wprowadzany.numer
                        >> wprowadzany.imie
                        >> wprowadzany.nazwisko;
                spis.push_back(wprowadzany); //TU WSTAW do tablicy nowy rekord
        }
}


void klasa::wypisz()
{
        for (vector<struct uczen>::iterator it = spis.begin(); it != spis.end(); ++it)
        {
                cout << it->numer << " "
                         << it->imie << " "
                         << it->nazwisko << "\n";
        }
}



void klasa::zapiszDoPliku(const char *nazwa)
{
        ofstream plik;
        plik.open(nazwa);
        for (vector<struct uczen>::iterator it = spis.begin(); it != spis.end(); ++it)
        {
                plik << it->numer << " "
                         << it->imie << " "
                         << it->nazwisko << "\n";
        }
        plik.close();  
}



int main(int argc, char** argv) {
        klasa TI;
        TI.wprowadz();
        TI.wypisz();
        TI.zapiszDoPliku("c:\\a.txt");
        return 0;
}
