class Onibus():
    def __init__(self, numero, vagas, origem, destino):
        self.numero = numero #Atributo que guarda o número do ônibus
        self.vagas = vagas #Atributo que guarda a quantidade de vagas disponíveis no ônibus
        self.origem = origem #Atributo que guarda a cidade de origem do ônibus
        self.destino = destino #Atributo que guarda a cidade de destino do ônibus

    @property
    def get_numero(self): #Funções get para acessar os atributos da classe onibus
        return self.__numero
    
    def set_numero(self, numero): #Funções set para atualizar os atributos da classe onibus
        self.numero = numero

    @property
    def get_vagas(self):
        return self.vagas
    
    def set_vagas(self, vagas):
        self.vagas = vagas

    @property
    def get_origem(self):
        return self.origem
    
    def set_origem(self, origem):
        self.origem = origem

    @property
    def get_destino(self):
        return self.destino
    
    def set_destino(self, destino):
        self.destino = destino