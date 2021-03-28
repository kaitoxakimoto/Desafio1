#include <iostream>
#include <stdio.h>
#include <list>
#include "sudoku.h"

using namespace std;

int main()
{
	State prueba;

	prueba.setCasilla(1, 4, 2);
	prueba.setCasilla(1, 6, 4);
	prueba.setCasilla(1, 7, 8);
	prueba.setCasilla(1, 8, 1);
	prueba.setCasilla(2, 2, 4);
	prueba.setCasilla(2, 6, 8);
	prueba.setCasilla(2, 7, 2);
	prueba.setCasilla(2, 8, 6);
	prueba.setCasilla(2, 9, 3);
	prueba.setCasilla(3, 1, 3);
	prueba.setCasilla(3, 4, 1);
	prueba.setCasilla(3, 5, 6);
	prueba.setCasilla(3, 9, 4);
	prueba.setCasilla(4, 1, 1);
	prueba.setCasilla(4, 5, 4);
	prueba.setCasilla(4, 7, 5);
	prueba.setCasilla(4, 8, 8);
	prueba.setCasilla(5, 1, 6);
	prueba.setCasilla(5, 2, 3);
	prueba.setCasilla(5, 3, 5);
	prueba.setCasilla(5, 4, 8);
	prueba.setCasilla(5, 5, 2);
	prueba.setCasilla(5, 9, 7);
	prueba.setCasilla(6, 1, 2);
	prueba.setCasilla(6, 4, 5);
	prueba.setCasilla(6, 5, 9);
	prueba.setCasilla(6, 7, 1);
	prueba.setCasilla(7, 1, 9);
	prueba.setCasilla(7, 2, 1);
	prueba.setCasilla(7, 4, 7);
	prueba.setCasilla(7, 8, 4);
	prueba.setCasilla(8, 4, 6);
	prueba.setCasilla(8, 5, 8);
	prueba.setCasilla(8, 7, 7);
	prueba.setCasilla(8, 9, 1);
	prueba.setCasilla(9, 1, 8);
	prueba.setCasilla(9, 4, 4);
	prueba.setCasilla(9, 6, 3);
	prueba.setCasilla(9, 8, 5);

	prueba.mostrarSudoku();

	prueba.resolverSudoku();

	prueba.mostrarSudoku();

	return 0;
}