#include<stdio.h>
#include<stdlib.h>

struct node{
	int st;
	struct node *link;
};
struct node *head=NULL,*ran,*temp2,*slow,*fast;

void inrand(){
	int i;
	ran=head;
	for(i=0;i<3;i++){
		ran=ran->link;
	}
	temp2->link=ran;

}

void insert(int i){

	struct node *temp=(struct node*)malloc(sizeof(struct node));

	temp->st=i;
	temp->link=NULL;

	if(head==NULL){
		head=temp;
	}
	else{
		temp2=head;
		while(temp2->link != NULL){
			temp2=temp2->link;
		}
		temp2->link=temp;
		temp2=temp;
	}

}

void display(){
	struct node *temp;
	temp=head;
	printf("\n");
	while(temp!=NULL){
		printf("%d --->",temp->st);
		temp=temp->link;
	}
	printf("\n");
}

void removelp(){
	struct node *pre;
	slow=head;
	while(1){
		pre=fast;
		slow=slow->link;
		fast=fast->link;

		if(slow==fast){
			printf("\n starting of loop ---> %d\n",slow->st);
			printf("\n del node --->%d\n",pre->st);
			pre->link=NULL;
			break;
		}
	}

}

void findlpstart(){

	slow=head;
	fast=head;

	while(1){
		fast=fast->link;
		fast=fast->link;
		slow=slow->link;

		if(slow==fast){
			printf("\n loop detected\n");
			printf("\n meeting point --> %d\n",fast->st);
			removelp();
			break;
		}
	}
}


int main(){
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	insert(6);
	insert(7);
	insert(8);
	inrand();
	findlpstart();
	display();
	return 0;
}