
class node:
    name = ''
    children =[]
    parent = None
    sizes = []
    total_mem = 0
    
    def __str__(self):
        return self.name
            

def main():
    f = open("../inputs/day07", "r")
    
    root = node()
    root.name = '/'
    cur_node = root
    
    
    lines = f.readlines()
    lines = lines[1:]
    for line in lines:
        print(line)
        line  = line.split()
        if line[1] == "cd":
                if line[2] != "..":
                    for child in node.children:
                        if child.name == line[2]:
                            child.parent = cur_node
                            cur_node = child
                            
                if line[2] == "..":
                    cur_node = cur_node.parent
                    
        if line[0] == "dir":
            new_node = node()
            new_node.name = line[1]
            cur_node.children.append(new_node)
        if line[0].isnumeric():
            cur_node.sizes.append(int(line[0]))

            
    cur_node = root
    cur_node.print_node()

            
main()
