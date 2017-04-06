#include <SFML/Graphics.hpp>

const int Wys_planszy = 10;
const int Sze_planszy = 10;
const int Wys_pola = 20;
const int Sze_pola = 20;

class field
{
	sf::Color covered, uncovered; //dwa kolory dla odkrytego i zakrytego
	bool bcovered; // zamiana koloru
	sf::RectangleShape pole; // prostokat o nazwie pole

public:
	field();
	void uncover(); // zmiana bcovered => zmiana koloru
	void setpos(int x, int y); // ustawienie pozycji pola
	void drawfield(sf::RenderWindow & win); // ?
};

class board
{
	field tablica[Wys_planszy][Sze_planszy]; // tablica klas field
public:
	board(); // 
	void board::odkryj(int kol, int wie); // odkrywanie konkretnego pola
	void drawboard(sf::RenderWindow & win); //?
};

int main()
{
	sf::RenderWindow Okno(sf::VideoMode(Wys_pola*Wys_planszy, Sze_pola*Sze_planszy),"Test");

	board plansza; //deklaracja 

	while (Okno.isOpen())
	{
		sf::Event zdarzenie;

		while (Okno.pollEvent(zdarzenie))
		{
			if (zdarzenie.type == sf::Event::Closed)
				Okno.close();

			if (zdarzenie.type == sf::Event::MouseButtonPressed) //kod skopiowany z przykladow k6
			{
				if (zdarzenie.mouseButton.button == sf::Mouse::Right)
				{
					int wiersz = sf::Mouse::getPosition(Okno).y / Sze_planszy;
					int kolumna = sf::Mouse::getPosition(Okno).x / Wys_planszy;
					plansza.odkryj(kolumna, wiersz); // albo na odwrót - zale¿nie jak to sobie zdefiniowaliœcie
				}
			}
		}

		Okno.clear();

		plansza.drawboard(Okno); 

		Okno.display();
	}
	return 0;
}

field::field()
{
	covered = sf::Color::Black; //zakryte ma kolor czarny 
	uncovered = sf::Color::Blue; //odkryte kolor niebieski
	bcovered = true; // domyslnie zakryte
	pole.setSize(sf::Vector2f(Wys_pola, Sze_pola)); //rozmiary prostakata 
}

void field::drawfield(sf::RenderWindow & win) //?
{
	win.draw(pole);
}

board::board()
{
	for (int i = 0;i < Wys_planszy;i++)
	{
		for (int j = 0;j < Sze_planszy;j++)
		{
			tablica[i][j].setpos(i*Wys_pola, j*Sze_pola); // powinno ustawiac pole w zalerznosci od [i][j]
		}
	}
}

void board::drawboard(sf::RenderWindow & win) // kod wzorowany na https://github.com/gshopov/SFML-Minesweeper/blob/master/MineField.cpp crl + f (draw)
{
	for (int i = 0;i < Wys_planszy;i++)
	{
		for (int j = 0;j < Sze_planszy;j++)
		{
			tablica[i][j].drawfield(win);
		}
	}
}
void field::setpos(int x, int y) //metoda potrzebna do zmiany pozycji pola
{
	pole.setPosition(x, y);
}

void board::odkryj(int kol, int wie) //odkrywanie konkretnego pola
{
	tablica[kol][wie].uncover();
}

void field::uncover() //odkrywanie pola
{
	bcovered = false;
}