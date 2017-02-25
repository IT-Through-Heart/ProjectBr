
#include "STL.h"

void V3::setParent(Triangle* parent){
   this->parent = parent;
}
void V3::read(FILE* f)
{
   float buffer[3];
   fread(buffer,4,3,f);

   x = buffer[0];
   y = buffer[1];
   z = buffer[2];
}

void V3::write(FILE *f){
   float temp[3]={
      x+parent->parent->x + parent->parent->parent->x,
      y+parent->parent->y + parent->parent->parent->y,
      z+parent->parent->z + parent->parent->parent->z};
   fwrite(temp,4,3,f);
}

void V3::copy(V3 &original){
   x = original.x;
   y = original.y;
   z = original.z;
}
void V3::expand(int mx,int my,int mz){
   x*=mx;y*=my;z*=mz;
}
void V3::expand(int m){
   expand(m,m,m);
}
