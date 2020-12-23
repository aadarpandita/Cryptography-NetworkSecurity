def decimalToBinary(num):
    if num > 1:
       decimalToBinary(num // 2)
   print(num % 2, end='')
  
 
number = int(input("Enter a decimal number: "))
 
print("Binary equivalent of the decimal is : ")
decimalToBinary(number)
