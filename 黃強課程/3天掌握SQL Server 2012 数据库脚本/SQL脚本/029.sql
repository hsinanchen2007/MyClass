/*
SET   XACT_ABORT  ON  --����ع���������

--��ʼһ������
BEGIN  TRANSACTION  t

INSERT INTO  Score     VALUES( 1000, '����' , 90)
INSERT INTO  Student  VALUES(1000, '�ܰ�' ,17,'420005') --һ���������в�ִ�гɹ�
 
--�ύ����
COMMIT  TRANSACTION t


---------------------------------------------------------------------------------

SET   XACT_ABORT  OFF  --����ع���������
BEGIN TRY

--��ʼһ������
BEGIN  TRANSACTION  t
INSERT INTO  Score     VALUES( 1000, '����' , 90)
INSERT INTO  Student  VALUES(1000, '�ܰ�' ,17,'420005') --�����쳣
--�ύ����
COMMIT  TRANSACTION t

END  TRY
BEGIN  CATCH

PRINT  '��׽���쳣��'
ROLLBACK  TRANSACTION t--�ع�����

END  CATCH

*/

 
--��ʼһ������
BEGIN  TRANSACTION  t
INSERT INTO  Score     VALUES( 1005, '����' , 90)
SAVE    TRANSACTION  st  --����һ�������
INSERT INTO  Student  VALUES(1005, '�ܰ�' ,17,'420005') 
 
ROLLBACK  TRANSACTION st--�ع�������� 
 
