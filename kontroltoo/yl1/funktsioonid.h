typedef struct voistleja{
    char nimi[50];
    float kaugushupe;
    float odavise;
    float kakssada;
    float kettaheide;
    float tuhatviisada;
    float punktid;
    
}voistleja;



int saaRidadeArvFailis(FILE*);
FILE *avaFail(char[50], char [3]);
int sisestaInt();
void leiaKvalifitseerunud(voistleja[], int , int );
void loeAndmed(FILE *, voistleja[]);
