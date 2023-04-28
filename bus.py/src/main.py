import sys
import os #biblioteca padrão que fornece uma maneira de interagir com o sistema operaciona
import reservation


op = 0 #inicializando a variavel de opção
print('============================================')
print('Boas vindas ao sistema de reserva de onibus!')
print('============================================')

while op != 8:

    print('\n\tMenu:')
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
        print('Realizar reserva...\n')

        nome = input('Insira o nome do passageiro: ')
        os.system('cls') #Limpando a tela de console do windows

        print('\n\tOnibus disponiveis:\n')
        print('1 - Alexandria-RN-->Natal-RN ')
        print('2 - Alexadria-RN-->São Paulo-RN')
        print('3 - Pau dos Ferros-RN-->Fortaleza-CE')
        print('4 - Parana-RN-->Uirauna-PB\n')
        num_bus = int(input('Escolha o número do onibus: ')) 
        os.system('cls') #Limpando a tela de console do windows
        
        nome =  nome.title() #inicializando os nomes com letras maiusculas

        print('Reserva realizada com sucesso: ')
        #ticket = Tickets(nome, num_bus)
        #function = functions()
        reservation.realizar_reserva(nome, num_bus)

    elif op == 2:
        print('Excluir reserva...')

        nome = input('Insira o nome que consta no bilhete que deseja excluir: ')
        nome =  nome.title() #inicializando os nomes com letras maiusculas
        excluidos = reservation.exclui_reserva(nome)
        if excluidos:
            os.system('cls') #Limpando a tela de console do windows
            print('A seguinte reserva foi excluída:')
            for reserva in excluidos:
                print(reserva)
        else:
            os.system('cls') #Limpando a tela de console do windows
            print('Nenhuma reserva foi encontrada com o nome especificado!')
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