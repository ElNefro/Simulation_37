#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>

//-----------------------------------------------------------------------
//Учетные записи
int userCount = 2;
std::string* LoginArr = new std::string[userCount]{"admin", "user"};
std::string* PasswordArr = new std::string[userCount]{ "admin", "user" };
//-----------------------------------------------------------------------



bool isAdmin = false;



//-----------------------------------------------------------------------
//Функции
void Start();
bool Login();
void ShopMenu();


#if definded(max)
#undef max
#endif

int main()
{
    Start();
    delete[]LoginArr;
    delete[]PasswordArr;
    return 0;
}

void Start()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "\n\n\t\t\tСимуляция 37\t\t\t\n\n";
    Login();
    if (Login() == true)
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        ShopMenu();
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

        std::cout << "\n";

        for (int i = 0; i < userCount; i++)
        {
            if (login == LoginArr[0] && pass == PasswordArr[0])
            {
                std::cout << "Добро пожаловать " << LoginArr[0] << "\n";
                isAdmin = false;
                return true;
            }
            else if (login == LoginArr[i] && pass == PasswordArr[i])
            {
                std::cout << "Добро пожаловать " << LoginArr[i] << "\n";
                isAdmin = false;
                return true;
            }
        }
        system("cls");
        std::cout << "Неверно введен логин или пароль!\n\n";
    }
    
}
