#特殊目标
.SECONDEXPANSION:

ONE = onefile
TWO = twofile
  
a: $(ONE)  $$(TWO)
	echo  $^

#注意以下的区别
b: $(ONE)  $($(TWO))
	echo  $^


onefile:  
	@echo 1  

twofile:
	@echo 2