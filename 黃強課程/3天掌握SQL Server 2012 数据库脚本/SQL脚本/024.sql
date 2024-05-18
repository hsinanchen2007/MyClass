--IF语句
DECLARE   @i  int  
SET  @i = 20

/*
IF  @i>10
PRINT    CONVERT(nchar(5),@i) +'大于10'
 
 IF  @i>30
BEGIN  --一个语句块，相当于c语言中的{}
PRINT    CONVERT(nchar(5),@i) +'大于30'
PRINT    CONVERT(nchar(5),@i) +'大于30'
END




SET  @i = 5
IF  @i>10
PRINT    CONVERT(nchar(5),@i) +'大于10'
ELSE IF @i>5
PRINT    CONVERT(nchar(5),@i) +'大于5，小于等于10'
ELSE 
PRINT    CONVERT(nchar(5),@i) +'小于等于5'

*/


--WHILE语句
SET  @i = 0
WHILE  @i<5
BEGIN
SET @i= @i+1  --或者SELECT  @i=@i+1
PRINT  @i
END
