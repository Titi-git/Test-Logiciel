def max_3(list):
    if list == [] or len(list) < 3:
        return []
    newlist = []
    list_temp = list
    for i in range(3):
        newlist.append(max(list_temp))
        list.remove(max(list_temp))
    return newlist

def min_n(list, n):
    if list == [] or n == 0 or n > len(list):
        return []
    newlist = []
    list_temp = list
    for i in range(n):
        newlist.append(min(list_temp))
        list.remove(min(list_temp))
    return newlist

def is_prime(n):
    if n > 1:
        for i in range(2, n):
            if n % i == 0:
                return False
        return True
    else:
        return True

def is_arithmetic(list):
    if list == []:
        return False
    if list[0] and list[1]:
        diff = list[1] - list[0]
        for i in range(len(list)-1):
            if list[i+1] - list[i] != diff:
                return False
        return True
    else:
        return False

def is_geometric(list):
    if list == []:
        return False
    if list[0] and list[1]:
        diff = list[1] / list[0]
        for i in range(len(list)-1):
            if list[i+1] / list[i] != diff:
                return False
        return True
    else:
        return False