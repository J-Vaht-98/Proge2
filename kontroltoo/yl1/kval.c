/*Ylesanne 2 haldusyksuste kohta*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "funktsioonid.h"
#include "abifunktsioonid.c"

int main(void){
    
    FILE* fp = avaFail("voistlejad.txt","r");
    int voistlejate_arv = saaRidadeArvFailis(fp);
    voistleja ajad[voistlejate_arv];
    
    loeAndmed(fp,ajad);
    fclose(fp);
    int piir = sisestaInt();
    leiaKvalifitseerunud(ajad, voistlejate_arv,piir);
    
    return 0;
}

void loeAndmed(FILE *fp, voistleja voistlejad[])
{
    int i = 0;
    int x;
    float a;
    char buf[500];
    while (1) // See scannib kuni tuleb EOF
    {
        if (feof(fp))
        {
            break;
        }
        fscanf(fp,"%s",&buf,&voistlejad[i].kaugushupe);
        strcpy(voistlejad[i].nimi,buf);
        printf("\nnimi:%s",voistlejad[i].nimi); 
        
        fscanf(fp,"%s",&buf);
        voistlejad[i].kaugushupe = strtof(buf,NULL);
        printf("\n\tKaugushupe:%lf",voistlejad[i].kaugushupe); 
        
        fscanf(fp,"%s",&buf);
        voistlejad[i].odavise = strtof(buf,NULL);
        printf("\n\tOdavise:%lf",voistlejad[i].odavise); 
        
        fscanf(fp,"%s",&buf);
        voistlejad[i].kakssada = strtof(buf,NULL);
        printf("\n\t200m:%lf",voistlejad[i].kakssada); 
        
        fscanf(fp,"%s",&buf);
        voistlejad[i].kettaheide = strtof(buf,NULL);
        printf("\n\tKettaheide:%lf",voistlejad[i].kettaheide); 
        
        fscanf(fp,"%s",&buf);
        voistlejad[i].tuhatviisada = strtof(buf,NULL);
        printf("\n\t1500m:%lf",voistlejad[i].tuhatviisada); 
        
        i++;
        
    }
}
void leiaKvalifitseerunud(voistleja voistlejad[], int n, int piir){
    for(int i=0;i<n;i++){
        float kaugushupe = pow((0.188807*(100*voistlejad[i].kaugushupe-210)),1.41);
        float odavise = pow((15.9803*(1*voistlejad[i].odavise-3.8)),1.04);
        float kakssada = pow((4.99087*(42.5 - voistlejad[i].kakssada)),1.81);
        float kettaheide = pow((12.3311*(voistlejad[i].kettaheide - 3)),1.10);
        float tuhatviisada = pow((0.02883*(535 - voistlejad[i].tuhatviisada)),1.88);
        
        float punktid = kaugushupe + odavise + kakssada + kettaheide + tuhatviisada;
        
        voistlejad[i].punktid = punktid;
        
        if(punktid > piir){
            printf("\n%s -  punkte\t %lf",voistlejad[i].nimi,voistlejad[i].punktid);
        }
    }
    
}
