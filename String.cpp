#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<assert.h>
using namespace std;
////ģ��ʵ��String��
//
//class String
//{
//	friend ostream& operator<<(ostream& out, String& s);
//private:
//      char* _str;
//public:
//	//String()                  //���죿   //���Ǳ�������дһ��û�в����Ĺ��캯���Է��㲻�������Ķ������  ���Ƿ����@���ܲ�����
//	//	:_str(NULL)
//	//{
//	//	cout << "String" << endl;
//	//}
//	String(const char* str="")              //����Ĭ�ϲ����Ĺ��캯��         //���@�� ��ʼ�����β�*str=""  ����һ�����ַ��� ����Ϊ0  1���ֽ�                 
//		:_str(new char[strlen(str) + 1])    //���ٿռ�
//	{
//		cout << "String" << endl;
//		strcpy(_str, str);                 //ֵ����
//	}
//	String(const String& s)                      //��������
//		:_str(new char[strlen(s._str)+1])
//	{
//		cout << "String& s" << endl;
//		strcpy(_str, s._str);
//	}
//	String& operator=(const String& s)                           //��ֵ�����������
//	{
//		cout << "String& operator=(const String& s)" << endl;
//		if (this != &s)                                         //�����Ը�ֵ
//		{
//			delete[] _str;                                      //�ǵ�delete[]�ɶ�ʹ��
//			_str = new char[strlen(s._str) + 1];
//			strcpy(_str, s._str);
//		}
//		return *this;
//	}
//	~String()
//	{
//		cout << "~String" << endl;
//		if (_str != NULL)
//		{
//			delete[] _str;
//		}
//	}
//
//
//};
//ostream& operator<<(ostream& out, String& s)
//{
//	out << s._str;
//	return out;                                //�@��ǵ÷���ֵ
//}
//int main()
//{
//	String s1("hello bit.\n");
//	String s3;                     //�����޲εĹ��캯��
//	String s2(s3);                 //�������캯��
//	String s4(s1);
//	String s5("hello world\n");
//	String s6;
//	s6 = s5;
//	cout << s1;
//	cout << s2;
//	cout << s3;
//	cout << s6;
//	return 0;
//}



//String ��ͳд����ϰ   ���˼��
//class String
//{   
//	friend ostream& operator<<(ostream& out, String& s);
//private:
//	 char* _str;
//public:
//	String(const char* str="")        //����         �տ�ʼ��ʱ ����û��Ĭ�ϲ����Ĺ��캯��Ϊʲô���ǲ���ʹ��_str(str)���и�ֵ�أ�
//		:_str(new char[strlen(str)+1])                   //��һ�� �β�strָ��̬�����Ǹ����� ��ʼ��������_strҲָ��̬��  ��ô���������ʱ�����ͷž�̬�����ַ���������
//	{                                                       //�@���ʹ�������  ����_str�����@���ַ���Ҳû�а취���в��� ����Ҫ�Լ��������ٿռ�
//		cout << "����" << endl;
//		strcpy(_str, str);
//	}
//	String(const String& s)          //��������
//		:_str(new char[strlen(s._str)+1])
//	{
//		cout << "��������" << endl;
//		strcpy(_str, s._str);
//	}
//	String& operator=(const String& s)
//	{
//		if (this != &s)                             //�@��һ��Ҫ�ж��Ը�ֵ������  �����Ը�ֵ������ܴ������
//		{
//			cout << "��ֵ���������" << endl;
//			char* tmp = new char[strlen(s._str) + 1];       //�@�ﶨ��һ��tmp��Ŀ����Ϊ�˷�ֹ�ڿռ��ϳ������� ����ռ䲻������ͣ
//			strcpy(tmp, s._str);
//			delete[] _str;                           //����@���Ը�ֵ��  ��ô�@��Ͱ��Լ��ͷ��� 
//			_str = tmp;                              //����Լ��ͷ��� s._str��������
//		}
//		return *this;
//	}
//
//	~String()
//	{
//		cout << "����" << endl;
//		if (_str != NULL)
//		{
//			delete[]_str;
//			_str = NULL;
//		}
//	}
//
//
//};
//ostream& operator<<(ostream& out, String& s)
//{
//	out << s._str;
//	return out;
//}
//int main()
//{
//	String s1("hello today\n");
//	cout << s1;
//	String s2(s1);
//	cout << s2;
//	String s3("hi\n");
//	s2 = s3;
//	cout << s2;
//	return 0;
//}

//new delete�ڿ��ٿռ�ʧ�ܵ�ʱ������쳣  




//дʱ����
//�����ü�����ǳ�����Ĵ���ʽ1
//class String
//{
//	friend ostream& operator<<(ostream& out, String& s);
//private:
//	char* _str;
//	int _refCount;
//public:
//	String(const char* str="")
//		:_str(new char[strlen(str)+1])
//		, _refCount(1)
//	{
//		cout << "����" << endl;
//		strcpy(_str, str);
//	}
//	String( String& s)            //ǳ����       //�@������Ҫ��constȥ������Ϊ�����ı�s���õļ�����Ա
//		:_str(s._str)
//	{
//		++s._refCount;
//		_refCount = s._refCount;         
//	}
//	~String()
//	{
//		if (--_refCount == 0)    
//		{
//            if (_str != NULL)
//			{
//				cout << "����" << endl;
//				delete[] _str;
//				_str = NULL;
//			}
//		}
//	}
//};
//ostream& operator<<(ostream& out, String& s)
//{
//	cout << s._str;
//	return out;
//}
//int main()
//{
//	String s1("hello\n");
//	cout << s1;
//	String s2(s1);
//	return 0;
//}

