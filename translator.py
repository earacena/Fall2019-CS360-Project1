# Project:              Translate source code to assembly (C++ to x86_64)
# Author(s)/Group:      Emanuel Aracena
# Date created:         August 28, 2019
# Name of file:         translator.py 
# Description:          Translator removes all white space and excess characters like
#                       newlines, then parses based on syntax


class Function:
    def __init__(self, func_name, func_type, args, statements):
        self.name = func_name
        self.type = func_type 
        self.args = args
        self.statements = statements

class Declaration:
    def __init__(self, type, address, value):
        self.type = type
        self.address = address
        self.value = value
    
# class Statement:
#     def __init__(self, statement, conditional):
#         self.string = statement
#         self.conditional = conditional

# class Operand:
#     def __init__(self, address):
#         self.addr = address
        
class LogicalOperation:
    def __init__(self, destination, operand1, operator, operand2):
        self.dest = destination
        self.operand1 = operand1
        self.op = operator
        self.operand2 = operand2

    def print_asm():
        print("")
        
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
    type = ""
    function_name = ""
    args = ""
    statements = ""
    function_list = []
    bracket_stack = []
    
    for index, keyword in enumerate(source_code):
        # special cases
        if keyword == '{':
            # push
            bracket_stack.append('{')

        elif keyword == '}':
            bracket_stack.pop()
            function_list.append(Function(function_name, type, args, statements))
            # Clear variables for next function
            type = ""
            function_name = ""
            args = ""
            statements = ""
            
        else:
            # General cases
            if bracket_stack == []:
                # New function

                # type
                # int name( ...
                #  ^
                if source_code[index-1] == '}':
                    type = keyword
                    
                # name
                # int name( ....
                #         ^
                elif '(' in keyword:
                    function_name = keyword.split("(")[0]
                    args = keyword.split("(")[1]
                
                # args
                # ( args ,,,,
                # ^
                elif keyword != '{':
                    args = args + " " + keyword
                
            else:
                # Nested statement
                statements = statements + " " + keyword
                
    return function_list

# Parse functions into their respective classes
def process_statements(statements):
    statements_split = statements.split(";")
    statement_list = []
    for statement in statements_split:
        if "int" in statement:
            # Declaration
            if "="  in statement:
                op = Declaration(statement.split(" ")[0], statement.split(" ")[1],
                                 statement.split(" ")[3])
            else:
                # same as int x;
                op = Declaration(statement.split(" ")[0], statement.split(" ")[1], "none")
        elif "-" in statement:
            # Logical operation
            # a = a + c
            print("CALLED: " + statement )
            op = LogicalOperation(statement.split(" ")[0], statement.split(" ")[2],
                                  statement.split(" ")[3], statement.split(" ")[1])
            #
        else:
            op = "not processed"
        statement_list.append(op)
    return statement_list

# Make note of arguments and their addresses
# return: number of arguments
def process_arguments(arguments):
    return

# Translate function into assembly
# post: print assembly
def process_function(function):
    print(function.name + ":")
    arguments = process_arguments(function.args)
    statements = process_statements(function.statements)

# Return list containing parsed functions
def print_function_list(function_list):
    for function in function_list:
        print(function.type)
        print(function.name)
        print(function.args)
        print(function.statements)       

def main():
    filename = "example.cpp"

    source = read_source_code(filename)
    print(source)

    source = clean_up(source)
    print(source)

    function_list = parse_source_into_functions(source)
    print_function_list(function_list)

    for function in function_list:
        process_function(function)

if __name__ == "__main__":
    main()
