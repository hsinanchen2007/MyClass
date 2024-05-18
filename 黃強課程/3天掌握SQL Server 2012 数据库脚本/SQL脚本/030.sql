SELECT   *   FROM  Student  WHERE  SUBSTRING( info,0,3)='张三'  --不符合1NF，查询很麻烦
SELECT   *   FROM  Student  WHERE  SUBSTRING( info,4,3)='13'  --不符合1NF，查询很麻烦


--不符合2NF ，存在数据冗余

--不符合3NF，数据变更后修改很麻烦