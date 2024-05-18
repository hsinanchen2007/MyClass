--      学生实体，班级实体      1：N关系
CREATE  TABLE  Class
(
id int   PRIMARY  KEY, --班级编号
name  nchar(10) --班级名称
)
 
CREATE  TABLE  Student
(
id int   PRIMARY  KEY, --学号
name  nchar(10) ,--姓名
age  smallint,--年龄
classId int --学生所在班级号 (关系合并到N端的实体)
)


--      老师实体，班级实体      1：1关系
CREATE  TABLE  Teacher
(
id int   PRIMARY  KEY, --老师编号
name  nchar(10) ,--老师姓名
classId int--管理的班级 (关系合并到任意一端的实体) 
)

--  学生实体，课程实体     M：N关系
CREATE  TABLE  Course
(
id int   PRIMARY  KEY, --课程编号
name  nchar(10) --课程名称
)
 
 CREATE  TABLE  StuScore
(
stuId     int   , --学号
courId   int   /*课程名称 */  PRIMARY KEY(stuId,courId), --复合主键
score    smallint --成绩
)


--  老师实体，课程实体     N：1关系
--  将关系合并到N端实体（PPT演示的）   或者   建立一张老师教课表
 CREATE  TABLE  TeaCou
(
teaId     int   PRIMARY KEY  , --老师编号
courId   int   --课程编号
)



---SQL语句的示例

--查询每个学生的班级与班主任老师
SELECT   s.name   学生姓名,  c.name  班级,  t.name 班主任   FROM   Student  s , Class  c , Teacher  t  
WHERE  ( s.classId =  c.id AND   c.id  = t.classId)

--查询每个学生的课程与成绩
SELECT   s.name   学生姓名,  c.name  课程,  ss.score 分数     FROM   Student  s , Course  c , StuScore  ss 
WHERE  ( s.id =  ss.stuId   AND   c.id  = ss.courId)

--查询每个老师负责的课程与管理的班级
SELECT   t.name   老师姓名,  co.name  课程,  c.name 管理的班级     FROM   Teacher  t , Course  co , Class  c
WHERE  ( t.classId =  c.id   AND   t.courId  = co.Id)


