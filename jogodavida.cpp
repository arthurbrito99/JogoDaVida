#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void geraMatriz(){

	ifstream arquivo("coordVida.txt");
	string str[255];

	//arquivo.open("coordVida.txt");

	if (!arquivo) {
    	cout << "Erro ao abrir o arquivo 'coordVida.txt'";
    	exit(1);
	}

	while(arquivo){

	}


}

void proximaGeracao(bool matriz[][22]){

	int vizinhosVivos;

	for(int i = 0; i < 80; i++){
		for(int j = 0; j < 22; j++){
			
			vizinhosVivos = 0;

			for(int k = -1; k <= 1; k++){
				for(int l = -1; l <= 1; l++){

					if(((k != 0) && (l != 0)) && (matriz[i + k][j + l] == true)){
						vizinhosVivos++;
					}

				}
			}

			if((matriz[i][j] == true) && (vizinhosVivos < 2))
				matriz[i][j] = false;
			else if((matriz[i][j] == true) && (vizinhosVivos < 3))
				matriz[i][j] = false;
			else if((matriz[i][j] == false) && (vizinhosVivos == 3))
				matriz[i][j] = true;
			

		}
	}
}

void mostra(bool matriz[][22]){
	
	for(int i = 0; i < 80; i++){
		for(int j = 0; j < 22; j++){
			
			if(matriz[i][j] == true)
				cout << "*";
			else
				cout << "-";

		}
		cout << "\n";
	}
}

int main(){

//	bool matriz[80][22];

	ifstream infile("coordVida.txt");
	string line;

int a, b;
while (infile >> a >> b)
{
    // process pair (a,b)
	cout << a;
	cout << b;
	cout << "\n";
}

/*  	getline(infile, line);
	cout << line;
	getline(infile, line);
	cout << line; */


	infile.close();
 
	return 0;
}