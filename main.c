#include <stdio.h>
#include<string.h>
#include<stdbool.h>
//structure de etat
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
    if(fichierdot==NULL){perror("errur d overture de dot.dot");
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

