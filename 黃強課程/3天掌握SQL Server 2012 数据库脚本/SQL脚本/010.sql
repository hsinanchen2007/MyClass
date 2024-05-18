-- 更改表结构，为学生表增加一个性别字段
/*
ALTER  TABLE  Student
ADD  sex   nchar(1)


-- 更改表结构，为学生表删除一个性别字段
ALTER  TABLE  Student
DROP  COLUMN   sex 
*/

-- 更改表结构， 学生表的年龄字段的类型改变为tinyint
ALTER  TABLE  Student
ALTER  COLUMN  age  tinyint

