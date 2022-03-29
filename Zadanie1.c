//Marian Bodnar
//Zaklady programovania
//Zadanie 1


#include <stdio.h>

int main() {
    float ziadam;
    float a = 0.01, b = 0.02, c = 0.03;
    float vysledok;
    

    printf("Zadajte vysku uveru:");
    scanf("%f" , &ziadam);

    
    if (ziadam <20000 & ziadam > 0) {
        vysledok = ziadam*a;
        printf( " Prva splatka pre sumu do 20 000: %.02f\n" , vysledok );
    }
    
    else {
        
        if (ziadam >= 20000 & ziadam <49999.99) {
            vysledok = (ziadam*b)+200;
            printf("Prva splatka pre sumu do 50 000: %.02f\n" , vysledok);
            }
        else{
            
            if (ziadam >=50000 & ziadam <=150000){
                vysledok = (ziadam*c)+800;
                printf("Prva splatka pre sumu do 150 000: %.02f\n" , vysledok);
            }
            else{
                printf("Lutujeme uvedenu sumu neposkytujeme\n");
            }
        }
        }
    
    return 0;
}
