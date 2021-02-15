#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "abiFunktsioonid.c"
struct andmed;


/**************PROTOTYYBID*******/
int saaRidadeArvFailis(FILE* fp);
FILE *avaFail(char faili_nimi[50], char otstarve[3]);
void kysiHuviala(char*);
void loeAndmed(FILE* fp,andmed huvid[]);
void andmedFaili(FILE* fp, andmed huvid[], char huvi[20],int suurus);
void valjastaHuvid(andmed h[],int n);
void strLowercase(char huvi[20]);

int main(void){
    /*Faili lugemine*/
    FILE* fp = avaFail("F1.txt", "r");
    int suurus = saaRidadeArvFailis(fp);
    andmed huvid[suurus];
    loeAndmed(fp,huvid);
    fclose(fp);
    
    valjastaHuvid(huvid,suurus);
    
    /*Teise faili valjastamine*/
    char huvi[20];    
    kysiHuviala(huvi);  
    fp = avaFail("F2.txt","w");
    andmedFaili(fp,huvid,huvi,suurus);
    fclose(fp);
    
    return 0;
}


/*********Funktsioonid******/

void loeAndmed(FILE* fp,andmed huvid[]){
    /*Loeb failist sisse inimeste nimed ja huvialad*/
    int j;
    int i = 0;
    char buffer[1024];
    
    while(1){
        fscanf(fp,"%s",&buffer);      
        strcpy(huvid[i].nimi,buffer);  
        fscanf(fp,"%d",&j);
        huvid[i].huvialade_arv = j;
        j = 0;

        if(feof(fp))
            break;
            
        //printf("\n%s %d",huvid[i].nimi,huvid[i].huvialade_arv);
        for(j=0;j<huvid[i].huvialade_arv;j++){
            fscanf(fp,"%s",&buffer);
            strcpy(huvid[i].huvialad[j],buffer);
            //printf(" %s",huvid[i].huvialad[j]);
        }
        i++;
        

    }
}
void andmedFaili(FILE* fp, andmed huvid[], char huvi[20],int suurus){
    /*Paneb alast huvitatud nimed faili*/
    int on_huvi = 0;
    printf("\n%s huvitab järgmisi inimesi: ",huvi);
    strLowercase(huvi);
    for(int i = 0;i<suurus;i++){
        for(int j = 0;j<huvid[i].huvialade_arv;j++){
            strLowercase(huvid[i].huvialad[j]);
            if(strcmp(huvi, huvid[i].huvialad[j])==0 ){
                //kirjuta faili
                on_huvi = 1;
                fputs(huvid[i].nimi,fp);
                fputc('\n',fp);
                printf("\n%s",huvid[i].nimi);
            }
        }
    }
    if(on_huvi == 0){
        printf("\nAlast huvitatuid ei leidu");
    }
}




