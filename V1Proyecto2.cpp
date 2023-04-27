#include <iostream>
using namespace std;

class Mapa{
	enum class Elementos{
		VACIO, JUGADOR, CAJA, PARED, FINAL
	};

	int posJugador_x;
	int posJugador_y;
	int posInicial;
	int posFinal;
	Elementos** matriz;		
	//La matriz posse elementos. Elementos es un tipo. La matriz es de elementos
	int N, M;		//El user no sabra que eso es una matriz

	public:

	Mapa(){
		cin>>N>>M;
	}

	Mapa(int posJugador_x, int posJugador_y, int posInicial, int posFinal){
		this->posJugador_x = posJugador_x;
		this->posJugador_y = posJugador_y;
		this->posInicial = posInicial;
		this->posFinal = posFinal;
	}
	
	void mover_arriba();
	void mover_izquierda();
	void mover_abajo();
	void mover_derecha();

	/*int** crear_matriz(int N, int M){
		int** matriz = new int* [M];

		for(int i = 0; i < N; i++){
			matriz[i] = new int[M];	//Crear columnas

		}
		return matriz;
	}*/

	void imprimir_tablero(int N, int M){
		
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= M; j++){
		
				if (matriz[i][j] == Elementos::VACIO){
					cout<<"."<<endl;
				}

				if (matriz[i][j] == Elementos::JUGADOR){
					cout<<"K"<<endl;
				}

				if (matriz[i][j] == Elementos::CAJA){
					cout<<"C"<<endl;
				}

				if (matriz[i][j] == Elementos::PARED){
					cout<<"X"<<endl;
				}

				if (matriz[i][j] == Elementos::FINAL){
					cout<<"F"<<endl;
				}

			}
		}
	}	
};

int main(){

	Mapa map;			//Instancie mapa
	map.imprimir_tablero(N, M);
	return 0;
}