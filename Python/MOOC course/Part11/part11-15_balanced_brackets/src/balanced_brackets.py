def balanced_brackets(my_string: str):
    if len(my_string) == 0:
        return True
    my_string = "".join([character for character in my_string if character in "()[]"])
    if not (my_string[0] == '(' and my_string[-1] == ')'):
        if not (my_string[0] == '[' and my_string[-1] == ']'):
            return False
    return balanced_brackets(my_string[1:-1])    


if __name__ == "__main__":
    ok = balanced_brackets("([([])])")
    print(ok)

    ok = balanced_brackets("(python version [3.7]) please use this one!")
    print(ok)

    # this is no good, the closing bracket doesn't match
    ok = balanced_brackets("(()]")
    print(ok)

    # different types of brackets are mismatched
    ok = balanced_brackets("([bad egg)]")
    print(ok)