/*   �{���W�� : ch79.c                    */
/*   �ϥ� extern �w�q�~�b�ܼ�             */
int f(int i)
{
    extern int v;  /* �ŧi extern �~�b�ܼ�  */ 
    return ( v + i + 1 );
}
