#pragma once

#include <set>

using namespace std;


class State{
private:
	//Este grupo no cree en los atributos privadas
public:
	//Atributos
	set<int> matrix[9][9];

	//Constructor
	State();

	//Metodos de Impresion
	void mostrarSudoku();
	void mostrarSudokuDebug();

	//Metodo de casilla
	void setCasilla(int fila, int columnna, int numero);

	//Metodos de llenado
	void actualizarCasilla(int fila,int columna);

	//Metodos de Resolucion
	bool checkCandidato();
	bool encontrarLugar();
	void teoremaOcupacion();
	void resolverSudoku();

	//Metodos de Chequeo
	bool isFinal();
	
	bool numInCol();
	bool numInFila();
	bool numInBox();

	int posicionArrayCount(int* array);
};
