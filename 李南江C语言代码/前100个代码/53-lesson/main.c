#include <stdio.h>

int main()
{
    /*
    Ҫ���û�����һ����������������ķ��������Ӧ�ĵȼ�
    A 90��100
    B 80��89
    C 70��79
    D 60��69  60 / 10 = 6; 69 / 10 = 6
    E 0��59
     */
    // 1.��ʾ�û��������
    printf("������һ��0~100�ķ���,�Իس�����\n");
    // 2.������������û�����
    int score;
    // 3.�����û�����
    scanf("%i", &score);
    // 4.�жϷ���, ������
    // 4.1�ų��Ƿ�����
    /*
    if(score < 0 || score > 100){
        printf("û���������\n");
    }else if(score >= 90 && score <= 100){
        printf("��ǰ�ķ�����%i,��Ӧ�ĵȼ���A", score);
    }else if(score >= 80 && score <= 89){
        printf("��ǰ�ķ�����%i,��Ӧ�ĵȼ���B", score);
    }else if(score >= 70 && score <= 79){
        printf("��ǰ�ķ�����%i,��Ӧ�ĵȼ���C", score);
    }else if(score >= 60 && score <= 69){
        printf("��ǰ�ķ�����%i,��Ӧ�ĵȼ���D", score);
    }else{
         printf("��ǰ�ķ�����%i,��Ӧ�ĵȼ���E", score);
    }
    */
    switch(score / 10){
    case 10:
//         printf("��ǰ�ķ�����%i,��Ӧ�ĵȼ���A", score);
//        break;
    case 9:
         printf("��ǰ�ķ�����%i,��Ӧ�ĵȼ���A", score);
        break;
    case 8:
        printf("��ǰ�ķ�����%i,��Ӧ�ĵȼ���B", score);
        break;
    case 7:
        printf("��ǰ�ķ�����%i,��Ӧ�ĵȼ���C", score);
        break;
    case 6:
        printf("��ǰ�ķ�����%i,��Ӧ�ĵȼ���D", score);
        break;
    case 5:
//        printf("��ǰ�ķ�����%i,��Ӧ�ĵȼ���E", score);
//        break;
    case 4:
//        printf("��ǰ�ķ�����%i,��Ӧ�ĵȼ���E", score);
//        break;
    case 3:
//        printf("��ǰ�ķ�����%i,��Ӧ�ĵȼ���E", score);
//        break;
    case 2:
//        printf("��ǰ�ķ�����%i,��Ӧ�ĵȼ���E", score);
//        break;
    case 1:
//        printf("��ǰ�ķ�����%i,��Ӧ�ĵȼ���E", score);
//        break;
    case 0:
        printf("��ǰ�ķ�����%i,��Ӧ�ĵȼ���E", score);
        break;
    default:
        printf("û���������\n");
        break;
    }
    return 0;
}
