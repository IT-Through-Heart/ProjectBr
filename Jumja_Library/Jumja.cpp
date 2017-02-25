#include "Jumja.h"
#include <stdlib.h>

Jumja::Jumja(){
	for (int i=0;i<6;i++)
		point[i]=rand()%2;
}
