/*
SET   XACT_ABORT  ON  --出错回滚整个事务

--开始一个事务
BEGIN  TRANSACTION  t

INSERT INTO  Score     VALUES( 1000, '语文' , 90)
INSERT INTO  Student  VALUES(1000, '周八' ,17,'420005') --一个出错，所有不执行成功
 
--提交事务
COMMIT  TRANSACTION t


---------------------------------------------------------------------------------

SET   XACT_ABORT  OFF  --出错回滚整个事务
BEGIN TRY

--开始一个事务
BEGIN  TRANSACTION  t
INSERT INTO  Score     VALUES( 1000, '语文' , 90)
INSERT INTO  Student  VALUES(1000, '周八' ,17,'420005') --触发异常
--提交事务
COMMIT  TRANSACTION t

END  TRY
BEGIN  CATCH

PRINT  '捕捉到异常！'
ROLLBACK  TRANSACTION t--回滚事务

END  CATCH

*/

 
--开始一个事务
BEGIN  TRANSACTION  t
INSERT INTO  Score     VALUES( 1005, '语文' , 90)
SAVE    TRANSACTION  st  --设置一个保存点
INSERT INTO  Student  VALUES(1005, '周八' ,17,'420005') 
 
ROLLBACK  TRANSACTION st--回滚到保存点 
 
