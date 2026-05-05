import Control.Exception

checkAge :: (Ord n, Num n ) => n -> String
checkAge n | n < 25 = "Your are young"
           | otherwise   = "You are old" 


parseHandler  :: ErrorCall -> IO ()
parseHandler _  = putStrLn "Invalid input"



mainAskAge :: IO()
mainAskAge = do
              putStrLn "What is your age"
              age <-getLine
              catch (putStrLn (checkAge (read age))) parseHandler


fun2 [ ] = 0
fun2 ( x : xs ) = case ( x < 0 ) of
                True -> aux (-x) (fun2 xs )
                False -> aux x ( fun2 xs )
                where
                aux x y = x + y
                fun3 = aux (-5)




sumListFoldR :: Num a => [a] -> [a]
sumListFoldR xs = scanr (-) 0 xs

sumListFoldL :: Num a => [a] -> a 
sumListFoldL xs = foldl  (-) 0 xs


mapSum:: [Int] -> [Int]
mapSum  xs =  map (+1)xs


recursiveSum :: Int -> [Int] ->  [Int] -> [Int]
recursiveSum n [] acc = acc 
recursiveSum n (x:xs) acc = recursiveSum n xs (acc ++ [x +n])