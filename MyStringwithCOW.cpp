#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

// MyString  
class MyString
{
	friend void PrintMyString(const MyString& s);
private:
	char* _str;
public:
	MyString(const char* str = "")
		:_str(new char[strlen(str)+1])
	{
		strcpy(_str, str);
		cout << "����" << endl;
	}
	MyString(const MyString& s)
		:_str(new char[strlen(s._str)+1])      //���
	{
		strcpy(_str, s._str);
		cout << "��������" << endl;
	}
	MyString& operator=(const MyString& s)
	{
		if (this != &s)
		{
			char* tmp = _str;
			_str = new char[strlen(s._str) + 1];     //���
			strcpy(_str, s._str);
			delete[] tmp;
		}
		return *this;
	}
	~MyString()
	{
		if (_str != NULL)
		{
			delete[] _str;
			_str = NULL;              //ע���ÿշ�ֹҰָ��
		}
		cout << "~MyString()" << endl;
	}
};

void PrintMyString(const MyString& s)
{
	cout << s._str << endl;
}

// MyString+Copy-On-Write ,  �������������߸�ֵ��ʱ�����ü���++�� 
class MyCOWString
{
private:
	char* _str;
	int* _refCount;
public:
	MyCOWString(const char* str = "")
		:_str(new char[strlen(str) + 1])
		, _refCount(new int(1))
	{
		strcpy(_str, str);
		cout << "����" << endl;
	}
	MyCOWString(const MyCOWString& s)
		:_str(s._str)
		, _refCount(s._refCount)
	{
		cout << "��������" << endl;
		(*_refCount)++;
	}
	//MyCOWString& operator=(const MyCOWString& s)      //�@���ķ����Ǵ���ģ���Ҫ���ǵ��Ƿ���Ҫ�ͷ�֮ǰ�Ŀռ�
	//{
	//	if (this != &s)
	//	{
	//		_str = s._str;
	//		_refCount = s._refCount;
	//		(*_refCount)++;
	//	}
	//	return *this;
	//}

	MyCOWString& operator=(const MyCOWString& s)
	{
		if (this != &s)
		{
			if (--(*_refCount) == 0)           //���Ǳ���ֵ�Ķ������Դ�п��ܻ�����������ռ�У���--������Ϊ0��ʱ���ͷſռ�
			{
				delete[] _str;
				_str = NULL;
			}
			_str = s._str;
			_refCount = s._refCount;
			(*_refCount)++;
		}
		return *this;
	}
	const char& operator[](size_t index) const        //�±����õ�����  ֻ��
	{
		assert(index < strlen(_str));
		return _str[index];
	}
	char& operator[](size_t index)                    //�мǷ�������
	{
		assert(index < strlen(_str));
		if (--(*_refCount) != 0)                      //ע���@��Ҳ��Ҫע���������ü�������
		{
			if (_str)
			{
				char* tmp = new char[strlen(_str) + 1];     //�@�����дʱ������������
				strcpy(tmp, _str);
				_str = tmp;
			}
		}
		return _str[index];
	}
	~MyCOWString()
	{
		if (--(*_refCount) == 0)       //ע���ʱ�����ü�������--����
		{
			if (_str != NULL)
			{
				delete[] _str;
				_str = NULL;
				cout << "~MyCOWString" << endl;
			}
		}
	}
	void PrintString()
	{
		if (_str)
		{
			cout << _str << endl;
		}
	}
};
void MyCOWStringTest(void)
{
	MyCOWString s1("Hello COW");
	MyCOWString s3("Hello String");
	s3 = s1;
	s1[1] = 'o';
	//MyCOWString s2(s1);
	//s2.PrintString();
	//MyCOWString s3("Hello String");
	//s2.PrintString();
	//MyCOWString s4(s1);
	//MyCOWString s5(s1);
	//s4 = s1;
	//s4.PrintString();
	//cout << s1[1] << endl;
	s1.PrintString();
	s3.PrintString();
}

void MyStringTest(void)
{
	MyString s;
	MyString s2("Hello MyString");
	//PrintMyString(s2);
    MyString s3(s2);
	MyString s4("This is MyString");
	s2 = s4;
	PrintMyString(s2);
}
int main()
{
	//MyStringTest();
	MyCOWStringTest();
	return 0;
}