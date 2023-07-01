#include "AsExample_Lesson_Conversions.h"

// AsType
AsType::~AsType()
{
}
//-------------------------------------------------------------------------------------------------------------------------------
AsType::AsType()
	: I(3)
{
}
//-------------------------------------------------------------------------------------------------------------------------------
const char* AsType::hello() const
{
	return "Hello world, this is Parent!\n";;
}
//-------------------------------------------------------------------------------------------------------------------------------
void AsType::f(int v) const
{
	const_cast<AsType*>(this) -> I = v;
}
//-------------------------------------------------------------------------------------------------------------------------------
const void AsType::St_Type_Info()
{

}
//-------------------------------------------------------------------------------------------------------------------------------
int f()
{
	return 42;
}
//-------------------------------------------------------------------------------------------------------------------------------




// AType_Child
AType_Child::~AType_Child()
{
}
//-------------------------------------------------------------------------------------------------------------------------------
AType_Child::AType_Child()
{
}
//-------------------------------------------------------------------------------------------------------------------------------
const char* AType_Child::hello() const
{
	return "Hello world, this is Child!\n";;
}
//-------------------------------------------------------------------------------------------------------------------------------




// AsExample_Lesson_Conversions
AsExample_Lesson_Conversions::~AsExample_Lesson_Conversions()
{
}
//-------------------------------------------------------------------------------------------------------------------------------
AsExample_Lesson_Conversions::AsExample_Lesson_Conversions()
	:X(5), Y(19)
{
}
//-------------------------------------------------------------------------------------------------------------------------------
void AsExample_Lesson_Conversions::Init()
{

	//Reinterpret_Cast_Conversions_Examples();

	//Const_Cast_Conversions_Examples();

	//Character_Literal_Examples();

	// Conversions_Examples();

	// Lambda
	/*
	Lambda_Expressions();
	Lambda_Few_Examples_How_To_Use();
	*/
}
//-------------------------------------------------------------------------------------------------------------------------------
void AsExample_Lesson_Conversions::Conversions_Examples()
{
	// "Integral promotion"
	char a = 10, b = 20;
	int sum_two = a + b;  // Integral promotion from char to int

	// floating-point promotion
	float f = 3.14f;
	double d = f;  // floating-point promotion:from float to double

	// Integral conversions
	short s = 10;
	int i = s; // Integral conversion from short to int 
	i = 1000;
	short q = i;  // s = 232

	// Floating–integral conversions
	int float_to_int = static_cast<int>(f);  // float to int
	float int_to_float = static_cast<float>(i);  // int to float

	// Pointer conversions
	AHuman human;  // add obj
	AsLiving_Being *living_being = &human;  // ptr on base class point on child
	AHuman *human_1 = static_cast<AHuman*>(living_being);  // now ptr point on the same obj || now have all func 

	// Pointer-to-member conversions
	int (AHuman::*Human_Counts) = &AHuman::Test;  // ptr to parametrs 
	void (AHuman::*Thinkin)() = &AHuman::Think;  // ptr to func
	(human.*Thinkin)();  // call func from ptr on object

	// Qualification conversions
	int x = 15;
	const int *ptr = &x;
	int *mutable_int = const_cast<int *> (ptr);  // delete const CV

	if (mutable_int != 0)
		*mutable_int = 20;


}
//-------------------------------------------------------------------------------------------------------------------------------
void AsExample_Lesson_Conversions::Const_Cast_Conversions_Examples()
{// Usual arithmetic conversions
	const int x = 5;
	const int j = 3; // j is declared const

	char y = 20;
	short s = 10;
	int i = 3;                 // i is not declared const
	int *ptr;
	int* result;
	int offset = 3;
	int z;
	int a = 5;
	float b = 2.5;

	ptr = 0;
	double c = a + b; // int a будет преобразован в тип double
	z = s + y; // Оба операнда имеют тип int
	result = ptr + offset;

	ptr = const_cast<int*>(&x);
	*ptr = 10;  // change value of const int x = 5;

	const int& rci = i;
	const_cast<int&>(rci) = 4; // OK: modifies i
	cout << "i = " << i << '\n';

	// 
	AsType t; // if this was const AsType t, then t.f(4) would be undefined behavior
	t.f(4);  // call const function
	cout << "AsType::I = " << t.I << '\n';

	int *pj = const_cast<int*>(&j);
	*pj = 4;      // undefined behavior

	void (AsType::* pmf)(int) const = &AsType::f; // pointer to member function
	//const_cast<void(AsType::*)(int)>(pmf);   // compile error: const_cast does | not work on function pointers
}
//-------------------------------------------------------------------------------------------------------------------------------
void AsExample_Lesson_Conversions::Static_Cast_Conversions_Examples()
{
	int x = 10;
	double y = static_cast<double>(x);  // conversation to double

	AsType *type = new AType_Child();
	x = type->I;
	AType_Child *type_child = static_cast<AType_Child*>(type);
	type_child->f(x);

	// 
	AType_Child type_child_1;
	AsType &type_1 = type_child_1;  // upcast via implicit conversion
	cout << "1) " << type_1.hello();  // call func from Parent
	AType_Child &type_2 = static_cast< AType_Child& >(type_1); // downcast | cast from Parent to child
	cout << "1) " << type_2.hello();  // call func from child

	// 2. lvalue to xvalue
	vector<int> v0 { 1, 2, 3 };
	vector<int> v2 = static_cast< vector< int > && >(v0);  // Move from v0 to v2
	//cout << "2) after move, v0.size() = " << v0.size() << '\n';

	// 3. initializing conversion
	int n = static_cast<int>(3.14);  // n = 3;
	cout << "3) n = " << n << '\n';
	vector<int> v = static_cast<vector<int>>(10);  // create 10 new param
	cout << "3) v.size() = " << v.size() << '\n';

	// 4. discarded-value expression
	static_cast<void>(v2.size() );

	// 5. inverse of implicit conversion
	void *nv = &n;  // n = 3 save to void *nv 
	int *ni = static_cast<int*>(nv);  // load from nv and save to *ni now its = 3
	cout << "5) *ni = " << *ni << '\n';

	// 6. array-to-pointer followed by upcast
	AType_Child type_child_array[10];
	AsType *dp = static_cast<AsType*>(type_child_array);

	// 7. scoped enum to int
	E e = E::TWO;
	int two = static_cast<int>(e);
	cout << "7) " << two << '\n';

	// 8. int to enum, enum to another enum
	E e2 = static_cast<E>(two);
	EU eu = static_cast<EU>(e2);

	// 9. pointer to member upcast
	int AType_Child::*pm = &AType_Child::M;
	cout << "9) " << type_1.*static_cast<int AsType::*>(pm) << '\n';

	// 10. void* to any type
	void* voidp = &e;
	vector<int> *p = static_cast<vector<int>*>(voidp);
}
//-------------------------------------------------------------------------------------------------------------------------------
void AsExample_Lesson_Conversions::Reinterpret_Cast_Conversions_Examples()
{
	int i = 7;
	int *reinterp_i = new int(65);
	char *reinter_c = reinterpret_cast<char*>(reinterp_i);  // reinter_c = 'A';

	// pointer to func on Type_Get_Info in same class
	void (AsExample_Lesson_Conversions::*pf)(const AsType*) = &AsExample_Lesson_Conversions::Type_Get_Info;

	// pointer to integer and back
	uintptr_t v1 = reinterpret_cast<uintptr_t>(&i); // static_cast is an error
	cout << "The value of &i is " << showbase << hex << v1 << '\n';
	int *p1 = reinterpret_cast<int*>(v1);
	assert(p1 == &i);

	// pointer to function to another and back
	void(*fp1)() = reinterpret_cast<void(*)()>(f);  // global || static func to ptr fp1 
	fp1();  // call fp1
	int(*fp2)() = reinterpret_cast<int(*)()>(fp1);  // 
	cout << dec << fp2() << '\n'; // safe
	
	// pointer to function to another and back
	void(*f_p_g)() = reinterpret_cast<void(*)()>(AType_Child::St_Type_Info);  // static example
	f_p_g();
	void(*f_p_g_1)() = reinterpret_cast<void(*)()>(f_p_g);

	// type aliasing through pointer
	char *p2 = reinterpret_cast<char*>(&i);
	cout << (p2[0] == '\x7' ? "This system is little-endian\n" : "This system is big-endian\n");

	// type aliasing through reference
	reinterpret_cast<unsigned int&>(i) = 42;
	cout << i << '\n';

	const int &const_iref = i;
	// int &iref = reinterpret_cast<int&>(const_iref); // compiler error - can't get rid of const
	// Must use const_cast instead: 
	int &iref = const_cast<int&>(const_iref);

	cout << reinter_c;
	delete reinterp_i;
}
//-------------------------------------------------------------------------------------------------------------------------------
void AsExample_Lesson_Conversions::Character_Literal_Examples()
{
	wchar_t chineseChar = L'一'; // Начальный иероглиф

	for (int i = 0; i < 10; i++) {
		wcout << chineseChar << endl;
		chineseChar++; // Переход к следующему иероглифу
	}
}
//-------------------------------------------------------------------------------------------------------------------------------
void AsExample_Lesson_Conversions::Type_Get_Info(const AsType* type)
{
}
//-------------------------------------------------------------------------------------------------------------------------------
void AsExample_Lesson_Conversions::Value_Categories()
{
	int x = 10;        // переменная x - lvalue
	int y = x;         // x - lvalue, y - lvalue
	int* ptr = &x;     // ptr - lvalue, &x - lvalue (адрес переменной x)

	int sum = 5 + 3;   // 5 и 3 - rvalue (результат арифметического выражения)
	int value = Get_X();    // Get_X() - rvalue (результат вызова функции)

	int gl_x = 10;        // x - glvalue (lvalue)
	int& ref = x;      // ref - glvalue (lvalue reference)
	int&& rref = 5;    // rref - glvalue (rvalue reference)

	int pr_sum = 5 + 3;   // 5 и 3 - prvalue (чистые временные значения)
	int pr_value = Get_X();    // Get_X() - prvalue (результат вызова функции)

	std::vector<int> v1 = {1, 2, 3};   // v1 - lvalue
	std::vector<int> v2 = std::move(v1);   // std::move(v1) - xvalue (rvalue reference)

}
//-------------------------------------------------------------------------------------------------------------------------------
int AsExample_Lesson_Conversions::Get_X()
{
	return 0;
}
//-------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------
void AsExample_Lesson_Conversions::Lambda_Expressions()
{
	const int cons_x = 98;
	const int cons_y = 53;
	int x = 5;
	int y = 19;
	int result;

	// Example []
	auto lambda_1 = [=] () { return X + Y; };  // Example Capture - Default "=" get all params
	auto lambda_2 = [&x] () { return x; };  // Example Capture by &
	auto lambda_3 = [=, &y] () { return x + y; };  // Example Capture all except &y will be changed
	auto lambda_4 = [] () { return cons_x; };  // Example Capture if this is constexpr, const 

	// Example ()
	auto lambda_template_1 = [](auto x) { return x; };  // Example template in param
	cout << (result = lambda_template_1(x) ) << endl;
	auto lambda_template_2 = [](auto x, auto y) { return x + y; };  // Example template in params
	cout << (result = (int)lambda_template_2(3.23, 12.3) ) << endl;

	// Example () ->
	auto lambda_5 = [](int x, int y) -> int { return x + y; };  // auto will be int
	cout << (result = lambda_template_2(3, 12) ) << endl;

	// Example () mutable {
	auto lambda_6 = [x]() mutable { x = 10; };  // its like &x 
	cout << x << endl;

	// Example mutable, constexpr, consteval и static
	
	// generic lambda, operator() is a template with one parameter
	auto vglambda = [](auto printer)
	{
		return [=](auto&&... ts) // generic lambda, ts is a parameter pack
		{ 
			printer(forward<decltype(ts)>(ts)...);
			// nullary lambda (takes no parameters):
			return [=] { printer(ts...); };
		};
	};

	// Example auto examples
	auto p = vglambda([](auto v1, auto v2, auto v3)
		{
			std::cout << v1 << v2 << v3;
		});
	auto q = p(1, 'a', 3.14); // outputs 1a3.14
	q();       

	// Example Capture-less non-generic lambda:
	using F = int(*)(int);  // define type F its pointer to a func wich return int
	auto lamda_example = [](int x){ return x * x; };  // on this func we take pointer
	F func_l = lamda_example;  // now func_l can do same as lambda
	int result_1 = func_l(5);  // example

	// Capture-less generic lambda:
	//!!!
}
//-------------------------------------------------------------------------------------------------------------------------------
void AsExample_Lesson_Conversions::Lambda_Few_Examples_How_To_Use()
{
	vector<int> c{1, 2, 3, 4, 5, 6, 7};
	int x = 5;

	c.erase(remove_if(c.begin(), c.end(), [x](int n)
		{
			bool result = n < x;  // remove if n < m 
			return result;  // if true remove_if remove from vector
		}), c.end() );

	cout << "c: ";
	for_each(c.begin(), c.end(), [](int i)  // int i = c.begin() element
		{
			cout << i << ' ';
		});
	cout << '\n';

	auto func1 = [](int i = 6)
	{// the type of a closure cannot be named, but can be inferred with auto | since C++14, lambda could own default arguments
		int result = i + 4;
		return result;
	};
	cout << "func1: " << func1() << '\n';

	// like all callable objects, closures can be captured in function | (this may incur unnecessary overhead)
	function<int(int)> func2 = [](int i)
	{
		int result = i + 4;
		return result;
	};
	cout << "func2: " << func2(6) << '\n';


	// Example Fibonacci numbers v1:
	constexpr int fib_max { 8 };
	cout << "Emulate `recursive lambda` calls:\nFibonacci numbers: ";
	auto nth_fibonacci = [](int n)
	{
		function<int(int, int, int)> fib = [&](int n, int a, int b)
		{
			return n ? fib(n - 1, a + b, a) : b;
		};
		return fib(n, 0, 1);
	};

	for (int i { 1 }; i <= fib_max; ++i)
	{
		cout << nth_fibonacci(i);

		if (i < fib_max)
			cout << ", ";
		else
			cout << "\n";
		
		//cout << nth_fibonacci(i) << (i < fib_max ? ", " : "\n");
	}


	// Example Fibonacci numbers v2:
	cout << "Alternative approach to lambda recursion:\nFibonacci numbers: ";
	auto nth_fibonacci2 = [](auto self, int n, int a = 0, int b = 1) -> int
	{
		return n ? self(self, n - 1, a + b, a) : b;
	};

	for (int i{1}; i <= fib_max; ++i)
		cout << nth_fibonacci2(nth_fibonacci2, i) << (i < fib_max ? ", " : "\n");

#ifdef __cpp_explicit_this_parameter
	cout << "C++23 approach to lambda recursion:\n";
	auto nth_fibonacci3 = [](this auto self, int n, int a = 0, int b = 1) -> int
	{
		return n ? self(n - 1, a + b, a) : b;
	};

	for (int i{1}; i <= fib_max; ++i)
		cout << nth_fibonacci3(i) << (i < fib_max ? ", " : "\n");
#endif
}
//-------------------------------------------------------------------------------------------------------------------------------
