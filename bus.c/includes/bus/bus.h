typedef struct bus Bus;

//inicia a lista de onibus
Bus *startBus();

//Função para registrar o onibus
Bus *registerBus(Bus *b, int number, int vacancies, char *origin, char *destination);

//Função para mostrar onibus
void showBus(Bus *b);

//Função para mostrar as vagas dos onibus
void showAvaliableVacancies(Bus *b, int num);

//Função que mostrar a quantidade de passageiros cadastrados
void showPassengerQuantity(Bus *b, int vacancies, int num);

//Função para liberar o espaço que foi alocado na memoria
void freeBus(Bus *b);