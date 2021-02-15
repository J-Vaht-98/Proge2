#include <stdio.h>
#include <stdlib.h>

typedef struct andmed
{
    char nimi[50];
    int huvialade_arv;
    char huvialad[50][50];
    
}andmed;

FILE *avaFail(char faili_nimi[50], char otstarve[3]){
    FILE *fp;
    fp = fopen(faili_nimi, otstarve);
    if (fp != NULL)
        return fp;
    else{
        printf("\nFaili ei saadud avada");
        exit(1);
    }
}
void kysiHuviala(char* huvi){
    printf("\nSisesta Huviala: ");
    fflush(stdin);
    scanf("%s",huvi);
}

int saaRidadeArvFailis(FILE* fp){
    /*Loeb kokku mitu rida failis on*/
    double x;
    int i = 0;
    char buffer[500];
    while(fscanf(fp,"%lf",&x) != EOF){
        fgets(buffer,500,fp);
        i++;
    }
    rewind(fp);
    return i;
}
void strLowercase(char huvi[20]){
    /*Teeb stringi lowercase-iks*/
        for(int i = 0; huvi[i]; i++){
        huvi[i] = tolower(huvi[i]);
        }
}

void valjastaHuvid(andmed h[],int n){
    /*Valjastab inimese andmed*/
    for(int i = 0;i<n;i++){
        printf("\n-----------------------------------");
        printf("\nNimi: %s\nHuvisid: %d",h[i].nimi,h[i].huvialade_arv);
        printf("\nHuvid: ");
        for(int j = 0;j<h[i].huvialade_arv;j++){
            printf("%s,",h[i].huvialad[j]);
        }
    }
}
