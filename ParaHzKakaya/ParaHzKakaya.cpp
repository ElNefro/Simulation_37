#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>

#if defined(max)
#undef max
#endif 

// Учетные записи
bool isAdmin = false;
int userCount = 2;
std::string* loginArr = new std::string[userCount]{ "admin", "user" };
std::string* passwordArr = new std::string[userCount]{ "admin", "user" };
//-----------------------------

int size = 10;
int* idArr = new int[size];
int* countArr = new int[size];
double* priceArr = new double[size];
std::string* nameArr = new std::string[size];



//-----------------------------
// Функции
void Start();
bool Login();
void ShopUserMenu();
void ShopAdminMenu();
void CreateStaticStorage();
void ReffilStorage();
void WriteOffFromStorage();
void ChahgePrice();
void ChangeStaff();
void AddEmployee();
void AddProduct();
void ChangeProductName();
void DeleteProduct();

bool IsNumber(std::string string);

template<typename ArrType>
void SetArr(ArrType staticArr, ArrType dynamicArr, int size);

template<typename ArrType>
void printArr(ArrType dynamicArr, int size);

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

void Start()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	CreateStaticStorage();

	std::cout << "\n\n\t\t\tСИМУЛЯЦИЯ №37\n\n\n";
	if (Login() == true)
	{
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max());

		if (isAdmin == true)
		{

			std::string choose{};

			do
			{
				std::cout << "Использовать готовый склад или создать новый?\n";
				std::cout << "1 - Готовый склад\n2 - Создать новый \n\nВвод: ";
				std::getline(std::cin, choose, '\n');

			} while (choose.size() > 1 || choose[0] < 49 || choose[0] > 50);

			if (choose == "1")
			{
				CreateStaticStorage();
			}
			else
			{
				// создание динамического склада
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

void PrintStorage()
{
	std::cout << "id | \tНазвание\t\t\t\t  |\tЦена\t|\tКол-во           |\n";
	std::cout << "___|______________________________________________|_____________|________________________|\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << idArr[i] << "  | \t" << nameArr[i] << " | \t" << priceArr[i] << "\t|\t" << countArr[i] << "               |\n";
		std::cout << "___|______________________________________________|_____________|________________________|\n";
	}
	std::cout << "\n";
	std::cout << "\n";

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

		for (int i = 0; i < userCount; i++)
		{

			if (login == loginArr[0] && pass == passwordArr[0])
			{

				std::cout << "Добро пожаловать " << loginArr[0] << '\n';
				isAdmin = true;
				return true;

			}

			else if (login == loginArr[i] && pass == passwordArr[i])
			{

				std::cout << "Добро пожаловать " << loginArr[i] << '\n';
				isAdmin = false;
				return true;

			}

		}

		system("cls");
		std::cout << "ERR!!!!!!!!\n\n";

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

			// добавление скидок

		} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 56); // 48-56 

		if (choose == "1")
		{

		}
		else if (choose == "2")
		{
			PrintStorage();
		}
		else if (choose == "3")
		{
			ReffilStorage();
		}
		else if (choose == "4")
		{

		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cerr << "ERR!!!!!!\n";
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
			std::cout << "\n1. Начать продажу\n";
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

			// добавление скидок
		} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 56); // 48-56 

		if (choose == "1")
		{

		}
		else if (choose == "2")
		{
			PrintStorage();
		}
		else if (choose == "3")
		{
			ReffilStorage();
		}
		else if (choose == "4")
		{
			WriteOffFromStorage();
		}
		else if (choose == "5")
		{
			ChahgePrice();
		}
		else if (choose == "6")
		{

		}
		else if (choose == "7")
		{
			ChangeStaff();
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
			std::cerr << "ошибОЧКА";
		}
	}

}

