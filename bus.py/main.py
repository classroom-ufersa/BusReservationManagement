import os #biblioteca padrão que fornece uma maneira de interagir com o sistema operaciona

op = 0 #inicializando a variavel de opção
print('============================================')
print('Boas vindas ao sistema de reserva de onibus!')
print('============================================')

while op != 8:

    print('\tMenu:')
    print('1. Realizar reserva')
    print('2. Excluir reserva')
    print('3. Listar reserva')
    print('4. Buscar reserva')
    print('5. Editar reserva')
    print('6. Consultar vagas disponiveis para uma data origem - destino')
    print('7. Consultar quantitativos de passageiros')
    print('8. Sair')
    

    op = int(input('Sua opção: ')) #escolhendo a opção do menu
    os.system('cls') #Limpando a tela de console do windows

    if op == 1:
        print('Realizar reserva...')
    elif op == 2:
        print('Excluir reserva...')
    elif op == 3:
        print('Listar reserva...')
    elif op == 4:
        print('Buscar reserva...')
    elif op == 5:
        print('Editar reserva...')
    elif op == 6:
        print('Consultar vagas disponiveis para uma data origem - destino...')
    elif op == 7:
        print('Consultar quantitativos de passageiros...')
    elif op == 8:
        print('Saindo...')
    else:
        print("Opcao invalida!")