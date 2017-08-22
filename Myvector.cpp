#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
#include<string>

//ģ��ʵ��vector

template<class T>
class Myvector
{
	typedef T* Iterator;              
	typedef const T* ConstIterator;
private:
	Iterator _start;
	Iterator _finish;
	Iterator _endofstorage;
public:
	Myvector()               //����
		:_start(NULL)
		, _finish(NULL)
		, _endofstorage(NULL)
	{
		cout << "~Myvector()" << endl;
	}
	Myvector(const Myvector<T>& v)    //��������,��size���ǿ�capacity�� Ϊ�˽���ռ��ǿ���size
	{
		_start = new T[v.Size()];
		for (size_t i = 0; i < v.Size(); i++)
		{
			_start[i] = v[i];
		}
		_finish = _start + v.Size();
		_endofstorage = _finish;
	}
	Myvector<T>& operator=(const Myvector<T>& v)
	{
		if (this != &v)
		{
			if (this->Size())    //ԭ���Ŀռ����
				Destory();
			_start = new T[v.Size()];
			for (size_t i = 0; i < v.Size(); i++)   //����
			{
				_start[i] = v[i];
			}
			_finish = _start + v.Size();
			_endofstorage = _start + v.Capacity();
		}
		return *this;
	}
	//����
	void CheckCapacity()
	{
		if (Size() >= Capacity())
			Capacity() = Capacity() + Capacity() / 2;           //Ϊʲô��Ҫ1.5������
		Expand(Capacity());
	}
	//���ӹ̶������Ȼ�󿽱����ݺ���
	void Expand(size_t n)
	{
		if (n == 0)
			return;
		T* tmp = new T[n];
		assert(tmp);
		for (size_t i = 0; i < Size(); i++)
		{
			tmp[i] = _start[i];
		}
		delete[] _start;
		_start = tmp;
		_finish = _start + Size();
		_endofstorage = _start + n;
	}
	void PushBack(const T& data)                //β��
	{
		CheckCapacity();
		*_finish = data;
		_finish++;
	}
	void PopBack()                 //βɾ
	{
		if (Size() <= 0)
			return;
		_finish--;
	}
	void ReSize(size_t n)
	{
		
	}
	void Reserve(size_t n)          //Reserve��ֵ���Ա�ԭ��С��
	{
		if (n <= Size())
			return;
		Expand(n);
	}
	T& operator[]()
	{
		return _start[i];
	}
	size_t Size()
	{
		return _finish - _start;
	}
	size_t Capacity()
	{
		return _endofstorage - _start;
	}
	void Destory()
	{
		delete[]_start;
		_start = NULL;
		_finish = NULL;
		_endofstorage = NULL;
	}
};
void test()
{

}
int main()
{
	test();
	return 0;
}