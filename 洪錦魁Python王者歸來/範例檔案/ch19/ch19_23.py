# ch19_23.py
import openpyxl

wb = openpyxl.Workbook()                    # 建立空白的活頁簿
ws = wb.get_active_sheet()                  # 獲得目前工作表
row1 = ['數學', '物理', '化學']             # 定義串列資料
ws.append(row1)                             # 寫入串列
row2 = [98, 82, 89]                         # 定義串列資料
ws.append(row2)                             # 寫入串列
wb.save('out19_23.xlsx')                    # 將活頁簿儲存






