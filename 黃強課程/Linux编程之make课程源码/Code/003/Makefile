#第一个目标
a: a.c  
	gcc  a.c   -o a
 
#第二个目标
b: b.c
	gcc  b.c   -o b 
	
#第三个目标
c: c.c
	gcc  c.c   -o c 
 
 #设置默认目标
.DEFAULT_GOAL = c 
 

# 第四个目标 
d : a  b   
#执行echo命令
	echo  hello

#同名目标、保留先决条件，覆盖命令
d : c  	  
	echo  bye
