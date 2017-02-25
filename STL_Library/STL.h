#ifndef _STL_H
#define _STL_H

#include <vector>
#include <stdio.h>

using namespace std;
class STL;
class STL_Object;
class Triangle;
class V3;

class V3
{
public:
   void setParent(Triangle *parent);
	void read(FILE* f);
	void write(FILE* f);
   void copy(V3 &original);
   void expand(int mx,int my,int mz);
   void expand(int m);
   float x, y, z;
private:
   Triangle *parent;
};

class Triangle
{
public:
   Triangle(STL_Object *parent);
   Triangle(Triangle &original,STL_Object *parent);
	void read(FILE* str);
	void write(FILE* p);
   void expand(int mx,int my,int mz);
   void expand(int m);

	V3 p[3],normal;
   STL_Object* parent;
private:
};

class STL_Object{
public:
	STL_Object();
	STL_Object(STL_Object &original);
	~STL_Object();
	void write(FILE* f);
	void read(FILE* f);
	void moveto(float x,float y,float z);
   void expand(int mx,int my,int mz);
   void expand(int m);
	vector<Triangle*> surfaces;
	float x, y, z;
   STL *parent;
};

class STL{
public:
   STL();
   ~STL();
   void add(STL_Object* new_ob);
   void write(FILE* f);
   vector<STL_Object*> objects;
	void moveto(float x,float y,float z);
   float x,y,z;
};

#include "STL.cpp"
#include "STL_Object.cpp"
#include "Triangle.cpp"
#include "V3.cpp"

#endif
