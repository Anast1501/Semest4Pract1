#include <iostream>
#include <string>
using namespace std;
class SecurityEvent {
protected:
    string name;
    string location;
    string securityLevel;

public:
    SecurityEvent(const string& eventName, const string& eventLocation, const string& eventSecurityLevel)
        : name(eventName), location(eventLocation), securityLevel(eventSecurityLevel) {}

    virtual void displayDetails() {
        cout << "Security Event: " << name << ", Location: " << location << ", Security Level: " << securityLevel << endl;
    }
};

class InternalSecurityEvent : public SecurityEvent {
private:
    string department;

public:
    InternalSecurityEvent(const string& eventName, const string& eventLocation, const string& eventSecurityLevel, const string& eventDepartment)
        : SecurityEvent(eventName, eventLocation, eventSecurityLevel), department(eventDepartment) {}

    void displayDetails() override {
        cout << "Internal Security Event: " << name << ", Location: " << location << ", Security Level: " << securityLevel << ", Department: " << department << endl;
    }
};

class ExternalSecurityEvent : public SecurityEvent {
private:
    string organizer;

public:
    ExternalSecurityEvent(const string& eventName, const string& eventLocation, const string& eventSecurityLevel, const string& eventOrganizer)
        : SecurityEvent(eventName, eventLocation, eventSecurityLevel), organizer(eventOrganizer) {}

    void displayDetails() override {
        cout << "External Security Event: " << name << ", Location: " << location << ", Security Level: " << securityLevel << ", Organizer: " << organizer << endl;
    }
};

int main() {
    // Создание объектов различных типов событий и вызов методов
    SecurityEvent genericEvent("Generic Security Event", "Generic Location", "Low");
    InternalSecurityEvent internalEvent("Internal Security Meeting", "Office Room", "High", "Security Department");
    ExternalSecurityEvent externalEvent("Security Conference", "Convention Center", "Critical", "ABC Security Firm");

    genericEvent.displayDetails();
    internalEvent.displayDetails();
    externalEvent.displayDetails();

    return 0;
}








































/*#include <iostream>
#include <string>

using namespace std;

class SecurityEvent {
protected:
        string name;
        string location;
        string securityLevel;

public:
    SecurityEvent(const string& eventName, const string& eventLocation, const string& eventSecurityLevel)
        : name(eventName), location(eventLocation), securityLevel(eventSecurityLevel) {}

    virtual void displayDetalis() {
        cout<<"Security Event: " <<name<< ",  Location: " <<location<<", Security Level: " << securityLevel << endl;
    }
};

class InternalSecurityEvent : public SecurityEvent {
private:
    string department;

public:
    InternalSecurityEvent(const string& eventName, const string& eventLocation, const string& eventSecurutyLevel, const string& eventDepartment)
        : SecurityEvent(eventName, eventLocation, eventSecurityLevel), department(eventDepartment) {}

        void displayDetalis() override {
            cout<<"Internal Security Event:" << name << ", Location: "<<location<< " , Security Level: "<<securityLevel<<",Department: "<< department<<endl;
      }
};*/























/*
#include <iostream>
#include <string>

class SecurityEvent {
protected:
    string name;
    string location;
    string securityLevel;

public:
    SecurityEvent(const string& eventName, const string& eventLocation, const string& eventSecurityLevel)
        : name(eventName), location(eventLocation), securityLevel(eventSecurityLevel) {}

    virtual void displayDetails() {
        cout << "Security Event: " << name << ", Location: " << location << ", Security Level: " << securityLevel << endl;
    }
};

class InternalSecurityEvent : public SecurityEvent {
private:
    string department;

public:
    InternalSecurityEvent(const string& eventName, const string& eventLocation, const string& eventSecurityLevel, const string& eventDepartment)
        : SecurityEvent(eventName, eventLocation, eventSecurityLevel), department(eventDepartment) {}

    void displayDetails() override {
        cout << "Internal Security Event: " << name << ", Location: " << location << ", Security Level: " << securityLevel << ", Department: " << department << endl;
    }
};

class ExternalSecurityEvent : public SecurityEvent {
private:
    string organizer;

public:
    ExternalSecurityEvent(const string& eventName, const string& eventLocation, const string& eventSecurityLevel, const string& eventOrganizer)
        : SecurityEvent(eventName, eventLocation, eventSecurityLevel), organizer(eventOrganizer) {}

    void displayDetails() override {
        cout << "External Security Event: " << name << ", Location: " << location << ", Security Level: " << securityLevel << ", Organizer: " << organizer << endl;
    }
};

int main() {
    // Создание объектов различных типов событий и вызов методов
    SecurityEvent genericEvent("Generic Security Event", "Generic Location", "Low");
    InternalSecurityEvent internalEvent("Internal Security Meeting", "Office Room", "High", "Security Department");
    ExternalSecurityEvent externalEvent("Security Conference", "Convention Center", "Critical", "ABC Security Firm");

    genericEvent.displayDetails();
    internalEvent.displayDetails();
    externalEvent.displayDetails();

    return 0;
}
*/