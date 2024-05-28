#include <stdio.h>

class Test {
    int mi;
public:
    Test(int i) {
        mi = i;
    }

    // The "Test(0)" here has a big problem
    // as it is a temporary object and will
    // be deleted/end after that line
    Test() {
        Test(0);
        // so after Test(0), we actually didn't
        // initialize mi at all. mi is still an
        // uninitialized value
    }

    void print() {
        printf("mi = %d\n", mi);
    }
};


int main()
{
    // create t object, but actually
    // mi didn't get initialized yet
    Test t;

    // will print out random number
    t.print();

    return 0;
}
