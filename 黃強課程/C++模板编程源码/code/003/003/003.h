
//������ģ��
template<typename T>
class  Math
{
public:
	//��Ա�������ڲ�ʵ��
	T  sum(T  a, T  b)
	{
		return a + b;
	}

	//��Ա�������ⲿʵ��
	T   max(T  a, T b);

};


//��Ա�������ⲿʵ��,��Ȼ��Ҫ����template����
template<typename T>
T   Math<T>::max(T  a, T b)
{
	return  a > b ? a : b;
}

