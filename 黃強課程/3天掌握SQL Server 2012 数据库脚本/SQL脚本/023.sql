--T-SQL是SQL的增强版，适用于 SQL  Server数据库

/*
--定义两个局部变量，@开头
DECLARE  @age AS  int = 12,  @name nchar(10)

--为局部变量赋值
SELECT  @name ='张三'

SET @age = 13

--打印变量值
SELECT    @age    --在结果窗口显示
PRINT     @name  --在消息窗口显示
*/


--全局变量（一般由系统定义）
SELECT  @@LANGUAGE  --系统语言
SELECT  @@SERVERNAME  --服务器计算机的名称
SELECT  @@ERROR  --错误码
SELECT  @@IDENTITY   --自增值
SELECT  @@VERSION   --数据库服务器的版本
