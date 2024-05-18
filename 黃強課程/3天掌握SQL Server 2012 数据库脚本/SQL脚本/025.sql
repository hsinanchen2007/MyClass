--T-SQL编程

/*
--标量值函数
CREATE  FUNCTION  MySum(@a  int, @b int)
RETURNS  int AS
BEGIN
     DECLARE  @c int
	 SET  @c = @a+@b
	 return @c
END

--调用函数
PRINT  dbo.MySum(111,222)


--内联表值函数
CREATE  FUNCTION  GetStudentInfo(@id  int)
RETURNS  TABLE
AS
RETURN (SELECT  *  FROM  Student WHERE  id= @id)

--调用内联表值函数
SELECT  *  FROM   dbo.GetStudentInfo(1000)


--多声明表值函数
CREATE  FUNCTION  GetStudentSimple(@id  int)
RETURNS   @StuInfo  TABLE(name nchar(10) ,age int)--自己自定义一张表
AS
BEGIN 
DECLARE  @name nchar(10)
DECLARE  @age   int
--查询出学生信息
SELECT  @name=name ,@age= age   FROM  Student WHERE  id= @id
--将学生信息插入到定义的新表中
INSERT INTO  @StuInfo VALUES(@name,@age)
RETURN
END

--调用多声明的表值函数
SELECT  *  FROM   dbo.GetStudentSimple(1000)
*/


--删除函数，DDL
DROP  FUNCTION   MySum
DROP  FUNCTION   GetStudentInfo
DROP  FUNCTION   GetStudentSimple
 