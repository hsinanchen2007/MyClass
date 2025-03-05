# ch10_39.py
drinks = {"coffee", "tea", "wine"}
enumerate_drinks = enumerate(drinks)        # 數值初始是0
print(enumerate_drinks)                     # 傳回enumerate物件所在記憶體
print("下列是輸出enumerate物件類型")
print(type(enumerate_drinks))               # 列出物件類型
print("下列是轉成串列輸出")
print(list(enumerate_drinks))               # 轉成串列再輸出串列
print("下列是迴圈輸出")
for item in enumerate(drinks):              # 迴圈輸出
    print(item)

print("\n")
for count, item in enumerate(drinks):       # 將counter和元素內容分開輸出
    print(count, item)

print("\n")
for count, item in enumerate(drinks, 10):   # 將counter起始值設為10輸出
    print(count, item)





          


