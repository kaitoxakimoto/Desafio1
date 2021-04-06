# Desafio 1 - Estructura de Datos Avanzada y Algoritmos

Bienvenido a Desafio1. Este programa busca resolver mediante Greedy Beam Search un sudoku incompleto. Esta guía lo ayudará a ejecutar de manera correcta el programa.

<br></br>

## _Instrucciones de compilación_

En la carpeta podemos ver que existen los siguientes archivos.

<center>


<p align="center">
  <img  src="https://i.imgur.com/3Qb4S3s.png">
</p>

De estos al usuario le importa “sudoku.txt”, que contiene el sudoku a resolver en el siguiente formato


<p align="center">
  <img  src="https://i.imgur.com/WGEG3WM.png">
</p>


El archivo se compone de 9 filas de 9 caracteres cada una. Si una casilla tiene una pista inicial, se anota el número. Sino, se pone el caracter “ - ” (guión).

En caso de que el programa ya este precompilado entonces basta con ejecutar el programa desafio1.exe

En caso de querer compilar su propia versión del programa. podrá ejecutar el archivo            “ compilador.bat ” o en una terminal (cmd) ejecutar la siguiente línea de comandos.

`g++ -O3 -o desafio1 *.cpp`

Esto requerirá que su sistema tenga presente alguna versión del compilador g++. que puede conseguir [Aquí](http://mingw-w64.org/doku.php).


Al ejecutar el programa usted observará que el programa le mostrará su sudoku ingresado, para luego mostrar la solución.

<p align="center">
  <img  src="https://i.imgur.com/iW2ST32.png">
</p>

<br></br>

## _Descripción del problema_

Un sudoku para considerarse completo debe tener todas sus casillas llenas con números del 1 al 9, una casilla es considerada válida si su número no se repite en su fila, columna o bloque (9 mallas de 3x3).

Nuestra solución al desafío 1 modela el problema con una matriz de 9x9 casillas. Cada casilla contiene un set de números del 1 al 9, los cuales representan los posibles números que pueden colocarse allí. Cada vez que un número es colocado en la matriz, ya sea por el estado inicial o un movimiento, se remueve ese número de las otras casillas en su fila, columna y bloque. 


<br></br>

## _Descripción del algoritmo_

__ResolverSudoku():__ Esta función se llama recursivamente, y emplea los siguientes algoritmos de manera secuencial.

__Naked Single:__ Primero se examina el sudoku por casillas donde solo existe un candidato. Esto solo suele ocurrir en los sudokus de nivel básico e intermedio, es común que en estos se pueda llenar gran parte del sudoku solamente usando movimientos naked single, lo cual abre nuevos posibles movimientos con este criterio.



<p align="center">
  <img  src="https://i.imgur.com/UCY5LlK.png">
</p>

<p align="center">
  Fig 1. Casilla [4,9] solo posee el número 7 como candidato, limpiando las casillas de la fila 4, columna 9 y bloque [2,3] que tengan el número 7 como candidato. Lo cual a su vez hace que la casilla [4,7] tenga solo el número 8 como candidato.
</p>

<br></br>

__Simple Hidden Single:__ Luego se examina si existe una fila/columna/bloque (Set actual) donde exista un número que solo esté presente en una casilla del Set actual, similar al criterio de naked single, ya que este número solo existe en una casilla del set, es lógico que solo puede existir en esa casilla.



<p align="center">
  <img  src="https://i.imgur.com/dSAV8Ge.png">
</p>

<p align="center">
  Fig 2: La casilla [1,9] es la única de su fila, columna y bloque que posee el número 5 como candidato, por lo que es un movimiento seguro.
</p>

<br></br>

__Greedy Beam Search:__ Se buscan las casillas más prometedoras: las que posean la menor cantidad de candidatos. Luego se eligen por orden de llegada y se crean estados para cada uno de sus números candidatos donde se posiciona dicho número. La función ResolverSudoku() se llama iterativamente por sobre estos estados hasta encontrar la solución final o un estado invalido. Si encuentra un estado invalido se retrocederá al último estado válido y se probarán otros movimientos válidos hijos de este. Si un estado solo lleva a estados inválidos, este también es declarado invalido.



<p align="center">
  <img  src="https://i.imgur.com/dbrzzlU.png">
</p>

<p align="center">
  Fig. 3: La rama izquierda fue explorada y solo encontró estados inválidos, por lo que fue declarada inválida en su totalidad. La rama izquierda encontró un estado invalido, por lo que continuó explorando en su estado hermano, dejando 3 estados de la rama derecha sin explorar actualmente.
</p>

<br></br>

## _Coevaluación_

| Criterio | Descripción  |  Fabían Pizarro | Rafael Diaz  | Leandro Villalobos |
|---|---|---|---|---|
|A. Asistencia y puntualidad   | Asistió siempre a las reuniones de proyecto y fue puntual.  |  1 | 1  | 2  |
| B. Integración  |  Siempre escucha y comparte las ideas de sus compañeros e intenta integrarlas. Busca cómo mantener la unión en el grupo. |  -3 |  -2 | 2  |
| C. Responsabilidad  | Siempre entrega su trabajo a tiempo y el grupo no tiene que modificar sus fechas o plazos.  | 1  |  1 |  -3 |
|  D. Contribución |  Siempre ofrece ideas para realizar el trabajo y propone sugerencias para su mejora. Se esfuerza para alcanzar los objetivos del grupo. |  3 |1   | -3  |
|  E. Resolución de conflictos | En situaciones de desacuerdo o conflicto, siempre escucha otras opiniones y acepta sugerencias. Siempre propone alternativas para el consenso o la solución.  |  -2 |  -1 | 2  |

| | Fabían Pizarro | Rafael Diaz  | Leandro Villalobos | 
|---|---|---|---|
| Fabían Pizarro | | + Disponible a toda hora <br></br> - Cuando le emociona una idea, la sigue ciegamente sin flexibilidad  |  + Disposicion a ayudar en todo <br></br> - Dificultad de comunicacion de ideas|
| Rafael Diaz  | + Trabaja muy duro y de manera eficiente <br></br> - Dificultad de comunicación para coordinarse con sus compañeros | | + Involucrado en la investigación y desarrollo del trabajo <br></br> - Dificultad de comunicación para coordinarse con sus compañeros|
| Leandro Villalobos | + Buen liderazgo del grupo. <br></br> - A veces avanza sin previo aviso. | + Disponibilidad y comunicación. <br></br> - Sintaxis de pseudo codigo. | |

<br></br>

## _Presentación en video_

[Presentación en YouTube.](https://www.youtube.com/watch?v=A43KYQiKK5I)

[![Desafío 1: Sudoku
Estructura de Datos Avanzadas
](https://i.imgur.com/ipBDFQd.png)](https://www.youtube.com/watch?v=A43KYQiKK5I "Desafío 1: Sudoku
Estructura de Datos Avanzadas
")
