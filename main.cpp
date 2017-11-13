/** Lab 10 - 555 Timer Calculator
 *
 * Martina Nunvarova
 * 6/11/2017
 */

#include <iostream>
#include <stdio.h>

using namespace std;

///Input:
///     prompt - the text to be displayed
///     zeroOptions - 0=no option, only positive value; 1=Zero and positive; 2=Any real number
double getDoubleValue(string prompt, int zeroOptions)
{
    double output;
    char outOK;

    do {
        outOK=1;
        cout << prompt;
        fflush(stdout);
        fflush(stdin);
        cin>>output;
        if (output<0) {
            if (zeroOptions<2)
                outOK=0;
        } else if (output==0) {
            if (zeroOptions<1)
                outOK=0;
        }
        if (!outOK)
            cout << "Illegal input. ";
    } while (!outOK);
    return output;
}

/// using a function to calculate, using pointers to return the results
void timer555(double r1, double r2, double c, double *f, double *d)
{
    c/=1000000; ///convert to Farrads
    r1*=1000;   ///converty to Ohms
    r2*=1000;   /// --//--

    *f=(1.44/(r1+2*r2)/c);      ///use the prescribed formula
    *d=(r1/(r1+r2));            ///  --//--
}

///Main Function
int main()
{
    double r1,r2,c,f,d;                                                     ///Declare variables

    cout << "555 Timer calculator" << endl<<endl<<endl;                        ///Tell user, it's sphere calculator
    r1=getDoubleValue("Please enter value of R1 [kOhm]: ",0);               ///Force them to enter positive double or 0
    r2=getDoubleValue("Please enter value of R2 [kOhm]: ",0);               ///Force them to enter positive double or 0
    c=getDoubleValue("Please enter value of C    [uF]: ",0);                ///Force them to enter positive double or 0

    timer555(r1,r2,c,&f,&d);                                                ///Call a function as per assignment, with pointer parametres
    d*=100;                                                                 ///nicer in a % format
    cout <<endl<<endl<< "~The 555 Timer claculated~" << endl << endl << "Frequency: " <<f<<"Hz"<<endl<<"Duty: "<<d<<"%"<<endl<<endl; ///notify user

    getDoubleValue("Enter anything (i.e.: 'q' to quit\n",2);                ///wait for something to be entered

    return 0;                                                               ///exit to OS no errors
}
