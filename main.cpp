//根据用户输入的数值，创建相应个数的 Animal 对象和 Dog 对象，然后再销毁。
//用类的静态数据成员记录存活对象的数量。用构造函数和析构函数来更新存活对象的数量（10分）
//题目内容：
//1. 编写两个类
//Dog类继承Animal类；
//Animal类和Dog类各有一个默认构造函数，分别输出字符串 “Animal”和“Dog”。输出字符串后换行
//在类中（哪个类由你自己决定）添加一个静态数据成员，用于计算运行时刻存活的所有Animal和Dog对象的数量。
//所谓“存活的对象数量”是指创建的对象数量减去销毁的对象数量。注意：该静态数据成员要统计所有的Animal和Dog对象的数量，
//不仅仅是Animal的数量或者仅仅Dog对象的数量。
//添加上述静态数据成员的getter函数
//你需要修改类中的构造函数和析构函数，使得上述静态数据成员能够正确地反映当前系统中存活的对象的数量。注意析构函数中不输出任何信息
//2. 编写主函数
//在主函数中接受用户输入的一个整数N（大于0）；
//创建两个vector对象v1 和 v2 （你可以用其它名字），分别存储Animal对象的指针和Dog对象的指针。
//按照先创建一个 Animal 对象，紧接着再创建一个 Dog 对象这样交替创建的次序，一共创建 N 个 Animal对象和N个Dog对象；
// 将Animal对象的指针都存入v1中，将Dog对象的指针都存入v2中。
// （提示：可以使用vector::push_back()函数）。每创建一轮Animal和Dog对象后，输出所有对象的数量并换行（
//也就是创建一个Animal对象，再创建一个Dog对象，然后输出所有对象的数量并换行；之后再执行下一轮，直到执行N轮后结束）。
//按照先销毁一个Animal对象，紧接着再销毁一个 Dog 对象这样交替次序，将v1和v2中指针所指向的对象都销毁
//（提示，可以用数组下标运算符访问vector对象中存储的指针。使用delete运算符销毁对象）。
//每销毁一轮Animal和Dog对象后，输出所有对象的数量并换行（也就是销毁一个Animal对象，
// 再销毁一个Dog对象，然后输出所有对象的数量并换行；之后再执行下一轮销毁操作，直到执行N轮后结束）。
//程序中除了接受用户输入的整数之外，没有任何其它输入语句；
//程序中除了构造函数和存活对象数量的输出之外，没有任何其它输出。

#include <iostream>
#include <vector>
using namespace std;

class Animal {
public:
	static int numberOfObject;
	Animal() {
		cout << "Animal" << endl;
		numberOfObject++;
	}

	~Animal() {
		numberOfObject--;
	}
	void getNumberOfObject() {
		cout << numberOfObject << endl;
	}
};
class Dog :public Animal {
public:
	Dog() {
		cout << "Dog" << endl;
	}
	~Dog() {
	}
};
int Animal::numberOfObject{ 0 };
int main() {
	int N{ 0 };
	cin >> N;
	vector<Animal*> v1;
	vector<Dog*> v2;
	for (int i{ 0 }; i < N; i++) {
		Animal* pa = new Animal;
		v1.push_back(pa);
		Dog* pd{ new Dog };
		v2.push_back(pd);
		pa->getNumberOfObject();
	}

	for (int i{ 0 }; i < N; i++) {
		delete v1[i];
		delete v2[i];
		cout << Animal::numberOfObject << endl;
	}
	return 0;
}