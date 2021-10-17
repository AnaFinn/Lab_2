// Lab2_Payslip.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include <string.h>
#include <string>// as i want to use  getline string function should be included
using namespace std;

//identify sructure for employees and report
struct Report {
    float total_pay, total_deduction, total_gross;
};
struct Employee {
    int ird, number;
    float id, hours, rate, extra, gross, minus, deduction, tax1;
    string name, address, mail;
    //char code;
}; 

//function prototypes
void input();
float tax(float tax1, float gross);
float extra_hours(float hours, float gross);
//float report();

int main()
{
    string start, end;
    cout << "Enter Week Start Date\n";
    getline(cin, start);//enter a line of string having multiple words
    cout << "You entered: " << start;
    cout << "Enter Week end Date\n";
    getline(cin, end);
    cout << "You entered: " << end;
    input();//calling function
    //report();

}

void input()//declare function
{
    Employee e[2];//calling structure
    Report r;
    //tax1 = 0;// tax rate is equal to 0 for now
    for (int i = 0; i < 2; i++)//creating array using for loop
    {
        cout << "\nEnter Emplyee ID: " << endl;
        cin >> e[i].id;//filling the array using structure 
        cin.ignore();
        cout << "\nEnter Emplyee full Name: " << endl;
        getline(cin, e[i].name);
        cin.ignore();//creating space between the line in order to clear the buffer after getline
        cout << "\nEnter Emplyee address: " << endl;
        getline(cin, e[i].address);
        cout << "\nEnter Emplyee e-mail: " << endl;
        cin >> e[i].mail;
        cin.ignore();
        cout << "\nEnter Emplyee IRD num.: " << endl;
        cin >> e[i].ird;
        cin.ignore();
        cout << "\nEnter Emplyee hours per week: " << endl;
        cin >> e[i].hours;
        cin.ignore();
        cout << "\nEnter Emplyee hour rate: " << endl;
        cin >> e[i].rate;
        cin.ignore();
        //cout << "\nEnter Emplyee Tax rate: " << endl;
       // cin >> e[i].tax;
    }
    for (int i = 0; i < 2; i++)//accessing array using for loop
    {
        if (e[i].rate <= 50 && e[i].rate >= 20 && e[i].hours<50)//creating condition
        {
            cout << "\nEmplyee ID: " << e[i].id;
            cout << "\nEmplyee Name: " << e[i].name;
            cout << "\nEmplyee full adress: " << e[i].address;
            cout << "\nEmplyee e-mail: " << e[i].mail;
            cout << "\nEmplyee IRD: " << e[i].ird;
            cout << "\nEmplyee hours: " << e[i].hours;
            cout << "\nEmplyee hours rate: " << e[i].rate;
            e[i].extra = extra_hours(e[i].hours, e[i].rate);//calling function
            e[i].gross = e[i].hours * e[i].rate;//calculations are done with arithmetic operators
            cout << "\nEmplyee gross pay: " << e[i].gross;
            e[i].minus = tax(e[i].tax1, e[i].gross);//calling function and assigning it to the varible
            e[i].deduction = (e[i].gross * e[i].minus) / 100;
            cout << "\nTax Deduction: " << e[i].deduction;
            cout << "\nNet Pay: " << e[i].gross - e[i].deduction;
        }
        else//alternative if the data does not meet the criteria
        {
            cout << "\nThe information presented is not correct. Check hour rate or hours of work.";
        }
        r.total_gross = e[i].gross * i;
        r.total_deduction = e[i].deduction * i;
        r.total_pay = r.total_gross - r.total_deduction;
    }
 
       cout << r.total_gross<<endl;
       cout << r.total_deduction<<endl;
       cout << r.total_pay<<endl;
}

//declair function to establish tax rate
float tax(float tax1, float gross)
{
    if (gross < 270)
    {
        tax1 = 10.5;
    }
    else if (gross >= 270 && gross < 923)
    {
        tax1 = 17.5;
    }
    else if (gross >= 923 && gross < 1346)
    {
        tax1 = 30;
    }
    else if (gross >= 1346 && gross < 3461)
    {
        tax1 = 33;
    }
    return tax1;//returning the tax rate
}

float extra_hours(float hours, float rate)//function to identify The number of hours worked
{
    if (hours > 40)
    {
        rate = rate * 1.5;
    }
    return rate;
}


