#include <stdio.h>
#include<string.h>
#include<stdbool.h>
//structure de etat
int LireChoixEntre(int from, int to){
    int choix;
    do{
        printf("Entrez un choix entre %d et %d : \n", from,to);
    scanf("%d",&choix);
    }while(choix<from || choix>to);
    return choix;
}
typedef struct 
{
    int numetat;
    bool isini;
    bool isfin;
}etats;
//structure de transition 
typedef struct 
{
    etats etatpre;//peut etre pointeur
    etats etasuiv;//peut etre pointeur
    char symbole ;
}transitions;
//structure d autoumate
typedef struct 
{
    transitions *transition;
    int nombtransition ;
    etats *etat;
    int nombetat;
    char *alphabet;
    int nombalphabet;
}automates;
//marque un etat comme initial 
void etat_initial(automates *automate,int numdetat){
    for(int i =0;i=automate->nombetat;i++){
        if(automate->etat[i].numetat==numdetat){
            automate->etat->isini=true;
        }
    }
}
//marque un etat comme final
void etat_final(automates *automate,int numdetat){
    for(int i =0;i=automate->nombetat;i++){
        if(automate->etat[i].numetat==numdetat){
            automate->etat->isfin=true;
        }
    }
}
//fonction de lecture et stackage dans la memoire
void lireautomate(automates *automate ,const char *nomdefichier){//ici l utilisateur peut entre le nom de sont fichier et ne peut pas etre chager
    FILE*fichierdot =fopen(nomdefichier,"r");
    if(fichierdot==NULL){perror("erreur d overture de dot.dot");
    return;}
    char ligne[256];
    int nombdtetat;
    int nombdetransition;
    while(fgets(ligne,sizeof(ligne),fichierdot)){
            if (strstr(ligne,"shape = circle")){
                char *p=strchr(ligne,';');
                p++;
                while(*p!=';'&& *p!='\0'){
                    
                    nombdtetat++;
                    p=strchr(p,',');
                    p++;
                }
            }
            else if(strstr(ligne,"->")){
                nombdetransition++;
            }
    }
}
void _ShowTransaction(automates * automate )
{
    for(int i=0;i<automate->nombtransition;i++)
    {
        printf("%d --> %d \n",((automate->transition+i)->etatpre.numetat),((automate->transition+i)->etasuiv.numetat));
    }
}
int GetDispChoice (){
    printf(" Entrez votre choix d'affichage \n");
    printf("_________________________________");
    printf(" 1)Afficher les transitions \n");
    printf(" 2)Afficher les etats\n");
    printf(" 3)Afficher les alphabets\n");
    printf("4) Quitter");
    return LireChoixEntre(1,4);
}
void afficherAutomate(automates * automate ){
    printf("Entrez votre choix d'affichage \n");
    int Choix=GetDispChoice();

    switch(Choix){
        case 1:
        _ShowTransaction(automate);
        GetDispChoice();
        break;
        case 2:
         _ShowEtats();
        GetDispChoice();
        break;
        case 3:
         _ShowAlphabet();
        GetDispChoice();
        break;
        case 4:
         break;
    }

}
