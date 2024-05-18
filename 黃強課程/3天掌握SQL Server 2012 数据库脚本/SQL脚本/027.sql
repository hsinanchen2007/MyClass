/*
--创建本地临时表（与创建普通表一样，只是需要在表名前面加上#）
CREATE  TABLE  #TempStu
(
  name  nchar(10),
  age    int
)

--向临时表插入数据
INSERT  INTO  #TempStu   VALUES('张三',12)
INSERT  INTO  #TempStu   VALUES('李四',13)

--查询临时表
SELECT   *   FROM   #TempStu

--删除临时表
DROP  TABLE   #TempStu
*/


--创建全局临时表（与创建普通表一样，只是需要在表名前面加上##）
CREATE  TABLE  ##TempStu
(
  name  nchar(10),
  age    int
)

--向临时表插入数据
INSERT  INTO  ##TempStu   VALUES('张三',12)
INSERT  INTO  ##TempStu   VALUES('李四',13)

--查询临时表
SELECT   *   FROM   ##TempStu

--删除临时表
DROP  TABLE   ##TempStu






