--�����ӣ�OUTER JOIN��

/*
--�������ӣ��������ȫ������������ұ�û��ƥ��Ĳ�NULL��
SELECT  * FROM  Student  LEFT OUTER JOIN  Score
ON  Student.id = Score.studentID
--OUTER����ʡ��
SELECT  * FROM  Student  LEFT  JOIN  Score
ON  Student.id = Score.studentID


--�������ӣ��ұ�����ȫ��������������û��ƥ��Ĳ�NULL��
SELECT  * FROM  Student  RIGHT OUTER JOIN  Score
ON  Student.id = Score.studentID
--OUTER����ʡ��
SELECT  * FROM  Student  RIGHT  JOIN  Score
ON  Student.id = Score.studentID

*/

--ȫ�����ӣ����ߵ����ݶ���ʾ�����ĳһ�߱�û��ƥ��ģ���ô��NULL��
SELECT  * FROM  Student  FULL  OUTER JOIN  Score
ON  Student.id = Score.studentID
--OUTER����ʡ��
SELECT  * FROM  Student  FULL  JOIN  Score
ON  Student.id = Score.studentID
