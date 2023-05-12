#include <iostream>
#include<fstream>
using namespace std;

class Mapa{
	public:			//Para que se pueda acceder desde fuera de la clase 
	enum class Elementos{
		VACIO, JUGADOR, CAJA, PARED, FINAL
	};
	
	private: 
	int posJugador_x;
	int posJugador_y;
	int puntoFinal_x;
	int puntoFinal_y;
	
	public:
	int N, M;

								//Public
	Elementos** matriz;			//Para que se pueda usar la matriz por otras funciones
	//La matriz posse elementos. Elementos es un tipo. La matriz es de elementos

	Mapa(){}

	Mapa(int posJugador_x, int posJugador_y, int puntoFinal_x, int puntoFinal_y, Elementos** matriz, int N, int M){
			
		this->posJugador_x = posJugador_x;
		this->posJugador_y = posJugador_y;
		this->puntoFinal_x = puntoFinal_x;
		this->puntoFinal_y = puntoFinal_y;
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

			}else{		//Si en dos posiciones mas no es vacio entonces es pared o caja y quedara igual
				matriz[posJugador_y][posJugador_x] = matriz[posJugador_y][posJugador_x];	}
		
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

	void validadorTab(){
		int countX = 0, countC = 0, countK = 0, countV = 0, countF = 0;

		for (int i = 0; i < this->N; i++){
			for (int j = 0; j < this->M;j++){
			
				switch (this->matriz[i][j]){      //Que trabaje por cada elemento de la matriz
					case Mapa::Elementos::PARED :
						countX++;
					break;
									
					case Mapa::Elementos::CAJA :
						countC++;
					break;
									
					case Mapa::Elementos::JUGADOR :
						countK++;
					break;
									
					case Mapa::Elementos::VACIO :
						countV++;
					break;
									
					case Mapa::Elementos::FINAL :
						countF++;
					break;
				}
				/*if(this->matriz[i][j] != Mapa::Elementos::PARED ||this->matriz[i][j] != Mapa::Elementos::CAJA ||
				this->matriz[i][j] != Mapa::Elementos::JUGADOR || this->matriz[i][j] != Mapa::Elementos::VACIO ||this->matriz[i][j] != Mapa::Elementos::FINAL){
				cout<<"Tablero invalido"<<endl;
				}*/
			}
			
		}
		if (countX < 1 || countC < 1 || countV < 1 || countF < 1 || countK < 1 || countK > 1){
			cout<<"Tablero invalido"<<endl;
		}else{
			cout<<"Tablero correcto"<<endl;
		}
	}

	void ganador(){
		int countC, countF;
		Elementos caja;
		Elementos final;

		for (int i = 0; i < this->N; i++){
			for (int j = 0; j < this->M; j++){
			
				switch (this->matriz[i][j]){     
					case Mapa::Elementos::CAJA : 
						countC++;
						matriz[i][j] = Mapa::Elementos::CAJA;
						caja = matriz[i][j];
					break;
									
					case Mapa::Elementos::FINAL :
						countF++;
						matriz[i][j] = Mapa::Elementos::FINAL;
						final = matriz[i][j];
					break;
				}   
				
			}
		}
		if(countC >= countF){
					if(caja == final){
						cout<<"Ganaste la partida"<<endl;
					}else{
						cout<<"Perdiste la partida"<<endl;
					} 
		}
	}
};

class IOHandler{
	Mapa mapaPrueba;

	public:

	IOHandler(){}
	IOHandler(Mapa mapaPrueba){ this->mapaPrueba = mapaPrueba; }

	Mapa getMapaPrueba(){
		return mapaPrueba;
	}

