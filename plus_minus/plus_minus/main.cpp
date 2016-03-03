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
string getAnswer(char sign, string &firstNumb, string &secondNumb);
void changeNumbMax(string &firstNumb, string &secondNumb);
int convertNumb(char numb);
int equalMax(string firstNumb, string secondNumb);
void changeStr(string &firstStr, string &secondStr);
char inputSign();
char action(int sign, int a, int b, int base, int &ost);

int main(int argc, const char * argv[])
{
    string test = "0123";
    int sup = 17+48;
    char p = static_cast<char>(sup);
    cout << p << endl;
    cout << 'B' - '0'<< endl;
    return 0;
}

string inputBigNumber() //ввод числа
{
    string value = "";
    cin >> value;
    return value;
}

char inputSignAndBase() // ввод арифметического действия и системы счисления
{
    char sign = {};
    cin >> sign;
    return sign;
}

string getAnswer(char sign, string &firstNumb, string &secondNumb)  //функция, где происходит весь счет.
{
    string answer = "";
    int maxLength = (int) firstNumb.length();
    changeNumbMax(firstNumb, secondNumb);
    maxLength = (int)firstNumb.length() - 1;
    for (int i = maxLength - 1; i >= 0; i--)
    {
        // Добавить
    
        if (i == maxLength - 1)
        {
            //прибавить +1 к числу;
            
        }
        if (i == 0 )
        {
            //отнять 1 от числа;
        }
    }
    return answer;
}

void changeNumbMax(string &firstNumb, string &secondNumb)   //Ищет максимальное число и записывает его в firstNumb
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
        intNumb -= 7;
    }
    return intNumb;
}

char action(char sign, int a, int b, int base, int &ost)   //Складывает части числа
{
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
            a += (base - 1) - b + ost; //вычитание по школьному
            ost = a / base;
            a = a % base;
            break;
        }
        case '/':{
            //сделать
            break;
        }
    }
    return static_cast<char>(a + '0');
}






