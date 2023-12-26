import sys
from os import statvfs_result

mylist = ["metric.dump  flights.dump   memory_pool.dump"]

checklist = ["metric.dump", "flight.dump"]

for c in checklist:
    if c not in mylist[0]:
        print("can not found " +c +" in my list")
    else:
        print("success")

a = "sudo touch " + \
    "abc " + \
    "xyz "

s = (
        "this is a \"uniquely very\n"
        "long string\" too\n"
        'for sure ...\n' + 
        a
    )

print(s)