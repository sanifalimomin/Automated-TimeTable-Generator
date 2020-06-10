#include<iostream>
#include<windows.h>
#include<fstream>
#include<string>
#include<stdlib.h>
#include"Timetableclass.h"
#include"Timetable.cpp"

using namespace std;
void increase();

void admin(HWND hwnd)
{
	::MessageBox (hwnd,"Press Ok To Generate Timetable ","Button was clicked",MB_OK);
	Timetable t1;
	t1.setdata();
	t1.generatetimetable();	
}
void student(HWND hwnd,int num)
{
	string line;
	ifstream fout;
	if(num==1)		
	fout.open("Monday.txt",ios::in);
	else if(num==2)		
	fout.open("Tuesday.txt",ios::in);
	else if(num==3)		
	fout.open("Wednesday.txt",ios::in);
	else if(num==4)		
	fout.open("Thursday.txt",ios::in);
	else if(num==5)		
	fout.open("Friday.txt",ios::in);
	if(fout.is_open()){
		increase();
		system("cls");
		system("COLOR F0");
		while(!fout.eof()){
			getline(fout,line);
			cout<<line<<endl;
		}
		fout.close();
	}
	else {
		::MessageBox (hwnd,"Time Table Not yet created","View Time Table",MB_OK);
	}
	
}

void increase()
{
    SMALL_RECT rect;
    COORD coord;
    coord.X = 200; // Defining our X and
    coord.Y = 50;  // Y size for buffer.

    rect.Top = 0;
    rect.Left = 0;
    rect.Bottom = coord.Y-1; // height for window
    rect.Right = coord.X-1;  // width for window

    HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE); // get handle
    SetConsoleScreenBufferSize(hwnd, coord);       // set buffer size
    SetConsoleWindowInfo(hwnd, TRUE, &rect);       // set window size
}
