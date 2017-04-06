#include <SFML/Graphics.hpp>

const int Wys_planszy = 10;
const int Sze_planszy = 10;
const int Wys_pola = 20;
const int Sze_pola = 20;

class field
{
	sf::Color covered, uncovered;
	bool bcovered;
	sf::RectangleShape pole;

public:
	field();
	void uncover();
	void setpos(int x, int y);
	void drawfield(sf::RenderWindow & win);
};

class board
{
	field tablica[Wys_planszy][Sze_planszy];
public:
	board();
	void board::odkryj(int kol, int wie);
	void drawboard(sf::RenderWindow & win);
};

int main()
{
	sf::RenderWindow Okno(sf::VideoMode(Wys_pola*Wys_planszy, Sze_pola*Sze_planszy),"Test");

	board plansza;

	while (Okno.isOpen())
	{
		sf::Event zdarzenie;

		while (Okno.pollEvent(zdarzenie))
		{
			if (zdarzenie.type == sf::Event::Closed)
				Okno.close();

			if (zdarzenie.type == sf::Event::MouseButtonPressed)
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
	covered = sf::Color::Black;
	uncovered = sf::Color::Blue;
	bcovered = true;
	pole.setSize(sf::Vector2f(Wys_pola, Sze_pola));
}

void field::drawfield(sf::RenderWindow & win)
{
	win.draw(pole);
}

board::board()
{
	for (int i = 0;i < Wys_planszy;i++)
	{
		for (int j = 0;j < Sze_planszy;j++)
		{
			tablica[i][j].setpos(i*Wys_pola, j*Sze_pola);
		}
	}
}

void board::drawboard(sf::RenderWindow & win)
{
	for (int i = 0;i < Wys_planszy;i++)
	{
		for (int j = 0;j < Sze_planszy;j++)
		{
			tablica[i][j].drawfield(win);
		}
	}
}
void field::setpos(int x, int y)
{
	pole.setPosition(x, y);
}

void board::odkryj(int kol, int wie)
{
	tablica[kol][wie].uncover();
}

void field::uncover()
{
	bcovered = false;
}