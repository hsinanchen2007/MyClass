--查询的数据进行排序
--SELECT  *   FROM   Student  ORDER BY  age ASC  --升序
--SELECT  *   FROM   Student  ORDER BY  age DESC  --降序

--查询学生中年龄最大的2位学生
--SELECT   TOP  2   *   FROM   Student  ORDER BY  age DESC  --降序

--查询所有的学生姓名
SELECT  name   FROM   Student

--去除重复姓名（只保留一个，在统计的时候非常有用）
SELECT  DISTINCT   name   FROM   Student