#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>

typedef struct brojevi;

struct brojevi{
	int x;
	struct brojevi *next;
};

int push(void);
int Red(int x, struct brojevi *head);
int Stog(int x, struct brojevi *head);


int main(void)
{
	struct brojevi *head;
		struct brojevi *p;
	int i,j;
	head = (struct brojevi *)malloc(sizeof(struct brojevi));
	head->x = push();
	head->next = NULL;
	for (i = 0;i < 10;i++)
	{
		Red(push(), head);
	}
	p = head;
	while (p != NULL)
	{
		printf("%d", p->x);
		p = p->next;
	}
	scanf_s("%d", &j);
	
	

}

int push(void) {
	int x;
	x = rand() % 89+11;
	return x;
}

int Red(int x, struct brojevi *p) 
{

	struct brojevi *q;
	q = (struct brojevi*)malloc(sizeof(struct brojevi));
	q->x = x;
	q->next = NULL;
	
	while (p != NULL)
		p=p->next;

	p->next = q;
	q->next = p->next;

};
int Stog(int x, struct brojevi *p)
{

	struct brojevi *q;
	q = (struct brojevi *)malloc(sizeof(struct brojevi));
	q->x = x;
	q->next = NULL;
	q->next = p;
}