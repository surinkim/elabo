// elaboExample.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <string>
#include <iostream>
#include <assert.h>
#include <memory>

#include <elabo\Console.h>
#include <elabo\Singleton.h>
#include <elabo\Factory.h>
#include <elabo\String.h>
#include <elabo\Network.h>

using namespace elabo::console;
using namespace elabo::pattern;
using namespace elabo::string;
using namespace elabo::network;

class Foo : public Singleton<Foo>
{
private:
	friend class Singleton<Foo>;
	Foo() = default;
	~Foo() = default;

public:
	void Call() { std::cout << "Call in Foo. this = " << this << std::endl; }

};

class Human
{
public:
    explicit Human(std::string name) : _name(name) {}
    virtual ~Human() {};

    virtual void Call() {};

protected:
    std::string _name;
};

class Student : public Human
{
public:
    explicit Student(std::string name) : Human( name ) {}
    ~Student() 
    {
        std::cout << "Student Destructor." << std::endl;
    }

    void Call() override { std::cout << "I'm a student. My name is " << _name.c_str() << "." << std::endl; }
};

std::unique_ptr<Student> CreateStudent(std::string name)
{
    return std::make_unique<Student>(name);
}

class Professor : public Human
{
public:
    explicit Professor( std::string name ) : Human( name ) {}
    ~Professor()
    {
        std::cout << "Professor Destructor." << std::endl;
    }

    void Call() override { std::cout << "I'm a professor. My name is " << _name.c_str() << "." << std::endl; }
};

std::unique_ptr<Professor> CreateProfessor(std::string name)
{
    return std::make_unique<Professor>(name);
}

using FactoryType = elabo::pattern::Factory<Human, int>;

int main()
{

//pattern example/////////////////////////////////////////////////////////////

	//Singleton
	Foo& foo = Foo::GetInstance();
	Foo* pFoo = &Foo::GetInstance();
	assert( &foo == pFoo );

	foo.Call();
	pFoo->Call();

	//Should not be compiled;
	//Foo foo;
	//Foo* foo = new Foo;
	//Foo otherFoo(foo);
	//foo = *pFoo;

	std::cout << std::endl;

    //Factory
    FactoryType factory;
    factory.Add(1, std::bind(CreateStudent, std::placeholders::_1));
    auto human = factory.Create(1, "Robert");
    human.get()->Call();

    factory.Add(2, (std::unique_ptr<Human> (*)(std::string)) CreateProfessor);
    human = factory.Create(2, "Harry");
    human.get()->Call();

    std::cout << std::endl;

//string example///////////////////////////////////////////////////////////////
	const char* str = "This is an Multi byte string literal.\n";
	std::cout << str << std::endl;

	std::wstring wstring = ConvertToWString( str );
	wstring += L"However, convert to Wide char string.\n";
	std::wcout << wstring << std::endl;

	std::string string = ConvertToString( wstring.c_str() );
	string += "Finally, it has converted to Multi byte string.";
	std::cout << string << std::endl;

	std::cout << std::endl;

//network example///////////////////////////////////////////////////////////////
	std::vector<std::string> vecAddr;
	if ( GetLocalAddress( vecAddr ) == false )
	{
		std::cout << "GetLocalAddress has failed." << std::endl;
		return -1;
	}

	for ( auto addr : vecAddr )
	{
		std::cout << "Local Address : " << addr.c_str() << std::endl;
	}

	std::cout << std::endl;

//console example///////////////////////////////////////////////////////////////
	//Set Console Text Color
	ColoredPrintf( TextColor::YELLOW, "This is a Yellow Color Text.\n" );
	ColoredPrintf( TextColor::RED, "This is a Red Color Text.\n" );
	ColoredPrintf( TextColor::GREEN, "This is a Green Color Text.\n" );

	//Set Console Echo
	std::string text;
	std::cout << "Input text with console echo on." << std::endl << " >> ";
	std::cin >> text; //Console On;

	SetConsoleEcho( Turn::OFF );
	std::cout << "Input text with console echo off." << std::endl << " >> ";
	std::cin >> text; //Console Off;

	SetConsoleEcho( Turn::ON );
	std::cout << "Input text with console echo on." << std::endl << " >> ";
	std::cin >> text; //Console On;

	std::cout << std::endl;

	return 0;
}

