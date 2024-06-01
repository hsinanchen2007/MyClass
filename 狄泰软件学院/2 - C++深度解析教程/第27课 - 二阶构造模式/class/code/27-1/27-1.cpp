#include <stdio.h>

class Test
{
    int mi;
    int mj;
    bool mStatus;
public:
    Test(int i, int j) : mStatus(false)
    {
        mi = i;

        return;

        // Below here, j and mStatus will not be
        // called at all, as the return statement
        // above
        mj = j;

        mStatus = true;
    }
    int getI()
    {
        return mi;
    }
    int getJ()
    {
        return mj;
    }
    int status()
    {
        return mStatus;
    }
};

int main()
{
    Test t1(1, 2);

    // as constructor has return statement
    // before mStatus is set to true, this
    // one will always at false status
    if (t1.status())
    {
        printf("t1.mi = %d\n", t1.getI());
        printf("t1.mj = %d\n", t1.getJ());

    }

    return 0;
}
