#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "budget.h"

int main(void){
    Budget *sp[100];
    int count = 0;
    int menu;
    int result=0;
    int index=0;
    int ip=1;

    char file[20];

    while (1){
        menu = selectMenu();
        if (menu == 0)break;
        else if (menu == 1){
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
        }else if(menu == 8){
            if(count > 0){
                printf("=> ������ ������ �̸� : ");
                scanf("%s", file);
                saveData(sp, file, count);
                printf("\n=> '%s' ���Ͽ� �����͸� �����߽��ϴ�.\n", file);
            }
        }else if(menu == 9){
            printf("=> �ҷ��� ������ �̸� : ");
            scanf("%s", file);
            for(int i = 0; i < count; i++){
                free(sp[i]);
                sp[i] = NULL;
            }
            count = loadData(sp, file);
            index = count;
            if(count > 0){
                printf("\n=> '%s' ���Ͽ��� �����͸� �ҷ��Խ��ϴ�.\n", file);
            }
        }
    }
    printf("�����!\n");
    return 0;
}