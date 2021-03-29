#include <stdio.h>

#include <iostream>
#include <string>

#include "sudoku.h"

using namespace std;

int main() {
  State prueba;

  prueba.leerArchivo("sudokuExamples/1.txt");

  prueba.mostrarSudoku();

  prueba.resolverSudoku();

  prueba.mostrarSudoku();
  prueba.mostrarSudokuDebug();

  return 0;
}