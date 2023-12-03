#define _CSNATIVE_IMPORT

#include "../Lib/System.Runtime/System.hpp"
#include "../Lib/System.Runtime/System/Collections/Generic.hpp"
#include <iostream>
#include <memory>
#include <chrono>

using namespace System;
using namespace std::chrono;

class __declspec(dllexport) Program
{
	public:
		static Int32 Main();
};

Int32 Program::Main()
{
	Int32 x = Int32(45);
	Int32 y = Int32(32);;
	Boolean truthy = x > y;\

	String* str1 = new String(L"Hello, World!", 13);
	String* str2 = new String(L"Value of y\0+x is: ", 18);
	String* str3 = new String(L"Value of boolean is: ", 21);

	std::shared_ptr<String> combined = std::make_shared<String>(L"constus");

	Console::WriteLine(str1);
	Console::Write(str2);
	Console::WriteLine(x+y);
	Console::Write(str3);
	Console::WriteLine(truthy);
	Console::WriteLine(new Object());


	return Int32(0);
}

extern "C" int RuntimeDLLRunner()
{
	return Program::Main().ToNative();
}