import streamlit as st

def realizar_reserva(input_name, input_numBus, num_ticket):
    #Formatar a reserva como uma string separada por linhas
    reserva = f'Nome do passageiro: {input_name}\n' \
              f'Número do ônibus selecionado: {input_numBus}\n' \
              f'Número do ticket: {num_ticket}\n'

    #Ler as reservas existentes do arquivo
    reservas = [] # Cria uma lista vazia chamada "reservas"
    with open('tickets.txt', 'r') as file:
        reserva_atual = ''
        for line in file:
            line = line.strip() #Remove espaços em branco extras do início e do fim da linha.
            if line == '': #Verifica se a linha está vazia. Isso indica o fim de uma reserva.
                reservas.append(reserva_atual) #Adiciona a reserva atual à lista de reservas.
                reserva_atual = '' #Limpa a variável "reserva_atual" para armazenar a próxima reserva.
            else:
                reserva_atual += line + '\n' #Adiciona a linha atual à variável "reserva_atual".

    reservas.append(reserva) #Adicionar nova reserva à lista reservas
    reservas.sort() #Ordenar a lista em ordem alfabética dos nomes

    with open('tickets.txt', 'w') as file: #Escrever as reservas ordenadas de volta ao arquivo
        for reserva in reservas:
            file.write(reserva + '\n')
def excluir_reserva(nome):
    with open('tickets.txt', 'r') as file:
        lines = file.readlines() #Lê o arquivo por linha
    
    with open('tickets.txt', 'w') as file:
        deleted = False
        for i in range(0, len(lines), 4): #itera sobre os indices da lista 'lines' com o encremento de +4
            if lines[i].strip() == f'Nome do passageiro: {nome}': #verifica se a linha atual possui o nome fornecido
                deleted = True
                continue #Pula para a próxima iteração do loop
            file.write(lines[i]) #escreve a linha atual(nome do passageiro) no arquivo
            file.write(lines[i+1])
            file.write(lines[i+2])
            file.write(lines[i+3])

    if deleted:
        st.write(f"A reserva para {nome} foi excluída com sucesso.")
    else:
        st.write(f"Não foi encontrada uma reserva para {nome}.")
def listar_reservas():
    with open('tickets.txt', 'r') as file:
        lines = file.readlines()
    
    if len(lines) == 0:
        st.write("Não há reservas registradas.")
    else:
        for i in range(0, len(lines), 4):
            nome = lines[i].strip().split(': ')[1] #Divide a linha em duas partes usando o separador ': '
            num_bus = lines[i+1].strip().split(': ')[1]
            num_ticket = lines[i+2].strip().split(': ')[1]
            st.write(f"Nome do passageiro: {nome}")
            st.write(f"Número do ônibus selecionado: {num_bus}")
            st.write(f"Número do ticket: {num_ticket}")
            st.write('---')  
def buscar_reservas(nome):
    with open('tickets.txt', 'r') as file:
        lines = file.readlines()

    reservas_encontradas = []
    for i in range(0, len(lines), 4):
        nome_passageiro = lines[i].strip().split(': ')[1]
        if nome_passageiro.lower() == nome.lower():
            num_bus = lines[i+1].strip().split(': ')[1]
            num_ticket = lines[i+2].strip().split(': ')[1]
            reservas_encontradas.append((nome_passageiro, num_bus, num_ticket))

    if len(reservas_encontradas) == 0:
        st.write(f"Não foi encontrada nenhuma reserva para {nome}.")
    else:
        for reserva in reservas_encontradas:
            st.write('Reserva encontrada:')
            st.write(f"Nome do passageiro: {reserva[0]}")
            st.write(f"Número do ônibus selecionado: {reserva[1]}")
            st.write(f"Número do ticket: {reserva[2]}")
            st.write('---')
def editar_reserva(nome, new_bus,new_num_ticket):
    with open('tickets.txt', 'r') as file:
        lines = file.readlines()

    with open('tickets.txt', 'w') as file:
        edited = False
        for i in range(0, len(lines), 4):
            if lines[i].strip() == f'Nome do passageiro: {nome}':
                # Escrever os novos dados da reserva no arquivo
                file.write(f'Nome do passageiro: {nome}\n')
                file.write(f'Número do ônibus selecionado: {new_bus}\n')
                file.write(f'Número do ticket: {new_num_ticket}\n')
                file.write(f'\n')

                edited = True
            else:
                file.write(lines[i])
                file.write(lines[i+1])
                file.write(lines[i+2])
                file.write(lines[i+3])

    if edited:
        st.write(f"A reserva para {nome} foi editada com sucesso.")