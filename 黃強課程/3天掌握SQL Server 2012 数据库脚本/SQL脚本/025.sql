--T-SQL���

/*
--����ֵ����
CREATE  FUNCTION  MySum(@a  int, @b int)
RETURNS  int AS
BEGIN
     DECLARE  @c int
	 SET  @c = @a+@b
	 return @c
END

--���ú���
PRINT  dbo.MySum(111,222)


--������ֵ����
CREATE  FUNCTION  GetStudentInfo(@id  int)
RETURNS  TABLE
AS
RETURN (SELECT  *  FROM  Student WHERE  id= @id)

--����������ֵ����
SELECT  *  FROM   dbo.GetStudentInfo(1000)


--��������ֵ����
CREATE  FUNCTION  GetStudentSimple(@id  int)
RETURNS   @StuInfo  TABLE(name nchar(10) ,age int)--�Լ��Զ���һ�ű�
AS
BEGIN 
DECLARE  @name nchar(10)
DECLARE  @age   int
--��ѯ��ѧ����Ϣ
SELECT  @name=name ,@age= age   FROM  Student WHERE  id= @id
--��ѧ����Ϣ���뵽������±���
INSERT INTO  @StuInfo VALUES(@name,@age)
RETURN
END

--���ö������ı�ֵ����
SELECT  *  FROM   dbo.GetStudentSimple(1000)
*/


--ɾ��������DDL
DROP  FUNCTION   MySum
DROP  FUNCTION   GetStudentInfo
DROP  FUNCTION   GetStudentSimple
 