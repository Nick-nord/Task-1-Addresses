// Задача 1. Адреса.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>

using namespace std;

class Address
{
	std::string City;
	std::string Street;
	int NumHouse;
	int NumFlat;
public:
	Address() // конструктор класса по умолчанию
	{
		this -> City = " ";
		this -> Street = " ";
		this -> NumHouse = 0;
		this -> NumFlat = 0;
	};
		
	Address(std::string City, std::string Street, int NumHouse, int NumFlat) // конструктор класса
	{
		this -> City = City;
		this -> Street = Street;
		this -> NumHouse = NumHouse;
		this -> NumFlat = NumFlat;
	};
	
	friend ostream& operator<<(ostream& stream, Address& arr);
  
};

ostream& operator << (ostream& stream, Address& arr)
{
	stream << arr.City << " ";
	stream << arr.Street << " ";
	stream << arr.NumHouse << " ";
	stream << arr.NumFlat;
	return stream;
}


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian"); //Корректное отображение Кириллицы
	system("chcp 1251");
	
	int Size; // определение и инициализация переменных
	std::string inCity;
	std::string inStreet;
	int inHouse{ 0 };
	int inFlat{ 0 };

	ifstream fin("in.txt"); // чтение данных из файла
	if (!fin)
	{
		std::cout << "File not open";
		return 1;
	}
	fin >> Size;

	Address *arr = new Address[Size]; // создание динамического массива 

	for (int i = 0; i < Size; i++)
	{
		fin >> inCity;
		fin >> inStreet;
		fin >> inHouse;
		fin >> inFlat;
        arr[i] = { inCity, inStreet, inHouse, inFlat };
	};
	fin.close();
	
	ofstream out("out.txt"); // запись данных в файл
	if (!out)
	{
		std::cout << "File not open";
		return 1;
	}
    out << Size << std::endl;
	for (int i = Size - 1; i >= 0; i--)
	{
		out << arr[i];
		out << std::endl;
	};

	delete []arr;
	return EXIT_SUCCESS;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

