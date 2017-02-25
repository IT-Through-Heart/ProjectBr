#include "STL.h"

Triangle::Triangle(STL_Object *parent){
   this->parent = parent;
   for (int i=0;i<3;i++)
      p[i].setParent(this);
   normal.setParent(this);
}

Triangle::Triangle(Triangle &original, STL_Object *parent) : Triangle(parent){
   for (int i=0;i<3;i++){
		p[i].copy(original.p[i]);
   }
   normal.copy(original.normal);
}

void Triangle::read(FILE* f){
   normal.read(f);
   for (int i=0;i<3;i++)
      p[i].read(f);
   unsigned short a;
   fread(&a,2,1,f);
}

void Triangle::write(FILE *f){
   normal.write(f);
   for (int i=0;i<3;i++)
      p[i].write(f);
   unsigned __int16 a=0;
   fwrite(&a,2,1,f);
}

void Triangle::expand(int mx,int my,int mz){
   normal.expand(mx,my,mz);
   for (int i=0;i<3;i++)
      p[i].expand(mx,my,mz);
}
void Triangle::expand(int m){
   expand(m,m,m);
}
