from BusAndTicket import onibus, Tickets
import random

def realizar_reserva(nome, num_bus):
    numero_ticket = random.randint(10000, 99999)
    if num_bus == 1:
        reserva = f'Nome do passageiro: {nome}\nNumero do bilhete: {numero_ticket}\nNumero do onibus: {num_bus}\nDestino: Alexandria-RN-->Natal-RN\n\n'
    elif num_bus == 2:
        reserva = f'Nome do passageiro: {nome}\nNumero do bilhete: {numero_ticket}\nNumero do onibus: {num_bus}\nDestino: Alexadria-RN-->Sao Paulo-RN\n\n'
    elif num_bus == 3:
        reserva = f'Nome do passageiro: {nome}\nNumero do bilhete: {numero_ticket}\nNumero do onibus: {num_bus}\nDestino: Pau dos Ferros-RN-->Fortaleza-CE\n\n'
    elif num_bus == 4:
        reserva = f'Nome do passageiro: {nome}\nNumero do bilhete: {numero_ticket}\nNumero do onibus: {num_bus}\nDestino: Parana-RN-->Uirauna-PB\n\n'
    
    rv = open('bus.py\\data\\reservation.csv', 'a') #para abrir o arquivo
    rv.write(reserva) #Reservando
    rv.close()

def exclui_reserva(nome):
    excluidos = [] #lista com bilhetes excluidos
    with open('bus.py\\data\\reservation.csv', 'r') as f:
        linhas = f.readlines() #Lê todas as linhas do arquivo
    with open('bus.py\\data\\reservation.csv', 'w') as f:
        i = 0
        while i < len(linhas):
            if nome in linhas[i]: #Se o nome estiver na linha, exclui a linha e as três seguintes
                excluidos.extend(linhas[i:i+4]) #adiciona as cinco linhas à lista de excluídos
                i += 4 # avança quatro linhas
            else:
                f.write(linhas[i]) # escreve a linha de volta no arquivo
                i += 1 # avança uma linha
    return excluidos #Retorna a lista de reservas excluídas