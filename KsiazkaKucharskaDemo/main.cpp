#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <list>
#include <conio.h>
#include <windows.h>
#include <fstream>

using namespace std;

enum class Typ_potrawy { owoc, warzywo, mieso, nabial, zbozowe, inne };

class Produkt
{
private:
	string nazwa, ilosc;
	Typ_potrawy typ;


	void napis_jako_typ()
	{
		int wybor;
		cout << "Podaj odpowiedni nr: 1.owoc 2.warzywo 3.mieso 4.nabial 5.zbozowe 6.inne" << endl;
		cin >> wybor;
		switch (wybor)
		{
		case 1:
		{
			typ = Typ_potrawy::owoc;
		}break;
		case 2:
		{
			typ = Typ_potrawy::warzywo;
		}break;
		case 3:
		{
			typ = Typ_potrawy::mieso;
		}break;
		case 4:
		{
			typ = Typ_potrawy::nabial;
		}break;
		case 5:
		{
			typ = Typ_potrawy::zbozowe;
		}break;
		case 6:
		{
			typ = Typ_potrawy::inne;
		}break;
		default:
			break;
		}
	}

public:

	Produkt() :nazwa("domyslne"), ilosc("domyslne"), typ(Typ_potrawy::inne) {}

	Produkt(string nazwa, string ilosc, Typ_potrawy typ) :nazwa(nazwa), ilosc(ilosc), typ(typ)
	{

	}

	~Produkt()
	{

	}

	string typ_jako_napis()
	{
		switch (typ)
		{
		case Typ_potrawy::owoc:
		{
			return "owoc";
		}
		break;
		case Typ_potrawy::warzywo:
		{
			return "warzywo";
		}
		break;
		case Typ_potrawy::mieso:
		{
			return "mieso";
		}
		break;
		case Typ_potrawy::nabial:
		{
			return "nabial";
		}
		break;
		case Typ_potrawy::zbozowe:
		{
			return "zbozowe";
		}
		case Typ_potrawy::inne:
		{
			return "inne";
		}
		break;
		default:
		{
			return "nieznany";
		}
		break;
		}
	}




	void ustaw_nazwe()
	{
		cout << "Podaj nazwê sk³adnika" << endl;
		cin >> nazwa;
	}

	void ustaw_typ()
	{
		napis_jako_typ();
	}

	void ustaw_ilosc()
	{
		cout << "Podaj ilosc" << endl;
		cin >> ilosc;
	}
	string get_nazwa() { return this->nazwa; }
	string get_ilosc() { return this->ilosc; }




	friend ostream& operator<<(ostream &out, Produkt &produkt);



};

ostream& operator<<(ostream &out, Produkt &produkt)
{
	return out << produkt.nazwa << " " << produkt.ilosc << endl;
}



class Posilek
{
protected:
	string nazwa, przepis;

	vector<Produkt> produkty;

public:
	Posilek(string nazwa, string ilosc, string przepis) :nazwa(nazwa), przepis(przepis) {}

	virtual void dodaj_skladnik()
	{
		int liczba = 1;
		while (liczba == 1)
		{
			Produkt produkt;
			produkt.ustaw_nazwe();
			produkt.ustaw_ilosc();
			produkt.ustaw_typ();
			produkty.push_back(produkt);
			cout << "Czy dodac kolejny skladnik? 1. Tak 2.Nie" << endl;
			cin >> liczba;
			if (liczba != 1)
			{
				cout << "Podaj przepis: ";
				cin.ignore();
				getline(cin, przepis);
			}
		}
	}



	virtual void wypisz_posilek()
	{
		HANDLE hOut;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
		cout << "Nazwa potrawy: " << this->nazwa << endl;
		cout << "===============================" << endl;
		cout << "Skladniki" << endl;
		cout << endl;
		for (auto it = produkty.begin(); it != produkty.end(); it++)
		{
			cout << *it << endl;
		}
		cout << "Przepis" << endl;
		cout << this->przepis << endl;


	}

	virtual string get_nazwa() { return this->nazwa; }
	virtual string get_przepis() { return this->przepis; }

