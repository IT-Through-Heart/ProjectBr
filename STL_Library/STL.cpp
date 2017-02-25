#include "STL.h"

using namespace std;

STL::STL(){
   x=y=z=0;
}
STL::~STL(){
    while (objects.size()>0){
        delete objects.back();
        objects.pop_back();

    }
}

void STL::add(STL_Object* new_ob){
    objects.push_back(new_ob);
    new_ob->parent = this;
}

void STL::write(FILE* f){
    fprintf(f,"binary stl file");
    for (int i=0;i<65;i++)
        fprintf(f," ");
    vector<STL_Object*>::iterator i;
    unsigned int triangle_num = 0;
    for (i=objects.begin();i!=objects.end();i++)
        triangle_num+=(*i)->surfaces.size();
    fwrite(&triangle_num,4,1,f);

    for (i=objects.begin();i!=objects.end();i++)
        (*i)->write(f);
}

void STL::moveto(float x,float y,float z){
   this->x = x;
   this->y = y;
   this->z = z;
}
