v :: Bool
v = True

sumNumber :: (Int, Int) -> Int
sumNumber (a,b)  = a + b

printTuple (a,b) = (a, b)

printList [a] = [a]

addElementListHead (a, b) = b:[a]


addElementTail :: ([Int], Int) -> [Int]
addElementTail (a, c) = a ++ [c]

printValue :: String -> String
printValue (value) = value

printIndex :: ([Int], Int)  ->  [Int]
printIndex (s, t) = [t]

-- NEGATE

substract :: (Int, Int) -> Int
substract (q, w) = q  + (negate w)


-- let number = [1,2,3]
-- let tuple  = ("a", "b")



