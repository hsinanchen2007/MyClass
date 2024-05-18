--内连接的写法一
/*
SELECT  *   FROM  Student INNER JOIN SCORE
ON  Student.id = Score.studentID

--使用表的别名简写
SELECT  *   FROM  Student   st  INNER JOIN SCORE   sc
ON  st.id = sc.studentID
*/

--内连接的写法二（INNER可以省略）
SELECT  *   FROM  Student  JOIN SCORE
ON  Student.id = Score.studentID

--内连接的写法三（隐式）
SELECT  *   FROM  Student  , SCORE
WHERE  Student.id = Score.studentID

-- 写法四（交叉连接 ）
SELECT  *   FROM  Student  CROSS JOIN SCORE
WHERE  Student.id = Score.studentID