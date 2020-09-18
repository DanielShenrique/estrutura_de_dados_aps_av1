#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct
{
    int chave;
} Chave;
typedef struct
{
    Chave chave;

    int Elemento;
} Elemento;
typedef struct
{
    int inicio; // inicio da lista
    int final;	// Final da lista
    int no;		// posisao atual de busca do vetor
    int numero;	//

    Elemento Elemento[MAX];
} Lista;

void FormatarTexto(char texto[]) {
	int quat = strlen(texto);
	int letra;
	
	for( letra=0; letra<quat ; letra++) {
		texto[letra] = tolower(texto[letra]);
	}
}

void iniciarLista(Lista *lista) {
	lista->inicio=0; 
    lista->final=0;	
    lista->no=0;	
    lista->numero=0;
}

//void Insercao(List *list, Element *x, int cr);

void main(void)
{

    Lista *lista;
    Elemento *w, *x;
    int cr;

    int chooseOpcion;

    lista = (Lista *)calloc(1, sizeof(Lista));
    w = (Elemento *)calloc(1, sizeof(Elemento));
    x = (Elemento *)calloc(1, sizeof(Elemento));

    int dados[MAX],ELO,tipoID=0;
	char comando[MAX], tipo[3][6];
	
	strcpy(tipo[0],"lista");
	strcpy(tipo[1],"fila");
	strcpy(tipo[2],"pilha");
	
	printf("Escolha o tipo de organização de dados que deseja montar: lista, fila e pilha\n");
	do{
		scanf("%s",comando);
		FormatarTexto(comando);
		
	}while( strcmp(comando,tipo[0]) && strcmp(comando,tipo[1]) && strcmp(comando,tipo[2]) );
	
	if( !strcmp(comando,tipo[0]) ) {//entra e sai de qualquer lugar
		printf("Uma lista\n");
		tipoID = 0;
		
	}
	else {
		if( !strcmp(comando,tipo[1]) ) {//entra no primeiro Indice e sai no ultimo indereço
			printf("Uma fila\n");
			tipoID = 1;
			
		}
		else {
			if( !strcmp(comando,tipo[2]) ) {//entra e sai na mesma posição
				printf("Uma pilha\n");
				tipoID = 2;
				
			}
		}
	}
	
	printf("Escolha o comando para sua %s ou incerrar o programa: fim, buscar e adicionar\n",tipo[tipoID]);
	do{
		scanf("%s",comando);
		FormatarTexto(comando);
		
	}while( strcmp(comando,"fim") );
}

/*void Insercao(List *list, Element *x, int cr)
{
    if (ListaCheia(list) == 1)
    {
        cr = 4; // lista estÃ¡ cheia
    }
    else
    {
        cr = 0; // significa que a lista estÃ¡ vazia

        list->end += 1;                                // o final da lista vai ser acrescentado mais um
        list->element[list->end].key = x->key;         // aqui esse elemento recebe essa chave
        list->element[list->end].content = x->content; // aqui esse elemento recebe esse conteudo

        if (list->num == 0) // se nÃ£o tiver nenhum nÃºmero na lista, o inicio vai receber o fim.
        {
            list->ini = list->end;
        }

        list->num += 1; // aqui acrescenta mais um numero na lista, para dizer quantos tem
    }
}*/
