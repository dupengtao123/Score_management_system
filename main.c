//
//  main.c
//  C_program
//
//  Created by 杜朋涛 on 20/06/2017.
//  Copyright © 2017 杜朋涛. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30
typedef struct student{
    long ID;
    char name[20];
    int score[6];
    double aver;
    int sum;
}STU;
void course_score(STU stu[],int cou_num,int stu_num);
void student_score(STU stu[],int cou_num,int stu_num);
void descending(STU stu[],int cou_num,int stu_num);
void ascending(STU stu[],int cou_num,int stu_num);
void ID_ascending(STU stu[],int cou_num,int stu_num);
void name_dictionary(STU stu[],int cou_num,int stu_num);
void ID_search(STU stu[],int cou_num,int stu_num);
void name_search(STU stu[],int cou_num,int stu_num);
void course_analyses(STU stu[],int cou_num,int stu_num);
void printout(STU stu[],int cou_num,int stu_num);
void print(STU stu[],int cou_num,int stu_num);
int isscoem();
int main(){
    STU stu[N];
    int flag_input=0,flag_score1=0,flag_score2=0;
    int a,stu_num,cou_num;
    while(1){
        printf("\n");
        printf("1.Input record\n");
        printf("2.Caculate total and average score of every course\n");
        printf("3.Caculate total and average score of every student\n");
        printf("4.Sort in descending order by total score of every student\n");
        printf("5.Sort in ascending order by total score of every student\n");
        printf("6.Sort in ascending order by number\n");
        printf("7.Sort in dictionary order by name\n");
        printf("8.Search by number\n");
        printf("9.Search by name\n");
        printf("10.Statistic analysis for every course\n");
        printf("11.List record\n");
        printf("0.Exit\n");
        printf("\n");
        printf("Please enter your choice:\n");
        scanf("%d",&a);
        switch(a){
            case 1:
                printf("Please enter the number of students\n");
                scanf("%d",&stu_num);
                while(1){
                    if(stu_num<0||stu_num>30){
                        printf("error!(0<stu_num<=30) please re-enter\n");
                        scanf("%d",&stu_num);
                    }else{
                        break;
                    }
                }
                printf("Please enter the number of course\n");
                scanf("%d",&cou_num);
                while(1){
                    if(cou_num<0||cou_num>6){
                        printf("error!(0<cou_num<=6) please re-enter\n");
                        scanf("%d",&cou_num);
                    }else{
                        break;
                    }
                }
                int i,j;
                for(i=0;i<stu_num;i++){
                    printf("Please enter the ID of the NO.%d student\n",i+1);
                    scanf("%ld",&stu[i].ID);
                    printf("Please enter the name of the NO.%d student\n",i+1);
                    scanf("%s",&stu[i].name);
                    for(j=0;j<cou_num;j++){
                        printf("Please enter the NO.%d score of the %s\n",j+1,stu[i].name);
                        scanf("%d",&stu[i].score[j]);
                    }
                }
                flag_input=1;
                break;
            case 2:
                if(flag_input==1||isscoem()==1){
                    course_score(stu,cou_num,stu_num);
                    flag_score1=1;
                }else{
                    printf("because of empty file,please input 1 firstly\n");
                }
                break;
            case 3:
                if(flag_input==1||isscoem()==1){
                    student_score(stu,cou_num,stu_num);
                    flag_score2=1;
                }else{
                    printf("because of empty file,please input 1 firstly\n");
                }
                break;
            case 4:
                if(flag_score2==1||isscoem()==1){
                    descending(stu,cou_num,stu_num);
                    print(stu,cou_num,stu_num);
                }else{
                    printf("please input 3 before 4\n");
                }
                break;
            case 5:
                if(flag_score2==1||isscoem()==1){
                    ascending(stu,cou_num,stu_num);
                    print(stu,cou_num,stu_num);
                }else{
                    printf("please input 3 before 5\n");
                }
                break;
            case 6:
                if(flag_score2==1||isscoem()==1){
                    ID_ascending(stu,cou_num,stu_num);
                    print(stu,cou_num,stu_num);
                }else{
                    printf("please input 3 before 6\n");
                }
                break;
            case 7:
                if(flag_score2==1||isscoem()==1){
                    name_dictionary(stu,cou_num,stu_num);
                    print(stu,cou_num,stu_num);
                }else{
                    printf("please input 3 before 7\n");
                }
                break;
            case 8:
                if(flag_score2==1||isscoem()==1){
                    ID_search(stu,cou_num,stu_num);
                }else{
                    printf("please input 3 before 8\n");
                }
                break;
            case 9:
                if(flag_score2==1||isscoem()==1){
                    name_search(stu,cou_num,stu_num);
                }else{
                    printf("please input 3 before 9\n");
                }
                break;
            case 10:
                if(flag_input==1&&flag_score1==1||isscoem()==1){
                    course_analyses(stu,cou_num,stu_num);
                }else{
                    printf("pleaes input 1 and 2 befose that\n");
                }
                break;
            case 11:
                if(flag_score2==1&&flag_score1==1||isscoem()==1){
                    printout(stu,cou_num,stu_num);
                    course_score(stu,cou_num,stu_num);
                }else{
                    printf("pleaes input 1,2,3 befose that\n");
                }
                break;
            case 0:
                printf("system over!");
                exit(0);
            default:
                printf("error\n");
        }
    }
}
void course_score(STU stu[],int cou_num,int stu_num){
    int i,j,sum=0;
    for(i=0;i<cou_num;i++){
        sum=0;
        for(j=0;j<stu_num;j++){
            sum=sum+stu[j].score[i];
        }
        printf("The sum of the NO.%d course is %d\n",i+1,sum);
        printf("The average of the NO.%d course is %4.1f\n",i+1,(double)sum/stu_num);
    }
}
void student_score(STU stu[],int cou_num,int stu_num){
    int i,j;
    for(i=0;i<stu_num;i++){
        stu[i].sum=0;
        for(j=0;j<cou_num;j++){
            stu[i].sum=stu[i].sum+stu[i].score[j];
        }
        printf("The sum of the %s is %d\n",stu[i].name,stu[i].sum);
        stu[i].aver=(double)stu[i].sum/cou_num;
        printf("The average of the %s is %4.1f\n",stu[i].name,stu[i].aver);
    }
}
void descending(STU stu[],int cou_num,int stu_num){
    int i,j,k,temp_score;
    long temp_ID;
    char temp_name[20];
    for(i=0;i<stu_num-1;i++){
        for(j=i+1;j<stu_num;j++){
            if(stu[j].sum>stu[i].sum){
                for(k=0;k<cou_num;k++){
                    temp_score=stu[i].score[k];
                    stu[i].score[k]=stu[j].score[k];
                    stu[j].score[k]=temp_score;
                }
                temp_score=stu[i].aver;
                stu[i].aver=stu[j].aver;
                stu[j].aver=temp_score;
                temp_ID=stu[i].ID;
                stu[i].ID=stu[j].ID;
                stu[j].ID=temp_ID;
                temp_score=stu[i].sum;
                stu[i].sum=stu[j].sum;
                stu[j].sum=temp_score;
                strcpy(temp_name,stu[i].name);
                strcpy(stu[i].name,stu[j].name);
                strcpy(stu[j].name,temp_name);
            }
        }
    }
}
void ascending(STU stu[],int cou_num,int stu_num){
    int i,j,k,temp_score;
    long temp_ID;
    char temp_name[20];
    for(i=0;i<stu_num-1;i++){
        for(j=i+1;j<stu_num;j++){
            if(stu[j].sum<stu[i].sum){
                for(k=0;k<cou_num;k++){
                    temp_score=stu[i].score[k];
                    stu[i].score[k]=stu[j].score[k];
                    stu[j].score[k]=temp_score;
                }
                temp_score=stu[i].aver;
                stu[i].aver=stu[j].aver;
                stu[j].aver=temp_score;
                temp_ID=stu[i].ID;
                stu[i].ID=stu[j].ID;
                stu[j].ID=temp_ID;
                temp_score=stu[i].sum;
                stu[i].sum=stu[j].sum;
                stu[j].sum=temp_score;
                strcpy(temp_name,stu[i].name);
                strcpy(stu[i].name,stu[j].name);
                strcpy(stu[j].name,temp_name);
            }
        }
    }
}
void ID_ascending(STU stu[],int cou_num,int stu_num){
    int i,j,k,temp_score;
    long temp_ID;
    char temp_name[20];
    for(i=0;i<stu_num-1;i++){
        for(j=i+1;j<stu_num;j++){
            if(stu[i].ID>stu[j].ID){
                for(k=0;k<cou_num;k++){
                    temp_score=stu[i].score[k];
                    stu[i].score[k]=stu[j].score[k];
                    stu[j].score[k]=temp_score;
                }
                temp_score=stu[i].aver;
                stu[i].aver=stu[j].aver;
                stu[j].aver=temp_score;
                temp_ID=stu[i].ID;
                stu[i].ID=stu[j].ID;
                stu[j].ID=temp_ID;
                temp_score=stu[i].sum;
                stu[i].sum=stu[j].sum;
                stu[j].sum=temp_score;
                strcpy(temp_name,stu[i].name);
                strcpy(stu[i].name,stu[j].name);
                strcpy(stu[j].name,temp_name);
            }
        }
    }
}
void name_dictionary(STU stu[],int cou_num,int stu_num){
    int i,j,k,temp_score;
    long temp_ID;
    char temp_name[20];
    for(i=0;i<stu_num-1;i++){
        for(j=i+1;j<stu_num;j++){
            if(strcmp(stu[j].name,stu[i].name)<0){
                for(k=0;k<cou_num;k++){
                    temp_score=stu[i].score[k];
                    stu[i].score[k]=stu[j].score[k];
                    stu[j].score[k]=temp_score;
                }
                temp_score=stu[i].aver;
                stu[i].aver=stu[j].aver;
                stu[j].aver=temp_score;
                temp_ID=stu[i].ID;
                stu[i].ID=stu[j].ID;
                stu[j].ID=temp_ID;
                temp_score=stu[i].sum;
                stu[i].sum=stu[j].sum;
                stu[j].sum=temp_score;
                strcpy(temp_name,stu[i].name);
                strcpy(stu[i].name,stu[j].name);
                strcpy(stu[j].name,temp_name);
            }
        }
    }
    
}
void print(STU stu[],int cou_num,int stu_num){
    int i,num=1;
    for(i=0;i<stu_num;i++){
        printf("%d. %s %d\n",num,stu[i].name,stu[i].sum);
        num++;
    }
}
void ID_search(STU stu[],int cou_num,int stu_num){
    int a,i,num=1,flag=0;
    descending(stu,cou_num,stu_num);
    printf("Please input the ID\n");
    scanf("%d",&a);
    while(1){
        for(i=0;i<stu_num;i++){
            if(a==stu[i].ID){
                flag=1;
            }
        }
        if(flag==1){
            for(i=0;i<stu_num;i++){
                if(a==stu[i].ID){
                    break;
                }
                num++;
            }
            break;
        }else{
            printf("not found,please re-enter\n");
            scanf("%d",&a);
        }
    }
    printf("%d. %s %d\n",num,stu[i].name,stu[i].sum);
}
void name_search(STU stu[],int cou_num,int stu_num){
    char a[20];
    int i,num=1,flag=0;
    descending(stu,cou_num,stu_num);
    printf("Please input the name\n");
    scanf("%s",a);
    while(1){
        for(i=0;i<stu_num;i++){
            if(strcmp(a,stu[i].name)==0){
                flag=1;
            }
        }
        if(flag==1){
            for(i=0;i<stu_num;i++){
                if(strcmp(a,stu[i].name)==0){
                    break;
                }
                num++;
            }
            break;
        }else{
            printf("not found,please re-enter\n");
            scanf("%s",&a);
        }
    }
    printf("%d. %s %d\n",num,stu[i].name,stu[i].sum);
}
void course_analyses(STU stu[],int cou_num,int stu_num){
    int i,j;
    for(i=0;i<cou_num;i++){
        int yx=0,lh=0,zd=0,jg=0,bjg=0,sum=0;
        for(j=0;j<stu_num;j++){
            if(stu[j].score[i]>=90&&stu[j].score[i]<=100){
                yx++;
            }else if(stu[j].score[i]>=80&&stu[j].score[i]<=89){
                lh++;
            }else if(stu[j].score[i]>=70&&stu[j].score[i]<=79){
                zd++;
            }else if(stu[j].score[i]>=60&&stu[j].score[i]<=69){
                jg++;
            }else if(stu[j].score[i]>=0&&stu[j].score[i]<=59){
                bjg++;
            }
        }
        sum=yx+lh+zd+jg+bjg;
        printf("NO.%dcourse,youxiu:%2d,percent:%4.1f%%\n",i+1,yx,100*(float)yx/sum);
        printf("NO.%dcourse,lianghao:%2d,percent:%4.1f%%\n",i+1,lh,100*(float)lh/sum);
        printf("NO.%dcourse,zhongdeng:%2d,percent:%4.1f%%\n",i+1,zd,100*(float)zd/sum);
        printf("NO.%dcourse,jige:%2d,percent:%4.1f%%\n",i+1,jg,100*(float)jg/sum);
        printf("NO.%dcourse,bujige:%2d,percent:%4.1f%%\n",i+1,bjg,100*(float)bjg/sum);
        printf("\n");
    }
}
void printout(STU stu[],int cou_num,int stu_num){
    int i,j;
    descending(stu,cou_num,stu_num);
    for(i=0;i<stu_num;i++){
        printf("%d %s ",stu[i].ID,stu[i].name);
        for(j=0;j<cou_num;j++){
            printf("%d ",stu[i].score[j]);
        }
        printf("\n");
    }
}
int isscoem(){
    FILE *fp;
    if((fp=fopen("score.txt","r"))==NULL){
        printf("fail to open file\n");
        exit(0);
    }
    int ch;
    ch=fgetc(fp);
    if(ch==EOF){
        return 0;
    }else{
        return 1;
    }
}
