/*
--����������ʱ���봴����ͨ��һ����ֻ����Ҫ�ڱ���ǰ�����#��
CREATE  TABLE  #TempStu
(
  name  nchar(10),
  age    int
)

--����ʱ���������
INSERT  INTO  #TempStu   VALUES('����',12)
INSERT  INTO  #TempStu   VALUES('����',13)

--��ѯ��ʱ��
SELECT   *   FROM   #TempStu

--ɾ����ʱ��
DROP  TABLE   #TempStu
*/


--����ȫ����ʱ���봴����ͨ��һ����ֻ����Ҫ�ڱ���ǰ�����##��
CREATE  TABLE  ##TempStu
(
  name  nchar(10),
  age    int
)

--����ʱ���������
INSERT  INTO  ##TempStu   VALUES('����',12)
INSERT  INTO  ##TempStu   VALUES('����',13)

--��ѯ��ʱ��
SELECT   *   FROM   ##TempStu

--ɾ����ʱ��
DROP  TABLE   ##TempStu






