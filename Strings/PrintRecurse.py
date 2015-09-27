import os

def print_recurr(str_list, row, curr_row, output):
    if curr_row >= row:
        print(" ".join(output))
        return;
    for e in str_list[curr_row]:
        output += [e]
        print_recurr(str_list, row, curr_row + 1, output)
        output.remove(e);
        

str_list = [['you','we'],['have','are'],['sleep','eat','drink']]
output = []
print_recurr(str_list, 3, 0, output)
