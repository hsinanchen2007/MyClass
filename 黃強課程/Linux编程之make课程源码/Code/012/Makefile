#定义变量
obj = main.o a.o b.o c.o


#目标
app:   $(obj)
	gcc -o app  $(obj)

main.o: main.c   main.h
	gcc -c main.c  

a.o: a.c  a.h
	gcc -c a.c  
  
b.o: b.c  b.h
	gcc -c b.c  

c.o: c.c  c.h
	gcc -c c.c  

#清理
clean: 
	rm    app   $(obj)