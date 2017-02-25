#include <stdio.h>
#include "STL_Library\STL.h"
#include "Jumja_Library\Jumja.h"
#include <vector>
#include <time.h>

#define W 7
#define PADDING_LEFT 5
#define PADDING_UP 5
#define JUMJA_GAP (2.5)
#define LINE_GAP 10
#define BRAILLE_PER_LINE 10
#define BOARD_HEIGHT 100
#define JUMJA_RADIUS 0.75
int main(){
	srand(time(NULL));
   printf("Hello world!\n");
   Jumja jumjas[200];

   FILE *sphere_f = fopen("sphere.stl","rb");
   FILE *board_f = fopen("board.stl","rb");
   STL myStl;
   STL_Object *sphere = new STL_Object();
   STL_Object *board = new STL_Object();
   sphere->read(sphere_f);
   board->read(board_f);
	board->expand(200, 10, 100);
   myStl.add(board);

   int num = 0,line = 0,length = 200;
   for (int i=0;i<length;i++){
   	for (int j=0;j<6;j++){
      	if (jumjas[i].point[j]){
	         STL_Object* newOb = new STL_Object(*sphere);
	         newOb->moveto(num*W + JUMJA_GAP*((j>=3)?1:0) + PADDING_LEFT ,0,BOARD_HEIGHT-PADDING_UP-line*LINE_GAP-(j%3)*JUMJA_GAP);
	         myStl.add(newOb);
      	}
      }
      num++;
      if (num*W+PADDING_LEFT*2+JUMJA_GAP+JUMJA_RADIUS>BOARD_WIDTH){
         line++;
         num=0;
      }
	}

	myStl.moveto(100,100,0);

   FILE *newf = fopen("new.stl","wb");
   myStl.write(newf);
   fclose(sphere_f);
   fclose(newf);
}
