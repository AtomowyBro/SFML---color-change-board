#include <SFML/Graphics.hpp>
#include <time.h>
#include <stdlib.h>
#include "field.h"
#include "board.h"
#include "menu.h"

const int Wys_planszy1 = 10;
const int Sze_planszy1 = 10;
const int Wys_pola2 = 20;
const int Sze_pola2 = 20;

int main()
{

	bool graj = false;
	bool wyjscie = false;
	while (!wyjscie)
	{
		sf::RenderWindow Menu(sf::VideoMode(400, 300), "Menu");

		sf::Font font;

		bool latwy = false;
		bool sredni = false;
		bool trudny = false;
		int ile_min;
		bool random = true;

		font.loadFromFile("arial.ttf");
		std::string napis = "Saper", Sgraj = "Graj", S10x10 = "Latwy", S20x20 = "Sredni", S30x30 = "Trudny", Imie = "Michal", Nazwisko = "Sokolowski", Nr_indeksu = "234976";
		sf::Text atext,Tgraj,T10x10,T20x20,T30x30,TImie,TNazwisko,TNr_indeksu;
		atext.setFont(font);
		atext.setCharacterSize(20);
		atext.setStyle(sf::Text::Bold);
		atext.setPosition(200, 50);
		atext.setString(napis);

		Tgraj.setFont(font);
		Tgraj.setCharacterSize(20);
		Tgraj.setStyle(sf::Text::Bold);
		Tgraj.setPosition(200, 100);
		Tgraj.setString(Sgraj);

		T10x10.setFont(font);
		T10x10.setCharacterSize(20);
		T10x10.setStyle(sf::Text::Bold);
		T10x10.setPosition(100, 150);
		T10x10.setString(S10x10);

		T20x20.setFont(font);
		T20x20.setCharacterSize(20);
		T20x20.setStyle(sf::Text::Bold);
		T20x20.setPosition(200, 150);
		T20x20.setString(S20x20);

		T30x30.setFont(font);
		T30x30.setCharacterSize(20);
		T30x30.setStyle(sf::Text::Bold);
		T30x30.setPosition(300, 150);
		T30x30.setString(S30x30);

		TImie.setFont(font);
		TImie.setCharacterSize(20);
		TImie.setStyle(sf::Text::Bold);
		TImie.setPosition(100, 0);
		TImie.setString(Imie);

		TNazwisko.setFont(font);
		TNazwisko.setCharacterSize(20);
		TNazwisko.setStyle(sf::Text::Bold);
		TNazwisko.setPosition(175, 0);
		TNazwisko.setString(Nazwisko);

		TNr_indeksu.setFont(font);
		TNr_indeksu.setCharacterSize(20);
		TNr_indeksu.setStyle(sf::Text::Bold);
		TNr_indeksu.setPosition(300, 0);
		TNr_indeksu.setString(Nr_indeksu);

		main_window window;
		window.text_change("Graj");
		while (Menu.isOpen())
		{
			sf::Event Menu_event;

			while (Menu.pollEvent(Menu_event))
			{
				if (Menu_event.type == sf::Event::Closed)
				{
					Menu.close();
					wyjscie = true;
					graj = false;
				}
				if (Menu_event.type == sf::Event::MouseButtonPressed) //Proste menu z mozliwoscia wyboru trudnosci, bez trudnosci ustawiane jest po przeketnej
				{
					if (Menu_event.mouseButton.button == sf::Mouse::Left)
					{
						if (sf::Mouse::getPosition(Menu).x >= 200 && sf::Mouse::getPosition(Menu).x <= 280 && sf::Mouse::getPosition(Menu).y >= 100 && sf::Mouse::getPosition(Menu).y <= 140)
						{
							{
								Menu.close();
								graj = true;
								if (!latwy && !sredni&&!trudny)
								{
									random = false;
									ile_min = 0;
								}
								else if (latwy)
								{
									random = true;
									ile_min = 4;
								}
								else if (sredni)
								{
									random = true;
									ile_min = 8;
								}
								else if (trudny)
								{
									random = true;
									ile_min = 16;
								}
							}
						}
						if (sf::Mouse::getPosition(Menu).x >= 100 && sf::Mouse::getPosition(Menu).x <= 180 && sf::Mouse::getPosition(Menu).y >= 150 && sf::Mouse::getPosition(Menu).y <= 230)
						{
							{
								window.change_active(0);
								window.to_inactive(1, 2);
								if (latwy)
									latwy = false;
								else
									latwy = true;
								sredni = false;
								trudny = false;
							}
						}
						if (sf::Mouse::getPosition(Menu).x >= 200 && sf::Mouse::getPosition(Menu).x <= 280 && sf::Mouse::getPosition(Menu).y >= 150 && sf::Mouse::getPosition(Menu).y <= 230)
						{
							{
								window.change_active(1);
								window.to_inactive(0, 2);
								if (sredni)
									sredni = false;
								else
									sredni = true;
								latwy = false;
								trudny = false;
							}
						}
						if (sf::Mouse::getPosition(Menu).x >= 300 && sf::Mouse::getPosition(Menu).x <= 380 && sf::Mouse::getPosition(Menu).y >= 150 && sf::Mouse::getPosition(Menu).y <= 230)
						{
							{
								window.change_active(2);
								window.to_inactive(0, 1);
								if (trudny)
									trudny = false;
								else
									trudny = true;
								sredni = false;
								latwy = false;
							}
						}
					}
				}
			}
			Menu.clear();

			window.draw(Menu);


			Menu.draw(atext);
			Menu.draw(Tgraj);		
			Menu.draw(T10x10);		
			Menu.draw(T20x20);
			Menu.draw(T30x30);
			Menu.draw(TImie);
			Menu.draw(TNazwisko);
			Menu.draw(TNr_indeksu);


			

			Menu.display();

		}
		if (graj)
		{
			sf::Text text_ilosc_min[Wys_planszy1][Sze_planszy1]; // tablica sf::text



			sf::RenderWindow Okno(sf::VideoMode(Wys_pola2*Wys_planszy, Sze_pola2*Sze_planszy), "Saper");
			srand(time(0));
			board plansza;
			plansza.deploy_mines(ile_min, random);//deklaracja
			bool wygrana = false;

			int ilosc_min = 0;

			for (int i = 0;i < Wys_planszy1;i++) //zliczam miny na planszy
			{
				for (int j = 0;j < Sze_planszy1;j++)
				{
					if (plansza.hasMine(i, j))
						ilosc_min++;
				}
			}

			for (int i = 0;i < Wys_planszy1;i++) //tworze tablice sf::Text i zminiam polozenie, i zawartosc kazdego w zaleznosci od ilosci min
			{
				for (int j = 0;j < Sze_planszy1;j++)
				{
					text_ilosc_min[i][j].setFont(font);
					text_ilosc_min[i][j].setFillColor(sf::Color::Green);
					text_ilosc_min[i][j].setCharacterSize(20);
					text_ilosc_min[i][j].setPosition(i*Wys_pola, j*Sze_pola);
					if (plansza.count_mines(i, j)&&!plansza.hasMine(i,j))
					{
						text_ilosc_min[i][j].setString(static_cast<char>(plansza.count_mines(i,j)+48)); //zamieniam int na char i dodaje 48 aby wyswietlal poprawne ascii
					}
				}
			}

			while (Okno.isOpen())
			{
				sf::Event zdarzenie;

				int ilosc_zakrytych = 0;

				for (int i = 0;i < Wys_planszy1;i++) // zliczam zawsze od nowa ilosc zakrytych
				{
					for (int j = 0;j < Sze_planszy;j++)
					{
						if (plansza.iscovered(i, j))
							ilosc_zakrytych++;
					}
				}
				if (ilosc_min == ilosc_zakrytych) // jezeli jest tyle samo zakrytych co min koncze gre i wygrywam
				{
					wygrana = true;
					Okno.close();
				}

				while (Okno.pollEvent(zdarzenie))
				{
					if (zdarzenie.type == sf::Event::Closed)
						Okno.close();

					if (zdarzenie.type == sf::Event::MouseButtonPressed) //kod skopiowany z przykladow k6
					{
						if (zdarzenie.mouseButton.button == sf::Mouse::Right)
						{
							int wiersz = sf::Mouse::getPosition(Okno).y / Sze_pola2;
							int kolumna = sf::Mouse::getPosition(Okno).x / Wys_pola2;
							plansza.change_flage(kolumna, wiersz); // albo na odwrót - zale¿nie jak to sobie zdefiniowaliœcie
						}
						if (zdarzenie.mouseButton.button == sf::Mouse::Left)
						{
							int wiersz = sf::Mouse::getPosition(Okno).y / Sze_pola2;
							int kolumna = sf::Mouse::getPosition(Okno).x / Wys_pola2;
							if (!plansza.isflage(kolumna, wiersz))
							{
								plansza.odkryj(kolumna, wiersz);
								if (plansza.hasMine(kolumna, wiersz)) //jezeli odkryjemy pole z mina nastepuje koniec gry
								{
									Okno.close();
								}
							}
						}
					}
				}
				
				Okno.clear();
				plansza.drawboard(Okno); // rysuje plansze
				for (int i = 0;i < Wys_planszy1;i++) //nad plansza rysuje liczby
				{
					for (int j = 0;j < Sze_planszy1;j++)
					{
						Okno.draw(text_ilosc_min[i][j]);
					}
				}



				Okno.display();
			}
			if (wygrana)
			{

				sf::Font font;
				sf::RenderWindow oknoWygrana(sf::VideoMode(200, 40), "Wygrana");
				font.loadFromFile("arial.ttf");
				std::string napis = "Wygrales! :D";
				sf::Text atext;
				atext.setFont(font);
				atext.setCharacterSize(20);
				atext.setStyle(sf::Text::Bold);
				atext.setPosition(0, 0);

				atext.setString(napis);
				while (oknoWygrana.isOpen())
				{
					sf::Event close;
					while (oknoWygrana.pollEvent(close))
					{
						if (close.type == sf::Event::Closed)
							oknoWygrana.close();
					}
					oknoWygrana.clear();
					oknoWygrana.draw(atext);
					oknoWygrana.display();
				}
			}
			else if (!wygrana)
			{

				sf::Font font;
				sf::RenderWindow oknoPrzegrana(sf::VideoMode(200, 40), "Przegrana");
				font.loadFromFile("arial.ttf");
				std::string napis = "Przegrales :(";
				sf::Text atext;
				atext.setFont(font);
				atext.setCharacterSize(20);
				atext.setStyle(sf::Text::Bold);
				atext.setPosition(0, 0);

				atext.setString(napis);
				while (oknoPrzegrana.isOpen())
				{
					sf::Event close;
					while (oknoPrzegrana.pollEvent(close))
					{
						if (close.type == sf::Event::Closed)
						oknoPrzegrana.close();
					}
					oknoPrzegrana.clear();
					oknoPrzegrana.draw(atext);
					oknoPrzegrana.display();
				}
			}
		}
	}
	return 0;
}



