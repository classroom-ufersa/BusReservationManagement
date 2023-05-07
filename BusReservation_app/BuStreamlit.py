import streamlit as st
import random as rd
import reservation as rst

# Definir o título da página
new_title = 'Bus Reservation Service'
icon_path = 'logo.ico'

# Configurar a página com o novo título e icone
st.set_page_config(page_title=new_title, page_icon=icon_path)

st.sidebar.title('Menu')
selecionar_pagina = st.sidebar.selectbox('Escolha a opção: ', ['Pagina inicial','Realizar reserva','Excluir reserva', 'Listar reserva', 'Buscar reserva', 'Editar reserva', 'Consultar vagas disponiveis', 'Consultar quantitativos de passageiros'])

if selecionar_pagina == 'Pagina inicial':
    st.title('Bem vindos ao seu app de reserva de ônibus')
    image = 'logo.png'
    # Centraliza a imagem usando uma caixa de layout
    col1, col2, col3 = st.columns([1, 6, 1])
    with col2:
        st.image(image, use_column_width=True)
        st.write('DESENVOLVEDORES: Caio Moisés Vieira Cavalcante, Heitor Claudino Dantas')
if selecionar_pagina == 'Realizar reserva':
    with st.form(key='Passageiro'):
        num_ticket = rd.randint(10000, 99999)
        opcoes_onibus = ['Ônibus 1 - Alexandria-RN -> Natal-RN',
                              'Ônibus 2 - Pau dos Ferros-RN -> Fortaleza-CE', 
                              'Ônibus 3 - Alexandria-RN -> Salvador-Bh']

        input_name = st.text_input(label='Nome do passageiro')
        input_numBus = st.selectbox('Número do ônibus e destino', opcoes_onibus)
        input_enviar = st.form_submit_button('Enviar')
    if input_enviar:
        st.write('Bilhete cadastrado com sucesso!')
        st.write('Nome do passageiro:', input_name.title())
        st.write('Número do ônibus selecionado:', input_numBus)
        st.write('Número do ticket:', num_ticket)
            
        rst.realizar_reserva(input_name.title(), input_numBus, num_ticket)
if selecionar_pagina == 'Excluir reserva':
    with st.form(key='Passageiro'):
        input_name = st.text_input(label='Nome do passageiro que deseja excluir o bilhete: ')
        input_excluir = st.form_submit_button('Excluir')

    if input_excluir:
        rst.excluir_reserva(input_name.title())
if selecionar_pagina == 'Listar reserva':
    rst.listar_reservas()
     