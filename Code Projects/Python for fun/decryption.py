def decrypt(text, key):
    #code here
    result = ""
    for i in range(len(text)):
        c = text[i]
        if c.isalpha():
            if c.isupper():
                result += chr((ord(c) - key - 65) % 26 + 65)
            else:
                result += chr((ord(c) - key - 97) % 26 + 97)
        else:
            result += c
    return result

def reverse(text):
    #code here
    result = ""
    for i in range(len(text) - 1, -1, -1):
        result += text[i]
    return result

txt = input("Enter ciphertext: ")
print(decrypt(txt, 3))