void CreateStaticStorage()
{
	const int staticSize = 10;
	int idStaticArr[staticSize]{ 1,2,3,4,5,6,7,8,9,10 };
	std::string nameStaticArr[staticSize]
	{
		"Первокурсник                             ",
		"Графический дизайнер                     ",
		"Длииииинный кот                          ",
		"Не длииииинная собака                    ",
		"Неведомая хрень                          ",
		"Крыса                                    ",
		"Голубь Виталий                           ",
		"Андрей Бижов                             ",
		"Яблоко                                   ",
		"Большая кнопка Enter                     "
	};
	int countStaticArr[staticSize]{ 14,16,10,9,20,19,11,18,15,19 };
	double priceStaticArr[staticSize]{ 1227.0, 1200.0, 1400.0, 1300.0, 900.0, 1250.0, 1350.0, 1400.0, 1200.0, 1400.0 };

	SetArr(idStaticArr, idArr, staticSize);
	SetArr(nameStaticArr, nameArr, staticSize);
	SetArr(countStaticArr, countArr, staticSize);
	SetArr(priceStaticArr, priceArr, staticSize);

}
void ReffilStorage()
{
	std::string idStr;

	do
	{
		std::cout << "Пополнение склада\nВведите id товара:";
		std::getline(std::cin, idStr, '\n');

		if (idStr.size() == 2 && std::stoi(idStr) <= size && std::stoi(idStr) > 0)
		{
			break;
		}



	} while (idStr.size() > 1 || std::stoi(idStr) < 1 || std::stoi(idStr) > size);


	int id = std::stoi(idStr);

	std::cout << idArr[id - 1] << "\t" << nameArr[id - 1] << "\n";
	int add{};
	do
	{
		std::cout << "Введите кол-во товара для пополнения:";
		std::cin >> add;
	} while (add < 0 || add > MAXINT - countArr[id - 1]);

	countArr[id - 1] += add;
	std::cout << "Товар" << nameArr[id - 1] << "Успешно пополнен\n\n";
	system("pause");
	std::cin.ignore(std::numeric_limits<std::streamsize>::max());
}

void WriteOffFromStorage()
{
	std::string idStr;

	do
	{
		std::cout << "Списание со склада\nВведите id товара:";
		std::getline(std::cin, idStr, '\n');

		if (idStr.size() == 2 && std::stoi(idStr) <= size && std::stoi(idStr) > 0)
		{
			break;
		}



	} while (idStr.size() > 1 || std::stoi(idStr) < 1 || std::stoi(idStr) > size);


	int id = std::stoi(idStr);

	std::cout << idArr[id - 1] << "\t" << nameArr[id - 1] << "\n";
	int del{};
	do
	{
		std::cout << "Введите кол-во товара для списания:";
		std::cin >> del;
	} while (del < 0 || del > MAXINT - countArr[id - 1]);

	countArr[id - 1] -= del;
	std::cout << "Товар" << nameArr[id - 1] << "Успешно списан\n\n";
	system("pause");
	std::cin.ignore(std::numeric_limits<std::streamsize>::max());
}

void ChahgePrice()
{
	std::string idStr;

	do
	{
		std::cout << "Изменение цены\nВведите id товара:";
		std::getline(std::cin, idStr, '\n');

		if (idStr.size() == 2 && std::stoi(idStr) <= size && std::stoi(idStr) > 0)
		{
			break;
		}



	} while (idStr.size() > 1 || std::stoi(idStr) < 1 || std::stoi(idStr) > size);


	int id = std::stoi(idStr);

	std::cout << idArr[id - 1] << "\t" << nameArr[id - 1] << "Текущая цена" << priceArr[id - 1] << "\n\n";
	double newPrice{};
	do
	{
		std::cout << "Введите новую цену:";
		std::cin >> newPrice;
	} while (newPrice < 0 || newPrice > MAXINT);

	priceArr[id - 1] = newPrice;
	std::cout << "Товар" << nameArr[id - 1] << "Принял новую цену\n\n";
	system("pause");
	std::cin.ignore(std::numeric_limits<std::streamsize>::max());
}

