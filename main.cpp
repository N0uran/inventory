#include<iostream>
#include<fstream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

class product
{
private:
    string p_ID ;
    string p_Name ;
    string p_Amount;
    string price;
    string type_of_p;
    string shelf_number;

public:
    vector<string>vect;
    void Read ();
    void insert ();
    void search_name ();
    void search_id ();
    void search_type ();
    void Delete ();
    void update (string name_update ,string amount_upd); 
    int check_id (string check_id , string check_name); // use to check unique ID
    void vectorName();                                  // use to sort name in vector and sort it then use in binary search
    int binarySearch_end(vector<string>vec);
    void main_search();
    bool valid_name(string s);   // use to check name if user enter number 
    bool valid_num(string s);    // use to check num if user enter char 

};
void product::Read()
{

    ifstream myfile;
    myfile.open("inventory.txt" , ios::in | ios::app);
    if(myfile.is_open())
    {
        while(!myfile.eof())
        {
            getline(myfile,p_ID,'|');
            getline(myfile,p_Name,'|');
            getline(myfile,p_Amount,'|');
            getline(myfile,price,'|');
            getline(myfile,type_of_p,'|');
            getline(myfile,shelf_number,'\n');

            if(!myfile.eof())
            {

                cout<<p_ID<<"\t"<<p_Name<<"\t"<<p_Amount<<"\t"<<price<<"\t"<<type_of_p<<"\t"<<shelf_number<<"\t";

                cout<<endl;
            }
        }

    }
    else
        cout<<"File not exist";
    myfile.close();


}
void product::insert()
{

    string p_ID ;
    string p_Name ;
    string p_Amount;
    string price;
    string type_of_p;
    string shelf_number;
    char choice;

    ofstream myfile;
    myfile.open("inventory.txt" , ios::out|ios::app);
    if(myfile.is_open())
    {
        do
        {

            cout<<"Enter the product_ID"<<endl;
            cin>>p_ID;
            
//check product_name if has number

	a:
            cout<<"Enter the product_Name"<<endl;
            cin>>p_Name;
            if(!valid_name(p_Name))
            {
                cout<<" CHECK NAME AGAIN YOU SHOULD CONTAIN CHARACTER ONLY "<<endl;
                goto a;
            }
            
//check product_amount if has char
            
	b:
            cout<<"Enter the product_Amount"<<endl;
            cin>>p_Amount;
            if(!valid_num(p_Amount))
            {
                cout<<" ERROR IN INSERT YOU SHOULD TO BE BETWEEN 0-9 ONLY "<<endl;
                goto b;
            }
            
//check price if has char

	c:
            cout<<"Enter the price"<<endl;
            cin>>price;
            if(!valid_num(price))
            {
                cout<<" ERROR IN INSERT YOU SHOULD TO BE BETWEEN 0-9 ONLY "<<endl;
                goto c;
            }
            cout<<"Enter the type_of_product"<<endl;
            cin>>type_of_p;

            cout<<"Enter the shelf_number"<<endl;
            cin>>shelf_number;
            
//check  shelf_number if has char

	d:
            if(!valid_num(shelf_number))
            {
                cout<<" ERROR IN INSERT YOU SHOULD  Insert BETWEEN 0-9 ONLY "<<endl;
                goto d;
            }
// check unique _ID
	        
            int z = check_id(p_ID,p_Name);
            if(z==1)
            {
                update(p_Name,p_Amount);
                //myfile.close();
            }
            else if(z==2)
            {
                cout<<"ID should be unique"<<endl;
            }
            else if(z==3)
            {
                myfile<<p_ID<<"|";
                myfile<<p_Name<<"|";
                myfile<<p_Amount<<"|";
                myfile<<price<<"|";
                myfile<<type_of_p<<"|";
                myfile<<shelf_number;
                myfile<<endl;
                myfile.close();

            }

            cout<<"if you need to insert again insert Y "<<endl;
            cin>>choice;

        }
        while(choice== 'y' || choice == 'Y');
        myfile.close();

    }
    else
        cout<<"File not exist";
    myfile.close();
}

