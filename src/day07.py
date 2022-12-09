class node:
    
    name = ''
    children = None
    parent = None
    sizes = None
    total = 0

    def __init__(self, parent, name):
        self.parent = parent
        self.children = []
        self.sizes = []
        self.name = name
        self.total = 0

    def __str__(self):
        return self.name

    def add_file(self, size):
        self.sizes.append(size)
        self.total += size
        
    def get_anwser(self, anws):
        
        # not leaf: keep going
        if len(self.children) != 0:
            for child in self.children:
                anws = child.get_anwser(anws)

        if self.total <= 100000:
            anws += self.total
        return anws
    
    def sum_totals(self):
            
        #get to leaves
        if len(self.children) != 0:
            for child in self.children:
                child.sum_totals()

        if self.parent != None:
            self.parent.total += self.total
        return
    
    def files_larger(self, thresh, l):
    
        #get to leaves
        if len(self.children) != 0:
            for child in self.children:
                l = child.files_larger(thresh, l)
                
        if self.total > thresh:
            l.append(self.total)
            
        return l
    
def p1():
    
    f = open("../inputs/day07", "r")

    # make the root node
    root = node(None, "/")
    cur_node = root

    # split up lines
    lines = f.readlines()
    lines = lines[1:]

    for line in lines:
        line  = line.split()
        
        if line[1] == "cd":
                if line[2] != "..":
                    for child in cur_node.children:
                        if child.name == line[2]:
                            cur_node = child
                if line[2] == "..":
                    cur_node = cur_node.parent

        if line[0] == "dir":
            new_node = node(cur_node, line[1])
            cur_node.children.append(new_node)
        if line[0].isnumeric():
            cur_node.add_file(int(line[0]))

    anwser = 0
    root.sum_totals()
    print("p1:", root.get_anwser(anwser))

    return root

def p2(root):

    greater = []
    search = 30000000 - (70000000 - root.total)
    
    print("p2:", min(root.files_larger(search, greater)))
    
root = p1()
p2(root)
