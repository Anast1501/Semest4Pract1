#include <iostream>
#include <string>

using namespace std;

// Базовый интерфейс для всех мероприятий
class Event {
public:
    virtual ~Event() {}

    virtual void securityCheck() const = 0;
    virtual void perform() const = 0;
};

// Внутреннее мероприятие
class InternalEvent : public Event {
private:
    string name;
public:
    InternalEvent(const string& name) : name(name) {}

    void securityCheck() const override {
        cout << "Performing security check for internal event: " << name << endl;
        // Логика проверки безопасности для внутреннего мероприятия
    }

    void perform() const override {
        cout << "Performing internal event: " << name << endl;
        // Логика выполнения внутреннего мероприятия
    }

};

// Внешнее мероприятие
class ExternalEvent : public Event {
    private:
    string name;
public:
    ExternalEvent(const string& name) : name(name) {}

    void securityCheck() const override {
        cout << "Performing security check for external event: " << name << endl;
        // Логика проверки безопасности для внешнего мероприятия
    }

    void perform() const override {
        cout << "Performing external event: " << name << endl;
        // Логика выполнения внешнего мероприятия
    }


};

// Функция для выполнения мероприятия с проверкой безопасности
void executeEvent(const Event& event) {
    event.securityCheck();
    event.perform();
}

int main() {
    // Создание объектов различных классов и вызов общей функции для их выполнения
   // InternalEvent internalEvent("Внутреннее мероприятие 1");
    InternalEvent internalEvent("internal events 1");
    //ExternalEvent externalEvent("Внешнее мероприятие 1");
    ExternalEvent externalEvent("external events 1");

    executeEvent(internalEvent);
    executeEvent(externalEvent);

    return 0;
}
