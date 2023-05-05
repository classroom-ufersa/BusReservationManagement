#include "reservation.h" // inclui a definição das estruturas e protótipos das funções
#include "../bus/bus.c"

struct tickets // definindo a estrutura de bilhetes
{
    char passengerName[50];
    char origin[50];
    char destination[50];
    int busNum;

    Tickets *next;
};

Tickets *start() // função para criar uma nova instância da estrutura ticket e inicializar o primeiro ponteiro com NULL
{
    return NULL;
}

Tickets *makeReservation(Tickets *t, Bus *b, int number, char *name) // função para criar um novo bilhete e adicioná-lo à Tickets encadeada de bilhetes
{
    Tickets *ticket = (Tickets *)malloc(sizeof(Tickets));
    Tickets *previous = NULL;
    Tickets *current = t;

    Bus *bus = (Bus *)malloc(sizeof(Bus));
    if (ticket == NULL || bus == NULL)
    {
        printf("Erro na alocação!\n");
        exit(1);
    }

    for (bus = b; bus != NULL; bus = bus->next)
    {
        if (number == bus->number) // verifica se o numero do onibus é existe e atribui os valores à passagem
        {
            if(bus->vacancies == 0){
                printf("As vagas deste onibus esgotou!");
                return t;
            }
            strcpy(ticket->origin, bus->origin);
            strcpy(ticket->destination, bus->destination);
            strcpy(ticket->passengerName, name);

            ticket->busNum = bus->number;
            bus->vacancies--; // diminui a quantidade de vagas
            ticket->next = t;

            break;
        }
    }

    while (current != NULL && (strcmp(current->passengerName, name)) < 0)
    {
        previous = current;
        current = current->next;
    }

    if (previous == NULL)
    {
        t = ticket; // o novo bilhete deve ser o primerio da lista
    }
    else
    {
        previous->next = ticket; // insere o novo bilhete apos o bilhete anterior
    }
    ticket->next = current;

    return t;
}

Tickets *deleteReservation(Tickets *t, Bus *b, char *name)
{
    Tickets *prev = NULL;
    Tickets *ticket = t;
    if (ticket == NULL)
    {
        printf("\nLista vazia!\n");
        return t;
    }

    Bus *bus = b;

    while (ticket != NULL && strcmp(ticket->passengerName, name) != 0)
    {
        prev = ticket;
        ticket = ticket->next;
    }

    if (ticket == NULL)
    {
        printf("\nNome nao cadastrado!\n");
        return t;
    }

    // verifica se o nó a ser excluído é o primeiro nó da lista
    if (ticket == t)
    {
        t = ticket->next;
    }
    else
    {
        prev->next = ticket->next;
    }

    while (bus != NULL && bus->number != ticket->busNum)
    {
        bus = bus->next;
    }

    if (bus != NULL)
    {
        bus->vacancies++;
    }

    free(ticket);

    // t = prev;

    printf("\nReserva excluida com sucesso!\n");
    return t;
}

void showReservation(Tickets *t, int number)
{
    Tickets *ticket = (Tickets *)malloc(sizeof(Tickets));
    int found = 0;
    int alreadyPrinted = 0;

    for (ticket = t; ticket != NULL; ticket = ticket->next)
    {
        if (!alreadyPrinted)
        {
            printf("\nPassageiros com reservas no onibus %d\n", number);
            alreadyPrinted = 1;
        }

        if (number == ticket->busNum)
        {
            printf("Nome: %s\n", ticket->passengerName);
            found = 1;
        }
    }
    if (!found)
    {
        printf("\nNumero do onibus inexistente!\n");
    }
}

void searchReservation(Tickets *t, char *name)
{
    int found = 0;
    int alreadyPrinted = 0;
    Tickets *ticket = (Tickets *)malloc(sizeof(Tickets));
    if (ticket == NULL)
    {
        exit(1);
    }
    for (ticket = t; ticket != NULL; ticket = ticket->next)
    {
        if (!alreadyPrinted)
        {
            printf("Informacoes de sua reserva:\n");
            alreadyPrinted = 1;
        }
        if (strcmp(ticket->passengerName, name) == 0)
        {
            printf("\nNome: %s\nNumero do onibus: %d\nOrigem: %s\nDestino: %s\n", ticket->passengerName, ticket->busNum, ticket->origin, ticket->destination);
            found = 1;
        }
    }
    if (!found)
    {
        printf("\nNome nao cadastrado!\n");
    }
}

void editReservation(Tickets *t, Bus *b, int number)
{
    Bus *bus = NULL;
    for (bus = b; bus != NULL; bus = bus->next)
    {
        // aumenta a vaga do onibus do qual a reserva sera desfeita
        if (bus->number == t->busNum)
        {
            bus->vacancies++;
        }
        // verificando o elemento o qual contem o mesmo numero/codigo do onibus
        if (number == bus->number)
        {
            strcpy(t->origin, bus->origin);
            strcpy(t->destination, bus->destination);
            t->busNum = bus->number;

            bus->vacancies--;
        }
    }
}

void writeFile(Tickets *t)
{
    FILE *f = fopen("../service/data.txt", "w");
    if (f == NULL)
    {
        printf("Erro na abertura do arquivo!\n");
        exit(1);
    }

    while (t != NULL)
    {
        // grava os dados do bilhete no arquivo
        fprintf(f, "Nome: %s\n", t->passengerName);
        fprintf(f, "Origem: %s\n", t->origin);
        fprintf(f, "Destino: %s\n", t->destination);
        fprintf(f, "Numero do onibus: %d\n\n", t->busNum);

        t = t->next;
    }

    fclose(f); // fecha o arquivo
}

Tickets *readFile(Tickets *t, Bus *b)
{
    FILE *f = fopen("../service/data.txt", "r");
    Tickets *head = NULL;
    Tickets *temp = NULL;
    Tickets *aux = NULL;
    if (f == NULL)
    {
        printf("\nErro ao abrir o arquivo!\n");
        exit(1);
    }

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    if (size == 0) // arquivo vazio
    {
        fclose(f);
        return t;
    }
    fseek(f, 0, SEEK_SET); // retorna o ponteiro do arquivo ao início

    while (!feof(f))
    {
        Tickets *ticket = (Tickets *)malloc(sizeof(Tickets));
        if (ticket == NULL)
        {
            printf("Erro na alocacao!\n");
            exit(1);
        }
        fscanf(f, "Nome: %s\nOrigem: %s\nDestino: %s\nNumero do onibus: %d\n\n", ticket->passengerName, ticket->origin, ticket->destination, &ticket->busNum);
        ticket->next = NULL;
        if (head == NULL)
        {
            head = ticket;
            temp = ticket;
        }
        else
        {
            temp->next = ticket;
            temp = ticket;
        }
    }

    aux = head; // mexe em uma copia da struct tickets head
    while (aux != NULL)
    {
        for (Bus *bus = b; bus != NULL; bus = bus->next) // acha o numero da reserva associadp ao numero do onibus
        {
            if (aux->busNum == bus->number)
            {
                bus->vacancies--; // declementa a quantidade de vagas
            }
        }
        aux = aux->next;
    }

    fclose(f);
    return head;
}

void freeTickets(Tickets *t)
{
    Tickets *ticket = t;
    Tickets *aux;
    while (ticket != NULL)
    {
        aux = ticket->next;
        free(ticket);
        ticket = aux;
    }
}
