#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <io.h>
#include <graphics.h>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**some-fcts**/
void deconnecter();
void menu();
void SetColor(int);
void gotoxy(int,int);
void rectangle();
void rectangle0();
void rectangle1();
void rectangle2();
void rectangle3();
void rectanglemenu1();
void rectanglemenu2();
void rectanglemenu3();
void rectanglemenu4();
void rectanglemenu5();
void rectanglemenu6();
void rectanglemenu7();
void rectanglemenu8();
void rectanglemenu9();
void image();

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**Ecran1**/
void ecran1(void)
{
    SetColor(1);
    gotoxy(48,10);
    printf("BIENVENUE AU MEDICABINET\n");
    gotoxy(40,12);
    printf("<pour se connecter appuyer sur un button>");
    _getch();
    system("cls");
}

/**Logo**/
void lolgo(void)
{
    printf("");
    printf("*MEDICABINET*");
    printf("");
}

/**Se Con**/
void connecter(void)
{
    int i=1;
    int j=0;
    char ID[10];
    char MDP[20];
    char ID_cor[10]= "GI12022";
    char MDP_cor[20]= "GI123456789";
    do
    {
        j=0;
        system("cls");
        SetColor(15);
        rectangle0();
        SetColor(1);
        gotoxy(38,8);
        lolgo();
        SetColor(15);
        gotoxy(38,9);
        printf("VEULLIEZ ENTER VOS");
        gotoxy(38,10);
        printf("INFOS POUR SE CONNECTER\n");
        gotoxy(40,12);
        SetColor(7);
        printf("entrez votre ID\n");
        gotoxy(40,13);
        SetColor(10);
        //scanf("%s",&ID);
        fflush(stdin);
        gets(ID);
        SetColor(15);
        gotoxy(40,14);
        printf("entrez votre MDP\n");
        SetColor(10);
        gotoxy(40,15);
        //scanf("%s",&MDP);
        do
        {
            MDP[j]= _getch();;
            printf("*");
            j++;
        }
        while(MDP[j-1]!='\r');
        MDP[j-1]='\0';
        if(strcmp(ID,ID_cor)==0 && strcmp(MDP,MDP_cor)==0)
        {
            SetColor(9);
            gotoxy(38,17);
            printf("connexion avec succee...\n");
            gotoxy(38,18);
            printf("BIENVENUE AU MEDICABINET");
            _getch();
            menu();
        }
        else
        {
            SetColor(6);
            gotoxy(38,17);
            printf("probleme de connexion svp reentrer");
            gotoxy(38,18);
            printf("votre informations...");
            i++;
            _getch();
        }
    }
    while(i<=3);
    if(i>3)
    {
        SetColor(4);
        gotoxy(38,19);
        printf("!!!vous avez essayer plusieurs fois");
        gotoxy(38,20);
        printf("vous ne pouvez pas entrer!!!");
        _getch();
        deconnecter();
    }
}