	int leerArchivo(string nombreArchivo){
				
		char caracter;
		int N, M;
		//string nombreArchivo;
		//Para usarlas al crear el mapa		Seran igual a la pos del jugador en i j
		int posJugador_x;	
		int posJugador_y;
		int puntoFinal_x;
		int puntoFinal_y;
	
		ifstream f{nombreArchivo};

		if(f.is_open()){		//Sin .eof ya que luego de leer a matriz seria lo ultimo que haya en el archivo
			
			f>>N;
			f>>M;
				
			Mapa::Elementos** matriz = new  Mapa::Elementos*[N];

			for(int i  = 0; i < N; i++){ matriz[i] = new Mapa::Elementos[M]; }

					for (int i = 0; i < N; i++){
						for (int j = 0; j < M; j++){
							f>>caracter;

							switch (caracter)
							{
								case 'X':
									matriz[i][j] = Mapa::Elementos::PARED;
									break;
								
								case 'C':
									matriz[i][j] = Mapa::Elementos::CAJA;
									break;
								
								case 'K':
									matriz[i][j] = Mapa::Elementos::JUGADOR;
										
									posJugador_x = j;	//La altura, columna del jugador
									posJugador_y = i;	//Que tan alejado esta del piso, fila 

									break;
								
								case '.':
									matriz[i][j] = Mapa::Elementos::VACIO;
									break;
								
								case 'F':
									matriz[i][j] = Mapa::Elementos::FINAL;
									puntoFinal_x = j;
									puntoFinal_y = i;
									break;
								
								default:
									return -1;	//Indicaria que hay error del que se encarga el menu
									
							}
						}	
					}
			//los valores al crear el mapa con la matriz dentro del constructor no se saben
			//porque en distintos archivos la matriz puede ser distinta por ende NO son constantes
			
			Mapa map2{posJugador_x,posJugador_y, puntoFinal_x,puntoFinal_y, matriz, N,M};
			this->mapaPrueba = map2;		//Inicializar el atributo con los valores del constructor	
		}
	
		return 0;
	}

	void teclas(){              //Solo mueve no recibe archivos
		char tecla;
		cin>>tecla;

		if (tecla == 'W'){   
			this->mapaPrueba.mover_arriba();
		}

		if(tecla == 'A'){
			this->mapaPrueba.mover_izquierda();
		}

		if(tecla == 'S'){ 
			this->mapaPrueba.mover_abajo();
		}

		if(tecla == 'D'){
			this->mapaPrueba.mover_derecha();
		}
		//Sino no se hace nada
	}

