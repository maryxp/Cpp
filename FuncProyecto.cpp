#include<iostream>
using namespace std;

void validadorTab(){
    int N, M, countX = 0, countC = 0, countK = 0, countV = 0, countF = 0;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
           
            switch (this->matriz[i][j]){      //Que trabaje por cada elemento de la matriz
				case 'X':
                    countX++;       
				break;
								
				case 'C':               //Sustituida por ::cosito 
                    countC++;
				break;
								
    			case 'K':
		    		countK++;
				    break;
								
				case '.':
				    countV++;
				break;
								
				case 'F':
					countF++;
					break;
            }

            if (countX < 1 || countC < 1 || countV < 1 || countF < 1 || countK < 1 || countK > 1){
                cout<<"Tablero invalido"<<endl;
            }
        }
    }
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

void ganador(){
    int N, M, countC, countF, caja, final;

     for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
           
            switch (this->matriz[i][j]){     
                case 'C':
                    countC++;
                    matriz[i][j] = Mapa::Elementos::CAJA;
                    caja = matriz[i][j];
				break;
								
				case 'F':
                    countF++;
                    matriz[i][j] = Mapa::Elementos::FINAL;
                    final = matriz[i][j];
                break;
            }

            if(countC >= countF){
                if(caja == final){
                    cout<<"Ganaste la partida"<<endl;
                }    
            }
        }
     }
}