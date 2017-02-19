Introduction
====================

elabo is a c++ library.
This project is written in VS2010 and early stage yet.

How to use
====================

You can know how to use this library through elaboExample.
For example,

```c++
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

```


Tool
====================
 - Memory Leak Detection
 
 I strongly recommend the [deleaker](http://www.deleaker.com/) as a memory leak detection tool. 
 It tightly integrates with visual studio, and is very easy to use.
 
 (I am very impressed with their [free license policy for open source developer](https://isocpp.org/blog/2015/01/deleaker-for-free-for-opensource-project-owners). )
 
 - Documentation
 
 Doxygen
 
 - Unit Test
 
 google test

Author
====================

 - mail : nnhope@hotmail.com  
 - stackoverflow : http://stackoverflow.com/users/2231098/codedreamer


