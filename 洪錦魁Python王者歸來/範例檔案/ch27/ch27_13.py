# ch27_13.py
from PIL import Image

newImage = Image.new('RGBA', (300, 100), "Yellow")
print(newImage.getpixel((150, 50)))      # 列印中心點的色彩
newImage.save("out27_13.png")













