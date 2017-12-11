#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct zaznam{
  int hodnota;
  char meno[52];
  char spz[9];
  int stav;
  double cena;
  int datum;
  struct zaznam *dalsi;
} zaznam;
void vypis(zaznam ** p_zaznam, int * n, int * s)
{
  FILE *fr;
  zaznam * p_akt;
  int c = 0, i, stav, datum;
  char meno[52], spz[9];
  double cena;
  fr = fopen("predaj.txt","r");
  while((c = getc(fr)) != EOF){
    if(c == '\n')
    ++*n;}
  (*p_zaznam) = (zaznam *) malloc(sizeof(zaznam));
  *n = (*n + 1) / 6;
  rewind(fr);
  p_akt = * p_zaznam;
  for(i = 1; i <= *n; i++){
    fgets(meno, 52, fr);
    fgets(spz, 9, fr);
    fscanf(fr, "%d\n%lf\n%d\n", &stav, &cena, &datum);
    p_akt->hodnota = i;
    strcpy(p_akt->meno, meno);
    strcpy(p_akt->spz, spz);
    p_akt->stav = stav;
    p_akt->cena = cena;
    p_akt->datum = datum;
    if(i == *n)
      break;
    p_akt->dalsi = (zaznam *) malloc(sizeof(zaznam));
    p_akt = p_akt->dalsi;
  }
  fclose(fr);
  p_akt = *p_zaznam;
  for(i = 1; i <= *n; i++){
    printf("%d.\n", p_akt->hodnota);
    printf("meno a priezvisko: %s", p_akt->meno);
    printf("spz: %s", p_akt->spz);
    printf("typ auta: %d", p_akt->stav);
    printf("\ncena: %.2lf", p_akt->cena);
    printf("\ndatum: %d\n", p_akt->datum);
    p_akt = p_akt->dalsi;
  }
return;
}

void odmeny(zaznam ** p_zaznam, int * n, int * s)
{
  int i, a =0, rok;
  zaznam *p_akt;
  p_akt = *p_zaznam;
  scanf("%d", &rok);
  p_akt = *p_zaznam;
  for(i = 1; i <= *n; i++){
    if(rok - p_akt->datum > 9999){
      printf("%d.\n", ++a);
      printf("meno a priezvisko: %s", p_akt->meno);
      printf("spz: %s", p_akt->spz);
      if(p_akt->stav == 1)
        printf("odmena: %.2lf\n", (1.5 * p_akt->cena) / 100);
      else
        printf("odmena: %.2lf\n", (2.2 * p_akt->cena) / 100);
    }
    p_akt = p_akt->dalsi;}
  return;
}

void vypisspz(zaznam ** p_zaznam, int * n, int * s)
{
  int i, ii;
  zaznam *p_akt;
  p_akt = *p_zaznam;
  for(i = 1; i <= *n; i++){
    for(ii = 0; ii <= 7; ii++){
      if(ii == 2 || ii == 5)
      printf(" ");
      printf("%c", (p_akt->spz)[ii]);}
    p_akt = p_akt->dalsi;}
 return;
}
int main(){
  zaznam *p_zaznam, *p_akt;
  char vstup;
  int k = 0, kk = 0, *s, *n;
  s = &k;
  n = &kk;
  while(vstup != 'k'){
    scanf("%c", &vstup);
    switch(vstup)
    {
      case 'v' :vypis(&p_zaznam, n, s);    break;
      case 'o' :odmeny(&p_zaznam, n, s);   break;
      case 's' :vypisspz(&p_zaznam, n, s); break;
    }
  }
  return 0;
}
