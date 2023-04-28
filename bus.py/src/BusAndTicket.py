class onibus:
    def __init__(self, numero, vagas, origem, destino):
        self.numero = numero #Atributo que guarda o número do ônibus
        self.vagas = vagas #Atributo que guarda a quantidade de vagas disponíveis no ônibus
        self.origem = origem #Atributo que guarda a cidade de origem do ônibus
        self.destino = destino #Atributo que guarda a cidade de destino do ônibus

    def get_numero(self): #Funções get para acessar os atributos da classe onibus
        return self.__numero
    
    def set_numero(self, numero): #Funções set para atualizar os atributos da classe onibus
        self.numero = numero

    def get_vagas(self):
        return self.vagas

    def set_vagas(self, vagas):
        self.vagas = vagas

    def get_origem(self):
        return self.origem
    
    def set_origem(self, origem):
        self.origem = origem

    def get_destino(self):
        return self.destino
    
    def set_destino(self, destino):
        self.destino = destino

class tickets:
    def __init__(self, nome, origem, destino, num_bus):
        self.nome = nome #Atributo que guarda o nome do passageiro que comprou o bilhete
        self.origem = origem #Atributo que guarda a cidade de origem do passageiro
        self.destino = destino #Atributo que guarda a cidade de destino do passageiro
        self.num_bus = num_bus #Atributo que guarda o objeto do tipo ônibus associado a esse bilhete

    def get_nome(self): #Funções get para acessar os atributos da classe tickets
        return self.__nome
    
    def set_nome(self, nome): #Funções set para atualizar os atributos da classe tickets
        self.nome = nome
    
    def get_origem(self):
        return self.__origem
    
    def set_origem(self, origem):
        self.origem = origem

    def get_destino(self):
        return self.__destino

    def set_destino(self, destino):
        self.destino = destino

    def get_num_bus(self):
        return self.__num_bus

    def set_num_bus(self, num_bus):
        self.num_bus = num_bus 