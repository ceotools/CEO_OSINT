#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <Windows.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;

string green = "\033[32m";
string blue = "\033[94m";
string white = "\033[97m";

void banner(){
	system("cls");
    ifstream Banner("../Banners/Launcher.txt");
    string content;
    while(getline(Banner,content)){
        cout<<green<<content<<endl;
    }
    Banner.close();
}

int Core(){
    int option = 0;
    while (option != 3){
		banner();
	    cout<<green<<"\n\n[+]"<<white<<"WOULD YOU LIKE TO:\n(1)EXECUTE CEO_OSINT\n(2)ACTIVATE DATABASE(LOCALHOST ONLY)\n(3)EXIT\n\n"<<green<<"[#CEO_OSINT#]"<<white<<"-->";
	    cin>>option;
	    if(option == 1){
			cout<<green<<"\n[+]"<<white<<"EXECUTING CEO_OSINT";
			Sleep(2);
			chdir("..");
	        system("python CEO_OSINT.py");
	        chdir("Launchers");
	    }
	    else if(option == 2){
			cout<<blue<<"\n[I]"<<white<<"ACTIVATING DATABASE...";
			Sleep(2);
	        system("START /B php -S 127.0.0.1:5001 -t ../GUI 2>NUL >NUL");
	        cout<<blue<<"\n\n[I]"<<white<<"DATABASE STARTED ON: http://127.0.0.1:5001\n\nPRESS ANY KEY TO STOP";
	        system("pause 2>NUL >NUL");
			cout<<blue<<"\n\n[I]"<<white<<"STOPPING DATABASE\n";
	        system("taskkill /F /IM php.exe 2>NUL >NUL");
			Sleep(2);
	        cout<<"\nDATABASE STOPPED";
			Sleep(3);
	    }
	    else if(option == 3){
	    	return 0;
		}
		else{
			Core();
		}
	}
}

int main(){
	Core();
}
