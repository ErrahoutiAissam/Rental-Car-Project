#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "date.c"
#include "macros.c"
#ifndef WINDOWS
#include <windows.h>
#endif

int i;

//global variables
HWND window0, window1, window2, EmpNom ,EmpPrenom, EmpID, hClientPermis, hNomClient, hClientAdresse, hClientCIN,
        hClientTel, hClientVille,hMatricule, hMarques, hDateDebut_Jour, hDateDebut_Mois, hDateDebut_annee,
        hDateFin_Jour, hDateFin_Mois, hDateFin_annee, hPrixTotal, hPrixJour, hModele;

int joursDiff;
char CIN[9];
int num_matr, num_modele;


//vérifier les donnees de l'employee
int verifierEmp(HWND *hwnds){
    char EmpTab[3][20];
    for(int i=0; i<3; i++){
        GetWindowText(hwnds[i], EmpTab[i], 20);
    }
    FILE *femp = fopen("BD/employee.txt", "r");
    if(!femp)exit(1);
    char buff[256], IDTmp[5], NomTmp[30], PrenomTmp[30];

    while(!feof(femp)){
        fgets(buff, 256, femp);
        sscanf(buff, "%s%s%s", IDTmp, NomTmp, PrenomTmp);
        if(strcmp(IDTmp, EmpTab[0])==0 && strcmp(NomTmp, EmpTab[1])==0 && strcmp(PrenomTmp, EmpTab[2])==0)return 1;
    }
    return 0;
}

void effacerWindow(HWND *hwnds, int n){
    for(int i=0; i<n; i++){
        SetWindowText(hwnds[i], L"");
    }
}

//return 0 si une entrée est vide
int verifierSiVide(HWND *hwnd, int n){
    char buff[100];
    for(int i=0; i<n; i++){
        GetWindowText(hwnd[i], buff, 100);
        if(strcmp(buff, "")==0)return 0;
    }
    return 1;
}

//return 0 si les dates sont incorrectes
int verefierLesDate(HWND *hwnds){
    int tabDate[6];
    char buff[5];
    for(int i=0; i<6; i++){
        GetWindowText(hwnds[i],buff,5);
        tabDate[i] = atoi(buff);
    }
    Date d1 = {tabDate[0],tabDate[1],tabDate[2]};
    Date d2 = {tabDate[3],tabDate[4],tabDate[5]};

    if(!verifierDate(d1, d2))return 0;
    joursDiff = diffDates(d1,d2);
    return 1;
}

int calculerPrix(){
    char prixJ_[10];
    GetWindowText(hPrixJour, prixJ_, 10);
    return joursDiff * atoi(prixJ_);
}

// return tous les matricules du voitures reserve dans une intervalle de temps
char **matriculeDeVoi_reserve(){
    num_matr = 0;
    Date d1, d2;
    char marque[40];
    char buff[256],cin[12], matr[12];
    char **matr_voiture_resr = (char**)malloc(sizeof(char*)*20);

    GetWindowText(hMarques, marque, 40);
    HWND dateEntry[6] = {hDateDebut_Jour, hDateDebut_Mois, hDateDebut_annee, hDateFin_Jour, hDateFin_Mois, hDateFin_annee};
    char tabDate[6][5];
    for(int i=0; i<6; i++){
        GetWindowText(dateEntry[i], tabDate[i], 5);
    }
    Date d3 = {atoi(tabDate[0]),atoi(tabDate[1]),atoi(tabDate[2])};
    Date d4 = {atoi(tabDate[3]),atoi(tabDate[4]),atoi(tabDate[5])};

    char filePath[200];
    sprintf(filePath, "BD/voiture reserve/%s.txt", marque);
    FILE *fp = fopen(filePath, "r");
    if (fp == NULL) {
        MessageBox(NULL,TEXT("erreur"), "erreur", MB_OK| MB_ICONERROR);
    }
    fseek(fp, 117, SEEK_SET);
    while(!feof(fp)){
        fgets(buff,256,fp);
        sscanf(buff, "%s%s %d/%d/%d %d/%d/%d", cin, matr, &(d1.jour), &(d1.mois), &(d1.annee),
                                &(d2.jour), &(d2.mois), &(d2.annee));
        if(intersection(d1,d2,d3,d4)){
            matr_voiture_resr[num_matr]= (char*) malloc(sizeof(char)*(strlen(matr)+1));
            strcpy(matr_voiture_resr[num_matr],matr);
            num_matr++;
        }
    }

    fclose(fp);
    return matr_voiture_resr;
}