//�����������  ʹ��static����refCountʹ��Ϊ��̬    ������Ȼ��������                  ��̬��Ա����������thisָ��  ��̬��Ա�������ܷ��ʷǾ�̬��Ա
//class String
//{
//	friend ostream& operator<<(ostream& out, String& s);
//private:
//	char* _str;
//	static int _refCount;      //��̬��Ա�����ڳ�ʼ���б��г�ʼ��  ֻ���ں����ڲ�����������г�ʼ��
//public:
//	String(const char* str = "")
//		:_str(new char[strlen(str) + 1])
//	{
//		_refCount = 1;
//		cout << "����" << endl;
//		strcpy(_str, str);
//	}
//	String(String& s)            //ǳ����       //�@������Ҫ��constȥ������Ϊ�����ı�s���õļ�����Ա
//		:_str(s._str)
//	{
//		++_refCount;             //
//	}
//	~String()
//	{
//		if (--_refCount == 0)
//		{
//			if (_str != NULL)
//			{
//				cout << "����" << endl;
//				delete[] _str;
//				_str = NULL;
//			}
//		}
//	}
//};
//ostream& operator<<(ostream& out, String& s)
//{
//	cout << s._str;
//	return out;
//}
//int String::_refCount = 0;
//int main()
//{
//	String s1("hello\n");
//	cout << s1;
//	String s2(s1);               //�@����ֻ������һ��
//	String s3(s2);
//	String s4(s3);
//	cout << s3;
//
//	String s5("bit\n");    //�@������������Ĵ���  ���¹�����һ������֮�� �Ծ�̬��refCount���Ӱ�� 
//	String s6(s5);         //��������̬���ĳ����ַ�����ָ��   ������Ȼֻ������һ��                ��������
//	cout << s6;
//	return 0;
//}



//���յĽ������    CopyOnWrite  
class String
{
	friend ostream& operator<<(ostream& out, String& s);
private:
	char* _str;
    int* _refCount;                       //��ָ��ά���@������     ���һ��Ϊʲô��ָ����ά��
public:
	String(const char* str = "")
		:_str(new char[strlen(str) + 1])
		, _refCount(new int(1))
	{
		cout << "����" << endl;
		strcpy(_str, str);
	}
	String(String& s)            
		:_str(s._str)
		, _refCount(s._refCount)
	{
		++(*_refCount);
		
	}
	String& operator=(String& s)           //��ֵ�������������Ҫ����3�����       ͦ��Ҫ��
	{
		if (this != &s)                   //1.���=����������ָ�����ͬһ��ռ� ��ִ��
		{
			if (--(*_refCount) == 0)            //2.���s1ָ��Ŀռ�û�������Ķ���ָ���� ��ôs1�ı�ָ�����Ҫ���Լ��ĳ�Ա������ռ�Ŀռ��������
			{                                  //��ָ��s2
				cout << "����" << endl;
				delete[]_str;
				delete _refCount;
			}
			_str = s._str;
			_refCount = s._refCount;             //3.���s1ָ��Ŀռ�Ҳ�������Ķ���ָ��  ��ô�ǿ�ռ��_refCount-1������ s1ֱ�Ӹı�ָ������ɶ��������
			++(*_refCount);                //ע�⣺�@��ļ����Ѿ�������s1�ļ�����  �Ѿ���s2�ļ�����
		}
		return *this;
	}
	char& operator[](size_t index)         //�±����������������  //�@��ΪʲôҪ����һ��char&  ?  ˼��
	{
		assert(index < strlen(_str));
		return _str[index];                 //�@�ﷵ�ص���_str��ָ����ַ�����ĳ���ַ�������   ����ʹ��char&  ����һ���ַ�
	}

	~String()
	{
		if (--(*_refCount) == 0)
		{
			if (_str != NULL)
			{
				cout << "����" << endl;
				delete[] _str;
				delete _refCount;
				_str = NULL;
			}
		}
	}
};
ostream& operator<<(ostream& out, String& s)
{
	cout << s._str;
	return out;
}
int main()
{
	String s1("hello\n");
	cout << s1;
	String s2(s1);           
	String s3(s2);
	String s4(s3);
	cout << s3;

	String s5("bit\n");       
	String s6(s5);            //�@�����ܹ��������� 
	cout << s6;
	s5 = s1;                         //����ڸ�ֵ�����������  ����ôдʱǳ�����أ�
	String s7("juxin");
	String s8;
	s8 = s7;
	s7[3] = 'I';            //�@�����˼������ĺ��������������s7[3]ʵ���ϴ�������±�Ϊ3���ַ�������   ��ô�á�I������ֵ ��Ȼ�ǿ��ԴӸ�Դ���ĵ� 
	cout << s7;
	return 0;
}

