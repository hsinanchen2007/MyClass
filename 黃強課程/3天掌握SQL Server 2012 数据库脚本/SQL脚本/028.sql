/*
--普通游标（只能向后移动）

--定义游标
DECLARE  cur  CURSOR  FOR  SELECT   name,age FROM   Student
--打开游标
OPEN  cur

DECLARE  @name nchar(10), @age int
--抓取一行数据,类似于读文件的每一行
FETCH NEXT FROM  cur  INTO   @name, @age
WHILE @@FETCH_STATUS =0 -- 0表示读取下一条数据成功
BEGIN
PRINT  @name + CONVERT(nchar(5),  @age) 
FETCH NEXT FROM  cur  INTO   @name, @age--继续向下一行移动游标
END

--关闭游标
CLOSE  cur
--释放游标
DEALLOCATE  cur
*/


--滚动游标（更灵活，只能向前后移动，并且还可以移动多行 ，非常类似于数组指针）

--定义滚动游标
DECLARE  cur  SCROLL CURSOR  FOR  SELECT   name,age FROM   Student
--打开游标
OPEN  cur

DECLARE  @name nchar(10), @age int
--抓取第一行数据 
FETCH  FIRST  FROM  cur  INTO  @name,@age
PRINT  '抓取第一行：'+@name + CONVERT(nchar(5),  @age) 
FETCH  LAST  FROM  cur  INTO  @name,@age
PRINT  '抓取末尾行：'+@name + CONVERT(nchar(5),  @age) 
FETCH  PRIOR FROM  cur  INTO  @name,@age
PRINT  '抓取当前行的前一行：'+@name + CONVERT(nchar(5),  @age) 
FETCH  RELATIVE  1  FROM  cur  INTO  @name,@age
PRINT  '抓取当前行距离为1的行：'+@name + CONVERT(nchar(5),  @age) 
FETCH  ABSOLUTE 2  FROM  cur  INTO  @name,@age
PRINT  '抓取第2行：'+@name + CONVERT(nchar(5),  @age) 

--关闭游标
CLOSE  cur
--释放游标
DEALLOCATE  cur