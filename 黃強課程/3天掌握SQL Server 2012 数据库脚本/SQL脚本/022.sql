--LEN������ȡ�ַ����ĳ���
--SELECT  LEN(name) FROM  Student
--SELECT  LEN('12345678')

--LOWER �ַ�תСд
SELECT  LOWER('AbCDEF')

--UPPER �ַ�ת��д
--SELECT  UPPER('abcDEF')

--LEFT   ������ߵ�N���ַ�
--SELECT  LEFT('abcDEF',3)

--RIGHT   �����ұߵ�N���ַ�
--SELECT  RIGHT('abcDEF',3)

--SUBSTRING ��ȡ���ַ���
--SELECT  SUBSTRING('abcdef' , 2,3)

--CONVERT ת����������
SELECT  CONVERT(int ,1.234) --С��ת����
--SELECT   1.234+ 'abc' --����ֱ�Ӽ�
SELECT  CONVERT( nchar(5) ,1.234) + 'abc' --С��ת�ַ���

