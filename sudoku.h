#pragma once

#include <set>

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

  // Metodos de llenado
  bool actualizarCasilla(int fila, int columna);

  // Metodos de Resolucion
  bool checkCandidato();
  bool encontrarLugar();
  void teoremaOcupacion();
  void resolverSudoku();

  // Metodos de Chequeo
  bool isFinal();

  bool numInCol(int numero, int columna);
  bool numInFila(int numero, int fila);
  bool numInBox(int numero, int fila, int columna);
};
