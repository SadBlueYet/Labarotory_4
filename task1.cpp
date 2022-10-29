#include <iostream>
#include <fstream>
#include <locale.h>


int number(int *a)
{
    int count = 1;
    for (int i = 1; i < *a; i++)
    {
        
        if (*a % i == 0)
        {
            
            count++;
        }
        
    }
    return count;
}

bool primeNumber(int *a)
{
    if (*a == 1 || *a == 3 || (*a * *a) % 24 == 1)
    {
        return true;
    }
    else return false;
    
    
}




int main()
{
    setlocale(LC_ALL, "ru");

    std::ifstream f_input;
    std::ofstream f_output;
    std::ofstream result("result.txt ");

    int count = 0;
    int numberInTheFile;
    int num;
    
    do
    {
        std::cout << "Введите целое число: ";
        std::cin >> num;

        if (num != 0)
        {
            f_output.open("R.txt", std::ofstream::app);

            if (!f_output.is_open())
            {
                std::cout << "Ошибка открытия файла";
                return 1;
            }
            else
            {
                f_output << num << '\n';
                f_output.close();
            }
        }
        else
        {
            std::cout << "Последовательность завершена!";
        }
       
    } while (num != 0);

    f_input.open("R.txt", std::ios_base::in);

    if (!f_input.is_open())
    {
        std::cout << "Ошибка открытия файла";
        return 1;
    }
    else
    {
        while (f_input >> numberInTheFile)
        {
            
            result << number(&numberInTheFile) << std::endl;
            if (primeNumber(&numberInTheFile) == true)
            {
                count++;
            }           
        }
       result << "Общие количество простых чисел в последовательности равно: " << count;
       f_input.close();
    }
    return 0;

}