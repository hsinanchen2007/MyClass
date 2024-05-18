--T-SQL编程

/*
--存储过程,使用OUTPUT参数返回结果
CREATE  PROCEDURE  SP_Sum
@a  AS  int,
@b   int,
@sum   int  OUTPUT --传出结果
AS
BEGIN
SET  @sum = @a+@b
END


GO --分隔之后，前面执行失败，不影响后面的SQL执行


--如何调用存储过程
DECLARE  @sum int
EXECUTE   SP_Sum  111,222, @sum OUTPUT
PRINT   @sum


--存储过程，直接返回结果
CREATE  PROCEDURE  SP_Sum
@a  AS  int,
@b   int 
AS
BEGIN
DECLARE @sum int
SET  @sum = @a+@b
RETURN  @sum
END


GO --分隔之后，前面执行失败，不影响后面的SQL执行


--如何调用存储过程
DECLARE  @sum int
EXECUTE   @sum = SP_Sum  111,222  
PRINT  @sum



--存储过程，没有返回值
CREATE  PROCEDURE  SP_QueryStuById
@id  AS  int 
AS
BEGIN
IF @id IS NULL --判断参数是否为NULL
SELECT  *  FROM  Student 
ELSE
SELECT  *  FROM  Student  WHERE  id=@id
END

--调用存储过程
EXECUTE  SP_QueryStuById 1000  --查询单个学生
EXECUTE  SP_QueryStuById  NULL  --查询所有



 --删除存储过程 DDL
 DROP   PROCEDURE   SP_Sum
 DROP   PROCEDURE  SP_QueryStuById

 */

 --存储过程，没有返回值
CREATE  PROCEDURE  SP_QueryStuById_Encrypt
@id  AS  int 
WITH ENCRYPTION --加密的存储过程
AS
BEGIN
IF @id IS NULL --判断参数是否为NULL
SELECT  *  FROM  Student 
ELSE
SELECT  *  FROM  Student  WHERE  id=@id
END