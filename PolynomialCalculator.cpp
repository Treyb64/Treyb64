/*
Practice Project
FOIL Calculator
*/

#include <iostream>
using namespace std;

class Polynomial
{
    protected:
        int c1, c2;
        char pm, v1, v2;
    public:
        Polynomial()
        {
            this->c1 = 0;
            this->v1 ='0';
            this->pm ='0';
            this->c2 = 0; 
            this->v2 ='0';  
        }
        Polynomial(int c1, char v1, char pm, int c2, char v2)
        {
            this->c1=c1;
            this->v1=v1; 
            this->pm=pm;
            this->c2=c2;
            this->v2=v2;   
        }
        friend istream& operator >>(istream& input, Polynomial& Polynomial);
        friend ostream& operator <<(ostream& output, Polynomial& Polynomial);
        friend void operator *(const Polynomial& P1, const Polynomial& P2);
};
class ax_b:public Polynomial
{
    public:
        ax_b()
        {
            this->c1 = 0;
            this->v1 ='0';
            this->pm ='0';
            this->c2 = 0;   
        }
        ax_b(int c1, char v1, char pm, int c2)
        {
            this->c1=c1;
            this->v1=v1;
            this->pm=pm;
            this->c2=c2;   
        }
        friend istream& operator >>(istream& input, ax_b& Binomial);
        friend ostream& operator <<(ostream& output, ax_b& Binomial);
        friend void operator *(const ax_b& b1, const ax_b& b2);
};
class ax:public Polynomial
{
    public:
        ax()
        {
            this->c1 = 0;
            this->v1 ='0';
        }
        ax(int c1, char v1)
        {
            this->c1=c1;
            this->v1=v1;
        }
        friend istream& operator >>(istream& input, ax& Monomial);
        friend ostream& operator <<(ostream& output, ax& Monomial);
        friend void operator *(const ax& m1, const ax& m2);
};

int main()
{
    
    int choice;
    string (response);
    do{
        cout<<"Please choose the form\n1.)ax\n2.)ax+b\n3.)ax+by"<< endl;
        cin >>choice;
        switch(choice)
        {
            case 1:
            {
                ax m1,m2;
                cout<<"Enter your Monomial, if there is no coefficient, put 1 in front\n";
                cin >>m1 >>m2;
                cout<<m1<<m2<<endl;
                m1*m2;
                break;
            }

            case 2:
            {
                ax_b b1,b2;
                cout<<"Enter your Binomials(ax +/- b), if there is no coefficient, put 1 in front\n";
                cin >> b1 >> b2;
                cout << b1<<b2<<endl;
                b1*b2;
                break;
            }
            case 3:
            {
                Polynomial p1,p2;
                cout<<"Enter your Binomials(ax +/- by), if there is no coefficient, put 1 in front\n";
                cin >> p1 >> p2;
                cout << p1 << p2 << endl;
                p1*p2;
                break;
            }
            default:
            {
                cout << "Invalid input";
                exit(1);
            }

        };
        cout<<"\nWould you like to go again?"<<endl;
        cin >> response;
    }while(response == "yes"||response == "Yes");
    
    return 0;
}

istream& operator >>(istream& input, Polynomial& Polynomial)
{
    cin >> Polynomial.c1 >> Polynomial.v1 >> Polynomial.pm >> Polynomial.c2>>Polynomial.v2;
    if(Polynomial.c2 < 0 && Polynomial.pm =='-')
    {
        Polynomial.pm = '+';
        Polynomial.c2*=-1;
    }else if(Polynomial.c2 < 0)
    {
        Polynomial.pm = '-';
        Polynomial.c2*=-1;
    }
    return input;
}
ostream& operator <<(ostream& output, Polynomial& Polynomial)
{
    if(Polynomial.c1 == 1)
    {
        cout << "(" <<Polynomial.v1 <<Polynomial.pm << Polynomial.c2<< Polynomial.v2<<")";
    }else if(Polynomial.c2 == 1)
    {
        cout << "(" << Polynomial.c1 <<Polynomial.v1 <<Polynomial.pm << Polynomial.v2<<")";
    }else if(Polynomial.c1 ==1 && Polynomial.c2 == 1)
    {
        cout << "(" <<Polynomial.v1 <<Polynomial.pm << Polynomial.v2<<")";
    }else
    {
        cout << "(" << Polynomial.c1 <<Polynomial.v1 <<Polynomial.pm << Polynomial.c2<< Polynomial.v2<<")";
    }
    
    return output;
}

