--LEN函数获取字符串的长度
--SELECT  LEN(name) FROM  Student
--SELECT  LEN('12345678')

--LOWER 字符转小写
SELECT  LOWER('AbCDEF')

--UPPER 字符转大写
--SELECT  UPPER('abcDEF')

--LEFT   返回左边的N个字符
--SELECT  LEFT('abcDEF',3)

--RIGHT   返回右边的N个字符
--SELECT  RIGHT('abcDEF',3)

--SUBSTRING 截取子字符串
--SELECT  SUBSTRING('abcdef' , 2,3)

--CONVERT 转换数据类型
SELECT  CONVERT(int ,1.234) --小数转整数
--SELECT   1.234+ 'abc' --不能直接加
SELECT  CONVERT( nchar(5) ,1.234) + 'abc' --小数转字符串

