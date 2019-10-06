import serial
import numpy
import matplotlib.pyplot as plt
from drawnow import *


arduinoData=serial.Serial('com5',9600)
Date_1=set()
Time_1=[]
sensor_1=[]
sensor_2=[]
plt.ion()
cnt=0

def makefig():
    plt.xticks(Time_1)
    plt.grid(True)
    plt.ylim(36,45)
    plt.title('Sensor data')
    plt.ylabel('Sensor_1')
    plt.plot(Time_1,sensor_1,'ro-',label='Degree C')
    plt.legend(loc='upper left')
    plt2=plt.twinx()
    plt.ylim(20,40)
    plt2.plot(Time_1,sensor_2,'bo-',label='Degree C')
    plt2.legend(loc='upper right')
    
while True:
    while (arduinoData.inWaiting()==0):
        pass
    arduinoString=arduinoData.readline().decode('ascii')
    dataArray=arduinoString.split('      ')
    Date=dataArray[0]
    Time=float(dataArray[1])
    Sensor1=float(dataArray[2])
    Sensor2=float(dataArray[3])
    Date_1.add(Date)
    Time_1.append(Time)
    sensor_1.append(Sensor1)
    sensor_2.append(Sensor2)
    print(Time_1)
    drawnow(makefig)
    plt.pause(0.000001)
    cnt+=1
    if(cnt>500):
        sensor_1.pop(0)
        sensor_2.pop(0)
    
