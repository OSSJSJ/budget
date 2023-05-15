#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "budget.h"

int addBudget(Budget *s){
    printf("이름은? "); 
    scanf("%*c");
    fgets(s->name, sizeof(s->name), stdin);
    s->name[strcspn(s->name, "\n")] = '\0';

    printf("가격은? "); 
    scanf("%d", &s->price); 

    printf("날짜는? "); 
    scanf("%d", &s->date); 

    printf("타입은?(지출 or 수입) "); 
    scanf("%s", s->type);

    printf("카테고리는? "); 
    scanf("%*c");
    fgets(s->category, sizeof(s->category), stdin);
    s->category[strcspn(s->category, "\n")] = '\0';
    return 1;
}

void readBudget(Budget s){
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
    printf("이름은? "); 
    scanf("%*c");
    fgets(s->name, sizeof(s->name), stdin);
    s->name[strcspn(s->name, "\n")] = '\0';
    
    printf("가격은? "); 
    scanf("%d", &s->price); 

    printf("날짜는? "); 
    scanf("%d", &s->date); 

    printf("타입은?(지출 or 수입) "); 
    scanf("%s", s->type);

    printf("카테고리는? "); 
    scanf("%*c");
    fgets(s->category, sizeof(s->category), stdin);
    s->category[strcspn(s->category, "\n")] = '\0';
    
    printf("=> 수정됨!\n");
    return 1;
}

int selectDataNo(Budget *s[], int count){
    int no;   
    listBudget(s, count);   
    printf("번호는 (취소 :0)? ");   
    scanf("%d", &no);
    return no;
}

int deleteBudget(Budget *s){
    s->date = -1; 
    return 1;
}

int selectMenu(){
    int menu;
    printf("\n*** 가계부 ***\n");
    printf("1. 조회 ");
    printf("2. 추가 ");
    printf("3. 수정 ");
    printf("4. 삭제 ");
    printf("8. 파일 저장 ");
    printf("9. 파일 불러오기 ");
    printf("0. 종료 >> ");
    scanf("%d", &menu);
    return menu;
}

void saveData(Budget *s[], char file[20], int count){
    FILE *fp;
    fp = fopen(file, "wt");
    if(count > 0){
        for(int i = 0; i < count; i++){
            fprintf(fp, "%d %s %d %s %s\n", s[i]->date, s[i]->name, s[i]->price, s[i]->category, s[i]->type);
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
            fscanf(fp, "%s", s[count]->name);
            fscanf(fp, "%d", &s[count]->price);
            fscanf(fp, "%s", s[count]->category);
            fscanf(fp, "%s", s[count]->type);
            count++;
        }
        fclose(fp);
    }
    if(count == 0) printf("\n=> '%s' 파일을 찾을수 없습니다\n", file);
    return count;
}