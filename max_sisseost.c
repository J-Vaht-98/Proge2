#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int SorteeriFail(FILE *fp, double hinnad[],int kogused[]);
void bubbleSort(double massiiv[], int massiiv2[], int suurus);
void PrintArrays(double hinnad[], int kogused[],int suurus);

int main(void)
{
    FILE *fp;
    double hinnad[20];
    int kogused[20]; 
    double raha;
    int vastus = 0;
    fp = fopen("ostud.sis", "r");
    int suurus = SorteeriFail(fp,hinnad,kogused);
    fclose(fp);
    //Sorteerib saadud andmed ja valjastab
    bubbleSort(hinnad, kogused, suurus);
    PrintArrays(hinnad,kogused,suurus);

    printf("Sisesta rahasumma: ");
    scanf("%lf", &raha);
    printf("Raha on %.2lf\n", raha);

    int i=0 ;
    int rahaotsas = 0;
    while(i < suurus && rahaotsas == 0){
        while(kogused[i] > 0){
            raha = raha-hinnad[i];
            
            kogused[i]--;
            
            vastus++;
            if(raha < 0){
                raha = raha + hinnad[i];
                kogused[i]++;
                vastus--;
                rahaotsas = 1;
                break;
            }
            printf("Raha j2rgi: %.2lf\n",raha);
            
        }
        i++;
    }
    
    printf("Selle eest saaks osta %d asja\n", vastus);
    printf("Raha jargi %.2lf \n",raha);

    return 0;
}

void bubbleSort(double massiiv[], int massiiv2[], int suurus)
{
    /*Sorteerib massiivi kasvamise v kahanemise järjekorras
    Ylesande raames on vaja kaks massiivi hoida vastavuses,
    seega massiiv2 elementide järjekord muutub identselt
    */
    double temp;

    for (int samm = 0; samm < suurus - 1; ++samm)
    {
        for (int i = 0; i < suurus - samm - 1; ++i)
        {
            // Sortimisviisid: ">" = kasvav , "<" = langev
            if (massiiv[i] > massiiv[i + 1])
            {
                temp = massiiv[i];
                massiiv[i] = massiiv[i + 1];
                massiiv[i + 1] = temp;

                temp = massiiv2[i]; //Liigutab teises massiivis elemendi ringi, et nende indeksid oleks vastavad
                massiiv2[i] = massiiv2[i + 1];
                massiiv2[i + 1] = temp;
            }
        }
    }
}

int SorteeriFail(FILE *fp, double hinnad[],int kogused[])
{
    /*Funktsioon v6tab faili, ja jagab tyhikute koha pealt laiali ning eri massiividesse*/
    int i,j;
    i = 0;
    char *token;
    double x;
    double hind;
    int kogus;
    char *ptr;
    char buffer[55];

    while (fscanf(fp, "%lf", &x) != EOF) // See scannib kuni tuleb EOF
    {
        fgets(buffer, 55, fp); //v6tab 55 symbolit
        j = 0;
        token = strtok(buffer, " "); //tsykkel jagab read hinnaks ja koguseks eraldi muutujatesse.
        while (token != NULL)
        {

            if (j == 0)
            {
                printf("Nimi on %s\t", token);
            }
            if (j == 1)
            {
                hind = strtod(token, &ptr);
                printf("Hind on %.2lf\t", hind);
            }
            if (j == 2)
            {
                kogus = atoi(token);
                printf("Kogus on %d", kogus);
            }
            token = strtok(NULL, " ");
            j++;
        }
        printf("\n");
        hinnad[i] = hind;
        kogused[i] = kogus;
        i++;
    }
    return i;
}
void PrintArrays(double hinnad[], int kogused[],int suurus){
    for (int i = 0; i < suurus; i++)
    {
        printf("Hind on %.2lf\t", hinnad[i]);
        printf("Kogus on %d\n", kogused[i]);
    }
}
