#include <iostream>
#include <vector>

// --------------------------------------
//   모던 C++ 디자인 패턴
//
/// 참조 https://devjino.tistory.com/50 
//  https://github.com/gilbutITbook/007028/blob/master/Behavioral/Strategy/strategy_static.cpp

//https://copynull.tistory.com/132
//----------------------------------------

using namespace std;

class Adaptee
{
public:
	void adaptedOperation(){
		cout << "adotedOperation" << endl;
	}
};

class Adapter
{
public:
	virtual void operation() = 0;
};

class ConcreteAdapterA : public Adapter
{
public:
	void operation() override {
		pAdaptee.adaptedOperation();
	}
private:
	Adaptee  pAdaptee;
};

class ConcreteAdapterB : public Adapter, public Adaptee
{
public:
	void operation() override {
		adaptedOperation();
	}
};



///////////////////

class CStrData
{
public :
	CStrData(string data): m_strData(data)
	{
	}
	const string GetStringData() {
		return m_strData;
	}
private:
	string m_strData;
};

class MyAdapter {
public:
	virtual int operation() = 0;

};

class MyConcreteAdapterA :MyAdapter
{
public:
	MyConcreteAdapterA(string aa) : m_strData(aa) {};
	int operation() override {
		return atoi(m_strData.GetStringData().c_str());
	
	}
private:
	CStrData m_strData; // 객체 내부 선언 
};

class MyConcreteAdpaterB : public MyAdapter,public CStrData
{
public:
	MyConcreteAdpaterB(string data) : CStrData(data) {}
	
	int operation() override {
		return atoi(GetStringData().c_str());
	}

};

int main()
{
	ConcreteAdapterA  adapterA;
	adapterA.operation();

	ConcreteAdapterA  adapterB;
	adapterB.operation();

}


