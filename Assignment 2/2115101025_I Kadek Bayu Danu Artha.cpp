#include <iostream>
#include <iomanip>
#include <math.h>


using namespace std;


float x0, x1, x2, f0, f1, f2;
int count, step = 1;
int f(int x){
	int result= (x*x*x) - x - 1;
	return result;
}	
void false_position(){
	cout<<" The equation is X^3 - X - 1\n";
	
	cout<<" Enter the first interval : ";
	cin>>x0;
	cout<<" Enter the second interval : ";
	cin>>x1;
	cout<<" Input the number of iteration you want to perform: ";
	cin>>count;
	system("cls");
	
	cout<<" The False Position Result\n\n";
	cout<<"\n\n The equation is X^3 - X - 1\n";
	cout<<" The interval ["<<x0<<", "<<x1<<"]\n\n\n";
		
		f0 = f(x0);
		f1 = f(x1);
		
		if(f0 * f1 >0.0){
			cout << "You have not assumed right x0 and x1\n";
        	return;
		}
		while(step<=count){
			x2 = x1 - (x1 - x0)* f1/(f1-f0);
			f2 = f(x2);
			
			cout<<" After "<<step<<" interations the value root is "<<x2<<endl;
			
			if( f0 * f2 <0){
				x1 = x2;
				f2 = f2;
			}
			else if( f0 * f2 >0){
				x0 = x2;
				f0 = f2;
			}
			else if(f0 * f2 == 0){
				cout<<"\n\n The approximation of the root is: "<<x2;
			}
			step++;
	}
	cout<<"\n\n The approximation of the root is: "<<x2;
}

void bisection(){
	cout<<" The equation is X^3 - X - 1\n";
	
	cout<<" Enter the first interval : ";
	cin>>x0;
	cout<<" Enter the second interval : ";
	cin>>x1;
	cout<<" Input the number of iteration you want to perform: ";
	cin>>count;
	system("cls");
	
	cout<<" The Bisection Result\n\n";
	cout<<"\n\n The equation is X^3 - X - 1\n";
	cout<<" The interval ["<<x0<<", "<<x1<<"]\n\n\n";
	if(f(x0)==0){
		x2=x0;
	}
	else if(f(x1)==0){
		x2=x1;
	}
	else{
		while(count >= step){
			f0 = f(x0);
			f1 = f(x1);
			x2 = (x0+x1)/2;
			f2 = f(x2);
			
			cout<<" After "<<step<<" interations the value root is "<<x2<<endl;
			if(f2==0){
				break;
			}
			
			if(f0 * f2 < 0){
				x1=x2;
			}
			else if(f2 * f0 > 0){
				x0=x2;
			}
			step++;
		}
	}
	cout<<"\n\n The approximation of the root is: "<<x2;
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
		cout<<" 1. Bisection\n 2. False Position\n";
		cout<<" Enter your choose: ";
		cin>>choose;
		system("cls");
		
		switch (choose){
			case 1:
				bisection();
				text();
				cin>>repeat;
				system("cls");
				break;
			case 2: 
				false_position();
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