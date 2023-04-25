#include <iostream>
#include <string.h>
using namespace std;

int** crearMatriz(int N, int M){
	int** matriz = new int* [M];

	for (int i = 0; i < N; i++){
		matriz[i] = new int[M];
	}
	return matriz;
}

void llenarMatriz(int** matriz, int N, int M) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			do{
				cout<<"X";
			}while(i == 0 && i == N-1 && j == 0 && j == M-1);

		}
		cout << endl;
		
	}
}

void opciones() {
	//Se cargara el tablero de la opcion 4
	cout << "W" << endl;
	cout << "A" << endl;
	cout << "S" << endl;
	cout << "D" << endl;
}

void leerCadena(string cadena) {

	cin >> cadena;

	for (int i = 0; i < cadena.size(); i++) {

		if (cadena[i] != 'W' || cadena[i] != 'A' || cadena[i] != 'S' || cadena[i] != 'D') {
			cout << "Tablero inválido" << endl;
		}
	}
}

void menu(){
	int opcion = 0;
	string cadena;
	/*int N, M;
	int** matriz;
	*/
	do{

		cout<<"1. Juego en vivo"<<endl;
		cout<<"2. Juego cargado"<<endl;
		cout<<"3. Cargar partida"<<endl;
		cout<<"4. Cargar tablero"<<endl;
		cout<<"5. Salir"<<endl;

		cin>>opcion;

		switch (opcion){
		case 1:
			opciones();
			break;

		case 2:
			leerCadena(cadena);
			
			break;

		case 3:


			break;

		case 4:

			
			break;

		case 5:
			break;

		default:
			cout << "Opción inválida" << endl;
			break;
		}
		

	}while(opcion != 5);
	
}

int main(){
	int N, M, opcion;
	cin >> N >> M;

	int** matriz = crearMatriz(N,M);
	llenarMatriz(matriz, N, M);

	menu();
		
	return 0;
}	
