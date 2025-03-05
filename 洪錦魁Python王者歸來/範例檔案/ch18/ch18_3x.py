# ch18_3x.py
import PyPDF2

pdfObj = open('mytravel.pdf','rb')
pdfReader = PyPDF2.PdfFileReader(pdfObj)

pdfWriter = PyPDF2.PdfFileWriter()
for pageNum in range(pdfReader.numPages):
    pdfWriter.addPage(pdfReader.getPage(pageNum))

pdfWriter.encrypt('jiinkwei')
resultPdf = open('encrypttravel.pdf', 'wb')
pdfWriter.write(resultPdf)
resultPdf.close()





