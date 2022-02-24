#include "BackEnd.c"
#include <windows.h>
#include "macros.c"


LRESULT CALLBACK WindowEmpProcedure(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WindowOperationsProcedure(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WindowAjClientProcedure(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WindowMdClientProcedure(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WindowAjVoitureProcedure(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WindowMdVoitureProcedure(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WindowSpVoitureProcedure(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WindowEvaluerProcedure(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WindowLouerProcedure(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WindowStatistiqueProcedure(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WindowAjouterEmpProcedure(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WindowAffClientProcedure(HWND, UINT, WPARAM, LPARAM);


void WindowEmpContent(HWND hWnd);
void WindowOperationContent(HWND hWnd);
void WindowAjClientContent(HWND hWnd);
void WindowMdClientContent(HWND hWnd);
void WindowAffClientContent(HWND hWnd);
void WindowAjVoitureContent(HWND hWnd);
void WindowMdVoitureContent(HWND hWnd);
void WindowSpVoitureContent(HWND hWnd);
void WindowLouerContent(HWND hWnd);
void WindowEvaluerContent(HWND hWnd);
void WindowStatistiqueContent(HWND hWnd);


//main function
int WINAPI WinMain(HINSTANCE hinst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow)
{
    //create 2 window object (structres)
    WNDCLASSW wc0 = {0}, wc1 = {0}, wc2 = {0}, wc3 = {0}, wc4 = {0}, wc5 = {0}, wc6 = {0}, wc7 = {0}, wc8 = {0}, wc9 ={0}, wc10 = {0}, wc11={0};
    

    //characteristics for each window object

    wc0.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc0.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc0.hInstance = hinst;
    wc0.lpszClassName = L"WindowEmpClass";
    wc0.lpfnWndProc = WindowEmpProcedure;

    wc1.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc1.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc1.hInstance = hinst;
    wc1.lpszClassName = L"WindowOperationClass";
    wc1.lpfnWndProc = WindowOperationsProcedure;

    wc2.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc2.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc2.hInstance = hinst;
    wc2.lpszClassName = L"WindowAjouterClient";
    wc2.lpfnWndProc = WindowAjClientProcedure;

    wc3.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc3.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc3.hInstance = hinst;
    wc3.lpszClassName = L"WindowModifierClient";
    wc3.lpfnWndProc = WindowMdClientProcedure;

    wc4.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc4.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc4.hInstance = hinst;
    wc4.lpszClassName = L"WindowAjouterVoiture";
    wc4.lpfnWndProc = WindowAjVoitureProcedure;

    wc5.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc5.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc5.hInstance = hinst;
    wc5.lpszClassName = L"WindowModifierVoiture";
    wc5.lpfnWndProc = WindowMdVoitureProcedure;

    wc6.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc6.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc6.hInstance = hinst;
    wc6.lpszClassName = L"WindowSupprimerVoiture";
    wc6.lpfnWndProc = WindowSpVoitureProcedure;


    wc7.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc7.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc7.hInstance = hinst;
    wc7.lpszClassName = L"WindowEvaluerClass";
    wc7.lpfnWndProc = WindowEvaluerProcedure;

    wc8.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc8.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc8.hInstance = hinst;
    wc8.lpszClassName = L"WindowLouerClass";
    wc8.lpfnWndProc = WindowLouerProcedure;

    wc9.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc9.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc9.hInstance = hinst;
    wc9.lpszClassName = L"WindowStatistiqueClass";
    wc9.lpfnWndProc = WindowStatistiqueProcedure;

    wc10.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc10.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc10.hInstance = hinst;
    wc10.lpszClassName = L"WindowAjouterEmpClass";
    wc10.lpfnWndProc = WindowAjouterEmpProcedure;

    wc11.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc11.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc11.hInstance = hinst;
    wc11.lpszClassName = L"WindowAffClientClass";
    wc11.lpfnWndProc = WindowAffClientProcedure;

    //checking if the objects were created
    if (!RegisterClassW(&wc0) || !RegisterClassW(&wc1) || !RegisterClassW(&wc2) || !RegisterClassW(&wc3) || !RegisterClassW(&wc4) ||
                 !RegisterClassW(&wc5) || !RegisterClassW(&wc6) || !RegisterClassW(&wc7) || !RegisterClassW(&wc8) || 
                 !RegisterClassW(&wc9) || !RegisterClassW(&wc10) || !RegisterClassW(&wc11))
    {
        return -1;
    }
    //create a window object from wc0="WindowClass0" class (this is the main window)
    windowEmp =  CreateWindowW(L"WindowEmpClass", L"Sign in", Disable_resize | WS_VISIBLE ,
                300, 100, 700, 400, NULL, NULL, NULL, NULL);

    MSG msg = {0};
    while (GetMessageW(&msg, NULL, NULL, NULL))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
//Call back function for window0
LRESULT CALLBACK WindowEmpProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
    HWND WinEmpTab[3] = {hEmpID, hEmpNom, hEmpPrenom};
    switch (msg)
    {
    case WM_CREATE:
        //create window0 content
        WindowEmpContent(hWnd);
        break;
    case WM_COMMAND:
        switch(wp){
            case Button_Emp:
                MessageBeep(MB_OK);
                // array of entries box
                HWND win0tab[3] = {hEmpID, hEmpNom, hEmpPrenom};
                if(!verifierEmp(win0tab)){
                    MessageBox(NULL,TEXT("essayer à nouveau"), "erreur", MB_OK| MB_ICONERROR);
                    break;
                }
                windowOperation =  CreateWindowW(L"WindowOperationClass", L"Location Voiture",
                        Disable_resize | WS_VISIBLE,300, 100, 700, 400, NULL, NULL, NULL, NULL);
                // effacerWindow(win0tab, 3);
                EnableWindow(windowEmp,0);   
                break;
            case Button_AjouterEmp:
                windowAjEmp = CreateWindowW(L"WindowAjouterEmpClass", L"Ajouter employee",
                        Disable_resize | WS_VISIBLE,300, 100, 700, 400, NULL, NULL, NULL, NULL);
                EnableWindow(windowEmp,0);
                break;
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProcW(hWnd, msg, wp, lp);
        break;
    }
}
//ajouter employee
LRESULT CALLBACK WindowAjouterEmpProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp){
    HWND WinAjEmpTab[2] = {hAjEmpNom, hAjEmpPrenom};
    switch (msg)
    {
    case WM_CREATE:
        WindowAjEmp(hWnd);
        break;
    case WM_COMMAND:
        switch(wp){
            case Button_AjouterEmpB:
                if(!verifierSiVide(WinAjEmpTab, 2)){
                    MessageBox(NULL,TEXT("Remplir tous les champs"), "erreur", MB_OK| MB_ICONERROR);
                    break;
                }
                char msgText[20];
                sprintf(msgText, "Votre ID est %d", getLastEmpId() + 1);
                MessageBox(NULL,msgText, "valide", MB_OK);
                ajouterEmp();
        }
        break;
    case WM_CLOSE:
        DestroyWindow(windowAjEmp);
        EnableWindow(windowEmp,1);
        break;
    default:
        return DefWindowProcW(hWnd, msg, wp, lp);
        break;
    }
}


// operations
LRESULT CALLBACK WindowOperationsProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp){
    switch (msg)
    {
    case WM_CREATE:
        //create window0 content
        WindowOperationContent(hWnd);
        break;
    case WM_COMMAND:
        switch(wp){
            case Button_AjouterClient:
                windowAjClient = CreateWindowW(L"WindowAjouterClient", L"Ajouter client",
                        Disable_resize | WS_VISIBLE,300, 100, 700, 400, NULL, NULL, NULL, NULL);
                EnableWindow(windowOperation,0);
                break;
            case Button_ModifierClient:
                windowMdClient = CreateWindowW(L"WindowModifierClient", L"Modifier client",
                        Disable_resize | WS_VISIBLE,300, 100, 700, 400, NULL, NULL, NULL, NULL);
                EnableWindow(windowOperation,0);
                break;

            case Button_afficherClient:
                windowAffClient = CreateWindowW(L"WindowAffClientClass", L"Afficher client",
                        Disable_resize | WS_VISIBLE,300, 100, 700, 400, NULL, NULL, NULL, NULL);
                break;


            case Button_AjouterVoiture:
                windowAjVoiture = CreateWindowW(L"WindowAjouterVoiture", L"Ajouter une voiture",
                        Disable_resize | WS_VISIBLE,300, 100, 700, 400, NULL, NULL, NULL, NULL);
                EnableWindow(windowOperation,0);
                break;
            
            case Button_ModifierVoiture:
                windowMdVoiture = CreateWindowW(L"WindowModifierVoiture", L"Modifier l'etat d'une voiture",
                        Disable_resize | WS_VISIBLE,300, 100, 700, 400, NULL, NULL, NULL, NULL);
                EnableWindow(windowOperation,0);
                break;
            case Button_SupprimerVoiture: 
                windowSpVoiture = CreateWindowW(L"WindowSupprimerVoiture", L"Supprimer une voiture",
                        Disable_resize | WS_VISIBLE,300, 100, 700, 400, NULL, NULL, NULL, NULL);
                EnableWindow(windowOperation,0);
                break;

            case Button_Evaluer:
                windowEvaluer = CreateWindowW(L"WindowEvaluerClass", L"Evaluation",
                        Disable_resize | WS_VISIBLE,300, 100, 700, 400, NULL, NULL, NULL, NULL);
                EnableWindow(windowOperation,0);
                break;
            case Button_Louer:
                windowLouer = CreateWindowW(L"WindowLouerClass", L"Reservation",
                        Disable_resize | WS_VISIBLE,300, 20, 700, 590, NULL, NULL, NULL, NULL);
                EnableWindow(windowOperation,0);
                break;
            case Button_Statistique:
                windowStatistique = CreateWindowW(L"WindowStatistiqueClass", L"Statistique",
                        Disable_resize | WS_VISIBLE,300, 100, 700, 400, NULL, NULL, NULL, NULL);
                EnableWindow(windowOperation,0);
                break;

            
        }
        break;
    case WM_CLOSE:
        DestroyWindow(windowOperation);
        EnableWindow(windowEmp,1);
        break;
    default:
        return DefWindowProcW(hWnd, msg, wp, lp);
        break;
    }
}

// Ajouter Client
LRESULT CALLBACK WindowAjClientProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp){
    HWND WinAjClTab[6] = {hCIN, hPermis, hNom, hTel, hVille, hAdresse};
    char CIN[12];
    switch (msg)
    {
    case WM_CREATE:
        //create window0 content
        WindowAjClientContent(hWnd);
        break;
    case WM_COMMAND:
        switch(wp){
            case Button_StockerClient :
                if(!verifierSiVide(WinAjClTab,6)){
                    MessageBox(NULL,TEXT("Remplir tous les champs"), "erreur", MB_OK| MB_ICONERROR);
                    break;
                }
                GetWindowText(hCIN, CIN, 12);
                if(CINExiste(CIN)){
                    MessageBox(NULL,TEXT("Le client est deja stocke"), "erreur", MB_OK| MB_ICONERROR);
                    break;
                }
                ajouterClient(WinAjClTab);
                MessageBox(NULL,TEXT("ajoute avec succes"), "Valide", MB_OK);
                break;
        }
        break;
    case WM_CLOSE:
        DestroyWindow(windowAjClient);
        EnableWindow(windowOperation,1);
        break;
    default:
        return DefWindowProcW(hWnd, msg, wp, lp);
        break;
    }
}
// Modifier client
LRESULT CALLBACK WindowMdClientProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp){
    HWND mdClTab[4] = {hNvCIN,hNvTel, hNvVille, hNvAdresse};
    char CIN[12];
    switch (msg)
    {
    case WM_CREATE:
        //create window0 content
        WindowMdClientContent(hWnd);
        break;
    case WM_COMMAND:
        switch(wp){
            case Button_ModifierClientB:
                if(!verifierSiVide(mdClTab,4)){
                    MessageBox(NULL,TEXT("Remplir tous les champs"), "erreur", MB_OK| MB_ICONERROR);
                    break;
                }
                GetWindowText(hNvCIN, CIN, 12);
                if(!CINExiste(CIN)){
                    MessageBox(NULL,TEXT("Le client n'existe pas"), "erreur", MB_OK| MB_ICONERROR);
                    break;
                }
                modifierClient(mdClTab);
                MessageBox(NULL,TEXT("modifier avec succes"), "Valide", MB_OK);
                break;
        }
        break;
    case WM_CLOSE:
        DestroyWindow(windowMdClient);
        EnableWindow(windowOperation,1);
        break;
    default:
        return DefWindowProcW(hWnd, msg, wp, lp);
        break;
    }
}
//affichage de client
LRESULT CALLBACK WindowAffClientProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp){
    HWND affClTab[6] = {hshowCIN, hShowPermis,  hShownom, hShowNbrRes, hShowTel,  hShowAdresse};
    switch (msg)
    {
    case WM_CREATE:
        WindowAffClientContent(hWnd);
        break;
    case WM_COMMAND:
        switch(wp){
            case Button_afficherClientB:
                AfficherClient();
                break;
        }
        break;
    case WM_CLOSE:
        DestroyWindow(windowAffClient);
        EnableWindow(windowOperation,1);
        break;
    default:
        return DefWindowProcW(hWnd, msg, wp, lp);
        break;
    }
}


//Ajouter voiture
LRESULT CALLBACK WindowAjVoitureProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp){
    HWND AjVoiTab[3] = {hAjMatricule, hAjMarque, hAjModele};
    char matr[12];
    switch (msg)
    {
    case WM_CREATE:
        //create window0 content
        WindowAjVoitureContent(hWnd);
        break;
    case WM_COMMAND:
        switch(wp){
            case Button_AjouterVoitureB:
                if(!verifierSiVide(AjVoiTab,3)){
                    MessageBox(NULL,TEXT("Remplir tous les champs"), "erreur", MB_OK| MB_ICONERROR);
                    break;
                }
                GetWindowText(hAjMatricule, matr, 12);
                if(MatrExiste(matr)){
                    MessageBox(NULL,TEXT("cette voiture a ete deja ajoute"), "erreur", MB_OK| MB_ICONERROR);
                    break;
                }
                ajouterVoiture(AjVoiTab);
                MessageBox(NULL,TEXT("ajoute avec succes"), "valide", MB_OK);
                break;
        }
        break;
    case WM_CLOSE:
        DestroyWindow(windowAjVoiture);
        EnableWindow(windowOperation,1);
        break;
    default:
        return DefWindowProcW(hWnd, msg, wp, lp);
        break;
    }
}
//Modifier voiture 
LRESULT CALLBACK WindowMdVoitureProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp){
    HWND mdVoiTab[5] = {hMdMatricule, hModifEtat, hMdayFinAssurance, hMmonthFinAssurance, hMyearFinAssurance};
    char matr[12], etat[4];
    switch (msg)
    {
    case WM_CREATE:
        //create window0 content
        WindowMdVoitureContent(hWnd);
        break;
    case WM_COMMAND:
        switch(wp){
            case Button_ModifierVoitureB:
                GetWindowText(hMdMatricule, matr, 12);
                if(!MatrExiste(matr)){
                    MessageBox(NULL,TEXT("cette voiture n'existe pas"), "erreur", MB_OK| MB_ICONERROR);
                    break;
                }
                GetWindowText(hMdMatricule, matr, 12);
                GetWindowText(hModifEtat, etat, 4);
                modifierEtat(matr, etat);
                modifierAssurance(mdVoiTab);
                MessageBox(NULL,TEXT("modifier avec succes"), "valide", MB_OK);
                break;
        }
        break;
    case WM_CLOSE:
        DestroyWindow(windowMdVoiture);
        EnableWindow(windowOperation,1);
        break;
    default:
        return DefWindowProcW(hWnd, msg, wp, lp);
        break;
    }
}
// Supprimer voiture
LRESULT CALLBACK WindowSpVoitureProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp){
    switch (msg)
    {
    case WM_CREATE:
        //create window0 content
        WindowSpVoitureContent(hWnd);
        break;
    case WM_COMMAND:
        switch(wp){
            case Button_SupprimerVoitureB:
                if(verifierSiVide(hSpMatricule,1)){
                    MessageBox(NULL,TEXT("Remplir tous les champs"), "erreur", MB_OK| MB_ICONERROR);
                    break;
                }
                suppVoiture();
        }
        break;
    case WM_CLOSE:
        DestroyWindow(windowSpVoiture);
        EnableWindow(windowOperation,1);
        break;
    default:
        return DefWindowProcW(hWnd, msg, wp, lp);
        break;
    }
}
LRESULT CALLBACK WindowEvaluerProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp){
    HWND EvalTab[8] = {hID, hMarqueEval, hCINEval, hMatrEval, hDateEval_jour, hDateEval_mois,
                            hDateEval_annee, hEvalEtat};
    char matr[12], etat[4], cin[12];
    switch (msg)
    {
    case WM_CREATE:
        //create window0 content
        WindowEvaluerContent(hWnd);
        break;
    case WM_COMMAND:
        switch(wp){
            case Button_EvaluerB:
                if(!verifierSiVide(EvalTab,8)){
                    MessageBox(NULL,TEXT("Remplir tous les champs"), "erreur", MB_OK| MB_ICONERROR);
                    break;
                }
                if(Retard(EvalTab)==404){
                    MessageBox(NULL,TEXT("ID non trouve"), "erreur", MB_OK| MB_ICONERROR);
                    break;
                }
                if(!evaluerEtat()){
                    MessageBox(NULL,TEXT("Etat a ete change"), "erreur", MB_OK| MB_ICONERROR);
                    GetWindowText(hMatrEval, matr, 12);
                    GetWindowText(hEvalEtat, etat, 4);
                    modifierEtat(matr, etat);
                }
                else{
                    MessageBox(NULL,TEXT("meme etat"), "erreur", MB_OK);
                }
                char msgText[100];
                sprintf(msgText,"%d jours de retard", Retard(EvalTab));
                MessageBox(NULL,TEXT(msgText), "valid", MB_OK);

                if(Retard(EvalTab)>0 || !evaluerEtat()){
                    AjouterListeNoir();
                }
                
                break;
        }
        break;
    case WM_CLOSE:
        DestroyWindow(windowEvaluer);
        EnableWindow(windowOperation,1);
        break;
    default:
        return DefWindowProcW(hWnd, msg, wp, lp);
        break;
    }
}
LRESULT CALLBACK WindowLouerProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp){
    HWND winLouerTab[11] = {hLouerCIN, hDateDebut_Jour, hDateDebut_Mois, hDateDebut_annee, hDateFin_Jour, hDateFin_Mois,
        hDateFin_annee,hMarques, hModele, hPrixJour, hPrixTotal};
    char CIN[12];
    TCHAR **tab;
    char Sprix[10];
    switch (msg)
    {
    case WM_CREATE:
        //create window0 content
        WindowLouerContent(hWnd);
        break;
    case WM_COMMAND:
        switch(wp){
            case Button_VerifierClient:
                GetWindowText(hLouerCIN, CIN, 12);
                if(enListNoir()){
                    MessageBox(NULL,TEXT("Ce client est en la liste noir"), "erreur", MB_OK| MB_ICONERROR);
                    DestroyWindow(windowLouer);
                    EnableWindow(windowOperation,1);
                    break;
                }
                if(!CINExiste(CIN)){
                    MessageBox(NULL,TEXT("Le client n'existe pas, veuillez l'ajouter"), "erreur", MB_OK| MB_ICONERROR);
                    break;
                }
                MessageBox(NULL,TEXT("Le client existe"), "Valide", MB_OK);
                if(EstFidele()){
                    MessageBox(NULL,TEXT("Client fidele, vous aurez un remis de 10 %"), "Valide", MB_OK);
                    break;
                }
                break;
            
            case Button_chercherModele:
                if(!verefierLesDate(winLouerTab)){
                    MessageBox(NULL,TEXT("Date incorrect"), "erreur", MB_OK| MB_ICONERROR);
                    break;
                }
                int i;
                for ( i = 0; i < nbrModele; i++)
                    SendMessage(hModele, (UINT) CB_DELETESTRING, (WPARAM) 0, 0);
                tab = Modeles();
                for ( i = 0; i < nbrModele; i++)
                    SendMessage(hModele, (UINT) CB_ADDSTRING, (WPARAM) 0, tab[i]);
                SendMessage(hModele, (UINT) CB_SETCURSEL, (WPARAM) 0, (LPARAM)0);
                
                break;
            case Button_Calculer:
                itoa(Prix(), Sprix, 10);
                SetWindowText(hPrixTotal, Sprix);
                break;
            case Button_reserver:
                stockerReservation(winLouerTab);
                incrementNbrResr();
                break;
        }
        break;
    case WM_CLOSE:
        DestroyWindow(windowLouer);
        EnableWindow(windowOperation,1);
        break;
    default:
        return DefWindowProcW(hWnd, msg, wp, lp);
        break;
    }
}
LRESULT CALLBACK WindowStatistiqueProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp){
    char StrGain[10];
    switch (msg)
    {
    case WM_CREATE:
        //create window0 content
        WindowStatistiqueContent(hWnd);
        break;
    case WM_COMMAND:
        switch(wp){
            case Button_Statistique:
                itoa(Gain(),StrGain,10);
                SetWindowText(hPrixMoisS, StrGain);
                break;
        }
        break;
    case WM_CLOSE:
        DestroyWindow(windowStatistique);
        EnableWindow(windowOperation,1);
        break;
    default:
        return DefWindowProcW(hWnd, msg, wp, lp);
        break;
    }
}
void WindowEmpContent(HWND hWnd){
    CreateWindowW(L"static", L"Sign in", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 140, 60, 400, 20,
                    hWnd, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Nom :", WS_VISIBLE | WS_CHILD  , 210, 120, 50, 20,
                    hWnd, NULL, NULL, NULL);
    hEmpNom = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER , 290, 120, 170, 20,
                            hWnd, NULL, NULL, NULL);

    CreateWindowW(L"static", L"Prenom :", WS_VISIBLE | WS_CHILD  , 210, 150, 60, 20,
                    hWnd, NULL, NULL, NULL);
    hEmpPrenom = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 290, 150, 170, 20,
                            hWnd, NULL, NULL, NULL);

    CreateWindowW(L"static", L"ID :", WS_VISIBLE | WS_CHILD  , 210, 180, 30, 20,
                    hWnd, NULL, NULL, NULL);
    hEmpID = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER | ES_PASSWORD , 290, 180, 170, 20,
                            hWnd, NULL, NULL, NULL);

    CreateWindowW(L"Button", L"Entrer", WS_VISIBLE | WS_CHILD | WS_BORDER, 290, 240, 100, 30, hWnd,
                         Button_Emp, NULL, NULL);

    CreateWindowW(L"Button", L"Ajouter", WS_VISIBLE | WS_CHILD | WS_BORDER, 290, 290, 100, 30, hWnd,
                         Button_AjouterEmp, NULL, NULL);

}

