#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int jour;
    int mois;
    int annee;
}Date;


int bissextile(int annee){
    return ((annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0));     
}

int joursParMois(Date d) {
    if (d.mois == 2)
        return bissextile(d.annee) ? 28 : 29;
    int jours[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return *(jours + d.mois - 1);
}

int valide_date(Date d){
    int valide = 1;

    if (d.annee >= 1800 && d.annee <= 9999){
        // check whether mon is between 1 and 12
        if(d.mois >= 1 && d.mois <= 12){
            // check for days in feb
            if (d.mois == 2){
                if (bissextile(d.annee) && d.jour == 29){
                    valide = 1;
                }
                else if(d.jour > 28){
                    valide = 0;
                }
            }

            // check for days in April, June, September and November
            else if (d.mois == 4 || d.mois == 6 || d.mois == 9 || d.mois == 11) {
                if (d.jour > 30){
                    valide = 0;
                }
            }

            // check for days in rest of the months 
            // i.e Jan, Mar, May, July, Aug, Oct, Dec
            else if(d.jour > 31){            
                valide = 0;
            }        
        }

        else{
            valide = 0;
        }
    }
    else{
        valide = 0;
    }
    return valide;

}
int comparer_dates(Date d1, Date d2){
    if (d2.annee < d1.annee)
       return 0;
    else if (d2.annee > d1.annee)
       return 1;
    if (d2.annee == d1.annee)
    {
        if (d2.mois<d1.mois)
            return 0;
        else if (d2.mois>d1.mois)
            return 1;
        else if (d2.jour<d1.jour)
            return 0;
        else if(d2.jour>d1.jour)
            return 1;
        else
            return 0;
    }
}


int comparer_dates_(Date d1, Date d2){
    if (d2.annee < d1.annee)
       return 0;
    else if (d2.annee > d1.annee)
       return 1;
    if (d2.annee == d1.annee)
    {
        if (d2.mois<d1.mois)
            return 0;
        else if (d2.mois>d1.mois)
            return 1;
        else if (d2.jour<d1.jour)
            return 0;
        else if(d2.jour>d1.jour)
            return 1;
        else
            return 1;
    }
}



int diffDates(Date d1, Date d2) {
  if (d1.annee <= d2.annee) {
    if ((d1.mois < d2.mois && d1.annee == d2.annee) || d1.annee < d2.annee) {
      int s = (d1.jour != 1) ? joursParMois(d1) - (d1.jour) + 1 : joursParMois(d1);
      
      d1.jour = 1;
      if (d1.mois == 12) {
        d1.mois = 1;
        d1.annee++;
      } else
        d1.mois++;

      return s + diffDates(d1, d2);
    } else if (d1.mois == d2.mois)
      return d2.jour - d1.jour;
    
    return -1;
  }
  return -1;
}

int verifierDate(Date d1, Date d2){
    if(valide_date(d1)&&valide_date(d2)){
        if(comparer_dates(d1,d2)){
            return 1;
        }
    }
    return 0;
}

int estEntre(Date debut, Date m, Date fin){
    return comparer_dates_(debut,m)&&comparer_dates_(m,fin);
}

//intersection =ensemble vide   =>  return 0
int intersection(Date d1, Date d2, Date d3, Date d4){
    return estEntre(d1,d3,d2) || estEntre(d1,d4,d2) || estEntre(d3,d1,d4) ;
}
