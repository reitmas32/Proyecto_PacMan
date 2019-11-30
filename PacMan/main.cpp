#include "Objetos/Tablero.hpp"
#include "Objetos/Comida.hpp"

//using namespace miniwin;



int main() {
   miniwin::vredimensiona(400, 300);
   srand(time(NULL));
   int Tecla = miniwin::tecla();
   /*Tablero*/
   Tablero T = Tablero(miniwin::GRIS, miniwin::NEGRO);
   T.creaMundo();
   T.creaGrafo();
   //T.pinta();

   /*Creación de los fantasmas y pacman*/
   
   /*Pacman*/
   Pacman pacman = Pacman(POS_PACMAN_ORIG_X, 
                     POS_PACMAN_ORIG_Y,
                     miniwin::AMARILLO,miniwin::NEGRO);

    /*Fantasma Rojo*/
    Fantasma f_rojo = Fantasma(POS_FANTASMA_ROJO_ORIG_X, 
                               POS_FANTASMA_ROJO_ORIG_Y,
                               miniwin::ROJO, miniwin::GRIS);

    /*Fantasma Verde*/
    Fantasma f_verde = Fantasma(POS_FANTASMA_VERDE_ORIG_X, 
                                POS_FANTASMA_VERDE_ORIG_Y,
                                miniwin::VERDE, miniwin::GRIS);

    /*Fantasma Naranja*/
    Fantasma f_magenta = Fantasma(POS_FANTASMA_MAGENTA_ORIG_X, 
                                  POS_FANTASMA_MAGENTA_ORIG_Y,
                                  miniwin::MAGENTA, miniwin::GRIS);

    /*Fantasma Cyan*/
    Fantasma f_cyan = Fantasma(POS_FANTASMA_CYAN_ORIG_X, 
                                  POS_FANTASMA_CYAN_ORIG_Y,
                                  miniwin::CYAN, miniwin::GRIS);

    /*Fantasma Naranja*/
    Fantasma f_white = Fantasma(POS_FANTASMA_WHITE_ORIG_X, 
                                  POS_FANTASMA_WHITE_ORIG_Y,
                                  miniwin::BLANCO, miniwin::GRIS);
   

   Comida posComida[COLUMNAS][FILAS];


   Fantasma::pintaBigFantasma();
   Pacman::pintaBigPacman();
   miniwin::color(miniwin::AMARILLO);
   miniwin::texto(90,210,"<=====Presiona ESPACIO para iniciar=====>");
   int maxPuntaje = 0;
   miniwin::texto(170,230,"Best: "+Tablero::intToString(maxPuntaje));
   miniwin::refresca();

   int time = 0;

   int dir = 0;

   Fantasma* listaFantasmas[NUM_FANTASMAS]; 

   listaFantasmas[0] = &f_rojo;
   listaFantasmas[1] = &f_verde;
   listaFantasmas[2] = &f_magenta;
   listaFantasmas[3] = &f_cyan;
   listaFantasmas[4] = &f_white;

   Pacman p_origen = pacman;

   for(size_t i = 0; i < T.vidas ; i++){
        Pacman p_v = Pacman(COLUMNAS + 5,2+i*2,miniwin::AMARILLO, miniwin::NEGRO);
        p_v.pinta_der();
   }

   while(Tecla != miniwin::ESPACIO){
      miniwin::espera(100);
      Tecla = miniwin::tecla();
   }

   int huye  = 0;

   while (Tecla != miniwin::ESCAPE)
   {
      Pacman copia = pacman;

      if(Tecla != miniwin::ARRIBA || Tecla != miniwin::ABAJO || Tecla != miniwin::DERECHA || Tecla != miniwin::IZQUIERDA || dir != 0){
         if(time > 40){
               time = 0;
            switch (dir)
               {
               case 1:
                  Tecla = miniwin::ARRIBA;
                  break;
               case 2:
                  Tecla = miniwin::ABAJO;
                  break;
               case 3:
                  Tecla = miniwin::DERECHA;
                  break;
               case 4:
                  Tecla  = miniwin::IZQUIERDA;
                  break;
               default:
                  break;
            }
            if(dir != 0){
               for (size_t i = 0; i < NUM_FANTASMAS; i++)
               {
                  if(huye == 0){
                     Tablero::moveFantasma(listaFantasmas[i], &T, &pacman,i);
                     listaFantasmas[i] -> pinta();                 
                  }else{
                     Tablero::huyeFantasma(listaFantasmas[i], &T, &pacman,i);
                     listaFantasmas[i] -> pintaAzul();
                  }

               }               
            }
         }
      }

      if( Tecla == miniwin::ARRIBA){
         pacman.mueve_arriba();
         dir = 1;
      }
        
      else if( Tecla == miniwin::ABAJO){
         pacman.mueve_abajo();
         dir = 2;
      }
      else if( Tecla == miniwin::DERECHA){
         pacman.mueve_derecha();
         dir = 3;
      }
      else if( Tecla == miniwin::IZQUIERDA){
         pacman.mueve_izquierda();
         dir = 4;
      }

      if(T.colision(pacman)){
         pacman = copia;
      }

      if(Tecla != miniwin::NINGUNA){
         T.repinta();         
         for(size_t i = 0; i < T.Columnas; i++){
            for(size_t j = 0; j < T.Filas; j++){
               if( T.tablero[j][i].getColorDecora() == T.ColorCamino){
                  posComida[i][j] = Comida(i,j,miniwin::AMARILLO, T.ColorCamino);
                  if(T.mapa[j][i] == 3){
                     posComida[i][j].pintaGrande();
                  }else{
                     posComida[i][j].pinta();
                  }
                        
               }
               else{
                  posComida[i][j] = Comida(i,j,T.ColorCamino, T.ColorCamino);
               }
                    
            }
         }


         for(size_t i = 0; i < NUM_FANTASMAS; i++){
               if(huye == 0 ){
                  listaFantasmas[i]->pinta();
               }
               else{
                   listaFantasmas[i]->pintaAzul();
               }
            }

         if(Tecla == miniwin::ARRIBA){
            pacman.pinta_arri();
         }
         else if(Tecla == miniwin::ABAJO){
            pacman.pinta_abajo();
         }
         else if(Tecla == miniwin::DERECHA){
            pacman.pinta_der();
         }
         else if(Tecla == miniwin::IZQUIERDA){
            pacman.pinta_izq();
         }
         
         if( Tecla == miniwin::ARRIBA || Tecla == miniwin::ABAJO || Tecla == miniwin::DERECHA || Tecla == miniwin::IZQUIERDA){
            if( T.tablero[pacman.getPosicion().y][pacman.getPosicion().x].getColorDecora() == T.ColorCamino){
               T.tablero[pacman.getPosicion().y][pacman.getPosicion().x].setColorDecora(T.ColorPared);
               posComida[pacman.getPosicion().x][pacman.getPosicion().y].setColorSolido(miniwin::NEGRO);
               T.puntos++;
               if(T.mapa[pacman.getPosicion().y][pacman.getPosicion().x] == 3){
                  huye = 400;
               }
            }
         }
         //std::cout<<pacman.getPosicion().x<<", "<<pacman.getPosicion().y<<std::endl;
      }

      for(size_t i = 0; i < NUM_FANTASMAS; i++){
         Fantasma* f = listaFantasmas[i];
            if(pacman.getPosicion().x == f->getPosicion().x &&
               pacman.getPosicion().y == f->getPosicion().y){
                  if( huye == 0){
                     if(T.vidas == 0){
                        miniwin::vcierra();               
                     }
                     else{
                        pacman = p_origen;
                        T.vidas--; 
                        T.repinta();
                        miniwin::color(miniwin::BLANCO);
                        miniwin::texto(23*TAM, 15*TAM,"Moriste");
                        miniwin::espera(500);
                        break;
                     }                     
                  }else if(T.vidas <= 6){
                     T.vidas++;
                     f->setPosicion(9,10);
                        T.repinta();
                        miniwin::color(miniwin::BLANCO);
                        miniwin::texto(23*TAM, 15*TAM,"Vida Extra");
                        miniwin::espera(500);
                  }

            } 
      }

      if(T.puntos == MAX_PUNTAJE){
         T.repinta();
         miniwin::color(miniwin::BLANCO);
         miniwin::texto(20*TAM, 20*TAM,"Felicidades Ganaste");
         miniwin::espera(1500);
         miniwin::vcierra();
      }
      miniwin::espera(10);
      time++;
      Tecla = miniwin::tecla();
      if(huye != 0){
         huye--;
      }
   }
   
   miniwin::vcierra();

   miniwin::refresca();

   return 0;
}
