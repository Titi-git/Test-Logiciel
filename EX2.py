class FIFO:
    def __init__(self):
        self.list = []
    def push(self, value):
        self.list.append(value)
    def pop(self):
        if len(self.list) > 0:
            return self.list.pop(0)
        else:
            return None
        
class LIFO:
    def __init__(self):
        self.list = []
    def push(self, value):
        self.list.append(value)
    def pop(self):
        if len(self.list) > 0:
            return self.list.pop()
        else:
            return None

class LILO:
    def __init__(self):
        self.list = []
    def push(self, value):
        self.list.append(value)
    def pop(self):
        if len(self.list) > 0:
            return self.list.pop(0)
        else:
            return None