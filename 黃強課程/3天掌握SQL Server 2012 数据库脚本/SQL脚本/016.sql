--��ѯ����ѧ��������IN�е�ѧ����Ϣ
--SELECT *   FROM  Student  
--WHERE   age  IN(14,15,16,18,19)

--��ѯ����ѧ��������BETWEEN�м��ѧ����Ϣ
--SELECT *   FROM  Student  
--WHERE   age  BETWEEN   13 AND 16   -- �ȼ��� WHERE  age>=13 AND  age <=16

--ģ����ѯ LIKE
--%��ʾͨ��һ�������ַ�
--SELECT *   FROM  Student  WHERE name LIKE  '%����%' --ֻҪ�������弴��
--SELECT *   FROM  Student  WHERE name LIKE  '����%' --�������忪ͷ������
--SELECT *   FROM  Student  WHERE name LIKE  '%����' --���������β������

--  _����һ���ַ�
SELECT *   FROM  Student  WHERE name LIKE  '_����' -- �������β��ͷ��������һ���ַ�
--  [] �������е��ַ� [^] ���������е��ַ� 
SELECT *   FROM  Student  WHERE name LIKE  '[��С]%' -- �������ַ�������
SELECT *   FROM  Student  WHERE name LIKE  '[^����]%' -- ���������ַ�������