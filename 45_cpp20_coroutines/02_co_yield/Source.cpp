#include <iostream>
#include <coroutine>

struct CoroType
{
	struct promise_type
	{
		CoroType get_return_object() { return CoroType(this); }
		std::suspend_always initial_suspend() { return {}; }
		std::suspend_always final_suspend() noexcept { return {}; }
		void unhandled_exception() noexcept
		{
			std::rethrow_exception(std::current_exception());
		}

		// Allows to use co_yield
		int m_value;
		std::suspend_always yield_value(int val)
		{
			m_value = val;
			return {};
		}

		void return_void() {};
	};

	CoroType(promise_type* p)
		: m_handle(std::coroutine_handle<promise_type>::from_promise(*p)) {}
	~CoroType()
	{
		std::cout << "Handle destroyed..." << std::endl;
		m_handle.destroy();
	}

	std::coroutine_handle <promise_type> m_handle;
};

CoroType do_work()
{
	std::cout << "Starting the coroutine..." << std::endl;
	co_yield 1;
	co_yield 2;
	co_yield 3;
}

int main()
{

	auto task = do_work();

	task.m_handle(); // This resumes the coroutine. When nex suspension point is hit it pauses.
	std::cout << "value: " << task.m_handle.promise().m_value << std::endl;

	task.m_handle();
	std::cout << "value: " << task.m_handle.promise().m_value << std::endl;

	task.m_handle();
	std::cout << "value: " << task.m_handle.promise().m_value << std::endl;



	std::cout << std::boolalpha << "coro done: " << task.m_handle.done() << std::endl;

	std::cout << "DONE!" << std::endl;

	return 0;
}