import serial
import csv

COMPORT='COM5'      #Enter the comport of your arduino board
BAUDRATE=9600       #Enter the baudrate at which ardino works 

arduinoData=serial.Serial(COMPORT,BAUDRATE)

while True:
    while (arduinoData.inWaiting()==0):
        pass
    arduinoString=arduinoData.readline().decode('ascii')
    dataArray=arduinoString.split('      ') #as data receive from arduino is in string form
    Date=dataArray[0]
    Time=float(dataArray[1])
    Sensor1=float(dataArray[2])
    Sensor2=float(dataArray[3])
    with open('csv.csv','a') as Data:
        thewriter = csv.writer(Data)
        thewriter.writerow([ Date , Time , Sensor1 , Sensor2  ])

        
