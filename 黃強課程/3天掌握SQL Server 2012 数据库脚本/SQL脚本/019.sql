--�����ӵ�д��һ
/*
SELECT  *   FROM  Student INNER JOIN SCORE
ON  Student.id = Score.studentID

--ʹ�ñ�ı�����д
SELECT  *   FROM  Student   st  INNER JOIN SCORE   sc
ON  st.id = sc.studentID
*/

--�����ӵ�д������INNER����ʡ�ԣ�
SELECT  *   FROM  Student  JOIN SCORE
ON  Student.id = Score.studentID

--�����ӵ�д��������ʽ��
SELECT  *   FROM  Student  , SCORE
WHERE  Student.id = Score.studentID

-- д���ģ��������� ��
SELECT  *   FROM  Student  CROSS JOIN SCORE
WHERE  Student.id = Score.studentID