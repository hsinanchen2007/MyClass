#目标
# app:  main.o a.o b.o c.o   
# 	gcc -o  $@   $^

 #目标名指定为先决条件中的任何一个，配方无需写
c: main.o a.o b.o c.o 

#清理
clean: 
	rm  app main.o a.o b.o c.o 