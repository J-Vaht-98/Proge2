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
    int i = 0;
    while (i < isikuid_kokku)
    {
        tootlus((isik_ptr + i), isikuid_kokku, laps_ptr, lapsi_kokku);
        i++;
    }
    return 0;
}

void tootlus(Isik *isik_ptr, int isikuid_kokku, Lapsed *laps_ptr, int laste_arv)
{ /*leiab vanavanemad ja v2ljastab need kujul:
    vanavanem
    laps
    selle lapse lapsed
    laps 2
    selle lapse lapsed jne.
*/

    //Stack
    Stack stack;
    // Vanavanem on algne isik
    stack.vanavanem = isik_ptr;
    printf("--------------------------------------");
    printf("\n-Vanavanem");
    valjastaIsik(stack.vanavanem); //add to stack 0

    //Leia tema lapsed
    stack.lapsed = leiaLapsed(isik_ptr->IK, isik_ptr, isikuid_kokku, laps_ptr, laste_arv);
    //Leia lapselapsed
    int vanemate_arv = saaLasteArv(isik_ptr, laps_ptr, laste_arv);
    printf("\nLaste arv %d", vanemate_arv);
    if (vanemate_arv == 0)
    {
        printf("Selle inimesel pole lapsi");
    }
    for (int i = 0; i < vanemate_arv; i++)
    {
        printf("\n-Lapsed");
        valjastaIsik(stack.lapsed[i]); //push to stack laps
        stack.lapselapsed = leiaLapsed(stack.lapsed[i]->IK, isik_ptr, isikuid_kokku, laps_ptr, laste_arv);
        //Leia lapselapsed
        int lapselaste_arv = saaLasteArv(stack.lapsed[i], laps_ptr, laste_arv);
        if (lapselaste_arv == 0)
        {
            printf("\nSelle inimesel pole lapselapsi");
        }
        printf("\nLapselaste arv %d", lapselaste_arv);
        printf("\nLapselapsed");
        for (int j = 0; j < lapselaste_arv; j++)
        {
            valjastaIsik(stack.lapselapsed[j]); //push to stack lapselapsed
        }
    }
    printf("--------------------------------------");
    
    
}

