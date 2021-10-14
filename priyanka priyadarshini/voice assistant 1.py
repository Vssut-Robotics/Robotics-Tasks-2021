import pyttsx3
import speech_recognition as sr 
import playsound
import webbrowser
import re

engine=pyttsx3.init('sapi5')
voices=engine.getProperty('voices')

engine.setProperty('voice',voices[1].id)


def speak(audio):
    engine.say(audio)
    engine.runAndWait()

def greet():
    speak("hi sir, this is jarvis. how may i help u? ")


def takeCommand():
    r=sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening....") 
        r.pause_threshold = 1
        audio=r.listen(source)
        search_web(audio)

greet()
takeCommand()
         
if __name__ == "__main__":
    while True:
        query=takeCommand().lower()

        if 'open' in query:
            result=re.search(r'\w.+\w',query).group()
            s=result+".com"
            webbrowser.open(s)           


        



   