void product::search_name ()
{
	bool cond=false;
    string key;
    cout<<" ENTER NAME TO SEARCH "<<endl;
    cin>>key;
    ifstream myfile;
    myfile.open("inventory.txt" , ios::in | ios::app);
    if(myfile.is_open())
    {
        while(!myfile.eof())
        {
            getline(myfile,p_ID,'|');
            getline(myfile,p_Name,'|');
            getline(myfile,p_Amount,'|');
            getline(myfile,price,'|');
            getline(myfile,type_of_p,'|');
            getline(myfile,shelf_number,'\n');


            if(p_Name.compare(key)==0 && p_ID.compare(" ")!=0)
            {
                cout <<"product_ID :"<<p_ID<<"\t"<<"product_Name :"<<p_Name<<"\t"<<"p_Amount :"<<p_Amount<<
                     "\t"<<"price :"<<price<<"\t"<<"type_of_product :"<<type_of_p<<"\t"<<"shelf_number :"<<shelf_number<<endl;
				cond=true;
                

            }
        }
        if(!cond)
        	cout<<"Record not found";

    }
    else
        cout<<"File Not exist :/ ";

    myfile.close();
   

}
void product::search_type ()
{
	bool cond=false;
    string key;
    cout<<" ENTER TYPE TO SEARCH "<<endl;
    cin>>key;
    ifstream myfile;
    myfile.open("inventory.txt");
    if(myfile.is_open())
    {
        while(!myfile.eof())
        {
            getline(myfile,p_ID,'|');
            getline(myfile,p_Name,'|');
            getline(myfile,p_Amount,'|');
            getline(myfile,price,'|');
            getline(myfile,type_of_p,'|');
            getline(myfile,shelf_number,'\n');


            if(type_of_p.compare(key)==0 && p_ID.compare(" ")!=0)
            {
                cout <<"product_ID :"<<p_ID<<"\t"<<"product_Name :"<<p_Name<<"\t"<<"p_Amount :"<<p_Amount<<
                     "\t"<<"price :"<<price<<"\t"<<"type_of_product :"<<type_of_p<<"\t"<<"shelf_number :"<<shelf_number<<endl;
				cond=true;
                

            }
        }
        if(!cond)
        	cout<<"Record not found";

    }
    else
        cout<<"File Not exist :/ ";

    myfile.close();
   

}


void product::search_id ()
{
	bool cond=false;
    string key;
    cout<<" ENTER ID TO SEARCH "<<endl;
    cin>>key;
    ifstream myfile;
    myfile.open("inventory.txt");
    if(myfile.is_open())
    {
        while(!myfile.eof())
        {
            getline(myfile,p_ID,'|');
            getline(myfile,p_Name,'|');
            getline(myfile,p_Amount,'|');
            getline(myfile,price,'|');
            getline(myfile,type_of_p,'|');
            getline(myfile,shelf_number,'\n');


            if(p_ID.compare(key)==0 && p_ID.compare(" ")!=0)
            {
                cout <<"product_ID :"<<p_ID<<"\t"<<"product_Name :"<<p_Name<<"\t"<<"p_Amount :"<<p_Amount<<
                     "\t"<<"price :"<<price<<"\t"<<"type_of_product :"<<type_of_p<<"\t"<<"shelf_number :"<<shelf_number<<endl;
				cond=true;
               

            }
        }
        if(!cond)
        	cout<<"Record not found";

    }
    else
        cout<<"File Not exist :/ ";

    myfile.close();
    

}

