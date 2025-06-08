/*   程式名稱 : ch79.c                    */
/*   使用 extern 定義外在變數             */
int f(int i)
{
    extern int v;  /* 宣告 extern 外在變數  */ 
    return ( v + i + 1 );
}
