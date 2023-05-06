#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "includes/reservation/reservation.c"

int main()
{
    Tickets *t = start(); // iniciando a lista de reservas
    Bus *b = startBus();  // iniciando a lista de onibus
    int option, number, vacancies = 10;
    char name[50], firstChar, firstCharUpper;

    printf("--------------------------------------------\n");
    printf("Boas vindas ao sistema de reserva de onibus!\n");
    printf("--------------------------------------------\n");

    b = registerBus(b, 1, vacancies, "Alexandria", "Natal");
    b = registerBus(b, 2, vacancies, "Parana", "Uirauna");

    t = readFile(t, b);

    do
    {
        printf("\nMenu:\n1. Realizar reserva\n2. Excluir reserva\n3. Listar reserva\n4. Buscar reserva\n5. Editar reserva\n6. Consultar vagas disponiveis para uma dada origem - destino\n7. Consultar quantitativos de passageiros\n8. Sair\n\n");
        printf("Digite uma opcao: ");
        if (scanf("%d", &option) != 1)
        {
            // Limpando o buffer do teclado
            int c;
            while ((c = getchar() != '\n') && c != EOF)
            {
                // Descartando caracteres
            }
            printf("\nOpcao invalida!\n");
            continue;
        }
        system("cls");
        switch (option)
        {
        case 1:
            printf("\nRealizando reserva...\n");
            printf("Informe seu nome: ");
            scanf(" %[^\n]s", name);

            // converte o primeiro caractere do nome para maiúsculo
            firstChar = name[0]; //Obtém o primeiro caractere do nome do passageiro
            firstCharUpper = toupper(firstChar); //Converte o primeiro caractere para maiúsculo
            name[0] = firstCharUpper; //Atualiza o primeiro caractere do nome com a versão maiúscula

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

            // converte o primeiro caractere do nome para maiúsculo
            firstChar = name[0];
            firstCharUpper = toupper(firstChar);
            name[0] = firstCharUpper;

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

            // converte o primeiro caractere do nome para maiúsculo
            firstChar = name[0];
            firstCharUpper = toupper(firstChar);
            name[0] = firstCharUpper;

            searchReservation(t, name);

            break;
        case 5:
            printf("\nEditando reserva...\n");
            printf("\nInforme seu nome: ");
            scanf(" %[^\n]s", name);

            // converte o primeiro caractere do nome para maiúsculo
            firstChar = name[0];
            firstCharUpper = toupper(firstChar);
            name[0] = firstCharUpper;

            int found = 0;
            Tickets *ticket = NULL;
            // passando apenas a reserva referente ao nome do usuario e mostrando os onibus disponiveis
            for (ticket = t; ticket != NULL; ticket = ticket->next)
            {
                if (strcmp(ticket->passengerName, name) == 0)
                {
                    printf("\nLista de onibus disponiveis:\n");
                    showBus(b);
                    printf("\n\nInforme outro numero de onibus para alterar sua reserva: ");
                    scanf("%d", &number);
                    editReservation(ticket, b, number);
                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                printf("\nNome nao encontrado!\n");
            }

            writeFile(t);

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

            showPassengerQuantity(b, vacancies, number);
            break;
        case 8:
            printf("Saindo...\n");

            freeBus(b);
            freeTickets(t);
            break;
        default:
            printf("\nOpcao invalida!\n");
            break;
        }
    } while (option != 8);

    return 0;
}