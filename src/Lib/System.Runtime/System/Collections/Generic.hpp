#include "../../System.hpp"
#include "IEnumerable.hpp"
#include <vector>

namespace System::Collections::Generic
{
	template <class T, class ...Args> T CreateObject(Args... args)
	{
		return new T(args...);
	}

	template <class T> class DLLATTR List : virtual public IEnumerable<T>
	{
		std::vector<T> inner;

		public:
			List()
			{
				
				inner = std::vector<T>();
			}

			List(Int32 capacity)
			{
				
				inner = std::vector<T>(capacity.ToNative());
			}

			void Add(T elem)
			{
				inner.emplace_back(elem);
			}
			
			// List.Capacity is actually a prop (same for Count)
			Int32 get_Capacity() // getter
			{
				return Int32(inner.capacity());
			}

			void set_Capacity(Int32 value) // setter
			{
				inner.capacity(value.ToNative());
			}

			Int32 get_Count()
			{
				return Int32(inner.size());
			}

			T& operator[](Int32 idx) // may need proxy to try index properly
			{
				return inner[idx.ToNative()];
			}

	};
}

namespace System
{
	template <typename T> class DLLATTR Array
	{
		T* inner;
		int length;

		public:
			Array() : Array(new T[0], 0)
			{
			
			}

			Array(T elems[], size_t size)
			{
				inner = elems;
				length = size;
			}

			T& operator[](Int32 index)
			{
				return inner[index.ToNative()];
			}

			System::Collections::Generic::IEnumerator<T>* GetEnumerator()
			{
				return new ArrayEnumerator(this);
			}

			int get_Length()
			{
				return length;
			}

			~Array()
			{
				delete[] inner;
			}

		private:
			class ArrayEnumerator : public System::Collections::Generic::IEnumerator<T>
			{
				Array<T>* items;
				Int32 idx = Int32(0);

				public:
					ArrayEnumerator(Array<T>* items)
					{
						
						this->items = items;
					}

					// current is a prop
					T Current()
					{
						return items->operator[](idx);
					}

					void Dispose()
					{
						delete this;
						return;
					}

					Boolean MoveNext()
					{
						idx+=Int32(1);

						if (idx < items->length) return Boolean(true);
						
						idx-=Int32(1);

						return Boolean(false);
					}

					void Reset()
					{
						idx = Int32(-1);
					}
			};
		};


	extern template class Array<Object*>;
}