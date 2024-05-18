--创建一个学校数据库
--CREATE   DATABASE  School 


--在School库中创建学生表
USE     School  --指定当前数据库
CREATE   TABLE   Student
(
   id           int,--学号
   name     nchar(10),--姓名
   age       smallint, --年龄
   cardID   nchar(10)--身份证号
)

