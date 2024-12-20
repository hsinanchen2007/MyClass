#include <stdio.h>

int main()
{
    /*
     * 1.数组的存储细节
     * 1.1从未被占用内存地址大的开始给数组分配存储空间
     * 1.2从分配的存储空间中地址最小的开始给每一个元素分配存储空间
     * 1.3从每一个元素占用存储空间地址大的开始存储数据
     *
     * 2.结构体的存储细节
     * 2.1从未被占用内存地址大的开始给结构体分配存储空间
     * 2.2从分配的存储空间中地址最小的开始给每一个属性分配存储空间
     * 2.3从每一个属性占用存储空间地址大的开始存储数据
     *
     * 3.结构体变量分配存储空间的细节
     * 3.1会找到结构体类型中占用存储空间最大的属性
     * 3.2每次分配存储空间都会按照占用内存最大的属性来分配
     * 3.3并不是每个属性都会分配一次存储空间, 而是会看上一次分配的存储空间是否足够存储当前的属性
     * 3.4如果上一次分配的存储空间还有富余的, 并且能够存储当前的属性, 那么就不会再分配存储空间了
     * 3.5如果上一次分配的存储空间不足够存储当前的属性, 就会再次按照占用存储空间最大的属性来分配存储空间
     */
    /*
    int ages[3] = {1, 3, 5};

    struct Demo{
        int num;
        int value;
    };
    struct Demo d;
    d.num = 1;
    d.value = 3;

    printf("&d = %p\n", &d); //  &d = 0060FE9C
    printf("&num = %p\n", &d.num); //  &num = 0060FE9C
    printf("&value = %p\n", &d.value); //  &value = 0060FEA0
    */

    struct Demo{
//        double score; // 8
//        int num;  // 8 - 4 = 4
//        char value; // 4

        int num;  // 8 - 4 = 4
        double score; // 8
        char value; // 8
    };
    struct Demo d;
    printf("size = %i\n", sizeof(d)); // 16 24

    return 0;
}
