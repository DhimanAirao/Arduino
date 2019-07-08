import serial

Comport='COM5'   #Enter comport of arduino board
Baudrate=9600    #Enter baudrate of arduino board

arduinoData=serial.Serial(Comport,Baudrate)
DataValue=0

while True:
    while(arduinoData.inWaiting()==0):
        pass
    DataValue=arduinoData.readline().decode('ascii')
    DataArray=DataValue.split('      ')     #as data receive from arduino is in string format
    print(DataArray)
    
