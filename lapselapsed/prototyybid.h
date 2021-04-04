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
void valjastaIsikud(Isik* ,int );
void valjastaLapsed(Lapsed *, int );
Isik *leiaIsik(char isikukood[], Isik *, int);
Isik **leiaLapsed(char [], Isik * ,int , Lapsed *, int );
void tootlus(Isik* , int , Lapsed* ,int );
