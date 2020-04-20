#include <iostream>
#include <vector>
#include <fstream>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

struct uczen
{
        string imie, nazwisko, pesel, adres;
        int numer;
};

class klasa
{
                vector <struct uczen> spis;
       
        public:
                void wprowadz();
                void wypisz();
                void zapiszDoPliku(const char *);
	            void wczytajZPliku(const char *);                
};

void klasa::wprowadz()
{

        
                 //TU WSTAW do tablicy nowy rekord
        
}


void klasa::wypisz()
{
        for (vector<struct uczen>::iterator it = spis.begin(); it != spis.end(); ++it)
        {
                cout << it->numer << " "
                         << it->imie << " "
                         << it->nazwisko << " "
                         << it->pesel << " "
                         << it->adres << "\n";
        }
}

void klasa::wczytajZPliku(const char *)
{
	fstream plik;
	string imie, nazwisko, pesel, adres;
	int numer;
	plik.open("C:\\Users\\Eryk\\Desktop\\Files\\druga_iteracja_vectora\\y.txt", ios::in); 
   		if(plik.good())  
            while(!plik.eof())  
                  {
                   //getline(plik,napis);  
                   plik >> numer >> imie >> nazwisko >> pesel >> adres;
                   cout << numer << "\n" << imie << "\n" << nazwisko << "\n" << pesel << "\n" << adres << "\n";
                   cout<<endl;
                   	struct uczen wprowadzany;
		                cout << "Nr Imie Nazwisko Pesel Adres: ";
		                  	wprowadzany.numer = numer;
		                    wprowadzany.imie = imie;
		                	wprowadzany.nazwisko = nazwisko;
		                    wprowadzany.pesel = pesel;
		                    wprowadzany.adres = adres;
		            spis.push_back(wprowadzany);
                   }
                   plik.close();
}

void klasa::zapiszDoPliku(const char *nazwa)
{
        ofstream plik;
        plik.open(nazwa);
        for (vector<struct uczen>::iterator it = spis.begin(); it != spis.end(); ++it)
        {
                plik << "[\n {\n\"numer\" : \"" << it->numer << "\"\n }\n\n"
                         << " {\n\"imie\" : \"" << it->imie << "\"\n }\n\n"
                         << " {\n\"nazwisko\" : \"" << it->nazwisko << "\"\n }\n\n"
                         << " {\n\"pesel\" : \"" << it->pesel << "\"\n }\n\n"
                         << " {\n\"adres\" : \"" << it->adres << "\"\n }\n]";
        }
        plik.close();  
}


int main(int argc, char** argv) {
        klasa TI;
        TI.wczytajZPliku("C:\\Users\\Eryk\\Desktop\\Files\\druga_iteracja_vectora\\y.txt");
        TI.wprowadz();
        TI.wypisz();
        TI.zapiszDoPliku("C:\\Users\\Eryk\\Desktop\\Files\\druga_iteracja_vectora\\x.txt");
        
        return 0;
}
