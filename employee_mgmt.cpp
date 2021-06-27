#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

using namespace std;

int login();
void menu();
void heading();

void gotoxy(int x,int y)
{
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void color(int col)
{
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h,col);
}
class employee
{
    private:

    char name[30],gender,dept[16],ph[10],address[40];
    int age,emp_code,dd,mm,yy;
    float basic_pay,exp;

    public:
    	
    	void getdata()
    {   
        cout<<"   Employee code: ";
        cin>>emp_code;
        cout<<"   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout<<"   Name: ";
        cin.ignore(1);
        cin.getline(name,30);
        cout<<"   Age: ";
        cin>>age;
        cout<<"   Gender(M/F/O): ";
        cin>>gender;
        cout<<"   Address: ";
        cin.ignore(1);
        cin.getline(address,40);
        cout<<"   Phone number: ";
        cin>>ph;
        cout<<"   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout<<"   Department: ";
        cin>>dept;
        cout<<"   Basic pay: ";
        cin>>basic_pay;
        cout<<"   Date of joining: \n";
        cout<<"    *Date: ";
        cin>>dd;
        cout<<"    *Month: ";
        cin>>mm;
        cout<<"    *Year: ";
        cin>>yy;
        cout<<"   Work experience(yrs.): ";
        cin>>exp;
        cout<<"   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        
        
    }

    

    void getdata(int code1)
    {
        emp_code=code1;
        cout<<"   Name: ";
        cin.ignore(1);
        cin.getline(name,30);
        cout<<"   Age: ";
        cin>>age;
        label1:
		cout<<"   Gender(M/F/O): ";
        cin>>gender;
        if(gender=='m'||gender=='f'||gender=='o'||gender=='M'||gender=='F'||gender=='O'){
		}
		else{
         cout<<"   \nPlease enter correct input";
         goto label1;
		 }
        cout<<"   Address: ";
        cin.ignore(1);
        cin.getline(address,40);
        cout<<"   Phone number: ";
        cin>>ph;
        cout<<"   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout<<"   Department: ";
        cin>>dept;
        cout<<"   Basic pay: ";
        cin>>basic_pay;
        cout<<"   Date of joining: \n";
        cout<<"    *Date: ";
        cin>>dd;
        cout<<"    *Month: ";
        cin>>mm;
        cout<<"    *Year: ";
        cin>>yy;
        cout<<"   Work experience(yrs.): ";
        cin>>exp;
        cout<<"   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        
        
    }
     void putdata()
    {
        cout<<setiosflags(ios::left)<<" "<<setw(9)<<emp_code<<setw(22)<<name<<setw(8)<<gender<<setw(15)<<dept<<
        setw(7)<<age<<setw(14)<<basic_pay<<setw(10)<<ph<<endl;
    }


   void putdata1()
    {
        cout<<"   Employee code: "<<emp_code<<endl;
        cout<<"   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout<<"   Name: "<<name<<endl;
        cout<<"   Age: "<<age<<endl;
        cout<<"   Gender :"<<gender<<endl;
        cout<<"   Address: "<<address<<endl;
        cout<<"   Phone number: "<<ph<<endl;
        cout<<"   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout<<"   Department: "<<dept<<endl;
        cout<<"   Basic pay: "<<"Rs. "<<basic_pay<<endl;
        cout<<"   Date of joining: "<<dd<<"/"<<mm<<"/"<<yy<<endl;
        cout<<"   Work experience: "<<exp<<" yrs."<<endl;
        cout<<"   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        
        
    }

    int getempcode()
    {
        return emp_code;
    }

    char getgender()
    {
        return gender;
    }

    int getage()
    {
        return age;
    }

    char getdept()
    {
        return(dept[0]);
    }


};


class draw
{
int col1, col2, row1,row2;
char c;
public:

void line_hor(int col1,int col2,int row1,char c)
{

    for( int i=col1;i<=col2;i++)
    {
        gotoxy(i,row1);
        cout<<c;
    }
}

void line_ver(int row1,int row2, int col1, char c)
{
     for( int i=row1;i<=row2;i++)
    {
        gotoxy(col1,i);
        cout<<c;
    }

}

void drawbox(int row1,int row2,int col1,int col2,char c1, char c2)
{
    line_hor(col1,col2,row1,c1);  //top
    line_ver(row1,row2,col1,c2);  //left
    line_hor(col1,col2,row2,c1);  //bottom
    line_ver(row1,row2,col2,c2);  //right

}
};


