//
//  main.cpp
//  plus_minus
//
//  Created by Виталя on 25.02.16.
//  Copyright © 2016 Dreams of Pines. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;


string inputBigNumber();
string operations(char sign, string firstNumb, string secondNumb);
int giveNumbLong(string firstNumb, string secondNumb);

int main(int argc, const char * argv[])
{
    string test = "0123";
    cout << "12"+test << endl;
    cout << 'a'-'0'<< endl;
    return 0;
}

string inputBigNumber()
{
    string value = "";
    cin >> value;
    return value;
}

string operations(char sign, string firstNumb, string secondNumb)
{
    const string symbolArray = "0123456789ABCDEFG"; //Дописать;
    int maxLength = (int) firstNumb.length();
    if (giveNumbLong(firstNumb, secondNumb))
    {
        maxLength = (int) secondNumb.length();
    }
    for (int i = maxLength - 1; i >= 0; i--)
    {
       // if ()
    }
    return 0;
}

int giveNumbLong(string firstNumb, string secondNumb)
{
    int winner = 0;
    if (firstNumb.length() < secondNumb.length())
    {
        winner = 1;
    }
    return winner;
}




