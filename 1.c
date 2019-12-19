//maloma
#define _CRT_SECURE_NO_WARNINGS_
#include<stdio.h>
#include<string.h>
#define MAX 30

typedef struct{
	char ime[MAX];
	char prezime[MAX];
	int bodovi;
	float prosjek;
}student;

int BrojiRetke(char* datoteka);

int main()
{
	student* S;
	int i=0;
	int broj_redaka=0;
	int max=0;
	
	FILE *fp =NULL;
	fp=fopen("studenti.txt","r");
	if(fp==NULL)
		printf("GRESKA!");
		
	broj_redaka=BrojiRetke(fp);
	
	S=(student*)malloc(broj_redaka*sizeof(student));
	
	for(i=0;i<broj_redaka;i++){
		scanf(fp,"%s\t %s\t %d\t ", S[i].ime, S[i].prezime, &S[i].bodovi);
			}
	
	max=S[0].bodovi;
	
	for(i=0;i<broj_redaka;i++){
		S[i].prosjek=(float)S[i].bodovi/max*100;
			}
	printf("\tIme\tPrezime\tBodovi\tProsjek\n\n");
	
	for(i=0;i<broj_redaka;i++){
		printf("%s\t %s\t %d\t %f\n ", S[i].ime, S[i].prezime, S[i].bodovi, S[i].prosjek);
	}
	return 0;
}
int BrojiRetke(char* datoteka)
{
	int broj=0;
	int x=0;
	
	FILE*fp=NULL;
	fp=fopen("studenti.txt", "r");
	if(fp==NULL)
	 printf("GRESKA!");
	 
	 broj++;
	 while((x=fgetc(fp))!=EOF)
	 {
	 	if(x=='\n')
	 	broj++;
	 }
	 
	 return broj;
}

