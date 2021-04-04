#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LASTE_ARV 10
#define fail_1 "isik.txt"
#define fail_2 "isiku_lapsed.txt"

#include "prototyybid.h"
#include "abiFunktsioonid.c" //see fail siin all, sest muidu funktsioonid selles pole structidest teadlikud

/* 9. n�dala tunnit��
Lapselaste �lesanne 4 punkti
Staatiline + d�naamilinine / d�naamiline pinuga (+3 punkti)
2 struktuuri - Esimeses isiku andmed, isikukood, nimi,
teises: isikukood, lastearv, laste isikukoodid
Leida iga inimese lapselaste nimed
*/

int main(void)
{

    /***********ANDMED FAILIST STRUCTI****/
    FILE *fp = avaFail(fail_1, "r");
    int isikuid_kokku = saaRidadeArvFailis(fp);
    struct Isik *isik_ptr = loeIsikFailistStructi(fp, isikuid_kokku); //pointer isik structide algusesse
    fclose(fp);
    fp = avaFail(fail_2, "r");
    int lapsi_kokku = saaRidadeArvFailis(fp);
    struct Lapsed *laps_ptr = loeLapsedFailist(fp, lapsi_kokku); //pointer laste structide algussese (ik, laste arv, laste ikd)
    fclose(fp);
    int i;
    Stack stack;
    tootlus(stack,++isik_ptr,isikuid_kokku,laps_ptr,lapsi_kokku);
    
    return 0;
}


void **tootlus(Stack stack,Isik* isik_ptr, int isikuid_kokku, Lapsed* laps_ptr,int laste_arv)
{   /*leiab vanavanemad*/
   
    for(int a = 0; a<isikuid_kokku;a++){
    //Stack
    int vanemate_arv,lapselaste_arv;
    // Vanavanem on algne isik
    Isik* vanavanem_ptr = isik_ptr + a;
    printf("\n-Vanavanem");
    stack.vanavanem = vanavanem_ptr;//add to stack 0
    valjastaIsik(stack.vanavanem);
    
    //Leia tema lapsed
    Isik** vanem_ptrid = leiaLapsed((isik_ptr + a)->IK,isik_ptr + a, isikuid_kokku,laps_ptr,laste_arv);
    //Leia lapselapsed
    vanemate_arv = saaLasteArv(isik_ptr + a,laps_ptr,laste_arv);
    printf("\nlaste arv %d",vanemate_arv);
    // Isik **lapselapsed = (void **)malloc(sizeof(int*));
    
    printf("\n-Lapsed ");
    if(vanemate_arv == 0){
            printf("IK: %s %s %s --pole lapsi", stack.vanavanem->IK,stack.vanavanem->eesnimi,stack.vanavanem->perenimi);
             }
    for(int i = 0; i<=vanemate_arv;i++)
    {       

            stack.lapsed = calloc(1,sizeof(Isik*));
            stack.lapsed[i] = vanem_ptrid[i];
            valjastaIsik(stack.lapsed[i]);//push to stack laps
            
            
            Isik** lapselaps_ptrid = leiaLapsed(stack.lapsed[i]->IK,isik_ptr + a, isikuid_kokku,laps_ptr,laste_arv);
            //Leia lapselapsed
            lapselaste_arv = saaLasteArv(stack.lapsed[i],laps_ptr,laste_arv);
            printf("\nlapselaste arv %d",lapselaste_arv);
            // Isik **lapselapsed = (void **)malloc(sizeof(int*));
            
            
            printf("\n-Lapselapsed");
                if(lapselaste_arv == 0){
                printf("\nIK: %s  %s %s --pole lapselapsi",stack.lapsed[i]->IK, stack.lapsed[i]->eesnimi,stack.lapsed[i]->perenimi);
                }
            for(int j = 0; j<=lapselaste_arv;j++){

                stack.lapselapsed = calloc(1,sizeof(Isik*));
                stack.lapselapsed[j] = lapselaps_ptrid[j];
                valjastaIsik(stack.lapselapsed[j]); //push to stack lapselapsed
                free(stack.lapselapsed[j]);
                
            }
            free(stack.lapsed[i]);
            
    }

    free(stack.vanavanem);
    isik_ptr = isik_ptr + a;
    }
}
            

    
    
    
    
