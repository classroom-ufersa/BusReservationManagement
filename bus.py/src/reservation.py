#from BusAndTicket import onibus, Tickets
import random
import csv
import pandas as pd

def realizar_reserva(nome, num_bus):
    numero_ticket = random.randint(10000, 99999)
    if num_bus == 1:
        reserva = f'{nome}|,{numero_ticket}|,{num_bus}|,Alexandria-RN-->Natal-RN|\n'
    elif num_bus == 2:
        reserva = f'{nome}|,{numero_ticket}|,{num_bus}|,Alexadria-RN-->Sao Paulo-RN|\n'
    elif num_bus == 3:
        reserva = f'{nome}|,{numero_ticket}|,{num_bus}|,Pau dos Ferros-RN-->Fortaleza-CE|\n'
    elif num_bus == 4:
        reserva = f'{nome}|,{numero_ticket}|,{num_bus}|,Parana-RN-->Uirauna-PB|\n'

    rv = open('BusReservationManagement\\bus.py\\data\\reservation.csv', 'a') #para abrir o arquivo
    rv.write(reserva) #Reservando
    rv.close()

def vagas():
    lista = pd.read_csv('BusReservationManagement\\bus.py\\data\\reservation.csv')
    select = ['Numero do onibus|']
    lista = lista[select]
    print(lista)
    bus1 = lista[lista == 1].sum()
    print(bus1)

def exclui_reserva(nome):
    excluidos = [] #lista com bilhetes excluidos
    with open('BusReservationManagement\\bus.py\\data\\reservation.csv', 'r') as f:
        linhas = f.readlines() #Lê todas as linhas do arquivo
    with open('BusReservationManagement\\bus.py\\data\\reservation.csv', 'w') as f:
        i = 0
        while i < len(linhas):
            if nome in linhas[i]: #Se o nome estiver na linha, exclui a linha e as três seguintes
                excluidos.extend(linhas[i]) #adiciona as cinco linhas à lista de excluídos
                i += 1 # avança para a proxima linhas
            else:
                f.write(linhas[i]) # escreve a linha de volta no arquivo
                i += 1 # avança uma linha
    return excluidos #Retorna a lista de reservas excluídas

def listar_reservas():
    ler = pd.read_csv('BusReservationManagement\\bus.py\\data\\reservation.csv')
    print(ler.to_string(index=False))

def buscar_reservas(nome):
    with open('BusReservationManagement\\bus.py\\data\\reservation.csv', 'r') as f:
        linhas = f.readlines() #Lê todas as linhas do arquivo
    reservas_encontradas = []
    for i, linha in enumerate(linhas):
        if nome in linha: #Se o nome estiver na linha, adiciona a linha e as três seguintes à lista de reservas encontradas
            reservas_encontradas.extend(linhas[i:i+4])
    if reservas_encontradas:
        print('Reservas encontradas:')
        print('---------------------')
        for reserva in reservas_encontradas:
            print(reserva.strip()) #Remove o caractere de quebra de linha da string
        print('---------------------')
    else:
        print(f'Nenhuma reserva encontrada para o nome {nome}.')

def editar_reserva(nome):
    a = 1

