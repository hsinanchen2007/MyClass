#include <stdio.h>

class Test
{
    int mi;
public:
    Test(int i);
    Test(const Test& t);
    int getMi() const;
    void setMi(int v) { mi = v; };
};

Test::Test(int i)
{
    mi = i;
}

Test::Test(const Test& t)
{
    mi = t.mi;
}

int Test::getMi() const
{
    return mi;
}

int main()
{
    Test t1(1);
    t1.setMi(10);

    // The class object is created as const
    // so we can only get mi, but we cannot
    // set mi as the object is const
    const Test t2(99);
    t2.getMi();
    // t2.setMi(999); cannot change t2's mi value
    printf("t2 address = %p\n", &t2);
    printf("t2.mi = %d\n", t2.getMi());

    // convert const t2 to t3 then modify its mi value
    Test *t3 = const_cast<Test *>(&t2);
    printf("t3 address = %p\n", t3);
    t3->setMi(999);
    printf("t2.mi = %d\n", t2.getMi());
    printf("t3.mi = %d\n", t3->getMi());

    return 0;
}
