--T-SQL��SQL����ǿ�棬������ SQL  Server���ݿ�

/*
--���������ֲ�������@��ͷ
DECLARE  @age AS  int = 12,  @name nchar(10)

--Ϊ�ֲ�������ֵ
SELECT  @name ='����'

SET @age = 13

--��ӡ����ֵ
SELECT    @age    --�ڽ��������ʾ
PRINT     @name  --����Ϣ������ʾ
*/


--ȫ�ֱ�����һ����ϵͳ���壩
SELECT  @@LANGUAGE  --ϵͳ����
SELECT  @@SERVERNAME  --�����������������
SELECT  @@ERROR  --������
SELECT  @@IDENTITY   --����ֵ
SELECT  @@VERSION   --���ݿ�������İ汾
