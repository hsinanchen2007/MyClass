 #条件判断
 ifeq ($(CC), cc)
$(info CC is  cc !) 
endif
 
#与空判断
 ifeq ($(MAKEFLAGS),)
 $(info MAKEFLAGS  is Empty  !)
 endif

 #不等于判断 
N = 3
 ifeq   "$(N)"   '1'
$(info  num 1)
else   ifneq   '$(N)'    '2'
$(info  num  not  2)
else
$(info   other num!)
endif

#测试变量是否具有值
v=     
ifdef  $(v)
$(info   var has value )
else
$(info   var has no value )
endif

#目标
g: 	 
ifeq (hq,$(USER)) 
	${info   user is hq!  } 
else 
	${info    other user!  }
endif
