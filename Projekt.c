#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const double vacsia_odmena = 2.2;
const double mensia_odmena = 1.5;
const int struktura_polozky = 6;
const int dni_roka = 9999;
const int velkost_spz = 7;
const int a_medzera = 2;
const int b_medzera = 5;

typedef struct zaznam
{
  int poradie;
  char meno[52];
  char spz[9];
  int stav;
  double cena;
  int datum;
  struct zaznam * dalsi;
} zaznam;

void novy(zaznam ** p_zaznam, int * pocet)
{
  FILE *fr;
  zaznam * p_akt;
  int c_zaznamu, pismeno, stav, datum;
  char meno[52], spz[9];
  double cena;
  
  if((fr = fopen("predaj.txt", "r")) == NULL)
  {
    printf("Subor sa nenasiel\n");
    return;
  }
  
  while((pismeno = getc(fr)) != EOF)
    if(pismeno == '\n')
      ++*pocet;
  ++*pocet;
  *pocet /= struktura_polozky;
  
  if((*p_zaznam = (zaznam *) malloc(sizeof(zaznam))) == NULL)
  {
    printf("Chyba v pamati.\n");
    return;
  }
  
  p_akt = *p_zaznam;
  rewind(fr);
  
  for(c_zaznamu = 1; c_zaznamu <= *pocet; c_zaznamu++)
  {
    fgets(meno, 52, fr);
    fgets(spz, 9, fr);
    fscanf(fr, "%d\n%lf\n%d\n", &stav, &cena, &datum);

    p_akt->poradie = c_zaznamu;
    strcpy(p_akt->meno, meno);
    strcpy(p_akt->spz, spz);
    p_akt->stav = stav;
    p_akt->cena = cena;
    p_akt->datum = datum;
    
    if(c_zaznamu == *pocet)
      break;
    
    if((p_akt->dalsi = (zaznam *) malloc(sizeof(zaznam))) == NULL)
    {
      printf("Chyba v pamati.\n");
      return;
    }
    
    p_akt = p_akt->dalsi;
  }
  printf("Zoznam inicializovany.\n");
  fclose(fr);
  return;
}

void vypis(zaznam ** p_zaznam, int * pocet)
{
  if(*p_zaznam == NULL)
  {
    printf("Zoznam neinicializovany.\n");
    return;
  }
  
  zaznam * p_akt;
  p_akt = *p_zaznam;
  int c_zaznamu;
  
  for(c_zaznamu = 1; c_zaznamu <= *pocet; c_zaznamu++)
  {
    printf("%d.\n", p_akt->poradie);
    printf("meno a priezvisko: %s", p_akt->meno);
    printf("spz: %s", p_akt->spz);
    printf("typ auta: %d", p_akt->stav);
    printf("\ncena: %.2lf", p_akt->cena);
    printf("\ndatum: %d\n", p_akt->datum);
    p_akt = p_akt->dalsi;
  }
  return;
}

void odmeny(zaznam ** p_zaznam, int * pocet)
{
  if(*p_zaznam == NULL)
  {
    printf("Zoznam neinicializovany.\n");
    return;
  }
  
  zaznam *p_akt;
  p_akt = *p_zaznam;
  int rok, c_zaznamu, p_cislo = 0;
  
  scanf("%d", &rok);
  
  for(c_zaznamu = 1; c_zaznamu <= *pocet; c_zaznamu++)
  {
    if(rok - p_akt->datum > dni_roka)
    {
      printf("%d.\n", ++p_cislo);
      printf("meno a priezvisko: %s", p_akt->meno);
      printf("spz: %s", p_akt->spz);
      if(p_akt->stav == 1)
        printf("odmena: %.2lf\n", (mensia_odmena * p_akt->cena) / 100);
      else
        printf("odmena: %.2lf\n", (vacsia_odmena * p_akt->cena) / 100);
    }
    p_akt = p_akt->dalsi;
  }
  return;
}

void vypisspz(zaznam ** p_zaznam, int * pocet)
{
  if(*p_zaznam == NULL)
  {
    printf("Zoznam neinicializovany.\n");
    return;
  }
  
  zaznam *p_akt;
  p_akt = *p_zaznam;
  int c_zaznamu, pismeno;
  
  for(c_zaznamu = 1; c_zaznamu <= *pocet; c_zaznamu++)
  {
    for(pismeno = 0; pismeno <= velkost_spz; pismeno++)
    {
      if(pismeno == a_medzera || pismeno == b_medzera)
        printf(" ");
      printf("%c", p_akt->spz[pismeno]);
    }
    p_akt = p_akt->dalsi;
  }
  return;
}

int main()
{
  zaznam *p_zaznam, *p_akt;
  int *pocet, hpocet = 0;
  char vstup;
  
  pocet = &hpocet;
  
  while(vstup != 'k')
  {
    scanf("%c", &vstup);
    switch(vstup)
    {
      case 'n' : novy(&p_zaznam, pocet);     break;
      case 'v' : vypis(&p_zaznam, pocet);    break;
      case 'o' : odmeny(&p_zaznam, pocet);   break;
      case 's' : vypisspz(&p_zaznam, pocet); break;
    }
  }
  return 0;
}
