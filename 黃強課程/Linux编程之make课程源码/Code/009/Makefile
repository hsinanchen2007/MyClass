a = hi
#递归扩展变量赋值
b = $(a) boy
#简单扩展变量赋值
c:= $(a) boy
#改变a的值
a = hello 
 
    
#目标
g1: 
	@ echo   $(a),$(b),$(c)   

 
#条件变量赋值运算符
#d = bad
d ?= good 

e = welcome to 
#向变量添加值
e +=  my  house
#目标
g2:  
	@ echo   $(d)
	@ echo   $(e) 


#变量赋多行值
define   f 
@echo  AAA
@echo  BBB
endef
 
#目标
g3:  
	$(f)  