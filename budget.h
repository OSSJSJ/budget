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