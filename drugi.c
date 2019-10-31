//MaLoMa Team 
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct Osoba;
typedef struct Osoba *pozicija; 
typedef struct Osoba{
    char ime[30];
    char prezime[30];
    int godinaRodenja;
    pozicija *next;
}_Osoba;
pozicija AlociranjeMemorijeZaElementListe();
int UnosJednogElementa(_Osoba *);
int UnosElementaNaPocetak(_Osoba *);
int UnosElementaNaKraj(_Osoba *);
int Ispis(_Osoba *);
_Osoba *PronadiPoPrezimenu(_Osoba *,char *);
int BrisiElementListe(_Osoba *,_Osoba *);
int DodajElementIzaNekogElementa(_Osoba *el,_Osoba *novi);
int DodajElementPrijeNekogElementa(_Osoba *Head,_Osoba *novi);
_Osoba *pronadiPrethodni(_Osoba *Head,_Osoba *element);
int ZamijeniPozicije(_Osoba *Head,_Osoba *prvi,_Osoba *drugi);
int SortirajListuPoPrezimenu(_Osoba *head);
int Udatoteku(_Osoba *head,char *ime);
int IzDatoteke(_Osoba *head,char *ime);
int main(void)
{
    _Osoba *Head=NULL;
    _Osoba *element=NULL;
    int x,y,nastavak,s;
    int r=0;
    char prezime[100];
    char imedat[100];
    Head=AlociranjeMemorijeZaElementListe();
    UnosJednogElementa(Head);
    Head->next=NULL;
   start: printf("Zelite li dodati element liste na pocetak ili na kraj?(odaberite 1 ili 2)\n");
    printf("1.Dodavanje na pocetak.(1)\n");
    printf("2.Dodavanje na kraj.(2)\n");
    scanf("%d",&x);
    switch(x) {
    	case 1:{UnosElementaNaPocetak(Head);
    	       printf("Ubacili ste element na pocetak liste.\n");
    	       break;}
    	case 2:{UnosElementaNaKraj(Head);
    		   printf("Ubacili ste element na kraj liste.\n");
    		   break;}
    	default:printf("Niste odabrali nista od navedenog..Program nastavlja dalje..\n");
    		    break;
	}
	printf("Zelite li unijeti jos elemenata? Ako zelite pritisnite 1,ako ne bilo sta drugo.\n");
	scanf("%d",&y);
	if(y==1) goto start;
	printf("Ispis unesene liste:\n");
	Ispis(Head);
	printf("\nIspisali ste listu.\n");
	printf("Zelite li nastaviti s programom?\n");
	printf("Ako zelite pritisnite 1.");
	scanf("%d",&nastavak);
	if(nastavak==1)
	{
		printf("Sto zelite raditi s programom...\n1.Dodavanje elem. na pocetak\n2.Dodavanje elem.na kraj\n3.Brisite elem.\n4.ispisite listu\n5.Dodaj element iza nekog elementa.\n6.Dodaj element iza nekog elementa\n7.sortiraj listu\n8.Spremi listu u datoteku\n9.Ucitaj listu iz datoteke\n10.zatvori program");
		scanf("%d",&s);
		pocetak:switch(s)
		{
			case 1:{UnosElementaNaPocetak(Head);
    	       printf("Ubacili ste element na pocetak liste.\n");
    	       break;}
    		case 2:{UnosElementaNaKraj(Head);
    		   printf("Ubacili ste element na kraj liste.\n");
    		   break;}
    		case 3:{
    			printf("Unesi prezime: ");
                scanf(" %s",prezime);
            	brisiElement(Head, pronadiElement(Head, prezime));
            	break;}
			case 4:{
				Ispis(Head);
				break;
			}
			case 5:{
				printf("Unesi prezime: ");
            	scanf("%s",prezime);
            	element = pronadiElement(Head,prezime);
            	_Osoba *Student=NULL;
            	UnosJednogElementa(Student);
            	DodajElementIzaNekogElementa(element,Student);
				break;
			}
			case 6:{
				printf("Unesi prezime: ");
				scanf("%s",prezime);
				element=pronadiElement(Head,prezime);
				DodajElementPrijeNekogElementa(Head,element);
				break;
			}
			case 7:{
				SortirajListuPoPrezimenu(Head);
				Ispis(Head);
				break;
			}
			case 8:{
				printf("Unesi ime datoteke: ");
            	scanf(" %s",imedat);
            	UDatoteku(Head,imedat);
				break;
			}
			case 9:{
				printf("Unesi ime datoteke: ");
            	scanf(" %s",imedat);
            	IzDatoteke(Head, imedat);
            	break;
			}
		}
			}
		printf("Zelite li jos nesto?Ako zelite pritisnite 1.");
		scanf("%d",&r);
		if(r==1) goto pocetak;
		else printf("pozdrav.");
		
	}
	
    
}
pozicija AlociranjeMemorijeZaElementListe()
{
    pozicija *p;
    p=(pozicija *)malloc(sizeof(pozicija));
    return *p;
}
int UnosJednogElementa(_Osoba *Student)
{
	printf("Unesite podatke studenta:\n");
	printf("Ime: ");
	scanf("%s",Student->ime);
	printf("\nPrezime: ");
	scanf("%s",Student->prezime);
	printf("Godina rodenja: ");
	scanf("%d",&Student->godinaRodenja);
	return 0;
}
int UnosElementaNaPocetak(_Osoba *Head)
{
	_Osoba *Student=NULL;
	Student=AlociranjeMemorijeZaElementListe();
	UnosJednogElementa(Student);
	
	Student->next=Head->next;
	Head->next=Student;
	
	return 0;
}
int UnosElementaNaKraj(_Osoba *Head)
{
	_Osoba *Student=NULL;
	Student=AlociranjeMemorijeZaElementListe();
	UnosJednogElementa(Student);
	while(Head->next==NULL)
		Head=Head->next;
		
	Student->next=Head->next;
	Head->next=Student;
	
	return 0;
}

