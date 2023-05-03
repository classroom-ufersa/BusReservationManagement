#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "includes/reservation/reservation.c"

int main()
{
    Tickets *t = start(); // iniciando a lista de reservas
    Bus *b = startBus();  // iniciando a lista de onibus
    int option, number, vacancies = 10;
    char name[50];

    printf("--------------------------------------------\n");
    printf("Boas vindas ao sistema de reserva de onibus!\n");
    printf("--------------------------------------------\n");

    b = registerBus(b, 1, vacancies, "Alexandria", "Natal");
    b = registerBus(b, 2, vacancies, "Parana", "Uirauna");

    t = readFile(b);

    do
    {
        printf("\nMenu:\n1. Realizar reserva\n2. Excluir reserva\n3. Listar reserva\n4. Buscar reserva\n5. Editar reserva\n6. Consultar vagas disponiveis para uma dada origem - destino\n7. Consultar quantitativos de passageiros\n8. Sair\n\n");
        printf("Digite uma opcao: ");
        scanf("%d", &option);
        system("cls");
        switch (option)
        {
        case 1:
            printf("\nRealizando reserva...\n");
            printf("Informe seu nome: ");
            scanf(" %[^\n]s", name);

            showBus(b); // mostra os onibus disponiveis para reserva

            printf("\nInforme o numero do onibus: ");
            scanf("%d", &number);

            t = makeReservation(t, b, number, name);

            writeFile(t);

            printf("\nReserva realizada com sucesso!\n");

            break;
        case 2:
            printf("\nExcluindo reserva...\n");
            printf("\nInforme seu nome: ");
            scanf(" %[^\n]s", name);

            t = deleteReservation(t, b, name);

            writeFile(t);

            break;
        case 3:
            printf("Listando reserva...\n\n");
            printf("Informe o numero do onibus: ");
            scanf("%d", &number);

            showReservation(t, number);
            break;
        case 4:
            printf("Buscando reserva...\n\n");
            printf("Informe seu nome: ");
            scanf(" %[^\n]s", name);

            printf("Informacoes de sua reserva:\n");
            searchReservation(t, name);
            break;
        case 5:
            printf("\nEditando reserva...\n");
            printf("\nInforme seu nome: ");
            scanf(" %[^\n]s", name);

            showBus(b);

            Tickets *ticket = NULL;
            int found = 0;
            for (ticket = t; ticket != NULL; ticket = ticket->next)
            {
                if (strcmp(name, ticket->passengerName) == 0)
                {
                    printf("\nInforme o numero do onibus para alterar sua reserva: ");
                    scanf("%d", &number);
                    t = editReservation(b, ticket, name, number);
                    printf("\nReserva editada com sucesso!\n");
                    found = 1;
                    break;
                }
            }
            if (!found)
            {
                printf("\nNome nao cadastrado!\n");
            }
            break;
        case 6:
            printf("Consultando vagas disponiveis...\n\n");
            printf("Informe o numero do onibus: ");
            scanf("%d", &number);

            showAvaliableVacancies(b, number);
            break;
        case 7:
            printf("Consultando quantitativos de passageiros...\n\n");
            printf("Informe o numero do onibus: ");
            scanf("%d", &number);

            showPassengerQuantity(b, number);
            break;
        case 8:
            printf("Saindo...\n");

            freeBus(b);
            freeTickets(t);
            break;
        default:
            printf("\nOpcao invalida!\n\n");
            break;
        }
    } while (option != 8);

    return 0;
}