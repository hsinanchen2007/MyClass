#include <stdio.h>

int main()
{
    // ʵ��+ - * / �򵥼�����
    // 1.��ʾ�û�����������Ͳ�������
    printf("��������Ҫ�����ı��ʽ\n");
    printf("����: 1+1\n");
    // 2.������������û�����Ĳ������Ͳ�������
    int a, b;
    char ch;
    // 3.�����û�����Ĳ������Ͳ�������
    scanf("%i%c%i", &a, &ch, &b);
    // 4.���ݲ������Ž��ж�Ӧ������
    switch(ch){
    case '+':
        printf("%i %c %i = %i", a, ch, b, a + b);
        break;
    case '-':
        printf("%i %c %i = %i", a, ch, b, a - b);
        break;
    case '*':
        printf("%i %c %i = %i", a, ch, b, a * b);
        break;
    case '/':
        printf("%i %c %i = %i", a, ch, b, a / b);
        break;
    default:
        printf("��ʹ�ø��๦���빺�򸶷Ѱ汾\n");
        break;
    }
    return 0;
}
