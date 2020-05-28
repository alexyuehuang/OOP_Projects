1. Alex Huang Xiaowen Ma
2. Output:
index out of bounds!
wrong index:10
I cannot fail to catch exception, because I used catch(...)
3. Order: catch out_of_range; catch logic_error, catch(...)
why not necessary: In this function we called squareElements, and if index is out of bounds it will throw error for us;
4. Valid index:
4
36
9
(I printed the result, divider and the divident)
invalid index:
index out of bounds!
wrong index:
Divide zero:
second one cannot zero!
divide 0

what it tells me: exceptions break the function and (potentially) the function that calls it immidiately. But we can catch it.
