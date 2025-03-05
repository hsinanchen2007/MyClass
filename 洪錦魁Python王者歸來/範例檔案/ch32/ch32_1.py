# ch32_1.py
from tkinter import *

def buttonClick():
    print("Hi! Python")

tk = Tk()
btn = Button(tk, text="Click me!", command=buttonClick)
btn.pack()
mainloop()





