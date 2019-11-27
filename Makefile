#-----------------Graphics Engine----------------#
miniwin.o:PacMan/Graphics_Engine/miniwin.h PacMan/Graphics_Engine/miniwin.cpp
	g++ -Wall -g -DDEBUG  -c "PacMan/Graphics_Engine/miniwin.cpp" -o "PacMan/bin/miniwin.o"

#-------------------Main-------------------------#
main.o:PacMan/main.cpp miniwin.o
	g++ -Wall -g -DDEBUG  -c "PacMan/main.cpp" -o "PacMan/bin/main.o"

Pacman:main.o miniwin.o
	g++  -o "PacMan/bin/PacMan" "PacMan/bin/main.o" "PacMan/bin/miniwin.o" Estructuras/Grafo/Grafo.cpp Estructuras/Grafo/Recursos/Vertex/Vertex.cpp Estructuras/Grafo/Recursos/Administrador/Administrador.cpp -pthread  -lX11
