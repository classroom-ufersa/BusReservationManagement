import streamlit as st
def realizar_reserva(input_name, input_numBus, num_ticket):
    with open('tickets.txt', 'a+') as file:
                file.write(f'Nome do passageiro: {input_name}\n')
                file.write(f'Número do ônibus selecionado: {input_numBus}\n')
                file.write(f'Número do ticket: {num_ticket}\n')
                file.write('\n')
def excluir_reserva(nome):
    with open('tickets.txt', 'r') as file:
        lines = file.readlines()
    
    with open('tickets.txt', 'w') as file:
        deleted = False
        for i in range(0, len(lines), 4):
            if lines[i].strip() == f'Nome do passageiro: {nome}':
                deleted = True
                continue
            file.write(lines[i])
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
            nome = lines[i].strip().split(': ')[1]
            num_bus = lines[i+1].strip().split(': ')[1]
            num_ticket = lines[i+2].strip().split(': ')[1]
            st.write(f"Nome do passageiro: {nome}")
            st.write(f"Número do ônibus selecionado: {num_bus}")
            st.write(f"Número do ticket: {num_ticket}")
            st.write('---')
def buscar_reservas(nome):
    with open('tickets.txt', 'r') as f:
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

