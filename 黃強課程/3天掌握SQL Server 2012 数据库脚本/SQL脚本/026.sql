--T-SQL���

/*
--�洢����,ʹ��OUTPUT�������ؽ��
CREATE  PROCEDURE  SP_Sum
@a  AS  int,
@b   int,
@sum   int  OUTPUT --�������
AS
BEGIN
SET  @sum = @a+@b
END


GO --�ָ�֮��ǰ��ִ��ʧ�ܣ���Ӱ������SQLִ��


--��ε��ô洢����
DECLARE  @sum int
EXECUTE   SP_Sum  111,222, @sum OUTPUT
PRINT   @sum


--�洢���̣�ֱ�ӷ��ؽ��
CREATE  PROCEDURE  SP_Sum
@a  AS  int,
@b   int 
AS
BEGIN
DECLARE @sum int
SET  @sum = @a+@b
RETURN  @sum
END


GO --�ָ�֮��ǰ��ִ��ʧ�ܣ���Ӱ������SQLִ��


--��ε��ô洢����
DECLARE  @sum int
EXECUTE   @sum = SP_Sum  111,222  
PRINT  @sum



--�洢���̣�û�з���ֵ
CREATE  PROCEDURE  SP_QueryStuById
@id  AS  int 
AS
BEGIN
IF @id IS NULL --�жϲ����Ƿ�ΪNULL
SELECT  *  FROM  Student 
ELSE
SELECT  *  FROM  Student  WHERE  id=@id
END

--���ô洢����
EXECUTE  SP_QueryStuById 1000  --��ѯ����ѧ��
EXECUTE  SP_QueryStuById  NULL  --��ѯ����



 --ɾ���洢���� DDL
 DROP   PROCEDURE   SP_Sum
 DROP   PROCEDURE  SP_QueryStuById

 */

 --�洢���̣�û�з���ֵ
CREATE  PROCEDURE  SP_QueryStuById_Encrypt
@id  AS  int 
WITH ENCRYPTION --���ܵĴ洢����
AS
BEGIN
IF @id IS NULL --�жϲ����Ƿ�ΪNULL
SELECT  *  FROM  Student 
ELSE
SELECT  *  FROM  Student  WHERE  id=@id
END