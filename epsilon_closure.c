#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{

    int st;
    struct node *link;

};

struct node *transition[20][1]={NULL};
char closure[100]="";
int nostates;
static int pr;
void insert(int,int);
void findclosure(int);
void display();
void str_append(int);

int main(){

    int i,s1,s2;
    char alpha;
    int notrans;
    printf("\n enter no of states\n");
    scanf("%d%*c",&nostates);

    printf("\n enter no of transitions archs\n");
    scanf("%d%*c",&notrans);

    printf("\n enter transitions eg: 1 alpha 2 \n");
    printf("\n note : epsilon is the letter e only use single letter transitions \n");


    for(i=1;i<=notrans;i++){

        scanf("%d %c %d",&s1,&alpha,&s2);
        if(alpha=='e')
            insert(s1,s2);

    }
    display();
    printf("\nepisilon transitions\n");

    for(i=1;i<=nostates;i++){

        pr=i;
        printf("\n q%d:{",i);
        findclosure(i);
        printf("%s",closure);
        printf("}");
        strcpy(closure,"");
    }


}

void insert(int s1,int s2){

    struct node *temp=(struct node*)malloc(sizeof(struct node)); 
    struct node *temp2;

    temp->st=s2;
    temp->link=NULL;

    if(transition[s1][0]==NULL){

        transition[s1][0]=temp;

    }
    else{
        temp2=transition[s1][0];
        while(temp2->link!=NULL){
            temp2=temp2->link;
        }
        temp2->link=temp;
    }
}

void findclosure(int i){

    struct node *temp,*pre;

    str_append(i);
    temp=transition[i][0];
    pre=temp;
    while(temp!=NULL){

        if(pr==temp->st){
            return ;
        }
        findclosure(temp->st);
        pre=temp;
        temp=temp->link;

    }
    return ;
}
void str_append(int i){

    int str_len;
    str_len=strlen(closure);
    closure[str_len]=i+'0';
    closure[str_len+1]=',';
    closure[str_len+2]='\0';

}
void display(){
    int i;
    struct node *temp;
    for(i=1;i<=nostates;i++){

        temp=transition[i][0];
        printf("\n%d:",i);
        while(temp!=NULL){
            printf("%d",temp->st);
            temp=temp->link;
        }
        printf("\n");

    }
}
  