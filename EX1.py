def max_3(list):
    newlist = []
    for i in range(3):
        newlist.append(max(list))
        list.remove(max(list))
    return newlist

def min_n(list, n):
    newlist = []
    for i in range(n):
        newlist.append(min(list))
        list.remove(min(list))
    return newlist

def is_prime(n):
    if n % 2 == 0:
        return False
    else:
        return True

def is_arithmetic(list):
    if list[0] and list[1]:
        diff = list[1] - list[0]
        for i in range(len(list)-1):
            if list[i+1] - list[i] != diff:
                return False
        return True
    else:
        return False

def is_geometric(list):
    if list[0] and list[1]:
        diff = list[1] / list[0]
        for i in range(len(list)-1):
            if list[i+1] / list[i] != diff:
                return False
        return True
    else:
        return False