/**Decon**/
void deconnecter(void)
{
    system("cls");
    system("COLOR 90");
    gotoxy(50,10);
    lolgo();
    gotoxy(32,12);
    printf(">>MRC POUR LA VISITE, AU REVOIR ET A LA PROCHAINE FOIS<<");
    _getch();
    gotoxy(0,24);
    exit(0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**Main**/
main(void)
{
    image();
    rectangle();
    SetColor(9);
    ecran1();
    connecter();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**Declaration des structures**/
typedef struct dt
{
    int jour,mois,annee;
} date;

typedef struct rv
{
    char Date_RV[12];
} RDV;

typedef struct Dg
{
    char Dig[200];

} Diag;

typedef struct pt
{
    char nom[20],prenom[20],CIN[10],tele[12];
    date consultation;
    RDV DTR;
    Diag dig;
    struct pt *next;

} *patient;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**Declaration des fonctions**/

/**Ajout**/
void ajouterpatient(patient &p)
{
    gotoxy(38,2);
    SetColor(9);
    printf("AJOUTER UN PATIENT");
    SetColor(15);
    rectangle3();

    char NOM[20],PRENOM[20],Cin[10],TELE[12];
    int J,M,A;
    gotoxy(40,4);
    printf("NOM : ");
    SetColor(1);
    gotoxy(40,5);
    fflush(stdin);
    gets(NOM);
    //scanf(" %s",&NOM);
    SetColor(15);
    gotoxy(40,7);
    printf("PRENOM : ");
    SetColor(1);
    gotoxy(40,8);
    fflush(stdin);
    gets(PRENOM);
    //scanf(" %s",&PRENOM);
    SetColor(15);
    gotoxy(40,10);
    printf("CIN : ");
    gotoxy(40,11);
    SetColor(1);
    fflush(stdin);
    gets(Cin);
    //scanf(" %s",&Cin);
    if(Cin[0] != toupper(Cin[0]))
    {
        Cin[0]=toupper(Cin[0]);
    }
    if(Cin[1] != toupper(Cin[1]))
    {
        Cin[1]=toupper(Cin[1]);
    }
    gotoxy(40,13);
    SetColor(15);
    printf("TELE : ");
    SetColor(1);
    gotoxy(40,14);
    scanf(" %s",&TELE);
    gotoxy(40,16);
    SetColor(15);
    printf("Date de consultation : \n");
    gotoxy(40,17);
    SetColor(15);
    printf("JOUR : ");
    SetColor(1);
    gotoxy(40,18);
    scanf("%d",&J);
    gotoxy(50,17);
    SetColor(15);
    printf("MOIS : ");
    SetColor(1);
    gotoxy(50,18);
    scanf("%d",&M);
    gotoxy(60,17);
    SetColor(15);
    printf("ANNEE : ");
    SetColor(1);
    gotoxy(60,18);
    scanf("%d",&A);
    patient nouv=(struct pt *) malloc(sizeof(struct pt));
    strcpy(nouv-> nom,NOM);
    strcpy(nouv-> prenom,PRENOM);
    strcpy(nouv-> CIN,Cin);
    strcpy(nouv-> tele,TELE);
    nouv->consultation.jour=J;
    nouv->consultation.mois=M;
    nouv->consultation.annee=A;
    nouv->next=NULL;
    if(p==NULL)
    {
        p=nouv;
    }
    else
    {
        patient q=p;
        while(q->next != NULL)
            q=q->next;
        q->next=nouv;
    }

    SetColor(2);
    gotoxy(38,20);
    printf("Ajouter par succee... \n");
    SetColor(15);
    gotoxy(38,21);
    printf("Appuyez sur un button pour revenir");
    SetColor(15);
    gotoxy(38,22);
    printf("au menu \n");
}

/**Chercher**/
void chercherpatient(patient &p)
{
    gotoxy(40,3);
    SetColor(9);
    printf("CHERCHER UN PATIENT");
    SetColor(15);
    char Cin[10];
    int i=0;

    if(p==NULL)
    {
        gotoxy(40,5);
        SetColor(4);
        printf("Veuillez remplir d'abord la liste des patients\n");

    }

    else
    {
        gotoxy(40,5);
        SetColor(15);
        printf("Veuillez entrer le CIN du patient : ");
        gotoxy(40,6);
        SetColor(12);
        fflush(stdin);
        gets(Cin);
        //scanf(" %s",&Cin);
        if(Cin[0] != toupper(Cin[0]))
        {
            Cin[0]=toupper(Cin[0]);
        }
        if(Cin[1] != toupper(Cin[1]))
        {
            Cin[1]=toupper(Cin[1]);
        }
        patient q=p;
        while(q!=NULL)
        {
            if(strcmp(q->CIN,Cin)==0)
            {
                i++;
                break;

            }
            q=q->next;
        }
        if(i == 0)
        {
            gotoxy(40,8);
            SetColor(4);
            printf("Patient n'est pas trouve !!");
            gotoxy(40,9);
            SetColor(4);
            printf("Veuillez verifier le CIN du patient svp\n");
        }
        else
        {
            gotoxy(40,8);
            SetColor(15);
            printf("Les informations du patient cherche : \n");
            gotoxy(40,9);
            SetColor(15);
            printf("NOM : ");
            gotoxy(65,9);
            SetColor(12);
            printf(" %s",q->nom);
            gotoxy(40,10);
            SetColor(15);
            printf("PRENOM : ");
            gotoxy(65,10);
            SetColor(12);
            printf(" %s",q->prenom);
            gotoxy(40,11);
            SetColor(15);
            printf("CIN : ");
            gotoxy(65,11);
            SetColor(12);
            printf(" %s\n",q->CIN);
            gotoxy(40,12);
            SetColor(15);
            printf("TELE : ");
            gotoxy(65,12);
            SetColor(12);
            printf(" %s\n",q->tele);
            gotoxy(40,13);
            SetColor(15);
            printf("Diag : ");
            gotoxy(65,13);
            SetColor(12);
            printf(" %s\n",q->dig.Dig);
            gotoxy(40,14);
            SetColor(15);
            printf("Date de consultation : ");
            gotoxy(65,14);
            SetColor(12);
            printf(" %d/%d/%d",q->consultation.jour,q->consultation.mois,q->consultation.annee);
            printf("\n");
        }
    }
    SetColor(15);
    gotoxy(40,16);
    printf("Appuyez sur un button pour revenir");
    SetColor(15);
    gotoxy(40,17);
    printf("au menu \n");
}


/**Suppression**/
void supprimerpatient(patient &p)
{
    gotoxy(40,3);
    SetColor(9);
    printf("SUPPRIMER UN PATIENT");
    SetColor(15);
    char Cin[10];
    int i=0,j=0;
    if(p==NULL)
    {
        gotoxy(40,5);
        SetColor(4);
        printf("Veuillez remplir d'abord la liste des patients\n");

    }

    else
    {
        gotoxy(40,5);
        SetColor(15);
        printf("Veuillez entrer le CIN du patient que vous voulez supprimer : ");
        gotoxy(40,6);
        SetColor(4);
        fflush(stdin);
        gets(Cin);
        //scanf(" %s",&Cin);
        if(Cin[0] != toupper(Cin[0]))
        {
            Cin[0]=toupper(Cin[0]);
        }
        if(Cin[1] != toupper(Cin[1]))
        {
            Cin[1]=toupper(Cin[1]);
        }
        patient q=p;
        patient k=p;

        if(strcmp(q->CIN,Cin)== 0  && i==0)
        {
            j++;
            p=p->next;
            free(q);
        }
        i++;
        q=q->next;
        while(q != NULL)
        {
            if(strcmp(q->CIN,Cin)==0)
            {
                j++;
                k->next=q->next;
                q->next=NULL;
                free(q);
                break;

            }
            q=q->next;
            k=k->next;

        }
        if(j == 0)
        {
            gotoxy(40,7);
            SetColor(4);
            printf("Suppression n'est pas effectuee!!");
            gotoxy(40,8);
            SetColor(4);
            printf("Veuillez verifier le CIN du patient svp");
        }
        else
        {
            gotoxy(40,7);
            SetColor(4);
            printf("Suppression effectuee");
        }

    }

    SetColor(15);
    gotoxy(40,9);
    printf("Appuyez sur un button pour revenir");
    SetColor(15);
    gotoxy(40,10);
    printf("au menu");
}


/**PAYER**/
int paiement()
{
    gotoxy(57,3);
    SetColor(9);
    printf("-PAIMENT-");
    SetColor(15);
    int choix,C=150,E=200,R=250,ER=450;
    gotoxy(48,20);
    SetColor(15);
    printf("Veuillez entrer une tache : \n");
    SetColor(15);
    rectanglemenu1();
    gotoxy(15,6);
    SetColor(15);
    printf("Consultation");
    gotoxy(20,7);
    printf("(1)");
    rectanglemenu2();
    gotoxy(43,6);
    SetColor(15);
    printf("Ecographie");
    gotoxy(46,7);
    printf("(2)");
    rectanglemenu3();
    gotoxy(70,6);
    printf("Radio");
    gotoxy(71,7);
    printf("(3)");
    rectanglemenu4();
    gotoxy(91,6);
    SetColor(15);
    printf("Ecographie + Radio\n");
    gotoxy(98,7);
    printf("(4)");
    SetColor(12);
    rectanglemenu7();
    gotoxy(50,14);
    printf("Retour Au Menu Principale");
    gotoxy(61,15);
    printf("(5)");
    SetColor(15);
    rectangle2();
    gotoxy(44,22);
    scanf("%d",&choix);
    switch(choix)
    {
    case 1 :
        gotoxy(48,25);
        SetColor(4);
        return C;
        break;
    case 2 :
        gotoxy(48,25);
        SetColor(4);
        return E;
        break;
    case 3 :
        gotoxy(48,25);
        SetColor(4);
        return R;
        break;
    case 4 :
        gotoxy(48,25);
        SetColor(4);
        return ER;
        break;
    case 5 :
            menu();
        break;
    default :
        gotoxy(48,25);
        SetColor(4);
        printf("OPERATION NON VALIDE !!! \n");
        break;
    }
    SetColor(15);
    gotoxy(0,28);
    printf("\n");
    system("pause");
    system("cls");
}

/**DIAG**/
void diagnostique(patient &p)
{
    gotoxy(40,3);
    SetColor(9);
    printf("AJOUTER UN DIAGNOSTIQUE");
    SetColor(15);
    char Cin[10],dg[200];
    int i=0;
    if(p==NULL)
    {
        gotoxy(40,5);
        SetColor(4);
        printf("Veuillez remplir d'abord la liste des patients\n");

    }
    else
    {
        patient q=p;
        gotoxy(40,5);
        SetColor(15);
        printf("Veuillez entrer le CIN du patient : ");
        gotoxy(40,6);
        SetColor(4);
        fflush(stdin);
        gets(Cin);
        //scanf(" %s",&Cin);
        if(Cin[0] != toupper(Cin[0]))
        {
            Cin[0]=toupper(Cin[0]);
        }
        if(Cin[1] != toupper(Cin[1]))
        {
            Cin[1]=toupper(Cin[1]);
        }
        while(q!=NULL)
        {
            if(strcmp(q->CIN,Cin)==0)
            {
                i++;
                break;
            }
            q=q->next;
        }
        if(i == 0)
        {
            gotoxy(40,7);
            SetColor(4);
            printf("Impossible de trouver le patient!!!");
            gotoxy(40,8);
            SetColor(4);
            printf("Veuillez verifier le CIN svp\n");
        }
        else
        {
            gotoxy(40,7);
            SetColor(15);
            printf("Diagnostique : ");
            gotoxy(40,8);
            SetColor(4);
            fflush(stdin);
            gets(dg);

            while(q!=NULL)
            {
                if(strcmp(q->CIN,Cin)==0)
                {
                    strcpy(q->dig.Dig,dg);
                    break;
                }
                q=q->next;
            }
            gotoxy(40,9);
            SetColor(2);
            printf("Diagnostique ajoute avec succes\n");

        }
    }
    SetColor(15);
    gotoxy(40,11);
    printf("Appuyez sur un button pour revenir");
    SetColor(15);
    gotoxy(40,12);
    printf("au menu \n");
}

/**Affichagesss**/
void afficherpatients(FILE *lp)
{
    gotoxy(3,5);
    SetColor(9);
    printf("AFFICHAGE DES PATIENTS\n");
    SetColor(15);
    char buff[256];
    lp=fopen("C:\\Desktop\\MEDICABINET\\PATIENTS FINAL.txt","r");
    if(lp==NULL)
    {
        gotoxy(40,7);
        SetColor(4);
        printf("Fichier introuvable!!!");
        exit(1);
    }
    while(!feof(lp))
    {
        SetColor(15);
        fgets(buff,256,lp);
        printf(" %s",buff);
    }
    fclose(lp);
    _getch();
}

/**ajout_RDV**/
void ajouterRDV(patient &p,FILE *lp)
{
    SetColor(9);
    printf("AJOUT DES RDV\n");
    SetColor(15);
    char Cin[10], DT_R[12],buff[50],ON[4];
    int i=0,j,k;

    if(p==NULL)
    {
        gotoxy(3,6);
        SetColor(4);
        printf("Veuillez remplir d'abord la liste des patients\n");

    }
    else
    {
        do
        {
            j=0;
            SetColor(15);
            printf("Veuillez entrer la date du RDV sous la forme (jj/mm/aaaa) : \n");
            SetColor(12);
            fflush(stdin);
            gets(DT_R);
            //scanf(" %s",&DT_R);
            lp=fopen("C:\\Desktop\\MEDICABINET\\PATIENTS FINAL.txt","r");
            if(lp==NULL)
            {
                SetColor(4);
                printf("Fichier introuvable!!");
                exit(1);
            }
            while(!feof(lp))
            {
                fgets(buff,24,lp);
                if(strstr(buff,DT_R))
                {
                    j++;
                }
            }
            fclose(lp);
            SetColor(9);
            printf("Le nombre des rendez-vous reserve a ce jour est : %d\n",j);
            printf("Voulez-vous changer le RDV ? (OUI/NON)\n");
            SetColor(12);
            fflush(stdin);
            gets(ON);
            //scanf(" %s",&ON);
            for(k=0; k<3; k++)
                ON[k]= toupper(ON[k]);

        }
        while( strcmp(ON,"OUI") == 0);
        patient q=p;
        SetColor(15);
        printf("Veuillez entrer le CIN du patient : \n");
        SetColor(12);
        fflush(stdin);
        gets(Cin);
        //scanf(" %s",&Cin);
        if(Cin[0] != toupper(Cin[0]))
        {
            Cin[0]=toupper(Cin[0]);
        }
        if(Cin[1] != toupper(Cin[1]))
        {
            Cin[1]=toupper(Cin[1]);
        }
        while(q!=NULL)
        {
            if(strcmp(q->CIN,Cin)==0)
            {
                i++;
                break;
            }
            q=q->next;
        }
        if(i == 0){
            printf("\nImpossible de trouver le patient!!!\nVeuillez verifier le CIN svp\n");
        }
        else
        {
            while(q!=NULL)
            {
                if(strcmp(q->CIN,Cin)==0)
                {
                    strcpy( q-> DTR.Date_RV,DT_R);

                    break;
                }
                q=q->next;
            }
            SetColor(2);
            printf("\nRDV ajoutee avec succes\n");
        }
    }
}

/**AfficheRDV**/
void afficherRDV(FILE *lp)
{
    gotoxy(40,2);
    SetColor(9);
    printf("AFFICHGE DES RDV DU JOUR");
    SetColor(15);
    char DT[10],TT[256],buff[256];
    int i=0;
    gotoxy(40,3);
    SetColor(15);
    printf("Veuillez entrer la date du jour de cette forme (jj/mm/aaaa) : ");
    gotoxy(40,4);
    SetColor(2);
    fflush(stdin);
    gets(DT);
    //scanf(" %s",&DT);
    lp=fopen("C:\\Desktop\\MEDICABINET\\PATIENTS FINAL.txt","r");
    if(lp==NULL)
    {
        gotoxy(40,5);
        SetColor(4);
        printf("Fichier introuvable!!");
        exit(1);
    }
    while(!feof(lp))
    {
        SetColor(15);
        fgets(buff,22,lp);
        fgets(TT,256,lp);
        if(strstr(buff,DT))
        {
            i++;
            printf(" %s",TT);
        }
    }
    if(i==0)
        SetColor(4);gotoxy(40,6);
    printf("Pas de RDV dans ce jour");
    fclose(lp);
}

/**ENREGISTRER**/
void enregistrer(patient &p,FILE *ep,FILE *lp)
{
    gotoxy(40,3);
    SetColor(9);
    printf("ENREGISTREMENT");
    SetColor(15);
    patient q=p;
    char buff[256];
    ep=fopen("C:\\Desktop\\MEDICABINET\\SECOND TRY.txt","w");

    if(ep==NULL)
    {
        gotoxy(40,5);
        SetColor(4);
        printf("Fichier introuvable!!!\n");
        gotoxy(40,6);
        SetColor(4);
        printf("Enregistrement impossible\n");
        exit(1);
    }

    while(q!=NULL)
    {
        gotoxy(3,3);
        SetColor(15);
        fprintf(ep," Date RDV : %s    \tCIN : %s      \tNom: %s      \tPrenom : %s      \tTelephone : %s      \tDate de consultation : %d/%d/%d      \tDiagnostique : %s  ",q->DTR.Date_RV,q->CIN,q->nom,q->prenom,q->tele,q->consultation.jour,q->consultation.mois,q->consultation.annee,q->dig.Dig);
        fprintf(ep,"\n--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        q=q->next;
    }
    fclose(ep);

    ep=fopen("C:\\Desktop\\MEDICABINET\\SECOND TRY.txt","r");
    lp=fopen("C:\\Desktop\\MEDICABINET\\PATIENTS FINAL.txt","a");
    if(ep==NULL)
    {
        gotoxy(40,7);
        SetColor(4);
        printf("Fichier introuvable!!!\n");
        gotoxy(40,8);
        SetColor(4);
        printf("Enregistrement impossible\n");
        exit(1);
    }
    if(lp==NULL)
    {
        gotoxy(40,7);
        SetColor(4);
        printf("Fichier introuvable!!!\n");
        gotoxy(40,8);
        SetColor(4);
        printf("Enregistrement impossible\n");
        exit(2);
    }

    while(!feof(ep))
    {
        SetColor(15);
        fgets(buff,256,ep);
        fprintf(lp,"%s",buff);
    }
    gotoxy(40,8);
    SetColor(4);
    printf("Enregistrement effectuee\n");
    fclose(lp);
    fclose(ep);

}

/**QUITTER**/
void quitter(patient &p,FILE *ep,FILE *lp)
{
    gotoxy(40,4);
    printf("QUITTER");
    int k;
    char ON[4];
    gotoxy(40,5);
    SetColor(4);
    printf("Voulez vous enregistrer votre travail avant de QUITTER? (OUI/NON) : ");
    gotoxy(40,7);
    SetColor(4);
    fflush(stdin);
    gets(ON);
    //scanf(" %s",&ON);
    for(k=0; k<3; k++)
        ON[k]= toupper(ON[k]);
    if(strcmp(ON,"OUI") == 0)
    {
        enregistrer(p,ep,lp);
        _getch();
        deconnecter();
    }
    else
        deconnecter();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**Menu**/
void menu(void)
{
    int choose, choix;
    patient P=NULL;
    FILE *ep=NULL;
    FILE *lp=NULL;
M:
    do
    {
        system("cls");
        SetColor(13);
        gotoxy(55,2);
        lolgo();
        gotoxy(52,3);
        printf("Soyez Les Bienvenue\n");
        gotoxy(48,20);
        printf("Veuillez choisir une tache: \n");
        rectangle2();
        SetColor(15);
        rectanglemenu1();
        gotoxy(13,6);
        printf("Gerer Les Patient");
        gotoxy(20,7);
        printf("(1)");
        rectanglemenu2();
        gotoxy(36,6);
        printf("Gerer Les Diagnostiques");
        gotoxy(46,7);
        printf("(2)");
        rectanglemenu3();
        gotoxy(64,6);
        printf("Gerer Les Paiments");
        gotoxy(73,7);
        printf("(3)");
        rectanglemenu4();
        gotoxy(93,6);
        printf("Gerer Les RDV");
        gotoxy(98,7);
        printf("(4)");
        SetColor(10);
        rectanglemenu5();
        gotoxy(42,14);
        printf("Enregistrer");
        gotoxy(46,15);
        printf("(5)");
        SetColor(12);
        rectanglemenu6();
        gotoxy(73,14);
        printf("Quitter");
        gotoxy(75,15);
        printf("(6)");
        SetColor(15);
        gotoxy(44,22);
        scanf("%d",&choose);
        system("cls");
        switch(choose)
        {
        case 1 :
        {
            do
            {
                SetColor(9);
                gotoxy(53,4);
                printf("-GERER PATIENT-");
                SetColor(15);
                rectanglemenu1();
                gotoxy(12,6);
                printf("Ajouter un patient");
                gotoxy(20,7);
                printf("(1)");
                rectanglemenu2();
                gotoxy(38,6);
                printf("Chercher un patient");
                gotoxy(46,7);
                printf("(2)");
                rectanglemenu3();
                gotoxy(64,6);
                printf("Supprimer un patient");
                gotoxy(73,7);
                printf("(3)");
                rectanglemenu4();
                gotoxy(89,6);
                printf("Afficher les patients");
                gotoxy(98,7);
                printf("(4)");
                SetColor(12);
                rectanglemenu7();
                gotoxy(50,14);
                printf("Retour Au Menu Principale");
                gotoxy(61,15);
                printf("(5)");
                SetColor(9);
                gotoxy(48,20);
                printf("Veuillez choisir une tache: \n");
                rectangle2();
                SetColor(15);
                gotoxy(44,22);
                scanf("%d",&choix);
                system("cls");
                switch(choix)
                {
                case 1 :
                {
                    ajouterpatient(P);
                }
                break;
                case 2 :
                {
                    chercherpatient(P);
                }
                break;
                case 3 :
                {
                    supprimerpatient(P);
                }
                break;
                case 4 :
                {
                    afficherpatients(lp);
                }
                break;
                case 5 :
                {
                    goto M;
                }
                break;
                default :
                    SetColor(4);
                    gotoxy(32,12);
                    printf("CHOIX NON VALIDE, VEUILLEZ ENTRER UN NBR ENTRE 1 ET 5\n");
                    _getch();
                    break;
                }
                SetColor(15);
                gotoxy(0,24);
                printf("\n");
                system("pause");
                system("cls");
            }
            while(choix!=5);
        }
        break;
        case 2 :
        {
            diagnostique(P);
        }
        break;
        case 3 :
        {
            printf("Montant a payer : %d,00DH\n",paiement());
        }
        break;
        case 4 :
        {
            do
            {
                SetColor(9);
                gotoxy(56,2);
                printf("GERER LES RDV");
                SetColor(15);
                rectanglemenu8();
                gotoxy(57,6);
                printf("Ajouter RDV");
                gotoxy(61,7);
                printf("(1)");
                rectanglemenu9();
                gotoxy(50,10);
                printf("Afficher les RDV du jour");
                gotoxy(61,11);
                printf("(2)");
                SetColor(12);
                rectanglemenu7();
                gotoxy(50,14);
                printf("Retour Au Menu Principale");
                gotoxy(61,15);
                printf("(3)");
                SetColor(9);
                gotoxy(48,20);
                printf("Veuillez choisir une tache: \n");
                rectangle2();
                SetColor(15);
                gotoxy(44,22);
                scanf("%d",&choix);
                system("cls");
                switch(choix)
                {
                case 1 :
                {
                    ajouterRDV(P,lp);
                }
                break;
                case 2 :
                {
                    afficherRDV(lp);
                }
                break;
                case 3 :
                {
                    goto M;
                }
                break;
                default :
                    SetColor(4);
                    gotoxy(32,12);
                    printf("CHOIX NON VALIDE, VEUILLEZ ENTRER UN NBR ENTRE 1 ET 3\n");
                    _getch();
                    break;
                }
                SetColor(15);
                gotoxy(0,24);
                printf("\n");
                system("pause");
                system("cls");
            }
            while(choix!=3);
        }
        break;
        case 5 :
        {
            enregistrer(P,ep,lp);
        }
        break;
        case 6 :
        {
            quitter(P,ep,lp);
        }
        break;
        default :
            SetColor(4);
            gotoxy(32,12);
            printf("CHOIX NON VALIDE, VEUILLEZ ENTRER UN NBR ENTRE 1 ET 6\n");
            _getch();
            menu();
            break;
        }
        SetColor(15);
        gotoxy(0,24);
        printf("\n");
        system("pause");
        system("cls");
    }
    while(choose != 6);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**some-graphics**/

/**rectangle-S-box**/
void rectangle0()
{
    int i;
    for(i=38; i<=70; i++)
    {
        gotoxy(i,11);
        _cprintf(":");
        gotoxy(i,16);
        _cprintf(":");
    }
    for(i=12; i<=16; i++)
    {
        gotoxy(38,i);
        _cprintf(":");
        gotoxy(70,i);
        _cprintf(":");
    }
}

void rectangle3()
{
    int i;
    for(i=38; i<=70; i++)
    {
        gotoxy(i,3);
        _cprintf(".");
        gotoxy(i,19);
        _cprintf(".");
    }
    for(i=4; i<=19; i++)
    {
        gotoxy(38,i);
        _cprintf(":");
        gotoxy(70,i);
        _cprintf(":");
    }
}

void rectangle2()
{
    int i;
    for(i=42; i<=80; i++)
    {
        gotoxy(i,21);
        _cprintf(".");
        gotoxy(i,23);
        _cprintf(".");
    }
    for(i=22; i<=22; i++)
    {
        gotoxy(42,i);
        _cprintf(":");
        gotoxy(80,i);
        _cprintf(":");
    }
}

void rectangle()
{
    int i;
    SetColor(13);
    for(i=36; i<=85; i++)
    {
        gotoxy(i,8);
        _cprintf(">");
        gotoxy(i,14);
        _cprintf("<");
    }
    SetColor(4);
    for(i=8; i<=14; i++)
    {
        gotoxy(36,i);
        _cprintf("#");
        gotoxy(85,i);
        _cprintf("#");
    }
}

void rectanglemenu1()
{
    int i;
    for(i=9; i<=33; i++)
    {
        gotoxy(i,5);
        _cprintf(":");
        gotoxy(i,8);
        _cprintf(":");
    }
    for(i=5; i<=8; i++)
    {
        gotoxy(9,i);
        _cprintf(":");
        gotoxy(33,i);
        _cprintf(":");
    }
}

void rectanglemenu2()
{
    int i;
    for(i=35; i<=59; i++)
    {
        gotoxy(i,5);
        _cprintf(":");
        gotoxy(i,8);
        _cprintf(":");
    }
    for(i=5; i<=8; i++)
    {
        gotoxy(35,i);
        _cprintf(":");
        gotoxy(59,i);
        _cprintf(":");
    }
}

void rectanglemenu3()
{
    int i;
    for(i=61; i<=85; i++)
    {
        gotoxy(i,5);
        _cprintf(":");
        gotoxy(i,8);
        _cprintf(":");
    }
    for(i=5; i<=8; i++)
    {
        gotoxy(61,i);
        _cprintf(":");
        gotoxy(85,i);
        _cprintf(":");
    }
}

void rectanglemenu4()
{
    int i;
    for(i=87; i<=111; i++)
    {
        gotoxy(i,5);
        _cprintf(":");
        gotoxy(i,8);
        _cprintf(":");
    }
    for(i=5; i<=8; i++)
    {
        gotoxy(87,i);
        _cprintf(":");
        gotoxy(111,i);
        _cprintf(":");
    }
}

void rectanglemenu5()
{
    int i;
    for(i=39; i<=56; i++)
    {
        gotoxy(i,13);
        _cprintf(":");
        gotoxy(i,16);
        _cprintf(":");
    }
    for(i=13; i<=16; i++)
    {
        gotoxy(39,i);
        _cprintf(":");
        gotoxy(56,i);
        _cprintf(":");
    }
}

void rectanglemenu6()
{
    int i;
    for(i=68; i<=85; i++)
    {
        gotoxy(i,13);
        _cprintf(":");
        gotoxy(i,16);
        _cprintf(":");
    }
    for(i=13; i<=16; i++)
    {
        gotoxy(68,i);
        _cprintf(":");
        gotoxy(85,i);
        _cprintf(":");
    }
}

void rectanglemenu7()
{
    int i;
    for(i=47; i<=76; i++)
    {
        gotoxy(i,13);
        _cprintf(":");
        gotoxy(i,16);
        _cprintf(":");
    }
    for(i=13; i<=16; i++)
    {
        gotoxy(47,i);
        _cprintf(":");
        gotoxy(76,i);
        _cprintf(":");
    }
}

void rectanglemenu8()
{
    int i;
    for(i=47; i<=76; i++)
    {
        gotoxy(i,5);
        _cprintf(":");
        gotoxy(i,8);
        _cprintf(":");
    }
    for(i=5; i<=8; i++)
    {
        gotoxy(47,i);
        _cprintf(":");
        gotoxy(76,i);
        _cprintf(":");
    }
}

void rectanglemenu9()
{
    int i;
    for(i=47; i<=76; i++)
    {
        gotoxy(i,9);
        _cprintf(":");
        gotoxy(i,12);
        _cprintf(":");
    }
    for(i=9; i<=12; i++)
    {
        gotoxy(47,i);
        _cprintf(":");
        gotoxy(76,i);
        _cprintf(":");
    }
}

/**COLOR fct**/
void SetColor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

/**Gotoxy**/
void gotoxy(int x,int y)
{
    COORD C= {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),C);
}

/**Image**/
void image()
{
    int gmode= DETECT,gm;
    initgraph(&gmode,&gm,"c://tc//bgi");
    readimagefile("C:\\Desktop\\MEDICABINET\\IMG-1st-SCREEN.jpg",0,0,650,500);
    getch();
    closegraph();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
