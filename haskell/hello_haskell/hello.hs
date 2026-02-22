square :: Double -> Double
square x = x * x

printPlusTwo :: Double -> Double
printPlusTwo p = plusValue where plusValue =  p +2


--INTROUDCITON WHERE let p = 5 in p + 3
addThree  = n + s 
        where n =10 
              s = 5

oddEven :: Int -> String
oddEven v(value) =
    if value `mod` 2 == 0
        then evenStr
        else oddStr
    where evenStr = "even"
          oddStr  = "odd"

min_max :: [Int] -> Int
min_max ([a]) = max([a])



listLength :: [Int] -> Int
listLength ([a]) = length([a])