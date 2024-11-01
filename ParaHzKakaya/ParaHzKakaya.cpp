#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>

#if defined(max)
#undef max
#endif 

//_______________________________________________________________________________

// Учетные записи

bool isAdmin = false;
int userCount = 2;
std::string* loginArr = new std::string[userCount]{ "admin", "user" };
std::string* passwordArr = new std::string[userCount]{ "admin", "user" };

//_______________________________________________________________________________



int size = 10;
int* idArr = new int[size];
int* countArr = new int[size];
double* priceArr = new double[size];
std::string* nameArr = new std::string[size];



//_______________________________________________________________________________

// Функции

void Start();
bool Login();
void ShopUserMenu();
void ShopAdminMenu();
void CreateStaticStorage();
void ShowStorage();

template<typename ArrType>
void SetArr(ArrType staticArr, ArrType dynamicArr, int size);

template<typename ArrType>
void PrintArr(ArrType dynamicArr, int size);


//_______________________________________________________________________________

int main()
{


	Start();

	delete[]loginArr;
	delete[]passwordArr;
	delete[]idArr;
	delete[]countArr;
	delete[]priceArr;
	delete[]nameArr;

	return 0;
}

//_______________________________________________________________________________

void Start()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout << "\n\n\t\t\tСимуляция 37\n\n\n";
	if (Login() == true)
	{
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max());

		if (isAdmin == true)
		{
			std::string choose;

			do
			{
				std::cout << "Использовать готовый склад или создать новый?\n";
				std::cout << "1) Готовый\n2) Новый\n\nВвод: ";
				std::getline(std::cin, choose, '\n');

				system("cls");

			} while (choose.size() > 1 || choose[0] < 49 || choose[0] > 50); // 48-56 
			
			if (choose == "1")
			{
				CreateStaticStorage();
			}
			else
			{
				//Создание динам склада
			}

			ShopAdminMenu();
		}
		else
		{
			CreateStaticStorage();
			ShopUserMenu();
		}
	}

}

bool Login()
{
	while (true)
	{
		std::string login, pass;
		std::cout << "Введите логин: ";
		std::getline(std::cin, login, '\n');
		std::cout << "Введите пароль: ";
		std::getline(std::cin, pass, '\n');

		system("cls");

		for (int i = 0; i < userCount; i++)
		{
			if (login == loginArr[0] && pass == passwordArr[0])
			{
				std::cout << "Добро пожаловать " << loginArr[0] << '\n';
				std::cout << "\n";
				isAdmin = true;
				return true;
			}
			else if (login == loginArr[i] && pass == passwordArr[i])
			{
				std::cout << "Добро пожаловать " << loginArr[i] << '\n';
				std::cout << "\n";
				isAdmin = false;
				return true;
			}
		}
		system("cls");
		std::cout << "Неверно введен логин или пароль!\n\n";
	}

}

void ShopUserMenu()
{

	std::string choose{};

	while (true)
	{
		do
		{
			std::cout << "1. Начать продажу\n";
			std::cout << "2. Показать склад\n";
			std::cout << "3. Пополнить склад\n";
			std::cout << "4. Отчет о прибыли\n\n";
			std::cout << "0. Закрыть смену\n";

			std::cout << "Ввод: ";
			std::getline(std::cin, choose, '\n');
			system("cls");
			// добавление акции
		} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 56); // 48-56 

		if (choose == "1")
		{

		}
		else if (choose == "2")
		{
			ShowStorage();
		}
		else if (choose == "3")
		{

		}
		else if (choose == "4")
		{

		}
		else if (choose == "5")
		{

		}
		else if (choose == "6")
		{

		}
		else if (choose == "7")
		{

		}
		else if (choose == "8")
		{

		}
		else if (choose == "0")
		{

			break;
		}
		else
		{
			std::cerr << "Ошибка";
		}
	}
}

void ShopAdminMenu()
{
	std::string choose{};

	while (true)
	{
		do
		{
			std::cout << "1. Начать продажу\n";
			std::cout << "2. Показать склад\n";
			std::cout << "3. Пополнить склад\n";
			std::cout << "4. Списать со склада\n";
			std::cout << "5. Изменить цену\n";
			std::cout << "6. Изменить склад\n";
			std::cout << "7. изменить сотрудника\n";
			std::cout << "8. Отчет о прибыли\n\n";
			std::cout << "0. Закрыть смену\n";

			std::cout << "Ввод: ";
			std::getline(std::cin, choose, '\n');
			system("cls");
			// добавление акции
		} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 56); // 48-56 

		if (choose == "1")
		{

		}
		else if (choose == "2")
		{
			ShowStorage();
		}
		else if (choose == "3")
		{

		}
		else if (choose == "4")
		{

		}
		else if (choose == "5")
		{

		}
		else if (choose == "6")
		{

		}
		else if (choose == "7")
		{

		}
		else if (choose == "8")
		{

		}
		else if (choose == "0")
		{

			break;
		}
		else
		{
			std::cerr << "Ошибка";
		}
	}

}

void CreateStaticStorage()
{
	const int staticSize = 10;

	int idStaticArr[staticSize]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	std::string nameStaticArr[staticSize]
	{ 
		"Кружка обманка                           ",
		"Футболка противостояние 37 и 28          ",
		"Толстовка с мемами                       ",
		"Значки 37                                ",
		"Наклейка Маленький дагестанец            ",
		"Сумка хз какая, потом придумаю           ",
		"Кепка 'У меня все описано!               ",
		"Чехол для телефона 'Я Знаю, Что Ты Думал!",
		"Плюшевая игрушка 'Питонист               ",
		"Магнит 'Когда Ты Знал, Что Делаешь Чепуху" 
	};



	int countStaticArr[staticSize]{ 23, 37, 42, 29, 45, 31, 48, 25, 36, 41 };

	double priceStaticArr[staticSize]{450.0, 1000.0, 2500.0, 50.0, 25.0, 1750.0, 700.0, 500.0, 666.0, 100.0 };
	SetArr(idStaticArr, idArr, staticSize);
	SetArr(nameStaticArr, nameArr, staticSize);
	SetArr(countStaticArr, countArr, staticSize);
	SetArr(priceStaticArr, priceArr, staticSize);


}



template<typename ArrType>
void SetArr(ArrType staticArr, ArrType dynamicArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		dynamicArr[i] = staticArr[i];
	}
}

template<typename ArrType>
void PrintArr(ArrType dynamicArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << dynamicArr[i] << " ";
	}
	std::cout << "\n";
}


void ShowStorage()
{
	std::cout << "id | \tНазвание\t\t\t\t  |\tЦена\t|\tКол-во           |\n";
	std::cout << "___|______________________________________________|_____________|________________________|\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << idArr[i] << "  | \t" << nameArr[i] << " | \t" << priceArr[i] << "\t|\t" << countArr[i] << "               |\n";
		std::cout << "___|______________________________________________|_____________|________________________|\n";
	}
}