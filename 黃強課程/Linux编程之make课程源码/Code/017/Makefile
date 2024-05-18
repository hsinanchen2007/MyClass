#目标
main:  main.o  a.o   b.o c.o

 #模式规则
%.o: %.c   
	@echo  模式规则111
	gcc -c   $(CFLAGS)  $<

#模式规则
%: %.o  
	@echo  模式规则222
	gcc     $^ $(LDFLAGS)   -o  $@
	
#清理
clean: 
	$(RM)  main   main.o a.o b.o c.o
 
