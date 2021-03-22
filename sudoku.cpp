#include "sudoku.h"
#include <iostream>
#include <stdio.h>
#include <list>

//Metodos de Action
Action::Action() {
	x = 1;
	y = 1;
	numero = 4;
}

//Metodos de State
State::State() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			matrix[i][j] = 0; //cambiar
		}
	}
}

void State::mostrarSudoku() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			std::cout << matrix[i][j] << "\t\t";
		}
		std::cout << "\n";
	}
}

std::list<Action> State::getActions() {
	std::list<Action> list;
	return list;
}

void State::transition(Action action) {
	int x = action.x - 1;
	int y = action.y - 1;
	int num = action.numero;
	matrix[x][y] = num;
}
