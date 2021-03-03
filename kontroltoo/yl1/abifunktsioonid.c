#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int saaRidadeArvFailis(FILE* fp){
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

FILE *avaFail(char faili_nimi[50], char otstarve[3])
{

    FILE *fp;
    fp = fopen(faili_nimi, otstarve);
    if (fp != NULL)
        return fp;
    else
    {
        printf("\nFaili ei saadud avada");
        exit(1);
    }
}

int sisestaInt(){
    int n;
while (1)
{
            
            printf("\nSisesta kvalifikatsiooni piir: ");
            int i = scanf("%d",&n);
            if(i > 0){
                printf("\nSisestati %d",n);                
                break;
                
            }else{
                printf("\nPole number!");
                fflush(stdin);
            }
            
}
return n;

}



