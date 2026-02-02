square :: Double -> Double
square x = x * x

printPlusTwo :: Double -> Double
printPlusTwo p = plusValue where plusValue =  p +2


--INTROUDCITON WHERE let p = 5 in p + 3
addThree  = n + s 
        where n =10 
              s = 5

oddEven :: Double -> String
oddEven value =
    if value `mod` 2 == 0
        then evenStr
        else oddStr
    where
    evenStr = "even"
    oddStr  = "odd"


