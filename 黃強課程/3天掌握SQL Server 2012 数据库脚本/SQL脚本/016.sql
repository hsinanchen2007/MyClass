--查询所有学生年龄在IN中的学生信息
--SELECT *   FROM  Student  
--WHERE   age  IN(14,15,16,18,19)

--查询所有学生年龄在BETWEEN中间的学生信息
--SELECT *   FROM  Student  
--WHERE   age  BETWEEN   13 AND 16   -- 等价于 WHERE  age>=13 AND  age <=16

--模糊查询 LIKE
--%表示通配一个或多个字符
--SELECT *   FROM  Student  WHERE name LIKE  '%王五%' --只要包含王五即可
--SELECT *   FROM  Student  WHERE name LIKE  '王五%' --必须王五开头的姓名
--SELECT *   FROM  Student  WHERE name LIKE  '%王五' --必须王五结尾的姓名

--  _代替一个字符
SELECT *   FROM  Student  WHERE name LIKE  '_王五' -- 以王五结尾，头部必须有一个字符
--  [] 包含其中的字符 [^] 不包含其中的字符 
SELECT *   FROM  Student  WHERE name LIKE  '[张小]%' -- 包含张字符的姓名
SELECT *   FROM  Student  WHERE name LIKE  '[^张王]%' -- 不包含张字符的姓名