# Write your solution here
import string
def run(program: list):
    variables = {}
    list = []
    uppercase = string.ascii_uppercase
    for letter in uppercase:
        variables[letter] = 0
    i = 0
    while i < len(program):
        if " " in program[i]:
            parts = program[i].split(" ")
            if parts[0] == "PRINT":
                if parts[1] in string.ascii_uppercase:
                    list.append(variables[parts[1]])
                else:
                    list.append(int(parts[1]))
            elif parts[0] == "MOV":
                if parts[2] in string.ascii_uppercase:
                    variables[parts[1]] = variables[parts[2]]
                else:
                    variables[parts[1]] = int(parts[2])
            elif parts[0] == "ADD":
                if parts[2] in string.ascii_uppercase:
                    variables[parts[1]] += variables[parts[2]]
                else:
                    variables[parts[1]] += int(parts[2])
            elif parts[0] == "SUB":
                if parts[2] in string.ascii_uppercase:
                    variables[parts[1]] -= variables[parts[2]]
                else:
                    variables[parts[1]] -= int(parts[2])
            elif parts[0] == "MUL":
                if parts[2] in string.ascii_uppercase:
                    variables[parts[1]] *= variables[parts[2]]
                else:
                    variables[parts[1]] *= int(parts[2])
            elif parts[0] == "JUMP":
                temp = parts[1] + ":"
                index = program.index(temp)
                i = index
            elif parts[0] == "IF":
                if parts[2] == "==":
                    if parts[1] in string.ascii_uppercase and parts[3] in string.ascii_uppercase:
                        if variables[parts[1]] == variables[parts[3]]:
                            temp = parts[5] + ":"
                            index = program.index(temp)
                            i = index
                    elif parts[1] in string.ascii_uppercase and parts[3] not in string.ascii_uppercase:
                        if variables[parts[1]] == int(parts[3]):
                            temp = parts[5] + ":"
                            index = program.index(temp)
                            i = index
                    else:
                        if int(parts[1]) == variables[parts[3]]:
                            temp = parts[5] + ":"
                            index = program.index(temp)
                            i = index
                elif parts[2] == "!=":
                    if parts[1] in string.ascii_uppercase and parts[3] in string.ascii_uppercase:
                        if variables[parts[1]] != variables[parts[3]]:
                            temp = parts[5] + ":"
                            index = program.index(temp)
                            i = index
                    elif parts[1] in string.ascii_uppercase and parts[3] not in string.ascii_uppercase:
                        if variables[parts[1]] != int(parts[3]):
                            temp = parts[5] + ":"
                            index = program.index(temp)
                            i = index
                    else:
                        if int(parts[1]) != variables[parts[3]]:
                            temp = parts[5] + ":"
                            index = program.index(temp)
                            i = index
                elif parts[2] == "<":
                    if parts[1] in string.ascii_uppercase and parts[3] in string.ascii_uppercase:
                        if variables[parts[1]] < variables[parts[3]]:
                            temp = parts[5] + ":"
                            index = program.index(temp)
                            i = index
                    elif parts[1] in string.ascii_uppercase and parts[3] not in string.ascii_uppercase:
                        if variables[parts[1]] < int(parts[3]):
                            temp = parts[5] + ":"
                            index = program.index(temp)
                            i = index
                    else:
                        if int(parts[1]) < variables[parts[3]]:
                            temp = parts[5] + ":"
                            index = program.index(temp)
                            i = index
                elif parts[2] == "<=":
                    if parts[1] in string.ascii_uppercase and parts[3] in string.ascii_uppercase:
                        if variables[parts[1]] <= variables[parts[3]]:
                            temp = parts[5] + ":"
                            index = program.index(temp)
                            i = index
                    elif parts[1] in string.ascii_uppercase and parts[3] not in string.ascii_uppercase:
                        if variables[parts[1]] <= int(parts[3]):
                            temp = parts[5] + ":"
                            index = program.index(temp)
                            i = index
                    else:
                        if int(parts[1]) <= variables[parts[3]]:
                            temp = parts[5] + ":"
                            index = program.index(temp)
                            i = index
                elif parts[2] == ">":
                    if parts[1] in string.ascii_uppercase and parts[3] in string.ascii_uppercase:
                        if variables[parts[1]] > variables[parts[3]]:
                            temp = parts[5] + ":"
                            index = program.index(temp)
                            i = index
                    elif parts[1] in string.ascii_uppercase and parts[3] not in string.ascii_uppercase:
                        if variables[parts[1]] > int(parts[3]):
                            temp = parts[5] + ":"
                            index = program.index(temp)
                            i = index
                    else:
                        if int(parts[1]) > variables[parts[3]]:
                            temp = parts[5] + ":"
                            index = program.index(temp)
                            i = index
                else:
                    if parts[1] in string.ascii_uppercase and parts[3] in string.ascii_uppercase:
                        if variables[parts[1]] >= variables[parts[3]]:
                            temp = parts[5] + ":"
                            index = program.index(temp)
                            i = index
                    elif parts[1] in string.ascii_uppercase and parts[3] not in string.ascii_uppercase:
                        if variables[parts[1]] >= int(parts[3]):
                            temp = parts[5] + ":"
                            index = program.index(temp)
                            i = index
                    else:
                        if int(parts[1]) >= variables[parts[3]]:
                            temp = parts[5] + ":"
                            index = program.index(temp)
                            i = index 
            i += 1        
        else:
            if program[i] == "END":
                return list
                break
            i += 1
            continue
    return list
            
if __name__ == "__main__":
    program1 = []
    program1.append("MOV A 1")
    program1.append("MOV B 2")
    program1.append("PRINT A")
    program1.append("PRINT B")
    program1.append("ADD A B")
    program1.append("PRINT A")
    program1.append("END")
    result = run(program1)
    #print(result)

    program = ['MOV A 10', 'PRINT A', 'MOV B A', 'SUB B 8', 'PRINT B', 'SUB A B', 'PRINT A']
    #print(run(program))

    program2 = []
    program2.append("MOV A 1")
    program2.append("MOV B 10")
    program2.append("begin:")
    program2.append("IF A >= B JUMP quit")
    program2.append("PRINT A")
    program2.append("PRINT B")
    program2.append("ADD A 1")
    program2.append("SUB B 1")
    program2.append("JUMP begin")
    program2.append("quit:")
    program2.append("END")
    result = run(program2)
    #print(result)

    program3 = []
    program3.append("MOV A 1")
    program3.append("MOV B 1")
    program3.append("begin:")
    program3.append("PRINT A")
    program3.append("ADD B 1")
    program3.append("MUL A B")
    program3.append("IF B <= 10 JUMP begin")
    program3.append("END")
    result = run(program3)
    #print(result)

    program4 = []
    program4.append("MOV N 50")
    program4.append("PRINT 2")
    program4.append("MOV A 3")
    program4.append("begin:")
    program4.append("MOV B 2")
    program4.append("MOV Z 0")
    program4.append("test:")
    program4.append("MOV C B")
    program4.append("new:")
    program4.append("IF C == A JUMP error")
    program4.append("IF C > A JUMP over")
    program4.append("ADD C B")
    program4.append("JUMP new")
    program4.append("error:")
    program4.append("MOV Z 1")
    program4.append("JUMP over2")
    program4.append("over:")
    program4.append("ADD B 1")
    program4.append("IF B < A JUMP test")
    program4.append("over2:")
    program4.append("IF Z == 1 JUMP over3")
    program4.append("PRINT A")
    program4.append("over3:")
    program4.append("ADD A 1")
    program4.append("IF A <= N JUMP begin")
    result = run(program4)
    print(result)