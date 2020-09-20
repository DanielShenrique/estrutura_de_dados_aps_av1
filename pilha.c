#include <stdio.h>
#include <stdlib.h>

#define Maximo 10

typedef struct
{
    int indice;
} Chave;
typedef struct
{
    Chave chave;

    int conteudo;
} Elemento;
typedef struct
{
    int inicio;
    int final;
    int quantidadeNumeros;
    int vazia;
    int cheia;

    Elemento elemento[10];
} Pilha;

int VerificarSeEstaVazio(Pilha *pilha, int vazia);
int VerificarSeEstaCheia(Pilha *pilha, int cheia);
void Inserir(Pilha *pilha, int valor, int chave);
void Exluir(Pilha *pilha);

int main(int argc, char const *argv[])
{
    int valor, chave;

    Pilha *pilha;
    pilha = (Pilha *)calloc(1, sizeof(Pilha));

    //TODO:fazer depois as regras de negocio

    system("Pause");
    return 0;
}

int VerificarSeEstaVazio(Pilha *pilha, int vazia)
{
    if (pilha->quantidadeNumeros == 0)
    {
        vazia = 1;
    }
    else
    {
        vazia = 0;
    }

    return vazia;
}

int VerificarSeEstaCheia(Pilha *pilha, int cheia)
{
    if (pilha->quantidadeNumeros == Maximo)
    {
        cheia = 1;
    }
    else
    {
        cheia = 0;
    }

    return cheia;
}

void Inserir(Pilha *pilha, int valor, int chave)
{
    if (VerificarSeEstaCheia(pilha, pilha->cheia))
    {
        printf("A Pilha esta cheia.\n");
    }
    else
    {

        printf("Digite o valor da chave:\n");
        scanf("%d", &chave);
        printf("Digite o valor do conteudo:\n");
        scanf("%d", &valor);

        pilha->elemento[pilha->final].chave.indice = chave;
        pilha->elemento[pilha->final].conteudo = valor;

        if (pilha->quantidadeNumeros == 0)
        {
            pilha->inicio = pilha->final;
        }

        pilha->final++;
        pilha->quantidadeNumeros++;
    }
}

void Exluir(Pilha *pilha)
{
    if (VerificarSeEstaVazio(pilha, pilha->vazia))
    {
        printf("A pilha ja está vazia.\n");
    }
    else
    {
        pilha->elemento[pilha->final].chave.indice = 0;
        pilha->elemento[pilha->final].conteudo = 0;

        pilha->final--;
        pilha->quantidadeNumeros--;
    }
}