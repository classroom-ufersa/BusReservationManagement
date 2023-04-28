typedef struct bus Bus;

Bus *startBus();
Bus *registerBus(Bus *b, int number, int vacancies, char *origin, char *destination);
void showAvaliableBus(Bus *b);