--      ѧ��ʵ�壬�༶ʵ��      1��N��ϵ
CREATE  TABLE  Class
(
id int   PRIMARY  KEY, --�༶���
name  nchar(10) --�༶����
)
 
CREATE  TABLE  Student
(
id int   PRIMARY  KEY, --ѧ��
name  nchar(10) ,--����
age  smallint,--����
classId int --ѧ�����ڰ༶�� (��ϵ�ϲ���N�˵�ʵ��)
)


--      ��ʦʵ�壬�༶ʵ��      1��1��ϵ
CREATE  TABLE  Teacher
(
id int   PRIMARY  KEY, --��ʦ���
name  nchar(10) ,--��ʦ����
classId int--����İ༶ (��ϵ�ϲ�������һ�˵�ʵ��) 
)

--  ѧ��ʵ�壬�γ�ʵ��     M��N��ϵ
CREATE  TABLE  Course
(
id int   PRIMARY  KEY, --�γ̱��
name  nchar(10) --�γ�����
)
 
 CREATE  TABLE  StuScore
(
stuId     int   , --ѧ��
courId   int   /*�γ����� */  PRIMARY KEY(stuId,courId), --��������
score    smallint --�ɼ�
)


--  ��ʦʵ�壬�γ�ʵ��     N��1��ϵ
--  ����ϵ�ϲ���N��ʵ�壨PPT��ʾ�ģ�   ����   ����һ����ʦ�̿α�
 CREATE  TABLE  TeaCou
(
teaId     int   PRIMARY KEY  , --��ʦ���
courId   int   --�γ̱��
)



---SQL����ʾ��

--��ѯÿ��ѧ���İ༶���������ʦ
SELECT   s.name   ѧ������,  c.name  �༶,  t.name ������   FROM   Student  s , Class  c , Teacher  t  
WHERE  ( s.classId =  c.id AND   c.id  = t.classId)

--��ѯÿ��ѧ���Ŀγ���ɼ�
SELECT   s.name   ѧ������,  c.name  �γ�,  ss.score ����     FROM   Student  s , Course  c , StuScore  ss 
WHERE  ( s.id =  ss.stuId   AND   c.id  = ss.courId)

--��ѯÿ����ʦ����Ŀγ������İ༶
SELECT   t.name   ��ʦ����,  co.name  �γ�,  c.name ����İ༶     FROM   Teacher  t , Course  co , Class  c
WHERE  ( t.classId =  c.id   AND   t.courId  = co.Id)


