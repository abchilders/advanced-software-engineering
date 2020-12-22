import math

# Using tutorial from:
# https://www.codementor.io/@ukwuomaignatius/already-familiar-with-programming-learn-python-syntax-in-5-minutes-ast95q4pg

# Numbers 
number_of_cars = 34 
pi = 3.14159
hours = 24 
debt = -5

print('int(pi): ')
print(int(math.pi))

print('float(hours): ')
print(float(hours))

print(abs(debt))

# Strings
print('hello'.capitalize()) # Capitalizes first letter of string
print('holaalaa'.count('a')) # Returns # of occurrences of substring

print('holaalaa'.find('a')) # Returns index of first occurrence of substring
print('holaalaa'.replace('a','e')) # Replaces all occurrences of arg1 with arg2 

print('1234'.isdigit()) # Returns True if string only contains digits
print('hello'.isalpha()) # Returns True if all chars in string are alphabetic 

print('some, useful, value'.split(',')) # Returns array with string split on char
print(len('holaalaa')) # Returns length of string 

alpha = 'a'
beta = 'b' 

# Using the string Format function 
print('''The first letter is {0} 
    and the second letter is {1}'''.format(alpha, beta))

# Using string interpolation 
print(f'The first letter is {alpha} and the second letter is {beta}')

# Booleans 
python_article = True 
java_article = False 
print(int(python_article)) # True -> 1
print(int(java_article)) # False -> 0 
print(str(python_article)) # Returns boolean as a string

# If Statements 
text = 'Python'
number = 7 
# Python uses truthy/falsy values 
if text or number: 
    print('This is Python')
else:
    print('This is something else')

# use 'elif' instead of 'else if' 
value = True 
if not value:
    print('value is False')
elif value is None:
    print('value is None')
else:
    print('value is True')

# ternary statements: writes "rich" if valuables is truthy (not empty)
# else, writes "poor" 
valuables = ['gold', 'diamonds']
print('rich') if valuables else ('poor')

# Lists 
student_names = ['Mark', 'John', 'James']
print(student_names[0]) # Returns first element in the list 
print(student_names[-1]) # Returns last element in the list 
print(student_names[-2]) # Return second-to-last element in the list 
print(student_names[1:3])