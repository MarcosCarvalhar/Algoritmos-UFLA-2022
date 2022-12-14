#include <iostream>
#include <cstring>

using namespace std;

struct banda
{
	int id, ano, numFamosas;
	string nome, estilo;
};

banda *redimencionar(banda *rock, int &tam)
{
	banda *aux[tam+1];
	
	memcpy(aux, rock, sizeof(banda)*tam);
	
	/*for(int i = 0; i < tam; i++)
	{
		aux[i] = rock[i];
	}*/
	
	//banda *rock = NULL;
	//rock = new banda[tam+1];
	/*for(int i = 0; i < tam; i++)
	{
		rock[i] = aux[i];
	}*/
	
	return *aux;
}

void incluir(banda *rock, int &tam)
{
	//tam++;
	if(tam >= 5)
	{	
		redimencionar(rock,tam);
	}
	//cout << "Digite o id :" << endl;
	cin >> rock[tam].id;
	//cout << "Digite o nome :" << endl;
	cin.ignore();
	getline(cin,rock[tam].nome);
	//cout << "Digite o estilo musical :" << endl;
	cin >> rock[tam].estilo;
	//cout << "Digite o ano de criacao :" << endl;
	cin >> rock[tam].ano;
	//cout << "Digite o numero de musicas famosas:" << endl;
	cin >> rock[tam].numFamosas;
	//tam++;
}


void excluir(banda *rock, int pos)
{
	rock[pos].id = -1;
	rock[pos].nome = " ";
	rock[pos].estilo = " ";
	rock[pos].ano = -1;
	rock[pos].numFamosas = -1;
}

void listar(banda *rock,int tam)
{
	for(int j = 0; j < tam; j++)
	{
		if(rock[j].id != -1)
		{
			cout << rock[j].id << endl;
			cout << rock[j].nome << endl;
			cout << rock[j].estilo << endl;
			cout << rock[j].ano << endl;
			cout << rock[j].numFamosas << endl;
		}
	}
}

void alterar(banda *rock, int alt)
{
	//cout << "Digite o id :" << endl;
	cin >> rock[alt].id;
	//cout << "Digite o nome :" << endl;
	cin.ignore();
	getline(cin,rock[alt].nome);
	//cout << "Digite o estilo musical :" << endl;
	cin >> rock[alt].estilo;
	//cout << "Digite o ano de criacao :" << endl;
	cin >> rock[alt].ano;
	//cout << "Digite o numero de musicas famosas:" << endl;
	cin >> rock[alt].numFamosas;
}

void ordenar(banda *rock, int tam)
{
	
}

int main()
{
	int opc,tam = 0,exl,alt;
	banda *rock = new banda[5];
	while(opc != 6)
	{
		cout << "\t MENU" << endl;
		cout << "1 - Incluir" << endl;
		cout << "2 - Exluir" << endl;
		cout << "3 - Listar" << endl;
		cout << "4 - Alterar" << endl;
		cout << "5 - Ordenar" << endl;
		cout << "6 - Sair" << endl;
		cout << "Digite a opcao desejada : " << endl;
		
		cin >> opc;
		switch(opc)
		{
			case 1 :
				tam++;
				incluir(rock, tam);
			break;
			
			case 2 : 
				cout << "Digite a posicao do vetor que deseja excluir : " << endl;
				cin >> exl;
				excluir(rock,exl);
			break;
			
			case 3 : 
				listar(rock, tam);
			break;
			
			case 4 : 
				cout << "Digite a posicao do vetor que deseja alterar : " << endl;
				cin >> alt;
				alterar(rock,alt);
			break;
			
			case 5 :
				ordenar(rock,tam);
			break;
		}
	}
	return 0;
}
