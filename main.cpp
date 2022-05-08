//�����û��������ֵ��������Ӧ������ Animal ����� Dog ����Ȼ�������١�
//����ľ�̬���ݳ�Ա��¼��������������ù��캯�����������������´������������10�֣�
//��Ŀ���ݣ�
//1. ��д������
//Dog��̳�Animal�ࣻ
//Animal���Dog�����һ��Ĭ�Ϲ��캯�����ֱ�����ַ��� ��Animal���͡�Dog��������ַ�������
//�����У��ĸ��������Լ����������һ����̬���ݳ�Ա�����ڼ�������ʱ�̴�������Animal��Dog�����������
//��ν�����Ķ�����������ָ�����Ķ���������ȥ���ٵĶ���������ע�⣺�þ�̬���ݳ�ԱҪͳ�����е�Animal��Dog�����������
//��������Animal���������߽���Dog�����������
//���������̬���ݳ�Ա��getter����
//����Ҫ�޸����еĹ��캯��������������ʹ��������̬���ݳ�Ա�ܹ���ȷ�ط�ӳ��ǰϵͳ�д��Ķ����������ע�����������в�����κ���Ϣ
//2. ��д������
//���������н����û������һ������N������0����
//��������vector����v1 �� v2 ����������������֣����ֱ�洢Animal�����ָ���Dog�����ָ�롣
//�����ȴ���һ�� Animal ���󣬽������ٴ���һ�� Dog �����������洴���Ĵ���һ������ N �� Animal�����N��Dog����
// ��Animal�����ָ�붼����v1�У���Dog�����ָ�붼����v2�С�
// ����ʾ������ʹ��vector::push_back()��������ÿ����һ��Animal��Dog�����������ж�������������У�
//Ҳ���Ǵ���һ��Animal�����ٴ���һ��Dog����Ȼ��������ж�������������У�֮����ִ����һ�֣�ֱ��ִ��N�ֺ��������
//����������һ��Animal���󣬽�����������һ�� Dog ��������������򣬽�v1��v2��ָ����ָ��Ķ�������
//����ʾ�������������±����������vector�����д洢��ָ�롣ʹ��delete��������ٶ��󣩡�
//ÿ����һ��Animal��Dog�����������ж�������������У�Ҳ��������һ��Animal����
// ������һ��Dog����Ȼ��������ж�������������У�֮����ִ����һ�����ٲ�����ֱ��ִ��N�ֺ��������
//�����г��˽����û����������֮�⣬û���κ�����������䣻
//�����г��˹��캯���ʹ��������������֮�⣬û���κ����������

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