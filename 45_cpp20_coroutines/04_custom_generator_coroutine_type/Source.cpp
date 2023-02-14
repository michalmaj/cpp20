#include <iostream>
#include <coroutine>
#include <cassert>

template <typename T>
struct generator
{
	struct promise_type
	{
		T m_value;
		generator get_return_object() { return generator(this); }
		std::suspend_always initial_suspend() { return {}; }
		std::suspend_always final_suspend() noexcept { return {}; }

		void unhandled_exception() noexcept
		{
			std::rethrow_exception(std::current_exception());
		}

		std::suspend_always yield_value(T val)
		{
			m_value = val;
			return {};
		}

		void return_void()
		{
			std::cout << "Returning void..." << std::endl;
		}
	};

	generator(promise_type* p) : m_handle(std::coroutine_handle<promise_type>::from_promise(*p)){}
	~generator()
	{
		std::cout << "Handle destroyed..." << std::endl;
		m_handle.destroy();
	}

	T operator()()
	{
		assert(m_handle != nullptr);
		m_handle.resume();
		return (m_handle.promise().m_value);
	}

	std::coroutine_handle<promise_type> m_handle;
};

generator<int> generate_numbers()
{
	std::cout << "generate_numbers starting" << std::endl;

	co_yield 10; // return 10 and pauses
	std::cout << "After stop point #1" << std::endl;

	co_yield 20; // return 20 and pauses
	std::cout << "After stop point #2" << std::endl;

	co_yield 30; // return 30 and pauses
	std::cout << "After stop point #3" << std::endl;

	std::cout << "generate_numbers ending" << std::endl;
}

generator<int> infinite_number_stream(int start=0)
{
	auto value = start;
	for(int i{0};;++i)
	{
		//std::cout << "In infinite_number stream..." << std::endl;
		co_yield value;
		++value;
	}
}

generator<int> range(int first, int last)
{
	while (first < last)
	{
		co_yield first++;
	}
}


int main()
{
	auto task1 = generate_numbers();

	std::cout << "value: " << task1() << std::endl;
	std::cout << std::endl;

	std::cout << "value: " << task1() << std::endl;
	std::cout << std::endl;

	std::cout << "value: " << task1() << std::endl;
	std::cout << std::endl;

	std::cout << "value: " << task1() << std::endl;
	std::cout << std::endl;

	std::cout << std::boolalpha << "coro done: " << task1.m_handle.done() << std::endl;

	std::cout << "\n==========================================\n\n";

	auto task2 = infinite_number_stream();

	for(int i{0}; i < 100; ++i)
		std::cout << "value: " << task2() << std::endl;
	std::cout << std::endl;

	std::cout << "\n==========================================\n\n";

	// Range
	auto task3 = range(0, 25);

	while(true)
	{
		if(task3.m_handle.done())
			break;
		std::cout << task3() << std::endl;
	}


	std::cout << "Done!" << std::endl;

	return 0;
}