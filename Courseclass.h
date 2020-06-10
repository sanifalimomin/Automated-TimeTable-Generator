#ifndef Courseclass_H
#define Courseclass_H
#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<algorithm>
#include"Teacherclass.h"
using namespace std;

class Course
{
	string course_name;
	string course_id;
	int c_hours;
	int noofteachers;
	int noofclasses;
	Teacher *teacher;
	char *sections;
	public:
		Course(){}
		int setCourse(string batch)
		{
			ofstream fout;
			
			if(batch=="Freshman")				
			fout.open("Freshman.txt",ios::app);
			else if (batch=="Sophomore")		
			fout.open("Sophomore.txt",ios::app);
			else if (batch=="Junior")			
			fout.open("Junior.txt",ios::app);
			else if (batch=="Senior")			
			fout.open("Senior.txt",ios::app);			
			
			char num=65;
			int i=0,noc;																			//number of classes
			bool check=false;

			cout<<"\n\nEnter Course Name: ";
			cin>>course_name;
			
			transform(course_name.begin(),course_name.end(),course_name.begin(),::toupper);			//filling
			
			
			cout<<"\n\n\t\t--------For "<<course_name<<" Course----------\n";
			cout<<"Enter Credit Hours: ";
			cin>>c_hours;
			cout <<"Enter Number of Classes: ";
			cin>>noofclasses;
			cout<<"Enter Number of Teachers for a Course: ";
			cin>>noofteachers;
			
			fout<<course_name<<"\t";
			fout<<c_hours<<endl;
			fout<<noofteachers<<endl;
			
			while((noofclasses/noofteachers>3)||(noofteachers>noofclasses))							// max 3 classes for a teacher OR techaer greater than num of section
			{			
				cout<<"Invalid Entry of Number of teacher and Number of classes\n\n";				//validation
				cout <<"Enter Number of Classes: ";	
				cin>>noofclasses;
				cout<<"Enter Number of Teachers for a Course: ";
				cin>>noofteachers;
			}	
			sections=new char[noofclasses];															//allacationg sections
			for(;i<noofclasses;i++)
			{
				*(sections+i)=num++;																//num='A',num+1='B'
			}
			noc=noofclasses;
			
			
			teacher=new Teacher[noofteachers];
			for(int j=0;j<noofteachers;j++)
			{
				(teacher+j)->setTeacher(batch);
				if(	noc%(noofteachers-j)==0	 &&	 (noc%2!=0	&& noofteachers-j==1)	)
				{
					if(noc>3)
						(teacher+j)->assignsection(sections,i,3,batch);	
					else
						(teacher+j)->assignsection(sections,i,noc,batch);
				}	
				else
				{
					(teacher+j)->assignsection(sections,i,0,batch);
				}
				
				noc=0;
				
				for(int k=0;k<i;k++)
				{
					if(*(sections+k)!='0')
					{
						check=true;
						noc++;
					}
				}	
				if(check==false){
					cout<<"No more Section Available for Teachers!"<<endl;//validation
					break;					
				}
				
			}
			fout<<endl;
			fout.close();
			return noofclasses;
		}
	
};


#endif
