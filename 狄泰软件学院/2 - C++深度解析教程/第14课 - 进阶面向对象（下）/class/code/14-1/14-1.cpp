#include <stdio.h>

// For struct, it is by default public inhertance
// The main difference in C++ between struct and class
// is that struct by default is public, but class
// by default is private. 
struct Biology {
    bool living;
};

struct Animal : Biology {
    bool movable;
    void findFood() { }
};

struct Plant : Biology {
    bool growable;
};

struct Beast : Animal {
    void sleep() { }
};

struct Human : Animal {
    void sleep() { }
    void work() { }
};

int main()
{
    Human H;

    // Because struct by default is public inheritance,
    // we can access functions and members from Human, 
    // to Animal, to Biology
    H.findFood();
    H.movable;
    H.living;

    return 0;
}
