#VPATH = src:header

vpath   %.c    src
vpath   %.h    header


# 目标
app : main.o  fun.o   
	gcc    -o     app    fun.o    main.o

# 目标
fun.o : fun.c  fun.h
	gcc    -c     src/fun.c  -Iheader

# 目标
main.o : main.c  fun.h
	gcc    -c     src/main.c  -Iheader
 
# 清理
clean:
	$(RM)   *.o    app
 
