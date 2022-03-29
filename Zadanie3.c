// Zadanie c. 3
// Marian Bodnar
// FI 1 extern


#include <stdio.h>                                  // Standartna kniznica
#include <stdlib.h>

int c;                                              // Globalne premenne
int max;
char *mesiace[] = {"", "Januar", "Februar", "Marec", "April", "Maj", "Jun", "jul", "August", "September", "Oktober", "November", "December"} ;
int dni[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int vzor[14];                                       // vzorec pre vypocet vzhladu mesiacov
int v = 1;
int vysledok;
int skok;

void funkcia(void)                                  // funkcia pre kreslenie kalendara podla vzorca
{
    int b = 0;                                      // counter pre viditelne znaky
    int e = 0;                                      // counter pre neviditelne znaky

    while( e < skok)                                // skok pred vypisom cisel v kalendari 
    {
        printf("    ");
        e++;
    }
   
    while(max != 0) 
    {
    max--;                                          // vstup pre slucku z pola dni 
    e++;                                            // pocet neviditelnych znakov counter
    b++;                                            // vypis dni counter
    
        if ( b < 10)                                // zarovnanie riadku vyrovnat rozdiel v pocte znakov
        {
            printf("   %i", b);
        }
        else
        {
            printf("  %i", b);
        }

        if ( e % 7)                                 // kopanec do riadku modulo 
        {}
        else
        {
            printf("\n");
        } 
    }
}

void matika(void)                                   // funkcia matematika vypocet do vzorca  ako rozlozit mesiac
{
    vysledok =  (max + c) - 28;

    if (vysledok > 7)
    {
        vysledok = vysledok - 7;
    }
    else if( vysledok % 7);                         // podmienky pre spravne radenie kalendara
    else
    {
        vysledok = 0;
    }
    
    c = vysledok;                                   // vratit hodnotu na vypocet novej
}

int main()                                          // hlavna funkcia
{
    int g = 1;                                      
    int h = 0;                                      // counter premenne
    int a = 0;
    int rok;                                        // nacitanie roku
    
    printf("Zadajte rok: ");                        // citanie roku
    scanf ("%i", &rok);
    
    if(rok <= 0 || rok >= 3000)                     // Kontrola vstupu a vyhodnotenie roku
    {   
        printf("Zadali ste zly rok!\n");
        printf("Zadajte rok od 0 do 3000\n");
        exit(-1);
    }
    else
    {
        if ( rok % 4 || rok % 400 && (!(rok % 100)))
        {
            printf("Zadali ste nepriestupny rok\n");
        }
        else
        {
            printf("Zadali ste priestupny rok\n");
            dni[1] = 29;
        }
    }

    printf("Zadajte den v tyzdni\n");               // Citanie dni
    scanf("%i", &c);
    
    if(c >= 1 && c <= 7)                            // kontrola zadaneho dna a oznam
    {
        printf("1. datum pripadne na %i. den v tyzdni\n", c);
    }
    else
    {
        printf("Zadali ste nespravny den!\n");
        printf("Povolene su len dni od 1 po 7\n");
        exit(-2);
    }
    c = c-1;                                        // uprava skoku
    
    vzor[0] = c;                                    // prva hodnota do vzorca podla zadanej hodnoty
    
    while(a < 12)                                   // slucka pre vypis mesiacov
    {
    printf("\n\n");                                 // medzera medzi mesiacmi
    printf("%i | ", rok);
    printf("%s", mesiace[g]);                       // vypis mesiac
    printf(" | %d Dni \n", dni[h]);                 // vypis pocet dni
    
    max = dni[h];                                   // hodnota pre matiku z pola

    printf("   P   U   S   S   P   S   N \n");
    printf("=============================\n");
    
    matika();                                       // vypocet hodnot do vzorca
    
    vzor[v]= vysledok;                              // nacitanie hodnot do vzorca                               

    skok = vzor[h];                                 // hodnota pre funkciu zo vzorca
    
    funkcia();                                      // opakovanie funkcie , fukcia vracia dni v spravnom tvare 
    
    printf("\n=============================\n");

    v++;                                            // citanie pola pre vypocet funkcie 
    h++;                                            // pocet dni counter 
    g++;                                            // Vypis mesiacov counter
    a++;                                            // fungovanie slucky while counter
    }    

    printf("\n\nPress Any Key to Continue\n");      // pre exe subor odchod
    getchar();

    
    
    return 0;
}