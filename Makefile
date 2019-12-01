#-----------------Graphics Engine----------------#
miniwin.o:PacMan/Graphics_Engine/miniwin.h PacMan/Graphics_Engine/miniwin.cpp
	g++ -Wall -g -DDEBUG  -c "PacMan/Graphics_Engine/miniwin.cpp" -o "PacMan/bin/miniwin.o"

ManejadorEntrada.o:PacMan/Graphics_Engine/ManejadorEntrada.hpp PacMan/Graphics_Engine/ManejadorEntrada.cpp
	g++ -Wall -g -DDEBUG  -c "PacMan/Graphics_Engine/ManejadorEntrada.cpp" -o "PacMan/bin/ManejadorEntrada.o"

Cuadro.o:PacMan/Graphics_Engine/Cuadro.hpp PacMan/Graphics_Engine/Cuadro.cpp
	g++ -Wall -g -DDEBUG  -c "PacMan/Graphics_Engine/Cuadro.cpp" -o "PacMan/bin/Cuadro.o"

Figura.o:PacMan/Objetos/Figura.hpp PacMan/Objetos/Figura.cpp
	g++ -Wall -g -DDEBUG  -c "PacMan/Objetos/Figura.cpp" -o "PacMan/bin/Figura.o"

Fantasma.o:PacMan/Objetos/Fantasma.hpp PacMan/Objetos/Fantasma.cpp
	g++ -Wall -g -DDEBUG  -c "PacMan/Objetos/Fantasma.cpp" -o "PacMan/bin/Fantasma.o"

Pacman.o:PacMan/Objetos/Pacman.hpp PacMan/Objetos/Pacman.cpp
	g++ -Wall -g -DDEBUG  -c "PacMan/Objetos/Pacman.cpp" -o "PacMan/bin/Pacman.o"

Comida.o:PacMan/Objetos/Comida.hpp PacMan/Objetos/Comida.cpp
	g++ -Wall -g -DDEBUG  -c "PacMan/Objetos/Comida.cpp" -o "PacMan/bin/Comida.o"

Tablero.o:PacMan/Objetos/Tablero.hpp PacMan/Objetos/Tablero.cpp
	g++ -Wall -g -DDEBUG  -c "PacMan/Objetos/Tablero.cpp" -o "PacMan/bin/Tablero.o"

#----------------Estructuras---------------------#
Grafo.o:PacMan/Estructuras/Grafo/Grafo.hpp PacMan/Estructuras/Grafo/Grafo.cpp
	g++ -Wall -g -DDEBUG  -c "PacMan/Estructuras/Grafo/Grafo.cpp" -o "PacMan/bin/Grafo.o"

Vertex.o:PacMan/Estructuras/Grafo/Recursos/Vertex.hpp PacMan/Estructuras/Grafo/Recursos/Vertex.cpp
	g++ -Wall -g -DDEBUG  -c "PacMan/Estructuras/Grafo/Recursos/Vertex.cpp" -o "PacMan/bin/Vertex.o"

#---------------Oredeanamiento-------------------#
HeapSort.o:PacMan/Ordenamiento/HeapSort.hpp PacMan/Ordenamiento/HeapSort.cpp
	g++ -Wall -g -DDEBUG  -c "PacMan/Ordenamiento/HeapSort.cpp" -o "PacMan/bin/HeapSort.o"

Jugadores.o:PacMan/Ordenamiento/Jugadores.hpp PacMan/Ordenamiento/Jugadores.cpp
	g++ -Wall -g -DDEBUG  -c "PacMan/Ordenamiento/Jugadores.cpp" -o "PacMan/bin/Jugadores.o"
#-------------------Main-------------------------#
main.o:PacMan/main.cpp miniwin.o
	g++ -Wall -g -DDEBUG  -c "PacMan/main.cpp" -o "PacMan/bin/main.o" -fopenmp

Pacman:main.o miniwin.o Cuadro.o Figura.o Fantasma.o Pacman.o Comida.o Tablero.o Grafo.o Vertex.o HeapSort.o Jugadores.o ManejadorEntrada.o
	g++  -o "PacMan/bin/PacMan" "PacMan/bin/main.o" "PacMan/bin/miniwin.o" "PacMan/bin/Cuadro.o" "PacMan/bin/Figura.o" "PacMan/bin/Fantasma.o" "PacMan/bin/Pacman.o" "PacMan/bin/Comida.o" "PacMan/bin/Tablero.o" "PacMan/bin/Grafo.o" "PacMan/bin/Vertex.o" "PacMan/bin/HeapSort.o" "PacMan/bin/Jugadores.o" "PacMan/bin/ManejadorEntrada.o" -pthread  -lX11