//"ajouter client" content
void WindowAjEmp(HWND hWnd){
    CreateWindowW(L"static", L"Employee", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 50, 40, 600, 20,
                    hWnd, NULL, NULL, NULL);
    
    CreateWindowW(L"static", L"Nom :", WS_VISIBLE | WS_CHILD  , 210, 120, 50, 20,
                    hWnd, NULL, NULL, NULL);
    hAjEmpNom = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER , 290, 120, 170, 20,
                            hWnd, NULL, NULL, NULL);

    CreateWindowW(L"static", L"Prenom :", WS_VISIBLE | WS_CHILD  , 210, 150, 60, 20,
                    hWnd, NULL, NULL, NULL);
    hAjEmpPrenom = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 290, 150, 170, 20,
                            hWnd, NULL, NULL, NULL);
    
    CreateWindowW(L"Button", L"Ajouter", WS_VISIBLE | WS_CHILD | WS_BORDER, 290, 210, 100, 30, hWnd,
                         Button_AjouterEmpB, NULL, NULL);
}

void WindowOperationContent(HWND hWnd){
    //Client
    CreateWindowW(L"static", L"Client", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 50, 40, 600, 20,
                    hWnd, NULL, NULL, NULL);
    
    CreateWindowW(L"Button", L"Ajouter", WS_VISIBLE | WS_CHILD | WS_BORDER, 100, 80, 100, 30, hWnd,
                         Button_AjouterClient, NULL, NULL);

    CreateWindowW(L"Button", L"Modifier", WS_VISIBLE | WS_CHILD | WS_BORDER, 300, 80, 100, 30, hWnd,
                         Button_ModifierClient, NULL, NULL);

    CreateWindowW(L"Button", L"Afficher", WS_VISIBLE | WS_CHILD | WS_BORDER, 500, 80, 100, 30, hWnd,
                         Button_afficherClient, NULL, NULL);

    //Voiture

    CreateWindowW(L"static", L"Voiture", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 50, 140, 600, 20,
                    hWnd, NULL, NULL, NULL);
    
    CreateWindowW(L"Button", L"Ajouter", WS_VISIBLE | WS_CHILD | WS_BORDER, 100, 180, 100, 30, hWnd,
                         Button_AjouterVoiture, NULL, NULL);
    
    CreateWindowW(L"Button", L"Modifier", WS_VISIBLE | WS_CHILD | WS_BORDER, 300, 180, 100, 30, hWnd,
                         Button_ModifierVoiture, NULL, NULL);
    
    CreateWindowW(L"Button", L"Supprimer", WS_VISIBLE | WS_CHILD | WS_BORDER, 500, 180, 100, 30, hWnd,
                         Button_SupprimerVoiture, NULL, NULL);

    //Operation
    CreateWindowW(L"static", L"Operation", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 50, 240, 600, 20,
                    hWnd, NULL, NULL, NULL);
    
    CreateWindowW(L"Button", L"Evaluer", WS_VISIBLE | WS_CHILD | WS_BORDER, 100, 280, 100, 30, hWnd,
                         Button_Evaluer, NULL, NULL);
    
    
    CreateWindowW(L"Button", L"Statistique", WS_VISIBLE | WS_CHILD | WS_BORDER, 500, 280, 100, 30, hWnd,
                         Button_Statistique, NULL, NULL);

    CreateWindowW(L"Button", L"Louer", WS_VISIBLE | WS_CHILD | WS_BORDER, 300, 280, 100, 30, hWnd,
                         Button_Louer, NULL, NULL);
}