// return tous les voitures non reserve dans une intervalle de temps
char **modeleNonReserve(){
    num_modele=0;
    char **matricule_Reserve = matriculeDeVoi_reserve();
    FILE *fp = fopen("BD/voiture.txt","r");
    if(!fp)MessageBox(NULL,TEXT("erreur"), "erreur", MB_OK| MB_ICONERROR);
    char **modele_NonReserve = (char**)malloc(sizeof(char*)*6);
    char buff[256], matr[12], marque[20], md1[20], md2[20];
    char marque_Commande[20];
    GetWindowText(hMarques, marque_Commande, 20);
    fseek(fp, 37, SEEK_SET);
    while(!feof(fp)){
        int index=0;
        fgets(buff, 256, fp);
        sscanf(buff, "%s%s%s%s", matr, marque, md1, md2);
        strcat(md1," ");
        strcat(md1,md2);
        if(strcmp(marque,marque_Commande)==0){
            for(int i=0; i<num_matr; i++){
                if(strcmp(matr,matricule_Reserve[i])==0){
                    index = 1;
                }
            }
            if(index==0){
                modele_NonReserve[num_modele] = (char*)malloc(sizeof(char)*(strlen(md1)+1));
                    strcpy(modele_NonReserve[num_modele], md1);
                    num_modele++;
            }
        }
    }
    fclose(fp);
    return modele_NonReserve;
}

//recherche la matricule de voiture commande par le client
char *matriculeDeVoi_Commande(){
    FILE *fp = fopen("BD/voiture.txt","r");
    if(!fp)MessageBox(NULL,TEXT("erreur"), "erreur", MB_OK| MB_ICONERROR);
    char *matricule = (char*)malloc(sizeof(char)*12);
    char **tabMatriculeReserve = matriculeDeVoi_reserve();
    char buff[256];
    //les colonnes de voiture.txt  (voitureInfo[0] = Matricule, voitureInfo[1] = Marque, voitureInfo[2] = Modele)
    char voitureInfo[3][20];
    // variables pour stocker l'entrée de l'utilisateur (la marque et le modele de voiture)
    char marque[20] ,modele[20];
    GetWindowText(hMarques, marque, 20);
    GetWindowText(hModele, modele, 20);
    fseek(fp,40,SEEK_SET);
    while(!feof(fp)){
        fgets(buff, 256, fp);
        sscanf(buff,"%s%s %[^\n]", voitureInfo[0],voitureInfo[1],voitureInfo[2]);
        if(strcmp(voitureInfo[1],marque)==0&&strcmp(voitureInfo[2],modele)==0){
            int i=0;
            for(int j=0; j<num_matr;j++){
                if(strcmp(voitureInfo[0],tabMatriculeReserve[j])==0){
                    i=1;
                }
            }
            if(i==0){
                strcpy(matricule,voitureInfo[0]);
            }
        }

    }
    fclose(fp);
    return matricule;
}

//stocker les donnees de client
void stockerClient(HWND *hwnds){
    FILE *fp = fopen("BD/client.txt", "a");
    if(!fp){
        MessageBox(NULL,TEXT("erreur"), "erreur", MB_OK| MB_ICONERROR);
        return;
    }
    char clientInfo[100];
    GetWindowText(hClientCIN, CIN, 9);
    fprintf(fp, "\n%-15s", CIN);
    for(int i=1; i<6; i++){
        GetWindowText(hwnds[i],clientInfo,100);
        fprintf(fp, "%-20s",clientInfo);
    }
}

//stocker les donnees de voiture
void stockerVoiture(HWND *hwnds){
    char marque[20];
    GetWindowText(hMarques,marque, 20);
    char filepath[100];
    char voitureInfo[100];
    sprintf(filepath,"BD/voiture reserve/%s.txt",marque);
    FILE *fp = fopen(filepath, "a");
    if(!fp){
        MessageBox(NULL,TEXT("erreur"), "erreur", MB_OK| MB_ICONERROR);
        return;
    }
    fprintf(fp,"\n%-14s %-20s", CIN, matriculeDeVoi_Commande());
    for(int i=0; i<7; i++){
        GetWindowText(hwnds[i],voitureInfo, 100);
        if(i==0||i==1||i==3||i==4){
            fprintf(fp,"%s/",voitureInfo);
        }
        else{
            fprintf(fp,"%-20s",voitureInfo);
        }
    }
    fprintf(fp,"%d", calculerPrix());
}
