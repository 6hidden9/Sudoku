#include <iostream>
//#include <graphics.h>
using namespace std;
bool cheeker (int table[9][9],int satr,int sotoon,int nom)
{
    for (int i =0 ; i<9; i++)
    {
        if (table[satr][i]==nom)
            return false;
    }
    for (int i =0 ; i<9 ; i++)
    {
        if (table[i][sotoon]==nom)
            return false ;
    }
    for (int i =0 ; i<3 ; i++)
    {
        for (int j =0; j <3; j++)
        {
            if (table[(satr/3)*3+i][(sotoon/3)*3+j]==nom )
                return false ;
        }
    }
    return true ;
}

bool movve (int table[9][9] ,int satr ,int  sotoon)
{
 cout<<satr<<" "<<sotoon<<endl;
    if (sotoon==9)
    {
       if (satr==8)
       {
           return true ;
       }
       else
       {
           satr++;
           sotoon=0;
       }
    }



    if (table [satr][sotoon]>0)
    {
       return movve(table,satr,sotoon+1);
    }
    else
    {
        for (int i =1; i<10; i++)
        {
            if (cheeker(table,satr,sotoon,i))
            {
                table[satr][sotoon]=i;
                if (movve(table,satr,sotoon+=1))
                {
                    return true;
                }
            table[satr][sotoon]=0;
            }

        }
        return false ;
    }
}


int main()
{
    //vorood jadval
    int table[9][9];
    for (int i =0 ; i<9 ; i++)
    {
        for (int j = 0 ; j<9; j++)
        {
            cin >> table[i][j];
        }
    }
    movve(table,0,0);

    // initwindow(490,490);
     for (int i =0 ; i<9 ; i++)
        {
            for (int j = 0 ; j<9; j++)
            {
                cout<<table[i][j]<<" ";
            }
            cout<<endl;
        }
    system("pause");
    return 0 ;
}