void WindowAjClientContent(HWND hWnd){
    CreateWindowW(L"static", L"informations de clients", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER,
                  20, 50, 650, 20, hWnd, NULL, NULL, NULL);

    CreateWindowW(L"static", L"Permis #:", WS_VISIBLE | WS_CHILD ,
                  40, 120, 200, 20, hWnd, NULL, NULL, NULL);
    hPermis = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 130, 120, 170, 20, hWnd,
                         NULL, NULL, NULL);
    
    CreateWindowW(L"static", L"Le nom :", WS_VISIBLE | WS_CHILD ,
                  370, 120, 200, 20, hWnd, NULL, NULL, NULL);
    hNom = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 465, 120, 170, 20, hWnd,
                         NULL, NULL, NULL);

    CreateWindowW(L"static", L"CIN :", WS_VISIBLE | WS_CHILD ,
                  40, 150, 200, 20, hWnd, NULL, NULL, NULL);
    hCIN = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 130, 150, 170, 20, hWnd,
                         NULL, NULL, NULL);

    CreateWindowW(L"static", L"Adresse :", WS_VISIBLE | WS_CHILD ,
                  370, 150, 200, 20, hWnd, NULL, NULL, NULL);
    hAdresse = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL, 465, 150, 170, 20, hWnd,
                         NULL, NULL, NULL);

    CreateWindowW(L"static", L"Tel :", WS_VISIBLE | WS_CHILD ,
                  40, 180, 200, 20, hWnd, NULL, NULL, NULL);
    hTel = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER, 130, 180, 170, 20, hWnd,
                         NULL, NULL, NULL);

    CreateWindowW(L"static", L"Ville :", WS_VISIBLE | WS_CHILD ,
                  370, 180, 200, 20, hWnd, NULL, NULL, NULL);
    hVille = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 465, 180, 170, 20, hWnd,
                         NULL, NULL, NULL);


    CreateWindowW(L"Button", L"Ajouter", WS_VISIBLE | WS_CHILD | WS_BORDER, 290, 280, 100, 30, hWnd,
                         Button_StockerClient, NULL, NULL);
}

