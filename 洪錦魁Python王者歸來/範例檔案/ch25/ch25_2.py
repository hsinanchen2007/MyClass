# ch25_2.py
from twilio.rest import Client

# 你從twilio.com申請的帳號
accountSid='AC308f91e9db748a59538feb0l74ed623a'
# 你從twilio.com獲得的圖騰
authToken='f513161b53f21720f64118e4443c85ac'

client = Client(accountSid, authToken)
message = client.messages.create (
            from_ = "+15052073368",         # 這是twilio.com給你的號碼
            to = "+886952xxxxxx",           # 這是收簡訊方的號碼
            body = "Python王者歸來" )       # 發送的訊息



