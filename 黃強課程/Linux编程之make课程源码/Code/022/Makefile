a = hi

# 递归扩展变量赋值 ，延迟展开
b = $(a) boy

#简单扩展变量赋值  ， 立即展开
c:= $(a) boy
 
a = hello 
  
#目标
g1: 
	@ echo   $(a),$(b),$(c)    