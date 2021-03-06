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
bool changeNumbMax(string &firstNumb, string &secondNumb, char sign);
bool checkCorrectedInputValue(string value, int base);
bool checkCorrectedInputBase(int base);
int comparisonNumb(string firstNumb, string secondNumb);
int convertNumb(char numb);
int equalMax(string firstNumb, string secondNumb);
int inputBase();
int findFactorForDivider(int base, string divident, string divider);
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
    
    cout << "+ " << getAnswer('+', 10, "2", "26") << endl;
    cout << "- " << getAnswer('-', 10, "134", "134") << endl;
    cout << "* " << getAnswer('*', 10, "25", "4") << endl;
    cout << "/ " << getAnswer('/', 10, "1001", "9") << endl;
    
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

bool checkCorrectedInputBase(int base)
{
    bool answer = true;
    if (base > 36)
    {
        answer = false;
    }
    return answer;
}

bool checkCorrectedInputValue(string value, int base)
{
    bool answer = true;
    int  sizeValue = (int) value.length();
    for (int i = 0; i < sizeValue; ++i)
    {
        if (convertNumb(value[i]) >= base)
        {
            answer = false;
            break;
        }
    }
    return answer;
}

string getAnswer(char sign, int base, string firstNumb, string secondNumb)  //функция, где происходит весь счет.
{
    string answer = "";
    turnString(firstNumb, 0, (int)firstNumb.length() - 1);  //Переворачиваем строку, для простого счета
    turnString(secondNumb, 0, (int)secondNumb.length() - 1);
    if (changeNumbMax(firstNumb, secondNumb, sign))         // Действия относительно знака
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
     answer = "Error, wrong numbers, the second number is greater than the second number!";  //Если
    }
    return answer;
}

string additionNumber(string firstNumber, string secondNumber, int base) //Сложение
{
    string answer = "";
    int ost = 0;
    answer = helpAdd(firstNumber, secondNumber, 1, base, ost, 0, (int)secondNumber.length() - 1); //Скалдываем и вычисляем
    if (firstNumber.length() != secondNumber.length())                                            // остаток и склеиваем строку
    {
        answer += helpAdd(firstNumber, secondNumber, 0, base, ost, (int)secondNumber.length(),(int)firstNumber.length() - 1);
    }                                                                                             // Если первое чилсо длиннее, то мы добавляем остальные цифры
    if (ost != 0)
    {
        answer += getNumberOrLetter(ost);
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

bool changeNumbMax(string &firstNumb, string &secondNumb, char sign)   //Ищет максимальное число и (записывает его в firstNumb)
{
    if (comparisonNumb(firstNumb, secondNumb) + 1)                  // проверяем какое число больше, если первое, то ничего не делаем
    {
        return true;
    }else
    {
        if ( (sign == '-') || (sign == '/'))                                    // Если второе, то смотрим на знак,
        {
            return false;
        }else                                                   // Если знак не удовлетворяет условию, то меняем строки.
        {
            changeStr(firstNumb, secondNumb);
            return true;
        }
    }
}

int comparisonNumb(string firstNumb, string secondNumb)       // Функция сравнивает две строки, 1 - первая больше, 0 - равны, -1 - вторая больше
{
    int firstGreaterSecond = 1;                            // Иницилизируем, что первая строка больше
    if (firstNumb.length() < secondNumb.length())
    {
        firstGreaterSecond = -1;                          //Eсли первое число меньше второго мы выводим false
    }else
    {
        if ((firstNumb.length() == secondNumb.length()))
        {
            firstGreaterSecond = equalMax(firstNumb,secondNumb);
        }                                                           //Сравниваем строку одинаковой длины
    }
    return firstGreaterSecond;
}

void changeStr(string &firstStr, string &secondStr) // меняет местами строки
{
    string helpStr = firstStr;
    firstStr = secondStr;
    secondStr = helpStr;
}
    
int equalMax(string firstNumb, string secondNumb)  // сравнивает две строки одинаковой длины
{
    int greaterNumber = 0;                                       // максим второе число
    for(int i = 0; i < (int) firstNumb.length(); i++)
    {
        if((convertNumb(firstNumb[i])) != (convertNumb(secondNumb[i])))  // переводим из чар в инт и сравниваем значение
        {
            if ((convertNumb(firstNumb[i])) < (convertNumb(secondNumb[i])))
            {
                greaterNumber = -1;
                break;
            }else
            {
                greaterNumber = 1;
                break;
            }
        }
    }
    return greaterNumber;

}

int convertNumb(char numb)  //Конвертирует символ в число
{
    int intNumb = numb - '0';                   //Перевод из чар в инт
    if ((intNumb) > 9)                          //Если эта буква, то мы должны отнять 7 у заглавных и 39 у строчных
    {
        intNumb > 40 ? (intNumb -= 39) : (intNumb -= 7);
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
        answer = static_cast<char>(number + '0' + 7);      // перевод из инта в чар(ост), если больше 9, то прибавляем 7, чтобы
    }else                                                  // получить букву, иначе прибавляем только '0'
    {
        answer = static_cast<char>(number + '0');
    }
    return answer;
}

string divisionNumber(string firstNumb, string seconNumb, int base)         // Деление
{
    string answer = "";
    while(comparisonNumb(firstNumb, seconNumb) + 1 )                             // выполняем цикл, пока первое число больше второго
    {
        turnString(firstNumb, 0, (int)firstNumb.length() - 1);
        turnString(seconNumb, 0, (int)seconNumb.length() - 1);
        string divident = firstNumb.substr(0, seconNumb.length());          // составляем число, которое будем делить (длина равна длине 2), из первого
        if (comparisonNumb(seconNumb,divident))                           // если при равной длине делимое меньше, то добавляем еще одну цифру из первого
        {
            divident += firstNumb[seconNumb.length()];
        }
        string subtrahend = "";
        int helpNumb = findFactorForDivider(base, divident, seconNumb);
        subtrahend += getNumberOrLetter(helpNumb);                                                  // с помощью фунции findFactor ищем множитель, и
        answer += subtrahend;
        turnString(seconNumb, 0, (int) seconNumb.length() - 1);
        subtrahend = multiplicationNumber(seconNumb, subtrahend, base);         // перемножаем множитель и второе число
        turnString(subtrahend, 0, (int) subtrahend.length() - 1);
        for (int i = 0; i < firstNumb.length() - 2; i++)
        {
            subtrahend = multiplicationNumber(subtrahend, "01", base);
            turnString(subtrahend, 0, (int) subtrahend.length() - 1);
        }
        turnString(firstNumb, 0, (int) firstNumb.length() - 1);
        firstNumb = subtractionNumber(firstNumb, subtrahend, base);                             // отнимаем от первого числа произведение
    }
    return answer;
}

int findFactorForDivider(int base, string divident, string divider)                             // Дихотомия, которая ищет множитель
{
    int left = 0;
    int right = base;
    if (equalMax(divident, divider) == 0)
    {
        right = 1;
    }else
    {
        turnString(divider, 0, (int)divider.length() - 1);
        while (left <= right)
        {
            int middle = (left + right) / 2;
            string factor = "";
            factor += getNumberOrLetter(middle);
            string composition = multiplicationNumber(divider, factor, base);
            if (comparisonNumb(divident, composition) + 1)
            {
                left = middle + 1;
            }else
            {
                right = middle - 1;
            }
        }
    }
    return right;
}











