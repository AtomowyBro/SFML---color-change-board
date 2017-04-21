#include "field.h"


void field::drawfield(sf::RenderWindow & win) //?
{
	win.draw(pole);
}

bool field::isflage()
{
	return bflage;
}

void field::change_flage() //odkrywanie pola
{
	if (bflage)
		bflage = false;
	else
		bflage = true;
}

void field::setpos(int x, int y) //metoda potrzebna do zmiany pozycji pola
{
	pole.setPosition(x, y);
}

void field::color_covered()
{
	pole.setFillColor(covered);
}

void field::color_uncovered()
{
	pole.setFillColor(uncovered);
}

void field::color_uncovered_near()
{
	pole.setFillColor(uncovered_near);
}

void field::color_mine()
{
	pole.setFillColor(mine);
}

void field::color_flage()
{
	pole.setFillColor(flage);
}

void field::place_mine() //umieszcza mine na polu
{
	bmine = true;
}

void field::uncover() // odkrywa pole
{
	bcovered = false;
}

bool field::ismine() //sprawdza czy pole ma mine
{
	if (bmine)
		return true;
	else
		return false;
}

bool field::iscovered() //sprawdzam czy jest zakryte
{
	return bcovered;
}