	virtual vector<Produkt> get_produkty() { return this->produkty; }
};




class Sniadanie : public Posilek
{
private:

public:
	Sniadanie(string nazwa, string ilosc, string przepis) :Posilek((nazwa), (ilosc), (przepis)) {}


};

class Obiad : public Posilek
{
private:

public:
	Obiad(string nazwa, string ilosc, string przepis) :Posilek((nazwa), (ilosc), (przepis)) {}

};

class Kolacja : public Posilek
{
private:

public:
	Kolacja(string nazwa, string ilosc, string przepis) :Posilek((nazwa), (ilosc), (przepis)) {}

};


class Deser : public Posilek
{
private:

public:
	Deser(string nazwa, string ilosc, string przepis) :Posilek((nazwa), (ilosc), (przepis)) {}

};




class Interfejs
{

	int wybor;
public:
	void menu()
	{
		list<Sniadanie> lista_sniadan;
		list<Obiad> lista_obiadow;
		list<Kolacja> lista_kolacji;
		list<Deser> lista_deserow;


		for (;;)
		{
			HANDLE hOut;
			hOut = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
			cout << endl;
			cout << "1: Dodaj sniadanie" << endl;
			cout << "2: Wyswietl sniadania" << endl;
			cout << "3: Usun sniadanie" << endl;
			cout << "4: Dodaj obiad" << endl;
			cout << "5: Wyswietl obiady" << endl;
			cout << "6: Usun obiad" << endl;
			cout << "7: Dodaj kolacje" << endl;
			cout << "8: Wyswietl kolacje" << endl;
			cout << "9: Usun kolacje" << endl;
			cout << "10: Dodaj deser" << endl;
			cout << "11: Wyswietl desery" << endl;
			cout << "12: Usun deser" << endl;
			cout << "13 Wyjscie z programu " << endl;

			cin >> wybor;
			switch (wybor)
			{
			case 1:
			{
				string nazwa, ilosc, przepis;
				cout << "Podaj nazwe posilku" << endl;
				getline(cin, nazwa);
				getline(cin, nazwa);
				Sniadanie sniadanie(nazwa, ilosc, przepis);

				sniadanie.dodaj_skladnik();
				lista_sniadan.push_back(sniadanie);

				system("cls");

			}break;
			case 2:
			{
				HANDLE hOut;
				hOut = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
				int licznik1 = 0;
				for (auto it = lista_sniadan.begin(); it != lista_sniadan.end(); it++)
				{
					++licznik1;
					cout << licznik1 << " ";
					(*it).wypisz_posilek();
					cout << endl;
				}
			}break;

			case 3:
			{
				int licznik2 = 0;
				for (auto it = lista_sniadan.begin(); it != lista_sniadan.end(); it++)
				{
					++licznik2;
					cout << licznik2 << " ";
					(*it).wypisz_posilek();
					cout << endl;
				}

				int licznik3 = 0;
				int pozycja;
				cin >> pozycja;
				for (auto it = lista_sniadan.begin(); it != lista_sniadan.end();)
				{
					licznik3++;
					if (licznik3 == pozycja)
						it = lista_sniadan.erase(it);
					else
						++it;
				}
			}break;
			case 4:
			{
				string nazwa, ilosc, przepis;
				cout << "Podaj nazwe posilku" << endl;
				getline(cin, nazwa);
				getline(cin, nazwa);
				Obiad obiad(nazwa, ilosc, przepis);

				obiad.dodaj_skladnik();
				lista_obiadow.push_back(obiad);
				system("cls");
			}break;

			case 5:
			{
				HANDLE hOut;
				hOut = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
				int licznik4 = 0;
				for (auto it = lista_obiadow.begin(); it != lista_obiadow.end(); it++)
				{
					++licznik4;
					cout << licznik4 << " ";
					(*it).wypisz_posilek();
					cout << endl;
				}
			}break;

			case 6:
			{
				int licznik5 = 0;
				for (auto it = lista_obiadow.begin(); it != lista_obiadow.end(); it++)
				{
					++licznik5;
					cout << licznik5 << " ";
					(*it).wypisz_posilek();
					cout << endl;
				}

				int licznik6 = 0;
				int pozycja;
				cin >> pozycja;
				for (auto it = lista_obiadow.begin(); it != lista_obiadow.end();)
				{
					licznik6++;
					if (licznik6 == pozycja)
						it = lista_obiadow.erase(it);
					else
						++it;
				}
			}break;

			case 7:
			{
				string nazwa, ilosc, przepis;
				cout << "Podaj nazwe posilku" << endl;
				getline(cin, nazwa);
				getline(cin, nazwa);
				Kolacja kolacja(nazwa, ilosc, przepis);

				kolacja.dodaj_skladnik();
				lista_kolacji.push_back(kolacja);
				system("cls");
			}break;

			case 8:
			{
				HANDLE hOut;
				hOut = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
				int licznik7 = 0;
				for (auto it = lista_kolacji.begin(); it != lista_kolacji.end(); it++)
				{
					++licznik7;
					cout << licznik7 << " ";
					(*it).wypisz_posilek();
					cout << endl;
				}
			}break;

			case 9:
			{
				int licznik8 = 0;
				for (auto it = lista_kolacji.begin(); it != lista_kolacji.end(); it++)
				{
					++licznik8;
					cout << licznik8 << " ";
					(*it).wypisz_posilek();
					cout << endl;
				}

				int licznik9 = 0;
				int pozycja;
				cin >> pozycja;
				for (auto it = lista_kolacji.begin(); it != lista_kolacji.end();)
				{
					licznik9++;
					if (licznik9 == pozycja)
						it = lista_kolacji.erase(it);
					else
						++it;
				}
			}break;

			case 10:
			{
				string nazwa, ilosc, przepis;
				cout << "Podaj nazwe posilku" << endl;
				getline(cin, nazwa);
				getline(cin, nazwa);
				Deser deser(nazwa, ilosc, przepis);

				deser.dodaj_skladnik();
				lista_deserow.push_back(deser);
				system("cls");
			}break;

			case 11:
			{
				HANDLE hOut;
				hOut = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
				int licznik10 = 0;
				for (auto it = lista_deserow.begin(); it != lista_deserow.end(); it++)
				{
					++licznik10;
					cout << licznik10 << " ";
					(*it).wypisz_posilek();
					cout << endl;
				}
			}break;

			case 12:
			{
				int licznik11 = 0;
				for (auto it = lista_deserow.begin(); it != lista_deserow.end(); it++)
				{
					++licznik11;
					cout << licznik11 << " ";
					(*it).wypisz_posilek();
					cout << endl;
				}

				int licznik = 0;
				int pozycja;
				cin >> pozycja;
				for (auto it = lista_deserow.begin(); it != lista_deserow.end();)
				{
					licznik++;
					if (licznik == pozycja)
						it = lista_deserow.erase(it);
					else
						++it;
				}
			}break;
			case 13:
			{
				exit(0);
			}

			case 14:
			{
				fstream plik;
				plik.open("sniadania.txt", ios::out);

				for (auto it = lista_sniadan.begin(); it != lista_sniadan.end(); it++)
				{
					string nazwa_potrawy = (*it).get_nazwa();


					plik << nazwa_potrawy;
					plik << endl;
					std::vector<Produkt> produkty = (*it).get_produkty();
					for (int i = 0; i < produkty.size(); i++)
					{
						string nazwa_produktu = produkty[i].get_nazwa();
						string ilosc = produkty[i].get_ilosc();
						string typ = produkty[i].typ_jako_napis();

						plik << nazwa_produktu << " " << ilosc << " " << typ << endl;

					}
					string przepis = (*it).get_przepis();
					plik << "Przepis" << endl;
					plik << przepis << endl;
				}
				cout << "Zapisano w pliku" << endl;
				plik.close();

			}break;


			default:
				break;
			}

		}
	}
	void zapis();
	void odczyt();
};


int main()
{
	Interfejs program;
	program.menu();
	int x;
	cin >> x;

	return 0;
}