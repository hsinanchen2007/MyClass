# ch32_10.py
from tkinter import *

tk = Tk()
canvas = Canvas(tk, width=640, height=480)
canvas.pack()
myPict = PhotoImage(file='antarctica.gif')
canvas.create_image(0,0,image=myPict, anchor=NW)








