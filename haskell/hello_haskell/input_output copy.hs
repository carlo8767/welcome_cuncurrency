


main :: IO ()
main = do
    putStrLn "hello"
    putStrLn "world"


addElementBegins :: a -> [a] -> [a]
addElementBegins n xs = n : xs

addElementEnd :: a -> [a] -> [a]
addElementEnd n xs = xs ++ [n]

accumulatorSum :: [Int] -> Int
accumulatorSum xs = foldr( \elem acc -> elem + acc  )0 xs

foldrEx :: [Int] -> [Int]
foldrEx xs = scanr (\elem acc -> acc ++ [elem]) [] xs

-- ACTION TO ANOTHER ACTION https://wiki.haskell.org/Introduction_to_Haskell_IO/Actions
mainAction :: IO()
mainAction = do
            line <- getLine  -- FIRST ACTION
            putStrLn ("You said : " ++ line) -- SECODN  ACTION BUT RETURN



writeTheName :: IO()
writeTheName = do
               putStr ("Enter your name : ")
               line <- getLine 
               do
                    putStrLn ("Welcome " ++ line ++ "!" )



takeInput :: IO String
takeInput = do
               putStr ("Enter your name : ")
               line <- getLine 
               pure line


passWritheTheName ::  IO()
passWritheTheName  =  do
                      name <- takeInput
                      putStrLn   ("The input was ++ " ++ name )


printMenu :: IO String
printMenu = do
            putStrLn "1) Push a number on the stack"
            putStrLn "2) Add the top two number on the stack"
            putStrLn "3) Print all the value in the stack"
            putStrLn "4) Exit"
            getOption <- getLine
            pure  getOption



