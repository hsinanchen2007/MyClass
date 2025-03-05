# ch13_29.py
import keyword                      # 導入keyword模組

keywordLists = ['as', 'while', 'break', 'sse', 'Python']
for x in keywordLists:
    print("%8s " % x, keyword.iskeyword(x))

