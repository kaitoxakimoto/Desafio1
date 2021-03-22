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
			matrix[i][j] = (i+1)*(j+1); //cambiar
		}
	}
}

void State::mostrarSudoku() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			std::cout << matrix[i][j] << "\t";
		}
		std::cout << "\n";
	}
}

std::list<Action> State::getActions() {
	
}

State State::transition(State state, Action action) {
	State new_state = state;
	int x = action.x;
	int y = action.y;
	int num = action.numero;
	new_state.matrix[x][y] = num;
	return new_state;
}
