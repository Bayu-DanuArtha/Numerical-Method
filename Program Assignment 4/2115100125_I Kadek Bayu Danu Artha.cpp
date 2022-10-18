#include <iostream>
using namespace std;

double Epsilon;
double function(double x)
{
	return x*x*x - x -1;
}

void bisection()
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

void text(){
	cout<<"\n\n\n Do you want repeat the program? (y/n)";
	cout<<" Enter your choose: ";
}

int main(){

	char repeat;
	do{
		bisection();
		text();
		cin>>repeat;
		system("cls");
	}while(repeat=='y'||repeat=='Y');
	cout<<"\n\n\n\t\t!-----THANK YOU----!";
	return 0;
}