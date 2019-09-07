#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void geraMatriz(bool **matriz){

	ifstream arqCoordenadas("coordVida.txt");

	if (!arqCoordenadas) {
    	cout << "Erro ao abrir o arquivo 'coordVida.txt'";
    	exit(1);
	}

	int x, y;
	while (arqCoordenadas >> x >> y){

		matriz[x][y] = true;
	}

	arqCoordenadas.close();

}

void mostra(bool **matriz){
	
	for(int i = 0; i < 22; i++){
		for(int j = 0; j < 80; j++){
			
			if(matriz[i][j] == true)
				cout << "*";
			else
				cout << "-";

		}
		cout << "\n";
	}
}

void proximaGeracao(bool **matriz){

	int vizinhosVivos;

	bool **proxGeracao;
	proxGeracao = new bool *[22];
	for(int i = 0; i < 22; i++){
		proxGeracao[i] = new bool[80];
	}

	for(int i = 1; i < 21; i++){
		for(int j = 1; j < 79; j++){
			
			vizinhosVivos = 0;

			for(int k = (-1); k <= 1; k++){
				for(int l = (-1); l <= 1; l++){

					if(!((k == 0) && (l == 0)) && (matriz[i + k][j + l] == true)){
						vizinhosVivos = vizinhosVivos + 1;
					}

				}
			}

			if((matriz[i][j] == true) && (vizinhosVivos < 2))
				proxGeracao[i][j] = false;
			else if((matriz[i][j] == true) && (vizinhosVivos > 3))
				proxGeracao[i][j] = false;
			else if((matriz[i][j] == false) && (vizinhosVivos == 3))
				proxGeracao[i][j] = true;
			else
				proxGeracao[i][j] = matriz[i][j];
			
		}
	}

	for(int i = 0; i < 22; i++){
		for(int j = 0; j < 80; j++){
			
			matriz[i][j] = proxGeracao[i][j];

		}
	}
	mostra(matriz);
	cout << "\n";
	system("sleep 2s");
	system("clear");
}


int main(){

	bool **matriz;
	matriz = new bool *[22];
	for(int i = 0; i < 22; i++){
		matriz[i] = new bool[80];
	}

	geraMatriz(matriz);
	mostra(matriz);
	system("sleep 2s");
	system("clear");
	while(true){
		proximaGeracao(matriz);
	}

	return 0;
}