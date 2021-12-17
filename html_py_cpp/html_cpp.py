# coding=<UTF-8>

def open_file(filename):
    with open(filename,"r") as file:
        ALL_LINES = file.readlines()
    
    return ALL_LINES


def conversion(list_with_lines):
    cpp_string = ""
    for index in list_with_lines:
        cpp_string += index.replace("/t","")
        print(cpp_string)
    return cpp_string

name = input("Name of the file? ")
list_lines = open_file(name)
total_string = conversion(list_lines)



print(repr(total_string))



