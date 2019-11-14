#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cvor* Position;

struct Cvor{
	int El;
	Position Next;
};

int Ispis(Position);
int Unos(Position, int);
int CitajIzDat(char *, Position);
int Unija_Presjek(Position, Position, Position, Position);
int Postoji_li(Position, Position);
int Unija(Position,Position,Position);
int Presjek(Position,Position,Position);
int dealociranje(Position);

int main(void){
	struct Cvor P1;
	struct Cvor P2;
	struct Cvor P;
	struct Cvor U;
	int check=0;
	int a=0;

	P1.Next=NULL;
	P2.Next=NULL;
	P.Next=NULL;
	U.Next=NULL;

	check= CitajIzDat("prvo.txt" , &P1);

	if(check!=0)
		printf("Greska\n");

	printf("Prva lista: ");
	Ispis( P1.Next);

	puts("");
	check = CitajIzDat("drugo.txt" , &P2);

	if(check!=0)
		printf("Greska\n");

	printf("Druga lista: ");
	Ispis(P2.Next);

	do
	{
		puts("");
		printf("Samo unija(1), samo presjek(2), unija i presjek(3): ");
		scanf(" %d",&a);

		if(a==1){
			Unija(P1.Next,P2.Next,&U);
			printf("Unija: ");
			Ispis(U.Next);

			puts("");
		}
		else if(a==2){
			Presjek(P1.Next,P2.Next,&P);

			printf("Presjek: ");
			Ispis(P.Next);

			puts("");
		}
		else if(a==3){
			Unija_Presjek(P1.Next, P2.Next, &U, &P);

			printf("Unija: ");
			Ispis(U.Next);

			puts("");

			printf("Presjek: ");
			Ispis(P.Next);

			puts("");
		}
		else
			printf("Wrong input");


		dealociranje(&P1);
		dealociranje(&P2);
		dealociranje(&U);
		dealociranje(&P);
	} 
	while (a < 4);

	return 0;
}

int Ispis(Position P){
	while(P != NULL){
		printf("%d ", P->El);
		P=P->Next;
	}
	return 0;
}
int Unos(Position P, int x){
	Position q;
	q= (struct Cvor*)malloc(sizeof(struct Cvor));

	while(P->Next != NULL && P->Next->El < x){
		P=P->Next;
	}

	q->El=x;
	q->Next=P->Next;
	P->Next=q;

	return 0;
}

int CitajIzDat(char *fn, Position P){
	FILE *in;
	in=fopen(fn, "r");

	if(in==NULL)
		return 1;

	while (!feof(in)){
		fscanf(in," %d ", &P->El);
		Unos(P,P->El);
	}
	fclose(in);
	return 0;
}
int Unija_Presjek(Position X, Position Y, Position Z, Position K){
	int rez=0;

	Position q;
	q= (struct Cvor*)malloc(sizeof(struct Cvor));

	q=X;

	while(q!= NULL){
		Unos(Z, q->El);
		q=q->Next;
	}

	while(Y != NULL){
		rez=Postoji_li(X, Y);
		if(rez==0)
			Unos(Z, Y->El);

		else if(rez != 0)
			Unos(K, Y->El);

		rez=0;
		Y=Y->Next;
	}
	free(q);
	return 0;
}
int Postoji_li(Position X, Position Y){
	int brojac=0;
	while(X!= NULL){
		if(X->El == Y->El){
			brojac++;
		}
		X = X->Next;
	}
	return brojac;
}
int Unija(Position X,Position Y,Position Z){
	int rez=0;

	Position q;
	q= (struct Cvor*)malloc(sizeof(struct Cvor));

	q=X;

	while(q!= NULL){
		Unos(Z, q->El);
		q=q->Next;
	}

	while(Y != NULL){
		rez=Postoji_li(X, Y);
		if(rez==0)
			Unos(Z, Y->El);
		rez=0;
		Y=Y->Next;
	}
	return 0;
}
int Presjek(Position X,Position Y,Position K){
	int rez=0;

	while(Y != NULL){
		rez=Postoji_li(X, Y);
		if(rez != 0)
			Unos(K, Y->El);
		rez=0;
		Y=Y->Next;
	}
	return 0;
}
int dealociranje(Position P){
	Position temp;

	while(P->Next !=NULL){
		temp = P->Next;
		P->Next = P->Next->Next;
		free(temp);
	}
	P->Next=NULL;
	return 0;
}