	void imprimirTablero(){

		/*Como mapa es solo el capaz de imprimir, para que otras funciones puedan imprimir y
		no romper el encapsulamiento hay que crear en IO un metodo que se llame igual y que invoque 
		al imprimir original */
		this->mapaPrueba.imprimirTablero();

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

		Mapa map{1,1, 4,4, matriz, 4,5};

		map.imprimirTablero();

			/*
		x x x x x		pared pared pared pared pared
		x K	. .	x		pared jug vacio vacio pared
		x . c f	x		pared vacio caja final pared
		x x x x x 		pared pared pared pared pared
	*/	
	
}

void impresionesMove(){

	/*
	Ya que las funciones de movimiento estan en la clase mapa y no se pueden acceder desde IO, ya que hacer una instancia
	de IO no serviria para acceder a ese mapa. Se crea un get para poder acceder al mapa de IO que por debajo invoca a Class Map
	*/

	IOHandler leerMove;

	//Pruebas de impresion 	Before & After 
	//cout<<"================"<<endl;
	leerMove.leerArchivo("ArribaUno.txt");
	leerMove.imprimirTablero();

	leerMove.getMapaPrueba().mover_arriba();
	leerMove.imprimirTablero();
	cout<<"================"<<endl;

	leerMove.leerArchivo("ArribaDos.txt");
	leerMove.imprimirTablero();
	
	leerMove.getMapaPrueba().mover_arriba();
	leerMove.imprimirTablero();
	cout<<"================"<<endl;
	
	leerMove.leerArchivo("ArribaTres.txt");
	leerMove.imprimirTablero();
	
	leerMove.getMapaPrueba().mover_arriba();
	leerMove.imprimirTablero();
	cout<<"================"<<endl;
	
	leerMove.leerArchivo("ArribaCuatro.txt");
	leerMove.imprimirTablero();

	leerMove.getMapaPrueba().mover_arriba();
	leerMove.imprimirTablero();
	cout<<"================"<<endl;
	
	leerMove.leerArchivo("ArribaCinco.txt");
	leerMove.imprimirTablero();

	leerMove.getMapaPrueba().mover_arriba();
	leerMove.imprimirTablero();
	cout<<"================"<<endl;


	leerMove.leerArchivo("IzqUno.txt");
	leerMove.imprimirTablero();

	leerMove.getMapaPrueba().mover_izquierda();
	leerMove.imprimirTablero();
	cout<<"================"<<endl;

	leerMove.leerArchivo("IzqDos.txt");
	leerMove.imprimirTablero();
	
	leerMove.getMapaPrueba().mover_izquierda();
	leerMove.imprimirTablero();
	cout<<"================"<<endl;
	
	leerMove.leerArchivo("IzqTres.txt");
	leerMove.imprimirTablero();
	
	leerMove.getMapaPrueba().mover_izquierda();
	leerMove.imprimirTablero();
	cout<<"================"<<endl;
	
	leerMove.leerArchivo("IzqCuatro.txt");
	leerMove.imprimirTablero();

	leerMove.getMapaPrueba().mover_izquierda();
	leerMove.imprimirTablero();
	cout<<"================"<<endl;
	
	leerMove.leerArchivo("IzqCinco.txt");
	leerMove.imprimirTablero();

	leerMove.getMapaPrueba().mover_izquierda();
	leerMove.imprimirTablero();
	cout<<"================"<<endl;


	leerMove.leerArchivo("AbajoUno.txt");
	leerMove.imprimirTablero();

	leerMove.getMapaPrueba().mover_abajo();
	leerMove.imprimirTablero();
	cout<<"================"<<endl;

	leerMove.leerArchivo("AbajoDos.txt");
	leerMove.imprimirTablero();
	
	leerMove.getMapaPrueba().mover_abajo();
	leerMove.imprimirTablero();
	cout<<"================"<<endl;
	
	leerMove.leerArchivo("AbajoTres.txt");
	leerMove.imprimirTablero();
	
	leerMove.getMapaPrueba().mover_abajo();
	leerMove.imprimirTablero();
	cout<<"================"<<endl;
	
	leerMove.leerArchivo("AbajoCuatro.txt");
	leerMove.imprimirTablero();

	leerMove.getMapaPrueba().mover_abajo();
	leerMove.imprimirTablero();
	cout<<"================"<<endl;
	
	leerMove.leerArchivo("AbajoCinco.txt");
	leerMove.imprimirTablero();

	leerMove.getMapaPrueba().mover_abajo();
	leerMove.imprimirTablero();
	cout<<"================"<<endl;


	leerMove.leerArchivo("DerUno.txt");
	leerMove.imprimirTablero();

	leerMove.getMapaPrueba().mover_derecha();
	leerMove.imprimirTablero();
	cout<<"================"<<endl;

	leerMove.leerArchivo("DerDos.txt");
	leerMove.imprimirTablero();
	
	leerMove.getMapaPrueba().mover_derecha();
	leerMove.imprimirTablero();
	cout<<"================"<<endl;
	
	leerMove.leerArchivo("DerTres.txt");
	leerMove.imprimirTablero();
	
	leerMove.getMapaPrueba().mover_derecha();
	leerMove.imprimirTablero();
	cout<<"================"<<endl;
	
	leerMove.leerArchivo("DerCuatro.txt");
	leerMove.imprimirTablero();

	leerMove.getMapaPrueba().mover_derecha();
	leerMove.imprimirTablero();
	cout<<"================"<<endl;
	
	leerMove.leerArchivo("DerCinco.txt");
	leerMove.imprimirTablero();

	leerMove.getMapaPrueba().mover_derecha();
	leerMove.imprimirTablero();
	//cout<<"================"<<endl;	

}

int main(){

	Mapa map;			//Instancie mapa
	Mapa map2;
	pruebaTab();

	//IOHandler lectura;

	//Pruebas de lectura de archivos
	//lectura.leerArchivo("mapaUno.txt");
	//lectura.imprimirTablero();		//Modifica el objeto luego que lee el archivo
	//lectura.leerArchivo("mapaDos.txt");
	//lectura.imprimirTablero();
	//lectura.leerArchivo("mapaTres.txt");
	//lectura.imprimirTablero();
	
	IOHandler lectura;

	/*Prueba de tableros validos
	
	lectura.leerArchivo("ValidadoUno.txt");
	lectura.imprimirTablero();
	lectura.getMapaPrueba().validadorTab();
	cout<<endl;

	lectura.leerArchivo("ValidadoDos.txt");
	lectura.imprimirTablero();
	lectura.getMapaPrueba().validadorTab();
	cout<<endl;

	lectura.leerArchivo("ArribaTres.txt");
	lectura.imprimirTablero();
	lectura.getMapaPrueba().validadorTab();
	cout<<endl;*/

	lectura.leerArchivo("Teclas.txt");
	lectura.imprimirTablero();
	cout<<endl;
	lectura.teclas();
	lectura.imprimirTablero();
	lectura.teclas();
	cout<<endl;
	lectura.imprimirTablero();
	cout<<endl;
	lectura.teclas();
	lectura.imprimirTablero();
	cout<<endl;
	/*lectura.getMapaPrueba().mover_arriba();
	lectura.imprimirTablero();
	cout<<endl;
	lectura.getMapaPrueba().mover_arriba();
	lectura.imprimirTablero();
	cout<<endl;
	lectura.getMapaPrueba().ganador();*/

	return 0;

}