int Ispis(_Osoba *Head)
{
	_Osoba *p=Head;
	while(p!=NULL)
	{
		printf("\nIme:%s\nPrezime:%s\nGodina rodenja:%d",p->ime,p->prezime,p->godinaRodenja);
		p=p->next;
	}
	return 0;
}
int BrisiElementListe(_Osoba *Head,_Osoba *element)
{
    _Osoba *p=Head;
    _Osoba *q=Head;
    while (p!=NULL && p->next!=element) {
    	p=p->next;
    }

    if (p==NULL)
        return -1;
    else
    {
    	q=p->next;
        p->next=q->next;
        free(element);
    }

    return 0;
}
_Osoba *PronadiPoPrezimenu(_Osoba *Head, char *prezime)
{
    _Osoba *p=Head->next;

    while(p!=NULL && strcmp(p->prezime,prezime)) {
        p=p->next;
    }

    return p;
}
int DodajElementIzaNekogElementa(_Osoba *el,_Osoba *novi)
{
    novi->next = el->next;
    el->next = novi;
    return 0;
}
int DodajElementPrijeNekogElementa(_Osoba *Head,_Osoba *novi)
{
	_Osoba *q=Head;
	_Osoba *student=NULL;
	student=AlociranjeMemorijeZaElementListe();
	UnosJednogElementa(Student);
	while(q!=NULL && q->next!=element)
	{
		q=q->next;
	}
	DodajElementIzaNekogElementa(p,student);
	
	return 0;
}
_Osoba *pronadiPrethodni(_Osoba *Head,_Osoba *element)
{
    _Osoba *q = Head;

    while(q!=NULL && q->next!=element)
        q=q->next;

    return q;
}
int zamijeniPozicije(_Osoba *Head,_Osoba *prvi,_Osoba *drugi)
{
    _Osoba *pret=pronadiPrethodni(Head,prvi);
    _Osoba *t=drugi->next;

    pret->next=drugi;
    drugi->next=prvi;
    prvi->next=t;

    return 0;
}
int SortirajListuPoPrezimenu(_Osoba *Head)
{
    _Osoba *l = Head->next;
    _Osoba *r = NULL;

    while(Head->next!=r) {
        while(l->next!=r) {
            if(strcmp(l->prezime,l->next->prezime)>0) {
                zamijeniPozicije(Head,l,l->next);
            }
            else
                l=l->next;
        }
        r=pronadiPrethodni(Head,r);
        l=Head->next;
    }
    
    return 0;
}
int UDatoteku(_Osoba *Head,char *ime)
{
	_Osoba *p=Head->next;
    FILE *f=NULL;
    f=fopen(ime, "w");
    if(f==NULL)
        return -1;
    while (p!=NULL) 
	{
        fprintf(f, "%s %s %d\n", p->ime, p->prezime, p->godinaRodenja);
        p=p->next;
    }
    fclose(f);
    return 0;
}
int IzDatoteke(_Osoba *Head,char *ime)
{
	FILE *f;
    int brojSt=0;
    int i=0;
    _Osoba *p=Zadnji(Head);
    char niz[1024] = {0};

    f=fopen(ime, "r");

    if (f==NULL)
        return -1;

    while(fgets(niz,1024, f))
        brojSt++;

    rewind(f);

    for (i=0;i<brojSt;i++) {
        _Osoba *novi=(_Osoba *)malloc(sizeof(_Osoba));
        novi->next=NULL;
        p->next=novi;
        p=p->next;

        fscanf(f, "%s %s %d", novi->ime,novi->prezime,&(novi->godinaRodenja));}
        fclose(f);
        return 0;
}



