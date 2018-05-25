
#include "Kigyo.h"
#include "Konstansok.h"

kigyoElem *noveles(kigyoElem *kigyo){
        kigyoElem *mozgo;
        kigyoElem *novkigyo = (kigyoElem*)malloc(sizeof(kigyoElem));
        for(mozgo = kigyo; mozgo->kov != NULL; mozgo = mozgo->kov)
            ;


            novkigyo->eloz = mozgo;
            novkigyo->i = mozgo->i;
            novkigyo->kov = NULL;
             if(mozgo->i == fel){
                novkigyo->K.x = mozgo->K.x;
                novkigyo->K.y = mozgo->K.y+10;}
             else if(mozgo->i == le){
                novkigyo->K.x = mozgo->K.x;
                novkigyo->K.y = mozgo->K.y-10;}
            else if(mozgo->i == jobbra){
                novkigyo->K.x = mozgo->K.x-10;
                novkigyo->K.y = mozgo->K.y;}
            else if(mozgo->i == balra){
                novkigyo->K.x = mozgo->K.x+10;
                novkigyo->K.y = mozgo->K.y;}
             novkigyo->K.h=KIGYO_M;

             novkigyo->K.w=KIGYO_SZ;


            mozgo->kov = novkigyo;

            return kigyo;
}

kigyoElem *lepes(kigyoElem *kigyo){
    kigyoElem *mozgo;
        if(kigyo->i != 0){
                /*léptetés*/
            for(mozgo = kigyo; mozgo != NULL; mozgo = mozgo->kov){
                if(mozgo->i==fel)
                    mozgo->K.y-=10;
                else if(mozgo->i==le)
                    mozgo->K.y+=10;
                else if(mozgo->i==jobbra)
                    mozgo->K.x+=10;
                else if(mozgo->i==balra)
                    mozgo->K.x-=10;
            }

        /*irány átadása*/
    for(mozgo = kigyo; mozgo->kov != NULL; mozgo = mozgo->kov)
        ;

    for( ; mozgo != kigyo ; mozgo = mozgo->eloz){
            mozgo->i = mozgo->eloz->i;
    }}
return kigyo;
}
void increaseScore(kigyoElem *kigyo){
    kigyo->score+=10;
}
