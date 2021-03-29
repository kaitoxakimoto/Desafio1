#pragma once

#include <stdio.h>

#include <fstream>
#include <iostream>
#include <set>
#include <list>
#include <string>

using namespace std;

class State {
 private:
  // Este grupo no cree en los atributos privadas
 public:
  // Atributos
  set<int> matrix[9][9];

  // Constructor
  State();

  // Metodos de Impresion
  void mostrarSudoku();
  void mostrarSudokuDebug();

  // Metodo de casilla
  void setCasilla(int fila, int columnna, int numero);
  void leerArchivo(string ruta);

  // Metodos de llenado
  bool actualizarCasilla(int fila, int columna);

  // Metodos de Resolucion
  bool nakedSingle();
  bool hiddenSingle();
  void resolverSudoku();
  list<State> getBestActions();

  // Metodos de Chequeo
  bool isValid();
  bool isFinal();

  int numInCol(int numero, int columna);
  int numInFila(int numero, int fila);
  int numInBox(int numero, int fila, int columna);



};
