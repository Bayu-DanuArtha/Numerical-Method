#include <iostream>
using namespace std;

double Epsilon;
double function(double x)
{
	return x*x*x - x -1;
}

void bisec_no_epsilon()
{
	int count, i=1;
	double X0, X1, X2;
	double result, f1, f2, f3;
	
	cout<<" The equation is X^3 - X - 1\n";
	
	cout<<" Enter the first interval : ";
	cin>>X0;
	cout<<" Enter the second interval : ";
	cin>>X1;
	cout<<" Input the number of iteration you want to perform: ";
	cin>>count;
	system("cls");
	
	cout<<"\n\n The equation is X^3 - X - 1\n";
	cout<<" The interval ["<<X0<<", "<<X1<<"]\n\n\n";
	if(function(X0)==0){
		result=X0;
	}
	else if(function(X1)==0){
		result=X1;
	}
	else{
		while(count >= i){
			f1 = function(X0);
			f2 = function(X1);
			X2 = (X0+X1)/2;
			f3 = function(X2);
			result=X2;
			
			if(f3==0){
				result=f3;
				break;
			}
			cout<<" After "<<i<<" interations the value root is "<<result<<endl<<endl;
			
			if(f1 * f3 < 0){
				X1=X2;
			}
			else if(f3 * f2 < 0){
				X0=X2;
			}
			i++;
		}
	}
	cout<<" The approximation of the root is: "<<X2;

}

void bisec_with_epsilon()
{
	double epsilon;
	double X0, X1, X2;
	double result, f1, f2, f3;
	
	cout<<" The equation is X^3 - X - 1\n";
	cout<<" Enter the first interval : ";
	cin>>X0;
	cout<<" Enter the second interval : ";
	cin>>X1;
	cout<<" Input the epsilon: ";
	cin>>epsilon;
	system("cls");
	
	cout<<"\n\n The equation is X^3 - X - 1\n";
	cout<<" The interval ["<<X0<<", "<<X1<<"]\n";
	cout<<" The value epsilon : "<<epsilon<<"\n\n\n\n";
	
	f1 = function(X0);
	f2 = function(X1);
	
	if(f1 * f2 >=0){
		cout << "You have not assumed right X0 and X1\n";
        return;
	}
	while((X1-X0)>=epsilon){
		X2 = (X0+X1)/2;
		f3 = function(X2);
		result=X2;
	
		if(f3 == 0){
			break;
		}
		else if(f1 * f3 < 0){
				X1=X2;
			}
		else if(f3 * f2 < 0){
				X0=X2;
		}
	}
	cout<<" The value of root is: "<<result<<endl;
}

void text(){
	cout<<"\n\n\n Do you want repeat the program? (y/n)";
	cout<<" Enter your choose: ";
}

int main(){
	int choose;
	char repeat;
	do{
		cout<<" Choose your way to calculate with bisection method :\n";
		cout<<" 1. Just with interval\n 2. With interval and epsilon\n";
		cout<<" Enter your choose: ";
		cin>>choose;
		system("cls");
		
		switch(choose){
			case 1: 
				bisec_no_epsilon();
				text();
				cin>>repeat;
				system("cls");
				break;
		
			case 2:
				bisec_with_epsilon();
				text();
				cin>>repeat;
				system("cls");
				break;
			default:
				cout<<" Your input wrong enter 1 or 2 to run the program\n";
				text();
				cin>>repeat;
				system("cls");
		}
	}while(repeat=='y'||repeat=='Y');
	cout<<"\n\n\n\t\t!-----THANK YOU----!";
	return 0;
}