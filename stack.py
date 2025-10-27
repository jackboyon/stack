def isEmpty(stack:list):
    if len(stack) == 0: 
        print("stack is empty")
        return True
    print("stack is not empty")
    return False

def isFull(stack:list, size):
    if len(stack) >= size:
        print("stack is full")
        return True
    print("stack is not full")
    return False

def pop(stack:list, top):
    if isEmpty(stack): return top
    stack.pop()
    top-=1
    return top

def push(stack:list, size, top):
    if isFull(stack, size): return top
    while True:
        ch = input("enter a value: ")
        if(ch.isdigit()): break;
        else: print("invalid input")
    
    ch = int(ch)
    top += 1
    stack.append(ch)
    return top
    
def peek(stack:list,top):
    if not isEmpty(stack): return stack[top]

def sizeA(stack:list):
    if not isEmpty(stack): return len(stack)
    
    
    
top = -1
size = 5;
stack = [];
while True:
    print(stack)
    print("\n***************")
    print("1 | isEmpty")
    print("2 | isFull")
    print("3 | pop")
    print("4 | push")
    print("5 | peek")
    print("6 | size")
    print("0 | exit")
    print("***************")
    ch = input("enter a choice: ")
    if not ch.isdigit(): print("invalid input");continue
    ch = int(ch)
    match(ch):
        case 0: print("exiting"); break
        case 1: isEmpty(stack)
        case 2: isFull(stack, size)
        case 3: top = pop(stack, top)
        case 4: top = push(stack, size, top)
        case 5: print(f"top is: {peek(stack, top)}")
        case 6: print(f"size is: {sizeA(stack)}")
        case _ : print("invalid choice")
        
        
        