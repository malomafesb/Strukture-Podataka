#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define N 130


typedef struct Cvor *Position;

struct Cvor {
	char ime[N];
	char prezime[N];
	int godina_rodenja;
	Position Next;

};

void Dodaj_Na_Pocetak(char[], char[], int, Position);
void Dodaj_Na_Kraj(char[], char[], int, Position);
void Ispis(Position);
Position Trazi_Element_Po_Prezimenu(char[], Position);
Position Trazi_Prethodni(int, Position);
void Brisi(int, Position);
void ispisi_trazeni_element(Position);
void dealociranje(Position);
void Dodaj_iza(int, Position);
void Dodaj_ispred(int, Position);
void Sortiraj(Position);
int Upisuj_u_dat(Position);
void Citaj_iz_dat(Position);


int main(void) {
	struct Cvor head;
	head.Next = NULL;

	char name[N], surname[N];
	int yob = 0;

	int check = 0;

	Position t;

	char odabir = '1';


	printf("\t\t3.zadatak SP\n");
	printf("Unos na pocetak(press 1) ");
	printf("\nUnos na kraj(press 2) ");
	printf("\nIspis liste (press 3) ");
	printf("\nPronalazak elementa po prezimenu(press 4)");
	printf("\nBrisanje elementa iz liste (press 5) ");
	printf("\nDodavanje elementa iza(press 6)");
	printf("\nDodavanje elementa ispred(press 7)");
	printf("\nSortiranje po prezimenu (press 8)");
	printf("\nUpisivanje u datoteku (press 9)");
	printf("\nCitanje iz datoteke (press a or A)");
	printf("\nZavrsetak programa(press 0)\n ");
	while (odabir != '0') {
		printf("\n\tODABIR: ");
		scanf(" %c", &odabir);
		switch (toupper(odabir)) {
		case '1':
			printf("Ime, prezime, godina rodenja: ");
			scanf(" %s %s %d", name, surname, &yob);
			Dodaj_Na_Pocetak(name, surname, yob, &head);
			break;
		case '2':
			printf("Ime, prezime, godina rodenja: ");
			scanf(" %s %s %d", name, surname, &yob);
			Dodaj_Na_Kraj(name, surname, yob, &head);
			break;
		case '3':
			Ispis(head.Next);
			break;
		case '4':
			printf("Koje prezime zelite pronaci: ");
			scanf(" %s", surname);
			t = Trazi_Element_Po_Prezimenu(surname, head.Next);
			ispisi_trazeni_element(t);
			break;
		case '5':
			printf("Unesite godinu rodenja osobe koju zelite izbriati: ");
			scanf(" %d", &yob);
			Brisi(yob, &head);
			Ispis(head.Next);
			break;
		case '6':
			printf("Iza godine rodenja koje osobe dodati novu: ");
			scanf(" %d", &yob);
			Dodaj_iza(yob, &head);
			break;
		case '7':
			printf("Ispred godine rodenja koje osobe dodati novu: ");
			scanf(" %d", &yob);
			Dodaj_ispred(yob, &head);
			break;
		case '8':
			Sortiraj(&head);
			printf("Sortirana lista: \n");
			Ispis(head.Next);
			break;
		case '9':
			check = Upisuj_u_dat(head.Next);
			if (check == 0)
				puts("Upisano u datoteku..");
			break;
		case 'A':
			Citaj_iz_dat(&head);
			Ispis(head.Next);
			break;
		default:
			if (odabir != '0')
				printf("Pokusajte ponovo: ");
			break;
		}
	}


	free(t);

	dealociranje(&head);


	return 0;
}

void Dodaj_Na_Pocetak(char x[], char y[], int z, Position P) {
	Position q;
	q = (struct Cvor*) malloc(sizeof(struct Cvor));
	strcpy(q->ime, x);
	strcpy(q->prezime, y);
	q->godina_rodenja = z;

	q->Next = P->Next;
	P->Next = q;
};

void Dodaj_Na_Kraj(char x[], char y[], int z, Position P) {

	Position q;
	q = (struct Cvor*) malloc(sizeof(struct Cvor));
	strcpy(q->ime, x);
	strcpy(q->prezime, y);
	q->godina_rodenja = z;

	while (P->Next != NULL)
		P = P->Next;

	q->Next = P->Next;
	P->Next = q;
};


