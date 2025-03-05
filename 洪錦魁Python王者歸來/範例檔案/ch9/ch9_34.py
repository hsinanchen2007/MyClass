# ch9_34.py
fruits = {'apple':20, 'banana':15, 'orange':22}
ret_value = fruits.pop('grape', 'does not exist')
print("傳回刪除元素的值", ret_value)
print("刪除後的字典內容", fruits)
