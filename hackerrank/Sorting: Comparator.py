from functools import cmp_to_key
class Player:
    def __init__(self, name, score):
        self.name = name
        self.score = score
        
    def __repr__(self):
        return self.name + " " + str(self.score)
        
    def comparator(a, b):
        if a.score != b.score:
            if a.score > b.score:
                return -1
            else:
                return 1
        else:
            lena, lenb = len(a.name), len(b.name)
            for _ in range(min(lena, lenb)):
                if a.name[_] != b.name[_]:
                    if a.name[_] > b.name[_]:
                        return 1
                    else:
                        return -1
            if lena == lenb:
                return 0
            elif lena > lenb:
                return 1
            else:
                return -1

