#变量
src  = a.c    b.c   c.c  
#替换
header =  $(src:c=h )
obj = ${src:.c=.o } 
bin = $(src:.c= ) 

a:
	@echo  源文件     $(src)
	@echo  头文件     $(header)
	@echo  目标文件 $(obj) 
	@echo  去后缀     $(bin)  



b:	
	@echo  ${patsubst %c,  %h,    $(src)  }  
	@echo  $(patsubst %.c,  %.o,    $(src)   )
	@echo  ${patsubst %.c,  % ,    ${src}  } 
 