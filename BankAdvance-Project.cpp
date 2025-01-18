#include<stdio.h>
#include<iostream>
#include<string.h>
#include<cstdlib>
#include<fstream>
using namespace std;
int t;
class BankAccount{
	public:
		char u[100],e[100],p[100],ac[100];
		int age,mb;
		long long int pn;
		double b;
	void setDetails(){
		int z=1;
		while(1){
			z=1;
			cout<<"\nEnter username : "; cin>>u;
			for(int i=0;i<=100;i++){
				if(u[i]==' '){
					cout<<"\nPlease enter a username without spaces";
					z=0;
					continue;
				}
			}
			if(z==1) break;
		}
		cout<<"\nEnter password : "; cin>>p;
		cout<<"\nEnter email : "; cin>>e;
		while(1)
		{
		cout<<"\nEnter mobile number : "; cin>>pn; if(!(pn>=6000000000&&pn<=9999999999)) cout<<"\nPlease enter a valid mobile number"; else break;
		}
		while(1){
		cout<<"\nEnter age : "; cin>>age;
		if(age<18) cout<<"\nUnderage, cannot open account";
		else break;
	}
		while(1){
		
		cout<<"\nEnter balance : Rs."; cin>>b;
		if(!((age>=18&&age<=25&&b>=1000)||(age>=26&&age<=45&&b>=1500)||(age>46&&b>=2000))) {
			cout<<"\nPlease enter a higher balance since your previously emtered is below minimum balance according to your age";
			mb=(age>=18&&age<=25)?1000:(age>=26&&age<=45)?1500:2000;
		}
		else break;
	}
		cout<<"\nEnter account type : "; cin>>ac;
	}
	void viewAccountDetails(){
		cout<<"\n----------Account Details----------\nUsername : "<<u<<"\nEmail : "<<e<<"\nPhone number : "<<pn<<"\nAccount Type : "<<ac<<"\nBalance : Rs."<<b;
		
	}
	void withdraw(){
		int w;
		char p2[100];
		cout<<"\n----------Withdraw Amount----------";
		while(1){
		cout<<"\nEnter your password : "; cin>>p2;
		if(strcmp(p2,p)!=0){
			cout<<"\nPlease enter correct password";
		}
		else break;
	}
	while(1){
		cout<<"\nEnter the amount to be withdrawn : "; cin>>w;
		if((b-w)<mb) cout<<"\nRs."<<w<<" cannot be withdrawn as balance will go below minimum balance of Rs."<<mb;
		else{
			cout<<"\nSuccess! Rs."<<w<<" withdrawn from your account";
			b=b-w;
			cout<<"\nRemaining amount : Rs."<<b;
			break;
		}
	}
	
	}
	void deposit(){
		int n100,n200,n500,n2000,d;
		cout<<"\n----------Deposit Amount----------\nCurrent Balance : "<<b<<"\nEnter the amount to be deposited : Rs.";
		cin>>d;
		while(1){
			cout<<"\nEnter the number of notes of the following : \n100 : "; cin>>n100;
			cout<<"\n200 : "; cin>>n200;
			cout<<"\n500 : "; cin>>n500;
			cout<<"\n2000 : "; cin>>n2000;
			if((n100*100+n200*200+n500*500+n2000*2000)!=d){
				cout<<"\nPlease enter the current number fo notes as the sum of the notes does not equal to deposit amount";
				
			}
			else {
				cout<<"\nSuccess! The amount is deposited to your account\n";
				b=b+d;
				cout<<"Remaining balance : "<<b;
				break;
			}
		}
		
	}
	void authenticate(){
		char u1[100],p1[100];
		while(1){
		
		cout<<"\nEnter username : "; cin>>u1;
		cout<<"\nEnter password : "; cin>>p1;
		if(strcmp(u1,u)!=0||strcmp(p1,p)!=0){
			cout<<"\nIncorrect username or password, please try again!";
		}
		else break;
	}
	}
};

class BankSystem{
	public:
	void system(){
	BankAccount a;
	fstream fout;
	cout<<"Namaste! Welcome to National Bank!\nWe hope that you are having great day.\n\nPlease Register to continue:";
	fout.open("login.dat",ios::binary|ios::app);
	a.setDetails();
	fout.write((const char*)&a,sizeof(a));
	cout<<"Data written successfully!!!";
	fout.close();
	cout<<"\n----------Login----------";
	char u1[100],p1[100];
	int g=0,k=0;
	while(1){
	cout<<"\nEnter username : "; cin>>u1;
	cout<<"\nEnter password : "; cin>>p1;
	fout.open("login.dat",ios::binary|ios::in);
	g=0,k=0;
	while(fout.read((char*)&a,sizeof(a))){
		if(strcmp(a.u,u1)==0&&strcmp(a.p,p1)==0){
			g=1; 
			k=1;
			break;}
	}
	fout.close();
	if(k==0) cout<<"Account not found";
	if(g==1) break; 
	}
	int ch;
	
	while(1){
	ch=0;
	t=0;
	cout<<"\n----------MENU----------\n1.View account details\n2.Withdraw money\n3.Deposit money\n4.exit\nEnter your choice : "; cin>>ch;
	
	switch(ch){
		case 1:
			fout.open("login.dat",ios::binary|ios::in|ios::out);
			while(fout.read((char*)&a,sizeof(a))){
				if(strcmp(a.u,u1)==0&&strcmp(a.p,p1)==0){
					a.viewAccountDetails();
					break;
				}
			}
			fout.close();
			break;
		case 2:
			fout.open("login.dat",ios::binary|ios::in|ios::out);
			while(fout.read((char*)&a,sizeof(a))){
				if(strcmp(a.u,u1)==0&&strcmp(a.p,p1)==0){
					a.withdraw();
					t=fout.tellp();
					fout.seekp(t-sizeof(a));
					fout.write((const char*)&a,sizeof(a));
					break;
				}
			}
			fout.close();
			break;
		case 3:
			fout.open("login.dat",ios::binary|ios::in|ios::out);
			while(fout.read((char*)&a,sizeof(a))){
				if(strcmp(a.u,u1)==0&&strcmp(a.p,p1)==0){
					a.deposit();
					t=fout.tellp();
					fout.seekp(t-sizeof(a));
					fout.write((const char*)&a,sizeof(a));
					break;
				}
			}
			fout.close();
			break;
		case 4:
			exit(0);
			break;
		default:
			cout<<"Invalid input";
			
	}
}
}
};

int main(){
	remove("login.dat");
	BankSystem c;
	c.system();
}
