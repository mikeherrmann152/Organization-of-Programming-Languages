# write my own code here

def combination(first, last):  # uses the predefined combinations function
    if first == 0:    # if first == 0 then return the array
        return [[]]
    if last == []:    # if last is empty, return an empty array
        return []
    return [s[:1] + a for a in combination(m-1, s[1:])] + combination(m, s[1:]) # otherwise return the combination of the two different combinationi calls that gathers the two different numbers in the pairs of elements
