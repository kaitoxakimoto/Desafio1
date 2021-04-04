#include <stdio.h>

#include <stdio.h>

#include <fstream>
#include <iostream>
#include <set>
#include <list>
#include <string>

#include "sudoku.h"

using namespace std;

int main() {
  State prueba;

  prueba.leerArchivo("sudoku.txt");

  cout << "el sudoku a resolver es el siguiente" << endl;
  prueba.mostrarSudoku();

  prueba.resolverSudoku();

  cout << "respuesta" << endl;
  prueba.mostrarSudoku();

  getchar();

  return 0;
}