#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
	char data;
	struct node *lchild;
	struct node *rchild;
}*root=NULL,*treenode=NULL;

struct node* create(char data);
struct node* inorder(struct node *start);
struct node* leaves(struct node *start);
struct node* search(struct node *start, char key);
struct node* sibling(struct node *start,struct node *parent,char key);
void print_data(struct node *loc);
void child_gc(struct node *start,char key);
void search_gen(struct node *start, int count, int level);
int search_level(struct node *start, int count, char key);

void main()
{
	struct node *rc,*lc;
	char key;
	int l,tc;
	FILE *fp;
	fp = fopen("testcases.txt","r");
	/* File exception */
	if(fp==NULL)
	{
		printf("File open error\n");
		exit(1);
	}
	else
	{
		fscanf(fp,"%d",&tc);
		/* Test cases exception */
		if(isalpha(tc)||tc<=0)
		{
			printf("Testcases cannot be less than zero or cannot be a character\n");
			exit(1);
		}
		else
		{
			/* hard coding tree*/
			root = create('A');
			root->lchild = create('B');
			root->rchild = create('C');
			lc = root->lchild;
			rc = root->rchild;
			lc->lchild = create('D');
			lc->rchild = create('E');
			rc->rchild = create('F');
			lc = lc->rchild;
			rc = rc->rchild;
			lc->lchild = create('G');
			rc->rchild = create('H');
			lc = lc->lchild;
			rc = rc->rchild;
			lc->lchild = create('I');
			lc->rchild = create('J');
			rc->lchild = create('K');
			rc->rchild = create('L');
			lc = lc->lchild;
			rc = rc->rchild;
			lc->rchild = create('M');
			rc->rchild = create('N');
			printf("Inorder traversal is : \n");
			inorder(root);
			printf("\nLeaf nodes are\n");
			leaves(root);
			while(tc>0)
			{
				printf("\n******OUTPUT******\n");
				fscanf(fp," %c",&key);
				/* Input key exception*/
				if(isdigit(key))
				{
					printf("Key cannot be a number\n");
					exit(1);
				}
				else
				{
					/* Input character exception*/
					if(key!='A' && key!='B' && key!='C' && key!='D' && key!='E' && key!='F' && key!='G' && key!='H' && key!='I' && key!='J' && key!='K' && key!='L' && key!='M' && key!='N')
					{
						printf("Input character Exception\n");
						exit(1);
					}
					else
					{
						printf("\nLevel of %c is: ",key);
						l = search_level(root,0,key);
						printf("%d\n",l);
						printf("Members of generation for %c are: \n",key);
						search_gen(root,1,l);
						printf("\n");
						child_gc(root,key);
						printf("\nSiblings are :\n");
						lc = sibling(root,NULL,key);
					}
				}
				tc--;
				printf("\n");
			}
		}
	}
}

struct node* create(char data)
{
	treenode = malloc(sizeof(struct node));
	treenode->data = data;
	treenode->lchild = treenode->rchild = NULL;
	return treenode;
}

struct node* inorder(struct node *start)
{
	if(start==NULL)
		return NULL;
	else
	{
		inorder(start->lchild);	
		printf("%c ",start->data);
		inorder(start->rchild);
	}
}

struct node* leaves(struct node *start)
{
	if(start==NULL)
		return NULL;
	else if(start->lchild==NULL && start->rchild==NULL)
		printf("%c ",start->data);
	else
	{
		leaves(start->lchild);
		leaves(start->rchild);
	}
}


int search_level(struct node *start, int count, char key)
{
	int vall,valr;
	if(start==NULL)
		return 0;
	else if(start->data == key)
		return count+1;
	else
	{
		vall = search_level(start->lchild,count+1,key);
		valr = search_level(start->rchild,count+1,key);
		if(vall==0 && valr==0)
			return 0;
		else if(vall>valr)
			return vall;
		else 
			return valr;
	}
}

void search_gen(struct node *start, int count, int level)
{
	if(count==level)
	{
		printf("%c ",start->data);
	}
	else
	{
		if(start->lchild!=NULL)
			search_gen(start->lchild,count+1,level);
		if(start->rchild!=NULL)
			search_gen(start->rchild,count+1,level);
	}	
}

void child_gc(struct node *start,char key)
{
	struct node *loc,*rc,*lc;
	loc = search(start,key);
	if(loc==NULL)
		printf("Element not found\n");
	else
	{
		lc= rc = NULL;
		printf("\nChildren are\n");
		if(loc->lchild!=NULL)
		{
			printf("%c ",loc->lchild->data);
			lc=loc->lchild;
		}
		if(loc->rchild!=NULL)
		{
			printf("%c",loc->rchild->data);
			rc = loc->rchild;
		}
		printf("\nGrand children are:\n");
		if(lc!=NULL)
			print_data(lc);
		if(rc!=NULL)
			print_data(rc);
	}

}

void print_data(struct node *loc)
{
	if(loc->lchild!=NULL)
		printf("%c ",loc->lchild->data);
	if(loc->rchild!=NULL)
		printf("%c ",loc->rchild->data);
}

struct node* search(struct node *start, char key)
{
	struct node *addl=NULL,*addr=NULL;
	if(start==NULL)
		return NULL;
	else if(start->data == key)
		return start;
	else
	{
		addl = search(start->lchild,key);
		addr = search(start->rchild,key);
		
		if(addl!=NULL && addr==NULL)
			return addl;
		else if(addl==NULL && addr!=NULL)
			return addr;
		else if(addl==NULL && addr==NULL)
			return NULL;
		else
			return addl;
	}
}

struct node* sibling(struct node *start,struct node *parent,char key)
{
	if(start==NULL)
		return NULL;
	else if(start->data==key)
	{
		if(parent!=NULL)
		{
			print_data(parent);
		}
	}
	else
	{
		parent = start;
		sibling(start->lchild,parent,key);
		sibling(start->rchild,parent,key);
	}

}
