/*
Text file handling code for - Automatic Temperature and Attendance Machine [ ATAM ]
*/

#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <sstream>

using namespace std;

char dept_class[5][10] = {"AIML-1","CSE-A-1","CSE-B-1","CSE-C-1","IT-1"};

class atam{
	
	int sno, dept, dd, mm, yy, n, x, found, edited;
	char uid[20], name[25], regno[15], phno[11], username[9], pwd[9], seperator;
	string line , find ,  _tag_ , _name_ , _regno_ , _class_ , _phno_, uid01;
	string dataUID, dataDATE, dataTIME, dataTEMP;
	
	public:
		
		void add_user();
		void view_all_user();
		void search_user();
		void edit_user();
			void editByRegno();	
			void editByName();
		void del_user();
		void view_log();
			void view_user_log();
			void view_class_log();
		string date();
		int password();
		void mainmenu();
		
}o;
/*---------------------------------------------------------------------------------------------------------------------------------*/
void atam::add_user(){
	
	system("cls");
	int a = o.password();
	if(a==1){
		ofstream fout;
		fout.open("register.txt", ios::app);
		if(!fout){
			cout<<"\n ERROR WHILE OPENING THE FILE!";
		}
		if(fout){
			cout<<"\n Enter No.of Users : "; cin>>o.n;
			for(int i=0; i<o.n; i++){
				cout<<"\n ----------------------------------------------------------";
				cout<<"\n Input Details "<<i+1<<" :-";
				cout<<"\n ******************\n"; fflush(stdin);
				cout<<"\n Enter Tag UID   :  "; cin.getline(o.uid,20); fflush(stdin); 
				cout<<"\n Enter Name      :  "; cin.getline(o.name,25); fflush(stdin);
				cout<<"\n Enter Reg.No    :  "; cin.getline(o.regno,15); fflush(stdin);
				cout<<"\n Enter Phone No. :  "; cin.getline(o.phno,11); fflush(stdin);
		pos1:	cout<<"\n Department Classes (Class-Year):-";
				cout<<"\n *********************************";
				cout<<"\n 1. AIML-1\n 2. CSE-A-1\n 3. CSE-B-1\n 4. CSE-C-1\n 5. IT-1\n\n Your Option : "; cin>>o.dept;
				switch(o.dept){
					case 1:
						fout<<o.uid<<","<<o.name<<","<<o.regno<<","<<dept_class[0]<<","<<o.phno<<endl;
						break;
					case 2:
						fout<<o.uid<<","<<o.name<<","<<o.regno<<","<<dept_class[1]<<","<<o.phno<<endl;
						break;
					case 3:
						fout<<o.uid<<","<<o.name<<","<<o.regno<<","<<dept_class[2]<<","<<o.phno<<endl;
						break;
					case 4:
						fout<<o.uid<<","<<o.name<<","<<o.regno<<","<<dept_class[3]<<","<<o.phno<<endl;
						break;
					case 5:
						fout<<o.uid<<","<<o.name<<","<<o.regno<<","<<dept_class[4]<<","<<o.phno<<endl;
						break;
					default:
						cout<<"\n ---INVALID OPTION---\n";
						goto pos1;
				}
			}
		}
		fout.close();
	}
	if(a==0){
		cout<<"\n ---Incorrect Username or Password---";
	}
	
	int opt;
	cout<<"\n\n================================================================================================";
	cout<<"\n\n 1. Main Menu \t2. Exit \n\n Your Option : ";cin>>opt;
	switch(opt){
		case 1: 
			o.mainmenu();
			break;
		case 2:
			break;
		default:
			cout<<"\n\n ---Invalid Option---";
	}
}
/*---------------------------------------------------------------------------------------------------------------------------------*/
void atam::view_all_user(){
	
	system("cls");	
	ifstream fin;
	fin.open("register.txt", ios::in);
	if(!fin){
		cout<<"\n ERROR WHILE OPENING \"register.txt\" FILE!";
	}
	if(fin){
		cout<<"\n YOUR DETAILS";
		cout<<"\n ************\n";
		cout<<"\n S.NO  |      TAG UID      |           NAME           |     REG.NO     |    CLASS    |    PHONE    ";
		cout<<"\n---------------------------------------------------------------------------------------------------";
		if( fin.peek() == ifstream::traits_type::eof())
			cout<<"\n   ---YOUR FILE \"register.txt\" IS EMPTY---";
		sno = 1;
		while(getline(fin,line))
		{
			stringstream linestream(line);
			while(getline(linestream,_tag_,',')){
				getline(linestream,_name_,',');
				getline(linestream,_regno_,',');
				getline(linestream,_class_,',');
				getline(linestream,_phno_,',');
				setfill(' ');
				cout<<"\n "<<left<<setw(5)<<sno<<" | "<<setw(17)<<_tag_<<" | "<<setw(24)<<_name_<<" | "<<setw(14)<<_regno_<<" | "<<setw(11)<<_class_<<" | "<<setw(11)<<_phno_;
				cout<<"\n---------------------------------------------------------------------------------------------------";
				sno++;
			}
		}
	}
	fin.close();
	
	int opt;
	cout<<"\n\n 1. Main Menu \t2. Exit \n\n Your Option : ";cin>>opt;
	switch(opt){
		case 1: 
			o.mainmenu();
			break;
		case 2:
			break;
		default:
			cout<<"\n\n ---Invalid Option---";
	}
}
/*---------------------------------------------------------------------------------------------------------------------------------*/
void atam::search_user(){
	
	system("cls");
	ifstream fin;
	fin.open("register.txt");
	if(!fin){
		cout<<"\n ERROR WHILE OPENING \"register.txt\" FILE!";
	}
	if(fin){
		if( fin.peek() == ifstream::traits_type::eof())
			cout<<"\n   ---YOUR FILE \"register.txt\" IS EMPTY---";
		found = 0;
		cout<<"\n Enter Reg.No to Search User : "; fflush(stdin); getline(cin,find);
		while(getline(fin,line))
		{
			stringstream linestream(line);
			getline(linestream,_tag_,',');
			getline(linestream,_name_,',');
			getline(linestream,_regno_,',');
			getline(linestream,_class_,',');
			getline(linestream,_phno_,',');
			
			if(find == _regno_){
				cout<<"\n\n ----------------------------------------------------------\n";
				cout<<"\n Tag UID    :  "<<_tag_;
				cout<<"\n Name       :  "<<_name_;
				cout<<"\n Reg.No     :  "<<_regno_;
				cout<<"\n Class      :  "<<_class_;
				cout<<"\n Phone No.  :  "<<_phno_;
				found = 1;
			}
		}
		if(found == 0){
			cout<<"\n\n ----------------------------------------------------------\n";
			cout<<"\n ---Record Not Found---";
		}		
	}
	fin.close();
	int opt;
	cout<<"\n\n 1. Main Menu \t2. Exit \n\n Your Option : ";cin>>opt;
	switch(opt){
		case 1: 
			o.mainmenu();
			break;
		case 2:
			break;
		default:
			cout<<"\n\n ---Invalid Option---";
	}
}
/*---------------------------------------------------------------------------------------------------------------------------------*/
void atam::edit_user(){
	
	system("cls");
	int a = o.password();
	if(a==1){
		int opt;
pos2:	cout<<"\n 1. Edit User by Reg.No";
		cout<<"\n 2. Edit User by Name";
		cout<<"\n 3. Exit";
		cout<<"\n\n Your Option : "; cin>>opt;
		switch(opt){
			case 1:
				o.editByRegno();
				break;
			case 2:
				o.editByName();
				break;
			case 3:
				break;
			default:
				cout<<"\n ---INVALID OPTION---\n";
				goto pos2;
		}
	}
	if(a==0){
		cout<<"\n ---Incorrect Username or Password---";
	}
	int opt;
	cout<<"\n\n================================================================================================";
	cout<<"\n\n 1. Main Menu \t2. Exit \n\n Your Option : ";cin>>opt;
	switch(opt){
		case 1: 
			o.mainmenu();
			break;
		case 2:
			break;
		default:
			cout<<"\n\n ---Invalid Option---";
	}	
}
/*---------------------------------------------------------------------------------------------------------------------------------*/
void atam::editByRegno(){
	
	system("cls");
	
	ofstream temp;
	temp.open("temp.txt", ios::app);
	
	ifstream fin;
	fin.open("register.txt", ios::in);
	
	if(!fin){
		cout<<"\n ERROR WHILE OPENING \"register.txt\" FILE!";
	}
	if(!temp){
		cout<<"\n ERROR WHILE OPENING \"temp.txt\" FILE!";
	}
	if(fin){
		edited = 0;		
		cout<<"\n Enter Old Reg.No to Edit : "; fflush(stdin); getline(cin,find);
		while(getline(fin,line)){
			stringstream linestream(line);
			getline(linestream,_tag_,',');
			getline(linestream,_name_,',');
			getline(linestream,_regno_,',');
			getline(linestream,_class_,',');
			getline(linestream,_phno_,',');
			
			if(find != _regno_){
				temp<<_tag_<<","<<_name_<<","<<_regno_<<","<<_class_<<","<<_phno_<<endl;
			}
			if(find == _regno_){
				cout<<"\n\n ----------------------------------------------------------\n";
				cout<<"\n Enter new Tag UID   :  "; cin.getline(o.uid,20); fflush(stdin); 
				cout<<"\n Enter new Name      :  "; cin.getline(o.name,25); fflush(stdin);
				cout<<"\n Enter new Reg.No    :  "; cin.getline(o.regno,15); fflush(stdin);
				cout<<"\n Enter new Phone No. :  "; cin.getline(o.phno,11); fflush(stdin);
		pos3:	cout<<"\n Department Classes (Class-Year):-";
				cout<<"\n *********************************";
				cout<<"\n 1. AIML-1\n 2. CSE-A-1\n 3. CSE-B-1\n 4. CSE-C-1\n 5. IT-1\n\n Your Option : "; cin>>o.dept;
				switch(o.dept){
					case 1:
						temp<<o.uid<<","<<o.name<<","<<o.regno<<","<<dept_class[0]<<","<<o.phno<<endl;
						break;
					case 2:
						temp<<o.uid<<","<<o.name<<","<<o.regno<<","<<dept_class[1]<<","<<o.phno<<endl;
						break;
					case 3:
						temp<<o.uid<<","<<o.name<<","<<o.regno<<","<<dept_class[2]<<","<<o.phno<<endl;
						break;
					case 4:
						temp<<o.uid<<","<<o.name<<","<<o.regno<<","<<dept_class[3]<<","<<o.phno<<endl;
						break;
					case 5:
						temp<<o.uid<<","<<o.name<<","<<o.regno<<","<<dept_class[4]<<","<<o.phno<<endl;
						break;
					default:
						cout<<"\n ---INVALID OPTION---\n";
						goto pos3;
				}
				edited = 1;
			}
		}
	}
	
	if(edited == 1)
		cout<<"\n ---Record Edited Successfully---";
	if(edited == 0)
		cout<<"\n ---Record Not Found---";
	fin.close();
	temp.close();
	remove("register.txt");
	rename("temp.txt","register.txt");
}
/*---------------------------------------------------------------------------------------------------------------------------------*/
void atam::editByName(){
	
	system("cls");
	
	ofstream temp;
	temp.open("temp.txt", ios::app);
	
	ifstream fin;
	fin.open("register.txt", ios::in);
	
	if(!fin){
		cout<<"\n ERROR WHILE OPENING \"register.txt\" FILE!";
	}
	if(!temp){
		cout<<"\n ERROR WHILE OPENING \"temp.txt\" FILE!";
	}
	if(fin){
		edited = 0;		
		cout<<"\n Enter Old Name to Edit : "; fflush(stdin); getline(cin,find);
		while(getline(fin,line)){
			stringstream linestream(line);
			getline(linestream,_tag_,',');
			getline(linestream,_name_,',');
			getline(linestream,_regno_,',');
			getline(linestream,_class_,',');
			getline(linestream,_phno_,',');
			
			if(find != _name_){
				temp<<_tag_<<","<<_name_<<","<<_regno_<<","<<_class_<<","<<_phno_<<endl;
			}
			if(find == _name_){
				cout<<"\n\n ----------------------------------------------------------\n";
				cout<<"\n Enter new Tag UID   :  "; cin.getline(o.uid,20); fflush(stdin); 
				cout<<"\n Enter new Name      :  "; cin.getline(o.name,25); fflush(stdin);
				cout<<"\n Enter new Reg.No    :  "; cin.getline(o.regno,15); fflush(stdin);
				cout<<"\n Enter new Phone No. :  "; cin.getline(o.phno,11); fflush(stdin);
		pos3:	cout<<"\n Department Classes (Class-Year):-";
				cout<<"\n *********************************";
				cout<<"\n 1. AIML-1\n 2. CSE-A-1\n 3. CSE-B-1\n 4. CSE-C-1\n 5. IT-1\n\n Your Option : "; cin>>o.dept;
				switch(o.dept){
					case 1:
						temp<<o.uid<<","<<o.name<<","<<o.regno<<","<<dept_class[0]<<","<<o.phno<<endl;
						break;
					case 2:
						temp<<o.uid<<","<<o.name<<","<<o.regno<<","<<dept_class[1]<<","<<o.phno<<endl;
						break;
					case 3:
						temp<<o.uid<<","<<o.name<<","<<o.regno<<","<<dept_class[2]<<","<<o.phno<<endl;
						break;
					case 4:
						temp<<o.uid<<","<<o.name<<","<<o.regno<<","<<dept_class[3]<<","<<o.phno<<endl;
						break;
					case 5:
						temp<<o.uid<<","<<o.name<<","<<o.regno<<","<<dept_class[4]<<","<<o.phno<<endl;
						break;
					default:
						cout<<"\n ---INVALID OPTION---\n";
						goto pos3;
				}
				edited = 1;
			}
		}
	}
	
	if(edited == 1)
		cout<<"\n ---Record Edited Successfully---";
	if(edited == 0)
		cout<<"\n ---Record Not Found---";
	fin.close();
	temp.close();
	remove("register.txt");
	rename("temp.txt","register.txt");
}
/*---------------------------------------------------------------------------------------------------------------------------------*/
void atam::del_user(){
	
	system("cls");
	
	ofstream temp;
	temp.open("temp.txt");
	
	ifstream fin;
	fin.open("register.txt");
	
	int a = o.password();
	if(a==1){
		if(!fin){
			cout<<"\n ERROR WHILE OPENING \"register.txt\" FILE!";
		}
		if(!temp){
			cout<<"\n ERROR WHILE OPENING \"temp.txt\" FILE!";
		}
		if(fin){
			char c;
			int b = 0, deleted = 0;
			cout<<"\n Enter Reg.No of the User to Delete : "; fflush(stdin); getline(cin,find);
			cout<<"\n DO YOU WANT TO DELETE THE RECORD PERMANENTLY [Y/N] : "; fflush(stdin); cin>>c;
			if(c=='y' || c=='Y'){
				while(getline(fin,line)){
					stringstream linestream(line);
					getline(linestream,_tag_,',');
					getline(linestream,_name_,',');
					getline(linestream,_regno_,',');
					getline(linestream,_class_,',');
					getline(linestream,_phno_,',');
					
					if(find != _regno_){
						temp<<_tag_<<","<<_name_<<","<<_regno_<<","<<_class_<<","<<_phno_<<endl;
					}
					
					if(find == _regno_){
						b = 1;
					}
				}
				if(b==1) cout<<"\n ---Record Deleted Successfully---";
			    if(b==0) cout<<"\n ---Record Not Found---";
			    
			    fin.close();
				temp.close();
				
				remove("register.txt");
				rename("temp.txt","register.txt");
			}
			else{
				cout<<"\n ---Record Not Deleted---";
				fin.close();
				temp.close();
				remove("temp.txt");
			}
		}
		
	}
	if(a==0){
		cout<<"\n ---Incorrect Username or Password---";
	}
	
	int opt;
	cout<<"\n\n================================================================================================";
	cout<<"\n\n 1. Main Menu \t2. Exit \n\n Your Option : ";cin>>opt;
	switch(opt){
		case 1: 
			o.mainmenu();
			break;
		case 2:
			break;
		default:
			cout<<"\n\n ---Invalid Option---";
	}
}
/*---------------------------------------------------------------------------------------------------------------------------------*/
void atam::view_log(){
	
	system("cls");
	int opt;
pos4:	cout<<"\n 1. View Particular User Log";
	cout<<"\n 2. View Particular Class Log in a Day";
	cout<<"\n 3. Exit";
	cout<<"\n\n Your Option : "; cin>>opt;
	switch(opt){
		case 1:
			o.view_user_log();
			break;
		case 2:
			o.view_class_log();
			break;
		case 3:
			break;
		default:
			cout<<"\n ---INVALID OPTION---\n";
			goto pos4;
	}
	int opt1;
	cout<<"\n\n=======================================================================================================";
	cout<<"\n\n 1. Main Menu \t2. Exit \n\n Your Option : ";cin>>opt1;
	switch(opt1){
		case 1: 
			o.mainmenu();
			break;
		case 2:
			break;
		default:
			cout<<"\n\n ---Invalid Option---";
	}
}
/*---------------------------------------------------------------------------------------------------------------------------------*/
void atam::view_user_log(){
	
	system("cls");
	
	ifstream data;
	data.open("DATA.txt");
	
	ifstream fin;
	fin.open("register.txt");
	
	if(!fin){
		cout<<"\n ERROR WHILE OPENING \"register.txt\" FILE!";
	}
	if(!data){
		cout<<"\n ERROR WHILE OPENING \"DATA.txt\" FILE!";
	}
	
	if(fin){
		
		if( fin.peek() == ifstream::traits_type::eof()){
			cout<<"\n   ---YOUR FILE \"register.txt\" IS EMPTY---";
			goto xpos1;
		}
		if( data.peek() == ifstream::traits_type::eof()){
			cout<<"\n   ---YOUR FILE \"DATA.txt\" IS EMPTY---";
			goto xpos1;
		}
		
		cout<<"\n Enter User Reg.No : "; fflush(stdin); getline(cin,find);
		
		while(getline(fin,line)){
			stringstream linestream(line);
			getline(linestream,_tag_,',');
			getline(linestream,_name_,',');
			getline(linestream,_regno_,',');
			getline(linestream,_class_,',');
			getline(linestream,_phno_,',');
			
			if(find == _regno_){
				cout<<"\n\n ----------------------------------------------------------\n";
				cout<<"\n Name       :   "<<_name_;
				cout<<"\n Class      :   "<<_class_;
				cout<<"\n Phone No.  :   "<<_phno_<<endl;
				cout<<"\n      TAG UID      |    DATE    |  TIME  |  TEMP   ";
				cout<<"\n---------------------------------------------------";
				uid01 = _tag_;
				while(getline(data,line)){
					stringstream linestream(line);
					getline(linestream,dataUID,',');
					getline(linestream,dataDATE,',');
					getline(linestream,dataTIME,',');
					getline(linestream,dataTEMP,',');
					
					if(dataUID == uid01){
						setfill(' ');
						cout<<"\n "<<left<<setw(17)<<dataUID<<" | "<<setw(10)<<dataDATE<<" | "<<setw(6)<<dataTIME<<" | "<<setw(7)<<dataTEMP;
						cout<<"\n---------------------------------------------------";
					}
				}
				break;
			}
		}
	}
	xpos1:
	fin.close();
	data.close();
}
/*---------------------------------------------------------------------------------------------------------------------------------*/
void atam::view_class_log(){
	
	system("cls");
	
	ifstream data;
	data.open("DATA.txt", ios::in);
	
	ifstream fin;
	fin.open("register.txt", ios::in);
	
	if(!fin){
		cout<<"\n ERROR WHILE OPENING \"register.txt\" FILE!";
	}
	if(!data){
		cout<<"\n ERROR WHILE OPENING \"DATA.txt\" FILE!";
	}
	
	if(fin){
		
		if( fin.peek() == ifstream::traits_type::eof()){
			cout<<"\n   ---YOUR FILE \"register.txt\" IS EMPTY---";
			goto xpos2;
		}
		if( data.peek() == ifstream::traits_type::eof()){
			cout<<"\n   ---YOUR FILE \"DATA.txt\" IS EMPTY---";
			goto xpos2;
		}
		
		string class_name, uid02[400], name02[400], regno02[400];
pos5:	cout<<"\n Department Classes (Class-Year):-";
		cout<<"\n *********************************";
		cout<<"\n 1. AIML-1\n 2. CSE-A-1\n 3. CSE-B-1\n 4. CSE-C-1\n 5. IT-1\n\n Your Option : "; cin>>o.dept;
		switch(o.dept){
			case 1:
				class_name = "AIML-1";
				break;
			case 2:
				class_name = "CSE-A-1";
				break;
			case 3:
				class_name = "CSE-B-1";
				break;
			case 4:
				class_name = "CSE-C-1";		
				break;
			case 5:
				class_name = "IT-1";
				break;
			default:
				cout<<"\n ---INVALID OPTION---\n";
				goto pos5;
		}
		
		string date02 = o.date();
		cout<<"\n\n";
		cout<<"\n S.NO  |      TAG UID      |           NAME           |     REG.NO     |    DATE    |  TIME  |  TEMP   ";
		cout<<"\n-------------------------------------------------------------------------------------------------------";
	
		int i = 0;
		sno=1;
		string temp_date;
		
		data.seekg(0,ios::end);
		int c = data.tellg();
		data.seekg(0,ios::beg);
		
		while(getline(fin,line)){			
			stringstream linestream(line);
			getline(linestream,_tag_,',');
			getline(linestream,_name_,',');
			getline(linestream,_regno_,',');
			getline(linestream,_class_,',');
			getline(linestream,_phno_,',');
			
			if( _class_ == class_name ){
				uid02[i] = _tag_;
				name02[i] = _name_;
				regno02[i] = _regno_;
				
				while(getline(data,line)){
					stringstream linestream(line);
					getline(linestream,dataUID,',');
					getline(linestream,dataDATE,',');
					getline(linestream,dataTIME,',');
					getline(linestream,dataTEMP,',');
					
					if(dataUID == uid02[i] && dataDATE == date02){
						temp_date=dataDATE;
						setfill(' ');
						cout<<"\n "<<left<<setw(5)<<sno<<" | "<<setw(17)<<dataUID<<" | "<<setw(24)<<name02[i]<<" | "<<setw(14)<<regno02[i]<<" | "<<setw(10)<<dataDATE<<" | "<<setw(6)<<dataTIME<<" | "<<setw(7)<<dataTEMP;                
						sno++;
					}
					if(data.tellg() == c){
						data.seekg(0,ios::beg);
						break;
					}
				}
				i++;
			}
			
		}
		if( temp_date != date02 ){
			cout<<"\n\n ---DATE NOT MATCHED---";
		}
	}
	xpos2:
	fin.close();
	data.close();
}
/*---------------------------------------------------------------------------------------------------------------------------------*/
int atam::password(){
	
	char uname[9]="admin";
	char pass[9]="admin123";
	cout<<"\n\n Username  : "; fflush(stdin); cin.getline(o.username,9);
	cout<<"\n Password  : ";
	for (o.x=0;o.x<8;o.x++){
		o.pwd[o.x]=getch();
		cout<<"*";
	}
	o.pwd[o.x]='\0';
	cout<<"\n ----------------------------------------------------------\n";
	
	if((strcmp(o.username,uname))==0 && (strcmp(o.pwd,pass))==0)
		return 1;
	else
		return 0;
		
}
/*---------------------------------------------------------------------------------------------------------------------------------*/
string atam::date(){
	
	start1: 
	fflush(stdin);
	cout<<"\n Enter Date to Check (DD/MM/YYYY format) : ";
	if(cin>>o.dd>>o.seperator && o.seperator == '/' && cin>>o.mm>>o.seperator && o.seperator=='/' && cin>>o.yy)
	{
		cout<<"\n Date : "<<o.dd<<"/"<<o.mm<<"/"<<o.yy;
		//check year
		if(o.yy>=1900 && o.yy<=9999)
		{
			//check month
			if(o.mm>=1 && o.mm<=12)
			{
				//check days
				if((o.dd>=1 && o.dd<=31) && (o.mm==1 || o.mm==3 || o.mm==5 || o.mm==7 || o.mm==8 || o.mm==10 || o.mm==12))
					cout<<"    ---Date is Valid---";
				else if((o.dd>=1 && o.dd<=30) && (o.mm==4 || o.mm==6 || o.mm==9 || o.mm==11))
					cout<<"    ---Date is Valid---";
				else if((o.dd>=1 && o.dd<=28) && (o.mm==2) && ((o.yy%4)!=0))
					cout<<"    ---Date is Valid---";
				else if((o.dd>=1 && o.dd<=29) && (o.mm==2) && ((o.yy%4)==0))
					cout<<"    ---Date is Valid---";
				else
				{
					cout<<"    ---Date is not Valid---";
					cout<<"\n ____________________________________________"<<endl;
					goto start1;
				}
			}
			else
			{
				cout<<"    ---Date is not Valid---";
				cout<<"\n ____________________________________________"<<endl;
				goto start1;
			}	
		}
		else
		{
			cout<<"    ---Date is not vald---";
			cout<<"\n ____________________________________________"<<endl;
			goto start1;
		}
	}
	else{
		cout<<"\n ---Invalid Date Format---";
		cout<<"\n ____________________________________________"<<endl;
		goto start1;
	}
	string date01, str_dd, str_mm, str_yy;
	str_dd = to_string(dd);
	str_mm = to_string(mm);
	str_yy = to_string(yy);
	
	date01 = str_dd + "/" + str_mm + "/" + str_yy;
	
	return date01;
}
/*---------------------------------------------------------------------------------------------------------------------------------*/
void atam::mainmenu(){
	system("cls");
	cout<<"\n\t Automatic Temperature and Attendance Monitor - Mark 1";
	cout<<"\n\t *****************************************************";
	int opt;
	cout<<"\n\n 1. Add User\n 2. View All Users\n 3. Search User\n 4. Edit User\n 5. Delete User\n 6. View Log Details\n 7. Exit\n\n Your Option : ";
	cin>>opt;
	switch(opt){
		case 1:
			o.add_user();
			break;
		case 2:
			o.view_all_user();
			break;
		case 3:
			o.search_user();
			break;
		case 4:
			o.edit_user();
			break;
		case 5:
			o.del_user();
			break;
		case 6:
			o.view_log();
			break;
		case 7:
			break;
		default:
			cout<<" \n---INVALID OPTION---";
	}
	
}
/*---------------------------------------------------------------------------------------------------------------------------------*/

int main(){
	atam o;
	o.mainmenu();
	cout<<"\n\n";
	cout<<"---------------------------------\n";
	system("pause");
	return 0;
}

/*
Sample data:-
*************

//into "register.txt"
11 22 33 444,Aadhavan J R,713521AM001,AIML-1,7904492146
11 22 33 555,Aaron Shajan,713521AM002,AIML-1,9789483823
11 22 33 666,Abishek E T,713521AM003,AIML-1,9789451122

//into "DATA.txt"
11 22 33 444,1/1/2022,08:30,93.5*F
11 22 33 555,1/1/2022,08:45,96.5*F
11 22 33 555,2/1/2022,08:15,95.4*F
11 22 33 444,2/1/2022,09:00,99.9*F

*/
