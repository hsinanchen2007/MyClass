-- 查询学生表中的所有数据  DML
--SELECT  *  FROM  Student

--查询学生指定列(姓名、年龄)的信息
--SELECT  name,age   FROM   Student

----根据条件查询学生的信息
--比较运算符
--SELECT  * FROM  Student  WHERE  name='张三'   --等于
--SELECT  * FROM  Student  WHERE  name!='张三'  --不等于
--SELECT  * FROM  Student  WHERE   age>=16      --大于等于

--逻辑运算符
SELECT  * FROM  Student  WHERE  name='张三'  AND  age=17  --且
SELECT  * FROM  Student  WHERE  name='张三'  OR  age=17  --或
