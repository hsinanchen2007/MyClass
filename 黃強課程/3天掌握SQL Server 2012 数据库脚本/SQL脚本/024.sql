--IF���
DECLARE   @i  int  
SET  @i = 20

/*
IF  @i>10
PRINT    CONVERT(nchar(5),@i) +'����10'
 
 IF  @i>30
BEGIN  --һ�����飬�൱��c�����е�{}
PRINT    CONVERT(nchar(5),@i) +'����30'
PRINT    CONVERT(nchar(5),@i) +'����30'
END




SET  @i = 5
IF  @i>10
PRINT    CONVERT(nchar(5),@i) +'����10'
ELSE IF @i>5
PRINT    CONVERT(nchar(5),@i) +'����5��С�ڵ���10'
ELSE 
PRINT    CONVERT(nchar(5),@i) +'С�ڵ���5'

*/


--WHILE���
SET  @i = 0
WHILE  @i<5
BEGIN
SET @i= @i+1  --����SELECT  @i=@i+1
PRINT  @i
END
