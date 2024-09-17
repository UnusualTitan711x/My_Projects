txt = "Hello. I am Djiomou Arthur Tanyi Che. I am 18 years old. My hobbies are gaming, coding, cooking and making art. I aspire to be a computer engineer and a game dev."

t = "Hello Boy"


def encrypt(text, key):
    #code here
    result = ""
    for i in range(len(text)):
        c = text[i]
        if c.isalpha():
            if c.isupper():
                result += chr((ord(c) + key - 65) % 26 + 65)
            else:
                result += chr((ord(c) + key - 97) % 26 + 97)
        else:
            result += c
    
    return result

def reverse(text):
    #code here
    result = ""
    for i in range(len(text) - 1, -1, -1):
        result += text[i]
    return result


print("Plain text: " + txt)
print("Cipher 1: " + encrypt(txt, 5))
print("Cipher 2: " + reverse(txt))
print("Cipher 1 + 2: " + reverse(encrypt(txt, 5)))


