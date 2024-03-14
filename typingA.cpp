#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    //Используем неявную типизацию данных для определения словаря
    map<string, vector<int>> eventsDictionary;

    //Добавляем элементы в словарь
    eventsDictionary["internal event"] = {1, 2, 3}; //внутреннее мероприятие 
    eventsDictionary["external event"] = {4, 5, 6, 7}; //внешнее мероприятие 

    int  keyToSearch = 0;
    cin>>keyToSearch;
    while  (keyToSearch!=0)
    { 
        if(keyToSearch == 0)
        {
            break;
        }
        if (keyToSearch == 1 || keyToSearch == 2 || keyToSearch == 3)
        {
            cout<<"internal event"<<endl;
        }
        else 
        if(keyToSearch == 4 || keyToSearch == 5 || keyToSearch == 6 || keyToSearch == 7)
        {
            cout<<"external  event"<<endl;
        }
       
        else{
            cout<<"key not found"<<endl;
        }
        cin>>keyToSearch;
    }
    return 0;
}



    /*
    //Вывод содержимого словаря 
    cout<<"Dictionary content:\n";
    for(const auto& pair : eventsDictionary) {
        cout<<pair.first<<" : ";
        for(int value : pair.second) {
            cout<<value<<" ";
        }
        cout<<endl;
    } 
    return 0;
}*/




/*
В этом примере используется структура данных std::map, где ключами являются строки (std::string),
а значениями - списки чисел (std::vector<int>). 
При добавлении элементов в словарь мы используем неявную типизацию данных, 
поскольку типы ключей и значений определяются автоматически на основе используемых значений.
*/