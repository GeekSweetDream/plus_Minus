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
int convertNumb(char numb);
char action(int sign, int a, int b, int base, int &ost);

int main(int argc, const char * argv[])
{
    string test = "0123";
    cout << "12"+test << endl;
    cout << 123<< endl;
    return 0;
}

string inputBigNumber() //ввод числа
{
    string value = "";
    cin >> value;
    return value;
}

string operations(char sign, string firstNumb, string secondNumb)  //
{
    string answer = "";
    int maxLength = (int) firstNumb.length();
    if (giveNumbLong(firstNumb, secondNumb))
    {
        maxLength = (int) secondNumb.length();
    }
    for (int i = maxLength - 1; i >= 0; i--)
    {
      //Не потерять
    }
    return 0;
}

int giveNumbLong(string firstNumb, string secondNumb)   //Выдает максимальное число
{
    int winner = 0;
    if (firstNumb.length() < secondNumb.length())
    {
        winner = 1;
    }
    return winner;
}

int convertNumb(char numb)  //Конвертирует символ в число
{
    int intNumb = numb - '0';
    if ((numb - '0') > 9)
    {
        intNumb -= 6;
    }
    return intNumb;
}

char action(char sign, int a, int b, int base, int &ost)   //Складывает части числа
{
    char answer = {};
    switch (sign)
    {
        case '+':{
            a += b + ost;
            ost = a / base;
            a = a % base;
            break;
        }
        case '*':{
            a *= b + ost;
            ost = a / base;
            a = a % base;
            break;
        }
        case '-':{
            // Сделать
            break;
        }
        case '/':{
            //сделать
            break;
        }
    }
    return answer+a ;
}






