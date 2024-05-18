#export将变量传递给子make进程
export  x=hello

#目标
a:  
	@echo  第${MAKELEVEL}层目录${CURDIR}   
	@echo  选项${MAKEFLAGS}   
	cd dir &&  $(MAKE)
