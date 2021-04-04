#include "sudoku.h"

#include <stdio.h>

#include <fstream>
#include <iostream>
#include <list>
#include <set>
#include <string>

using namespace std;

// Metodos de State

// Constructor
State::State() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      // Por cada casilla
      for (int numero = 1; numero <= 9; numero++) {
        matrix[i][j].insert(numero);
      }
    }
  }
}

// Metodos de Impresion
void State::mostrarSudoku() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (matrix[i][j].size() == 1) {
        set<int>::iterator primer = matrix[i][j].begin();
        cout << " " << *primer;
      } else {
        cout << " "
             << "-";
      }
      cout << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void State::mostrarSudokuDebug() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      set<int>::iterator iterador;
      for (iterador = matrix[i][j].begin(); iterador != matrix[i][j].end();
           ++iterador) {
        cout << *iterador;
      }
      for (int aux = 0; aux < 10 - matrix[i][j].size(); aux++) {
        cout << " ";
      }
    }
    cout << endl;
  }
  cout << endl;
}

// Metodos de casilla
void State::setCasilla(int fila, int columna, int numero) {
  set<int> nueva;
  nueva.insert(numero);

  matrix[fila - 1][columna - 1] = nueva;
}

void State::leerArchivo(string ruta) {
  char c;
  ifstream archivo(ruta);
  int fila = 1;
  int columna = 1;
  while (archivo.get(c)) {
    if (c == '\n') {
      fila++;
      columna = 1;
    } else if (c == '-') {
      columna++;
    } else {
      setCasilla(fila, columna, c - '0');
      columna++;
    }
  }
}

// Metodos de llenado
bool State::actualizarCasilla(int fila, int columna) {
  bool flag = false;
  set<int>::iterator iterador;

  // Si la casilla es final, no necesita hacer nada.
  if (matrix[fila][columna].size() == 1) return flag;

  // iteramos cada elemento presente en la casilla
  for (iterador = matrix[fila][columna].begin();
       iterador != matrix[fila][columna].end(); ++iterador) {
    if (numInFila(*iterador, fila) || numInCol(*iterador, columna) ||
        numInBox(*iterador, fila, columna)) {
      flag = true;
      matrix[fila][columna].erase(*iterador);
      iterador = matrix[fila][columna].begin();
    }
  }
  return flag;
}

// Metodos de Resolucion
bool State::nakedSingle() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      actualizarCasilla(i, j);
    }
  }
  return false;
}

bool State::hiddenSingle() {
  bool flag = false;
  int count;
  set<int> dondePuede;
  for (int i = 0; i < 9; i++) {  // recorro las filas y columnas
    for (int numero = 1; numero <= 9; numero++) {  // veo desde 1 a 9, la
                                                   // custion
      // con filas
      if (!numInFila(numero,
                     i)) {  // busco si existe el numero de arriba en la fila
        count = 0;
        dondePuede.clear();
        for (int k = 0; k < 9;
             k++) {  // si no existe, voy casilla por casilla en la fila
          if (matrix[i][k].count(numero) == 1) {
            dondePuede.insert(k);
            count++;
          }
        }
        if (count == 1) {
          setCasilla(i + 1, *dondePuede.begin() + 1, numero);
          flag = true;
        }
      }
      // con columnas, que es lo mismo, pero invierto funciones
      if (!numInCol(numero,
                    i)) {  // busco si existe el numero de arriba en la fila
        count = 0;
        dondePuede.clear();
        for (int k = 0; k < 9;
             k++) {  // si no existe, voy casilla por casilla en la fila
          if (matrix[k][i].count(numero) == 1) {
            dondePuede.insert(k);
            count++;
          }
        }
        if (count == 1) {
          setCasilla(*dondePuede.begin() + 1, i + 1, numero);
          flag = true;
        }
      }
    }
  }

  return flag;
}

void State::resolverSudoku() {
  if (!isValid()){
    return;
  }
  bool huboCambios = true;
  do {
    huboCambios = nakedSingle() || hiddenSingle();
  } while (huboCambios && isValid());

  if (isFinal()) {
    return;
  } else {
    list<State> posibilidades = getBestActions();
    list<State>::iterator candidato;

    for (candidato = posibilidades.begin(); candidato != posibilidades.end();
         ++candidato) {
      State stateCandidato = *candidato;
      //cout << "la dimension paralela es la siguiente" << endl;
      //stateCandidato.mostrarSudoku();
      stateCandidato.resolverSudoku();
      if (stateCandidato.isFinal()){
        *this = stateCandidato;
      }
    }
  }
}

list<State> State::getBestActions() {
  // Obtener la mejor Celda
  int bestFila = 0;
  int bestCol = 0;
  int bestPos = 10;

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (matrix[i][j].size() < bestPos && matrix[i][j].size() > 1) {
        bestFila = i;
        bestCol = j;
        bestPos = matrix[i][j].size();
      }
    }
  }
  list<State> lista;
  set<int>::iterator iterador;
  for (iterador = matrix[bestFila][bestCol].begin();
       iterador != matrix[bestFila][bestCol].end(); ++iterador) {
    State aux = *this;
    aux.setCasilla(bestFila + 1, bestCol + 1, *iterador);
    lista.push_back(aux);
  }
  return lista;
}

// Metodos de Chequeo
bool State::isValid() {
  for (int numero = 1; numero <= 9; numero++) {
    // Fila y Columna
    for (int i = 0; i < 9; i++) {
      if (numInCol(numero, i) > 1 || numInFila(numero, i) > 1) {
        return false;
      }
    }
    // Cajas
    for (int i = 0; i < 9; i += 3) {
      for (int j = 0; j < 9; j += 3)
        if (numInBox(numero, i, j) > 1) {
          return false;
        }
    }
  }
  return true;
}

bool State::isFinal() {
  if (!isValid()) {
    return false;
  }
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (matrix[i][j].size() != 1) {
        return false;
      }
    }
  }
  return true;
}

int State::numInCol(int num, int col) {
  int cont = 0;
  for (int row = 0; row < 9; row++) {
    if (matrix[row][col].size() == 1 && matrix[row][col].count(num) == 1) {
      cont++;
    }
  }
  return cont;
}

int State::numInFila(int num, int row) {
  int cont = 0;
  for (int col = 0; col < 9; col++) {
    if (matrix[row][col].size() == 1 && matrix[row][col].count(num) == 1) {
      cont++;
    }
  }
  return cont;
}

int State::numInBox(int num, int row, int col) {
  int cont = 0;

  int startRow = (row / 3) * 3;
  int finishRow = startRow + 3;
  int startCol = (col / 3) * 3;
  int finishCol = startCol + 3;

  for (int i = startRow; i < finishRow; i++) {
    for (int j = startCol; j < finishCol; j++) {
      if (matrix[i][j].size() == 1 && matrix[i][j].count(num) == 1) {
        cont++;
      }
    }
  }
  return cont;
}
