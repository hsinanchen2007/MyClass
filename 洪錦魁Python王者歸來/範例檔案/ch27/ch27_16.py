# ch27_16.py
from PIL import Image

pict = Image.open("rushmore.jpg")           # 建立Pillow物件
copyPict = pict.copy()                      # 複製
copyPict.save("out27_16.jpg")







