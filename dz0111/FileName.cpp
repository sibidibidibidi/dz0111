#include<iostream>
#include<string>
using namespace std;

class Pet
{
public:
    virtual void Sound() = 0;
    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }
private:
    string name;
};

class Dog : public Pet
{
public:
    Dog(string name)
    {
        Pet::setName(name);
    }
    void Sound() override
    {
        cout << "woof woof" << endl;
    }
};

class Cat : public Pet
{
public:
    Cat(string name)
    {
        Pet::setName(name);
    }
    void Sound() override
    {
        cout << "meow meow" << endl;
    }
};

class Parrot : public Pet
{
public:
    Parrot(string name)
    {
        Pet::setName(name);
    }
    void Sound() override
    {
        cout << "squeak" << endl;
    }
};

class Owner : public Pet
{
public:
    void petapet(Pet* pet)
    {
        pet->Sound();
    }
    void Sound() override
    {
        cout << "grumping" << endl;
    }
};

int main()
{
    string name;
    Dog dog("Loki");
    Cat cat("Bella");
    Owner owner;
    owner.petapet(&dog);
    name = dog.getName();
    cout << "name: " << name << endl;
    owner.petapet(&cat);
    name = cat.getName();
    cout << "name: " << name << endl;
}
