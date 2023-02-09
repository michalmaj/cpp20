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
		void return_void() {};
	};

	CoroType(promise_type* p)
		: m_handle(std::coroutine_handle<promise_type>::from_promise(*p)){}
	~CoroType()
	{
		std::cout << "Handle destroyed..." << std::endl;
		m_handle.destroy();
	}

	std::coroutine_handle <promise_type> m_handle;
};

CoroType do_work()
{
	std::cout << "Doing first thing..." << std::endl;
	co_await std::suspend_always{};
	std::cout << "Doing second thing..." << std::endl;
	co_await std::suspend_always{};
	std::cout << "Doing third thing..." << std::endl;
}

int main()
{
	auto task = do_work();

	// Resume our coroutine (first way)
	task.m_handle();
	std::cout << std::boolalpha << "coro done: " << task.m_handle.done() << std::endl;

	// Resume our coroutine (second way)
	task.m_handle.resume();
	std::cout << std::boolalpha << "coro done: " << task.m_handle.done() << std::endl;

	// Resume our coroutine
	task.m_handle.resume();
	std::cout << std::boolalpha << "coro done: " << task.m_handle.done() << std::endl;

	//// Resume after coroutine has run to completion: VERY BAD! 
	//task.m_handle.resume();
	//std::cout << std::boolalpha << "coro done: " << task.m_handle.done() << std::endl;

	std::cout << "DONE!" << std::endl;

	return 0;
}