void WindowMdClientContent(HWND hWnd){
    CreateWindowW(L"static", L"Modification d'information de client", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER,
                  20, 50, 650, 20, hWnd, NULL, NULL, NULL);

    CreateWindowW(L"static", L"CIN:", WS_VISIBLE | WS_CHILD ,
                  220, 120, 200, 20, hWnd, NULL, NULL, NULL);
    hNvCIN = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 310, 120, 170, 20, hWnd,
                         NULL, NULL, NULL);

    CreateWindowW(L"static", L"Tel:", WS_VISIBLE | WS_CHILD ,
                  220, 150, 200, 20, hWnd, NULL, NULL, NULL);
    hNvTel = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 310, 150, 170, 20, hWnd,
                         NULL, NULL, NULL);
    
    CreateWindowW(L"static", L"Ville:", WS_VISIBLE | WS_CHILD ,
                  220, 180, 200, 20, hWnd, NULL, NULL, NULL);
    hNvVille = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 310, 180, 170, 20, hWnd,
                         NULL, NULL, NULL);

    CreateWindowW(L"static", L"Adresse:", WS_VISIBLE | WS_CHILD ,
                  220, 210, 200, 20, hWnd, NULL, NULL, NULL);
    hNvAdresse = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 310, 210, 170, 20, hWnd,
                         NULL, NULL, NULL);
    
    CreateWindowW(L"Button", L"Modifier", WS_VISIBLE | WS_CHILD | WS_BORDER, 290, 260, 100, 30, hWnd,
                         Button_ModifierClientB, NULL, NULL);
}

