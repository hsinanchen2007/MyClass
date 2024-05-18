#变量
reverse = $(2) $(1)
${info $(reverse)}

#调用变量
a= $(call reverse,AA,BB)
${info $(a)}
 
 
#多行变量
define  print
@echo $(1)
@echo $(2)
endef
 
#目标
g: 	 
	$(call   print,CC,DD)