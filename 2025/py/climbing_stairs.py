def cs(n):
    if n == 1:
        return 1
    if n == 2:
        return 2
    
    return cs(n-1) + cs(n-2)