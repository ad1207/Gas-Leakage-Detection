import serial
import pyttsx3
from twilio.rest import Client

# Initialize Text-to-Speech engine
engine = pyttsx3.init()

# Initialize Twilio Client
client = Client(TWILIO_SID, TWILIO_AUTH_TOKEN)

# # Open serial connection (change COM port accordingly)
ser = serial.Serial('COM15', 9600, timeout=1)  # For Windows (Check Device Manager)
# # ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)  # For Linux/Raspberry Pi
# # ser = serial.Serial('/dev/tty.usbserial', 9600, timeout=1)  # For macOS

while True:
    try:
        data = ser.readline().decode('utf-8').strip()  # Read data from Arduino
        if data == "YES":
            print("Alert! Gas Leak Detected.")
            message = client.messages.create(
                body="🚨 Gas Leak Alert! Immediate action required!",
                from_=TWILIO_PHONE_NUMBER,
                to=TO_PHONE_NUMBER)
            print(f"📩 SMS Sent! Message SID: {message.sid}")
            engine.say("Warning! Gas leak detected. Please take action immediately.")
            engine.runAndWait()
        elif data == "NO":
            print("No gas detected.")
    except Exception as e:
        print(f"Error: {e}")



# while True:
#     data = ser.readline().decode('utf-8').strip()  # Read data from Arduino
#     print("Data Received: ", data)
#     print("Alert! Gas Leak Detected.")
#     # engine.say("Warning! Gas leak detected. Please take action immediately.")
#     # engine.runAndWait()