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
        contador1 = 2
        contador2 = 20
        contador3 = 20
        contador4 = 20
        print('Realizar reserva...\n')
        nome = input('Insira o nome do passageiro: ')
        os.system('cls') #Limpando a tela de console do windows

        print('\n\tOnibus disponiveis:\n')
        print(f'1 - Alexandria-RN-->Natal-RN     Vagas: {contador1}')
        print(f'2 - Alexadria-RN-->São Paulo-RN     Vagas: {contador2}')
        print(f'3 - Pau dos Ferros-RN-->Fortaleza-CE     Vagas: {contador3}')
        print(f'4 - Parana-RN-->Uirauna-PB     Vagas: {contador4}\n')
        num_bus = int(input('Escolha o número do onibus: ')) 
        os.system('cls') #Limpando a tela de console do windows
        
        if num_bus == 1:
            if contador1 == 0:
                print('Nao ha vagas disponiveis para este onibus')
            else:
                contador1 -= 1
                print('Reserva realizada com sucesso: ')
        elif num_bus == 2:
            if contador2 == 0:
                print('Nao ha vagas disponiveis para este onibus')
            else:
                contador2 -= 1
                print('Reserva realizada com sucesso: ')
        elif num_bus == 3:
            if contador3 == 0:
                print('Nao ha vagas disponiveis para este onibus')
            else: 
                contador3 -= 1
                print('Reserva realizada com sucesso: ')
        elif num_bus == 4:
            if contador4 == 0:
                print('Nao ha vagas disponiveis para este onibus')
            else: 
                contador4 -= 1
                print('Reserva realizada com sucesso: ')

        nome =  nome.title() #inicializando os nomes com letras maiusculas

        #ticket = Tickets(nome, num_bus)
        #function = functions()
        reservation.realizar_reserva(nome, num_bus, contador1, contador2, contador3, contador4)

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
        print('Listando reservas...\n')
        reservation.listar_reservas()
    elif op == 4:
        print('Buscar reserva...')
        nome = input('Insira o nome que deseja verificar a passagem: ')
        nome =  nome.title()
        os.system('cls')

        reservation.buscar_reservas(nome)
    elif op == 5:
        print('Editar reserva...')
        nome = input('insira o nome que consta no bilhete que deseja editar: ')
        os.system('cls')
        reservation.editar_reserva(nome)
    elif op == 6:
        print('Consultar vagas disponiveis para uma data origem - destino...')
    elif op == 7:
        print('Consultar quantitativos de passageiros...')
    elif op == 8:
        print('Saindo...')
    elif op == 9:
        reservation.vagas()
    else:
        print("Opcao invalida!")