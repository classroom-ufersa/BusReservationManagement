typedef struct bus Bus;

Bus *startBus();
Bus *registerBus(Bus *b, int number, int vacancies, char *origin, char *destination);
void showBus(Bus *b);
void showAvaliableVacancies(Bus *b, int num);
void showPassengerQuantity(Bus *b, int vacancies, int num);
void freeBus(Bus *b);