 #include <vector>
#include <string>
#include <iostream>
#include <initializer_list>

using namespace std;

class myVector {
	vector<int> m_vec;
	public: 
		myVector(const initializer_list<int>& v) {
			for (auto itr = v.begin(); itr != v.end(); ++ itr)
				m_vec.push_back(*itr * *itr);
		}
		void printme()
		{
			for (auto it = m_vec.begin(); it != m_vec.end(); ++ it)
				cout << "\t" << *it << endl;		
		}
};

class A {
public:
		A() : A(0) {}
		A(int v) : A(v, 0) {}
		A(int a, int b) { avg = (a + b)/2; }
		int getAvg() { return avg; }
private:
	int a;
	int b;
	int avg;
};

constexpr int cube (int x) { return x*x*x; }
class cat {
	public:
		int age;
		string name;
		cat(int ag, string nm) :
			age(ag),
			name(nm)
		{
			cout << "CAT Ctor(int, string)" << endl;
		}
		void giveVoice()
		{
			std::cout << name << " " << age << endl;
		}
};

class dog {
	int age;
public:
	dog(int age):  age(age) {}
	dog() = default;
	virtual void voice() {
		cout << "Hau hau!" << endl;
	}
};

constexpr long double operator"" _cm(long double x) { return x * 10; }
constexpr long double operator"" _m(long double x) { return x * 1000; }
constexpr long double operator"" _mm(long double x) { return x; }

int main()
{
	// static assert
	static_assert(sizeof(int) == 4, "Int must be 32bit");
	
	// initializer list
	myVector v = {0, 2, 3, 4};
	v.printme();
	
	// uniform unitialization
	cat c1 = {2, "Alice"};
	c1.giveVoice();
	
	// test foreach
	vector<int> m = {0, 1, 2, 3, 4, 6, 7};
	for (auto val : m)
		cout << val << endl;
	// change values in loop
	for (auto & i : m)
		i++;
	for (auto val : m)
		cout << val << endl;
		
	// delegate
	A a(5);
	cout << "avg a() " << a.getAvg() << endl;
	
	// default test
	dog d1;
	
	// constexpr
	cout << cube(3*3*3) << endl;
	
	// string literals
	long double height = 3.4_cm;
	cout << height << endl;
	cout << (height + 13.0_m) << endl; 
    return 0;
}