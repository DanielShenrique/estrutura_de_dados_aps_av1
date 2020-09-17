#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int key;
} Key;
typedef struct
{
    Key key;

    int content;
} Element;
typedef struct
{
    int ini;
    int end;
    int cor;
    int num;

    Element element[10];
} List;

int ListaCheia(List *list);
void Insercao(List *list, Element *x, int cr);

void main(void)
{

    List *list;
    Element *w, *x;
    int cr;

    int chooseOpcion;

    list = (List *)calloc(1, sizeof(List));
    w = (Element *)calloc(1, sizeof(Element));
    x = (Element *)calloc(1, sizeof(Element));

    do
    {
        fflush(stdin);

        printf("1 - Inserir um valor na lista\n");
        printf("2 - Excluir um valor na lista\n");
        printf("3 - Verificar se a lista esta cheia\n");
        printf("4 - Verificar se a lista esta vazia ou se o elemento a ser excluido nao existe\n");
        printf("9999 - para sair do programa\n");

        scanf("%i", &chooseOpcion);

        switch (chooseOpcion)
        {
        case 1:
            Insercao(list, x, cr);
            break;
        case 2:
            // colocar a função de excluir
            break;
        case 3:
            ListaCheia(list);
            break;
        case 4:
            // colocar a função de veridicar se a lista está vazia ou se o elemento não existe
            break;

        default:
            printf("Opcao nao encontrada. Digite outra opcao\n");
            break;
        }
        

    } while (chooseOpcion != 9999);

    system("pause");
}

int ListaCheia(List *list)
{
    if (list->num != 10)
    {
        return 0;
        printf("A lista não esta cheia.\n");
    }
    else
    {
        return 1;
        printf("A lista esta cheia.\n");
    }
}

void Insercao(List *list, Element *x, int cr)
{
    if (ListaCheia(list) == 1)
    {
        cr = 4; // lista está cheia
    }
    else
    {
        cr = 0; // significa que a lista está vazia

        list->end += 1;                                // o final da lista vai ser acrescentado mais um
        list->element[list->end].key = x->key;         // aqui esse elemento recebe essa chave
        list->element[list->end].content = x->content; // aqui esse elemento recebe esse conteudo

        if (list->num == 0) // se não tiver nenhum número na lista, o inicio vai receber o fim.
        {
            list->ini = list->end;
        }

        list->num += 1; // aqui acrescenta mais um numero na lista, para dizer quantos tem
    }
}