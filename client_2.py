import socket

IP_Address='192.168.4.1'    #Enter the Ip Address of your server
Port=1000                   #Enter the Port on which your server works

s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect((IP_Address,Port))

while True:
    Data=s.recv(1024)       #Enter the number of bytes you want to receive at time
    Data1=Data.decode('ascii')  
    print(Data1,end='')
    with open('Data.txt','a') as Data_file:
        Data_file.write(Data1)
    
