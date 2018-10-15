#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

int main()
{
    first:
        system ("CLS");
    string ch;

    cout<<"Enter the stream of characters: ";
    cin>>ch;

    int n = ch.size();
    cout<<"Number of characters: "<<n<<endl;
    int chtoInt[n];    // to store the integer values of the character array

    for(int i=0; i<n ; i++)
    {
        chtoInt[i] = (int)(ch[i]);   //converts character to integer value
    }


//----------------------Logic for converting integer to binary and adding the parity bit-----------------

    int bin[n][8] = {0};          // 2D array for each 8-bit binary number
    int countofOne[n] = {0};      // to count the number of ones for each binary number for setting even/odd parity
    int temp=0;

        for(int i=0; i<n ; i++)
        {
            temp = chtoInt[i];

            for (int j=0 ; temp>0 ; j++)
            {
                if(temp%2 == 0)
                    bin[i][j] = 0;

                else
                {
                    bin[i][j] = 1;
                    countofOne[i] += 1; //counting the number of ones
                }

                temp = temp/2;

            }
        }

//------------------------Logic for even/odd parity---------------------------

        int choice;
        again:
        cout<<"Enter \'0\' for even parity or \'1\' for odd parity: ";
        cin>>choice;
        cout<<endl;
        if((choice != 1) && (choice != 0))
            goto again;

        for(int i=0; i<n ; i++)
        {

            if(!(countofOne[i]%2 == choice)) //to compare our choice with the count of ones
            {                                // and set or reset the MSB according to our choice(even/odd parity)
                bin[i][7] = 1;
            }

        }
//--------------------------Displaying the Numbers-------------------------------------



        for(int i=0; i<n ; i++)
        {
            cout<<ch[i]<<" | Integer Value:"<<chtoInt[i]<<" | Number of ones: "<<countofOne[i];
            cout<<" | Binary Value after setting parity: ";
            for(int j=7 ; j>=0 ; j--)
            {
                cout<<bin[i][j];
            }
            cout<<endl;
        }
        cout<<endl;

//----------------The below logic converts the Binary Numbers to HEX and displays them---------------

char ch1,ch2;

cout<<"After setting parity: "<<endl;

for(int k=0 ; k<n ; k++)
{
            int res=0, res2=0;  //breaking up the 8 bit binary in two 4-bit numbers.

                for(int i=0; i<8 ;i++)
                {
                    if(i>=0 && i<=3)
                    {
                        res += ((bin[k][i])*(pow(2,i))); //converting the first 4 bits to integer
                    }
                    else if(i>=4 && i<=7)
                    {
                        res2 += ((bin[k][i])*(pow(2,i-4))); //converting the next 4 bits to integer
                    }
                }

                // If either of the result is between 0-9, adding 48 to it, since their ASCII value is between 48-57
                // or if the result is between 10-15, adding 55 to it, since their ASCII value is between 65-70 (A-F)
                // Displaying the result in the form of character


                if(res<=9)
                {
                    res = res+48;
                }
                else if(res >= 10)
                {
                    res = res+55;
                }

                if(res2<=9)
                {
                    res2 = res2+48;
                }
                else if(res2 >= 10)
                {
                    res2 = res2+55;
                }
                ch1 = (char)res;
                ch2 = (char)res2;

                cout<<"Hex value of "<<ch[k]<<": "<<ch2<<ch1<<endl;

}
    int first;
    cout<<"Enter \'1\' to continue or \'0\' to exit: ";
    cin>>first;
    cout<<endl;
        if(first == 1)
            goto first;
        else if(first == 0)
            exit(0);


}

