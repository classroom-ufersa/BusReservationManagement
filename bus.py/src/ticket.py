class Tickets():
    def __init__(self, nome,  num_bus):
        self.nome = nome #Atributo que guarda o nome do passageiro que comprou o bilhete
        self.num_bus = num_bus #Atributo que guarda o objeto do tipo ônibus associado a esse bilhete

    def get_nome(self): #Funções get para acessar os atributos da classe tickets
        return self.__nome
    
    def set_nome(self, nome): #Funções set para atualizar os atributos da classe tickets
        self.nome = nome

    def get_num_bus(self):
        return self.__num_bus

    def set_num_bus(self, num_bus):
        self.num_bus = num_bus 
    
    _nome = property(fget=get_nome,fset=set_nome)
    _num_bus = property(fget=get_num_bus,fset=set_num_bus)