void ChangeStaff()
{
	std::string choose;
	std::cout << "Изменение персонала магазина\n\n";
	do
	{
		std::cout << "1 - Добаавить нового сотрудника\n2 - Изменить логин и пароль\n3 - Удалить старого сотрудника\n\nВвод:";
		std::getline(std::cin, choose, '\n');
	} while (choose.size() > 1 || choose[0] < 49 || choose[0] > 50);

	if (choose == "1")
	{
		AddEmployee();
	}
	else if (choose == "2")
	{

	}
	else if (choose == "3")
	{

	}
	else if (choose == "0")
	{

	}
	else
	{
		std::cerr << "\nChangeStaffError\n\n";
	}

}

void AddEmployee()
{
	std::string* tempLogin = new std::string[userCount];
	std::string* tempPassword = new std::string[userCount];
	for (int i = 0; i < userCount; i++)
	{
		tempLogin[i] = loginArr[i];
		tempPassword[i] = passwordArr[i];
	}

	delete[]loginArr;
	delete[]passwordArr;
	userCount++;
	std::string* loginArr = new std::string[userCount];
	std::string* passwordArr = new std::string[userCount];
	for (int i = 0; i < userCount - 1; i++)
	{
		loginArr[i] = tempLogin[i];
		passwordArr[i] = tempPassword[i];

	}

	std::string newLogin, newPass;
	std::cout << "Введите логин нового сотрудника:";
	std::getline(std::cin, newLogin, '\n');
	std::cout << "Введите пароль нового сотрудника:";
	std::getline(std::cin, newLogin, '\n');

	loginArr[userCount - 1] = newLogin;
	passwordArr[userCount - 1] = newPass;
	delete[]tempLogin;
	delete[]tempPassword;
	//test
	for (int i = 0; i < userCount; i++)
	{
		std::cout << loginArr[i] << " " << passwordArr[i] << "\n";
	}
}




void AddProduct()
{
	std::string choose;

	while (true)
	{
		std::cout
			<< "1) Добавить новый товар\n\n"
			<< "0) Выход\n\n\n ?> ";
		std::getline(std::cin, choose, '\n');

		if (choose == "0")
		{
			break;
		}
		else if (choose == "1")
		{
			int* tempId = new int[size];
			int* tempCount = new int[size];
			double* tempPrice = new double[size];
			std::string* tempName = new std::string[size];

			for (int i = 0; i < size; i++)
			{
				tempId[i] = idArr[i];
				tempCount[i] = countArr[i];
				tempPrice[i] = priceArr[i];
				tempName[i] = nameArr[i];
			}

			delete[]idArr;
			delete[]countArr;
			delete[]priceArr;
			delete[]nameArr;

			size++;

			idArr = new int[size];
			countArr = new int[size];
			priceArr = new double[size];
			nameArr = new std::string[size];

			for (int i = 0; i < size - 1; i++)
			{
				idArr[i] = tempId[i];
				countArr[i] = tempCount[i];
				priceArr[i] = tempPrice[i];
				nameArr[i] = tempName[i];
			}

			std::string newCountStr, newPriceStr, newName;
			idArr[size - 1] = idArr[size - 2] + 1;

			while (true)
			{
				std::cout << "Введите имя нового товара: ";
				std::getline(std::cin, newName, '\n');

				if (newName.size() <= 30)
				{
					nameArr[size - 1] = newName;
					break;
				}
				else
				{
					std::cout << "Максимальная длинна названия 30 символов.";
				}
			}

			while (true)
			{
				std::cout << "Введите количество нового товара: ";
				std::getline(std::cin, newCountStr, '\n');

				if (IsNumber(newCountStr))
				{
					if (std::stoi(newCountStr) >= 0 && std::stoi(newCountStr) < 1000)
					{
						countArr[size - 1] = std::stoi(newCountStr);
						break;
					}
				}
				else
				{
					std::cout << "Некоректный ввод.";
				}
			}

			while (true)
			{
				std::cout << "Введите цену нового товара: ";
				std::getline(std::cin, newPriceStr, '\n');
				if (IsNumber(newPriceStr))
				{
					if (std::stod(newPriceStr) >= 0 && std::stod(newPriceStr) < 10000000)
					{
						priceArr[size - 1] = std::stod(newPriceStr);
						break;
					}
					else
					{
						std::cout << "Некоректная цена.";
					}
				}
				else
				{
					std::cout << "Некоректный ввод.";
				}
			}


			delete[]tempId;
			delete[]tempCount;
			delete[]tempPrice;
			delete[]tempName;
			break;
		}
		else
		{
			std::cout << "Некоректный ввод.";
		}
	}
}

