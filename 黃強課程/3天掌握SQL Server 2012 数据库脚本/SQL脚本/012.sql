
-- DML 插入一条学生数据 ，按列名的默认顺序 
--INSERT  INTO   Student  VALUES(1001,'张三',14,'420001')

--插入一条学生数据，指定列名顺序
INSERT  INTO   Student(cardID, age, id, name) 
VALUES('420002', 15,1002,'李四')