void product::update (string name_update ,string amount_upd)
{

    ifstream myfile;
    bool x=false;
    myfile.open("inventory.txt",ios::in | ios::app);
    ofstream newfile;
    newfile.open("new.txt",ios::out| ios::app);
    if(myfile.is_open())
    {
        while(!myfile.eof())
        {
            getline(myfile,p_ID,'|');
            getline(myfile,p_Name,'|');
            getline(myfile,p_Amount,'|');
            getline(myfile,price,'|');
            getline(myfile,type_of_p,'|');
            getline(myfile,shelf_number,'\n');

            if( p_Name.compare(name_update)==0 )
            {
                if(!myfile.eof())
                {
                    newfile<<p_ID<<"|"<<p_Name<<"|"<<amount_upd<<"|"<<price<<"|"<<type_of_p<<"|"<<shelf_number<<endl;
                    cout<<"Updated successfuly"<<endl;
                    x=true;
                }

            }
            else
            {

                if(!myfile.eof())
                {
                    newfile<<p_ID<<"|"<<p_Name<<"|"<<p_Amount<<"|"<<price<<"|"<<type_of_p<<"|"<<shelf_number<<endl;

                }
            }

        }
    }
    else
    {

        cout<<"File Not exist :/ ";
    }
    if(!x)
        cout<<"Not Found"<<endl;
    myfile.close();
    newfile.close();

    remove("inventory.txt");
    rename( "new.txt", "inventory.txt");


}
int product::check_id (string check_id , string check_name)
{

    ifstream myfile;
    myfile.open("inventory.txt");
    if(myfile.is_open())
    {
        while(!myfile.eof())
        {
            getline(myfile,p_ID,'|');
            getline(myfile,p_Name,'|');
            getline(myfile,p_Amount,'|');
            getline(myfile,price,'|');
            getline(myfile,type_of_p,'|');
            getline(myfile,shelf_number,'\n');


            if( p_ID.compare(check_id)==0 && p_Name.compare(check_name)==0)
            {
                myfile.close();
                return 1;
            }
            else if(p_ID.compare(check_id)==0 && p_Name.compare(check_name)!=0)
            {
                myfile.close();
                return 2;
            }


        }

    }
    else
        cout<<"File Not exist :/ ";

    myfile.close();
    return 3;

}
void product::Delete ()
{
string word;
cout<<" Enter NAME To Delete "<<endl;
cin>>word;

    ifstream myfile;
    myfile.open("inventory.txt",ios::in | ios::app);
    ofstream newfile;
    newfile.open("temp.txt",ios::out);
    bool x =false;
    if(myfile.is_open())
    {
        while(!myfile.eof())
        {
            getline(myfile,p_ID,'|');
            getline(myfile,p_Name,'|');
            getline(myfile,p_Amount,'|');
            getline(myfile,price,'|');
            getline(myfile,type_of_p,'|');
            getline(myfile,shelf_number,'\n');
            if(!myfile.eof())
            {

                if(p_Name.compare(word)!=0  )
                {
                    newfile<<p_ID<<"|"<<p_Name<<"|"<<p_Amount<<"|"<<price<<"|"<<type_of_p<<"|"<<shelf_number<<"\n";

                }
                else
                {
                    x=true;
                    
                }
            }
        }
    }
    else
        cout<<"File Not exist :/ ";

    if(!x)
        cout<<"Not found"<<endl;
    else
    	cout<<"founded and deleted"<<endl;
    myfile.close();
    newfile.close();
    remove("inventory.txt");
    rename("temp.txt" , "inventory.txt");
}
void product::vectorName()
{
    
    ifstream myfile;
    myfile.open("inventory.txt" , ios::in );
    if(myfile.is_open())
    {
        while(!myfile.eof())
        {
            getline(myfile,p_ID,'|');
            getline(myfile,p_Name,'|');
            getline(myfile,p_Amount,'|');
            getline(myfile,price,'|');
            getline(myfile,type_of_p,'|');
            getline(myfile,shelf_number,'\n');

            vect.push_back(p_Name);

        }


        sort(vect.begin(),vect.end());

    }


    myfile.close();

}
int product:: binarySearch_end(vector<string>vec)
{
    string key;
    cout<<" ENTER NAME TO SEARCH BY BINARYSEARCH"<<endl;
    cin>>key;
    int lower = 0;
    int higher =vec.size();
    while (1)
    {
        int mid = (lower+ higher)/2;
        if (vec[mid].compare(key)==0)
            return mid ;  // return index if key is found
        else if (lower>higher)
            return -1;
        else
        {
            if (vec[mid]> key)
                higher = mid -1;
            else
                lower = mid+1;
        }
    }
}

