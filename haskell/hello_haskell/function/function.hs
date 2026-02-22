-- UNCARRIED FUNCTIONS PASS ONLY ONE ARGUMENT
add :: (Int,Int) -> Int
add (x,y) =  x + y 

-- CARRIED FUNCTION YOU CAN PASS ARGUMENT SEPARATELY
addCarried :: Int -> ( Int -> Int )
addCarried x y = x + y

multiplyCarried :: Int -> (Int -> (Int -> Int ))
multiplyCarried x y z = x * (y + z)

-- CONVENTION REMOVE PARANTHESIS
addCarriedConvention :: Int -> Int -> Int -> Int
addCarriedConvention x y z = x * (y + z)

--LAMDA FUNCTIONS ANONYMOUS FUNCTION
addLamda = \x -> \y -> x + y
addNoLambda :: Int -> Int -> Int 
addNoLambda x y = sum(x,y)

--MAP
-- listMapMultiply = \[] -> \x * []

-- LIST VS TUPLE
listSame :: Int ->Int -> [Int]
listSame = \x -> \y -> [x,y]
tupleVary :: Int -> Bool -> (Int,Bool)
tupleVary = \x -> \True -> (x, True)

--CONDITIONAL TYPE
oddEven =  \x -> 
            if x `mod`2  == 0 
                then even
                else odd
            where even = "even"
                  odd = "odd"
-- SQUARE ROOT
squareRoot = \x -> sqrt x

verifySquare (x) | x == 25 = sqrt x
                 | otherwise = error "MISTAKE"

-- CASE PAST FUTURE
caseTime (x) =  case x of 
                "present" -> today
                "past" -> past
                _ -> error "Not time mapped"
                where today = "2026"
                      past = "1988"
-- CASE PAST FUTURE GUARD
caseTimeGuard (x)  | x == "present" = today  
                   | x == "past" = past
                   | otherwise = error "NO TIME MAPPED"
                    where today = "2026"
                          past = "1988"
-- PATTERN LIST MATCH
tailFirst :: [Int] -> [Int]
tailFirst (x:xs) = [x]


-- maybe optional value
safeDiv :: Int -> Int -> Maybe Int
safeDiv _ 0 = Nothing
safeDiv n p = Just (div n p)


sefeDivLeft :: Int -> Int -> Either String Int
sefeDivLeft _ 0 = Left "divison by zero"
sefeDivLeft x y = Right (div x y) 


-- MAP ADD A LIST 
mapAddList :: Int -> [Int] -> [Int]
mapAddList y xs = map(\x-> x+y)xs


-- FILTER function


filterList p (x:xs)  
            | p (x) =  x : filter p xs
            | otherwise = filter p xs
