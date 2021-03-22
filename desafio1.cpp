#include <stdio.h>
#include <list>
#include "sudoku.h"


int main(){
	State prueba;

	prueba.mostrarSudoku();

	Action action;
	prueba.transition(prueba, action);


	return 0;
}