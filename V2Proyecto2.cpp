#include <iostream>
#include <string.h>
using namespace std;

public class Mapa{
    
    enum class Elementos {
        Vacio,Jugador,Caja,Pared
    };

    Elementos** matriz;
    private int posJugador_x;
    private int posJugador_y;
    private posInicial;
    private posFinal;
    
    public Mapa(){

    }

    public Mapa(int posJugador_x, int posJugador_y, posInicial, posFinal){
        this.posJugador_x = posJugador_x; 
        this.posJugador_y = posJugador_y; 
        this.posInicial = posInicial;
        this.posFinal = posFinal; 
    }

   void mover_arriba();
   void izquierda();
   void mover_abajo();    
   void mover_derecha();
   void imprimir();

}