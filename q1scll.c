/*A program to create a driven program for single circular linked list and then traverse it*/
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next;
};
struct node *newstart;
void createlist(struct node*);
void traverse(struct node*);
void insert_beg(struct node*);
void insert_end(struct node*);
void insert_loc(struct node*);
int count(struct node*);
void delete_beg(struct node*);
void delete_end(struct node*);
void delete_loc(struct node*);
int main()
{
	struct node *start;
	int choice=1;
	start=(struct node*)malloc(sizeof(struct node));
	if(start==NULL)
	{
		printf("\nOut of Memory");
		exit(0);
	}
	createlist(start);
	while(choice!=8)
	{
		printf("\nMenu\n1.Traverse\n2.insert_beg\n3.insert_end\n4.insert_loc\n5.delete_beg\n6.delete_end\n7.delete_loc\n8.Quit\nEnter your choice:");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:traverse(start);
			       break;
			case 2:insert_beg(start);
			       start=newstart;
			       break;
			case 3:insert_end(start);
			       break;
			case 4:newstart=start;
			       insert_loc(start);
			       start=newstart;
			       break;
			case 5:delete_beg(start);
			       start=newstart;
			       break;
			case 6:newstart=start;
                               delete_end(start);
	                       start=newstart;
			       break;
			case 7:newstart=start;
			       delete_loc(start);
			       start=newstart;
			       break;
			case 8:break;
			default:printf("Invalid Choice!");
		}
	}
	return 0;
}
void createlist(struct node *link)
{
	struct node *mlink,*cur;
	int i=1;
	char ch;
	mlink=link;
	printf("\nEnter element for node %d:",i);
	scanf("%d", &link->info);
	link->next=mlink;
	i++;
	printf("\n Do you want to add more(y/n)?:");
	scanf(" %c", &ch);
	while(ch!='n')
	{
		cur=(struct node*)malloc(sizeof(struct node));
		if(cur==NULL)
		{
			printf("\nOut of memory");
			return;
		}
		link->next=cur;
		link=link->next;
		printf("\nEnter element for node %d:",i);
		scanf("%d", &link->info);
		link->next=mlink;
		i++;
		printf("\nDo you want to add more(y/n)?");
		scanf(" %c", &ch);
	}
}
void traverse(struct node *link)
{
	struct node *mlink;
	mlink=link;
	printf("\nThe elements are:");
	do
	{
		printf("%d\t",link->info);
		link=link->next;
	}while(link!=mlink);
}
void insert_beg(struct node *link)
{
	struct node *mlink,*cur;
	mlink=link;
	cur=(struct node*)malloc(sizeof(struct node));
	if(cur==NULL)
	{
		printf("\nOut of memory!");
		return;
	}
	printf("\nEnter element:");
	scanf("%d", &cur->info);
	cur->next=link;
	while(link->next!=mlink)
		link=link->next;
	link->next=cur;
	newstart=cur;
}
void insert_end(struct node *link)
{
	struct node *mlink,*temp;
	mlink=link;
	temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("\nOut of memory!");
		return;
	}
	printf("\nenter element");
	scanf("%d", &temp->info);
	while(link->next!=mlink)
		link=link->next;
	link->next=temp;
	temp->next=mlink;
}
int count(struct node *link)
{
	int i=1;
	struct node *mlink;
	mlink=link;
	while(link->next!=mlink)
	{
		i++;
		link=link->next;
	}
	return i;
}
void insert_loc(struct node *link)
{
	struct node *mlink,*cur,*temp;
	int loc,c,i=1;
	mlink=link;
	printf("\nEnter location:");
	scanf("%d", &loc);
	c=count(link);
	if(loc>c)
	{
		printf("\nInvalid location!");
		return;
	}
	cur=(struct node*)malloc(sizeof(struct node));
	if(cur==NULL)
	{
		printf("\nOut of memory!");
		return;
	}
	printf("\nEnter element:");
	scanf("%d", &cur->info);
	if(loc==1)
	{
		cur->next=link;
		newstart=cur;
		while(link->next!=mlink)
			link=link->next;
		link->next=cur;
		return;
	}
	while(i<loc)
	{
		temp=link;
		link=link->next;
		i++;
	}
	temp->next=cur;
	cur->next=link;
}
void delete_beg(struct node *link)
{
	struct node *mlink;
	mlink=link;
	if(link->next==mlink)
	{
		newstart=NULL;
		free(link);
		return;
	}
	newstart=link->next;
	while(link->next!=mlink)
		link=link->next;
	link->next=newstart;
	free(mlink);
}
void delete_end(struct node *link)
{
	struct node *mlink,*temp;
	mlink=link;
	if(link->next==mlink)
	{
		newstart=NULL;
		free(link);
		return;
	}
	while(link->next!=mlink)
	{
		temp=link;
		link=link->next;
	}
	temp->next=mlink;
	free(link);
}
void delete_loc(struct node *link)
{
	struct node *mlink,*temp;
	int loc,c,i=1;
	mlink=link;
	printf("\nEnter location:");
	scanf("%d", &loc);
	c=count(link);
	if(loc>c)
	{
		printf("\nInvalid location!");
		return;
	}
	if(loc==1)
	{
		if(link->next==mlink)
		{
			newstart=NULL;
			free(link);
			return;
		}
		newstart=link->next;
		while(link->next!=mlink)
			link=link->next;
		link->next=newstart;
		free(mlink);
		return;
	}
	while(i<loc)
	{
		temp=link;
		link=link->next;
		i++;
	}
	temp->next=link->next;
	free(link);
}
