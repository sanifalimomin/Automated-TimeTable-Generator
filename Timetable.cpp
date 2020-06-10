#include "Timetableclass.h"


void Timetable::setdata(){
			system("cls");
			system("Color F0");
			cout<<"\n\n\t\t----------Freshman----------\n";
			cout<<"\nEnter Number of Courses: ";
			cin>>noofcourses[0];
			
			batch =new Freshman(noofcourses[0]);
			batch->setBatch();
			system("cls");
			
			system("Color F1");
			cout<<"\n\n\t\t----------Sophomore----------\n";
			cout<<"\nEnter Number of Courses: ";
			cin>>noofcourses[1];
		
			batch =new Sophomore(noofcourses[1]);
			batch->setBatch();
			system("cls");
			
			system("Color F4");
			cout<<"\n\n\t\t----------Junior----------\n";
			cout<<"\nEnter Number of Courses: ";
			cin>>noofcourses[2];
		
			batch =new Junior(noofcourses[2]);
			batch->setBatch();
			system("cls");
			
			system("Color F2");
			cout<<"\n\n\t\t----------Senior----------\n";
			cout<<"\nEnter Number of Courses: ";
			cin>>noofcourses[3];
		
			batch =new Senior(noofcourses[3]);
			batch->setBatch();
			system("cls");
}

