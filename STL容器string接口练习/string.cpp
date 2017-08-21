#define _CRT_SECURE_NO_WARNINGS 1


//////////////////////////////std::string�Ľӿ�ʹ��/////////////////////////////
#include<iostream>
#include<string>

using namespace std;

void Teststring()
{
	//����
	string s1("hello world");
	string s2(s1);            //��������
	string s3(s2, 2, 6);       //ȥ�涨λ�ù涨���ȵ��Ӵ�
	string s4(s1, 4);              //ȡ��4���ַ�
	string s5("code makes happy", 10); //ȡǰ10���ַ�
	string s6(10, 'x');            //����10����x��
	string s7(10, 42);             //10��ASCII��Ϊ42���ַ�
	string s8(s1.begin(), s1.begin() + 5);
	/*cout << s1 << endl;
cout << s2 << endl;
cout << s3 << endl;
cout << s4 << endl;
cout << s5 << endl;
cout << s6 << endl;*/
	//cout << s7 << endl;
	//cout << s8 << endl;

	//��ֵ��������� 
	string str1("hahha");
	string str2("hhhehehe");
	//str2 = str1;
	string str3(str1 + str2);        //�ַ���ƴ��

	//cout << str3 << endl;

	//begin()��end()   //������

	//rbegin() ��rend()   //���������  �����ַ�����

	//size()
	cout << str1.size() << endl;  //�ַ����ĳ���
	//length()
	cout << str1.length() << endl; //�ַ����ĳ���
	//max_size()
	cout << str1.max_size() << endl;  //�ַ����������ɵ���󳤶�
	//capacity()
	cout << str1.capacity() << endl;  //һ����15 ����Ŀǰ�ַ���������
	//reserve()
	str1.reserve(20);               //����  �ı�capacity
	cout << str1.capacity() << endl;   //�@��ʱ��capacity��ֵ��Ϊ31
	//clear   ɾ���ַ��������ݣ��⽫���һ�����ַ���(����Ϊ0)��
	s2.clear();
	//cout << s2 << endl;   //�մ�  ����Ϊ0
	//cout << sizeof(s2) << endl;    //һ���յ�string�����ֽ���28
	//empty()  �ж��ַ��������Ƿ���0
	//operator[] �±����  
	//cout << str1[20] << endl;
	//at  �±����        ���Խ�����׳��쳣
	//cout << str1.at(10) << endl;
	//ע��operator[] ��at()������

	//back()    �ַ��������һ���ַ�

	//front     �ַ����ĵ�һ���ַ�

	//�ص㣺
	//operator+=
	string str5 = "hello ";       //�ַ���ƴ��
	str5 += 'K';
	str5 += '.';
	str5 += "James";
	str5 += '\n';
	cout << str5;
	//append()     ��ĩβ����ַ���

	//push_back()   ���ַ���ĩβ����ַ�

	//assign()     ���ַ��������滻
	str5.assign("hhahahahahahahahah");
	cout << str5 << endl;

	//insert()      ��posλ��ǰ�����ַ������ַ���
	//str5.insert(5, "jj");   //��λ��֮ǰ�����ַ���
	str5.insert(5, 2, 'v');     //��λ��5֮ǰ����2���ַ�'v';
	cout << str5 << endl;

	//erase(pos��n)      ��posλ��֮��һ��λ�ÿ�ʼ��n��������ɾ������

	//replace()         �滻�ַ������̶����ȣ�

	//swap(string& str)       ����һ���ַ������滻֮�@���ַ���
	//str5.swap("nihao!");   �����@��ʹ��
	string str6 = "nihao!";
	str5.swap(str6);         //swap����Ҫ����һ������Ȼ����ܽ�������ֱ��ʹ��һ���ַ������滻
	//cout << str5 << endl;

	//pop_back()    C++11  
	//���ַ��������һ���ַ�ɾ��


	//��Ҫ��   
	//c_str()    //����һ���ַ������ָ��
	//���ã��õ�C�ַ��� ������һ�������ָ�룬���������һ����null��β���ַ�����(��C����ִ�)��ʾ�ַ�������ĵ�ǰֵ��
	//����������������ַ�������ֵ����ͬ�ַ����У��Լ���ĩβ����һ����ֹ�Ŀ��ַ�(' \ 0 ')��
	//ʹ�ó����� ��ʹ��strcpy��ĺ�����ʱ�򣬲�֧��string���ͣ��@��ʱ��Ϳ����б�Ҫ��stringת��ΪC����ַ���
	//char* strArr = new char[str5.size() + 1];
	//strcpy(strArr, str5.c_str());        //ʹ�ó���
	//cout << strArr << endl;

	//data            //���ܺ�c_str()����һ��  ��֪������
	char* strArr = new char[str5.size() + 1];
	strcpy(strArr, str5.data());        //ʹ�ó���
	cout << strArr << endl; 
	//data �� c_str() ����Ľ��һ��

	//size_t copy (char* s, size_t len, size_t pos = 0) const;
	//����ǰ���ַ�������ָ��λ�ã�ָ�����ȣ�������ָ���ַ�������s��


	//findϵ�нӿ�  ����ֵ��size_t ���ص��ǵ�һ�γ��ֵ�λ�� 
	//size_t find (const string& str, size_t pos = pos) const;
	//1.find ����ָ��λ��֮����ַ�����ָ���ַ�����һ�γ��ֵ�λ��
	//2.rfind ����ָ��λ��֮ǰ���ַ����е�һ�γ��ֵ�ָ���ַ�����λ��
    
	//find_first_of   ����ָ��λ��֮���ָ���ַ�����һ�γ��ֵ�λ��
	//find_first_not_of  �����ַ����е�һ�γ��ֵĲ�ƥ����ַ�����

	//substr(pos=0,len)  
	//��ȡ�Ӵ�����ָ����λ��pos��ȡ֮�󳤶�Ϊlen���Ӵ�
    
	//compare  �ַ����ȽϺ��� ����ָ��λ��ֻ������
	cout << str5.compare("o") << endl;  //-1
	cout << str5.compare("hahahahhahaha") << endl;  //1
	cout << str5.compare("nihao!") << endl; //0
	//ԭ���strcmp��һ����


	//operator<<    operator<< 
	//string������������������
}
int main()
{
	Teststring();
	return 0;
}