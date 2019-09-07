# Project:              Translate source code to assembly (C++ to x86_64)
# Author(s)/Group:      Emanuel Aracena
# Date created:         August 28, 2019
# Name of file:         translator.py 
# Description:          Translator removes all white space and excess characters like
#                       newlines, then parses based on syntax

def read_source_code(filename):
    source_code = []
    with open("example.cpp") as file:
        for line in file:
            source_code = source_code + line.split(" ")
    return source_code

def clean_up(source_code):

    
    # Turns all newline chars into whitespace or erases them from string
    source_code = [elem.strip('\n') for elem in source_code]

    # Use a filter to pick out all elements that are not whitespace (' ')
    # The lambda takes an element from source_code, if it is not '', it doesn't
    # get filtered
    source_code = list(filter(lambda elem: elem != '', source_code))    
    return source_code

def parse_source_into_functions(source_code):
    index1 = 0
    index2 = 0
    function_split = []
    flag = False
    while flag != True:
        # Move two markers from start of one function to end, using the '}' as
        # an indicator of the end of a function
        index1 = index2
        index2 = source_code.index("}", index1)
        function_split = function_split + [source_code[index1:index2] + ['}']]
        
        # Allow index to find following right curly brace
        try:
            source_code.remove("}")
        except ValueError:
            pass

        # Debug
        # print(index1, index2)

        # If all curly braces have been removed and index2 reached the end,
        # set flag true
        if index2 == len(source_code):
            flag = True

    # Remove return types
    for function in function_split:
        del function[0]
        
    return function_split

# If the parenthesis after function name are empty, there is no argument

def check_for_arguments(parsed_func_list):
    arg_flag_list = []
    present = False
    for function in parsed_func_list:
        arg_flag_list.append( function[0].split("(")[1] != ')' )
    return arg_flag_list

def calculate_reserved_bytes(function):
    counter = 0
    for keyword in function:
        if keyword == 'int' or 'int' in keyword:
            counter = counter + 1

    reserve = 20
    while (counter * 4)> reserve:
        reserve = reserve + 16

    return reserve

def parse_functions_into_asm(parsed_func_list, arg_flag_list):
    asm = []
    # Number of bytes to reserver, once 20 bytes reached, keep adding 16
    for index1, function in enumerate(parsed_func_list):
        reserve = calculate_reserved_bytes(function)
        function_name = function[0].split("(")[0]
        function[0] = 'name'
        asm.append(function_name + ":")
        for index2, keyword in enumerate(function):
            if 'name' in keyword:
                continue
            if keyword == '{':
                asm.append('\tpush\trbp')
                asm.append('\tmov\trbp, rsp')
                if arg_flag_list[index1]:
                    asm.append("\tmov\tDWORD PTR [rbp-" + str(reserve) +
                               "], edi")
            if keyword == 'return':
                return_value = function[index2+1].strip(";")
                asm.append('\tmov\teax, ' + return_value)
            if keyword == '}':
                asm.append('\tpop\trbp')
                asm.append('\tret')
            else:
                continue
    return asm

def print_asm(asm):
    print('\n')
    for instruction in asm:
        print(instruction)


def main():
    filename = "example.cpp"
    source = read_source_code(filename)
    print(source)
    source = clean_up(source)
    print(source)
    parsed_func_list = parse_source_into_functions(source)
    print(parsed_func_list)
    arg_flag_list = check_for_arguments(parsed_func_list)
    print(arg_flag_list)
    asm = parse_functions_into_asm(parsed_func_list, arg_flag_list)
    print_asm(asm)
    
if __name__ == "__main__":
    main()
