# This
import time
import sys

if sys.argv[1].isnumeric():
    Num = int(sys.argv[1])
else:
    print("[-] Error:")
    print("\tUsuage: This.py <length of maximum tries>")
    sys.exit(input())

print("[+] Starting the calculation of Fuzzing speed ")


def Fuzz(ln: int):
    for i in range(0, int("1" + "0" * ln * 2) - 1):
        yield ("".join((chr(int(x, 16)) if x is not None else "") for x in
                       [(str(hex(i))[2:][f:f + 2] if f % 2 == 0 else None) for f in range(len(str(hex(i))[2:]))]))


T = time.time()
for Try in Fuzz(Num):
    A = Try
print("[+] First Lasted: ", time.time() - T)

del Fuzz
del T
del A


# Or this
def Fuzz(ln: int):
    return (("".join((chr(int(x, 16)) if x is not None else "") for x in
                     [(str(hex(i))[2:][f:f + 2] if f % 2 == 0 else None) for f in range(len(str(hex(i))[2:]))])) for i
            in range(0, int("1" + "0" * ln * 2) - 1))


T = time.time()
for Try in Fuzz(Num):
    A = Try
print("[+] First Lasted: ", time.time() - T)

del Fuzz
del T
del A

# Or this: Fastest
Fuzz = lambda ln: (("".join((chr(int(x, 16)) if x is not None else "") for x in
                            [(str(hex(i))[2:][f:f + 2] if f % 2 == 0 else None) for f in range(len(str(hex(i))[2:]))]))
                   for i in range(0, int("1" + "0" * ln * 2) - 1))

T = time.time()
for Try in Fuzz(Num):
    A = Try
print("[+] First Lasted: ", time.time() - T)

del Fuzz
del T
del A

print("[+] Done: Quiting")
input()
r"""
Usuage:
  >>> for Try in Fuzz(6):
  >>>     print(try)

 C:\Users\NoGues>py -3.6 D:\NONO\Hacking\tries\Fuzz.py 3
[+] Starting the calculation of Fuzzing speed
[+] First Lasted:  6.917889833450317
[+] First Lasted:  6.950460195541382
[+] First Lasted:  6.856525897979736
[+] Done: Quiting

C:\Users\NoGues>py -3.6 D:\NONO\Hacking\tries\Fuzz.py 3
[+] Starting the calculation of Fuzzing speed
[+] First Lasted:  7.006311893463135
[+] First Lasted:  6.985356092453003
[+] First Lasted:  6.859590768814087
[+] Done: Quiting

C:\Users\NoGues>py -3.6 D:\NONO\Hacking\tries\Fuzz.py 3
[+] Starting the calculation of Fuzzing speed
[+] First Lasted:  7.068330764770508
[+] First Lasted:  7.0870747566223145
[+] First Lasted:  6.912209987640381
[+] Done: Quiting"""
