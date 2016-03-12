//
//  main.cpp
//  plus_minus
//
//  Created by Виталя on 25.02.16.
//  Copyright © 2016 Dreams of Pines. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>


using namespace std;

void changeStr(string &firstStr, string &secondStr);
void turnString(string &str, int begin, int end);
void removeZeroInStr(string &str);
bool changeNumbMax(string &firstNumb, string &secondNumb);
int convertNumb(char numb);
int equalMax(string firstNumb, string secondNumb);
int inputBase();
char action(char sign, int a, int b, int base, int &ost);
string multiplicationNumber(string firstNumb, string secondNumb, int base);
string additionNumber(string firstNumber, string secondNumber, int base);
string helpAdd(string firstNumber, string secondNumber, int addSecNumb,int base, int &ost, int begin, int end);
string subtractionNumber(string firstNumb, string secondNumb, int base);
string inputValue();
string getAnswer(char sign, int base, string firstNumb, string secondNumb);

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

    cout << getAnswer('+', 2, "1", "1") << endl;
    cout << getAnswer('-', 10, "133", "132") << endl;
    cout << getAnswer('*', 10, "16", "2") << endl;
    
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
    turnString(firstNumb, 0, (int)firstNumb.length() - 1);  //Переворачиваем строку, для простого счета
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
            case '*':{
                answer = multiplicationNumber(firstNumb, secondNumb, base);
                break;
            }
            case '/':break;
        }
    }else
    {
     answer = "Error, wrong numbers, the second number is greater than the second number!";
    }
    return answer;
}

string additionNumber(string firstNumber, string secondNumber, int base) //Сложение
{
    string answer = "";
    int ost = 0;
    answer = helpAdd(firstNumber, secondNumber, 1, base, ost, 0, (int)secondNumber.length() - 1); //Скалдываем и вычисляем
    if (firstNumber.length() != secondNumber.length())                                     // остаток и склеиваем строку
    {
        answer += helpAdd(firstNumber, secondNumber, 0, base, ost, (int)secondNumber.length(),(int)firstNumber.length() - 1);
    }// Если первое чилсо длиннее, то мы добавляем остальные цифры
    if (ost != 0)
    {
        if(ost > 9)
        {
            answer += static_cast<char>(ost + '0' + 7); // перевод из инта в чар(ост), если больше 9, то прибавляем 7, чтобы
        }else                                           // получить букву, иначе прибавляем только '0'
        {
            answer += static_cast<char>(ost + '0');
        }
    }
    turnString(answer, 0, (int)answer.length() - 1); // переворачиваем строку обратно
    return answer;
}

string helpAdd(string firstNumber, string secondNumber, int addSecNumb,int base, int &ost, int begin, int end)
{
    string answer = "";
    for(int i = begin; i <= end; i++)
    {
        int count = convertNumb(firstNumber[i]) + ost;  // складываем первое число и остаток
        if (addSecNumb)                                 // если надо, то мы прибавляем второе число
        {
            count += convertNumb(secondNumber[i]);
        }
        ost = count / base;                             // вычисляем остаток, который прибавляем к след. разряду
        count %= base;                                  // вычисляем остаток, который сохраняем в этом разряде
        if (count > 9)
        {
            answer += static_cast<char>(count + '0' + 7); // перевод из инта в чар
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
            if(equalMax(firstNumb,secondNumb))              //Сравниваем строку одинаковой длины
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
    int max = 0;                                                        // максим первое число
    for(int i = (int)firstNumb.length() - 1; i >= 0; i--)
    {
        if((convertNumb(firstNumb[i])) < (convertNumb(secondNumb[i])))  // переводим из чар в инт и сравниваем значение
        {                                                               // если  true, то максим второе число
            max = 1;
            break;
        }
    }
    return max;

}

int convertNumb(char numb)  //Конвертирует символ в число
{
    int intNumb = numb - '0';                   //Перевод из чар в инт
    if ((intNumb) > 9)                          //Если это буква, то отнимаем еще 7
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
        int diff = convertNumb(firstNumb[i]) - convertNumb(secondNumb[i]) + ost + (base - 1);       //ебаный говнокод
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
    removeZeroInStr(answer);
    return answer;
}

void removeZeroInStr(string &str)       //Удаление ведущих нулей
{
    int i = 0;
    while( (str[i] == '0') and (i < str.length() - 1))
    {
        i++;
    }
    str = str.substr(i,str.length());           //Удаляем ведущие нули, кроме 1, если результат равен 0. Удаляем копированием
}

string multiplicationNumber(string firstNumb, string secondNumb, int base)      //Умножение
{
    int sizeNumb = (int)(firstNumb.length() + secondNumb.length());  // максимально возможное длина, произведения
    string answer = "";
    vector<int> thirdNumb(sizeNumb);                                 // создаю вектор длиной макс длины
    for (int i = 0; i < firstNumb.length(); i++)
    {
        for(int j = 0; j < secondNumb.length(); j++)
        {
            thirdNumb[i + j] += convertNumb(firstNumb[i]) * convertNumb(secondNumb[j]); //циклом заполняем умножая две
        }                                                                               //цифры
    }
    for (int i = 0; i < sizeNumb; i++)                              // циклом проходим по вектору и вычисляем остатки
    {
        thirdNumb[i + 1] += thirdNumb[i] / base;                    // вычисляем остаток и прибавляем к следующему разряду
        thirdNumb[i] %= base;                                       // другой остаток записываем в этот разряд
        if (thirdNumb[i] > 9)
        {
            answer += static_cast<char>(thirdNumb[i] + '0' + 7);    // перевод из инта в чар
            continue;
        }
        answer += static_cast<char>(thirdNumb[i] + '0');
    }
    turnString(answer, 0, (int)answer.length() - 1);                // переворот строки
    removeZeroInStr(answer);                                        // удаление ведущих нулей
    return answer;
}

