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


int main(int argc, const char * argv[])
{
    string test = "0123";
    int sup = 17+48;
    char p = static_cast<char>(sup);
    cout << p + 1 << endl;
    string one = "23", two = "25";
    cout << 1 << endl;
    changeNumbMax(one, two);
    cout << one << " " << two <<endl;

    cout << getAnswer('-', 10, "25", "5") << endl;
    
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
    if (changeNumbMax(firstNumb, secondNumb))
    {
        int maxLength = (int)firstNumb.length() - 1;
        int ost = 0;
        switch (sign)
        {
            case '+':{
                answer = additionNumber(firstNumb, secondNumb, base);
                break;
            }
            case '-':break;
            case '*':break;
            case '/':break;
        }
            /*   // Добавить
             int numberOne = convertNumb(firstNumb[i]);
             int numberTwo = 0;
             if ((i - ((int)firstNumb.length() - (int)secondNumb.length())) >= 0)
             {
                numberTwo = convertNumb(secondNumb[i - (firstNumb.length() - secondNumb.length())]);
             }
             if ((sign == '-') && (i == maxLength - 1))
             {
             //прибавить +1 к числу;
                numberOne++;
            
             }
             if ((sign == '-' ) && (i == 0 ))
             {
             //отнять 1 от числа;
                numberOne--;
             }
             answer = action(sign, numberOne, numberTwo, base, ost) + answer;
             */
    }else
    {
     answer = "Error, wrong numbers, the second number is greater than the second number!";
    }
   // if (ost != 0)
   // {
   //     answer = static_cast<char>(ost + '0') + answer;
   // }
    return answer;
}

string additionNumber(string firstNumber, string secondNumber, int base)
{
    string answer = "";
    int ost = 0;
    turnString(firstNumber, 0, firstNumber.length() - 1);
    turnString(secondNumber, 0, secondNumber.length() - 1);
  /*  for(int i = 0; i <= secondNumber.length() - 1; i++)
    {
        
        int count = convertNumb(firstNumber[i]) + convertNumb(secondNumber[i]) + ost;
        ost = count / base;
        count = count % base;
        if (count > 9)
        {
            answer += static_cast<char>(count + '0' + 7);
            continue;
        }
        answer += static_cast<char>(count + '0');
    }*/
    answer = helpAdd(firstNumber, secondNumber, 1, base, ost, (int)secondNumber.length() - 1, (int)firstNumber.length() - 1);
    if (firstNumber.length() != secondNumber.length())
    {
       /* for(int i = (int)secondNumber.length() - 1; i <= firstNumber.length(); i++)
        {
            int count = convertNumb(firstNumber[i]) + ost;
            ost = count / base;
            count = count % base;
            if(count > 9)
            {
                answer += static_cast<char>(count + '0' + 7);
                continue;
            }
            answer += static_cast<char>(count + '0');
        }*/
        answer += helpAdd(firstNumber, secondNumber, 0, base, ost, (int)firstNumber.length() - 1, (int)secondNumber.length() - 1);
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
        int count = convertNumb(firstNumber[i]) + convertNumb(secondNumber[i]) + ost;
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
    for (int i = begin; i < (end / 2); i++)
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

/*
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
    return static_cast<char>( a + '0' );
}
 */