bool product::valid_name(string s)
{
    for(int i=0; i<s.size(); i++)
    {

        if(!(s[i]>='a'&&s[i]<='z'))
            return false;
    }
    return true;

}

bool product::valid_num(string s)
{
    for(int i=0; i<s.size(); i++)
    {

        if(!(s[i]>='0'&&s[i]<='9'))
            return false;
    }
    return true;

}

void product::main_search()
{

    char ch;
    do
    {
        int b;

        cout<<char(4)<<" IF YOU WANT TO SEARCH BY ID  PRESS(1)"<<endl;
        cout<<char(4)<<" IF YOU WANT TO SEARCH BY NAME PRESS(2)"<<endl;
        cout<<char(4)<<" IF YOU WANT TO SEARCH BY TYPE  PRESS(3)"<<endl;
        cout<<char(4)<<" IF YOU WANT TO BINARY SEARCH   PRESS(4)"<<endl;
        cin>>b;
        if(b==1)
            search_id();
        else if(b==2)
            search_name();
        else if(b==3)
            search_type();
        else if(b==4)
        {
            vectorName();
            int u =binarySearch_end(vect);
            if(u==-1)
                cout<<"NOT FOUND "<<endl;
            else
                cout<<"FOUND"<<endl;
        }
        else
            cout<<" ERROR IN SELECT OPERATOR "<<endl;

        cout<<" DO YOU WANT SEARCH AGAIN  "<<endl;
        cin>>ch;
    }
    while(ch=='y'||ch=='Y');


}

int main()
{

    char ch;
    do
    {
        product p1;
        int b;

        cout<<"             "<<char(3)<<char(3)<<" WELCOME IN MY PROGRAM "<<char(3)<<char(3)<<"           \n"<<endl;
        cout<<char(4)<<" IF YOU WANT TO INSERT  PRESS(1)"<<endl;
        cout<<char(4)<<" IF YOU WANT TO DISPLAY PRESS(2)"<<endl;
        cout<<char(4)<<" IF YOU WANT TO SEARCH  PRESS(3)"<<endl;
        cout<<char(4)<<" IF YOU WANT TO UPADTE  PRESS(4)"<<endl;
        cout<<char(4)<<" IF YOU WANT TO DELETE  PRESS(5)"<<endl;
        cout<<char(4)<<" IF YOU WANT TO EXIT    PRESS(0)"<<endl;
        cin>>b;
        if(b==1)
        
            p1.insert();
		else if(b==2)
            p1.Read();
        else if(b==3)
            p1.main_search();
            
        else if(b==4)
		{
        		string update_name ,update_amount;
        a:	
				cout<<"Enter product Name "<<endl;
				cin>>update_name;
        		if(!p1.valid_name(update_name))
            	{
                	cout<<" CHECK NAME AGAIN YOU SHOULD CONTAIN CHARACTER ONLY "<<endl;
                	goto a;
            	}
        b:    
				cout<<"Enter product Amount which you need update : "<<endl;
				cin>>update_amount;
        		if(!p1.valid_num(update_amount))
            	{
                	cout<<" CHECK Amount AGAIN YOU SHOULD CONTAIN Numbers ONLY "<<endl;
                	goto b;
            	}
        	p1.update(update_name,update_amount);
        	
    	}
		else if(b==5)
		{
            p1.Delete();
            
    	}
		else if(b==0)
        {
            cout<<" THANKS "<<endl;
            exit(0);
        }
        else
            cout<<" ERROR IN SELECT OPERATOR "<<endl;

        cout<<" DO YOU WANT OTHER OPERATOR AGAIN  "<<endl;
        cin>>ch;
    }
    while(ch=='y'||ch=='Y');


}

