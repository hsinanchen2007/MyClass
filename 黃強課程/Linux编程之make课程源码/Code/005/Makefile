#目标
a: a.c
	gcc  -c    a.c
	gcc  a.o   -o  a
  
  
#显式声明该目标是虚假的
.PHONY: clean  

#目标，用来执行清理工作
clean :
	rm  -rf  a.o
	rm  -rf  a  

 
 