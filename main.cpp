#include <iostream>
#include <windows.h>
#include <string>

int function(std::string str, int forbidden_length)
{
    int s = str.length();
    if (s == forbidden_length)
    {
        throw std::runtime_error("bad_length");
    }

    else
    {
        return s;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int size = 1;
    int forbidden_length = 1;
    std::cout << "Введите запретную длину: ";
    std::cin >> forbidden_length;

    do
    {
        std::string str;
        std::cout << "Введите слово: ";
        std::cin >> str;

        try
        {
            size = function(str, forbidden_length);
            std::cout << "Длина слова " << "\"" << str << "\" " << " равна " << size << std::endl;
        }

        catch (const std::exception& e)
        {
            size = str.length();
        }

    } while (size != forbidden_length);

    std::cout << "Вы ввели слово запретной длины! До свидания" << std::endl;
    return 0;
}