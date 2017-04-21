#include"board.h"
#include"field.h"


const int Wys_pola1 = 20;
const int Sze_pola1 = 20;
const int M = 10;
const int N = 10;


board::board()
{
	for (int i = 0;i < Wys_planszy;i++)
	{
		for (int j = 0;j < Sze_planszy;j++)
		{
			tablica[i][j].setpos(i*Wys_pola1, j*Sze_pola1); // powinno ustawiac pole w zalerznosci od [i][j]
		}
	}
}

bool board::iscovered(int x, int y)
{
	return tablica[x][y].iscovered();
}

void board::drawboard(sf::RenderWindow & win) // 
{
	for (int i = 0;i < Wys_planszy;i++)
	{
		for (int j = 0;j < Sze_planszy;j++)
		{
			tablica[i][j].drawfield(win);
			if (!tablica[i][j].isflage() && tablica[i][j].iscovered())
				tablica[i][j].color_covered();
			else if (tablica[i][j].isflage() && tablica[i][j].iscovered())
				tablica[i][j].color_flage();
			else if (!tablica[i][j].iscovered() && !count_mines(i, j))
				tablica[i][j].color_uncovered();
			else if (!tablica[i][j].iscovered() && count_mines(i, j) && !hasMine(i, j))
				tablica[i][j].color_uncovered();
			else if (!tablica[i][j].iscovered() && hasMine(i, j))
				tablica[i][j].color_mine();
		}
	}
}

void board::change_flage(int x, int y)
{
	tablica[x][y].change_flage();
}

void board::deploy_mines(int n, bool random)
{
	bool good = true;
	if (n > M*N) // sprawdzam czy nie jest za duzo min
	{
		good = false;
		std::cout << "Za duzo min" << std::endl;
	}
	if (random&&good) // jezeli wybralismy rozmieszczenie losowe rozmieszczamy miny z rozna szansa do momentu skonczenia sie min
	{
		while (good && n > 0)
		{
			for (int i = 0; i < M; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if (n>0 && !tablica[i][j].ismine()) // jezeli nie ma miny losujemy
						if (std::rand() % 10 == 0)
						{
							tablica[i][j].place_mine();
							n--;
						}

				}
			}
		}
	}
	else if (!random) //jezeli wylaczymy random miny sa ukladane po przekatnej
	{
		int i = 0;
		int j = 0;
		while (i < M && j < N)
		{
			tablica[i][j].place_mine();
			i++;
			j++;
		}
	}
}

bool board::hasMine(int x, int y) // sprawdza czy konkretne pole ma mine
{
	if (tablica[x][y].ismine())
		return true;
	else
		return false;
}

int board::count_mines(int x, int y)
{
	int ile_min = 0;
	int i = 0; //zmienne ktore beda pomocne przy ilosci pol w zaleznosci od tego ktore pole odkrywamy (6 przy krawedzi, 4 w rogu, 9 w srodku)
	int j = 0;
	int i_max = 3;
	int j_max = 3;
	if (x == 0) //dzieki tym zmiennym moge wszystkie mozliwosci wykonac w jednej petli
	{
		i = 1;
	}
	if (y == 0)
	{
		j = 1;
	}
	if (x == M - 1)
	{
		i_max = 2;
	}
	if (y == N - 1)
	{
		j_max = 2;
	}
	for (int i_pom = i;i_pom < i_max;i_pom++) //jestem w stanie przeszukiwac 3x3,2x3,3x2,1x3,3x1,1x2,2x1 i 1x1
	{
		for (int j_pom = j;j_pom < j_max;j_pom++) //dzieki i_pom i j_pom jestem w stanie korygowac i ustawiac wczesniej zadana wartosc
		{
			if (hasMine(x - 1 + i_pom, y - 1 + j_pom))
				ile_min++;
		}
	}
	return ile_min;
}

void board::odkryj(int x, int y)
{
	tablica[x][y].uncover();
	//	if(x<0||x>=M||)
	if (!count_mines(x, y))
	{
		int i = 0; //zmienne ktore beda pomocne przy ilosci pol w zaleznosci od tego ktore pole odkrywamy (6 przy krawedzi, 4 w rogu, 9 w srodku)
		int j = 0;
		int i_max = 3;
		int j_max = 3;
		if (x == 0) //dzieki tym zmiennym moge wszystkie mozliwosci wykonac w jednej petli
		{
			i = 1;
		}
		if (y == 0)
		{
			j = 1;
		}
		if (x == M - 1)
		{
			i_max = 2;
		}
		if (y == N - 1)
		{
			j_max = 2;
		}
		for (int i_pom = i;i_pom < i_max;i_pom++) //jestem w stanie przeszukiwac 3x3,2x3,3x2,1x3,3x1,1x2,2x1 i 1x1
		{
			for (int j_pom = j;j_pom < j_max;j_pom++) //dzieki i_pom i j_pom jestem w stanie korygowac i ustawiac wczesniej zadana wartosc
			{
				//tab[x-1+i_pom][y-1+j_pom].Uncover(); //stara opcja
				if (tablica[x - 1 + i_pom][y - 1 + j_pom].iscovered()) //nowa lepsza jezeli pobliskie pole jest zakryte to rekurenkcyjnie wywoluja ta funkcje na tamtym polu
					odkryj(x - 1 + i_pom, y - 1 + j_pom);
			}
		}
	}
}

bool board::isflage(int x, int y)
{
	return tablica[x][y].isflage();
}