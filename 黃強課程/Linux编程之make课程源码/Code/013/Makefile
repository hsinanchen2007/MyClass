#目标
app:  main.o a.o b.o c.o
	@echo 目标是$@ 
	@echo 所有先决条件$^
	@echo 第一个先决条件$<	
	@echo 比目标新的先决条件$?	 
	gcc -o $@   $^
	  
main.o: main.c    main.h   
	gcc -c $<

a.o: a.c  a.h
	gcc -c $< 
  
b.o: b.c  b.h
	gcc -c $<  

c.o: c.c  c.h
	gcc -c $< 

#清理
clean: 
	rm app main.o a.o b.o c.o
 