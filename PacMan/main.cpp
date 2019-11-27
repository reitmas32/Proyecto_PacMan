#include "Objetos/Tablero.hpp"
#include "Objetos/Comida.hpp"

using namespace miniwin;



int main() {
   vredimensiona(400, 300);
   srand(time(NULL));
   int Tecla = tecla();
   /*Tablero*/
   Tablero T = Tablero(MAPAS::LevelOne, Colors::Gray, Colors::Black);
   T.creaMundo();
   T.creaGrafo();
   T.pinta();

   /*Creación de los fantasmas y pacman*/
   
   /*Pacman*/
   Pacman pacman = Pacman(MAPAS::LevelOneWorld::POS_PACMAN_ORIG_X, 
                     MAPAS::LevelOneWorld::POS_PACMAN_ORIG_Y,
                     Colors::Yellow,Colors::Black);

   pacman.pinta_arri();

    /*Fantasma Rojo*/
    Fantasma f_rojo = Fantasma(MAPAS::LevelOneWorld::POS_FANTASMA_ORIG_X, 
                               MAPAS::LevelOneWorld::POS_FANTASMA_ORIG_Y,
                               Colors::Red, Colors::Gray);
    f_rojo.pinta();

    /*Fantasma Verde*/
    Fantasma f_verde = Fantasma(MAPAS::LevelOneWorld::POS_FANTASMA_ORIG_X, 
                                MAPAS::LevelOneWorld::POS_FANTASMA_ORIG_Y,
                                Colors::Green, Colors::Gray);
    f_verde.pinta();

    /*Fantasma Naranja*/
    Fantasma f_magenta = Fantasma(MAPAS::LevelOneWorld::POS_FANTASMA_ORIG_X, 
                                  MAPAS::LevelOneWorld::POS_FANTASMA_ORIG_Y,
                                  Colors::Magenta, Colors::Gray);
    f_magenta.pinta();

   Comida posComida[MAPAS::LevelOneWorld::COLUMNAS]
                     [MAPAS::LevelOneWorld::FILAS];

   refresca();

   int time = 0;

   int dir = 0;

   Fantasma* listaFantasmas[MAPAS::LevelOneWorld::NUM_FANTASMAS]; 

   listaFantasmas[0] = &f_rojo;
   listaFantasmas[1] = &f_verde;
   listaFantasmas[2] = &f_magenta;

   Pacman p_origen = pacman;

   for(size_t i = 0; i < T.vidas ; i++){
        Pacman p_v = Pacman(MAPAS::LevelOneWorld::COLUMNAS + 5,2+i*2,Colors::Yellow,Colors::Black);
        p_v.pinta_der();
   }

   while (Tecla != ESCAPE)
   {
      Pacman copia = pacman;

      for (size_t i = 0; i < MAPAS::LevelOneWorld::NUM_FANTASMAS; i++)
      {

            Tablero::moveFantasma(listaFantasmas[i], T, &pacman,i);
         	listaFantasmas[i] -> pinta();
        	listaFantasmas[i]->setTime(listaFantasmas[i]->getTime() + 1);
      }


      if(Tecla != ARRIBA || Tecla != ABAJO || Tecla != DERECHA || Tecla != IZQUIERDA || dir != 0){
         if(time > 40){
               time = 0;
            switch (dir)
               {
               case 1:
                  Tecla = ARRIBA;
                  break;
               case 2:
                  Tecla = ABAJO;
                  break;
               case 3:
                  Tecla = DERECHA;
                  break;
               case 4:
                  Tecla  = IZQUIERDA;
                  break;
               default:
                  break;
            }
         }
      }

      if( Tecla == ARRIBA){
         pacman.mueve_arriba();
         dir = 1;
      }
        
      else if( Tecla == ABAJO){
         pacman.mueve_abajo();
         dir = 2;
      }
      else if( Tecla == DERECHA){
         pacman.mueve_derecha();
         dir = 3;
      }
      else if( Tecla == IZQUIERDA){
         pacman.mueve_izquierda();
         dir = 4;
      }

      if(T.colision(pacman)){
         pacman = copia;
      }

      if(Tecla != NINGUNA){
         T.repinta();           
         for(size_t i = 0; i < T.Columnas; i++){
            for(size_t j = 0; j < T.Filas; j++){
               if(Colors::cmpColor(T.tablero[j][i].getColorDecora(), T.ColorCamino)){
                  posComida[i][j] = Comida(i,j,Colors::Yellow, T.ColorCamino);
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


         for(size_t i = 0; i < MAPAS::LevelOneWorld::NUM_FANTASMAS; i++){
                listaFantasmas[i]->pinta();
            }

         if(Tecla == ARRIBA){
            pacman.pinta_arri();
         }
         else if(Tecla == ABAJO){
            pacman.pinta_abajo();
         }
         else if(Tecla == DERECHA){
            pacman.pinta_der();
         }
         else if(Tecla == IZQUIERDA){
            pacman.pinta_izq();
         }
         
         if( Tecla == ARRIBA || Tecla == ABAJO || Tecla == DERECHA || Tecla == IZQUIERDA){
            if(Colors::cmpColor(T.tablero[pacman.getPosicion().y][pacman.getPosicion().x].getColorDecora(),T.ColorCamino)){
               T.tablero[pacman.getPosicion().y][pacman.getPosicion().x].setColorDecora(T.ColorPared);
               posComida[pacman.getPosicion().x][pacman.getPosicion().y].setColorSolido(Colors::Black);
               T.puntos++;
            }
         }

      }

      for(size_t i = 0; i < MAPAS::LevelOneWorld::NUM_FANTASMAS; i++){
         Fantasma* f = listaFantasmas[i];
            if(pacman.getPosicion().x == f->getPosicion().x &&
               pacman.getPosicion().y == f->getPosicion().y){
                  if(T.vidas == 0){
                     vcierra();               
                  }
                  else{
                     pacman = p_origen;
                     T.vidas--; 
                     T.repinta();
                     color(BLANCO);
                     texto(23*TAM, 15*TAM,"Moriste");
                     espera(500);
                     break;
                  }
            } 
      }

      if(T.puntos == MAPAS::LevelOneWorld::MAX_PUNTAJE){
         T.repinta();
         color(BLANCO);
         texto(20*TAM, 15*TAM,"Felicidades Ganaste");
         espera(1500);
         vcierra();
      }

      espera(10);
      time++;
      Tecla = tecla();
      
   }
   
   vcierra();

   refresca();

   return 0;
}
