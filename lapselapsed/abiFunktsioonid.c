int saaRidadeArvFailis(FILE *fp)
{
    double x;
    int i = 0;
    char buffer[500];
    while (fscanf(fp, "%lf", &x) != EOF)
    {
        fgets(buffer, 500, fp);
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
void valjastaIsikud(Isik *isik_ptr, int n)
{
    printf("\nIsikud:\n");
    for (int i = 0; i < n; ++i)
        printf("Ik: %s\tNimi: %s %s\n", (isik_ptr + i)->IK, (isik_ptr + i)->eesnimi, (isik_ptr + i)->perenimi);
}
void valjastaLapsed(Lapsed *laps_ptr, int n)
{
    printf("Lapsed:\n");
    for (int i = 0; i < n; ++i)
    {
        printf("\nIk: %s Lapsi: %d", (laps_ptr + i)->vanema_IK, (laps_ptr + i)->laste_arv, (laps_ptr + i)->lapsed);
        for (int j = 0; j < (laps_ptr + i)->laste_arv; j++)
        {
            printf("\n\tlaps: %s", (laps_ptr + i)->lapsed[j]);
        }
    }
}
void valjastaIsik(Isik* ptr){
    printf("\n---Ik: %s  Nimi: %s %s", ptr->IK, ptr->eesnimi, ptr->perenimi);
    
}

Isik *loeIsikFailistStructi(FILE *fp, int n)
{
    /*Tagastab pointer structide massiivi algusesse*/
    struct Isik *ptr;
    ptr = (struct Isik *)calloc(n, sizeof(struct Isik)); //teeb n isiku structi jaoks m2lu
    int i = 0;
    while (1)
    {
        if (feof(fp))
        {
            break;
        }
        fscanf(fp, "%s %s %s", (ptr + i)->IK, (ptr + i)->eesnimi, (ptr + i)->perenimi);
        i++;
    }

    printf("Kokku %d isikut", n);
    valjastaIsikud(ptr, n);
    return ptr;
}

Lapsed *loeLapsedFailist(FILE *fp, int n)

{

    struct Lapsed *ptr;
    ptr = (struct Lapsed *)malloc(n * sizeof(struct Lapsed));
    int i = 0;
    while (1)
    {

        if (feof(fp))
        {
            break;
        }

        fscanf(fp, "%s %d", (ptr + i)->vanema_IK, &(ptr + i)->laste_arv);

        for (int j = 0; j < (ptr + i)->laste_arv; j++)
        {
            fscanf(fp, "%s", (ptr + i)->lapsed[j]);
        }
        i++;
    }
    valjastaLapsed(ptr, n);
    return ptr;
}

Isik *leiaIsik(char isikukood[], Isik *isik_ptr, int n)
{
    /*Otsib l2bi isikute massiivi ja leiab vastava isikukoodiga isik structile pointeri
    *Kui isikut pole olemas siis tagastab NULL
    */
    int i;
    int s = 0;
    for (i = 0; i < n; i++)
    {
        if (strcmp((isik_ptr + i)->IK, isikukood) == 0)
        {
            return (isik_ptr + i);
        }
    }
    return NULL;
}

Isik **leiaLapsed(char vanema_isikukood[], Isik * isik_ptr,int isikute_arv, Lapsed *laps_ptr, int laste_arv)
{ /*Tagastab pointerite massiiv inimese laste Isik structidele , kui lapsi pole, siis NULL */


    /*Leia isiku lapsed*/
    Isik **rtrn_ptr = NULL;

    for (int i = 0; i < laste_arv; i++)
    {
        if (strcmp((laps_ptr + i)->vanema_IK, vanema_isikukood) == 0)
        {
            
            rtrn_ptr = (Isik **)calloc((laps_ptr + i)->laste_arv, sizeof(Isik*));
            for(int j = 0; j< (laps_ptr + i)->laste_arv;j++){
                rtrn_ptr[j] = malloc(sizeof(Isik*));
                rtrn_ptr[j] = leiaIsik((laps_ptr + i)->lapsed[j],isik_ptr,isikute_arv);// leiab vastava isik structi
            }
            break;
        }
    }
    return rtrn_ptr;


}
int saaLasteArv(Isik* isik_ptr, Lapsed* laps_ptr, int laste_arv)
{
    //Leia isiku isikoodile vastav laste arv
    for(int i = 0;i<laste_arv;i++)
    {
        if(strcmp(isik_ptr->IK, (laps_ptr + i)->vanema_IK) == 0){
            return ((laps_ptr + i)-> laste_arv);
        }
    }
    return 0;
}
