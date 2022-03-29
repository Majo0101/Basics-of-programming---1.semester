// Zadanie cislo 2

#include <stdio.h>
#include <stdlib.h>

int main()
{
   //premenne.............................................................................
   float num , cisla[100];            // nacitat cisla cez num do cisla
   int i = 0;                         // integer pre i  
   int n = 0;                         // premenna pre kladne cisla
   int m = 0;                         // premenna pre zaporne cisla
   int v = 0;                         // premenna pre vsetky cisla
   float sum;                         // sucet nacitanych cisel
   float vysledok;                    // vysledok priemer
   float max;                         // maximalna hodnota
   float min;                         // minimalna hodnota
   int spravne = 0;                   // spravne znaky v subore
   int nespravne = 0;                 // nespravne znaky v subore
   char ch;                           // nacitanie znakov
   FILE *subor;                       // nacitat subor
   //......................................................................................

   
   //subor kontrola ci existuje............................................................
   if ((subor = fopen("C:/tmp/dataf.txt","r")) == NULL)  // podmienka pre dataf.txt
    {
       printf("Chyba pri otvarani dokumentu\n");         // ak nenajde dataf
       printf("Ulozte textovy dokument do C:/tmp/ a pomenujte ho dataf.txt\n");    
       exit(1);                                          // skoncit
    }
    else
    {
        printf("Otvaram dokument ....\n");               // ak najde dataf
    }
    //.....................................................................................
  
    
    //primitivna kontrola..................................................................
    while(1)
    {
    ch=fgetc(subor);
    if(ch==EOF)                                // nacitat znaky
    break;
    if(ch=='9'||ch=='8'||ch=='7'||ch=='6'||ch=='5'||ch=='4'||ch=='3'||ch=='2'||ch=='1'||ch=='0'||ch==' '||ch=='-'||ch=='.'||ch=='\n')
    spravne++;                                 // spravne znaky 
    else
    {nespravne++;}                             // nespravne znaky
    }
    
    fclose(subor);
    
    if(nespravne > 0)
    {
    printf("V dokumente sa nachadzaju nepovolene znaky\n");
    printf("Zapiste dokument v tvare XX.XX XX.XX -XX.XX...\n");
    printf("alebo\n");
    printf("XX.XX\nXX.XX\n-XX.XX\n....");
    exit(2);
    }
    else
    printf("Dokument obsahuje spravne zapisane udaje\n");
    //.....................................................................................
    
    
    // citanie cisel z dataf...............................................................
    fopen("C:/tmp/dataf.txt","r");
    while( fscanf(subor, "%f", &num) != EOF )    // citanie suboru pokial nepride na koniec
    {
        if (num >= 0)                            // ak je cislo kladne
        {
        cisla[i++] = num;                        // nacitat kladne skore do cisla
        n++;                                     // pocitadlo nacitanych cisel
        sum += num;                              // scitanie skore
        }
        else if (num < 0 )                       // ak je cislo zaporne alebo nula
        {
        m++;                                     // pocitadlo zaporne cisla a nula
        }
    }
    fclose(subor);                               // zavriet subor po precitani
    //.....................................................................................

   
    //premenne pre max a min...............................................................
    max = cisla[0];
    min = cisla[0];
    //.....................................................................................


    //vypis definicie......................................................................
    for( i = 0; i < n; i++ )       // vypis skore , opakovat podla pocitadla kladneho skore 
    {
    printf("skore[%d] = %.02f\n",i, cisla[i]);        // vypis skore 
        
        if(cisla[i] > max)                            // nacitanie MAX skore
        {
            max = cisla[i];
        }

        
        if(cisla[i] < min)                            // nacitanie MIN skore
        {
            min = cisla[i];
        }
    }
    
    v = n + m;                                        // scitanie pocet vsetkych skore
    
    if (v == 0)                                       // blbol priemer pri pocitani z nula
    {
        vysledok = 0;                                 // odstranenie chybneho vypoctu 
    }
    else
    {
    vysledok = sum / n;                               // priemer skore vysledok
    }
    

    if( m > 0)                     // nacitanie zapornych a nulovych napocitanych hodnot
    {
        printf("\nv dokumente sa nachadzaju zaporne hodnoty");
    }
    //.....................................................................................    
        
        
    //vypisovanie..........................................................................
        printf("\npocet vsetkych skore: %i" , v);    // pocet vsetkych skore
        printf("\npocet spravnych skore: %i" , n);   // pocet spravnych skore
        printf("\nsucet skore:  %.02f" , sum);       // sucet skore
        printf("\npriemer skore: %.02f" , vysledok); // priemer skore
        printf("\nnajvyssie skore:  %.02f" , max);   // maximalna hodnota skore
        printf("\nnajmensie skore:  %.02f" , min);   // minimalna hodnota skore
    //.....................................................................................


       return 0;
}
