#include "sudoku.h"
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>

using namespace std;

//Metodos de State

//Constructor
State::State() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			//Por cada casilla
			for(int numero = 1; numero<=9 ;numero++){
				matrix[i][j].insert(numero);
			}
		}
	}
}

//Metodos de Impresion
void State::mostrarSudoku() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if(matrix[i][j].size() == 1){
				set<int>::iterator primer = matrix[i][j].begin();
				cout << " " << *primer;
			}
			else{
				cout << " " << "-";
			}
			cout << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void State::mostrarSudokuDebug() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			set<int>::iterator iterador;
			for(iterador = matrix[i][j].begin(); iterador!= matrix[i][j].end(); ++iterador){
				cout << *iterador;
			}
			for(int aux = 0; aux < 10 - matrix[i][j].size() ; aux++){
				cout << " ";
			}
		}
		cout << "\n";
	}
	cout << "\n";
}

//Metodos de casilla
void State::setCasilla(int fila, int columna, int numero){
	set<int> nueva;
	nueva.insert(numero);

	matrix[fila-1][columna-1] = nueva;
}

//Metodos de llenado
bool State::actualizarCasilla(int fila, int columna){
	
	bool flag = false;
	set<int>::iterator iterador;

	//Si la casilla es final, no necesita hacer nada.
	if (matrix[fila][columna].size() == 1) return flag;

	//iteramos cada elemento presente en la casilla
	for(iterador = matrix[fila][columna].begin(); iterador!= matrix[fila][columna].end(); ++iterador){
		if(numInFila(*iterador, fila) || numInCol(*iterador, columna) || numInBox(*iterador, fila,columna)){
			flag = true;
			matrix[fila][columna].erase(*iterador);
			iterador = matrix[fila][columna].begin();
		}
	}
	return flag;

}

//Metodos de Resolucion
bool State::checkCandidato(){
	for(int i=0; i<9; i++){
		for (int j=0; j<9; j++){
			actualizarCasilla(i,j);
		}
	}
	return false;
}

bool State::encontrarLugar(){
	bool flag = false;
	int count;
	set<int> dondePuede;
	for(int i=0; i<9; i++) { //recorro las filas y columnas
		for (int numero=1;numero<=9;numero++) { //veo desde 1 a 9, la custion
			//con filas
			if (!numInFila(numero,i)) { //busco si existe el numero de arriba en la fila
				count = 0;
				dondePuede.clear();
				for (int k=0;k<9;k++) { //si no existe, voy casilla por casilla en la fila
					if(matrix[i][k].count(numero) == 1){
						dondePuede.insert(k);
						count++;
					}
				}
				if (count == 1){
					setCasilla(i+1,*dondePuede.begin()+1,numero);
					flag = true;
				}
			}
			//con columnas, que es lo mismo, pero invierto funciones
			if (!numInCol(numero,i)) { //busco si existe el numero de arriba en la fila
				count = 0;
				dondePuede.clear();
				for (int k=0;k<9;k++) { //si no existe, voy casilla por casilla en la fila
					if(matrix[k][i].count(numero) == 1){
						dondePuede.insert(k);
						count++;
					}
				}
				if (count == 1){
					setCasilla(*dondePuede.begin()+1,i+1,numero);
					flag = true;
				}
			}
		}
	}

	return flag;
}

void State::teoremaOcupacion(){

}

void State::resolverSudoku(){
	/*Usamos metodos de checkCandidato y encontrarLugar
	hasta que no surja ningun efecto con este*/
	bool huboCambios = true;
	do{
		huboCambios = checkCandidato() || encontrarLugar();
	}while(huboCambios);

	/*Usamos el teorema de la Ocupacion*/
	//teoremaOcupacion();

	/*Si no funciona, asumimos un estado e intentamos resolver
	dicho estado recursivamente*/
}
//Metodos de Chequeo
bool State::isFinal(){
	return false;
}

bool State::numInCol(int num, int col){
	for(int row=0;row<9;row++){
		if(matrix[row][col].size()== 1 && matrix[row][col].count(num)==1){
			return true;
		}
	}
	return false;
}

bool State::numInFila(int num, int row){
	for(int col=0;col<9;col++){
		if(matrix[row][col].size()== 1 && matrix[row][col].count(num)==1){
			return true;
		}
	}
	return false;
} 

bool State::numInBox(int num, int row, int col){
	int startRow= (row/3)*3;
	int finishRow= startRow+3;
	int startCol= (col/3)*3;
	int finishCol= startCol+3;

	for(int i=startRow ; i<finishRow ; i++){
		for(int j=startCol ; j<finishCol ; j++){
			if(matrix[i][j].size()== 1 && matrix[i][j].count(num)==1){
				return true;
			}
		}
	}
	return false;
}
