
// Linker error - this definition is living only in this translation unit
namespace
{
	double add(double a, double b)
	{
		return a + b;
	}

	void do_something()
	{
		add(1, 2);
	}
}