void WindowAffClientContent(HWND hWnd){
   
    CreateWindowW(L"static", L"Afficher d'information de client", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER,
                  20, 50, 650, 20, hWnd, NULL, NULL, NULL);

    CreateWindowW(L"static", L"CIN :", WS_VISIBLE | WS_CHILD ,
                  240,100, 200, 20, hWnd, NULL, NULL, NULL);  

    hshowCIN = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 280, 100, 120, 20, hWnd,
                         NULL, NULL, NULL) ;             

    CreateWindowW(L"static", L"Tel :", WS_VISIBLE | WS_CHILD ,
                  120, 200, 200, 20, hWnd, NULL, NULL, NULL);   

    hShowTel = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER |  ES_READONLY, 185, 200, 150, 20, hWnd,
                         NULL, NULL, NULL);                   

    CreateWindowW(L"static", L"Permis #:", WS_VISIBLE | WS_CHILD ,
                  120, 150, 250, 20, hWnd, NULL, NULL, NULL);
    
    hShowPermis = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER |  ES_READONLY, 185, 150, 150, 20, hWnd,
                         NULL, NULL, NULL);                  
  
    CreateWindowW(L"static", L"Adresse :", WS_VISIBLE | WS_CHILD ,
                  370, 200, 250, 20, hWnd, NULL, NULL, NULL);

    hShowAdresse= CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER |  ES_READONLY | ES_AUTOHSCROLL, 435, 200, 150, 20, hWnd,
                         NULL, NULL, NULL);                   
  
    CreateWindowW(L"static", L"Nom :", WS_VISIBLE | WS_CHILD ,
                  370, 150, 200, 20, hWnd, NULL, NULL, NULL);

    hShownom = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER |  ES_READONLY, 435, 150, 150, 20, hWnd,
                         NULL, NULL, NULL); 
    
    CreateWindowW(L"static", L"Num Reservation :", WS_VISIBLE | WS_CHILD,
                  220, 250, 150, 20, hWnd, NULL, NULL, NULL);

    hShowNbrRes =  CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER |  ES_READONLY, 350, 250, 100, 20, hWnd,
                         NULL, NULL, NULL);            

    CreateWindowW(L"Button", L"Afficher", WS_VISIBLE | WS_CHILD | WS_BORDER, 280, 300, 100, 30, hWnd,
                         Button_afficherClientB, NULL, NULL);
                

}

