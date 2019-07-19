#include<iostream.h>
#include<stdio.h>
#include <conio.h>
#include<dos.h>
#include<iomanip.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
class sender	
{
     protected:
	  char str[1000];
      public:
	   void get();
};
void sender::get()

{
	      for(int i=0;i<12;i++)
	      {
	       cout<<endl;
	      }
	      textcolor(5+128);
	      cprintf("hello user");
	      cout<<endl;
	      textcolor(14);
	      cprintf("enter the message to be sent");
	      cin.getline(str,1000);
}

class algo:public sender
{
     protected:
     //data for xor cryptography
     char *e1,*d1,etr[1000];
     int l,key;
     //data for rsa cryptography
 double p,q,n,t,i,e,d;
int ci[1000],pi[1000],count;
char cc[1000],pc[1000];


public:
//for xor
     void enk(int key);
     void dec(int key);
     virtual int check_key()=0;
//for rsa
     void enk();
	void dec();
	int gcd(int,int);
     void admin();
      algo()
     {
      p=7;
      q=3;
      key=2;
     }
     friend int choice();
};
void algo::enk(int key)
{
l=strlen(str);
int i;
e1=str;
for(i=0;i<l;i++)
{
  *e1+=key;
  e1++;
}
system("cls");
textcolor(14);
cprintf("message encrypted succesfully");
cout<<"\n\n\n";
  strcpy(etr,str);
  cout<<"encrypted message is \n";
cout<<str;
getch();

}
void algo::dec(int key)
{
  int i;
  d1=etr;
  for(i=0;i<l;i++)
  {
  *d1-=key;
  d1++;
  }
   sleep(2);
  system("cls");
  cout<<"\n\n\n\n";
  textcolor(CYAN+BLINK);
  cprintf("decrypting.......................");
  sleep(2);
  system("cls");
  cout<<"decrypted message is \n";
  cout<<etr;
     getch();
     }

void algo::enk()
{
  p=7;
  q=3;
  n=p*q;l=strlen(str);
  t=(p-1)*(q-1);
e=2;
while(e<t)
{
count=gcd(e,t);
if(count==1)
break;

else
e++;
}
cout<<endl;
cout<<endl<<"the value of e is "<<e<<endl;
cout<<endl<<"the value of n is "<<n<<endl;
cout<<endl<<"the value of t is"<<t<<endl;
sleep(2);
system("cls");
textcolor(14+128);  cout<<"\n\n\n\n";
cprintf("message encrypted successfully");
sleep(1);
system("cls");

 cout<<endl;
 cout<<"encrypted message is \n";


for(i=0;i<l;i++)
{
ci[i]=int(etr[i]);
cc[i]=char(ci[i]);
ci[i]=pow(ci[i],e);
ci[i]=fmod(ci[i],n);
 cc[i]=char(ci[i]-100);
cout<<cc[i];
}
}

void algo::dec()
{
int d1;
double k; l=strlen(str);
k=2;
d=(1+(k*t))/e;
cout<<"enter d value\n";
cin>>d1;  sleep(2);
system("cls");
textcolor(6+128);
cprintf("decrypting...........");
sleep(2);
system("cls");cout<<"\n\n\n\n";
cout<<"decrypted messaage is "<<endl;
if(d1==d)
{
puts(str);
}
 else
for(i=0;i<l;i++)
{
pi[i]=pi[i];
pi[i]=int(cc[i]);
pi[i]=pow(pi[i],d);
pi[i]=fmod(pi[i],n);
pc[i]=char(pi[i]-97);
cout<<pc[i];
}
getch();
}

int algo::gcd(int a,int b)
{
while(a!=b)
{
if(a>b)
a-=b;
else
b-=a;
}
return a;


 }
 void algo::admin()
 {
 int opt;
 system("cls");
 sleep(2);
 textcolor(3);
 cout<<"\n\n\n\n";
 cprintf("here comes the admin");
 cout<<"\n\n\n";
 cout<<"1]rsa \n2]xor";
}
int choice()
{
int opt;        cout<<endl;
 cprintf("enter your option");
 cin>>opt;
 return opt;
 }

class receiver:public algo
{
  protected:
  int passkey;
  public:
  void put1();
 void put2();
int check_key();
};
void receiver::put1()
{
     sleep(2);
     system("cls");
     textcolor(14); cout<<"\n\n\n";
     cprintf("hi receiver");
     sleep(2);
if(check_key()==1)
{
   dec(2);
  }
  else
  {
  cout<<"\n password mismatched";
  }
}
int receiver::check_key()
{
   cout<<"\n enter the password to decrypt the text:";
   cin>>passkey;
   if(passkey==key)
   {
   return 1;
   }
   else
   return 0;
}
void receiver::put2()
{

     sleep(2);
     system("cls");
     textcolor(14+128);  cout<<"\n\n\n\n";
     cprintf("HI RECEIVER");
     sleep(2);
     dec();
}


int main()
{
    receiver o;
    int k;
    clrscr();

    o.get();
    o.admin();
    k=choice();
if(k==1)
{
    o.enk();
    o.put2();

   }
   if(k==2)
   {
    o.enk(2);

    o.put1();
    } getch();
    return 0;
    }