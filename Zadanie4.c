//Zadanie c.4

#include <stdio.h>
#include <stdlib.h>

int buf_vstup = 0;       // velkost pamate pre vstup orientacna vytvara sa podla skontrolovaneho suboru / dala by sa optimalizovat
int buf_kluc = 0;        // velkost pamete pre kluc orientacna vytvara sa podla skontrolovaneho suboru  / dala by sa optimalizovat

char *kluc_taska;        // pointer na zasobnik v pamati pre kluc typ CHAR
int *kluc_zasobnik;      // ponter na zasobnik v pamati pre kluc typ INT
int *vstup_zasobnik;     // pointer na zasobnik v pamati pre vstup typ INT

int gci = 0;             // |global counter in| vstup pre pocet nacitanych cisel


int kontrola_text(void)  // Funckia vracia int ,vstupna kontrola suboru TEXT , lokalne premenne , subor musi obsahovat spravne znaky, vystvara counter pre dynamicku pamat
{
    int spravne = 0;
    int nespravne = 0;
    int ch;

    FILE *vstup;
    
    vstup = fopen("C:/tmp/text.txt","r");

    if (vstup == NULL)
    {
        nespravne++;
    }

    while(1)
    {
        ch=fgetc(vstup);
        
        if(ch==EOF)                                
        break;
        
        if(ch <= '9' && ch >= '0'||ch==' '||ch=='\n')
        {
            spravne++;                                  
            buf_vstup++;
        }
        else
        {
            nespravne++;
        }                             
    
    }

    
    fclose(vstup);


    if (fclose(vstup) != EOF)
    {
        nespravne = nespravne + 10;
    }
    
    
    return (nespravne == 0);

}

int kontrola_key(void)   // Funckia vracia int ,vstupna kontrola suboru KEY , lokalne premenne , subor musi obsahovat spravne znaky, vystvara counter pre dynamicku pamat
{
    int spravne = 0;
    int nespravne = 0;
    int ch;

    FILE *kluc;
    
    kluc = fopen("C:/tmp/klucik.txt","r");

    if(kluc == NULL)
    {
        nespravne++;
    }

    while(1)
    {
        ch=fgetc(kluc);
        
        if(ch==EOF)                                
        break;
        
        if(ch <= '9' && ch >= '0' || ch==' ' || ch=='\n' || ch >= 'A' && ch <= 'Z')
        {
            spravne++;                                  
            buf_kluc++;
        }
        else
        {
            nespravne++;
            
        }                             
    
    }

    
    fclose(kluc);

    
    if (fclose(kluc) != EOF)
    {
        nespravne = nespravne + 10;
    }
    
    
    return (nespravne == 0);
}


void citanie_text()      // Nacitanie textu do dynamickej pamate typ int, kontrola suborov , kontrola ci sa pamat alokovala 
{
    int i = 0;
    
    FILE *vstup;
    
    vstup = fopen("C:/tmp/text.txt","r");

    if (vstup == NULL)
    {
        printf("\nNepodarilo sa precitat subor text\n");
        exit(2);
    }

    vstup_zasobnik = (int*) malloc((buf_vstup) * sizeof(int));

    if(vstup_zasobnik == NULL)
    {
        printf("\nCHyba pri alokacii pamate\n");
        exit(13);
    }

    while( fscanf(vstup, "%d", vstup_zasobnik + i) != EOF )
    {
        i++;
        gci++;
    }


    fclose(vstup);

    if (fclose(vstup) != EOF)
    {
        exit(3);
    }

}


void citanie_key()       // Nacitanie textu do dynamickej pamate typ int a typ char, kontrola suborov , kontrola ci sa pamat alokovala 
{

    int i = 0;
    
    FILE *kluc;
    
    kluc = fopen("C:/tmp/klucik.txt","r");

    if (kluc == NULL)
    {
        printf("\nNepodarilo sa precitat subor text\n");
        exit(4);
    }

    kluc_taska = (char*) malloc((buf_kluc) * sizeof(char));
    
    kluc_zasobnik = (int*) malloc((buf_kluc) * sizeof(int));

    if(kluc_taska == NULL)
    {
        printf("\nCHyba pri alokacii pamate\n");
        exit(11);
    }

    if(kluc_zasobnik == NULL)
    {
        printf("\nCHyba pri alokacii pamate\n");
        exit(12);
    }

    while( fscanf(kluc, "%d %c", kluc_zasobnik + i, kluc_taska + i) != EOF )
    {
        i++;
    }


    fclose(kluc);

    if (fclose(kluc) != EOF)
    {
        exit(3);
    }




}


void triedenie_vystup()   // Algoritmus na pre triedenie, zapis do suboru , osetreny DEADLOCK pre zle zadany vstup , kontrola suobru 
{

    int a = 0;
    int b = 0;

    FILE *vystup;

    vystup = fopen("C:/tmp/translation.txt","w");

    if (vystup == NULL)
    {
        printf("\nNepodarilo sa vytvorit subor\n");
        exit(6);
    }

    while(1)
    {    
    
        if(vstup_zasobnik[a] != kluc_zasobnik[b])
        {
        b++;
        } 

        if(b > 100)
        {
            printf("\nSifra sa nezhoduje s klucom!!\n");
            exit(8);
        }
        
        if(vstup_zasobnik[a] == kluc_zasobnik[b])
        {
        printf("%c ",kluc_taska[b]);
        fprintf(vystup, "%c ",kluc_taska[b]);
        b = 0;
        a++;
        }

        if(a >= gci)
        break;

    }


    fclose(vystup);

    if (fclose(vystup) != EOF)
    {
        exit(9);
    }

}


int main()                // Main cast programu volanie funkcii , vypis, volanie kontroly
{

    if(kontrola_key() > 0 && kontrola_text() > 0) 
    {
        printf("Do suborov boli zadane spravne udaje\n");

    }
    else
    {
        printf("\nZadajte spravne udaje do suborova skontrolujte ich umiestnenie");
        printf("\nPre sifru XX XX X XX");
        printf("\nPre kluc XX A");
        printf("\n         XX B");
        exit(1);
    }

    citanie_key();
    citanie_text();

    printf("\nPamat vyhradena pre kluc : %i bytes\n", buf_kluc * 4 + buf_kluc);
    printf("Pamat vyhradena pre vstup: %i bytes\n\n", buf_vstup * 4);

    printf("Vystup pre vas subor bude:  ");

    triedenie_vystup();

    free(vstup_zasobnik);
    free(kluc_zasobnik);
    free(kluc_taska);

    return 0;

}
