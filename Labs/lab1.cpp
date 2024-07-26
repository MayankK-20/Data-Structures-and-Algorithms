//Question 1
/*
#include<iostream>
using namespace std;

int main(){

    int num1, num2;
    cout<<"1st Number: ";
    cin>>num1;
    cout<<"2nd Number: ";
    cin>>num2;

    cout<<"Sum of the numbers: "<<num1+num2<<endl;
    cout<<"Average of the numbers: "<<(double)(num1+num2)/2<<endl;
    cout<<"Sum of the squares of the numbers: "<<(num1*num1)+(num2*num2)<<endl;

    return 0;
}*/







//Question 2
/*
#include<iostream>
using namespace std;

int main(){

    string name, address;
    int age;
    cout<<"Input your name: ";
    cin>>name;
    cout<<"Input your Address: ";
    cin>>address;
    cout<<"Input your age: ";
    cin>>age;
    cout<<"Your Name: "<<name<<endl;
    cout<<"Your Address: "<<address<<endl;
    cout<<"Your Age: "<<age<<endl; 

    return 0;
}
*/






//Question 3
/*
#include<iostream>
using namespace std;

int main(){

    int maxim, minim;
    int i;
    cout<<"Input 10 numbers with a space: ";
    cin>>i;
    maxim = i;
    minim = i;
    for (int j=1; j<10; j++){
        cin>>i;
        if (i>maxim){
            maxim=i;
        }
        if (i<minim){
            minim=i;
        }
    }
    cout<<"Maximum of the inputted numbers: "<<maxim<<endl;
    cout<<"Minimum of the inputted numbers: "<<minim<<endl;

    return 0;
}
*/




//Question 4
/*
#include<iostream>
using namespace std;

int main(){

    double celcius;
    cout<<"Input Celcius to be converted in degrees: ";
    cin>>celcius;
    cout<<((9*celcius)/5)+32<<" degrees fahrenheit"<<endl;

    return 0;
}
*/




//Question 5
/*
#include<iostream>
using namespace std;

int main(){

    cout<<"Your name is Mayank Kumar\nRoll number 2023317\nStudent at IIIT Delhi\n";

    return 0;
}
*/




//Question 6
/*
#include<iostream>
using namespace std;

int main(){

    int num, temp;
    cin>>num;
    temp = num;
    int arr[3];
    arr[0]= num/100;
    num -= (arr[0]*100);
    arr[1]= num/10;
    num -= (arr[1]*10);
    arr[2]= num;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            for (int k=0; k<3; k++){
                if (i!=j && j!=k && i!=k){
                    if ((arr[i]*100+arr[j]*10+arr[k])<=temp){
                        cout<<(arr[i]*100+arr[j]*10+arr[k])<<endl;
                    }
                }
            }
        }
    }
    

    return 0;
}
*/





//Question 7
/*
#include<iostream>
using namespace std;

int main(){

    int radius;
    cout<<"Input radius: ";
    cin>>radius;
    cout<<"The area of a circle of radius "<<radius<<" units is "<<(3.14159*radius*radius)<<" units.";

    return 0;
}
*/





//Question 8
/*
#include<iostream>
using namespace std;

int main(){

    double centi;
    cout<<"centimeters: ";
    cin>>centi;
    float inches=centi/2.54;
    int feet=inches/12;
    inches = inches-(feet*12);
    cout<<feet<<" feet "<<inches<<" inches";

    return 0;
}
*/






//Question 9
/*
#include<iostream>
using namespace std;

int main(){

    int seconds;
    cout<<"seconds: ";
    cin>>seconds;
    int hour = seconds/(60*60);
    seconds -= (hour*60*60);
    int minute = (seconds/60);
    seconds -= (minute*60);
    cout<<hour<<" hours "<<minute<<" minutes "<<seconds<<" seconds"<<endl;

    return 0;
}
*/





//Question 10
/*
#include<iostream>
using namespace std;

int main(){

    int clock,time;
    cin>>clock;
    cin>>time;
    int ans = (clock+time)%2400;
    if ((ans%100)>=60){
        if (((ans%100)-60)<10){
            cout<<"start time is "<<clock<<" duration is "<<time<<" end time is "<<(ans/100)+1<<"0"<<(ans%100)-60;
        }
        else{
            cout<<"start time is "<<clock<<" duration is "<<time<<" end time is "<<(ans/100)+1<<(ans%100)-60;
        }
    }
    else{
        cout<<"start time is "<<clock<<" duration is "<<time<<" end time is "<<ans;
    }

    return 0;
}
*/
