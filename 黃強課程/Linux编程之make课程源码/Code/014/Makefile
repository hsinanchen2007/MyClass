#目标
app:  main.o a.o b.o c.o	 
	gcc -o $@   $^
	  
#静态模式规则
 main.o a.o b.o c.o: %.o: %.c    %.h 
	@echo  先决条件 $^
	@echo  目标 $@
	gcc -c   $<


#清理
clean: 
	rm app main.o a.o b.o c.o
 