void operator *(const Polynomial& P1, const Polynomial& P2)
{
    char ch = 253;
    if(P1.c1 ==P2.c1 && P1.v1 == P2.v1 &&P1.pm != P2.pm && P1.c2 == P2.c2 && P1.v2 == P2.v2)
    {
        //Difference Of Squares
        cout << P1.c1*P1.c1 << P1.v1<<ch<<"-"<<P1.c2*P1.c2<<P1.v2<<ch;
    }else
    {
        //First
        cout<< P1.c1*P2.c1;
        if(P1.v1 == P2.v1)
        {
            cout << P1.v1 <<ch;
        }else
        {
            cout<< P1.v1 << P2.v1;
        }
        //Inner/Outer
        if((P1.v1 == P2.v1 && P1.v2==P2.v2)||(P1.v1 == P2.v2 && P1.v2 == P2.v1 ))
        {
            if((P2.c1*P1.c2+P2.c2*P1.c1)>0)
            {
                cout << P1.pm << (P2.c1*P1.c2+P2.c2*P1.c1)<<P1.v1<<P1.v2;
            }else 
            {
                cout << (P2.c1*P1.c2+P2.c2*P1.c1)<<P1.v1<<P1.v2;
            }

        }else
        {
            if(P1.v2 == P2.v1)
            {
                cout << P1.pm << P2.c1*P1.c2+P2.c2*P1.c1 << P1.v2<<ch;
            }else
            {
                cout << P1.pm << P2.c1*P1.c2<<P1.v2<<P2.v1;
            }
            
            if(P1.v1 == P2.v2)
            {
                cout << P2.pm << P2.c1*P1.c2+P2.c2*P1.c1 << P1.v1<<ch;
            }else
            {
                cout << P2.pm << P2.c2*P1.c1<<P1.v1<<P2.v2;
            }
        }
        //Last
        if(P1.pm == P2.pm)
        {
            cout<<"+"<<P1.c2*P2.c2;
        }else
        {
            cout<<"-"<<P1.c2*P2.c2;
        }
        if(P1.v2 == P2.v2)
        {
            cout << P1.v2 <<ch;
        }else
        {
            cout<< P1.v2 << P2.v2;
        }
    }
}
istream& operator >>(istream& input, ax_b& Binomial)
{
    cin >> Binomial.c1 >> Binomial.v1 >> Binomial.pm >> Binomial.c2;
    if(Binomial.c2 < 0 && Binomial.pm =='-')
    {
        Binomial.pm = '+';
        Binomial.c2*=-1;
    }else if(Binomial.c2 < 0)
    {
        Binomial.pm = '-';
        Binomial.c2*=-1;
    }
    return input;
}
ostream& operator <<(ostream& output, ax_b& Binomial)
{   
    if(Binomial.c1 == 1)
    {
        cout << "(" <<Binomial.v1 <<Binomial.pm << Binomial.c2<<")";
    }else 
    {
        cout << "(" << Binomial.c1 <<Binomial.v1 <<Binomial.pm << Binomial.c2<<")";
    }
    return output;
}
void operator *(const ax_b& B1, const ax_b& B2)
{
    char ch = 253;
    if(B1.c1 ==B2.c1 && B1.v1 == B2.v1 && B1.pm != B2.pm && B1.c2 == B2.c2)
    {
        //Difference Of Squares
        cout << B1.c1*B1.c1 << B1.v1<<ch<<"-"<<B1.c2*B1.c2;
    }else
    {
        //First
        cout<< B1.c1*B2.c1;
        if(B1.v1 == B2.v1)
        {
            cout << B1.v1 <<ch;
        }else
        {
            cout<< B1.v1 << B2.v1;
        }
        //Inner/Outer
        if(B1.pm == B2.pm)
        {
            cout << B1.pm << B2.c1*B1.c2+B2.c2*B1.c1 << B1.v1;
        }else
        {
            cout << B1.pm << B2.c1*B1.c2<<B2.v1;
            cout << B2.pm << B2.c2*B1.c1<<B1.v1;
        }
        //Last
        if(B1.pm == B2.pm)
        {
            cout<<"+"<<B1.c2*B2.c2;
        }else
        {
            cout << "-" <<B1.c2*B2.c2;
        }
    }
}
istream& operator >>(istream& input, ax& Monomial)
{
    cin >> Monomial.c1 >> Monomial.v1;
    return input;
}
ostream& operator <<(ostream& output, ax& Monomial)
{
    if(Monomial.c1==1)
    {
        cout << "("<< Monomial.v1<< ")"; 
    }else
    {
    cout << "(" << Monomial.c1 << Monomial.v1<< ")"; 
    }
    return output;
}
void operator *(const ax& m1, const ax& m2)
{
    char ch = 253;
    if(m1.v1==m2.v1)
    {
        cout<< m1.c1*m2.c1<<m1.v1<<ch;
    }else 
    {
        cout<<m1.c1*m2.c1<<m1.v1<<m2.v1;
    }
}