# coding=<UTF-8>

def open_file(filename):
    with open(filename,"r") as file:
        ALL_LINES = file.readlines()
    
    return ALL_LINES


def conversion(list_with_lines):
    cpp_string = ""
    for index in list_with_lines:
        string_edit = index.replace("/t","")
        string_edit = index.replace('"',"'")
        cpp_string += string_edit
        print(cpp_string,"DEBUG_______")
    return cpp_string

name = input("Name of the file? ")
list_lines = open_file(name)
total_string = conversion(list_lines)

        

print(repr(total_string))



