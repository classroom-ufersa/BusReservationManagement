#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "reservation.h" // inclui a definição das estruturas e protótipos das funções

struct bus // Defininido a estrutura onibus
{
    int number;
    int vacancies;
    char origin[50];
    char destination[50];
};

struct tickets // Definindo a estrutura de bilhetes
{
    char passengerName[50];
    char origin[50];
    char destination[50];
    int busNum;

    Tickets *next;
};

struct ticket // Definição da estrutura ticket, que agrupa os bilhetes em uma lista encadeada
{
    Tickets *first;
};

Ticket *start() // Função para criar uma nova instância da estrutura ticket e inicializar o primeiro ponteiro com NULL
{
    Ticket *t = (Ticket *)malloc(sizeof(Ticket)); // Aloca dinamicamente a memória para a estrutura ticket
    if (t == NULL)
    {
        printf("Erro na alocação!\n");
        exit(1);
    }
    t->first = NULL; // Inicializa o primeiro ponteiro com NULL, indicando que a lista está vazia

    return t; // Retorna a nova instância da estrutura ticket
}

void makeReservation(Ticket *l, char *name, char *origin, char *destination) // Função para criar um novo bilhete e adicioná-lo à lista encadeada de bilhetes
{
    Tickets *t = (Tickets *)malloc(sizeof(Tickets));
    if (t == NULL)
    {
        printf("Erro na alocação!\n");
        exit(1);
    }
    strcpy(t->passengerName, name);      // Copia o nome do passageiro para o bilhete
    strcpy(t->origin, origin);           // Copia a origem para o bilhete
    strcpy(t->destination, destination); // Copia o destinatario para o bilhete
    t->next = l->first;                  // Configura o ponteiro next do novo bilhete para apontar para o primeiro bilhete da lista
    l->first = t;                        // Chama a função para escrever os dados do passageiro em um arquivo

    writePassenger(name, origin, destination); // call the function to write data to a file
}
// Função para escrever os dados do passageiro em um arquivo de texto
void writePassenger(char *name, char *origin, char *destination)
{
    FILE *f = fopen("../service/data.txt", "a"); // Abre o arquivo em modo "append", para adicionar novos dados ao final do arquivo
    if (f == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    fprintf(f, "Nome: %s\nOrigem: %s\nDestino: %s\n\n", name, origin, destination); // Escreve os dados do passageiro no arquivo
    fclose(f);                                                                      // Fecha o arquivo
}

void deleteReservation(Ticket *t, char *nome)
{
    if(t->first == NULL )//para verificar se a lista esta vazia
    {  
        printf("Nao ha reservas cadastradas!");
    } 
    
    Tickets *prev = NULL;
    Tickets *curr = t->first;

    while (curr != NULL && strcmp(curr->passengerName, nome) != 0) // Procure o bilhete com o nome indicado
    {
        prev = curr;
        curr = curr->next;
    }

     if (curr == NULL) // Se o bilhete não foi encontrado
    {
        printf("Nao foi possivel encontrar uma reserva com o nome '%s'\n", nome);
        return;
    }

    if (prev == NULL) // Se o bilhete é o primeiro na lista
    {
        t->first = curr->next;
    }
    else // Se o bilhete não é o primeiro na lista
    {
        prev->next = curr->next;
    }

    printf("A reserva de %s de %s para %s foi cancelada!\n", curr->passengerName, curr->origin, curr->destination);

    free(curr); // Libera a memória alocada para o bilhete excluído
}

void showReservation(Ticket *t)
{
    if (t->first == NULL) // Checks if list is empty
    {
        printf("Nao ha reservas cadastradas!");
    }
    for (Tickets *i = t->first; i != NULL; i = i->next)
    {
        printf("Nome do passageiro: %s\nOrigem: %s\nDestino: %s\n\n", i->passengerName, i->origin, i->destination);
    }
}