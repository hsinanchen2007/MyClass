# ch19_24_1.py
import openpyxl

wb = openpyxl.Workbook()            # 建立空白的活頁簿
ws = wb.get_active_sheet()          # 獲得目前工作表
ws['A1'] = '明志科技大學'
rows = [                            # 定義串列資料
    ['數學', '物理', '化學'],
    [98, 82, 89],
    [79, 88, 90],
    [80, 78, 91]]                   
for row in rows:
    ws.append(row)                  # 寫入串列
wb.save('out19_24_1.xlsx')          # 將活頁簿儲存