void Timetable::generatetimetable(){
	srand(time(NULL));
	
	int room,slot,day;
	int subjects,chours,teachers,tsec;
	int batch;
	
	string name,tid;
	char * sections;
	ifstream fin;
	
	Table **monday,**tuesday,**wednesday,**thursday,**friday;
	monday=new Table*[8];
	tuesday=new Table*[8];	
	wednesday=new Table*[8];	
	thursday=new Table*[8];	
	friday=new Table*[8];
	for(int i=0;i<8;i++){
		monday[i]=new Table[8];
		tuesday[i]=new Table[8];	
		wednesday[i]=new Table[8];	
		thursday[i]=new Table[8];	
		friday[i]=new Table[8];
	}
	
	
	for(int p=1;p<=4;p++){
		
		switch (p){
			case 1:{
				batch=16;
				fin.open("Freshman.txt",ios::in);
				break;
			}
			case 2:{
				batch=15;
				fin.open("Sophomore.txt",ios::in);
				break;
			}
			case 3:{
				batch=14;
				fin.open("Junior.txt",ios::in);
				break;
			}
			case 4:{
				batch=13;
				fin.open("Senior.txt",ios::in);
				break;
			}
		}
	
	
	fin>>subjects;
	for(int i=0;i<subjects;i++){
		fin>>name;
		fin>>chours;
		fin>>teachers;
		for(int j=0;j<teachers;j++){
			fin>>tid;
			fin>>tsec;
			sections=new char[tsec];
			for(int k=0;k<tsec;k++)	fin>>*(sections+k);
			for(int k=0;k<tsec;k++){

				for(int l=0;l<chours;l++){
					int found=1;
					day=rand()%5+1;
					room=rand()%8;
					slot=rand()%8;
					while(found!=0){
						found=0;
						switch (day){
							case 1:{
								if(monday[room][slot].isempty()==false){
										room=rand()%8;
										slot=rand()%8;
										found=1;
									}
								for(int w=0;w<8;w++){
								for(int e=0;e<8;e++){
									if(monday[w][e].getbatch()==batch && monday[w][e].getcoursename()==name&& monday[w][e].getsection()==sections[k]){
										day=rand()%5+1;
										found=1;
									}
								}
									
									if(monday[w][slot].gettid()==tid){
										slot=rand()%8;
										found=1;
									}
									else if(monday[w][slot].getsection()==sections[k]	&& monday[w][slot].getbatch()==batch){
										slot=rand()%8;
										found=1;
									}
								}
								if(found==0){
									string tname,filein;
									int f1=0;
									ifstream tout;
									tout.open("Teacher.txt",ios::in);
									while(!tout.eof()	&&	f1==0){
										tout>>filein;
										if(filein==tid){
											tout>>filein;
											tout>>filein;
											tname=filein;
											f1=1;
										}
									}
									monday[room][slot].setdata(name,tid,batch,sections[k],tname);
								}
								
								
							} 
								break;
							case 2: {
								if(tuesday[room][slot].isempty()==false){
										room=rand()%8;
										slot=rand()%8;
										found=1;
									}
								for(int w=0;w<8;w++){
								for(int e=0;e<8;e++){
									if(tuesday[w][e].getbatch()==batch &&tuesday[w][e].getcoursename()==name&& tuesday[w][e].getsection()==sections[k]){
										day=rand()%5+1;
										found=1;
									}
								}
									if(tuesday[w][slot].gettid()==tid){
										slot=rand()%8;
										found=1;
									}
									else if(tuesday[w][slot].getsection()==sections[k]	&& tuesday[w][slot].getbatch()==batch){
										slot=rand()%8;
										found=1;
									}
								}
								if(found==0){
									string tname,filein;
									int f1=0;
									ifstream tout;
									tout.open("Teacher.txt",ios::in);
									while(!tout.eof()	&&	f1==0){
										tout>>filein;
										if(filein==tid){
											tout>>filein;
											tout>>filein;
											tname=filein;
											f1=1;
										}
									}
									tuesday[room][slot].setdata(name,tid,batch,sections[k],tname);
								}
								
							}
								break;	
							case 3:{
								if(wednesday[room][slot].isempty()==false){
										room=rand()%8;
										slot=rand()%8;
										found=1;
								}
								for(int w=0;w<8;w++){
								for(int e=0;e<8;e++){
						
									if(wednesday[w][e].getbatch()==batch &&wednesday[w][e].getcoursename()==name&& wednesday[w][e].getsection()==sections[k]){
										day=rand()%5+1;
										found=1;
									}	
								}
								
									if(wednesday[w][slot].gettid()==tid){
										slot=rand()%8;
										found=1;
									}
									else if(wednesday[w][slot].getsection()==sections[k]	&& wednesday[w][slot].getbatch()==batch){
										slot=rand()%8;
										found=1;
									}
									
								}
								if(found==0){
									string tname,filein;
									int f1=0;
									ifstream tout;
									tout.open("Teacher.txt",ios::in);
									while(!tout.eof()	&&	f1==0){
										tout>>filein;
										if(filein==tid){
											tout>>filein;
											tout>>filein;
											tname=filein;
											f1=1;
										}
									}
									wednesday[room][slot].setdata(name,tid,batch,sections[k],tname);
								}
								
							}
								break;
							case 4: {
								if(thursday[room][slot].isempty()==false){
										room=rand()%8;
										slot=rand()%8;
										found=1;
								}
								for(int w=0;w<8;w++){
								for(int e=0;e<8;e++){
									
									if(thursday[w][e].getbatch()==batch &&thursday[w][e].getcoursename()==name&& thursday[w][e].getsection()==sections[k]){
										day=rand()%5+1;
										found=1;
									}
									
								}
									if(thursday[w][slot].gettid()==tid){
										slot=rand()%8;
										found=1;
									}
									else if(thursday[w][slot].getsection()==sections[k]	&& thursday[w][slot].getbatch()==batch){
										slot=rand()%8;
										found=1;
									}
								}
								if(found==0){
									string tname,filein;
									int f1=0;
									ifstream tout;
									tout.open("Teacher.txt",ios::in);
									while(!tout.eof()	&&	f1==0){
										tout>>filein;
										if(filein==tid){
											tout>>filein;
											tout>>filein;
											tname=filein;
											f1=1;
										}
									}
									thursday[room][slot].setdata(name,tid,batch,sections[k],tname);
								}
								
							}
								break;
							case 5: {			
								if(friday[room][slot].isempty()==false){
										room=rand()%8;
										slot=rand()%8;
										found=1;
								}
								for(int w=0;w<8;w++){
								for(int e=0;e<8;e++){
									if(friday[w][e].getbatch()==batch &&friday[w][e].getcoursename()==name&& friday[w][e].getsection()==sections[k]){
										day=rand()%5+1;
										found=1;
									}
									
								}
									if(friday[w][slot].gettid()==tid){
										slot=rand()%8;
										found=1;
									}
									else if(friday[w][slot].getsection()==sections[k]	&& friday[w][slot].getbatch()==batch){
										slot=rand()%8;
										found=1;
									}
								}
								if(found==0){
									string tname,filein;
									int f1=0;
									ifstream tout;
									tout.open("Teacher.txt",ios::in);
									while(!tout.eof()	&&	f1==0){
										tout>>filein;
										if(filein==tid){
											tout>>filein;
											tout>>filein;
											tname=filein;
											f1=1;
										}
									}
									friday[room][slot].setdata(name,tid,batch,sections[k],tname);
								}
								
							}
							
						}//switch end;
				}	//while loop
				}	//credit hours loop
				
			}	//classes loop
			
		}	//teachers loop
	}	//Subjects loop
	fin.close();

}//	loop for different batches
	
	display(monday,1);
	display(tuesday,2);
	display(wednesday,3);
	display(thursday,4);
	display(friday,5);
	
	for(int i=0;i<8;i++){
		delete []	monday[i];
		delete []	tuesday[i];
		delete []	wednesday[i];
		delete []	thursday[i];
		delete	[]	friday[i];
	}
	
	delete []	monday;
	delete []	tuesday;
	delete []	wednesday;
	delete []	thursday;
	delete	[]	friday;
	
	
}


/*Timetable::~Timetable(){
		delete batch;
	}*/
