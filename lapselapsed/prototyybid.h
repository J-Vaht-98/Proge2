typedef struct Isik
{
    char IK[50];
    char eesnimi[50];
    char perenimi[50];
} Isik;

typedef struct Lapsed{
    char vanema_IK[50];
    int laste_arv;
    char lapsed[MAX_LASTE_ARV][50];
} Lapsed;

typedef struct Stack{
    Isik* vanavanem;
    Isik** lapsed;
    Isik** lapselapsed;
    
}Stack;

FILE *avaFail(char[50], char[3]); 
int saaRidadeArvFailis(FILE*);
Isik *loeIsikFailistStructi(FILE*,int);
Lapsed *loeLapsedFailist();
void valjastaIsikud(Isik* isik_ptr,int n);
void valjastaLapsed(Lapsed *laps_ptr, int n);
Isik *leiaIsik(char isikukood[], Isik *isik_ptr, int);
Isik **leiaLapsed(char vanema_isikukood[], Isik * isik_ptr,int isikute_arv, Lapsed *laps_ptr, int laste_arv);
void **tootlus(Stack stack,Isik* isik_ptr, int isikuid_kokku, Lapsed* laps_ptr,int laste_arv);
