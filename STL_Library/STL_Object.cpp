#include "STL.h"

using namespace std;

STL_Object::STL_Object(){
    x=y=z=0;
}

STL_Object::STL_Object(STL_Object& original){
   STL_Object();
   Triangle *newTri;
   for (int i=0;i<original.surfaces.size();i++){
      newTri = new Triangle(*original.surfaces[i],this);
      surfaces.push_back(newTri);
   }
   x=original.x;y=original.y;z=original.z;
}

STL_Object::~STL_Object(){
    while (surfaces.size()>0){
        delete surfaces.back();
        surfaces.pop_back();
    }
}


void STL_Object::write(FILE* f){
    vector<Triangle*>::iterator i;
    for (i=surfaces.begin();i!=surfaces.end();i++)
        (*i)->write(f);
}

void STL_Object::read(FILE *f){
    char c;
    for (int i=0;i<80;i++)
        fscanf(f,"%c",&c);
    unsigned int tri_num;
    fread(&tri_num,4,1,f);


    for (int i=0;i<tri_num;i++){
        Triangle *newTri = new Triangle(this);
        surfaces.push_back(newTri);
        newTri->read(f);
    }
}

void STL_Object::moveto(float x,float y,float z){
   this->x = x;
   this->y = y;
   this->z = z;
}

void STL_Object::expand(int mx, int my, int mz){
   for (vector<Triangle*>::iterator i = surfaces.begin();i!=surfaces.end();i++){
      (*i)->expand(mx,my,mz);
   }
}
void STL_Object::expand(int m){
   expand(m,m,m);
}
