#include <iostream>
#include <fstream>
#include <string>

bool file_Output(static std::string a, int b, int c)
{
	std::ofstream fout;
	if (a == "number.txt")
	{
		fout.open("number.txt", std::ofstream::app);

		if (!fout.is_open())
		{
			return false;
		}
		else
		{
			fout << b << '\n' << c << '\n';
			fout.close();
			return true;
		}
	}
}

int NOD(int a, int b)
{
	while (a != b)
	{
		if (a == b)
		{
			return a;
		}
		else if (a > b)
		{
			a -= b;
		}
		else
		{
			b -= a;
		}
	}
}

bool file_Input(int a, int b)
{
	std::ofstream result("result.txt", std::ofstream::app);
	std::ifstream fin;

	fin.open("number.txt", std::ios_base::in);
	
	if (!fin.is_open())
	{
		return false;
	}
	else 
	{
		if (NOD(a, b) == a)
		{
			result << "НОД чисел " << a << " и " << b << " равен: " << a;
			return true;
		}
	}
}

int main()
{
    setlocale(LC_ALL, "ru");
	int num1;
	int num2;
	int count = 0;
	std::string fileName;

	std::cout << "Введите название файла: " << '\n';
	std::cin >> fileName;

	if (fileName != "number.txt")
	{
		std::cout << "Ошибка открытия файла";
	}
	std::cout << "Введите 2 положительных числа: ";
	std::cin >> num1;
	std::cin >> num2;
	
	file_Output(fileName, num1, num2);
	file_Input(num1, num2);
	return 0;
	
		
}

