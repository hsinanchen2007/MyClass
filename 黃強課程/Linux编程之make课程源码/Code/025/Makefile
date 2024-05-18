#字符串输出函数
${info      this info  !}
${warning    this warn ! } 
#${error     this error !  } 

#去除后缀
a = $(basename  a/b/foo.c      a/b    a.h )
${info    ${a} } 

#字符串替换
b = $(subst   o,x,Hello world  )
${info    ${b} } 

#模式替换
c =$(patsubst %.c,%.o, foo.c.c  bar.c )
${info    ${c} } 


#去除两边空格，压缩中间空格
d = ${strip         a       b     c          } 
${info    ${d} } 

#查找字符串 
e = ${findstring a,   he is a boy   } 
${info    ${e} } 



#过滤符合模式的字符串 
f = $(filter  %.c %.s , foo.c   bar.c   foo.s   bar.h )
${info    ${f} } 

#排序字符串
h = $(sort   foo  b   z  z  an  )
${info    ${h} } 

#查找与 shell通配符 匹配的文件名 
i=  $(wildcard    ../016/*.txt )  
${info    ${i} } 

#返回字符串的第 2个单词 
j=  $(word   2,aa bb cc dd   )  
${info    ${j} } 




#目标
t: 