#include <iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
//e=0 customer
//e=1 employee
//employee pasword is abc
class basket;
class user 
{
    string name;
    int e;
    string pass;

    public:
    user()
    {
      name ="Default_name";
      pass = "Default_pass";
      e =0;
    }
    
    void reg()
    {
      ofstream app;
      app.open("lr.csv",ios_base::app);
      string a,b;
      cout<<"\t\t\t------Registration-------- \n";
      cout<<"\t\t\tCreate a new user name: ";
      cin>>a;
      app<< a<<",";
      l1:
      cout<<"\t\t\tselect a new password: ";
      cin>>a;
      cout<<"\t\t\tRenter the password: ";
      cin>>b;
      if(a!=b)
      {
        cout<<"\t\t\tPasswords don't match\n";
        goto l1;
      }
      app<< a<<",";
      //cout<<"--------------";
      l2:
      cout<<"\n\t\t\tEnter 0 if you are a customer\n\t\t\tEnter 1 if you are an employee: ";
      cin>>a;
      // cout<<"--------------";
      if(a == "1")
      {
        cout<<"\t\t\tEnter employee password: ";
        cin>>b;
        if(b!="abc")
        {
          cout<<"\t\t\tWrong password, try again\n";
          goto l2;
        }
      }
      else if(a != "0")
      {
        cout<<"\t\t\tInvalid input , please try again\n";
        goto l2;
      }
      app<<a<<"\n";
      cout<<"\t\t\tSuccessfully registred\n";
      app.close();
      }

      void login()
      {
        cout<<"\t\t\t---------Login---------\n";
        ifstream see;
        see.open("lr.csv");
        string w,p;
        int c=0;
        cout<<"\t\t\tEnter Username: ";
        cin>>p;
        while(getline(see,w,','))
        {
          if(w == p)
          {
            c++;
            getline(see,w,',');
            l1:
            cout<<"\t\t\tEnter password: ";
            cin>>p;
            
            if(p != w)
            {
              cout<<"\t\t\tWrong password: ";
              goto l1;
            }
            getline(see,w,'\n');
            if(w=="1")
            {
              cout<<"\n\n\t\t\tWelcome Employee, Thank You for working hard\n";
            }
            else
            {
              // cout<<"--------------";
              cout<<"\n\n\n\t\t\tWelcome dear customer :-\n";
            }
            break;
          }
          else
          {
            getline(see,w,',');
            getline(see,w,'\n');
          }
        }
        if(c==0)
        {
          cout<<"\n\n\nUsername not found\n";
          login();
        }
        see.close();

      }

    
};
// id , name, price, stock 
class product
{
  int price;
  string name;
  int stock;
  int id;
  public:
  void convert(product a[],int &n)
  {
    ifstream see;
    see.open("product.csv");
    string w;
    int i=0;
    n=0;
    while(getline(see,w,','))
    {
      a[i].id = stoi(w);
      getline(see,w,',');  
      a[i].price = stoi(w);
      getline(see,w,',');
      a[i].stock = stoi(w);
      getline(see,w,'\n');
      a[i++].name = w;
      n++;
    }
    see.close();
  }
  void out(product a[], int n)
  {
    cout<<"\t\t\tId   \t|\tprice \t|\tstock \t|\tname\n";
    int i=0;
    while(i<n)
    {
      cout<<"\t\t\t"<<a[i].id<<"\t|\t"<<a[i].price<<"  \t|\t "<<a[i].stock<<"  \t|\t"<<a[i].name<<endl;
      i++;
    }
  
  }

  void enter(product a[],int &n)
  {
    ofstream edit;
    edit.open("product.csv",ios_base::app);
  
    //cout<<"Enter product id:\n";
    a[n].id = 1000+n+1;
    cout<<"\t\t\tEnter product name: ";
    cin>>a[n].name;
    cout<<"\t\t\tEnter product cost: ";
    cin>>a[n].price;
    cout<<"\t\t\tEnter product stock: ";
    cin>>a[n].stock;
    edit<<a[n].id<<","<<a[n].price<<","<<a[n].stock<<","<<a[n].name<<"\n";
    n++;
    edit.close();
  }

  void searched(product obj[],int n)
  {
    int s =0;
    int c =0;
    l1:
    cout<<"\t\t\t\tEnter 0 for search by name\n\t\t\t\tEnter 1 for search by id\n\t\t\t\t";
    cin>>s;
    string nam;
    int ids;
    
    if(s==0)
    {
      cout<<"\t\t\t\tEnter product name: ";
    cin>>nam;
      for(int i = 0;i<n;i++)
      {
        if(nam == obj[i].name)
        {
          c++;
          cout<<"\t\t\t\tName : "<<obj[i].name<<endl;
          cout<<"\t\t\t\tID : "<<obj[i].id<<endl;
          cout<<"\t\t\t\tPrice : "<<obj[i].price<<endl;
          cout<<"\t\t\t\tStock : "<<obj[i].stock<<endl;
          break;
        }
      }
    }
    else if(s == 1)
    {
      cout<<"\t\t\t\tEnter product code: ";
      cin>>ids;
      for(int i = 0;i<n;i++)
      {
        if(ids == obj[i].id)
        {
          c++;
          cout<<"\t\t\t\tName : "<<obj[i].name<<endl;
          cout<<"\t\t\t\tID : "<<obj[i].id<<endl;
          cout<<"\t\t\t\tPrice : "<<obj[i].price<<endl;
          cout<<"\t\t\t\tStock : "<<obj[i].stock<<endl;
          break;
        }
      }
    }
    else
    {
      cout<<"\t\t\t\tWrong input for searching, please try again\n";
      goto l1;
    }  
    if(c==0)
    {
      cout<<"\t\t\t\tNot found\n";
    }
  }
  friend basket;
};



int main()
{
  user o;
  //o.reg();
  o.login();
  int n;
  product obj[30];
  obj[0].convert(obj,n);
  //obj[0].enter(obj,n);
  obj[0].searched(obj,n);
  obj[0].out(obj,n);

  return 0;
  
}