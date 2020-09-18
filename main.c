#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

#define MAX 10

typedef struct
{
	int chave;
} Chave;
typedef struct
{
	Chave chave;

	int conteudo;
} Elemento;
typedef struct
{
	int inicio; // inicio da lista
	int final;	// Final da lista
	int no;		// posisao atual de busca do vetor
	int numero; // numero de elementos na lista

	Elemento elemento[MAX];
} Lista; //N�o seria uma boa botar um nome mais generico como organisasao? lista parece que remete somente as listas

void FormatarTexto(char texto[]);
void iniciarLista(Lista *lista);

void main(void)
{
	
	setlocale(LC_ALL,"");
	
	Lista *lista;
	Elemento *w, *x;

	int cr;// como iremos trabalhar com esse dado?

	lista = (Lista *)calloc(1, sizeof(Lista));
	w = (Elemento *)calloc(1, sizeof(Elemento));
	x = (Elemento *)calloc(1, sizeof(Elemento));

	int tipoID = 0;
	char comando[MAX], tipo[3][6];
	bool vasia;

	// isso aqui não poderia ser simplificado com apenas 
	// tipo[3][6] = {"lista", "fila", "pilha"}; ?
	strcpy(tipo[0], "lista");
	strcpy(tipo[1], "fila");
	strcpy(tipo[2], "pilha");

	// Aqui escolhemos se queremos lista, filas ou pilhas
	printf("Escolha o tipo de organiza��o de dados que deseja montar: lista, fila e pilha\n");
	do
	{
		scanf("%s", comando);
		FormatarTexto(comando);

	} while (strcmp(comando, tipo[0]) && strcmp(comando, tipo[1]) && strcmp(comando, tipo[2]));

	// Aqui definimos o em o que vamos trabalhar
	if (!strcmp(comando, tipo[0]))
	{ //entra e sai de qualquer lugar -> lista
		printf("Uma lista\n");
		tipoID = 0;
	}
	else
	{
		if (!strcmp(comando, tipo[1]))
		{ //entra no primeiro Indice e sai no ultimo indere�o -> fila
			printf("Uma fila\n");
			tipoID = 1;
		}
		else
		{
			if (!strcmp(comando, tipo[2]))
			{ //entra e sai na mesma posi��o -> pilha
				printf("Uma pilha\n");
				tipoID = 2;
			}
		}
	}

	// Aqui são as operações que o usuário pode fazer (transformar isso aqui em função ?)
	printf("Escolha o comando para sua %s ou incerrar o programa: fim, incerção e exclusão\n", tipo[tipoID]);
	do
	{
		scanf("%s", comando);
		FormatarTexto(comando);

		// criar uma função que pegue o que o usuário quer

	} while (strcmp(comando, "fim"));
}


/*
	Aqui estão as funções do projeto-------------------------------------------------------------------------------
*/

void Insercao(Lista *lista, Elemento *x, int cr)
{
	if (ListaCheia(lista) == 1)//lista chea seria?
	{
		cr = 4; // lista está cheia
	}
	else
	{
		cr = 0; // significa que a lista está vazia

		lista->final += 1;									  // o final da lista vai ser acrescentado mais um
		lista->elemento[lista->final].chave = x->chave;		  // aqui esse elemento recebe essa chave
		lista->elemento[lista->final].conteudo = x->conteudo; // aqui esse elemento recebe esse conteudo

		if (lista->numero == 0) // se não tiver nenhum número na lista, o inicio vai receber o fim.
		{
			lista->inicio = lista->final;
		}

		lista->numero++; // aqui acrescenta mais um numero na lista, para dizer quantos tem
	}
}

// transforma a palavra toda para letras minusculas para melhor tratamento das strings para comparasao

void FormatarTexto(char texto[])
{
	int quat = strlen(texto);
	int letra;

	for (letra = 0; letra < quat; letra++)
	{
		texto[letra] = tolower(texto[letra]);
	}
}

// inicia uma lista 
void iniciarLista(Lista *lista)
{
	lista->inicio = 0;
	lista->final = 0;
	lista->no = 0;
	lista->numero = 0;
}

//checar se a lista esta vazia
bool checarLista(Lista *lista) {// estou pensando nessa fun��o talvez ela seja muito desnessesaria
	return (lista->final==0) ? true : false;
}

//fun��o que realiza a busca do ta lista,tabela e pilha
void buscar(Lista *lista,int buscado, char tipo[]) {
	bool acho = false;
	
	if(checarLista(lista)) {
		printf("Lista vazia!\n retorne as opi��es\n");
	}
	else {
		for(lista->no=0; (lista->no<lista->final) && !acho == false ; lista->no++) {//eplicando esse for que pode esta um pouco confuso que vai fazer de I ate o final atual na lista ate ele ve se achou ou n�o a posi��o quebrando o la�o
			if(lista->elemento[lista->no].conteudo == buscado) {//verifica se e igual ao valor buscado
				acho = true;
			}
		}
		if(acho)
			printf("O %i foi encontrado na posi��o %i na sua %s.\n",buscado, lista->no,tipo);//caso ache
		else
			printf("O %i nao foi encontrado na %s.\n",buscado,tipo);//caso nao ache
			
	}
}
