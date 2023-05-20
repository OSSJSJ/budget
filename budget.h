typedef struct{
    char name[20];
    int price;
    int date;
    char type[10]; 
    char category[20]; 
} Budget;

int addBudget(Budget *s);
void readBudget(Budget s);
void listBudget(Budget *s[], int count);
int updateBudget(Budget *s);
int selectDataNo(Budget *s[], int count);
int deleteBudget(Budget *s);
int selectMenu();

void saveData(Budget *s[], char file[20], int count);
int loadData(Budget *s[], char file[20]);

void searchByName(Budget *s[], int count, char name[20]);
void searchByDate(Budget *s[], int count, int date1, int date2);
void searchByCat(Budget *s[], int count, char name[20]);