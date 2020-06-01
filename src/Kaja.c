#include <time.h>

#include "Kaja.h"

void Food(food *f){

        f->F.x=(((rand()%77)+1)*10);
        f->F.y=(((rand()%57)+1)*10);
}
