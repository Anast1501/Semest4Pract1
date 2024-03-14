//Создание шаблона класса "Счет": инкапсуляция позволяет скрыть детали
//реализации и предоставить публичные методы для взаимодействия с объектом
//"Счет", такие как пополнение, списание и получение баланса. 

#include <iostream>

using namespace std;

class Account {
private:
    float balance;

public:
//Конструктор
Account(float initialBalance) : balance(initialBalance){}

//Метод для пополнения счёта
void deposit(float amount) {
    balance += amount;
}

//Метод для списания со счёта 
void withdraw(float amount) {
    if (balance>=amount){
        balance -=amount;
    } else{
        cout<<"Not enough balance to withdraw"<<endl;
    }
    }
    //Метод для получения баланса
    float getBalance() const{
        return  balance;
    }
};

int main()
{
    //Создание объекта счёта с начальным балансом типа int
    Account intAccount(1000);
    cout<<"Initial balance: "<<intAccount.getBalance()<<endl;

    //Пополнение счёта на 500
    intAccount.deposit(500);
    cout<<"Balance after deposit: "<<intAccount.getBalance()<<endl;

    //Списание с счёта 700
    intAccount.withdraw(700);
    cout<<"Balance after withdrawal:  "<<intAccount.getBalance()<<endl;

    //Попытка списания больше, чем есть на счёте 
    intAccount.withdraw(1500);
    cout<<"Balance after attempted overdraw: "<<intAccount.getBalance()<<endl;

    return 0;
}


/*
Этот код определяет шаблон класса Account, который представляет собой счет с балансом типа T. 
Класс имеет приватное поле balance для хранения баланса и публичные методы deposit, withdraw и getBalance для управления счетом. 
В main() создается объект intAccount с начальным балансом 1000 (тип int), 
а затем демонстрируется использование методов для внесения депозита, списания и получения баланса.
*/