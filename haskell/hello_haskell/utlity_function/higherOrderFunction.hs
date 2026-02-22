


-- hello reverse highre ordeer function
reverseList :: (a-> a) -> [Int]  ->  [Int]
reverseList f xs = reverse (reverse xs)

--- fileter functions

filterEven :: [Int] -> [Int]
filterEven xs = filter even xs