void WindowAjVoitureContent(HWND hWnd){
    CreateWindowW(L"static", L"Ajouter une voiture", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER,
                  20, 50, 650, 20, hWnd, NULL, NULL, NULL);
     CreateWindowW(L"static", L"Matricule:", WS_VISIBLE | WS_CHILD ,
                  220, 120, 200, 20, hWnd, NULL, NULL, NULL);
    hAjMatricule = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 310, 120, 170, 20, hWnd,
                         NULL, NULL, NULL);
    
    CreateWindowW(L"static", L"Marque:", WS_VISIBLE | WS_CHILD ,
                  220, 150, 200, 20, hWnd, NULL, NULL, NULL);
    hAjMarque = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 310, 150, 170, 20, hWnd,
                         NULL, NULL, NULL);

    CreateWindowW(L"static", L"Modele:", WS_VISIBLE | WS_CHILD ,
                  220, 180, 200, 20, hWnd, NULL, NULL, NULL);
    hAjModele = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 310, 180, 170, 20, hWnd,
                         NULL, NULL, NULL);
    
    CreateWindowW(L"Button", L"Ajouter", WS_VISIBLE | WS_CHILD | WS_BORDER, 290, 250, 100, 30, hWnd,
                         Button_AjouterVoitureB, NULL, NULL);
}
//modifier voiture()
void WindowMdVoitureContent(HWND hWnd){
    CreateWindowW(L"static", L"Modifier une voiture", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER,
                  20, 40, 650, 20, hWnd, NULL, NULL, NULL);

    CreateWindowW(L"static", L"Matricule(*):", WS_VISIBLE | WS_CHILD ,
                  200, 130, 180, 20, hWnd, NULL, NULL, NULL);

    hMdMatricule = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 280, 130, 150, 20, hWnd,
                         NULL, NULL, NULL);

    CreateWindowW(L"static", L"Etat:", WS_VISIBLE | WS_CHILD ,
                  200, 170, 200, 20, hWnd, NULL, NULL,NULL);   

    hModifEtat = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 280, 170, 150, 20, hWnd,
                         NULL, NULL, NULL);

    CreateWindowW(L"static", L"Assurance:", WS_VISIBLE | WS_CHILD ,
                  200, 210, 200, 20, hWnd, NULL, NULL,NULL);   
    
    hMdayFinAssurance = CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER ,
                  280,210,20,20,hWnd,NULL,NULL,NULL);

    CreateWindowW(L"static", L"/", WS_VISIBLE | WS_CHILD ,
                  305, 210, 20, 20, hWnd, NULL, NULL, NULL);              

    hMmonthFinAssurance = CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER ,
                  315,210,20,20,hWnd,NULL,NULL,NULL);     
    
    CreateWindowW(L"static", L"/", WS_VISIBLE | WS_CHILD ,
                  340, 210, 20, 20, hWnd, NULL, NULL, NULL);     

    hMyearFinAssurance = CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER ,
                  350,210,40,20,hWnd,NULL,NULL,NULL);      

    CreateWindowW(L"Button", L"Modifier", WS_VISIBLE | WS_CHILD | WS_BORDER, 280, 260, 100, 30, hWnd,
                    Button_ModifierVoitureB, NULL, NULL);
}
void WindowSpVoitureContent(HWND hWnd){
    CreateWindowW(L"static", L"Supprimer une voiture", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER,
                  20, 50, 650, 20, hWnd, NULL, NULL, NULL);
     CreateWindowW(L"static", L"Matricule:", WS_VISIBLE | WS_CHILD ,
                  220, 120, 200, 20, hWnd, NULL, NULL, NULL);
    hSpMatricule = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 310, 120, 170, 20, hWnd,
                         NULL, NULL, NULL);
    CreateWindowW(L"Button", L"Supprimer", WS_VISIBLE | WS_CHILD | WS_BORDER, 300, 200, 100, 30, hWnd,
                         Button_SupprimerVoitureB, NULL, NULL);

}
void WindowLouerContent(HWND hWnd){
    CreateWindowW(L"static", L"Verifier L'enregistrement de client", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER,
                  20, 40, 650, 20, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"static", L"CIN:", WS_VISIBLE | WS_CHILD ,
                  190, 90, 50, 20, hWnd, NULL, NULL, NULL);
    hLouerCIN = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 250, 90, 80, 20, hWnd,
                         NULL, NULL, NULL);
    CreateWindowW(L"Button", L"Verifier", WS_VISIBLE | WS_CHILD | WS_BORDER, 410, 85, 100, 30, hWnd,
                         Button_VerifierClient, NULL, NULL);

    
    //calendrier de commande

    CreateWindowW(L"static", L"calendrier de commande", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER,
                  20, 130, 650, 20, hWnd, NULL, NULL, NULL);


    CreateWindowW(L"static", L"Date de début :", WS_VISIBLE | WS_CHILD ,40, 170, 100, 20, hWnd, NULL, NULL, NULL);

    hDateDebut_Jour = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER, 150, 170, 20, 20, hWnd,
                         NULL, NULL, NULL);

    CreateWindowW(L"static", L"/", WS_VISIBLE | WS_CHILD ,177, 170, 20, 20, hWnd, NULL, NULL, NULL);

    hDateDebut_Mois = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER, 190, 170, 20, 20, hWnd,
                         NULL, NULL, NULL);

    CreateWindowW(L"static", L"/", WS_VISIBLE | WS_CHILD ,217, 170, 20, 20, hWnd, NULL, NULL, NULL);

    hDateDebut_annee = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER, 230, 170, 40, 20, hWnd,
                         NULL, NULL, NULL);

    CreateWindowW(L"static", L"Date de fin :", WS_VISIBLE | WS_CHILD ,
                  440, 170, 100, 20, hWnd, NULL, NULL, NULL);

    hDateFin_Jour = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER, 530, 170, 20, 20, hWnd,
                         NULL, NULL, NULL);

    CreateWindowW(L"static", L"/", WS_VISIBLE | WS_CHILD ,557, 170, 20, 20, hWnd, NULL, NULL, NULL);
    
    hDateFin_Mois = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER, 570, 170, 20, 20, hWnd,
                         NULL, NULL, NULL);

    CreateWindowW(L"static", L"/", WS_VISIBLE | WS_CHILD ,597, 170, 20, 20, hWnd, NULL, NULL, NULL);

    hDateFin_annee = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER, 610, 170, 40, 20, hWnd,
                         NULL, NULL, NULL);
                        
    CreateWindowW(L"static", L"Marque :", WS_VISIBLE | WS_CHILD , 190, 210, 100, 20,
                   hWnd, NULL, NULL, NULL);

    hMarques = CreateWindow(TEXT("combobox"), NULL, WS_CHILD | WS_VISIBLE | CBS_DROPDOWN, 280, 210, 170, 200, hWnd,
                         NULL, NULL, NULL);
    TCHAR tab[5][10] = {TEXT("Dacia"), TEXT("Renault"), TEXT("Peugeot"), TEXT("Ford"), TEXT("Fiat")};
    int i ;
    for (i = 0; i < 5; i++)
        SendMessage(hMarques, (UINT) CB_ADDSTRING, (WPARAM) 0, tab[i]);

    SendMessage(hMarques, (UINT) CB_SETCURSEL, (WPARAM) 0, (LPARAM) 0);


    CreateWindowW(L"Button", L"Chercher", WS_VISIBLE | WS_CHILD | WS_BORDER, 300, 250, 100, 30, hWnd,
                    Button_chercherModele, NULL, NULL);
    

    //affichage de modeles
    CreateWindowW(L"static", L"voiture sélectionnée", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER,
                  20, 300, 650, 20, hWnd, NULL, NULL, NULL);


    CreateWindowW(L"static", L"Modèle :", WS_VISIBLE | WS_CHILD ,
                  40, 355, 100, 20, hWnd, NULL, NULL, NULL);
    hModele = CreateWindow(TEXT("combobox"), NULL, WS_CHILD | WS_VISIBLE | CBS_DROPDOWN,
                        120, 355, 170, 120, hWnd, NULL, NULL, NULL);


    CreateWindowW(L"static", L"Prix :", WS_VISIBLE | WS_CHILD ,
                  390, 355, 70, 40, hWnd, NULL, NULL, NULL);
    hPrixJour = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER, 465, 355, 170, 20, hWnd,
                         NULL, NULL, NULL);



    //prix total
    
    CreateWindowW(L"static", L"Prix total", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER,
                  20, 420, 650, 20, hWnd, NULL, NULL, NULL);

    CreateWindowW(L"static", L"Prix total :", WS_VISIBLE | WS_CHILD ,
                  270, 470, 100, 20, hWnd, NULL, NULL, NULL);
    hPrixTotal = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER | ES_READONLY, 340, 470, 60, 20, hWnd,
                         NULL, NULL, NULL);
    CreateWindowW(L"static", L"DHs", WS_VISIBLE | WS_CHILD ,
                  405, 470, 20, 20, hWnd, NULL, NULL, NULL);

    CreateWindowW(L"Button", L"Calculer", WS_VISIBLE | WS_CHILD | WS_BORDER, 240, 510, 100, 30, hWnd,
                    Button_Calculer, NULL, NULL);

    CreateWindowW(L"Button", L"Reserver", WS_VISIBLE | WS_CHILD | WS_BORDER, 380, 510, 100, 30, hWnd,
                    Button_reserver, NULL, NULL);

    CreateWindowW(L"Button", L"sortie", WS_VISIBLE | WS_CHILD | WS_BORDER, 570, 520, 100, 30, hWnd,
                    Button_sortie, NULL, NULL);
    CreateWindowW(L"Button", L"effacer", WS_VISIBLE | WS_CHILD | WS_BORDER, 40, 520, 100, 30, hWnd,
                    Button_effacer, NULL, NULL);
}
//Evaluation
void WindowEvaluerContent(HWND hWnd){
    CreateWindowW(L"static", L"L'etat de voiture", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER,
                  20, 40, 650, 20, hWnd, NULL, NULL, NULL);

    CreateWindowW(L"static", L"ID reservation:", WS_VISIBLE | WS_CHILD ,
                  100, 110, 120, 20, hWnd, NULL, NULL, NULL);
    hID = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 200, 110, 100, 20, hWnd,
                         NULL, NULL, NULL);

    CreateWindowW(L"static", L"Marque:", WS_VISIBLE | WS_CHILD ,
                  340, 110, 120, 20, hWnd, NULL, NULL, NULL);
    hMarqueEval = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 450, 110, 120, 20, hWnd,
                         NULL, NULL, NULL);

    CreateWindowW(L"static", L"CIN:", WS_VISIBLE | WS_CHILD ,
                  100, 150, 70, 20, hWnd, NULL, NULL, NULL);
    hCINEval = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 200, 150, 100, 20, hWnd,
                         NULL, NULL, NULL);

    CreateWindowW(L"static", L"Date de retour:", WS_VISIBLE | WS_CHILD ,
                  340, 150, 120, 20, hWnd, NULL, NULL, NULL);
    hDateEval_jour = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 450, 150, 20, 20, hWnd,
                         NULL, NULL, NULL);
    CreateWindowW(L"static", L"/", WS_VISIBLE | WS_CHILD ,477, 150, 20, 20, hWnd, NULL, NULL, NULL);

    hDateEval_mois = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 490, 150, 20, 20, hWnd,
                         NULL, NULL, NULL);
    CreateWindowW(L"static", L"/", WS_VISIBLE | WS_CHILD ,517, 150, 20, 20, hWnd, NULL, NULL, NULL);

    hDateEval_annee = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 530, 150, 40, 20, hWnd,
                         NULL, NULL, NULL);

    CreateWindowW(L"static", L"Matricule:", WS_VISIBLE | WS_CHILD ,
                  100, 190, 120, 20, hWnd, NULL, NULL, NULL);
    hMatrEval = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 200, 190, 100, 20, hWnd,
                         NULL, NULL, NULL);

    CreateWindowW(L"static", L"Etat:", WS_VISIBLE | WS_CHILD ,
                  340, 190, 70, 20, hWnd, NULL, NULL, NULL);
    hEvalEtat = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 450, 190, 120, 20, hWnd,
                         NULL, NULL, NULL);

    CreateWindowW(L"Button", L"Evaluer", WS_VISIBLE | WS_CHILD | WS_BORDER, 290, 280, 100, 30, hWnd,
                         Button_EvaluerB, NULL, NULL);
    
}
void WindowStatistiqueContent(HWND hWnd){
    CreateWindowW(L"static", L"Statistique", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER,
                  20, 40, 650, 20, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Mois et annee:", WS_VISIBLE | WS_CHILD ,
                  250, 100, 120, 20, hWnd, NULL, NULL, NULL);
    hStatique_Mois = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 370, 100, 20, 20, hWnd,
                         NULL, NULL, NULL);
    CreateWindowW(L"static", L"/", WS_VISIBLE | WS_CHILD ,
                  397, 100, 650, 20, hWnd, NULL, NULL, NULL);
    hStatique_Annee = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 410, 100, 40, 20, hWnd,
                         NULL, NULL, NULL);
    CreateWindowW(L"Button", L"Chercher", WS_VISIBLE | WS_CHILD | WS_BORDER, 310, 150, 100, 30, hWnd,
                         Button_Statistique, NULL, NULL);

    CreateWindowW(L"static", L"Le gain:", WS_VISIBLE | WS_CHILD | SS_CENTER,
                  250, 220, 70, 20, hWnd, NULL, NULL, NULL);
    hPrixMoisS = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_READONLY , 350, 220, 70, 20, hWnd,
                         NULL, NULL, NULL);
}