void Ispis(Position P) {
	while (P != NULL) {
		printf("%s %s %d\n", P->ime, P->prezime, P->godina_rodenja);
		P = P->Next;
	}
};
Position Trazi_Element_Po_Prezimenu(char x[], Position P) {
	while (NULL != P && strcmp(P->prezime, x))
		P = P->Next;

	return P;
};
Position Trazi_Prethodni(int x, Position P) {

	while (P->Next != NULL && P->Next->godina_rodenja != x)
		P = P->Next;

	if (P->Next == NULL)
		return NULL;

	else
		return P;

};
void Brisi(int x, Position P) {

	Position temp;
	P = Trazi_Prethodni(x, P);

	if (P == NULL)
		printf("Ne postoji\n");

	else {
		temp = P->Next;
		P->Next = P->Next->Next;
		free(temp);
	}

};
void ispisi_trazeni_element(Position P) {
	printf("\n\n%s %s %d\n", P->ime, P->prezime, P->godina_rodenja);
}
void dealociranje(Position P) {
	Position temp;
	while (P->Next != NULL) {
		temp = P->Next;
		P->Next = P->Next->Next;
		free(temp);
	}
};

void Dodaj_iza(int x, Position P) {
	char name[N], surname[N];
	int yob = 0;

	Position q;
	q = (struct Cvor*) malloc(sizeof(struct Cvor));

	printf("Ime,prezime, god.rodenja nove osobe: ");
	scanf(" %s %s %d", name, surname, &yob);

	strcpy(q->ime, name);
	strcpy(q->prezime, surname);
	q->godina_rodenja = yob;

	P = Trazi_Prethodni(x, P);
	if (P == NULL)
		printf("Nema trazenog elementa\n");
	else {
		P = P->Next;
		q->Next = P->Next;
		P->Next = q;
	}

};
void Dodaj_ispred(int x, Position P) {
	char name[N], surname[N];
	int yob = 0;

	Position q;
	q = (struct Cvor*) malloc(sizeof(struct Cvor));

	printf("Ime,prezime, god.rodenja nove osobe: ");
	scanf(" %s %s %d", name, surname, &yob);

	strcpy(q->ime, name);
	strcpy(q->prezime, surname);
	q->godina_rodenja = yob;

	P = Trazi_Prethodni(x, P);
	if (P == NULL)
		printf("Nema trazenog elementa\n");

	else {
		q->Next = P->Next;
		P->Next = q;
	}
};
void Sortiraj(Position P) {
	Position i = P;
	Position j = NULL;
	Position pret_j = NULL;
	Position end = NULL;

	while (i->Next != end) {
		pret_j = i;
		j = pret_j->Next;
		while (j->Next != end) {
			if (strcmp(j->prezime, j->Next->prezime) > 0) {
				pret_j->Next = j->Next;
				j->Next = j->Next->Next;
				pret_j->Next->Next = j;
				j = pret_j->Next;

			}
			pret_j = j;
			j = j->Next;
		}
		end = j;
	}
}
int  Upisuj_u_dat(Position P) {
	FILE *out;

	char a[] = { "." };
	char *fp;
	fp = (char *)malloc(100);

	printf("Ime datoteke za upis (bez .txt): ");
	scanf(" %s", fp);
	if (strchr(fp, a[0]) == 0)
		strcat(fp, ".txt");
	else {
		printf("No dots please..\n");
		return 1;
	}

	out = fopen(fp, "w");

	if (out == NULL)
		printf("Neuspjesno otvaranje datoteke\n");

	while (P != NULL) {
		fprintf(out, "%s %s %d\n", P->ime, P->prezime, P->godina_rodenja);
		P = P->Next;
	}
	fclose(out);
	return 0;

}
void Citaj_iz_dat(Position P) {

	char name[N], surname[N];
	int yob = 0;

	char *fp;
	fp = (char *)malloc(100);

	FILE *in = NULL;
	printf("File name: \n");
	scanf(" %s", fp);

	strcat(fp, ".txt");

	in = fopen(fp, "r");

	if (in == NULL)
		printf("Neuspjesno otvaranje datoteke\n");

	while (1) {
		fscanf(in, " %s %s %d", name, surname, &yob);
		if (feof(in))
			break;
		Dodaj_Na_Kraj(name, surname, yob, P);
	}
	fclose(in);
}