/*
--��ͨ�αֻ꣨������ƶ���

--�����α�
DECLARE  cur  CURSOR  FOR  SELECT   name,age FROM   Student
--���α�
OPEN  cur

DECLARE  @name nchar(10), @age int
--ץȡһ������,�����ڶ��ļ���ÿһ��
FETCH NEXT FROM  cur  INTO   @name, @age
WHILE @@FETCH_STATUS =0 -- 0��ʾ��ȡ��һ�����ݳɹ�
BEGIN
PRINT  @name + CONVERT(nchar(5),  @age) 
FETCH NEXT FROM  cur  INTO   @name, @age--��������һ���ƶ��α�
END

--�ر��α�
CLOSE  cur
--�ͷ��α�
DEALLOCATE  cur
*/


--�����α꣨����ֻ����ǰ���ƶ������һ������ƶ����� ���ǳ�����������ָ�룩

--��������α�
DECLARE  cur  SCROLL CURSOR  FOR  SELECT   name,age FROM   Student
--���α�
OPEN  cur

DECLARE  @name nchar(10), @age int
--ץȡ��һ������ 
FETCH  FIRST  FROM  cur  INTO  @name,@age
PRINT  'ץȡ��һ�У�'+@name + CONVERT(nchar(5),  @age) 
FETCH  LAST  FROM  cur  INTO  @name,@age
PRINT  'ץȡĩβ�У�'+@name + CONVERT(nchar(5),  @age) 
FETCH  PRIOR FROM  cur  INTO  @name,@age
PRINT  'ץȡ��ǰ�е�ǰһ�У�'+@name + CONVERT(nchar(5),  @age) 
FETCH  RELATIVE  1  FROM  cur  INTO  @name,@age
PRINT  'ץȡ��ǰ�о���Ϊ1���У�'+@name + CONVERT(nchar(5),  @age) 
FETCH  ABSOLUTE 2  FROM  cur  INTO  @name,@age
PRINT  'ץȡ��2�У�'+@name + CONVERT(nchar(5),  @age) 

--�ر��α�
CLOSE  cur
--�ͷ��α�
DEALLOCATE  cur