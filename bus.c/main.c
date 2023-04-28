#include "includes/reservation.c"
//#include "includes/bus.c"

int main()
{
    Tickets *t = start();
    Bus *b = startBus();
    int option, number;
    char name[50];

    printf("--------------------------------------------\n");
    printf("Boas vindas ao sistema de reserva de onibus!\n");
    printf("--------------------------------------------\n");

    b = registerBus(b, 1, 20, "Alexandria", "Natal");

    do
    {
        printf("Menu:\n1. Realizar reserva\n2. Excluir reserva\n3. Listar reserva\n4. Buscar reserva\n5. Editar reserva\n6. Consultar vagas disponiveis para uma dada origem - destino\n7. Consultar quantitativos de passageiros\n8. Sair\n\n");
        printf("Digite uma opcao: ");
        scanf("%d", &option);
        // system("cls");
        switch (option)
        {
        case 1:
            printf("Realizando reserva...\n\n");
            printf("Informe seu nome: ");
            scanf(" %[^\n]s", name);

            showAvaliableBus(b);

            printf("\nInforme o numero do onibus: ");
            scanf("%d", &number);

            t = makeReservation(t, b, number);
            printf("%s", t->origin);

            printf("\nReserva realizada com sucesso!\n");
            break;
        case 2:
            printf("Excluindo reserva...\n\n");

            break;
        case 3:
            printf("Listando reserva...\n\n");

            break;
        case 4:
            printf("Buscando reserva...\n\n");
            break;
        case 5:
            printf("Editando reserva...\n");
            break;
        case 6:
            printf("Consultando vagas disponiveis...\n\n");
            break;
        case 7:
            printf("Consultando quantitativos de passageiros...\n\n");
            break;
        case 8:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção invalida!\n\n");
            break;
        }
    } while (option != 8);

    return 0;
}