#ifndef Batchclass_H
#define Batchclass_H
#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include"Courseclass.h"
using namespace std;

class Batch								// ABSTRACT CLASS
{									
	public:
	virtual void setBatch()=0;
	virtual ~Batch(){}			
};

class Freshman: public Batch
{
	int noofcourses;
	Course *courses;
	static int max_class;
	public:
		Freshman(int num)
		{
			noofcourses=num;
		}
		void setBatch()
		{
			int clas;
			char num=65;
			
			ofstream fout;
			fout.open("Freshman.txt");
			
			courses=new Course[noofcourses];
			
			fout<<noofcourses<<endl;
			for(int i=0;i<noofcourses;i++)
			{
				clas=(courses+i)->setCourse("Freshman");
				if(clas>max_class)
				max_class=clas;	
			}
			fout.close();
		}
		
		~Freshman()
		{					
			delete courses;
		}
};
int Freshman::max_class=0;				// static var =0





class Sophomore:public Batch
{
	int noofcourses;
	Course *courses;
	static int max_class;
	public:
		Sophomore(int num)
		{
			noofcourses=num;
		}
		void setBatch()
		{
			int clas;
			char num=65;
			
			
			ofstream fout;
			fout.open("Sophomore.txt");
			
			courses=new Course[noofcourses];
			
			fout<<noofcourses<<endl;
			for(int i=0;i<noofcourses;i++)
			{
				clas=(courses+i)->setCourse("Sophomore");
				if(clas>max_class)	
				max_class=clas;	
			}
			fout.close();
		}
		~Sophomore()
		{						
			delete courses;
		}
		
};
int Sophomore::max_class=0;





class Junior:public Batch
{
	int noofcourses;
	Course *courses;
	static int max_class;
	public:
		Junior(int num)
		{
			noofcourses=num;
		}
		void setBatch()
		{
			int clas;
			char num=65;
			
			ofstream fout;
			fout.open("Junior.txt");
			
			courses=new Course[noofcourses];
			
			fout<<noofcourses<<endl;
			for(int i=0;i<noofcourses;i++)
			{
				clas=(courses+i)->setCourse("Junior");
				if(clas>max_class)	
				max_class=clas;	
			}
			fout.close();
		}
		~Junior()
		{						
			delete courses;
		}
		
};
int Junior::max_class=0;





class Senior:public Batch
{
	int noofcourses;
	Course *courses;
	static int max_class;
	public:
		Senior(int num)
		{
			noofcourses=num;
		}
		void setBatch()
		{
			int clas;
			char num=65;
			
			ofstream fout;
			fout.open("Senior.txt");
			
			courses=new Course[noofcourses];
			
			fout<<noofcourses<<endl;
			for(int i=0;i<noofcourses;i++)
			{
				clas=(courses+i)->setCourse("Senior");
				if(clas>max_class)	max_class=clas;	
			}
			fout.close();
		}
		~Senior()
		{						
			delete courses;
		}
};
int Senior::max_class=0;





#endif
