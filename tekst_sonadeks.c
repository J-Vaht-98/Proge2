#include <stdio.h>
#include <string.h>


int main(void){

    FILE *fp;
    char sonad[500][30];
    char faili_nimi[40];

    printf("Sisesta faili nimi: ");
    scanf("%s",&faili_nimi);

    fp = fopen(faili_nimi, "r");

    char *token;
    double x;
    char buffer[2000];
    char sona[30];
    int i = 0;

    while (fscanf(fp, "%lf", &x) != EOF) // See scannib kuni tuleb EOF
    {
        fgets(buffer, 2000, fp); //v6tab 55 symbolit
        token = strtok(buffer, " "); //tsykkel jagab reas olevad sonad eraldi muutujatesse.
        while (token != NULL)
        {
            strcpy(sonad[i],token);
            i++;
            token = strtok(NULL, " ");
        }
        
    }
    fclose(fp);
    
    int suurus = i;
    i=0;
    while(i<suurus){
        printf("%d:\t %s\n",i,sonad[i]);
        i++;
    }
    return 0;
}

