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
int giveNumbMax(string firstNumb, string secondNumb);
int convertNumb(char numb);
int equalMax(string firstNumb, string secondNumb);
void changeStr(string &firstStr, string &secondStr);
char action(int sign, int a, int b, int base, int &ost);

int main(int argc, const char * argv[])
{
    string test = "0123";
    cout << "22"+test << endl;
    cout << 123<< endl;
    return 0;
}

string inputBigNumber() //ввод числа
{
    string value = "";
    cin >> value;
    return value;
}

string operations(char sign, string &firstNumb, string &secondNumb)  //
{
    string answer = "";
    int maxLength = (int) firstNumb.length();
    if (giveNumbMax(firstNumb, secondNumb))
    {
        maxLength = (int) secondNumb.length();
    }
    for (int i = maxLength - 1; i >= 0; i--)
    {
      //Не потерять
    }
    return 0;
}

void giveNumbMax(string &firstNumb, string &secondNumb)   //Ищет максимальное число и записывает его в firstNumb
{
    if (firstNumb.length() < secondNumb.length())
    {
        changeStr(firstNumb, secondNumb);
    }else
    {
        if ((firstNumb.length() == secondNumb.length()))
        {
            if(equalMax(firstNumb,secondNumb))
            {
                changeStr(firstNumb, secondNumb);
            }
        }
    }
}

void changeStr(string &firstStr, string &secondStr) // меняет местами строки
{
    string helpStr = firstStr;
    firstStr = secondStr;
    secondStr = helpStr;
}
    
int equalMax(string firstNumb, string secondNumb)  // сравнивает две строки одинаковой длины
{
    int max = 0;
    for(int i = (int)firstNumb.length() - 1; i >= 0; i--)
    {
        if((firstNumb[i] - '0') < (secondNumb[i] - '0'))
        {
            max = 1;
            break;
        }
    }
    return max;

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






