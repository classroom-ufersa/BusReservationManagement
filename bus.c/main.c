#include <stdio.h>
#include <stdlib.h>

int main()
{
    int option;

    printf("--------------------------------------------\n");
    printf("Boas vindas ao sistema de reserva de onibus!\n");
    printf("--------------------------------------------\n");
    do
    {
        printf("\n\tMenu:\n1. Realizar reserva\n2. Excluir reserva\n3. Listar reserva\n4. Buscar reserva\n5. Editar reserva\n6. Consultar vagas disponiveis para uma dada origem - destino\n7. Consultar quantitaticos de passageiros\n8. Sair\n\n");
        printf("Sua opcao: ");
        scanf("%d", &option);
        system("cls");
        switch (option)
        {
        case 1:
            printf("Realizando reserva...\n");
            break;
        case 2:
            printf("Excluindo reserva...\n");
            break;
        case 3:
            printf("Listando reserva...\n");
            break;
        case 4:
            printf("Buscando reserva...\n");
            break;
        case 5:
            printf("Editando reserva...\n");
            ;
            break;
        case 6:
            printf("Consultando vagas disponiveis...\n");
            break;
        case 7:
            printf("Consultando quantitativos de passageiros...\n");
            break;
        case 8:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção invalida!\n");
            break;
        }
    } while (option != 8);

    return 0;
}