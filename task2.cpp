#include <iostream>
#include <fstream>

int num(int a)
{
	if (a < 10 && a >= 0)
	{
		return 1;
	}
	else if (a > 9 && a <= 99)
	{
		return 2;
	}
	else if (a > 99 && a <= 999)
	{
		return 3;
	}
	else
		return 0;
}

int main()
{
	setlocale(LC_ALL, "ru");

	std::ifstream fin;
	std::ofstream fout;
	std::ofstream result("result.txt");

	int number;
	int numberInTheFile;
	int counter = 0;
	int counter1 = 0;
	int counter2 = 0;

	do
	{
		std::cout << "Введите положительное число:";
		std::cin >> number;

		if (number != 0)
		{
			fout.open("number.txt", std::ofstream::app);

			if (!fout.is_open())
			{
				std::cout << "Ошибка открытия файла";
				return 1;
			}
			else
			{
				fout << number << '\n';
				fout.close();
			}

		}

	} while (number != 0);

	fin.open("number.txt", std::ios_base::in);

	if (!fin.is_open())
	{
		std::cout << "Ошибка открытия файла";
		return 1;
	}
	else
	{
		while (fin >> numberInTheFile)
		{
			
			if (num(numberInTheFile) == 1)
			{
				counter++;
			}
			else if (num(numberInTheFile) == 2)
			{
				counter1++;
			}
			else if (num(numberInTheFile) == 3)
			{
				counter2++;
			}
			else if (numberInTheFile > 999)
			{
				std::cout << "Число " << numberInTheFile << " больше 999" << '\n';
			}
			else
			{
				std::cout << "Число " << numberInTheFile << " отрицательное" << '\n';
			}
			


		}
		fin.close();
		if (number == 0)
		{
			result << "Количество однозначных чисел: " << counter << '\n' <<
				"Количество двухзначных чисел: " << counter1 << '\n' << 
				"Количество трехзначных чисел: " << counter2  << '\n';	
		}

	}
	return 0;
}
