# ch30_33.py
import subprocess

txtPro = subprocess.Popen(['start', 'trip.txt'], shell=True)
pictPro = subprocess.Popen(['start', 'book.jpg'], shell=True)
m4vPro = subprocess.Popen(['start', 'pegiun.m4v'], shell=True)
print("txt檔案執行緒  = ", txtPro)
print("pict檔案執行緒 = ", pictPro)
print("m4v檔案執行緒  = ", m4vPro)



