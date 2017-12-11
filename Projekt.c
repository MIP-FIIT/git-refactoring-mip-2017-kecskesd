#include <stdio.h>
#include <stdlib.h>
int vypis(){
  int c=0, i;
  FILE *fr;
  if((fr=fopen("predaj.txt","r")) == NULL){
    printf("Neotvoreny subor\n");
    return 0;}
  fseek(fr,0,SEEK_END);
  if(ftell(fr)==0)
  return 0;
  fseek(fr,0,SEEK_SET);
  while(c != EOF){
    printf("meno priezvisko: ");
    while((c=getc(fr)) != '\n')
    putchar(c);
    printf("\nSPZ: ");
    while((c=getc(fr)) != '\n')
    putchar(c);
    printf("\ntyp auta: ");
    while((c=getc(fr)) != '\n')
    putchar(c);
    printf("\ncena: ");
    while((c=getc(fr)) != '\n')
    putchar(c);
    printf("\ndatum: ");
    while((c=getc(fr)) != '\n')
    putchar(c);
    printf("\n\n");
    c=getc(fr);}
  fclose(fr);
return 1;
}
int odmeny(int fa){
  FILE *fr;
  double cena, odmena;
  int c=0, x, i, ii, rok, dni;
  if((fa==0) || (fr=fopen("predaj.txt","r")) == NULL)
    return 0;
  scanf("%d", &rok);
  while(c != EOF){
    x=-18;
    for(i=0;i<4;i++)
      while ((c=getc(fr)) != '\n')
      --x;
    fscanf(fr,"%d",&dni);
    c = getc(fr);
    if((rok-dni) > 9999){
      fseek(fr,x,SEEK_CUR);
      while((c=getc(fr)) != '\n')
      putchar(c);
      printf(" ");
      while((c=getc(fr)) != '\n')
      putchar(c);
      fscanf(fr,"%d",&i);
      c=getc(fr);
      fscanf(fr,"%lf",&cena);
      c=getc(fr);
      if(i == 1)
      odmena=(1.5*cena)/100;
      else
      odmena=(2.2 * cena)/100;
      printf(" %.2lf\n", odmena);
      while ((c=getc(fr)) != '\n');}
    c=getc(fr);}
    fclose(fr);
  return 0;
}
int polespz(int fa, int fb, int * p, char *** xy){
  FILE *fr;
  int c, x, i, ii;
  char m;
  if((fa == 0) || (fr=fopen("predaj.txt","r")) == NULL)
    return 0;
  while(1){
    for(i=0;i<5;i++)
    while((c=getc(fr)) != '\n');
    ++x;
    c= getc(fr);
    if(c ==EOF) break;}
  if(fb == 1){
    for (i=0; i<*p; ++i)
      free((*xy)[i]);
    free(*xy);}
  *xy =(char **) malloc((x-1)*sizeof(char *));
  for(i=0; i<x; i++)
    (*xy)[i] = (char *) malloc(7*sizeof(char));
  rewind(fr);
  x=0;
  while(1){
    while((c=getc(fr)) != '\n');
    for(i=0; i<7; i++){
      c=getc(fr);
      (*xy)[x][i] = c;}
    x++;
    c=getc(fr);
    for(i=0; i<3; i++)
      while ((c = getc(fr)) != '\n');
    c=getc(fr);
    if(c == EOF) break;}
  *p =x;
  fclose(fr);
  return 1;
}
return 0;
}
int main(){
  int fa=0, fb=0, *p, x, i;
  char vstup, **xy;
  p=&x;
  while(vstup !='k'){
    scanf("%c", &vstup);
    switch(vstup){
      case 'v':fa=vypis();                 break;
      case 'o':odmeny(fa);                 break;
      case 'n':fb=polespz(fa, fb, p, &xy); break;
      case 's':vypisspz(fb, p, xy);        break;
    }}
  if(fb == 1){
    for (i=0; i<*p; ++i)
      free(xy[i]);
    free(xy);}
  return 0;
}
