x = X
y = Y
z = Z

#条件判断
 a =  $(if  $x  ,x非空)   
 b  = $(if  $x  ,x非空,x是空的) 
${info   $a , $b    }


#或   全空则返回空，否则返回第一个非空
c = $(or   $x ,$y , $z)
#且  有一个空则返回空，否则返回最后一个
d =  $(and   $x ,$y , $z)
${info  或 $c    ， 且 $d  }


#循环
str := A B  C  D
e  = $(foreach     s,$(str),hi $(s)!) 
${info $e  }

#目标
g: 	  
 
