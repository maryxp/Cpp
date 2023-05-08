#include <iostream>
using namespace std;

class Mapa{
	public:			//Para que se pueda acceder desde fuera de la clase 
	enum class Elementos{
		VACIO, JUGADOR, CAJA, PARED, FINAL
	};
	
	private: 
	int posJugador_x;
	int posJugador_y;
	int posInicial_x;
	int posInicial_y;
	int posFinal_x;
	int posFinal_y;
	
	public:
	int N, M;

								//Public
	Elementos** matriz;			//Para que se pueda usar la matriz por otras funciones
	//La matriz posse elementos. Elementos es un tipo. La matriz es de elementos

	Mapa(){
		
	}

	Mapa(int posJugador_x, int posJugador_y, int posInicial_x, int posInicial_y, int posFinal_x, int posFinal_y, Elementos** matriz, int N, int M){
			
		this->posJugador_x = posJugador_x;
		this->posJugador_y = posJugador_y;
		this->posInicial_x = posInicial_x;
		this->posInicial_y = posInicial_y;
		this->posFinal_x = posFinal_x;
		this->posFinal_y = posFinal_y;
		this ->matriz = matriz;
		this ->N = N;
		this -> M = M;
	}
	
	void mover_arriba(){
		Elementos aux = matriz[posJugador_y][posJugador_x];
		Elementos posDecrement = matriz[posJugador_y -1][posJugador_x];

		if(posDecrement == Mapa::Elementos::PARED){
			matriz[posJugador_y][posJugador_x] = matriz[posJugador_y][posJugador_x];

		}else if(posDecrement == Mapa::Elementos::CAJA){
			
			if(matriz[posJugador_y -2][posJugador_x] == Mapa::Elementos::VACIO){
				
				matriz[posJugador_y -2][posJugador_x] = Mapa::Elementos::CAJA;
				matriz[posJugador_y -1][posJugador_x] = Mapa::Elementos::VACIO;

				matriz[posJugador_y -1][posJugador_x] = matriz[posJugador_y][posJugador_x];
				matriz[posJugador_y][posJugador_x] = Mapa::Elementos::VACIO;

			}else{
				matriz[posJugador_y][posJugador_x] = matriz[posJugador_y][posJugador_x];
			}

		}else if(posDecrement == Mapa::Elementos::VACIO) {
			matriz[posJugador_y][posJugador_x] = posDecrement;
			matriz[posJugador_y-1][posJugador_x] = aux; 
		}
		
	}


	void mover_izquierda(){
		Elementos aux = matriz[posJugador_y][posJugador_x];
		Elementos posDecrementIzq = matriz[posJugador_y][posJugador_x-1];

		if(posDecrementIzq == Mapa::Elementos::PARED){
			matriz[posJugador_y][posJugador_x] = matriz[posJugador_y][posJugador_x];

		}else if(posDecrementIzq == Mapa::Elementos::CAJA){
			
			if(matriz[posJugador_y][posJugador_x -2] == Mapa::Elementos::VACIO){
				
				matriz[posJugador_y][posJugador_x -2] = Mapa::Elementos::CAJA;
				matriz[posJugador_y][posJugador_x -1] = Mapa::Elementos::VACIO;

				matriz[posJugador_y][posJugador_x -1] = matriz[posJugador_y][posJugador_x];
				matriz[posJugador_y][posJugador_x] = Mapa::Elementos::VACIO;
				
			}else{
				matriz[posJugador_y][posJugador_x] = matriz[posJugador_y][posJugador_x];
			}

		}else if(posDecrementIzq == Mapa::Elementos::VACIO) {
			matriz[posJugador_y][posJugador_x] = posDecrementIzq;
			matriz[posJugador_y][posJugador_x-1] = aux; 
		}
	}

	
	void mover_abajo(){
		Elementos aux = matriz[posJugador_y][posJugador_x];
		Elementos posIncrement = matriz[posJugador_y +1][posJugador_x];

		if(posIncrement == Mapa::Elementos::PARED){
			matriz[posJugador_y][posJugador_x] = matriz[posJugador_y][posJugador_x];

		}else if(posIncrement == Mapa::Elementos::CAJA){
			
			if(matriz[posJugador_y +2][posJugador_x] == Mapa::Elementos::VACIO){
				
				matriz[posJugador_y +2][posJugador_x] = Mapa::Elementos::CAJA;
				matriz[posJugador_y +1][posJugador_x] = Mapa::Elementos::VACIO;

				matriz[posJugador_y +1][posJugador_x] = matriz[posJugador_y][posJugador_x];
				matriz[posJugador_y][posJugador_x] = Mapa::Elementos::VACIO;

			}else{
				matriz[posJugador_y][posJugador_x] = matriz[posJugador_y][posJugador_x];
			}

		}else if(posIncrement == Mapa::Elementos::VACIO) {
			matriz[posJugador_y][posJugador_x] = posIncrement;
			matriz[posJugador_y+1][posJugador_x] = aux; 
		}
	}


