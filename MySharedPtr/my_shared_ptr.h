#ifndef MY_SHARED_PTR_H
#define MY_SHARED_PTR_H
#include <ostream>
namespace my
{
	template<class T>
	class Shared_ptr
	{
	private:
		T* m_ptr;
		int* m_counter;

	public:
		Shared_ptr()
		{
			m_ptr = new(T);
			m_counter = new int(1);

			std::cout << "Construct shared_ptr@" << this << std::endl;
		}

		Shared_ptr(T* t)
		{
			if (t != nullptr)
			{
				m_ptr = t;
				m_counter = new int(1);

				std::cout << "Construct shared_ptr@" << this << std::endl;
			}
		}

		Shared_ptr(Shared_ptr&& secondery_shared_prt) = delete;

		Shared_ptr(Shared_ptr& secondery_shared_prt) 
		{
			if (this->m_ptr != secondery_shared_prt.m_ptr)
			{
				this->m_ptr = secondery_shared_prt.m_ptr;
				++*secondery_shared_prt.m_counter;
				this->m_counter = secondery_shared_prt.m_counter;

				std::cout << "Copied shared_ptr from@" << &secondery_shared_prt << " to@" << this << std::endl;
			}
		}

		~Shared_ptr()
		{
			if (*m_counter == 1)
			{
				delete m_ptr;
				delete m_counter;
				m_ptr = nullptr;
				m_counter = nullptr;

				std::cout << "Destruct shared ptr@" << this << " and memory is safely cleared" << std::endl;
			}
			else
			{
				--(*m_counter);

				std::cout << "Shared@" << this << " destruct and counter has decreased and became = " << *m_counter << std::endl;
			}
		}

		//friend bool operator!= (const Shared_ptr& first_shared_prt, const Shared_ptr& secondery_shared_prt);
	};
	/*
	template<class T>
	bool operator!= (const Shared_ptr<T>& first_shared_prt, const Shared_ptr<T>& secondery_shared_prt)
	{
		return first_shared_prt.m_ptr != secondery_shared_prt.m_ptr;
	}
	*/
	
}

#endif // !MY_SHARED_PTR_H
