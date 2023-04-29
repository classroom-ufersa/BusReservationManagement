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

Tickets *makeReservation(Tickets *l, Bus *b, int number, char *name) // função para criar um novo bilhete e adicioná-lo à lista encadeada de bilhetes
{
    Tickets *ticket = (Tickets *)malloc(sizeof(Tickets));
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
            strcpy(ticket->origin, bus->origin);
            strcpy(ticket->destination, bus->destination);
            strcpy(ticket->passengerName, name);
            ticket->busNum = bus->number;

            bus->vacancies--; // diminui a quantidade de vagas

            ticket->next = l;
            return ticket;
        }
    }

    return NULL;
}

Tickets *deleteReservation(Tickets *t, Bus *b, char *name)
{
    Tickets *prev = NULL;
    Tickets *ticket = t;
    Bus *bus = b;

    while (ticket != NULL && (strcmp(ticket->passengerName, name)) != 0)
    {
        prev = ticket;
        ticket = ticket->next;
    }

    while (bus->number != ticket->busNum)
    {
        b = bus->next; // procura o onibus vinculado a reserva
    }

    if (bus->number == ticket->busNum)
    {
        bus->vacancies++; // aumente a quantidade de vagas disponiveis
    }

    if (ticket == NULL)
    {
        printf("\nNome nao cadastrado!\n");
        return t; // não achou a reserva e retorna a lista original
    }

    if (prev == NULL)
    {
        t = ticket->next;
    }
    else
    {
        prev->next = ticket->next;
    }

    free(ticket);

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

Tickets *editReservation(Bus *b, Tickets *t, char *name, int num)
{
    Tickets *ticket = NULL;
    for (ticket = t; ticket != NULL; ticket = ticket->next)
    {
        if (strcmp(name, ticket->passengerName) == 0)
        {
            Bus *bus = NULL;
            for (bus = b; bus != NULL; bus = bus->next)
            {
                if (num == bus->number)
                {
                    strcpy(ticket->origin, bus->origin);
                    strcpy(ticket->destination, bus->destination);
                    ticket->busNum = bus->number;
                    return ticket;
                }
            }
            break;
        }
    }
    return t;
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