import serial
import time

# Configuration of connection to the arduino system
arduino = serial.Serial('COM6', 9600)
time.sleep(.2)

arduino.close()
time.sleep(0.001)
arduino.open()

# Capture EMG signals in determined times
def capture_EMG_signals(value_count, type_of_signal1 = [], type_of_signal2 = []):
    for counter in range(value_count):
        #change a to EMG signals variable
        data = arduino.readline().decode('utf-8').rstrip()
        #split = data.split(',')
        #type_of_signal1.append(split[0])
        #type_of_signal2.append(split[1])
        print(data)

# Method for creating storage file (.txt) and encryption
def store_to_file(file_name, get_value_list):
    with open(file_name, 'w') as file:
        a = 1
        for data in get_value_list: # for loop is here in actual
            if(a != 500):
                file.write(str(data) + "\n")
                a+=1
            else:
                file.write(str(data))

# For sending commands in the Arduino
def sendCommand(command_key):
    if (command_key == '0'): # welcome movement
        arduino.write(command_key.encode())
    elif(command_key == '1'): # extension, fingers pointing upward, rest
        arduino.write(command_key.encode())
    elif(command_key == '2'): # close, closed fist
        arduino.write(command_key.encode())
    elif(command_key == '3'): # flexion, fingers pointing downward
        arduino.write(command_key.encode())

# Start of main
# EMG1 = anterior -below
# EMG2 = posterior-above
emgFull1_value = []
emgFull2_value = []

emgHalf1_value = []
emgHalf2_value = []

emgRest1_value = []
emgRest2_value = []

try:
    # Read from files
    time.sleep(.33)
    with open('EMGPH_full1.csv', 'r') as file:
        print("file EMG_full1 is found")
        for get_from_file in file:
            emgFull1_value.append(int(get_from_file.strip()))
    time.sleep(.33)
    with open('EMGPH_full2.csv', 'r') as file:
        print("file EMG_full2 is found")
        for get_from_file in file:
            emgFull2_value.append(int(get_from_file.strip()))

    time.sleep(.33)
    with open('EMGPH_half1.csv', 'r') as file:
        print("file EMG_half1 is found")
        for get_from_file in file:
            emgHalf1_value.append(int(get_from_file.strip()))
    time.sleep(.33)
    with open('EMGPH_half2.csv', 'r') as file:
        print("file EMG_half2 is found")
        for get_from_file in file:
            emgHalf2_value.append(int(get_from_file.strip()))

    time.sleep(.33)
    with open('EMGPH_rest1.csv', 'r') as file:
        print("file EMG_rest1 is found")
        for get_from_file in file:
            emgRest1_value.append(int(get_from_file.strip()))
    time.sleep(.33)
    with open('EMGPH_rest2.csv', 'r') as file:
        print("file EMG_rest2 is found")
        for get_from_file in file:
            emgRest2_value.append(int(get_from_file.strip()))

except FileNotFoundError:
    # Get 500 data to store
    sendCommand(0)
    # Closed fist
    print("Control hand to close, then open after")
    time.sleep(2.6)
    # Capture EMG signals five hundred times for Full, close
    capture_EMG_signals(500, emgFull1_value, emgFull2_value) 
    # Create file storage 
    store_to_file('EMGPH_full1.csv', emgFull1_value)
    store_to_file('EMGPH_full2.csv', emgFull2_value)

    # Fingers pointing downward
    print("Control hand to flexion, then open after")
    time.sleep(2.6)
    # Capture EMG signals five hundred times for Half, flexion
    capture_EMG_signals(500, emgHalf1_value, emgHalf2_value)
    # Create file storage
    store_to_file('EMGPH_half1.csv', emgHalf1_value)
    store_to_file('EMGPH_half2.csv', emgHalf2_value)

    # Fingers pointing upward
    print("Control hand to extension, then open after")
    time.sleep(2.6)
    # Capture EMG signals five hundred times for Rest, extension
    capture_EMG_signals(500, emgRest1_value, emgRest2_value)
    # Create file storage 
    store_to_file('EMGPH_rest1.csv', emgRest1_value)
    store_to_file('EMGPH_rest2.csv', emgRest2_value)

# Start of main loop

while True:
    #live feed of EMG signals
    sendCommand(input("enter"))
    emgSig1_Live = []
    emgSig2_Live = []

    capture_EMG_signals(200, emgSig1_Live, emgSig1_Live)


   # print(emgSig1_Live)
   # print(emgSig2_Live)