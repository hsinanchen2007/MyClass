--外连接（OUTER JOIN）

/*
--左外连接（左表数据全部保留，如果右表没有匹配的补NULL）
SELECT  * FROM  Student  LEFT OUTER JOIN  Score
ON  Student.id = Score.studentID
--OUTER可以省略
SELECT  * FROM  Student  LEFT  JOIN  Score
ON  Student.id = Score.studentID


--右外连接（右表数据全部保留，如果左表没有匹配的补NULL）
SELECT  * FROM  Student  RIGHT OUTER JOIN  Score
ON  Student.id = Score.studentID
--OUTER可以省略
SELECT  * FROM  Student  RIGHT  JOIN  Score
ON  Student.id = Score.studentID

*/

--全外连接（两边的数据都显示，如果某一边表没有匹配的，那么补NULL）
SELECT  * FROM  Student  FULL  OUTER JOIN  Score
ON  Student.id = Score.studentID
--OUTER可以省略
SELECT  * FROM  Student  FULL  JOIN  Score
ON  Student.id = Score.studentID
