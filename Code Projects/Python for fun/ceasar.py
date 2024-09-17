text = input("Enter ciphertext: \n")
p_txt = str

print("\n\n")

for i in range(len(text)):
    m = ord(text[i])
    if text[i].isalpha():
        if m >= 65 and m <= 67: m += 26
        if m >= 97 and m <= 99: m += 26

        print(chr(m - 3), end="")
    else:
        print(text[i], end="")

print("\n\n")

