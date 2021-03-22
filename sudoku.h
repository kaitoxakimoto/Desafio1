#pragma once

#include <list>

class Action {
private:
	//Este grupo no cree en los atributos privadas
public:
	//Atributos
	int x, y, numero;

	//Constructor
	Action();

	//Metodos

};

class State{
private:
	//Este grupo no cree en los atributos privadas
public:
	//Atributos
	int matrix[9][9];

	//Constructor
	State();

	//Metodos
	void mostrarSudoku();

	std::list<Action> getActions();
	
	State transition(State state, Action action);
};