void ChangeProductName()
{
	std::string choose;

	while (true)
	{
		std::cout
			<< "1) Изменить имя товара\n\n"
			<< "0) Выход\n\n\n ?> ";
		std::getline(std::cin, choose, '\n');
		if (choose == "0")
		{
			break;
		}
		else if (choose == "1")
		{
			std::string idStr, newName;
			int id{};

			while (true)
			{
				std::cout << "Введите ID товара: ";
				std::getline(std::cin, idStr, '\n');
				if (IsNumber(idStr))
				{
					id = std::stoi(idStr);
					if (id > 0 && id <= size)
					{
						break;
					}
					else
					{
						std::cout << "\n\nНекоректный ID\n\n";
					}
				}
				else
				{
					std::cout << "\n\nНекоректный ввод\n\n";
				}
			}
			while (true)
			{
				std::cout << "Введите имя товара: ";
				std::getline(std::cin, newName, '\n');
				if (newName.size() <= 30)
				{
					nameArr[id - 1] = newName;
					break;
				}
				else
				{
					std::cout << "\n\nМаксимальная длинна названия 30 символов\n\n";
				}
			}
		}
		else
		{
			std::cout << "\n\nНекоректный ввод\n\n";
		}

	}
}

void DeleteProduct()
{
	std::string choose;

	while (true)
	{
		std::cout
			<< "1) Удалить товар\n\n"
			<< "0) Выход\n\n\n ?> ";
		std::getline(std::cin, choose, '\n');
		if (choose == "0")
		{
			break;
		}
		else if (choose == "1")
		{


			std::string idStr;
			int id{};

			while (true)
			{
				std::cout << "Введите ID товара для удаления: ";
				std::getline(std::cin, idStr, '\n');
				if (IsNumber(idStr))
				{
					id = std::stoi(idStr);
					if (id > 0 && id <= size)
					{
						break;
					}
					else
					{
						std::cout << "\n\nНекоректный ID\n\n";
					}
				}
				else
				{
					std::cout << "\n\nНекоректный ввод\n\n";
				}
			}

			int* tempId = new int[size];
			int* tempCount = new int[size];
			double* tempPrice = new double[size];
			std::string* tempName = new std::string[size];

			for (int i = 0; i < size; i++)
			{
				tempId[i] = idArr[i];
				tempCount[i] = countArr[i];
				tempPrice[i] = priceArr[i];
				tempName[i] = nameArr[i];
			}

			delete[]idArr;
			delete[]countArr;
			delete[]priceArr;
			delete[]nameArr;

			size--;

			tempId = new int[size];
			tempCount = new int[size];
			tempPrice = new double[size];
			tempName = new std::string[size];

			for (int i = 0, j = 0; i < size, j < size; i++, j++)
			{
				if (i == id - 1)
				{
					i++;
					countArr[j] = tempCount[i];
					priceArr[j] = tempPrice[i];
					nameArr[j] = tempName[i];
					idArr[j] = tempId[j];
				}
				else
				{
					countArr[j] = tempCount[i];
					priceArr[j] = tempPrice[i];
					nameArr[j] = tempName[i];
					idArr[j] = tempId[j];
				}
			}

			std::cout << "\n\nТовар успешно удалён\n\n";

			delete[]tempId;
			delete[]tempCount;
			delete[]tempPrice;
			delete[]tempName;
		}
		else
		{
			std::cout << "Некоректный ввод.";
		}
	}
}




bool IsNumber(std::string string)//проверка на число ли в строке
{
	for (int i = 0; i < string.size(); i++)
	{
		if (!std::isdigit(string[i]))
		{
			return false;
		}
	}
	return true;
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