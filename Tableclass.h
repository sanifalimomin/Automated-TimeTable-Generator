#ifndef Tableclass_H
#define Tableclass_H
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Table
{
	string cname;
	string tid;
	char sec;
	int batch;
	bool empty;
	string tname;
	public:
		Table()
		{
			cname="";
			tid="";
			sec='\0';
			batch=0;
			tname="";
			empty=true;
		}
		void setdata(string name,string id,int batch,char sec,string tname)
		{
			cname=name;
			this->tname=tname;
			tid=id;
			this->sec=sec;
			this->batch=batch;
			empty=false;
		}
		bool isempty()
		{
			return empty;
		}
		string getcoursename()
		{
			return cname;
		}
		string gettid()
		{
			return tid;
		}
		int getbatch()
		{
			return batch;
		}
		char getsection()
		{
			return sec;
		}
		string getteachername()
		{
			return tname;
		}
		friend void display(Table **table,int day);
};

		void display(Table **table,int day)
		{
			
			ofstream fout;
			if(day==1)				
			fout.open("Monday.txt");
			else if (day==2)		
			fout.open("Tuesday.txt");
			else if (day==5)		
			fout.open("Wednesday.txt");
			else if (day==4)		
			fout.open("Thursday.txt");
			else if(day==5)			
			fout.open("Friday.txt");
			
			fout<<"|-------|---------------|---------------|---------------|---------------|---------------|---------------|---------------|---------------|\n";
			fout<<"|       |        1      |       2       |       3       |       4       |       5       |       6       |       7       |       8       |\n";
			fout<<"|-------|---------------|---------------|---------------|---------------|---------------|---------------|---------------|---------------|\n";
			fout<<"|       |"<<table[0][0].cname<<"\t\t|"<<table[0][1].cname<<"\t\t|"<<table[0][2].cname<<"\t\t|"<<table[0][3].cname<<"\t\t|"<<table[0][4].cname<<"\t\t|"<<table[0][5].cname<<"\t\t|"<<table[0][6].cname<<"\t\t|"<<table[0][7].cname<<"\t\t|"<<endl;
			fout<<"|Room 1 |"<<table[0][0].sec<<"\t\t|"<<table[0][1].sec<<"\t\t|"<<table[0][2].sec<<"\t\t|"<<table[0][3].sec<<"\t\t|"<<table[0][4].sec<<"\t\t|"<<table[0][5].sec<<"\t\t|"<<table[0][6].sec<<"\t\t|"<<table[0][7].sec<<"\t\t|"<<endl;
			fout<<"|       |"<<table[0][0].tname<<"\t\t|"<<table[0][1].tname<<"\t\t|"<<table[0][2].tname<<"\t\t|"<<table[0][3].tname<<"\t\t|"<<table[0][4].tname<<"\t\t|"<<table[0][5].tname<<"\t\t|"<<table[0][6].tname<<"\t\t|"<<table[0][7].tname<<"\t\t|"<<endl;
			fout<<"|       |"<<table[0][0].batch<<"\t\t|"<<table[0][1].batch<<"\t\t|"<<table[0][2].batch<<"\t\t|"<<table[0][3].batch<<"\t\t|"<<table[0][4].batch<<"\t\t|"<<table[0][5].batch<<"\t\t|"<<table[0][6].batch<<"\t\t|"<<table[0][7].batch<<"\t\t|"<<endl;
			fout<<"|-------|---------------|---------------|---------------|---------------|---------------|---------------|---------------|---------------|\n";
			fout<<"|       |"<<table[1][0].cname<<"\t\t|"<<table[1][1].cname<<"\t\t|"<<table[1][2].cname<<"\t\t|"<<table[1][3].cname<<"\t\t|"<<table[1][4].cname<<"\t\t|"<<table[1][5].cname<<"\t\t|"<<table[1][6].cname<<"\t\t|"<<table[1][7].cname<<"\t\t|"<<endl;
			fout<<"|Room 2 |"<<table[1][0].sec<<"\t\t|"<<table[1][1].sec<<"\t\t|"<<table[1][2].sec<<"\t\t|"<<table[1][3].sec<<"\t\t|"<<table[1][4].sec<<"\t\t|"<<table[1][5].sec<<"\t\t|"<<table[1][6].sec<<"\t\t|"<<table[1][7].sec<<"\t\t|"<<endl;
			fout<<"|       |"<<table[1][0].tname<<"\t\t|"<<table[1][1].tname<<"\t\t|"<<table[1][2].tname<<"\t\t|"<<table[1][3].tname<<"\t\t|"<<table[1][4].tname<<"\t\t|"<<table[1][5].tname<<"\t\t|"<<table[1][6].tname<<"\t\t|"<<table[1][7].tname<<"\t\t|"<<endl;
			fout<<"|       |"<<table[1][0].batch<<"\t\t|"<<table[1][1].batch<<"\t\t|"<<table[1][2].batch<<"\t\t|"<<table[1][3].batch<<"\t\t|"<<table[1][4].batch<<"\t\t|"<<table[1][5].batch<<"\t\t|"<<table[1][6].batch<<"\t\t|"<<table[1][7].batch<<"\t\t|"<<endl;
			fout<<"|-------|---------------|---------------|---------------|---------------|---------------|---------------|---------------|---------------|\n";
			fout<<"|       |"<<table[2][0].cname<<"\t\t|"<<table[2][1].cname<<"\t\t|"<<table[2][2].cname<<"\t\t|"<<table[2][3].cname<<"\t\t|"<<table[2][4].cname<<"\t\t|"<<table[2][5].cname<<"\t\t|"<<table[2][6].cname<<"\t\t|"<<table[2][7].cname<<"\t\t|"<<endl;
			fout<<"|Room 3 |"<<table[2][0].sec<<"\t\t|"<<table[2][1].sec<<"\t\t|"<<table[2][2].sec<<"\t\t|"<<table[2][3].sec<<"\t\t|"<<table[2][4].sec<<"\t\t|"<<table[2][5].sec<<"\t\t|"<<table[2][6].sec<<"\t\t|"<<table[2][7].sec<<"\t\t|"<<endl;
			fout<<"|       |"<<table[2][0].tname<<"\t\t|"<<table[2][1].tname<<"\t\t|"<<table[2][2].tname<<"\t\t|"<<table[2][3].tname<<"\t\t|"<<table[2][4].tname<<"\t\t|"<<table[2][5].tname<<"\t\t|"<<table[2][6].tname<<"\t\t|"<<table[2][7].tname<<"\t\t|"<<endl;
			fout<<"|       |"<<table[2][0].batch<<"\t\t|"<<table[2][1].batch<<"\t\t|"<<table[2][2].batch<<"\t\t|"<<table[2][3].batch<<"\t\t|"<<table[2][4].batch<<"\t\t|"<<table[2][5].batch<<"\t\t|"<<table[2][6].batch<<"\t\t|"<<table[2][7].batch<<"\t\t|"<<endl;
			fout<<"|-------|---------------|---------------|---------------|---------------|---------------|---------------|---------------|---------------|\n";
			fout<<"|       |"<<table[3][0].cname<<"\t\t|"<<table[3][1].cname<<"\t\t|"<<table[3][2].cname<<"\t\t|"<<table[3][3].cname<<"\t\t|"<<table[3][4].cname<<"\t\t|"<<table[3][5].cname<<"\t\t|"<<table[3][6].cname<<"\t\t|"<<table[3][7].cname<<"\t\t|"<<endl;
			fout<<"|Room 4 |"<<table[3][0].sec<<"\t\t|"<<table[3][1].sec<<"\t\t|"<<table[3][2].sec<<"\t\t|"<<table[3][3].sec<<"\t\t|"<<table[3][4].sec<<"\t\t|"<<table[3][5].sec<<"\t\t|"<<table[3][6].sec<<"\t\t|"<<table[3][7].sec<<"\t\t|"<<endl;
			fout<<"|       |"<<table[3][0].tname<<"\t\t|"<<table[3][1].tname<<"\t\t|"<<table[3][2].tname<<"\t\t|"<<table[3][3].tname<<"\t\t|"<<table[3][4].tname<<"\t\t|"<<table[3][5].tname<<"\t\t|"<<table[3][6].tname<<"\t\t|"<<table[3][7].tname<<"\t\t|"<<endl;
			fout<<"|       |"<<table[3][0].batch<<"\t\t|"<<table[3][1].batch<<"\t\t|"<<table[3][2].batch<<"\t\t|"<<table[3][3].batch<<"\t\t|"<<table[3][4].batch<<"\t\t|"<<table[3][5].batch<<"\t\t|"<<table[3][6].batch<<"\t\t|"<<table[3][7].batch<<"\t\t|"<<endl;
			fout<<"|-------|---------------|---------------|---------------|---------------|---------------|---------------|---------------|---------------|\n";
			fout<<"|       |"<<table[4][0].cname<<"\t\t|"<<table[4][1].cname<<"\t\t|"<<table[4][2].cname<<"\t\t|"<<table[4][3].cname<<"\t\t|"<<table[4][4].cname<<"\t\t|"<<table[4][5].cname<<"\t\t|"<<table[4][6].cname<<"\t\t|"<<table[4][7].cname<<"\t\t|"<<endl;
			fout<<"|Room 5 |"<<table[4][0].sec<<"\t\t|"<<table[4][1].sec<<"\t\t|"<<table[4][2].sec<<"\t\t|"<<table[4][3].sec<<"\t\t|"<<table[4][4].sec<<"\t\t|"<<table[4][5].sec<<"\t\t|"<<table[4][6].sec<<"\t\t|"<<table[4][7].sec<<"\t\t|"<<endl;
			fout<<"|       |"<<table[4][0].tname<<"\t\t|"<<table[4][1].tname<<"\t\t|"<<table[4][2].tname<<"\t\t|"<<table[4][3].tname<<"\t\t|"<<table[4][4].tname<<"\t\t|"<<table[4][5].tname<<"\t\t|"<<table[4][6].tname<<"\t\t|"<<table[4][7].tname<<"\t\t|"<<endl;
			fout<<"|       |"<<table[4][0].batch<<"\t\t|"<<table[4][1].batch<<"\t\t|"<<table[4][2].batch<<"\t\t|"<<table[4][3].batch<<"\t\t|"<<table[4][4].batch<<"\t\t|"<<table[4][5].batch<<"\t\t|"<<table[4][6].batch<<"\t\t|"<<table[4][7].batch<<"\t\t|"<<endl;
			fout<<"|-------|---------------|---------------|---------------|---------------|---------------|---------------|---------------|---------------|\n";
			fout<<"|       |"<<table[5][0].cname<<"\t\t|"<<table[5][1].cname<<"\t\t|"<<table[5][2].cname<<"\t\t|"<<table[5][3].cname<<"\t\t|"<<table[5][4].cname<<"\t\t|"<<table[5][5].cname<<"\t\t|"<<table[5][6].cname<<"\t\t|"<<table[5][7].cname<<"\t\t|"<<endl;
			fout<<"|Room 6 |"<<table[5][0].sec<<"\t\t|"<<table[5][1].sec<<"\t\t|"<<table[5][2].sec<<"\t\t|"<<table[5][3].sec<<"\t\t|"<<table[5][4].sec<<"\t\t|"<<table[5][5].sec<<"\t\t|"<<table[5][6].sec<<"\t\t|"<<table[5][7].sec<<"\t\t|"<<endl;
			fout<<"|       |"<<table[5][0].tname<<"\t\t|"<<table[5][1].tname<<"\t\t|"<<table[5][2].tname<<"\t\t|"<<table[5][3].tname<<"\t\t|"<<table[5][4].tname<<"\t\t|"<<table[5][5].tname<<"\t\t|"<<table[5][6].tname<<"\t\t|"<<table[5][7].tname<<"\t\t|"<<endl;
			fout<<"|       |"<<table[5][0].batch<<"\t\t|"<<table[5][1].batch<<"\t\t|"<<table[5][2].batch<<"\t\t|"<<table[5][3].batch<<"\t\t|"<<table[5][4].batch<<"\t\t|"<<table[5][5].batch<<"\t\t|"<<table[5][6].batch<<"\t\t|"<<table[5][7].batch<<"\t\t|"<<endl;
			fout<<"|-------|---------------|---------------|---------------|---------------|---------------|---------------|---------------|---------------|\n";
			fout<<"|       |"<<table[6][0].cname<<"\t\t|"<<table[6][1].cname<<"\t\t|"<<table[6][2].cname<<"\t\t|"<<table[6][3].cname<<"\t\t|"<<table[6][4].cname<<"\t\t|"<<table[6][5].cname<<"\t\t|"<<table[6][6].cname<<"\t\t|"<<table[6][7].cname<<"\t\t|"<<endl;
			fout<<"|Room 7 |"<<table[6][0].sec<<"\t\t|"<<table[6][1].sec<<"\t\t|"<<table[6][2].sec<<"\t\t|"<<table[6][3].sec<<"\t\t|"<<table[6][4].sec<<"\t\t|"<<table[6][5].sec<<"\t\t|"<<table[6][6].sec<<"\t\t|"<<table[6][7].sec<<"\t\t|"<<endl;
			fout<<"|       |"<<table[6][0].tname<<"\t\t|"<<table[6][1].tname<<"\t\t|"<<table[6][2].tname<<"\t\t|"<<table[6][3].tname<<"\t\t|"<<table[6][4].tname<<"\t\t|"<<table[6][5].tname<<"\t\t|"<<table[6][6].tname<<"\t\t|"<<table[6][7].tname<<"\t\t|"<<endl;
			fout<<"|       |"<<table[6][0].batch<<"\t\t|"<<table[6][1].batch<<"\t\t|"<<table[6][2].batch<<"\t\t|"<<table[6][3].batch<<"\t\t|"<<table[6][4].batch<<"\t\t|"<<table[6][5].batch<<"\t\t|"<<table[6][6].batch<<"\t\t|"<<table[6][7].batch<<"\t\t|"<<endl;
			fout<<"|-------|---------------|---------------|---------------|---------------|---------------|---------------|---------------|---------------|\n";
			fout<<"|       |"<<table[7][0].cname<<"\t\t|"<<table[7][1].cname<<"\t\t|"<<table[7][2].cname<<"\t\t|"<<table[7][3].cname<<"\t\t|"<<table[7][4].cname<<"\t\t|"<<table[7][5].cname<<"\t\t|"<<table[7][6].cname<<"\t\t|"<<table[7][7].cname<<"\t\t|"<<endl;
			fout<<"|Room 8 |"<<table[7][0].sec<<"\t\t|"<<table[7][1].sec<<"\t\t|"<<table[7][2].sec<<"\t\t|"<<table[7][3].sec<<"\t\t|"<<table[7][4].sec<<"\t\t|"<<table[7][5].sec<<"\t\t|"<<table[7][6].sec<<"\t\t|"<<table[7][7].sec<<"\t\t|"<<endl;
			fout<<"|       |"<<table[7][0].tname<<"\t\t|"<<table[7][1].tname<<"\t\t|"<<table[7][2].tname<<"\t\t|"<<table[7][3].tname<<"\t\t|"<<table[7][4].tname<<"\t\t|"<<table[7][5].tname<<"\t\t|"<<table[7][6].tname<<"\t\t|"<<table[7][7].tname<<"\t\t|"<<endl;
			fout<<"|       |"<<table[7][0].batch<<"\t\t|"<<table[7][1].batch<<"\t\t|"<<table[7][2].batch<<"\t\t|"<<table[7][3].batch<<"\t\t|"<<table[7][4].batch<<"\t\t|"<<table[7][5].batch<<"\t\t|"<<table[7][6].batch<<"\t\t|"<<table[7][7].batch<<"\t\t|"<<endl;
			fout<<"|-------|---------------|---------------|---------------|---------------|---------------|---------------|---------------|---------------|\n";
			fout.close();
		
		}
#endif
