# ch19_17.py
import openpyxl

wb = openpyxl.Workbook()                    # 建立空白的活頁簿
ws = wb.get_active_sheet()                  # 獲得目前工作表
print("目前工作表名稱 = ", ws.title)        # 列印目前工作表
ws.title = 'My sheet'                       # 更改目前工作表名稱
print("新工作表名稱   = ", ws.title)        # 列印新的目前工作表
wb.save('out19_17.xlsx')                    # 將活頁簿儲存






