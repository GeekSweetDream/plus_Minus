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


string inputValue();
int inputBase();
string getAnswer(char sign, int base, string firstNumb, string secondNumb);
bool changeNumbMax(string &firstNumb, string &secondNumb);
int convertNumb(char numb);
int equalMax(string firstNumb, string secondNumb);
void changeStr(string &firstStr, string &secondStr);
char action(char sign, int a, int b, int base, int &ost);
void turnString(string &str, int begin, int end);
string additionNumber(string firstNumber, string secondNumber, int base);
string helpAdd(string firstNumber, string secondNumber, int addSecNumb,int base, int &ost, int begin, int end);
string subtractionNumber(string firstNumb, string secondNumb, int base);
void removeZeroInStr(string &str, int begin, int end);


int main(int argc, const char * argv[])
{
    string test = "0123";
    int sup = 17+48;
    char p = static_cast<char>(sup);
    cout << p + 1 << endl;
    string one = "23", two = "125";
    cout << 1 << endl;
    turnString(two, 0, (int)two.length() - 1);
    cout << one << " " << two <<endl;

    cout << getAnswer('+', 10, "33", "32") << endl;
    cout << getAnswer('-', 10, "1133", "1132") << endl;
    
    return 0;
}

string inputValue() //ввод чисел и знака
{
    string value = "";
    cin >> value;
    return value;
}

int inputBase()
{
    int base = 10;
    cin >> base;
    return base;
}

string getAnswer(char sign, int base, string firstNumb, string secondNumb)  //функция, где происходит весь счет.
{
    string answer = "";
    turnString(firstNumb, 0, (int)firstNumb.length() - 1);
    turnString(secondNumb, 0, (int)secondNumb.length() - 1);
    if (changeNumbMax(firstNumb, secondNumb))
    {
        switch (sign)
        {
            case '+':{
                answer = additionNumber(firstNumb, secondNumb, base);
                break;
            }
            case '-':{
                answer = subtractionNumber(firstNumb, secondNumb, base);
                break;
            }
            case '*':break;
            case '/':break;
        }
    }else
    {
     answer = "Error, wrong numbers, the second number is greater than the second number!";
    }
    return answer;
}

string additionNumber(string firstNumber, string secondNumber, int base)
{
    string answer = "";
    int ost = 0;
    answer = helpAdd(firstNumber, secondNumber, 1, base, ost, 0, (int)secondNumber.length() - 1);
    if (firstNumber.length() != secondNumber.length())
    {
        answer += helpAdd(firstNumber, secondNumber, 0, base, ost, (int)secondNumber.length(),(int)firstNumber.length() - 1);
    }
    if (ost != 0)
    {
        if(ost > 9)
        {
            answer += static_cast<char>(ost + '0' + 7);
        }else
        {
            answer += static_cast<char>(ost + '0');
        }
    }
    turnString(answer, 0, (int)answer.length() - 1);
    return answer;
}

string helpAdd(string firstNumber, string secondNumber, int addSecNumb,int base, int &ost, int begin, int end)
{
    string answer = "";
    for(int i = begin; i <= end; i++)
    {
        int count = convertNumb(firstNumber[i]) + ost;
        if (addSecNumb)
        {
            count += convertNumb(secondNumber[i]);
        }
        ost = count / base;
        count = count % base;
        if (count > 9)
        {
            answer += static_cast<char>(count + '0' + 7);
            continue;
        }
        answer += static_cast<char>(count + '0');
    }
    return answer;
}

void turnString(string &str, int begin, int end)  //Переворачивает строку
{
    for (int i = begin; i <= (end / 2); i++)
    {
        char symb = str[i];
        str[i] = str[end - i];
        str[end - i] = symb;
    }
}

bool changeNumbMax(string &firstNumb, string &secondNumb)   //Ищет максимальное число и (записывает его в firstNumb)
{
    if (firstNumb.length() < secondNumb.length())
    {
        return false;
       // changeStr(firstNumb, secondNumb);                 //Eсли первое число меньше второго мы выводим false
    }else
    {
        if ((firstNumb.length() == secondNumb.length()))
        {
            if(equalMax(firstNumb,secondNumb))
            {
                return false;
               // changeStr(firstNumb, secondNumb);
            }
        }
    }
    return true;
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
        if((convertNumb(firstNumb[i])) < (convertNumb(secondNumb[i])))
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

string subtractionNumber(string firstNumb, string secondNumb, int base) // Вычитание
{
    string answer = "";
    int ost = 0;
    for(int i = 0; i <= (int)secondNumb.length() - 1; i++)
    {
        int diff = convertNumb(firstNumb[i]) - convertNumb(secondNumb[i]) + ost + 9;
        if( i == 0)
        {
            diff += 1;
        }
        ost = diff / base;
        diff = diff % base;
        if (diff > 9)
        {
            answer += static_cast<char>(diff + '0' + 7);
            continue;
        }
        answer += static_cast<char>(diff + '0');
    }
    if(firstNumb.length() != secondNumb.length())
    {
        firstNumb[secondNumb.length()] -= 1;
        int diff = convertNumb(firstNumb[secondNumb.length()]) + ost;
        if( diff > 9)
        {
            answer += static_cast<char>(diff + '0' + 7);
        }
        answer += static_cast<char>(diff + '0');
        for (int i = (int)secondNumb.length() + 1; i <= firstNumb.length() - 1; i++)
        {
            answer += firstNumb[i];
        }
    }
    turnString(answer, 0, (int)answer.length() - 1);
    removeZeroInStr(answer, 0, (int)answer.length() - 1);
    return answer;
}

void removeZeroInStr(string &str, int begin, int end)
{
    int i = 0;
    while( str[i] == '0')
    {
        i++;
    }
    str = str.substr(i,str.length());
}



