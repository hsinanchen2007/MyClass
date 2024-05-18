
//定义类模板
template<typename T>
class  Math
{
public:
	//成员方法在内部实现
	T  sum(T  a, T  b)
	{
		return a + b;
	}

	//成员方法类外部实现
	T   max(T  a, T b);

};


//成员方法类外部实现,依然需要加上template声明
template<typename T>
T   Math<T>::max(T  a, T b)
{
	return  a > b ? a : b;
}

