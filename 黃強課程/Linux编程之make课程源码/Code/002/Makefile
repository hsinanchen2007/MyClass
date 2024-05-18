# 注释、生成app依赖于两个目标文件
app : main.o  fun.o   
	gcc    -o     app    fun.o    main.o

# 生成fun.o依赖于fun.c  fun.h
fun.o : fun.c  fun.h
	gcc    -c     fun.c

# 生成main.o依赖于main.c fun.h
main.o : main.c  fun.h
	gcc    -c    main.c
 
