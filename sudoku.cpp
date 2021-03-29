#include "sudoku.h"
#include <iostream>
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
				cout << " " << *iterador;
			}
			cout << " ";
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
	bool flag false;
	set<int>::iterator iterador;

	//Si la casilla es final, no necesita hacer nada.
	if (matrix[fila][columna].size() == 1) return flag;

	//iteramos cada elemento presente en la casilla
	for(iterador = matrix[fila][columna].begin(); iterador!= matrix[fila][columna].end(); ++iterador){
		if(numInFila(*iterador, fila) || numInCol(*iterador, columna) || numInBox(*iterador, fila,columna)){
			flag = true;
			matrix[fila][columna].erase(*iterador);
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
	//iterar Filas
	int count = 0;
	int arrayCount[9] = { 0 };
	int i, j, k;
	bool check = false;

	for(i=0; i<9; i++) { //recorro las filas y columnas
		for ( j=0;j<9;j++) { //veo desde 1 a 9, la custion
		
		
			//con filas

			if (!numInFila(j,i)) { //busco si existe el numero de arriba en la fila
				for (k=0;k<9;k++) { //si no existe, voy casilla por casilla en la fila
					if  (matrix[i][k].size() > 1) { //si la casilla tiene un size mayor 1, significa que esta vacio
						if (!numInCol(j,k)) { //si el numero no existe la columna de esa casilla, se marca que puede existir ese numero en la casilla
							arrayCount[k]=1;
							check = true;
						}
					}
				}
				if (posicionArrayCount(arrayCount)) { //una función que aun no creo, que revisa si en todo el array, solo hay una posición marcada
					setCasilla(i,posicionArrayCount(arrayCount),j); //marca el numero en esa posicion
				}
				 //despues veo una manera eficiente de volver a dejarlo en 0
			}



			//con columnas, que es lo mismo, pero invierto funciones

			if (!numInCol(j,i)) { //busco si existe el numero de arriba en la columna
				for (int k=0;k<9;k++) { //si no existe, voy casilla por casilla en la columna
					if  (matrix[i][k].size() > 1) { //si la casilla tiene un size mayor 1, significa que esta vacio
						if (!numInFila(j,k)) { //si el numero no existe la columna de esa casilla, se marca que puede existir ese numero en la casilla
							arrayCount[k]=1;
							check = true;
						}
					}
				}
				if (posicionArrayCount(arrayCount)) { //una función que aun no creo, que revisa si en todo el array, solo hay una posición marcada
					setCasilla(i,posicionArrayCount(arrayCount),j); //marca el numero en esa posicion
				}
				 //despues veo una manera eficiente de volver a dejarlo en 0
			}
			
		}
		
	}

	//iterar Columnas



	//Iterar Cajas



	return check;

	//iterar Columnas



	//Iterar Cajas

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
	teoremaOcupacion();

	/*Si no funciona, asumimos un estado e intentamos resolver
	dicho estado recursivamente*/
}
//Metodos de Chequeo
bool State::isFinal(){

}

bool State::numInCol(int num, int col){
	for(int row=0;i<9;row++){
		if(matrix[row][col].size()== 1 && matrix[row][col].count(num)==1){
			return True;
		}
	}
	return False;
}

bool State::numInFila(int num, int row){
	for(int col=0;i<9;col++){
		if(matrix[row][col].size()== 1 && matrix[row][col].count(num)==1){
			return True;
		}
	}
	return False;
} 

bool State::numInBox(int num, int row, int col){
	int startRow= (row/3)*3;
	int finishRow= startRow+3;
	int startCol= (col/3)*3;
	int finishCol= startCol+3;

	for(int i=startRow ; i<finishRow ; i++){
		for(int j=startCol ; j<finishCol ; i++){
			if(matrix[i][j].size()== 1 && matrix[i][j].count(num)==1{
				return True;
			}
		}
	}
	return False;
}


int State::posicionArrayCount(int* array) {

	int index = 0;

	for (int i=0;i<9;i++) {
		if (array[i]==1) {
			if (index==0) {
				index = i;
			}
			else {
				return 0;
			}
		}
	}

	return index;
	
}