	void mover_derecha(){
		Elementos aux = matriz[posJugador_y][posJugador_x];
		Elementos posIncrementDer = matriz[posJugador_y][posJugador_x+1];

		if(posIncrementDer == Mapa::Elementos::PARED){
			matriz[posJugador_y][posJugador_x] = matriz[posJugador_y][posJugador_x];

		}else if(posIncrementDer == Mapa::Elementos::CAJA){
			
			if(matriz[posJugador_y][posJugador_x +2] == Mapa::Elementos::VACIO){
				
				matriz[posJugador_y][posJugador_x +2] = Mapa::Elementos::CAJA;
				matriz[posJugador_y][posJugador_x +1] = Mapa::Elementos::VACIO;

				matriz[posJugador_y][posJugador_x +1] = matriz[posJugador_y][posJugador_x];
				matriz[posJugador_y][posJugador_x] = Mapa::Elementos::VACIO;
				
			}else{
				matriz[posJugador_y][posJugador_x] = matriz[posJugador_y][posJugador_x];
			}


		}else if(posIncrementDer == Mapa::Elementos::VACIO) {
			matriz[posJugador_y][posJugador_x] = posIncrementDer;
			matriz[posJugador_y][posJugador_x+1] = aux; 
		}
		
	}

	/*int** crear_matriz(int N, int M){
		int** matriz = new int* [M];

		for(int i = 0; i < N; i++){
			matriz[i] = new int[M];	//Crear columnas

		}
		return matriz;
	}*/

	void imprimirTablero(){
		
		for(int i = 0; i < this->N; i++){
			for(int j = 0; j < this->M; j++){
		
				if (matriz[i][j] == Elementos::VACIO){
					cout<<".";
				}

				if (matriz[i][j] == Elementos::JUGADOR){
					cout<<"K";
				}

				if (matriz[i][j] == Elementos::CAJA){
					cout<<"C";
				}

				if (matriz[i][j] == Elementos::PARED){
					cout<<"X";
				}

				if (matriz[i][j] == Elementos::FINAL){
					cout<<"F";
				}

			}
			cout<<endl;
		}
	}	
};

void pruebaTab(){
	
		Mapa::Elementos** matriz = new Mapa::Elementos*[4];

		for(int i  = 0; i < 4; i++){ matriz[i] = new Mapa::Elementos[5]; }

		matriz[0][0] = Mapa::Elementos::PARED;
		matriz[0][1] = Mapa::Elementos::PARED;
		matriz[0][2] = Mapa::Elementos::PARED;
		matriz[0][3] = Mapa::Elementos::PARED;
		matriz[0][4] = Mapa::Elementos::PARED;

		matriz[1][0] = Mapa::Elementos::PARED;
		matriz[1][1] = Mapa::Elementos::JUGADOR;
		matriz[1][2] = Mapa::Elementos::VACIO;
		matriz[1][3] = Mapa::Elementos::VACIO;
		matriz[1][4] = Mapa::Elementos::PARED;

		matriz[2][0] = Mapa::Elementos::PARED;
		matriz[2][1] = Mapa::Elementos::VACIO;
		matriz[2][2] = Mapa::Elementos::CAJA;
		matriz[2][3] = Mapa::Elementos::FINAL;
		matriz[2][4] = Mapa::Elementos::PARED;

		matriz[3][0] = Mapa::Elementos::PARED;
		matriz[3][1] = Mapa::Elementos::PARED;
		matriz[3][2] = Mapa::Elementos::PARED;
		matriz[3][3] = Mapa::Elementos::PARED;
		matriz[3][4] = Mapa::Elementos::PARED;

		//Iniciando en una pos random

		Mapa map{1,1, 1,1, 4,4, matriz, 4,5};

		map.imprimirTablero();
	
}
	
	/*
		x x x x x		pared pared pared pared pared
		x K	. .	x		pared jug vacio vacio pared
		x . c f	x		pared vacio caja final pared
		x x x x x 		pared pared pared pared pared
	*/	


int main(){
	//int N, M;
	Mapa map;			//Instancie mapa
	
	pruebaTab();

	return 0;
}