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
    
class Statement:
    def __init__(self, statement, conditional):
        self.string = statement
        self.conditional = conditional
        
class Operand:
    def __init__(self, address):
        self.addr = address

        
class LogicalOperation:
    def __init__(self, destination, operand1, operator, operand2):
        self.dest = destination
        self.operand1 = operator1
        self.op = operator
        self.operand2 = operand2

        
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
                statements = statements + keyword
                
    return function_list

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

    source = parse_source_into_functions(source)
    print(source[0].type)
    print(source[0].name)
    print(source[0].args)
    print(source[0].statements)

if __name__ == "__main__":
    main()
