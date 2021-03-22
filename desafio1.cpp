#include <iostream>
#include <stdio.h>
#include <list>
#include "sudoku.h"


int main(){
	State prueba;

	prueba.mostrarSudoku();

	Action action;
	std::cout << std::endl;
	
	prueba.transition(action);
	prueba.mostrarSudoku();

	return 0;
}