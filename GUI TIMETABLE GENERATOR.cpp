#include<windows.h>
#include<cstring>
#include"Generator.cpp"


HWND B1,B2,B3,B4,B5,B6,BCLOSE;
HWND textBox,hlogo;
HWND textField0,textField1,textField2,textField3,textField4,textField5,textField6,textField7,textField10,textField11;
char username[5],password[5];
HBITMAP hpic;
void loadimage();
HWND hbitmapdisplay;
HBITMAP hmybitmap;

LRESULT CALLBACK Gui(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) // HWND WINDOW HANDLER
{
switch(Message) {
		case WM_CREATE:{
			hmybitmap = (HBITMAP)LoadImage(NULL, "i.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			hbitmapdisplay = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 335, 05, 10, 10, hwnd, NULL, NULL, NULL);
			SendMessage(hbitmapdisplay, STM_SETIMAGE, IMAGE_BITMAP,(LPARAM)hmybitmap);
			textField0 = CreateWindow("STATIC",
									" Welcome To FAST-NUCES Karachi Campus ",
									WS_VISIBLE | WS_CHILD | WS_BORDER  ,
									40,20,290,30,
									hwnd,
									NULL,NULL,NULL);
								
			textField1 = CreateWindow("STATIC",
									" Timetable Generator System",
									WS_VISIBLE | WS_CHILD | WS_BORDER,
									40,70,230,30,
									hwnd,
									NULL,NULL,NULL);
			
			textField2 = CreateWindow("STATIC",
									"FOR ADMIN :",
									WS_VISIBLE | WS_CHILD ,
									30,130,90,25,
									hwnd,
									NULL,NULL,NULL);
			textField6 = CreateWindow("STATIC",
									"Username :",
									WS_VISIBLE | WS_CHILD ,
									35,165,90,25,
									hwnd,
									NULL,NULL,NULL);
			textField7 = CreateWindow("STATIC",
									"Password :",
									WS_VISIBLE | WS_CHILD ,
									35,190,90,25,
									hwnd,
									NULL,NULL,NULL);
			textField10=CreateWindow("EDIT",
										"",
										WS_VISIBLE	|WS_CHILD	|	WS_BORDER,
										130,165,230,20,
										hwnd,NULL,NULL,NULL);
			
			textField11=CreateWindow("EDIT",
										"",
										WS_VISIBLE	|WS_CHILD	|	WS_BORDER,
										130,190,230,20,
										hwnd,NULL,NULL,NULL);							
			B1 = CreateWindow("BUTTON",
									"Sign In",
									WS_VISIBLE | WS_CHILD | WS_BORDER,
									370,165,80,45,
									hwnd,
									(HMENU) 1,NULL,NULL);
				
			textField3 = CreateWindow("STATIC",
									"FOR STUDENT :",
									WS_VISIBLE | WS_CHILD ,
									30,225,250,25,
									hwnd,
									NULL,NULL,NULL);
			textField5 = CreateWindow("STATIC",
									"View Timetable for day :",
									WS_VISIBLE | WS_CHILD ,
									35,250,220,25,
									hwnd,
									NULL,NULL,NULL);						
			B2 = CreateWindow("BUTTON",
									"Monday",
								WS_VISIBLE | WS_CHILD | WS_BORDER,
									50,300,100,60,
									hwnd,
									(HMENU) 2,NULL,NULL);
			B3 = CreateWindow("BUTTON",
									"Tuesday",
								WS_VISIBLE | WS_CHILD | WS_BORDER,
									200,300,100,60,
									hwnd,
									(HMENU) 3,NULL,NULL);
			B4 = CreateWindow("BUTTON",
									"Wednesday",
								WS_VISIBLE | WS_CHILD | WS_BORDER,
									350,300,100,60,
									hwnd,
									(HMENU) 4,NULL,NULL);
			B5 = CreateWindow("BUTTON",
									"Thursday",
								WS_VISIBLE | WS_CHILD | WS_BORDER,
									50,410,100,60,
									hwnd,
									(HMENU) 5,NULL,NULL);
			B6 = CreateWindow("BUTTON",
									"Friday",
								WS_VISIBLE | WS_CHILD | WS_BORDER,
									200,410,100,60,
									hwnd,
									(HMENU) 6,NULL,NULL);
			
			BCLOSE = CreateWindow("BUTTON",
									"Close",
									WS_VISIBLE | WS_CHILD | WS_BORDER,
									350,410,100,60,
									hwnd,
									(HMENU) 7,NULL,NULL);
				
			textField4 = CreateWindow("STATIC",
									"          Project Made By:\n\n\n Sanif Ali Momin\n",
									WS_VISIBLE | WS_CHILD | WS_BORDER,
									110,540,250,100,
									hwnd,
									NULL,NULL,NULL);
			hlogo = CreateWindow("STATIC",NULL,
									WS_VISIBLE | WS_CHILD | SS_BITMAP,
									50,250,220,25,
									hwnd,
									NULL,NULL,NULL);
			SendMessage(hlogo,STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hpic);					
							
			
			break;
		}

		
		case WM_COMMAND:{
			switch(LOWORD(wParam))
			{
				case 1:
					int var1,var2;
					var1=GetWindowText(textField10,&username[0],6);
					var2=GetWindowText(textField11,&password[0],6);	
					if (strcmp(username,"adminadmin")==0	&&	strcmp(password,"admin")==0){
						admin(hwnd);
					}
					else {
						::MessageBox (hwnd,"Sign in Window","Wrong Username or Password!",MB_OK);
					}
					break;
				case 2:
					student(hwnd,1);
					break;
				
				case 3:
					student(hwnd,2);
					break;
					
				case 4:
					student(hwnd,3);
					break;
					
				case 5:
					student(hwnd,4);
					break;
					
				case 6:
					student(hwnd,5);
					break;
				case 7:
					PostQuitMessage(0);
					break;
			}
			break;
		}
		/* Upon destruction, tell the main thread to stop */
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		
		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}    
	return 0;
}

/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) 
{
	
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG msg; /* A temporary location for all messages */

	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = Gui; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	system("COLOR F0");
	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Timetable Generator",WS_VISIBLE|WS_MINIMIZEBOX|WS_SYSMENU,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		500, /* width */
		700, /* height */
		NULL,NULL,hInstance,NULL);

	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	/*
		This is the heart of our program where all input is processed and 
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produce unreasonably high CPU usage
	*/
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); /* Send it to WndProc */
	}
	return msg.wParam;
	
}

