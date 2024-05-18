--COUNT 统计某一列或者表的总行数 （不统计NULL值）
--SELECT  COUNT(name)   姓名总行数   FROM Student
--SELECT  COUNT(*)   表总行数   FROM Student

--SUM 求某列（可求和）的总和
--SELECT  SUM(age) 年龄总和  FROM  Student

--AVG 求某列（可求和）的平均值
--SELECT  AVG(age)  平均年龄   FROM  Student

--MAX 求某列的最大值
SELECT  MAX(age)     最大年龄   FROM  Student
SELECT  MAX(name)  最大姓名   FROM  Student

--MIN 求某列的最小值
SELECT  MIN(age)     最小年龄   FROM  Student
SELECT  MIN(name)  最小姓名   FROM  Student