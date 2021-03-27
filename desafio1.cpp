#include <iostream>
#include <stdio.h>
#include <list>
#include "sudoku.h"

using namespace std;


int main(){
	State prueba;

	prueba.mostrarSudoku();
	prueba.mostrarSudokuDebug();

	prueba.setCasilla(1,1,9);
	prueba.setCasilla(4,3,1);

	prueba.mostrarSudoku();
	prueba.mostrarSudokuDebug();

	return 0;
}