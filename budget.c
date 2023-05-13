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
    //int sum=s.kor+s.eng+s.math;
    //double avg=sum/3.0;

    printf("%3s | %4d | %3d | %4s | %4s\n",s.name, s.price, s.date, s.type, s.category);
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

int selectMenu(){
    int menu;
    printf("\n*** ����� ***\n");
    printf("1. ��ȸ ");
    printf("2. �߰� ");
    printf("3. ���� ");
    printf("4. ���� ");
    printf("0. ���� >> ");
    scanf("%d", &menu);
    return menu;
}

int main(void){
    Budget *sp[100];
    int count = 0;
    int menu;
    int result=0;
    int index=0;
    int ip=1;

    while (1){
        menu = selectMenu();
        if (menu == 0){
            printf("\n=> ���ϴ� �޴���? ");
            scanf("%d",&ip);
            if(ip==0){
                break;
            } 
            else continue;
        } 
        if (menu == 1){
            if(count > 0) listBudget(sp, index);
            else printf("�����Ͱ������ϴ�.\n");
        }
        else if (menu == 2){
            sp[index] = (Budget *)malloc(sizeof(Budget));       
            count += addBudget(sp[index++]);
            printf("=> �߰���!\n");
        }
        else if (menu == 3){
            int no = selectDataNo(sp, index);
            if(no == 0){     
                printf("=> ��ҵ�!\n");
                continue; 
            } 
            updateBudget(sp[no-1]);
        }
        else if (menu == 4){
            int no = selectDataNo(sp, index);
            if(no == 0){  
                printf("=> ��ҵ�!\n"); 
            }
            int deleteok;
            printf("�����λ����Ͻðڽ��ϱ�?(���� :1)");
            scanf("%d", &deleteok);
            if(deleteok == 1){
                if(sp[no-1]) free(sp[no-1]);   
                sp[no-1] = NULL;   
                count--;
            }
            printf("������!\n");
        }
    }
    printf("�����!\n");
    return 0;
}