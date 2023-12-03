#include "NativeLikeTypes/Object.hpp"
#include "NativeLikeTypes/NumTypes.hpp"
#include "NativeLikeTypes/String.hpp"

#pragma once

namespace System
{
	// TODO: change impl to use TextWriter Out;
	class DLLATTR Console // static class, so doesn't inherit from Object
	{
		// TODO:
			// [public] System::IO::TextWriter Out;
		public:
			static void Write(Object* obj);
			static void Write(String* string);

			static void WriteLine();
			static void WriteLine(Object* obj);
			static void WriteLine(String* string);
	};
}