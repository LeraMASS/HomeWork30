#include <iostream>
#include <string>
#include <fstream>

//Задача 1

int overwrite(const std::string& filee, std::string& text)
{
	std::ofstream file(filee);
	if (!file.is_open())
	{
		return false;
	}
	else
		file << text;

	file.close();

	return true;
}


int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	//Задача 1.
	std::cout << "Задача 1\n";
	std::ofstream out;
	out.open("text.txt", std::ios::app);

	if (out.is_open())
	{
		std::string input;
		do
		{
			std::cout << "Введиет строку -> ";
			std::getline(std::cin, input);
			out << input << '\n';
		} while (input != "end");
	}
	else
		std::cout << "Ошибка открытия файла\n";

	out.close();

	std::ifstream in;
	in.open("text.txt");

	if (in.is_open())
	{
		std::string str;
		while (std::getline(in, str))
		{
			std::cout << str << std::endl;
		}
	}
	else
		std::cout << "Ошибка открытия файла\n";

	in.close();

	//Задача 2.
	std::cout << "Задача 2.\n";
	out.open("text.txt", std::ios::app);

	std::string input2;
	std::cout << "Введиет строку для замены -> ";

	std::getline(std::cin, input2);

	if (overwrite("text.txt", input2))
	{
		std::cout << input2 << std::endl;
	}
	else
		std::cout << "Файла нет";

	remove("text.txt");


	return 0;
}