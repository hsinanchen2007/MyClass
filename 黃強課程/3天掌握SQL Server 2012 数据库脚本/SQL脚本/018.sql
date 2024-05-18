--SELECT  *  FROM  Student  

--想显示中文的列名(为列增加了一个别名)
--SELECT  id 学号,  name   AS  姓名,  age 年龄 , cardID AS 身份证号码  FROM  Student  


--为表取别名
SELECT  学生表.id ,    学生表.name  FROM   Student  学生表
SELECT  s.id ,    s.name  FROM   Student  AS  s  --将表名简化，在多表查询时，更简洁