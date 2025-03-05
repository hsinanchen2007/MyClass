# ch19_35.py
import openpyxl
from openpyxl.chart import PieChart3D, Reference

wb = openpyxl.Workbook()                    # 開啟活頁簿
ws = wb.active                              # 獲得目前工作表
rows = [
    ['地區', '人次'],
    ['上海', 300],
    ['東京', 600],
    ['香港', 700],
    ['新加坡', 400]]
for row in rows:
    ws.append(row)

chart = PieChart3D()                        # 長條圖
chart.title = '深石員工旅遊意向調查表'

data = Reference(ws, min_col= 2, min_row=1, max_row=5)      # 圖表資料
chart.add_data(data, titles_from_data=True) # 建立圖表
labels = Reference(ws, min_col=1, min_row = 2, max_row=5)   # 標籤名稱
chart.set_categories(labels)                # 設定標籤名稱
ws.add_chart(chart, 'E1')                   # 放置圖表位置
wb.save('out19_35.xlsx')





