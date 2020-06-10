#ifndef Timetableclass_H
#define Timetableclass_H
#include<iostream>
#include<string>
#include<fstream>
#include<time.h>
#include<stdlib.h>
#include<cstring>
#include<windows.h>
#include"Batchclass.h"
#include"Tableclass.h"
using namespace std;

class Timetable
{
	Batch *batch;
	int noofcourses[4];
	public:
		void setdata();
		void generatetimetable();
};
#endif
