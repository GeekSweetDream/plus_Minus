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
#include <cmath>


using namespace std;

void changeStr(string &firstStr, string &secondStr);
void turnString(string &str, int begin, int end);
void removeZeroInStr(string &str);
bool changeNumbMax(string &firstNumb, string &secondNumb);
int convertNumb(char numb);
int equalMax(string firstNumb, string secondNumb);
int inputBase();
int findFactorForDivider(int base, long divident, long divider);
int getNumberForDivision(string number, int size, int base);
char action(char sign, int a, int b, int base, int &ost);
char getNumberOrLetter(int number);
string multiplicationNumber(string firstNumb, string secondNumb, int base);
string additionNumber(string firstNumber, string secondNumber, int base);
string helpAdd(string firstNumber, string secondNumber, int addSecNumb,int base, int &ost, int begin, int end);
string subtractionNumber(string firstNumb, string secondNumb, int base);
string inputValue();
string getAnswer(char sign, int base, string firstNumb, string secondNumb);
string divisionNumber(string firstNumb, string seconNumb, int base);

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
    
    cout << findFactorForDivider(10, 100, 34) << endl;
    
    cout << getAnswer('+', 16, "25", "6s") << endl;
    cout << getAnswer('-', 10, "133", "133") << endl;
    cout << getAnswer('*', 10, "25", "4") << endl;
    cout << getAnswer('/', 10, "100", "20") << endl;
    
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
            case '/':{
                answer = divisionNumber(firstNumb, secondNumb, base);
                break;
            }
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
        answer += getNumberOrLetter(count);
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
        diff %= base;
        answer += getNumberOrLetter(diff);
    }
    if(firstNumb.length() != secondNumb.length())
    {
        firstNumb[secondNumb.length()] -= 1;
        int diff = convertNumb(firstNumb[secondNumb.length()]) + ost;
        answer += getNumberOrLetter(diff);
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
    while( (str[i] == '0') && (i < str.length() - 1))
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
    for (int i = 0; i < (sizeNumb - 1); i++)                              // циклом проходим по вектору и вычисляем остатки
    {
        thirdNumb[i + 1] += thirdNumb[i] / base;                    // вычисляем остаток и прибавляем к следующему разряду
        thirdNumb[i] %= base;                                       // другой остаток записываем в этот разряд
        answer += getNumberOrLetter(thirdNumb[i]);
    }
    thirdNumb[sizeNumb - 1] %= base;                                       // другой остаток записываем в этот разряд
    answer += getNumberOrLetter(thirdNumb[sizeNumb - 1]);
    turnString(answer, 0, (int)answer.length() - 1);                // переворот строки
    removeZeroInStr(answer);                                        // удаление ведущих нулей
    return answer;
}

char getNumberOrLetter(int number)                        //Функция, выдающая в зависимости от кода букву или цифру
{
    char answer = {};
    if (number > 9)
    {
        answer = static_cast<char>(number + '0' + 7);    // перевод из инта в чар
    }else
    {
        answer = static_cast<char>(number + '0');
    }
    return answer;
    
}

string divisionNumber(string firstNumb, string seconNumb, int base)
{
    string answer = "";
    turnString(firstNumb, 0, (int) firstNumb.length() - 1);
    turnString(seconNumb, 0, (int)seconNumb.length() - 1);
    while(firstNumb.length()>= seconNumb.length())
    {
        long numbOne = getNumberForDivision(firstNumb, (int)firstNumb.length(), base);
        long numbTwo = getNumberForDivision(seconNumb, (int)seconNumb.length(), base);
        if (numbOne < numbTwo)
        {
            numbOne += convertNumb(firstNumb[seconNumb.length()]) * pow(base,seconNumb.length());
        }
        answer += static_cast<char>(findFactorForDivider(base, numbOne, numbTwo) + '0');
        firstNumb = subtractionNumber(firstNumb, seconNumb, base);
    }
    return answer;
}

int findFactorForDivider(int base, long divident, long divider)
{
    int left = 0;
    int x = 0;
    int right = base;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (divider * middle <= divident)
        {
            x = middle;
            left = middle + 1;
        }else
        {
            right = middle - 1;
        }
    }
    return right;
}

int getNumberForDivision(string number, int size, int base)
{
    int answer = convertNumb(number[0]);
    for (int i = 1; i <= size - 1; i++)
    {
        answer += convertNumb(number[i]) * (pow(base,i));
    }
    return answer;
}











