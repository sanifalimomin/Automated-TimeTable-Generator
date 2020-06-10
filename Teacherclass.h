#ifndef Teacherclass_H
#define Teacherclass_H
#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<algorithm>
using namespace std;

class Teacher{
	string fname;
	string lname;
	string id;
	int availabledays;
	int *days;
	char *section;
	public:
		Teacher(){}
		void setTeacher(string batch)
		{
			ofstream fout;	//FILING BATCH				
			ofstream tout;	//FILING TEACHER
			tout.open("Teacher.txt",ios::app);
			
			if(batch=="Freshman")				
			fout.open("Freshman.txt",ios::app);
			else if (batch=="Sophomore")		
			fout.open("Sophomore.txt",ios::app);
			else if (batch=="Junior")			
			fout.open("Junior.txt",ios::app);
			else if (batch=="Senior")			
			fout.open("Senior.txt",ios::app);
			
			cout<<"\n\nEnter Teacher First Name: ";
			cin>>fname;
			transform(fname.begin(),fname.end(),fname.begin(),::toupper);
			cout<<"Enter Teacher Last Name: ";
			cin>>lname;
			transform(lname.begin(),lname.end(),lname.begin(),::toupper);
			cout<<"Enter Teacher ID: ";
			cin>>id;
			
			tout<<id<<"\t";
			tout<<fname<<"\t";
			tout<<lname<<"\n";
			fout<<id<<"\t";
			fout.close();
			tout.close();
		}
		void assignsection(char *classes,int num,int sec,string batch)
		{
			int tsec;
			ofstream fout;
			
			if(batch=="Freshman")				
			fout.open("Freshman.txt",ios::app);
			else if (batch=="Sophomore")		
			fout.open("Sophomore.txt",ios::app);
			else if (batch=="Junior")			
			fout.open("Junior.txt",ios::app);
			else if (batch=="Senior")			
			fout.open("Senior.txt",ios::app);
			
			if (sec!=0)
			tsec=sec;
			else
			{														//when teacher can have less than 3 sections
				do
				{
					cout<<"Enter Number of Section to teach(MAX 3): ";		// VALIDATION
					cin>>tsec;
				}	while(tsec>3);
			}
			cout<<"Select Sections for Teacher: ";
			cout<<endl;
			fout<<tsec<<endl;
			
			section=new char[tsec];
			for(int i=0;i<tsec;i++)
			{
				
				bool ans=false,ans2=false;
				char a;
				cout<<"Sections Available: ";
				
				for(int j=0;j<num;j++)	
				{
					if(*(classes+j)!='0')
					{
						cout<<*(classes+j)<<"\t";
						ans=true;
					}
				}
				cout<<endl;
				cin>>a;
				
				if (ans==false)
				{
					cout<<"No more section available to teach!"<<endl;
					break;
				}
				else 
				{
					if (islower(a))	
					{
						a=toupper(a);
					}
					for(int k=0;k<num;k++)
					{
						if (*(classes+k)==a)
						{
							*(classes+k)='0';
							*(section+i)=a;
							
							fout<<a;
							ans2=true;
							break;
						}
					}
					if (ans2==false&&ans==false)
					{
						cout<<"Section Not on List!"<<endl;
						i--;
					}
				}
			}
			fout<<endl;
			fout.close();	
		}
		~Teacher()
		{
			delete days;
			delete section;
		}
};

#endif
		
