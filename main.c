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
            else printf("데이터가없습니다.\n");
        }
        else if (menu == 2){
            sp[index] = (Budget *)malloc(sizeof(Budget));       
            count += addBudget(sp[index++]);
            printf("=> 추가됨!\n");
        }
        else if (menu == 3){
            int no = selectDataNo(sp, index);
            if(no == 0){     
                printf("=> 취소됨!\n");
                continue; 
            } 
            updateBudget(sp[no-1]);
        }
        else if (menu == 4){
            int no = selectDataNo(sp, index);
            if(no == 0){  
                printf("=> 취소됨!\n"); 
            }
            int deleteok;
            printf("정말로삭제하시겠습니까?(삭제 :1)");
            scanf("%d", &deleteok);
            if(deleteok == 1){
                if(sp[no-1]) free(sp[no-1]);   
                sp[no-1] = NULL;   
                count--;
            }
            printf("삭제됨!\n");
        }else if(menu == 6){
            int search;
            printf("검색할 종류?\n");
            printf("1. 이름 2. 날짜 3. 종류\n");
            scanf("%d", &search);
            if(search == 1 || search == 3){
                char name[20];
                printf("검색할 내용? ");
                scanf("%s", name);
                if(search == 1) searchByName(sp, index, name);
                else if(search == 3) searchByCat(sp, index, name);
            }else if (search == 2){
                int date1, date2;
                printf("검색할 날짜는? ");
                scanf("%d %d", &date1, &date2);
                searchByDate(sp, index, date1, date2);
            }
        }else if(menu == 7){
            if(count > 0){
                printf("=> 저장할 파일의 이름 : ");
                scanf("%s", file);
                saveData(sp, file, count);
                printf("\n=> '%s' 파일에 데이터를 저장했습니다.\n", file);
            }
        }else if(menu == 8){
            printf("=> 불러올 파일의 이름 : ");
            scanf("%s", file);
            for(int i = 0; i < count; i++){
                free(sp[i]);
                sp[i] = NULL;
            }
            count = loadData(sp, file);
            index = count;
            if(count > 0){
                printf("\n=> '%s' 파일에서 데이터를 불러왔습니다.\n", file);
            }
        }
    }
    printf("종료됨!\n");
    return 0;
}