#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "budget.h"

int addBudget(Budget *s){
    printf("�̸���? "); 
    scanf("%*c");
    fgets(s->name, sizeof(s->name), stdin);
    s->name[strcspn(s->name, "\n")] = '\0';

    printf("������? "); 
    scanf("%d", &s->price); 

    printf("��¥��? "); 
    scanf("%d", &s->date); 

    printf("Ÿ����?(���� or ����) "); 
    scanf("%s", s->type);

    printf("ī�װ���? "); 
    scanf("%*c");
    fgets(s->category, sizeof(s->category), stdin);
    s->category[strcspn(s->category, "\n")] = '\0';
    return 1;
}

void readBudget(Budget s){
    printf("%3s | %3d | %3d | %4s | %4s\n",s.name, s.price, s.date, s.type, s.category);
}

void listBudget(Budget *s[], int count){  
    printf("\nNo Name Price Date Type Category\n");  
    printf("==================================\n");
    for(int i =0; i <count ; i++){
        if(s[i] == NULL) continue;     
        printf("%2d ", i+1);     
        readBudget(*s[i]);  }  
        printf("\n");
}

int updateBudget(Budget *s){
    printf("�̸���? "); 
    scanf("%*c");
    fgets(s->name, sizeof(s->name), stdin);
    s->name[strcspn(s->name, "\n")] = '\0';
    
    printf("������? "); 
    scanf("%d", &s->price); 

    printf("��¥��? "); 
    scanf("%d", &s->date); 

    printf("Ÿ����?(���� or ����) "); 
    scanf("%s", s->type);

    printf("ī�װ���? "); 
    scanf("%*c");
    fgets(s->category, sizeof(s->category), stdin);
    s->category[strcspn(s->category, "\n")] = '\0';
    
    printf("=> ������!\n");
    return 1;
}

int selectDataNo(Budget *s[], int count){
    int no;   
    listBudget(s, count);   
    printf("��ȣ�� (��� :0)? ");   
    scanf("%d", &no);
    return no;
}

int deleteBudget(Budget *s){
    s->date = -1; 
    return 1;
}

void saveData(Budget *s[], char file[20], int count){
    FILE *fp;
    fp = fopen(file, "wt");
    if(count > 0){
        for(int i = 0; i < count; i++){
            fprintf(fp, "%d %d %s %s %s\n", s[i]->date, s[i]->price, s[i]->category, s[i]->type, s[i]->name);
        }
    }
    fclose(fp);
}
int loadData(Budget *s[], char file[20]){
    FILE *fp;
    int count = 0;
    if(fp = fopen(file, "rt")){
        while(!feof(fp)){
            s[count] = (Budget*)malloc(sizeof(Budget));
            fscanf(fp, "%d", &s[count]->date);
            if(feof(fp)){
                free(s[count]);
                break;
            }
            fscanf(fp, "%d", &s[count]->price);
            fscanf(fp, "%s", s[count]->category);
            fscanf(fp, "%s", s[count]->type);
            fscanf(fp, "%[^\n]", s[count]->name);
            count++;
        }
        fclose(fp);
    }
    if(count == 0) printf("\n=> '%s' ������ ã���� �����ϴ�\n", file);
    return count;
}

void calculate(Budget *s[], int count){
    int receipt = 0; //����
    int expenditure = 0; //����
    for(int i=0; i<count; i++){
        if(s[i] == NULL) continue;
        if(strstr(s[i]->type, "����")){
            receipt+=s[i]->price;
        }
        else if(strstr(s[i]->type, "����")){
            expenditure+=s[i]->price;
        }
    }
    printf("�� ����: %d, �� ���� : %d\n",receipt, expenditure);
}

int selectMenu(){
    int menu;
    printf("\n*** ����� ***\n");
    printf("1. ��ȸ ");
    printf("2. �߰� ");
    printf("3. ���� ");
    printf("4. ���� ");
    printf("5. ���� ");
    printf("6. �˻� ");
    printf("7. ���� ���� ");
    printf("8. ���� �ҷ����� ");
    printf("0. ���� >> ");
    scanf("%d", &menu);
    return menu;
}


void searchByName(Budget *s[], int count, char name[20]){
    printf("\nNo Name Price Date Type Category\n");  
    printf("==================================\n");
    for(int i =0; i <count ; i++){
        if(s[i] == NULL) continue;     
        if(strstr(s[i]->name, name)){
            printf("%2d ", i+1);    
            readBudget(*s[i]);
        }
        printf("\n");
    }
}

void searchByDate(Budget *s[], int count, int date1, int date2){
    printf("\nNo Name Price Date Type Category\n");  
    printf("==================================\n");
    for(int i =0; i <count ; i++){
        if(s[i] == NULL) continue;     
        if(s[i]->date >= date1 && s[i]->date <= date2){
            printf("%2d ", i+1);    
            readBudget(*s[i]);
        }
        printf("\n");
    }
}

void searchByCat(Budget *s[], int count, char name[20]){
    printf("\nNo Name Price Date Type Category\n");  
    printf("==================================\n");
    for(int i =0; i <count ; i++){
        if(s[i] == NULL) continue;     
        if(strstr(s[i]->category, name)){
            printf("%2d ", i+1);    
            readBudget(*s[i]);
        }
        printf("\n");
    }
}