int main()
{
    employee emp;
    draw d1;
    color(14);
    gotoxy(4,3);
    cout<<"\t\tE M P L O Y E E    M A N A G E M E N T    S Y S T E M"<<endl;
    color(11);
    d1.drawbox(1,5,1,80,219,219);

    gotoxy(0,9);
    color(14);
    login();
    
    int ch;
    char yes='y';

    fstream inoutfile;

    do{
    menu();
    cin>>ch;
   system("cls");

    switch(ch)
    {

    //VIEW ALL RECORDS
    case 1:	

     {
      gotoxy(4,3);
      color(14);
      cout<<"\t\t\tC U R R E N T    R E C O R D S"<<endl;
      color(11);
      d1.drawbox(1,5,1,80,219,219);
      inoutfile.open("employee.txt",ios::in|ios::binary);
     
      heading();
      color(14);
      inoutfile.seekg(0,ios::beg);
      while(inoutfile.read((char *)&emp, sizeof(emp)))
     {
        emp.putdata();
     }
     inoutfile.clear();
     inoutfile.close();
     break;
     }


// ADD A RECORD:
    case 2:
    	 
         color(11);
         d1.drawbox(1,5,1,80,219,219);
         gotoxy(4,3);
    	 color(14);
         cout<<"\t\t\t    A D D   A   R E C O R D "<<endl;
        
       inoutfile.open("employee.txt",ios::binary|ios::in|ios::out|ios::ate);
       {
       int code,found=0;
       cout<<"\n\n\n\n   Enter Employee code: ";
       cin>>code;
       inoutfile.seekg(0,ios::beg);
       while(inoutfile.read((char*)&emp,sizeof emp))
             {
                if(emp.getempcode()==code)
                  found=1;
             }
       inoutfile.close();

               if (found==1)
               {
               	 color(12);
                 cout<<"   INCORRECT EMPLOYEE CODE!!"<<"\n   This Employee already exists."<<endl;
               }
               else
               {
                inoutfile.open("employee.txt",ios::in|ios::out|ios::ate|ios::binary);
               	cout<<"\n   Enter the details of the new employee: "<<endl;
               	cout<<"   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                emp.getdata(code);
                char c;
                cin.get(c);
                inoutfile.write((char*)&emp,sizeof(emp));
                inoutfile.seekg(0);
                color(12);
                cout<<"\n   RECORD ADDED SUCCESSFULLY!\n\n\n";
                
                
              }
        }
        inoutfile.close();
       break;

    //EDITING A RECORD:
    case 3:
    	
         color(11);
         d1.drawbox(1,5,1,80,219,219);
         gotoxy(4,3);
    	 color(14);
    	 cout<<"\t\t\t M O D I F Y   A   R E C O R D "<<endl;

        {   inoutfile.open("employee.txt",ios::in|ios::out|ios::ate|ios::binary);
            int code,found=0,loc=1;
            cout<<"\n\n\n\n   Enter the employee code: ";
            cin>>code;

            inoutfile.seekg(0,ios::beg);
            while(inoutfile.read ((char *)&emp,sizeof emp))
            {
                if(emp.getempcode()==code)
                {   found=1;}
            }
            inoutfile.close();

            inoutfile.open("employee.txt",ios::in|ios::out|ios::ate|ios::binary);
            if(found==1)
                {  inoutfile.seekg(0,ios::beg);
                   while(inoutfile.read((char*)&emp,sizeof emp))
                     {   if(emp.getempcode()==code)
                         break;
                         else
                         loc++;
                     }

               int location=(loc-1)*sizeof(emp);
               if(inoutfile.eof())
                inoutfile.clear();

               inoutfile.seekp(location);
               cout<<"\n   Enter new details of the employee: "<<endl;
               cout<<"   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
               emp.getdata();
               inoutfile.write((char*)&emp, sizeof(emp))<<flush;
               inoutfile.seekg(0);
               color(12);
               cout<<"\n\n   RECORD MODIFIED SUCCESSFULLY!\n";
               
               }


                else
                {   color(12);
                    cout<<"   RECORD NOT FOUND!!"<<endl<<"   Check Employee Code"<<endl;
                    cout<<"   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                }
        }
       inoutfile.close();
        break;



    //DELETING A RECORD
    case 4:
    	
    	 color(11);
         d1.drawbox(1,5,1,80,219,219);
         gotoxy(4,3);
    	 color(14);
         cout<<"\t\t\t D E L E T E    A   R E C O R D "<<endl;
      

     inoutfile.open("employee.txt",ios::in|ios::out|ios::ate|ios::binary);
      {
            int code,found=0;
            cout<<"\n\n\n\n   Enter Employee Id To Remove: ";
            cin>>code;
            inoutfile.seekg(0,ios::beg);

            while(inoutfile.read((char*)&emp,sizeof emp))
             {
            if(emp.getempcode()==code)
                {
                found=1;
                }
             }
            inoutfile.close();


            if (found==1)
            {
            fstream tempfile;
            tempfile.open("tempfile.txt",ios::out|ios::binary);
            inoutfile.open("employee.txt",ios::in|ios::out|ios::ate|ios::binary);
            inoutfile.seekg(0,ios::beg);
            while(inoutfile.read((char*)&emp,sizeof emp))
             {
            if(emp.getempcode()!=code)
                {
                tempfile.write((char*)&emp,sizeof(emp));
                }
             }
                tempfile.close();
                inoutfile.close();
                int isRemoved= remove("employee.txt");
                int isRenamed= rename("tempfile.txt", "employee.txt");
                cout<<"\n\n   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                color(12);
                cout<<"\n\n   RECORD REMOVED SUCCESSFULLY\n";
            }

            else
               {
			   cout<<"\n\n   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
               color(12);
               cout<<endl<<"   RECORD NOT FOUND!!"<<endl<<"   Check Employee Code   "<<endl;
               }
     }

     break;

     //SEARCHING A RECORD:
    case 5:
    	
    	 color(11);
         d1.drawbox(1,5,1,80,219,219);
         gotoxy(4,3);
    	 color(14);
         cout<<"\t\t\t S E A R C H    A    R E C O R D "<<endl;
         
         {
        inoutfile.open("employee.txt",ios::in|ios::binary);
        int code,found=0;
            cout<<"\n\n\n\n   Enter the Employee code: ";
            cin>>code;
            inoutfile.seekg(0,ios::beg);
            while(inoutfile.read((char*)&emp,sizeof emp))
             {
                if(emp.getempcode()==code)
              { 
                 color(12);
			     cout<<"\n   SEARCH SUCCESSFUL!\n";
			     cout<<"   __________________________________________________________________________\n\n";
                 color(14);
                  emp.putdata1();
                  found=1;
              }
             }
             
               if (found==0)
               { 
                 cout<<"\n\n   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                 color(12);
                 cout<<endl<<"   RECORD NOT FOUND!!"<<endl<<"   Check Employee Code"<<endl;
               }
            }
            inoutfile.close();
            break;


    //DETAILED ANALYSIS OF RECORDS:
    case 6:
    	
    	 color(11);
         d1.drawbox(1,5,1,80,219,219);
         gotoxy(4,3);
    	 color(14);
         cout<<"\t   D E T A I L E D   A N A L Y S I S   O F   R E C O R D S "<<endl;
        
        {
         inoutfile.open("employee.txt",ios::in|ios::binary);
         inoutfile.seekg(0,ios::beg);
         int emp_count=0;
         int m_count=0,f_count=0;
         int a_count=0,b_count=0,c_count=0,d_count=0;
         int adm=0,mar=0,fin=0,pur=0,sal=0;
            while(inoutfile.read((char*)&emp,sizeof emp))
            {
             emp_count++;

             {
			 if(emp.getgender()=='F'||emp.getgender()=='f')
                f_count++;

             else if(emp.getgender()=='M'||emp.getgender()=='m')
                m_count++; 
            }

            {
		    if(emp.getage()>=20&&emp.getage()<=30)
                a_count++;

            else if(emp.getage()>30&&emp.getage()<=40)
                b_count++;

            else if(emp.getage()>40&&emp.getage()<=50)
                c_count++;

            else
                d_count++;
            }

             switch(emp.getdept())
            {
            case 'A':
            case 'a':
                adm++;
                break;

            case 'S':
            case 's':
                sal++;
                break;

            case 'M':
            case 'm':
                mar++;
                break;

            case 'F':
            case 'f':
                fin++;
                break;

            case 'P':
            case 'p':
                pur++;
                break;

            }

            }

         
         color(14);
         cout<<"\n\n\n\n";
         cout<<"  *  Total Number of Employees  : "<<emp_count<<endl;
         cout<<"  ____________________________________________________________________________"<<endl;
         cout<<"  *  Female Employees           : "<<f_count<<endl;
         cout<<"  *  Male Employees             : "<<m_count<<endl;
         cout<<"  ____________________________________________________________________________"<<endl;
         cout<<"  *  20-30 yrs.                 : "<<a_count<<endl;
         cout<<"  *  31-40 yrs.                 : "<<b_count<<endl;
         cout<<"  *  41-50 yrs.                 : "<<c_count<<endl;
         cout<<"  *  Above 50 yrs.              : "<<d_count<<endl;
         cout<<"  ____________________________________________________________________________"<<endl;
         cout<<"  *  Administration             : "<<adm<<endl;
         cout<<"  *  Finance                    : "<<fin<<endl;
         cout<<"  *  Marketing                  : "<<mar<<endl;
         cout<<"  *  Purchase                   : "<<pur<<endl;
         cout<<"  *  Sales                      : "<<sal<<endl;
         color(12);
         cout<<"  ____________________________________________________________________________"<<endl;

         inoutfile.close();
        }
         break;

   //EXIT
    case 7: char s;
            color(14);
            cout<<"   Please click 'y' to exit:";
            cin>>s;
            if(s=='y')
            {exit(0);}
            break;


    default:
        cout<<" Please enter a valid option";
        break;
    }

cout<<endl<<endl;
system("pause");
cout<<"For Going back to main menu press 'Y': ";
//cin>>yes;
getch();
system("cls");


}while(yes=='y'||yes=='Y');
return 0;
}

void menu()
{   draw d;
    
    color(14);
    gotoxy(4,3);
    cout<<"\t\tE M P L O Y E E    M A N A G E M E N T    S Y S T E M"<<endl;
    color(11);
    d.drawbox(1,5,1,80,219,219);

    gotoxy(3,9);
    color(14);
    cout<<"   MENU:"<<endl<<endl;
    cout<<"     Enter  1.  To View all records"<<endl;
    cout<<"     Enter  2.  To Add a record"<<endl;
    cout<<"     Enter  3.  To Edit a record"<<endl;
    cout<<"     Enter  4.  To Delete a record"<<endl;
    cout<<"     Enter  5.  To Search a record"<<endl;
    cout<<"     Enter  6.  To Get Detailed Analysis of Records"<<endl;
    cout<<"     Enter  7.  To Exit"<<endl;
    color(12);
    d.drawbox(7,19,1,80,176,176);
    //color(14);
    cout<<"\n\n Please enter your choice: ";


}

void heading()
{    
     color(12);
     cout<<"\n ______________________________________________________________________________________"<<endl;
     cout<<setiosflags(ios::left)<<"|Emp_Code "<<setw(22)<<"Name"<<"Gender  "<<setw(15)<<"Department"
     <<setw(7)<<"Age"<<setw(14)<<"Basic_pay(Rs)"<<setw(10)<<"Phone No."<<" |"<<endl;
     cout<<"|______________________________________________________________________________________|"<<endl<<endl;
}

int login()
{
   string pass ="";
   char ch;
   color(14);
   cout <<"   Enter Your Password :  \n   ";
   ch = getch();
   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = getch();
     }
     color(12);
   if(pass == "pass")
   {
   	  cout << "\n\n   Access Granted!!\n\n";
   	  cout<<"   _______________________________________________________________________\n\n   ";
      system("pause");
      system("cls");
   }
   else
   {
      cout << "\n\n   Access Denied\n\n";
      cout<<"   _______________________________________________________________________\n   ";
      login();
   }
}

