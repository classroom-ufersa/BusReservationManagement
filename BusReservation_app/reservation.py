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
# def editar_reserva(nome):
#     with open('tickets.txt', 'r') as file:
#         lines = file.readlines()

#     reservas_encontradas = []
#     indices_reservas = []
#     for i in range(0, len(lines), 4):
#         nome_passageiro = lines[i].strip().split(': ')[1]
#         if nome_passageiro.lower() == nome.lower():
#             reservas_encontradas.append((nome_passageiro, lines[i+1], lines[i+2]))
#             indices_reservas.append(i)

#     if len(reservas_encontradas) == 0:
#         st.write(f"Não foi encontrada nenhuma reserva para {nome}.")
#     else:
#         with open('tickets.txt', 'w') as file:
#             for i, line in enumerate(lines):
#                 if i not in indices_reservas:
#                     file.write(line)
#             for reserva in reservas_encontradas:
#                 st.write(f"Reserva encontrada para {reserva[0]}:")
#                 st.write(f"Número do ônibus selecionado: {reserva[1]}")
#                 st.write(f"Número do ticket: {reserva[2]}")
#                 st.write('---')
#                 novo_num_bus = st.text_input("Novo número do ônibus", value=reserva[1].strip().split(': ')[1])
#                 file.write(f'Nome do passageiro: {reserva[0]}\n')
#                 file.write(f'Número do ônibus selecionado: {novo_num_bus}\n')
#                 file.write(f'Número do ticket: {reserva[2]}')
#                 file.write('\n')
#             st.write("Reserva atualizada com sucesso.")