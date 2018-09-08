"""
__Author__ = 0x539
__name__   = Recursion Dict to Json
__credits__ = 0x539
__version__ = "1.0"

Descreption:
    Weak function that will cause a stack overflow depending on the number of recursions, python will throw an exception
    but if you wanna test your machine set: import sys;sys.setrecursionlimit(7<<20)

The_Dict = {'hi': [{'hello': ['yo', 'sup'], 14: {'stop'}}, 'hi'], 'kk': 'hik'}
num_of_tabs = 4
Type_of_Tab = " " # default: "\t"
print(ch(The_Dict, tabs=num_of_tabs, TAB=Type_of_Tab))
"""

__Author__ = "0x539"
__name__   = "Recursion Dict to Json"
__credits__ = "0x539"
__version__ = "1.0"

def ch(d, k="", tabs=0, Round=0, TAB="\t"):
    if tabs:
        t = TAB
        TAB = TAB * tabs
        NEWL = "\n"
    else:
        TAB = ""
        t = TAB
        NEWL = ""
    if type(d) == str:
        k += '"' + str(d) + '"'
    elif type(d) in [int, float]:
        k += str(d)
    elif type(d) == list:
        k += "[" + NEWL
        Round += 1
        k += ((Round)*TAB)
        for h in range(len(d)):
            k = ch(d[h], k=k, tabs=tabs, Round=Round, TAB=t)
            if len(d) != (h + 1):
                k += ","
                # k += NEWL + (Round*TAB)
            else:
                k += NEWL
        Round -= 1
        k += ((Round) * TAB)
        k += "]"
    elif type(d) == set:
        k += "{" + NEWL
        Round += 1
        k += ((Round)*TAB)
        r = 0
        for h in d:
            k = ch(h, k=k, tabs=tabs, Round=Round, TAB=t)
            if len(d) != (r + 1):
                k += ","
                k += NEWL + (Round * TAB)
            else:
                k += NEWL
            r += 1
        Round -= 1
        k += ((Round) * TAB)
        k += "}"
    elif type(d) == dict:
        k += "{" + NEWL
        Round += 1
        k += ((Round)*TAB)
        h = 0
        for j in d:

            if type(j) == str:
                k += '"' + j + '"'
            elif type(j) in [int, float]:
                k += str(j)
            k += " : "
            k = ch(d[j], k=k, tabs=tabs, Round=Round, TAB=t)
            if len(d) != (h + 1):
                k += ","
                k += NEWL + (Round * TAB)
            else:
                k += NEWL
            h += 1
        Round -= 1
        k += ((Round) * TAB)
        k += "}"
    return k


