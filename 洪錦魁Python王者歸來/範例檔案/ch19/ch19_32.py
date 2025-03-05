# ch19_32.py
import openpyxl
from openpyxl.chart import BarChart, Reference

wb = openpyxl.Workbook()                    # 開啟活頁簿
ws = wb.active                              # 獲得目前工作表
rows = [
    ['', '2020年', '2021年'],
    ['亞洲', 100, 300],
    ['歐洲', 400, 600],
    ['美洲', 500, 700],
    ['非洲', 200, 100]]
for row in rows:
    ws.append(row)

chart = BarChart()                          # 長條圖
chart.title = '深石軟件銷售表'              # 圖表標題
chart.y_axis.title = '業績金額'             # y軸標題
chart.x_axis.title = '地區'                 # x軸標題

data = Reference(ws, min_col= 2, max_col=3, min_row=1, max_row=5) # 圖表資料
chart.add_data(data, titles_from_data=True) # 建立圖表
xtitle = Reference(ws, min_col=1, min_row = 2, max_row=5)         # x軸標記名稱
chart.set_categories(xtitle)                # 設定x軸標記名稱(亞洲歐洲美洲非洲)
ws.add_chart(chart, 'E1')                   # 放置圖表位置
wb.save('out19_32.xlsx')





